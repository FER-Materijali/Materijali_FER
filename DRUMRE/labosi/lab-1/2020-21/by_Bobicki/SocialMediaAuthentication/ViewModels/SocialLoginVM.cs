using System;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.Threading.Tasks;
using System.Windows.Input;
using Newtonsoft.Json;
using Plugin.FacebookClient;
using SocialMediaAuthentication.Models;
using SocialMediaAuthentication.Services;
using SocialMediaAuthentication.Views;
using Xamarin.Forms;

namespace SocialMediaAuthentication.ViewModels
{
    public class SocialLoginVM
    {
        private IFacebookClient _facebookClient = CrossFacebookClient.Current;
        private UserProfileService _userProfileService = new UserProfileService();

        public ICommand OnLoginCommand { get; set; }

        public ObservableCollection<SocialNetwork> SocialNetworks { get; set; } = new ObservableCollection<SocialNetwork>()
        {
            new SocialNetwork()
            {
                Name = "Facebook",
                Icon = "ic_fb",
                Foreground = "#FFFFFF",
                Background = "#4768AD"
            }
        };

        public SocialLoginVM(IOAuth2Service oAuth2Service)
        {
            OnLoginCommand = new Command<SocialNetwork>(async (data) => await LoginAsync(data));
        }

        private async Task LoginAsync(SocialNetwork authNetwork)
        {
            await LoginFacebookAsync(authNetwork);
        }

        private async Task LoginFacebookAsync(SocialNetwork socialNetwork)
        {
            try
            {

                if (_facebookClient.IsLoggedIn)
                {
                    _facebookClient.Logout();
                }

                EventHandler<FBEventArgs<string>> userDataDelegate = null;

                userDataDelegate = async (object sender, FBEventArgs<string> e) =>
                {
                    switch (e.Status)
                    {
                        case FacebookActionStatus.Completed:
                            var facebookProfile = await Task.Run(() => JsonConvert.DeserializeObject<FacebookProfile>(e.Data));
                            var userProfile = new UserProfile(facebookProfile.Id, $"{facebookProfile.FirstName} {facebookProfile.LastName}", facebookProfile.Email, facebookProfile.Picture.Data.Url);

                            await _userProfileService.CreateUserProfile(userProfile);
                            var userProfileFromDb = await _userProfileService.GetUserProfileByProfileId(userProfile.ProfileId);

                            await App.Current.MainPage.Navigation.PushModalAsync(new HomePage(userProfileFromDb));
                            break;
                        case FacebookActionStatus.Canceled:
                            await App.Current.MainPage.DisplayAlert("Facebook Auth", "Cancelled", "Ok");
                            break;
                        case FacebookActionStatus.Error:
                            await App.Current.MainPage.DisplayAlert("Facebook Auth", "Error", "Ok");
                            break;
                        case FacebookActionStatus.Unauthorized:
                            await App.Current.MainPage.DisplayAlert("Facebook Auth", "Unauthorized", "Ok");
                            break;
                    }

                    _facebookClient.OnUserData -= userDataDelegate;
                };

                _facebookClient.OnUserData += userDataDelegate;

                string[] fbRequestFields = { "email", "first_name", "picture", "gender", "last_name" };
                string[] fbPermisions = { "email" };
                await _facebookClient.RequestUserDataAsync(fbRequestFields, fbPermisions);
            }
            catch (Exception ex)
            {
                Debug.WriteLine(ex.ToString());
            }
        }
    }
}

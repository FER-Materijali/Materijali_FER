using System;
using SocialMediaAuthentication.Models;
using SocialMediaAuthentication.ViewModels;
using Xamarin.Forms;

namespace SocialMediaAuthentication.Views
{
    public partial class HomePage : ContentPage
    {
        private HomeVM _vm;

        public HomePage(UserProfile userProfile)
        {
            InitializeComponent();
            _vm = new HomeVM(userProfile);
            this.BindingContext = _vm;
            this.artistPicker.SelectedIndex = 0;
        }

        async void OnLogout(object sender, EventArgs e)
        {
            await Navigation.PopModalAsync();
        }

        async void OnPickerSelectedIndexChanged(object sender, EventArgs e)
        {
            var picker = (Picker)sender;
            int selectedIndex = picker.SelectedIndex;

            if (selectedIndex != -1)
            {
                var pickedArtist = (string)picker.ItemsSource[selectedIndex];
                await _vm.GetApiDataAsync(pickedArtist);
            }
        }
    }
}

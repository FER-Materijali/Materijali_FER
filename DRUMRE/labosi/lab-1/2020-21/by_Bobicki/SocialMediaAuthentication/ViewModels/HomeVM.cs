using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Threading.Tasks;
using System.Windows.Input;
using IF.Lastfm.Core.Api;
using OpenWeatherMap;
using SocialMediaAuthentication.Models;
using SocialMediaAuthentication.Services;

namespace SocialMediaAuthentication.ViewModels
{
    public class HomeVM : INotifyPropertyChanged
    {
        private LastfmArtistService _lastfmArtistService = new LastfmArtistService();
        private OpenWeatherMapService _openWeatherMapService = new OpenWeatherMapService();

        public ICommand GetApiDataCommand { get; set; }

        #region Properties
        private string _userProfilePicture;
        public string UserProfilePicture
        {
            get => _userProfilePicture;
            set
            {
                if (_userProfilePicture == value)
                    return;

                _userProfilePicture = value;

                HandlePropertyChanged();
            }
        }

        private string _userProfileName;
        public string UserProfileName
        {
            get => _userProfileName;
            set
            {
                if (_userProfileName == value)
                    return;

                _userProfileName = value;

                HandlePropertyChanged();
            }
        }

        private string _artistName;
        public string ArtistName
        {
            get => _artistName;
            set
            {
                if (_artistName == value)
                    return;

                _artistName = value;

                HandlePropertyChanged();
            }
        }

        private int _artistListeners;
        public int ArtistListeners
        {
            get => _artistListeners;
            set
            {
                if (_artistListeners == value)
                    return;

                _artistListeners = value;

                HandlePropertyChanged();
            }
        }

        private string _artistUrl;
        public string ArtistUrl
        {
            get => _artistUrl;
            set
            {
                if (_artistUrl == value)
                    return;

                _artistUrl = value;

                HandlePropertyChanged();
            }
        }

        private List<string> _artistTopTracks;
        public List<string> ArtistTopTracks
        {
            get => _artistTopTracks;
            set
            {
                if (_artistTopTracks == value)
                    return;

                _artistTopTracks = value;

                HandlePropertyChanged();
            }
        }

        private string _weatherCity;
        public string WeatherCity
        {
            get => _weatherCity;
            set
            {
                if (_weatherCity == value)
                    return;

                _weatherCity = value;

                HandlePropertyChanged();
            }
        }

        private string _weatherDescription;
        public string WeatherDescription
        {
            get => _weatherDescription;
            set
            {
                if (_weatherDescription == value)
                    return;

                _weatherDescription = value;

                HandlePropertyChanged();
            }
        }

        private string _weatherHumidity;
        public string WeatherHumidity
        {
            get => _weatherHumidity;
            set
            {
                if (_weatherHumidity == value)
                    return;

                _weatherHumidity = value;

                HandlePropertyChanged();
            }
        }

        private string _weatherPressure;
        public string WeatherPressure
        {
            get => _weatherPressure;
            set
            {
                if (_weatherPressure == value)
                    return;

                _weatherPressure = value;

                HandlePropertyChanged();
            }
        }

        private string _weatherTemperature;
        public string WeatherTemperature
        {
            get => _weatherTemperature;
            set
            {
                if (_weatherTemperature == value)
                    return;

                _weatherTemperature = value;

                HandlePropertyChanged();
            }
        }

        private string _weatherWindSpeed;
        public string WeatherWindSpeed
        {
            get => _weatherWindSpeed;
            set
            {
                if (_weatherWindSpeed == value)
                    return;

                _weatherWindSpeed = value;

                HandlePropertyChanged();
            }
        }
        #endregion

        public HomeVM(UserProfile userProfile)
        {
            UserProfilePicture = userProfile.Picture;
            UserProfileName = userProfile.Name;
        }

        public async Task GetApiDataAsync(string artist)
        {
            await GetLastfmApiDataAsync(artist);
            await GetOpenWeatherMapApiDataAsync(artist);
        }

        public async Task GetLastfmApiDataAsync(string artist)
        {
            var client = new LastfmClient(ApiKeys.LastfmApiKey, ApiKeys.LastfmApiSecret);
            var artistInfo = (await client.Artist.GetInfoAsync(artist)).Content;
            var artistTopTracks = (await client.Artist.GetTopTracksAsync(artist, itemsPerPage: 5)).Content;
            var trackList = new List<string>();
            foreach (var track in artistTopTracks)
            {
                var trackName = track.Name;
                trackList.Add(trackName);
            }

            var lastfmArtist = new LastfmArtist(artistInfo.Mbid, artistInfo.Name, artistInfo.Stats.Listeners, artistInfo.Url.AbsoluteUri, trackList);
            await _lastfmArtistService.CreateLastfmArtist(lastfmArtist);
            var lastfmArtistFromDb = await _lastfmArtistService.GetLastfmArtistByArtistId(lastfmArtist.ArtistId);
            ArtistName = lastfmArtistFromDb.Name;
            ArtistListeners = lastfmArtistFromDb.Listeners;
            ArtistUrl = lastfmArtistFromDb.Url;
            ArtistTopTracks = lastfmArtistFromDb.TopFiveTracks;
        }

        public async Task GetOpenWeatherMapApiDataAsync(string artist)
        {
            var client = new OpenWeatherMapClient(ApiKeys.OpenWeatherMapApiKey);
            var city = "";
            switch (artist)
            {
                case "Kanye West":
                    city = "Chicago";
                    break;
                case "Adele":
                    city = "London";
                    break;
                case "The Weeknd":
                    city = "Toronto";
                    break;
                case "Ariana Grande":
                    city = "Miami";
                    break;
            }
            var currentWeatherInfo = await client.CurrentWeather.GetByName(city);

            var weatherInfo = new WeatherInfo(currentWeatherInfo.City.Id, currentWeatherInfo.City.Name, currentWeatherInfo.Wind.Speed.Name + ", " + currentWeatherInfo.Clouds.Name, 
                currentWeatherInfo.Humidity.Value, currentWeatherInfo.Pressure.Value, currentWeatherInfo.Temperature.Value - 273, currentWeatherInfo.Wind.Speed.Value);
            await _openWeatherMapService.CreateWeatherInfo(weatherInfo);
            var weatherInfoFromDb = await _openWeatherMapService.GetWeatherInfoByCityId(weatherInfo.CityId);
            WeatherCity = weatherInfoFromDb.Name;
            WeatherDescription = weatherInfoFromDb.WeatherDescription;
            WeatherHumidity = weatherInfoFromDb.Humidity + "%";
            WeatherPressure = (int)Math.Round(weatherInfoFromDb.Pressure) + "hPa";
            WeatherTemperature = (int)Math.Round(weatherInfoFromDb.Temperature) + "°C";
            WeatherWindSpeed = Math.Round(weatherInfoFromDb.WindSpeed, 1) + "m/s";
        }

        void HandlePropertyChanged([CallerMemberName] string propertyName = "")
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }

        public event PropertyChangedEventHandler PropertyChanged;
    }
}

using System;
using MongoDB.Bson.Serialization.IdGenerators;
using MongoDB.Bson.Serialization.Attributes;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Collections.Generic;

namespace SocialMediaAuthentication.Models
{
    public class WeatherInfo : INotifyPropertyChanged
    {
        [BsonId(IdGenerator = typeof(CombGuidGenerator))]
        [BsonIgnoreIfDefault]
        public Guid Id { get; set; }

        private int _cityId;
        [BsonElement("cityId")]
        public int CityId
        {
            get => _cityId; 
            set
            {
                if (_cityId == value)
                    return;

                _cityId = value;

                HandlePropertyChanged();
            }
        }

        private string _name;
        [BsonElement("name")]
        public string Name
        {
            get => _name;
            set
            {
                if (_name == value)
                    return;

                _name = value;

                HandlePropertyChanged();
            }
        }

        private string _weatherDescription;
        [BsonElement("weatherDescription")]
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

        private int _humidity;
        [BsonElement("humidity")]
        public int Humidity
        {
            get => _humidity;
            set
            {
                if (_humidity == value)
                    return;

                _humidity = value;

                HandlePropertyChanged();
            }
        }

        private double _pressure;
        [BsonElement("pressure")]
        public double Pressure
        {
            get => _pressure;
            set
            {
                if (_pressure == value)
                    return;

                _pressure = value;

                HandlePropertyChanged();
            }
        }

        private double _temperature;
        [BsonElement("temperature")]
        public double Temperature
        {
            get => _temperature;
            set
            {
                if (_temperature == value)
                    return;

                _temperature = value;

                HandlePropertyChanged();
            }
        }

        private double _windSpeed;
        [BsonElement("windSpeed")]
        public double WindSpeed
        {
            get => _windSpeed;
            set
            {
                if (_windSpeed == value)
                    return;

                _windSpeed = value;

                HandlePropertyChanged();
            }
        }

        public WeatherInfo(int cityId, string name, string weatherDescription, int humidity, double pressure, double temperature, double windSpeed)
        {
            CityId = cityId;
            Name = name;
            WeatherDescription = weatherDescription;
            Humidity = humidity;
            Pressure = pressure;
            Temperature = temperature;
            WindSpeed = windSpeed;
        }

        void HandlePropertyChanged([CallerMemberName]string propertyName = "")
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }

        public event PropertyChangedEventHandler PropertyChanged;
    }
}

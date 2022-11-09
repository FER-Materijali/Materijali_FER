using System;
using MongoDB.Bson.Serialization.IdGenerators;
using MongoDB.Bson.Serialization.Attributes;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Collections.Generic;

namespace SocialMediaAuthentication.Models
{
    public class LastfmArtist : INotifyPropertyChanged
    {
        [BsonId(IdGenerator = typeof(CombGuidGenerator))]
        [BsonIgnoreIfDefault]
        public Guid Id { get; set; }

        private string _artistId;
        [BsonElement("artistId")]
        public string ArtistId
        {
            get => _artistId; 
            set
            {
                if (_artistId == value)
                    return;

                _artistId = value;

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

        private int _listeners;
        [BsonElement("listeners")]
        public int Listeners
        {
            get => _listeners;
            set
            {
                if (_listeners == value)
                    return;

                _listeners = value;

                HandlePropertyChanged();
            }
        }

        private string _url;
        [BsonElement("url")]
        public string Url
        {
            get => _url;
            set
            {
                if (_url == value)
                    return;

                _url = value;

                HandlePropertyChanged();
            }
        }

        private List<string> _topFiveTracks;
        [BsonElement("topTenTracks")]
        public List<string> TopFiveTracks
        {
            get => _topFiveTracks;
            set
            {
                if (_topFiveTracks == value)
                    return;

                _topFiveTracks = value;

                HandlePropertyChanged();
            }
        }

        public LastfmArtist(string artistId, string name, int listeners, string url, List<string> topFiveTracks)
        {
            ArtistId = artistId;
            Name = name;
            Listeners = listeners;
            Url = url;
            TopFiveTracks = topFiveTracks;
        }

        void HandlePropertyChanged([CallerMemberName]string propertyName = "")
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }

        public event PropertyChangedEventHandler PropertyChanged;
    }
}

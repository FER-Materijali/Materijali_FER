using System;
using MongoDB.Bson.Serialization.IdGenerators;
using MongoDB.Bson.Serialization.Attributes;
using System.ComponentModel;
using System.Runtime.CompilerServices;
namespace SocialMediaAuthentication.Models
{
    public class UserProfile : INotifyPropertyChanged
    {
        [BsonId(IdGenerator = typeof(CombGuidGenerator))]
        [BsonIgnoreIfDefault]
        public Guid Id { get; set; }

        private string _profileId;
        [BsonElement("profileId")]
        public string ProfileId
        {
            get => _profileId;          
            set
            {
                if (_profileId == value)
                    return;

                _profileId = value;

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

        private string _email;
        [BsonElement("email")]
        public string Email
        {
            get => _email;
            set
            {
                if (_email == value)
                    return;

                _email = value;

                HandlePropertyChanged();
            }
        }

        private string _picture;
        [BsonElement("picture")]
        public string Picture
        {
            get => _picture;
            set
            {
                if (_picture == value)
                    return;

                _picture = value;

                HandlePropertyChanged();
            }
        }

        public UserProfile(string profileId, string name, string email, string picture)
        {
            ProfileId = profileId;
            Name = name;
            Email = email;
            Picture = picture;
        }

        void HandlePropertyChanged([CallerMemberName]string propertyName = "")
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }

        public event PropertyChangedEventHandler PropertyChanged;
    }
}

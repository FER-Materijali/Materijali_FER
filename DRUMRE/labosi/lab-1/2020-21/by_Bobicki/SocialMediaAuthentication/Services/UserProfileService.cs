using System;
using System.Security.Authentication;
using MongoDB.Driver;
using System.Threading.Tasks;
using System.Collections.Generic;
using MongoDB.Driver.Linq;
using System.Linq;
using MongoDB.Bson;
using SocialMediaAuthentication.Models;

namespace SocialMediaAuthentication.Services
{
    public class UserProfileService
    {
        private string _dbName = "socialNetworksLabDB";
        private string _collectionName = "userProfiles";

        #region Properties
        private IMongoCollection<UserProfile> _userProfilesCollection;
        public IMongoCollection<UserProfile> UserProfilesCollection
        {
            get
            {
                if (_userProfilesCollection == null)
                {
                    var mongoUrl = new MongoUrl(ApiKeys.DbConnectionString);

                    // APIKeys.Connection string is found in the portal under the "Connection String" blade
                    MongoClientSettings settings = MongoClientSettings.FromUrl(
                      mongoUrl
                    );

                    settings.SslSettings =
                        new SslSettings() { EnabledSslProtocols = SslProtocols.Tls12 };

                    settings.RetryWrites = false;

                    // Initialize the client
                    var mongoClient = new MongoClient(settings);

                    // This will create or get the database
                    var db = mongoClient.GetDatabase(_dbName);

                    // This will create or get the collection
                    var collectionSettings = new MongoCollectionSettings { ReadPreference = ReadPreference.Nearest };
                    _userProfilesCollection = db.GetCollection<UserProfile>(_collectionName, collectionSettings);
                }
                return _userProfilesCollection;
            }
        }
        #endregion

        public async Task<List<UserProfile>> GetAllUserProfiles()
        {
            try
            {
                var userProfiles = await UserProfilesCollection
                    .Find(new BsonDocument())
                    .ToListAsync();

                return userProfiles;
            }
            catch (Exception ex)
            {
                System.Diagnostics.Debug.WriteLine(ex.Message);
            }
            return null;
        }

        public async Task<UserProfile> GetUserProfileByProfileId(string profileId)
        {
            var userProfile = await UserProfilesCollection
                .Find(f => f.ProfileId.Equals(profileId))
                .FirstOrDefaultAsync();

            return userProfile;
        }

        public async Task CreateUserProfile(UserProfile userProfile)
        {
            var existingUserProfile = await GetUserProfileByProfileId(userProfile.ProfileId);
            if (existingUserProfile == null)
            {
                await UserProfilesCollection.InsertOneAsync(userProfile);
            }
            else
            {
                await UpdateUserProfile(userProfile);
            }
        }

        public async Task UpdateUserProfile(UserProfile userProfile)
        {
            await UserProfilesCollection.ReplaceOneAsync(t => t.ProfileId.Equals(userProfile.ProfileId), userProfile);
        }

        public async Task DeleteUserProfile(UserProfile userProfile)
        {
            await UserProfilesCollection.DeleteOneAsync(t => t.ProfileId.Equals(userProfile.ProfileId));
        }
    }
}

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
    public class LastfmArtistService
    {
        private string _dbName = "socialNetworksLabDB";
        private string _collectionName = "lastfmArtists";

        #region Properties
        private IMongoCollection<LastfmArtist> _lastFmArtistsCollection;
        public IMongoCollection<LastfmArtist> LastfmArtistsCollection
        {
            get
            {
                if (_lastFmArtistsCollection == null)
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
                    _lastFmArtistsCollection = db.GetCollection<LastfmArtist>(_collectionName, collectionSettings);
                }
                return _lastFmArtistsCollection;
            }
        }
        #endregion

        public async Task<List<LastfmArtist>> GetAllLastfmArtists()
        {
            try
            {
                var lastfmArtists = await LastfmArtistsCollection
                    .Find(new BsonDocument())
                    .ToListAsync();

                return lastfmArtists;
            }
            catch (Exception ex)
            {
                System.Diagnostics.Debug.WriteLine(ex.Message);
            }
            return null;
        }

        public async Task<LastfmArtist> GetLastfmArtistByArtistId(string artistId)
        {
            var lastfmArtist = await LastfmArtistsCollection
                .Find(f => f.ArtistId.Equals(artistId))
                .FirstOrDefaultAsync();

            return lastfmArtist;
        }

        public async Task CreateLastfmArtist(LastfmArtist lastfmArtist)
        {
            var existingLastfmArtist = await GetLastfmArtistByArtistId(lastfmArtist.ArtistId);
            if (existingLastfmArtist == null)
            {
                await LastfmArtistsCollection.InsertOneAsync(lastfmArtist);
            }
            else
            {
                await UpdateLastfmArtist(lastfmArtist);
            }
        }

        public async Task UpdateLastfmArtist(LastfmArtist lastfmArtist)
        {
            await LastfmArtistsCollection.ReplaceOneAsync(t => t.ArtistId.Equals(lastfmArtist.ArtistId), lastfmArtist);
        }

        public async Task DeleteLastfmArtist(LastfmArtist lastfmArtist)
        {
            await LastfmArtistsCollection.DeleteOneAsync(t => t.ArtistId.Equals(lastfmArtist.ArtistId));
        }
    }
}

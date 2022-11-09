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
    public class OpenWeatherMapService
    {
        private string _dbName = "socialNetworksLabDB";
        private string _collectionName = "openWeatherMapInfos";

        #region Properties
        private IMongoCollection<WeatherInfo> _weatherInfosCollection;
        public IMongoCollection<WeatherInfo> WeatherInfosCollection
        {
            get
            {
                if (_weatherInfosCollection == null)
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
                    _weatherInfosCollection = db.GetCollection<WeatherInfo>(_collectionName, collectionSettings);
                }
                return _weatherInfosCollection;
            }
        }
        #endregion

        public async Task<List<WeatherInfo>> GetAllWeatherInfos()
        {
            try
            {
                var weatherInfos = await WeatherInfosCollection
                    .Find(new BsonDocument())
                    .ToListAsync();

                return weatherInfos;
            }
            catch (Exception ex)
            {
                System.Diagnostics.Debug.WriteLine(ex.Message);
            }
            return null;
        }

        public async Task<WeatherInfo> GetWeatherInfoByCityId(int cityId)
        {
            var weatherInfo = await WeatherInfosCollection
                .Find(f => f.CityId.Equals(cityId))
                .FirstOrDefaultAsync();

            return weatherInfo;
        }

        public async Task CreateWeatherInfo(WeatherInfo weatherInfo)
        {
            var existingWeatherInfo = await GetWeatherInfoByCityId(weatherInfo.CityId);
            if (existingWeatherInfo == null)
            {
                await WeatherInfosCollection.InsertOneAsync(weatherInfo);
            }
            else
            {
                await UpdateWeatherInfo(weatherInfo);
            }
        }

        public async Task UpdateWeatherInfo(WeatherInfo weatherInfo)
        {
            var a = await WeatherInfosCollection.ReplaceOneAsync(t => t.CityId.Equals(weatherInfo.CityId), weatherInfo);
        }

        public async Task DeleteWeatherInfo(WeatherInfo weatherInfo)
        {
            await WeatherInfosCollection.DeleteOneAsync(t => t.CityId.Equals(weatherInfo.CityId));
        }
    }
}

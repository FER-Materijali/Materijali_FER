using MongoDB.Bson;
using MongoDB.Driver;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Portal.Data
{
    public class Database
    {
        private static IMongoClient client = new MongoClient();
        private static IMongoDatabase database = client.GetDatabase("portal");

        public void AddComment(string comment, int id)
        {
            var com = new Comment { Text = comment, Timestamp = DateTime.Now };

            var collection = database.GetCollection<News>("news");
            var filter = Builders<News>.Filter.Eq("_id", id);
            var update = Builders<News>.Update.Push("comments", com);
            collection.UpdateOne(filter, update);
        }

        public List<News> GetNews(int count)
        {
            var collection = database.GetCollection<News>("news");
            var sort = Builders<News>.Sort.Descending("_id");

            return collection.Find(_ => true).Sort(sort).Limit(count).ToList();
        }

        public void Add(News model)
        {
            var collection = database.GetCollection<News>("news");
            model.Id = (int)collection.Count(new BsonDocument());
            collection.InsertOne(model);
        }
    }
}

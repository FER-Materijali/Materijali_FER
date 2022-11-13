using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MongoDB.Bson;
using MongoDB.Driver;

namespace DatabaseLayer
{
    public class Baza
    {
        protected static IMongoClient _client;
        protected static IMongoDatabase _database;

        public Baza()
        {
            _client = new MongoClient();
            _database = _client.GetDatabase("prvi");
        }

        public void  unesiKomentar(string comment, int ArticleId)
        {
            var komentar = new BsonDocument {
                {"timestamp", BsonDateTime.Create(DateTime.Now)}, {"commentar", comment}
            };

            var collection = _database.GetCollection<BsonDocument>("articles");
            var filter = Builders<BsonDocument>.Filter.Eq("_id", ArticleId);
            var update = Builders<BsonDocument>.Update
                .Push("comment", komentar);
            collection.UpdateOneAsync(filter, update);
        }

        //public void unesiSliku(byte[] slika, int ArticleId)
        //{
        //    var slikaJson = new BsonBinaryData(slika);

        //    var collection = _database.GetCollection<BsonDocument>("articles");
        //    var filter = Builders<BsonDocument>.Filter.Eq("_id", ArticleId);
        //    var update = Builders<BsonDocument>.Update
        //        .Set("picture", slikaJson);

        //    collection.UpdateOneAsync(filter, update);
        //}

        public List<Result> vratiVijesti(int number)
        {
            var collection = _database.GetCollection<BsonDocument>("articles");
            var filter = new BsonDocument();
            var sort = Builders<BsonDocument>.Sort.Descending("_id");
            var items = collection.Find(filter).Sort(sort).Limit(number).ToList();
            List<Result> rezultati = new List<Result>();


            foreach (var item in items)
            {
                Result novi = new Result();
                BsonValue value;
                item.TryGetValue("_id", out value);
                novi.id = value.AsInt32;
                item.TryGetValue("headline", out value);
                novi.headline = value.AsString;
                item.TryGetValue("text", out value);
                novi.text = value.AsString;
                item.TryGetValue("author", out value);
                novi.author = value.AsString;

                if (item.TryGetValue("picture", out value))
                    novi.picture = value.AsByteArray;

                novi.comments = new List<CommentResult>();

                if (item.TryGetValue("comment", out value))
                {
                    var listaKomentara = value.AsBsonArray;
                    foreach (var comment in listaKomentara)
                    {
                        CommentResult komentar = new CommentResult();
                        BsonValue help;
                        var helping = comment.AsBsonDocument;
                        helping.TryGetValue("timestamp", out help);
                        komentar.timestamp = help.ToUniversalTime();
                        helping.TryGetValue("commentar", out help);
                        komentar.text = help.AsString;

                        novi.comments.Add(komentar);
                    }
                }

                rezultati.Add(novi);
            }


            return rezultati;

        }

        public void unesiVijest(Result newArticle)
        {
            var collection = _database.GetCollection<BsonDocument>("articles");
            var id = (int) collection.Count(new BsonDocument());

            var vijest = new BsonDocument {
                {"_id", BsonInt32.Create(id + 1)},
                {"headline", BsonString.Create(newArticle.headline)}, {"text", BsonString.Create(newArticle.text)},
                {"author", BsonString.Create(newArticle.author)}, {"comment", new BsonArray()},
                {"picture", new BsonBinaryData(newArticle.picture)}
            };

            collection.InsertOneAsync(vijest);
        }

    }
}

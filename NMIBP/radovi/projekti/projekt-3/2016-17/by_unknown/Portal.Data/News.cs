using MongoDB.Bson.Serialization.Attributes;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Portal.Data
{
    public class News
    {
        [BsonElement("_id")]
        public int Id { get; set; }

        [BsonElement("headline")]
        public string Headline { get; set; }

        [BsonElement("text")]
        public string Text { get; set; }

        [BsonElement("author")]
        public string Author { get; set; }

        [BsonElement("comments")]
        public List<Comment> Comments { get; set; } = new List<Comment>();

        [BsonElement("picture")]
        public byte[] Picture { get; set; }
    }

    public class Comment
    {
        [BsonElement("timestamp")]
        public DateTime Timestamp { get; set; }

        [BsonElement("text")]
        public string Text { get; set; }

    }
}

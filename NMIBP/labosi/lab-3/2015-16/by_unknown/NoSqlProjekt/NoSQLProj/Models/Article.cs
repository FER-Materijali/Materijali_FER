using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using DatabaseLayer;

namespace NoSQLProj.Models
{
    public class Article 
    {
        public int id { get; set; }
        public string headline { get; set; }
        public string text { get; set; }
        public string author { get; set; }
        public List<Comment> comments { get; set; }
        public byte[] picture { get; set; }
    }
    public class Comment
    {
        public DateTime timestamp { get; set; }
        public string text { get; set; }
    }
}
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace SematicWeb.Models
{
    public class Movie : SearchResult
    {

        public string name { get; set; }
        public string url { get; set; }

        public string redatelj { get; set; }

        public string scenarist { get; set; }

        public string kratkiOpis { get; set; }

        public string dugiOpis { get; set; }

        public string datumNastanka { get; set; }
    
        public List<Actor> actors { get; set; }
    }
}

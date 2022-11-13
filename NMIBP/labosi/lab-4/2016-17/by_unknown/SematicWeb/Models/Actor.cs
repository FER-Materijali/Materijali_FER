using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace SematicWeb.Models
{
    public class Actor:SearchResult
    {

        public string name { get; set; }

        public int godine { get; set; }

        public string kratkiZivotopis { get; set; }

        public string mjestoRodenja { get; set; }

        public string prezime { get; set; }
    }
}
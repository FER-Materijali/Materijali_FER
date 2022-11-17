using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace FilmInfoService
{
    public class VisitStats : IComparable<VisitStats>
    {
        public string url { get; set; }
        public int count { get; set; }

        public VisitStats(string[] line)
        {
            url = line[0];
            count = int.Parse(line[1]);
        }

        public int CompareTo(VisitStats other)
        {
            if (count > other.count) return -1;
            if (count < other.count) return 1;
            return 0;
        }

        public override string ToString()
        {
            return count.ToString() + " : " + url;
        }
    }
}
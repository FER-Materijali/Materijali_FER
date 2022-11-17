using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TuringovStroj
{
    public class Stanje
    {
        public String Ime;
        public Stanje(String ime)
        {
            this.Ime = ime;
        }
        public override string ToString()
        {
            return Ime;
        }
    }
}

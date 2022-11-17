using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TuringovStroj
{
    public class ZnakTrake
    {
        public string Znak;
        public ZnakTrake(string znak)
        {
            this.Znak = znak;
        }
        public override string ToString()
        {
            return Znak;
        }
    }
}

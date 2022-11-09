using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace APR___lab2
{
    public class ImplicitnoOgranicenje
    {
        public bool Zadovoljava(List<double> x)
        {
            if (( x[0]-x[1]<=0) && (x[1]-2<=0))
                return true;
            return false;
        }
    }
}

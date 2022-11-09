using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace APR___lab2
{
    class EksplicitnoOgranicenje
    {
        double donjaGranica;

        public double DonjaGranica
        {
            get { return donjaGranica; }
            set { donjaGranica = value; }
        }
        double gornjaGranica;

        public double GornjaGranica
        {
            get { return gornjaGranica; }
            set { gornjaGranica = value; }
        }

        public EksplicitnoOgranicenje(double d, double g)
        {
            donjaGranica = d;
            gornjaGranica = g;
        }

        public bool Zadovoljava(List<double> x)
        {
            for (int i = 0; i < x.Count; i++)
            {
                if ((x[i] < DonjaGranica) && (x[i] > GornjaGranica))
                    return false;
            }
            return true;
        }
    }
}

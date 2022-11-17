using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SSP.Klase
{
    class ZnakComperer : IComparer<SSP.Klase.Znak>
    {
        /// <summary>
        /// Sluzi za sortiranje liste znakova
        /// </summary>
        public int Compare(SSP.Klase.Znak x, SSP.Klase.Znak y)
        {
            if (x == null)
            {
                return -1;
            }
            else if (y == null)
            {
                return 1;
            }
            else if (x.znak[0] > y.znak[0])
            {
                return 1;
            }
            else if (x.znak[0] < y.znak[0])
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }
    }
}

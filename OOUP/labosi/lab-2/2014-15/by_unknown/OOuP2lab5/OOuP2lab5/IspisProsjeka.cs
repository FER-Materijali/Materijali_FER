using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOuP2lab5
{
    class IspisProsjeka : Observer
    {
        public IspisProsjeka(SlijedBrojeva sb) : base(sb)
        {

        }

        public override void Update()
        {
            int suma=0;
            foreach (int i in slijedBrojeva.dajBrojeve())
            {
                suma += i;
            }

            Console.WriteLine("Trenutni prosjek:" + (double)suma / slijedBrojeva.dajBrojeve().Count());
        }
    }
}

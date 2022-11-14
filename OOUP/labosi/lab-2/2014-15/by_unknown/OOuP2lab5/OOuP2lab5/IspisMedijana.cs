using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOuP2lab5
{
    class IspisMedijana : Observer
    {
        public IspisMedijana(SlijedBrojeva sb) : base(sb)
        {

        }


        public override void Update()
        {
            List<int> niz = slijedBrojeva.dajBrojeve();
            niz.Sort();
            int n = niz.Count();
            double i;
            if (n == 1)
            {
                i= niz.ElementAt(0);
            } 
            else if(n%2==0)
            {
                
                i= (double)(niz.ElementAt(n/2)+niz.ElementAt(n/2-1))/2;
            }
            else
            {
                i= niz.ElementAt(n/2);
            }

            Console.WriteLine("Trenutni medijan:"+i);
        }
    }
}

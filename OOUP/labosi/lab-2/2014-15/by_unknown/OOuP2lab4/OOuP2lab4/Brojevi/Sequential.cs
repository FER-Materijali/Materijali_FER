using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOuP2lab4
{
    class Sequential : INumberGenerator
    {
        private int lijevi;
        private int desni;
        private int korak;

        public Sequential(int l, int d, int k)
        {
            lijevi = l;
            desni = d;
            korak = k;
        }

        public int[] Generate(){
            List<int> niz = new List<int>();

            for (int i = lijevi; i <= desni; i += korak)
            {
                niz.Add(i);
            }
            
            return niz.ToArray();
        }
    }
}

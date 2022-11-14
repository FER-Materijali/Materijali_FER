using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOuP2lab4
{
    class Fibonacci : INumberGenerator
    {
        private int n;

        public Fibonacci(int n)
        {
            this.n=n;
        }

        public int[] Generate()
        {
            List<int> niz = new List<int>();
            int prvi = 0, drugi = 1, t;

            for (int i = 0; i < n; i++)
            {
                niz.Add(prvi);
                t= drugi;
                drugi = prvi + drugi;
                prvi = t;
                
            }

            return niz.ToArray();
        }
    }
}

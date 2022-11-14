using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace OOuP2lab4
{
    class Normal : INumberGenerator
    {
        private double mean;
        private double stdDev;
        private int n;
        public Normal(double mean, double stdDev, int n)
        {
            this.mean = mean;
            this.stdDev = stdDev;
            this.n = n;
        }

        public int[] Generate()
        {
            List<int> niz = new List<int>();
            Random rand = new Random(); //reuse this if you are generating many

            for(int i=0; i<n ;i++)
            {
                double u1 = rand.NextDouble(); 
                double u2 = rand.NextDouble();
                double randStdNormal = Math.Sqrt(-2.0 * Math.Log(u1)) *
                             Math.Sin(2.0 * Math.PI * u2); 
                double randNormal =
                             mean + stdDev * randStdNormal;

                niz.Add((int)randNormal);
            }
            
            return niz.ToArray();
        }
    }
}

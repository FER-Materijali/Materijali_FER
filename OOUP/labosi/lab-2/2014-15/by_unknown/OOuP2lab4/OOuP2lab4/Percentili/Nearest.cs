using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOuP2lab4
{
    class Nearest : IPercentileCalc
    {
        
        public int Calculate(int p, int[] numbers)
        {
            Array.Sort<int>(numbers);
            int N = numbers.Length;
            double n_p = (double)p * N / 100 + 0.5;
            int i = Convert.ToInt32(n_p)-1;
            return numbers[i];
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOuP2lab4
{
    class Interpolation : IPercentileCalc
    {
        
        public int Calculate(int p, int[] v)
        {
            Array.Sort<int>(v);
            int N = v.Length;
            double p_v_i, p_v_i1;
            double interp;

            if (p < 100 * ((double)1 - 0.5) / N)
                return v[0];
            if (p > 100 * ((double)N - 0.5) / N)
                return v[N-1];
            for (int i = 0; i < N - 1; i++)
            {
                p_v_i = 100 * ((double)i + 1 - 0.5) / N;
                p_v_i1 = 100 * ((double)i + 1 + 1 - 0.5) / N;
                if (p >= p_v_i && p <= p_v_i1)
                {
                    interp = v[i] + (double)N * (p - p_v_i) * (v[i+1] - v[i]) / 100;
                    return Convert.ToInt32(interp);
                }
            }
            return new int();
        }
    }
}

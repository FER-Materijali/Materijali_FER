using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOuP2lab4
{
    class DistributionTester
    {
        private INumberGenerator numGen;
        private IPercentileCalc perCal;
        public DistributionTester(INumberGenerator gen, IPercentileCalc cal)
        {
            numGen = gen;
            perCal = cal;
        }

        

        public void Test()
        {
            int[] numbers = numGen.Generate();
            Console.Write("Generiran niz: ");
            for (int i = 0; i < numbers.Length; i ++)
            {
                Console.Write(numbers[i]+" ");
            }

            for (int i = 10; i <= 90; i+=10)
            {
                Console.Write("\n"+i+". percentil: "+perCal.Calculate(i, numbers));
            }
        }

    }
}

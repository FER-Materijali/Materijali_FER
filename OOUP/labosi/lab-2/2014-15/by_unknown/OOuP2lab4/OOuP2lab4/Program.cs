using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOuP2lab4
{
    class Program
    {
        static void Main(string[] args)
        {
            DistributionTester dt = new DistributionTester(new Fibonacci(10),new Interpolation());
            dt.Test();
            
            Console.ReadLine();
        }
    }
}

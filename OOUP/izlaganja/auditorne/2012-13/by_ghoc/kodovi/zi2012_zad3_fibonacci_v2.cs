using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Zadatak3
{

    public static class GlobalVar
    {
        static int _brPoziva;

        public static int BrPoziva
        {
            get { return _brPoziva; }
            set { _brPoziva = value; }
        }
    }


    interface Sequence
    {
        int getF(int n);
    }


    class Fibonacci:Sequence
    {
        public virtual int getF(int n)
        {
            Console.WriteLine("  POZVAN GET IZ FIBONACCIJA!");
            GlobalVar.BrPoziva += 1;

            Console.WriteLine("Poziv funkcije br. {0}", GlobalVar.BrPoziva);
            if (n<2)
            {
                return n;
            }
            else
            {
                return getF(n-1) + getF(n-2);
            }
        }
        
    }

    class CachedFibonacci:Fibonacci
    {
        Dictionary<int, int> cache;

        public CachedFibonacci()
        {
            this.cache = new Dictionary<int,int>();
        }
        
        public override int getF(int n)
        {
            Console.WriteLine("  POZVAN GET IZ CACHED FIBONACCIJA");
            if (this.cache.ContainsKey(n))
            {
                Console.WriteLine("  imam {0} u cacheu", n);
                return this.cache[n];
            }
            else
            {
                Console.WriteLine("  nemam {0}", n);
                int fib_n = base.getF(n);
                this.cache[n] = fib_n;
                return fib_n;
            }

        }
           
           
    }




    class Program
    {
        static void Main(string[] args)
        {

            Fibonacci f = new Fibonacci();
            CachedFibonacci cf = new CachedFibonacci();

            for (int a = 0; a < 5; a++)
            {
                Console.WriteLine("--------------{0}",cf.getF(a));
            }
            Console.ReadKey();

        }
    }



}

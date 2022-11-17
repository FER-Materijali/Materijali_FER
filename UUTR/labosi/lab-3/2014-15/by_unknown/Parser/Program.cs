using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Parser
{


    class Program
    {
        public static char slijedeciZnak()
        {
            char nextC;
            if (i < count)
            {
                nextC = input[i];
                i++;
            }
            else
            {
                nextC = '$';
            }
            return nextC;
        }

        public static void S()
        {
            zaIspis += 'S';
            if (ulaz == 'a')
            {
                ulaz = slijedeciZnak();
                A();
                if (jePrihvacen == false) return;
                B();
            }
            else if (ulaz == 'b')
            {
                ulaz = slijedeciZnak();
                B();
                if (jePrihvacen == false) return;
                A();
            }
            else
            {
                jePrihvacen = false;
            }
        }

        private static void A()
        {
            zaIspis += 'A';
            if (ulaz == 'b')
            {
                ulaz = slijedeciZnak();
                C();
            }
            else if (ulaz == 'a')
            {
                ulaz = slijedeciZnak();
            }
            else
            {
                jePrihvacen = false;
            }
        }

        private static void B() 
        {
            zaIspis += 'B';

            if (ulaz == 'c')
            {
                ulaz = slijedeciZnak();
                if (ulaz != 'c')
                {
                    jePrihvacen = false;
                    return;
                }
                ulaz = slijedeciZnak();
                S();
                if (ulaz != 'b')
                {
                    jePrihvacen = false;
                }
                ulaz = slijedeciZnak();
                if (ulaz != 'c')
                {
                    jePrihvacen = false;
                }
                ulaz = slijedeciZnak();

            }
            else if (ulaz == 'a' || ulaz == 'b' && jePrihvacen)
            {
                jePrihvacen = true;
                i--;
                ulaz = slijedeciZnak();
            }
            else if (ulaz != 'a' && ulaz != 'b' && ulaz != 'c' && jePrihvacen)
            {
                jePrihvacen = true;
            }
            else
            {
                jePrihvacen = false;
            }
        }

        private static void C()
        {
            zaIspis += 'C';
            A();
            if (jePrihvacen == false)
            {
                return;
            }
            A();
        }

        public static char ulaz;
        public static bool jePrihvacen = true;
        public static int i = 0;
        public static int count = 0;
        public static char[] input;
        public static string zaIspis = String.Empty;

        static void Main(string[] args)
        {
            input = Console.ReadLine().ToCharArray();

            count = input.Count();
            ulaz = slijedeciZnak();

            S();

            //nije sve procitano
            if (i < count - 1) jePrihvacen = false; 

            Console.WriteLine(zaIspis);

            if (jePrihvacen)
            {
                Console.WriteLine("DA");
            }
            else
            {
                Console.WriteLine("NE");
            }
        }
    }
}

using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace JP
{
    class Program
    {
        static void Main(string[] args)
        {
            bool korakOK = false;
            string tmp;
            int n = 0;
            while (!korakOK)
            {
                Console.WriteLine("Odaberi način rada programa:");
                Console.WriteLine("0: unos sa konzole");
                Console.WriteLine("1: unos iz datoteke");
                Console.WriteLine("2: predefinirani ulaz");
                tmp = Console.ReadLine();
                korakOK = Int32.TryParse(tmp, out n);
            }
            switch (n)
            {
                case 0:
                    UnosSaTipkovnice();
                    break;
                case 1:
                    UnosIzDatoteke();
                    break;
                case 2:
                    Test();
                    break;
                default:
                    Console.WriteLine("Mogućnost: " + n + " ne postoji, program završava");
                    break;
            }
        }

        private static void UnosIzDatoteke()
        {
            Console.Write("Unesi ime datoteke: ");
            string file = Console.ReadLine();
            StreamReader sr = new StreamReader(file);
            int count = Convert.ToInt32(sr.ReadLine());
            List<JP> input = new List<JP>();
            for (int i = 0; i < count; ++i)
            {
                input.Add(new JP(sr.ReadLine()));
            }
            JP requested = new JP(sr.ReadLine());

            Generator gen = new Generator(input, requested);
            string res = gen.Resolve();
            if (res != null)
                Console.WriteLine(res);
            else
                Console.WriteLine("Nije moguće izgraditi ciljni jezični procesor korištenjem raspoloživih jezičnih procesora!");
            Console.ReadKey();
        }

        private static void UnosSaTipkovnice()
        {
            bool korakOK = false;
            string tmp;
            int n = 0;
            while (!korakOK)
            {
                Console.WriteLine("Unesi broj jezičnih procesora u početnom skupu: ");
                tmp = Console.ReadLine();
                korakOK = Int32.TryParse(tmp, out n);
            }
            Console.WriteLine("Unesi {0} jezična procesora, svaki u svojoj liniji u obliku:", n);
            Console.WriteLine("izvorniJezik,ciljniJezik,jezikIzgradnje");

            List<JP> input = new List<JP>();
            for (int i = 0; i < n; ++i)
            {
                tmp = Console.ReadLine();
                input.Add(new JP(tmp));
            }

            Console.WriteLine("Unesi traženi jezični procesor:");
            tmp = Console.ReadLine();
            JP requested = new JP(tmp);

            Generator gen = new Generator(input, requested);
            string res = gen.Resolve();
            if (res != null)
                Console.WriteLine(res);
            else
                Console.WriteLine("Nije moguće izgraditi ciljni jezični procesor korištenjem raspoloživih jezičnih procesora!");
            Console.ReadKey();
        }

        private static void Test()
        {
            List<JP> input = new List<JP>();
            input.Add(new JP("X", "Y", "a"));
            input.Add(new JP("X", "Y", "b"));
            input.Add(new JP("X", "K", "Z"));
            input.Add(new JP("Z", "b", "a"));
            input.Add(new JP("Y", "Z", "a"));
            input.Add(new JP("Z", "K", "a"));
            input.Add(new JP("K", "P", "C"));
            input.Add(new JP("C", "X", "a"));
            input.Add(new JP("X", "a", "a"));
            input.Add(new JP("P", "C", "a"));
            JP requested = new JP("X", "C", "a");
            //JP requested = new JP("Z", "K", "a");
            Generator gen = new Generator(input, requested);
            string res = gen.Resolve();
            if (res != null)
                Console.WriteLine(res);
            else
                Console.WriteLine("Nije moguće izgraditi ciljni jezični procesor korištenjem raspoloživih jezičnih procesora!");
            Console.ReadKey();
        }
    }
}

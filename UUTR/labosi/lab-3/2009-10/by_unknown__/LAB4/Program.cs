using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace LAB4
{
    class Simulator
    {
        public struct prijelaz
        {
            public string stanje, znak, novo, zapis, pomak;
        }

        //prijelaz temp;
        prijelaz[] funkcije;
        string trenutnoStanje, traka;
        int glava;

        public Simulator()
        {
            trenutnoStanje = "1";
            glava = 0;
            funkcije = new prijelaz[18];

            CitajTrakuDef();
            traka = traka + "_";
        }

        private void Ispis()
        {
            string traka1;
            traka1 = traka.Trim('_');
            Console.WriteLine("Traka: {0} Glava: {1}", traka1, glava + 1);
            Console.WriteLine();
        }

        private void PromjenaTrake(string zap)
        {
            string[] splitter = new string[999];

            for (int i = 0; i < traka.Length; i++)
            {
                splitter[i] = Convert.ToString(traka[i]);
            }

            splitter[glava] = zap;
            traka = "";

            foreach (string s in splitter)
            {
                traka = traka + s;
            }

            traka = traka + "_";
        }

        private void SljedeceStanje()
        {
            while (true)
            {
                for (int i = 0; i < 18; i++)
                {
                    if ((funkcije[i].stanje == trenutnoStanje) && (Convert.ToChar(funkcije[i].znak) == traka[glava]))
                    {
                        trenutnoStanje = funkcije[i].novo;

                        PromjenaTrake(funkcije[i].zapis);

                        if (funkcije[i].pomak.Equals("l")) glava--;
                        else glava++;

                        break;
                    }
                }

                if (trenutnoStanje == "H") { Console.WriteLine("GOTOVO"); return; }

                Ispis();
            }
        }

        private void CitajTrakuDef()
        {
            using (StreamReader sr = new StreamReader("definicijaTS.txt"))
            {
                int i = 0;
                string linija;
                string[] splitter;

                while ((linija = sr.ReadLine()) != null)
                {
                    splitter = linija.Split(' ');

                    funkcije[i].stanje = splitter[0];
                    funkcije[i].znak = splitter[1];
                    funkcije[i].novo = splitter[2];
                    funkcije[i].zapis = splitter[3];
                    funkcije[i].pomak = splitter[4];

                    i++;
                }
            }

            using (StreamReader sr = new StreamReader("traka.txt"))
            {
                traka = sr.ReadLine();
            }

            /*Console.Write("Upisi neki broj za pozicioniranje glave: ");
            glava = Convert.ToInt32(Console.ReadLine()) % traka.Length;
            Console.WriteLine("\n");*/

            Ispis();
            SljedeceStanje();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Simulator sim = new Simulator();
            Console.ReadLine();
        }
    }
}

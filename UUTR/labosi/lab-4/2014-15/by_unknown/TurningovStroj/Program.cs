using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TurningovStroj
{
    class Program
    {
        private static List<string> skupStanja = new List<string>();
        private static List<string> skupUlaznihZnakova = new List<string>();
        private static List<string> skupZnakovaTrake = new List<string>();
        private static string praznaCelija = String.Empty;
        private static char[] txtZapisTrake;
        private static List<string> prihvatljivaStanja = new List<string>();
        private static string pocetnoStanje = String.Empty;
        private static int pocetniPolozajGlave = 0;
        

        static void Main(string[] args)
        {
            string skSt = Console.ReadLine();
            string skUlZn = Console.ReadLine();
            string skZnTr = Console.ReadLine();
            praznaCelija = Console.ReadLine();
            txtZapisTrake = Console.ReadLine().ToCharArray();
            string prSt = Console.ReadLine();
            pocetnoStanje = Console.ReadLine();
            pocetniPolozajGlave = Int32.Parse(Console.ReadLine());

            skupStanja = napuniListe(skSt);
            skupUlaznihZnakova = napuniListe(skUlZn);
            skupZnakovaTrake = napuniListe(skZnTr);
            prihvatljivaStanja = napuniListe(prSt);

            Dictionary<string, string> funkcijaPrijelaza = new Dictionary<string, string>();
            string line = "not empty";
            while (!String.IsNullOrEmpty(line))
            {
                line = Console.ReadLine();
                if (line != null)
                {
                    if (!funkcijaPrijelaza.ContainsKey(
                        line.Split(new string[] { "->" }, StringSplitOptions.None)[0])
                        )
                    {
                        funkcijaPrijelaza.Add(
                            line.Split(new string[] { "->" }, StringSplitOptions.None)[0],
                            line.Split(new string[] { "->" }, StringSplitOptions.None)[1]
                            ); 
                    }
                }
            }

            string trenutnoStanje = pocetnoStanje;
            int i = pocetniPolozajGlave;
            string zaIspis = String.Empty;
            /* simulacija */
            while (true)
            {
                string key = trenutnoStanje + "," + txtZapisTrake[i];
                if (i == 0 && funkcijaPrijelaza.ContainsKey(key))
                {
                    if (funkcijaPrijelaza[key].Split(',')[2] == "L")
                    {
                        break;
                    }
                }
                else if (i == 69 && funkcijaPrijelaza.ContainsKey(key))
                {
                    if (funkcijaPrijelaza[key].Split(',')[2] == "R")
                    {
                        break;
                    }
                }

                if (funkcijaPrijelaza.ContainsKey(key))
                {
                    string novoStanje = funkcijaPrijelaza[key].Split(',')[0];
                    char noviZnakNaTraci = Char.Parse(funkcijaPrijelaza[key].Split(',')[1]);
                    string pomak = funkcijaPrijelaza[key].Split(',')[2];

                    trenutnoStanje = novoStanje;
                    txtZapisTrake[i] = noviZnakNaTraci;
                    if (pomak == "R")
                    {
                        i++;
                    }
                    else
                    {
                        i--;
                    }
                }
                else
                {
                    break;
                }

            }

            zaIspis = trenutnoStanje + "|" + i.ToString() + "|" + String.Join("", txtZapisTrake);
            if (prihvatljivaStanja.Contains(trenutnoStanje))
            {
                zaIspis += "|1";
            }
            else
            {
                zaIspis += "|0";
            }
            Console.WriteLine(zaIspis);
        }

        private static List<string> napuniListe(string input)
        {
            List<string> lista = new List<string>();
            foreach (var item in input.Split(','))
            {
                lista.Add(item);
            }
            lista.Sort();
            return lista;
        }
    }
}

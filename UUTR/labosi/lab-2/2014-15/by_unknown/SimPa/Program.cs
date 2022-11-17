using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace SimPa
{
    class Program
    {
        public static string sadrzajStoga(Stack<string> stog)
        {
            string sadrzaj = String.Empty;
            Stack<string> pomocniStog = new Stack<string>();
            pomocniStog = stog;

            foreach (var x in pomocniStog)
            {
                sadrzaj += x;
            }
            return sadrzaj;
        }

        public static void DodajNaStog(Stack<string> stog, string noviZnaci)
        {
            stog.Pop();
            char[] arry = noviZnaci.ToCharArray();
            foreach (var item in arry.Reverse())
            {
                if (item != '$')
                {
                    stog.Push(item.ToString());
                }
            }
        }

        static void Main(string[] args)
        {
            string ulNi = Console.ReadLine();
            string skupSt = Console.ReadLine();
            string skupUlZn = Console.ReadLine();
            string skupZnSt = Console.ReadLine();
            string skupPrihvSt = Console.ReadLine();
            string pocetnoStanje = Console.ReadLine();
            string pocetniZnakStoga = Console.ReadLine();

            /**********************************************************/
            /***************** UČITAVANJE DEFINICIJE ******************/
            /**********************************************************/
            List<string> skupPrihvatljivihStanja = new List<string>();
            foreach (var stanje in skupPrihvSt.Split(','))
            {
                skupPrihvatljivihStanja.Add(stanje);
            }

            List<string> skupStanja = new List<string>();
            foreach (var stanje in skupSt.Split(','))
            {
                skupStanja.Add(stanje);
            }

            List<string> skupUlaznihZnakova = new List<string>();
            foreach (var znak in skupUlZn.Split(','))
            {
                skupUlaznihZnakova.Add(znak);
            }

            List<string> ulazniNizovi = new List<string>();
            foreach (var niz in ulNi.Split('|'))
            {
                ulazniNizovi.Add(niz);
            }

            List<string> skupZnakovaStoga = new List<string>();
            foreach (var znak in skupZnSt.Split(','))
            {
                skupZnakovaStoga.Add(znak);
            }

            skupPrihvatljivihStanja.Sort();
            skupStanja.Sort();
            skupUlaznihZnakova.Sort();
            ulazniNizovi.Sort();
            skupZnakovaStoga.Sort();
            /**********************************************************/
            /************** FUNKCIJA PRIJELAZA ************************/
            /**********************************************************/
            string line = "Not Empty";
            Dictionary<string, string> funkcijaPrijelaza = new Dictionary<string, string>();

            while (!String.IsNullOrEmpty(line))
            {
                line = Console.ReadLine();
                if (line != null)
                {
                    funkcijaPrijelaza.Add(
                        line.Split(new string[] { "->" }, StringSplitOptions.None)[0],
                        line.Split(new string[] { "->" }, StringSplitOptions.None)[1]
                        );
                }
            }
            /**********************************************************/
            /**********************************************************/
            Stack<string> stog = new Stack<string>();
            string privremenoTrStanje = String.Empty;
            string key = String.Empty;
            string trenutnoStanje = String.Empty;
            string znakSaStoga = String.Empty;
            string zaIspis = String.Empty;
            string noviZnakSaStoga = String.Empty;
            string[] znakovi;
            string prijelaz = String.Empty;
            string znakic = String.Empty;
            int i = 0;

            foreach (var niz in ulazniNizovi)
            {
                stog.Clear();
                stog.Push(pocetniZnakStoga);
                trenutnoStanje = pocetnoStanje;
                zaIspis = String.Empty;
                zaIspis += pocetnoStanje + "#" + stog.Peek();
                znakovi = niz.Split(',');
                i = 0;

                while (i < znakovi.Length)
                {
                    znakic = znakovi[i];
                    privremenoTrStanje = trenutnoStanje;
                    znakSaStoga = stog.Peek();

                    key = privremenoTrStanje + "," + znakic + "," + znakSaStoga;

                    if (funkcijaPrijelaza.ContainsKey(key))
                    {
                        prijelaz = funkcijaPrijelaza[key].Split(',')[0];
                        noviZnakSaStoga = funkcijaPrijelaza[key].Split(',')[1];
                        DodajNaStog(stog, noviZnakSaStoga);
                        if (stog.Count != 0)
                        {
                            zaIspis += "|" + prijelaz + "#" + sadrzajStoga(stog);
                            i++;
                        }
                        else
                        {
                            zaIspis += "|" + prijelaz + "#$" + "|fail|0";
                            break;
                        }
                    }
                    else
                    {
                        key = privremenoTrStanje + ",$," + znakSaStoga;
                        if (funkcijaPrijelaza.ContainsKey(key))
                        {
                            prijelaz = funkcijaPrijelaza[key].Split(',')[0];
                            noviZnakSaStoga = funkcijaPrijelaza[key].Split(',')[1];
                            DodajNaStog(stog, noviZnakSaStoga);

                            if (stog.Count != 0)
                            {
                                zaIspis += "|" + prijelaz + "#" + sadrzajStoga(stog);
                            }
                            else
                            {
                                zaIspis += "|" + prijelaz + "#$" + "|fail|0";
                                break;
                            }
                        }
                        else
                        {
                            zaIspis += "|fail|0";
                            break;
                        }

                    }
                    trenutnoStanje = prijelaz;

                }

                if (!Regex.IsMatch(zaIspis, "fail") && skupPrihvatljivihStanja.Contains(trenutnoStanje))
                {
                    zaIspis += "|1";
                }
                else if (!Regex.IsMatch(zaIspis, "fail") && !skupPrihvatljivihStanja.Contains(trenutnoStanje))
                {
                    prijelaz = trenutnoStanje;
                    while (true)
                    {

                        key = prijelaz + ",$," + stog.Peek();
                        if (funkcijaPrijelaza.ContainsKey(key))
                        {
                            prijelaz = funkcijaPrijelaza[key].Split(',')[0];
                            noviZnakSaStoga = funkcijaPrijelaza[key].Split(',')[1];
                            DodajNaStog(stog, noviZnakSaStoga);
                            if (stog.Count != 0)
                            {
                                if (skupPrihvatljivihStanja.Contains(prijelaz))
                                {
                                    zaIspis += "|" + prijelaz + "#" + sadrzajStoga(stog) + "|1";
                                    break;
                                }
                                else
                                {
                                    zaIspis += "|" + prijelaz + "#" + sadrzajStoga(stog);
                                }
                            }
                            else
                            {
                                if (skupPrihvatljivihStanja.Contains(prijelaz))
                                {
                                    zaIspis += "|" + prijelaz + "#$|1";
                                    break;
                                }
                                else
                                {
                                    zaIspis += "|" + prijelaz + "#$|fail|0";
                                    break;
                                }
                            }

                        }
                        else
                        {
                            zaIspis += "|0";
                            break;
                        }

                    }
                }
                Console.WriteLine(zaIspis);
            }
        }
    }
}

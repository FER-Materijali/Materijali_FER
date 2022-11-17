using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DKAminimizacija
{
    class Program
    {
        static void Main(string[] args)
        {
            string svaStanja = Console.ReadLine();
            string skupSimbolaAbecede = Console.ReadLine();
            string skupPrihvatljivihStanja = Console.ReadLine();
            string pocetnoStanje = Console.ReadLine();
            string line = "not empty";
            

            List<string> skupStanja = new List<string>();
            List<string> minimiziraniDKA = new List<string>();

            foreach (var stanje in svaStanja.Split(','))
            {
                skupStanja.Add(stanje);
                minimiziraniDKA.Add(stanje);
            }
            skupStanja.Sort();

            /***********************************************************************************/
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
            /***********************************************************************************/
            /***********************************************************************************/
            List<string> prihvatljivaStanja = new List<string>();
            List<string> neprihvatljivaStanja = new List<string>();

            foreach (var pStanje in skupPrihvatljivihStanja.Split(','))
            {
                prihvatljivaStanja.Add(pStanje);
            }
            prihvatljivaStanja.Sort();

            foreach (var nStanje in skupStanja)
            {
                if (!prihvatljivaStanja.Contains(nStanje))
                {
                    neprihvatljivaStanja.Add(nStanje);
                }
            }
            neprihvatljivaStanja.Sort();
            /************************************************************************************/


            Dictionary<string, bool> tablica = new Dictionary<string, bool>();
            Dictionary<string, string> funkcijaPrijelaza2 = new Dictionary<string, string>();
            List<string> dohvatljivaStanja = new List<string>();
            List<string> trenutnoNovoStanje = new List<string>();
            List<string> prethodnoNovoStanje = new List<string>();
            prethodnoNovoStanje.Add(pocetnoStanje);
            dohvatljivaStanja.Add(pocetnoStanje);
            bool imaPromjena = true;

           

            List<string> nedohvatljivaStanja = new List<string>();

            trenutnoNovoStanje.Add(pocetnoStanje);
            while (imaPromjena)
            {
                imaPromjena = false;
                foreach (var stanje in trenutnoNovoStanje)
                {
                    foreach (var simbol in skupSimbolaAbecede.Split(','))
                    {

                        if (!dohvatljivaStanja.Contains(funkcijaPrijelaza[stanje + "," + simbol]))
                        {
                            dohvatljivaStanja.Add(funkcijaPrijelaza[stanje + "," + simbol]);
                            imaPromjena = true;
                        }
                    }
                    
                }
                trenutnoNovoStanje.AddRange(dohvatljivaStanja);
                trenutnoNovoStanje.Distinct().ToList();
            }
            dohvatljivaStanja.Sort();
            dohvatljivaStanja.Distinct().ToList();

            foreach (var stanje in dohvatljivaStanja)
            {
                foreach (var simbol in skupSimbolaAbecede.Split(','))
                {
                    funkcijaPrijelaza2.Add(stanje + "," + simbol, funkcijaPrijelaza[stanje + "," + simbol]);
                }
            }
            foreach (var stanje in skupStanja)
            {
                if (!dohvatljivaStanja.Contains(stanje))
                {
                    nedohvatljivaStanja.Add(stanje);
                }
            }

            skupStanja.Clear();
            skupStanja.AddRange(dohvatljivaStanja);
            minimiziraniDKA.Clear();
            minimiziraniDKA.AddRange(dohvatljivaStanja);
            funkcijaPrijelaza = funkcijaPrijelaza2;


            foreach (var pStanje in prihvatljivaStanja)
            {
                foreach (var nStanje in neprihvatljivaStanja)
                {

                    if (!tablica.ContainsKey(pStanje + "," + nStanje))
                    {
                        tablica.Add(pStanje + "," + nStanje, true);
                    }
                }
            }
            prihvatljivaStanja.Sort();
            neprihvatljivaStanja.Sort();
            string temp1 = String.Empty;
            string temp2 = String.Empty;

            for (int i = 0; i < skupStanja.Count() - 1; i++)
            {
                for (int j = i + 1; j < skupStanja.Count(); j++)
                {
                    foreach (var simbol in skupSimbolaAbecede.Split(','))
                    {
                        temp1 = skupStanja[i] + "," + simbol;
                        temp2 = skupStanja[j] + "," + simbol;

                        if (tablica.ContainsKey(funkcijaPrijelaza[temp1] + "," + funkcijaPrijelaza[temp2]) ||
                            tablica.ContainsKey(funkcijaPrijelaza[temp2] + "," + funkcijaPrijelaza[temp1]))
                        {
                            if (!tablica.ContainsKey(skupStanja[i] + "," + skupStanja[j]))
                            {
                                tablica.Add(skupStanja[i] + "," + skupStanja[j], true);
                            }
                        }

                    }
                }
            }
            List<string> tablicaZaUsporedbu = new List<string>();
            List<string> tempLista = new List<string>();
            List<string> istovjetnaStanja = new List<string>();

            for (int i = 0; i < skupStanja.Count() - 1; i++)
            {
                for (int j = i + 1; j < skupStanja.Count(); j++)
                {
                    tablicaZaUsporedbu.Add(skupStanja[i] + "," + skupStanja[j]);
                }
            }

            foreach (var par in tablicaZaUsporedbu)
            {
                temp1 = par.Split(',')[0];
                temp2 = par.Split(',')[1];

                if (!tablica.ContainsKey(temp1 + "," + temp2) &&
                    !tablica.ContainsKey(temp2 + "," + temp1))
                {
                    tempLista.Add(temp1);
                    tempLista.Add(temp2);
                    tempLista.Sort();
                    istovjetnaStanja.Add(tempLista[0] + "," + tempLista[1]);
                    minimiziraniDKA.Remove(tempLista[1]);
                    tempLista.Clear();

                }
            }

            /***************************** ISPIS ******************************************/

            minimiziraniDKA.Sort();
            string noviSkupStanja = String.Empty;
            List<string> noviPrihvatljivihSkupStanja = new List<string>();

            noviSkupStanja = String.Join(",", minimiziraniDKA);
            Console.WriteLine(noviSkupStanja);
            Console.WriteLine(skupSimbolaAbecede);
            if (!String.IsNullOrEmpty(skupPrihvatljivihStanja))
            {
                foreach (var stanje in skupPrihvatljivihStanja.Split(','))
                {
                    if (minimiziraniDKA.Contains(stanje))
                    {
                        noviPrihvatljivihSkupStanja.Add(stanje);
                    }

                }
                Console.WriteLine(String.Join(",", noviPrihvatljivihSkupStanja));
            }
            else
            {
                Console.WriteLine("\n");
            }
            if (!nedohvatljivaStanja.Contains(pocetnoStanje))
            {
                if (!minimiziraniDKA.Contains(pocetnoStanje))
                {
                    foreach (var item in istovjetnaStanja)
                    {
                        if (pocetnoStanje == item.Split(',')[1])
                        {
                            pocetnoStanje = item.Split(',')[0];
                        }

                    }
                }
                Console.WriteLine(pocetnoStanje);
            }
            else
            {
                Console.WriteLine("\n");
            }

            string zaIspis = String.Empty;
            string istSt = String.Empty;

            /****************************** ISPIS STANJA minDKA ****************************************/
            foreach (var stanje in minimiziraniDKA)
            {
                foreach (var simbol in skupSimbolaAbecede.Split(','))
                {
                    if (!minimiziraniDKA.Contains(funkcijaPrijelaza[stanje + "," + simbol]))
                    {
                        foreach (var item in istovjetnaStanja)
                        {
                            if (funkcijaPrijelaza[stanje + "," + simbol] == item.Split(',')[1])
                            {
                                istSt = item.Split(',')[0];
                                zaIspis = String.Empty;
                                zaIspis = stanje + "," + simbol + @"->" + istSt + "\n";
                                if (minimiziraniDKA.Contains(istSt))
                                {

                                    Console.Write(zaIspis); 
                                }
                                zaIspis = String.Empty;
                            }

                        }
                    }
                    else
                    {
                        zaIspis = stanje + "," + simbol + @"->" + funkcijaPrijelaza[stanje + "," + simbol];
                        Console.WriteLine(zaIspis);
                        zaIspis = String.Empty;
                    }
                }
            }
        }
    }
}
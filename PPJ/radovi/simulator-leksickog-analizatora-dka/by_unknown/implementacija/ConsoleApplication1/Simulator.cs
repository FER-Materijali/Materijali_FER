//#define debug

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace SSP_Simulator_LEXa
{
    class Simulator
    {
        private List<string> DKAStanja = new List<string>();
        private List<string> DKAPrijelazi = new List<string>();
        private List<string> ulaznaAbeceda = new List<string>();

        public void SimulatorMain()
        {
            odrediUlaznuAbecedu();
            napraviDKAPrijelaze();
            Simulacija();
        }

        private void odrediUlaznuAbecedu () 
        {
            string ulaz = "" ;
            foreach ( List<string> listaPrijelaza in MainClass.prijelazi )
                foreach (string prijelaz in listaPrijelaza)
                {
                    ulaz = prijelaz.Split(' ')[1];
                    if (ulaznaAbeceda.Contains(ulaz) == false)
                    {
                        ulaznaAbeceda.Add(ulaz);
#if debug
                        Console.Write(ulaz);
#endif
                    }
                }
            Console.WriteLine("");
        }

        private void napraviDKAPrijelaze()
        {
            string pocetnoStanje = "";
            for (int i = 0; i < MainClass.prijelazi.Count; i++)
                pocetnoStanje += i.ToString() + "-0,";
            DKAStanja.Add(pocetnoStanje.Remove(pocetnoStanje.Length-1));

            for ( int i = 0 ; i < DKAStanja.Count ; i++ )
            {
#if debug
                Console.WriteLine ("  NKA stanje " + i.ToString() );
#endif
                string stanjaZaPojediniUlaz = "" ;
                string[] stanja = DKAStanja[i].Split(',') ;
                foreach ( string ulazniZnak in ulaznaAbeceda )
                {
#if debug
                    Console.WriteLine(" za ulazni znak --> " + ulazniZnak );
#endif
                    stanjaZaPojediniUlaz = "";
                    foreach ( string stanje in stanja )
                    {
                        foreach ( List<string> listaPrijelaza in MainClass.prijelazi )
                            foreach (string prijelaz in listaPrijelaza)
                            {
                                if ( stanje == prijelaz.Split(' ')[0] && ulazniZnak == prijelaz.Split(' ')[1] )
                                    stanjaZaPojediniUlaz += prijelaz.Split(' ')[2] + ",";
                            }
                    }
                    if ( stanjaZaPojediniUlaz.Length > 0 )
                    {
                        stanjaZaPojediniUlaz = stanjaZaPojediniUlaz.Remove(stanjaZaPojediniUlaz.Length - 1);
                        if ( DKAPrijelazi.Contains(DKAStanja[i] + " " + ulazniZnak + " " + stanjaZaPojediniUlaz )== false  )
                        DKAPrijelazi.Add(DKAStanja[i] + " " + ulazniZnak + " " + stanjaZaPojediniUlaz);
#if debug
                        Console.WriteLine("dodan prijelaz --> " + DKAStanja[i] + " " + ulazniZnak + " " + stanjaZaPojediniUlaz);
#endif
                        if ( DKAStanja.Contains(stanjaZaPojediniUlaz) == false  ) 
                        DKAStanja.Add(stanjaZaPojediniUlaz);
                    }
                }
            }
        }

        private void Simulacija ()
        {
            string[] linije = File.ReadAllLines("regularniIzrazi.txt");
            string[] imenaDefinicije = new string[linije.Length];
            for (int i = 0; i < linije.Length; i++)
            {
                string[] pom = linije[i].Split(' ');
                imenaDefinicije[i] = pom[0];
            }

            int početak = 0, posljednji = 0, izraz = -1;
            string ulazniNiz = File.ReadAllText("ulaz.txt").Replace(" " ,"");
            string trenutnoStanje = DKAStanja[0], novoStanje = "", grupiraneLexičkeJedinke="" ;
            bool postojiPrijelaz;

            for (int završetak = 0; završetak < ulazniNiz.Length+1 ; )
            {
                postojiPrijelaz = false;

                foreach (string prijelaz in DKAPrijelazi)
                {
                    postojiPrijelaz = false;
                    if (završetak == ulazniNiz.Length)
                        break;
                    if (prijelaz.Split(' ')[0] == trenutnoStanje && ulazniNiz[završetak].ToString() == prijelaz.Split(' ')[1])
                    {
                        postojiPrijelaz = true;
                        novoStanje = prijelaz.Split(' ')[2];
                        break;
                    }
                }

                if (ispitajPrihvatljivost(trenutnoStanje) == false && postojiPrijelaz == true)
                {
                    Console.WriteLine("\n       " + ulazniNiz);
                    Console.WriteLine("pocetak = " + početak + "   završetak = " + završetak + "   posljednji = " + posljednji + " izraz = " + izraz);
                    ++završetak;
                    trenutnoStanje = novoStanje;
                    
                }
                else if (ispitajPrihvatljivost(trenutnoStanje) == true && postojiPrijelaz == true)
                {
                    izraz = odaberiIzraz(trenutnoStanje);
                    posljednji = završetak;
                    Console.WriteLine("\n       " + ulazniNiz);
                    Console.WriteLine("pocetak = " + početak + "   završetak = " + završetak + "   posljednji = " + posljednji + " izraz = " + izraz);
                    ++završetak;
                    trenutnoStanje = novoStanje;
                }

                if (postojiPrijelaz == false)
                {
                    if (ispitajPrihvatljivost(trenutnoStanje) == true)
                    {
                        izraz = odaberiIzraz(trenutnoStanje);
                        posljednji = završetak-1;
                    }
                    if (početak == ulazniNiz.Length - 1)
                    {
                        Console.WriteLine("\n       " + ulazniNiz);
                        Console.WriteLine("pocetak = " + početak + "   završetak = " + završetak + "   posljednji = " + posljednji + " izraz = " + izraz);
                        Console.WriteLine("\n    Odbacuje se znak \"" + ulazniNiz[početak] + "\" jer ne postoji prefiks za grupiranje!");
                        break;
                    }

                    if (izraz == -1)
                    {
                        if (početak == ulazniNiz.Length)
                            break;
                        Console.WriteLine("\n       " + ulazniNiz);
                        Console.WriteLine("pocetak = " + početak + "   završetak = " + završetak + "   posljednji = " + posljednji + " izraz = " + izraz);
                        Console.WriteLine("\n    Odbacuje se znak \"" + ulazniNiz[početak] + "\" jer ne postoji prefiks za grupiranje!");
                        završetak = ++početak;
                        posljednji = početak;
                        trenutnoStanje = DKAStanja[0];
                    }
                    else
                    {
                        Console.WriteLine("\n       " + ulazniNiz);
                        Console.WriteLine("pocetak = " + početak + "   završetak = " + završetak + "   posljednji = " + posljednji + " izraz = " + izraz);
                        Console.WriteLine("\n   Niz znakova \"" + ulazniNiz.Substring(početak , 1+ posljednji - početak) + "\" grupira se u lexičku jedinku \""+imenaDefinicije[System.Convert.ToInt32(trenutnoStanje.Split('-')[0])]+"\" !");
                        grupiraneLexičkeJedinke += ulazniNiz.Substring(početak, 1 + posljednji - početak) + "  ";
                        if (završetak == ulazniNiz.Length)
                            break;
                        izraz = -1;
                        završetak = ++posljednji;
                        početak = posljednji;
                        
                        trenutnoStanje = DKAStanja[0];
                    }
                    
                }
                
            }
            Console.WriteLine("\n\nGrupirane leksičke jedinke:  " + grupiraneLexičkeJedinke);
        }

        private bool ispitajPrihvatljivost(string stanja)
        {
            string[] trenutnaStanja = stanja.Split(',');

            foreach (string stanje in trenutnaStanja)
            {
                
                if (MainClass.prihvatljivaStanja[System.Convert.ToInt32(stanje.Split('-')[0])] .Contains(stanje) == true)
                    return true;
            }
            return false;
        }

        private int odaberiIzraz (string stanja)
        {
            string[] trenutnaStanja = stanja.Split(',');

            foreach (string stanje in trenutnaStanja)
            {
                if (MainClass.prihvatljivaStanja.Contains(stanje) == true)
                    System.Convert.ToInt32(stanje.Split('-')[0]);
                return System.Convert.ToInt32(stanje.Split('-')[0]);
            }
            return -1;
        }
    }

}

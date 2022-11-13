using System;
using System.IO;
using System.Collections.Generic;
using Db4objects.Db4o;
using Db4objects.Db4o.NativeQueries;

namespace ConsoleApplication1
{
    public class Manage
    {
        public readonly static string YapFileName ="pripremaZaPrviMI.yap"; 

        //Ova funkcija ispisuje QBE i NQ rezultate
        public static void ListResult(IObjectSet result)
        {
            foreach (object item in result)
            {
                if (item.GetType() == typeof(Pilot))
                {
                    Pilot pilot = (Pilot)item;
                    Console.WriteLine("{0} {1} {2} {3} {4}",pilot.Ime,pilot.Prezime,pilot.Sifra,pilot.Momcad.Naziv,pilot.Vrsta);
                }
                if (item.GetType() == typeof(Drzava))
                {
                    Drzava drzava = (Drzava)item;
                    Console.WriteLine("{0} {1}", drzava.Naziv, drzava.Oznaka);
                }
                if (item.GetType() == typeof(Staza))
                {
                    Staza staza = (Staza)item;
                    Console.WriteLine("{0} {1} {2}", staza.Naziv, staza.Drzava.Naziv, staza.Rekord);
                }
                
            }
        }
        //Ova funkcija ispisuje LINQ rezultate
        public static void ListResult<T>(IEnumerable<T> result)
        {
            foreach (object item in result)
            {
                if (item.GetType() == typeof(Pilot))
                {
                    Pilot p = (Pilot)item;
                    Console.WriteLine("{0} {1} {2} {3} {4}", p.Ime, p.Prezime, p.Sifra, p.Momcad.Naziv, p.Vrsta);
                }
                if (item.GetType() == typeof(Drzava))
                {
                    Drzava dr = (Drzava)item;
                    Console.WriteLine("{0} {1}", dr.Naziv, dr.Oznaka);
                }
                if (item.GetType() == typeof(Staza))
                {
                    Staza staza = (Staza)item;
                    Console.WriteLine("{0} {1} {2}", staza.Naziv, staza.Drzava.Naziv, staza.Rekord);
                }
            }
        }
    }
}

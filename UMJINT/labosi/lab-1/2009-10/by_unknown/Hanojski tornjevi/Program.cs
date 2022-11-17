using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Hanojski_tornjevi
{
    class Program
    {
        static void Main()  //static void Main(string[] args)
        {
            Tornjevi.brojacIdentifikacijskogBroja = 1;
            odaberiBrojDiskova();
            odaberiAlgoritam();

            Cvor pocetniCvor = stvoriPocetniCvor();
            Cvor ciljniCvor = stvoriCiljniCvor();
            Tornjevi.otvoreniCvorovi.Add(pocetniCvor);

            Cvor trenutniCvor = new Cvor();
     
            while (true)
            {
                trenutniCvor = Tornjevi.otvoreniCvorovi[0];
                Tornjevi.otvoreniCvorovi.Remove(trenutniCvor); 
                Tornjevi.posjeceniCvorovi.Add(trenutniCvor); 
                if (trenutniCvor.jednak(ciljniCvor)) break;
                prosiriCvor(trenutniCvor);
            }

            napuniListuZaCrtanje(trenutniCvor);

            for (int redniBroj=0; redniBroj < Tornjevi.ListaZaCrtati.Count; redniBroj++)
                Cvor.crtajCvor(Tornjevi.ListaZaCrtati[redniBroj]);
        }

        //ako je čvor proširiv, zove metodu stvoriCvor, koja stvara dijete trenutnog čvora
        public static void prosiriCvor(Cvor trenutniCvor)
        {
            for (int stapSkini = 0; stapSkini < 3; stapSkini++)
                for(int stapStavi = 0; stapStavi < 3; stapStavi++)
                    if (stapStavi != stapSkini)
                    {
                        Cvor noviCvor = stvoriCvor(trenutniCvor, stapSkini, stapStavi);
                        if (noviCvor != null)
                        {
                            if (!posjeceniSadrze(noviCvor))
                            {
                                if (Tornjevi.odabirAlgoritma == 1)
                                    Tornjevi.otvoreniCvorovi.Add(noviCvor);
                                else if (Tornjevi.odabirAlgoritma == 2)
                                    Tornjevi.otvoreniCvorovi.Insert(0,noviCvor);
                            }
                        }
                    }

        }

        public static Cvor stvoriCvor(Cvor trenutniCvor, int stapSkini, int stapStavi)
        {
            bool stvoriIsOK = false;

            int najmanjiDisk = 0;
            while (najmanjiDisk < Tornjevi.brojDiskova)
            {
                if (trenutniCvor.naStapuDisk[stapSkini][najmanjiDisk] == 1)
                {
                    stvoriIsOK = true;
                    break;
                }
                if (trenutniCvor.naStapuDisk[stapStavi][najmanjiDisk] == 1)
                {
                    break;
                }
                najmanjiDisk++;
            }

            //ako je moguće stvoriti novi čvor, stvara ga
            if (stvoriIsOK)
            {
                Cvor noviCvor = new Cvor();

                //kopiramo trenutni čvor u novi
                for (int brojStapa = 0; brojStapa < 3; brojStapa++)
                    for (int pozicijaNaStapu = 0; pozicijaNaStapu < Tornjevi.brojDiskova; pozicijaNaStapu++)
                        noviCvor.naStapuDisk[brojStapa][pozicijaNaStapu] = trenutniCvor.naStapuDisk[brojStapa][pozicijaNaStapu];

                //mijenjamo potrebne podatke
                noviCvor.naStapuDisk[stapSkini][najmanjiDisk] = 0;
                noviCvor.naStapuDisk[stapStavi][najmanjiDisk] = 1;
                noviCvor.identifikacijskiBroj = Tornjevi.brojacIdentifikacijskogBroja;
                Tornjevi.brojacIdentifikacijskogBroja++;
                noviCvor.identifikacijskiBrojRoditelja = trenutniCvor.identifikacijskiBroj;

                return noviCvor;
            }
            return null;
        }

        public static void odaberiBrojDiskova()
        {
            Console.WriteLine("Unesite broj diskova");
            Tornjevi.brojDiskova = int.Parse(Console.ReadLine());
        }

        public static void odaberiAlgoritam()
        {
            while (true)
            {
                Console.WriteLine("Odaberite algoritam \n 1 - pretraživanje u širinu \n 2 - pretraživanje u dubinu");
                Tornjevi.odabirAlgoritma = int.Parse(Console.ReadLine());

                if (Tornjevi.odabirAlgoritma == 1 || Tornjevi.odabirAlgoritma == 2)
                {
                    break;
                }
                else
                {
                    Console.WriteLine("Unijeli ste krivi broj");
                }
            }
        }

        //inicijalizira početni čvor
        public static Cvor stvoriPocetniCvor()
        {
            Cvor pocetniCvor = new Cvor();
            pocetniCvor.identifikacijskiBroj = Tornjevi.brojacIdentifikacijskogBroja;
            Tornjevi.brojacIdentifikacijskogBroja++;
            for (int pozicijaNaStapu = 0; pozicijaNaStapu < Tornjevi.brojDiskova; pozicijaNaStapu++)
            {
                pocetniCvor.naStapuDisk[0][pozicijaNaStapu] = 1;
            }
            
            return pocetniCvor;
        }
        
        //inicijalizira ciljni čvor
        public static Cvor stvoriCiljniCvor()
        {
            Cvor ciljniCvor = new Cvor();
            ciljniCvor.identifikacijskiBroj = 0;

            for (int pozicijaNaStapu = 0; pozicijaNaStapu < Tornjevi.brojDiskova; pozicijaNaStapu++)
            {
                ciljniCvor.naStapuDisk[2][pozicijaNaStapu] = 1;
            }

            return ciljniCvor;
        }

        //metoda vraća true ako je stanje već bilo obrađeno, inače false
        public static bool posjeceniSadrze(Cvor trenutniCvor)
        {
            for (int redniBroj = 0; redniBroj < Tornjevi.posjeceniCvorovi.Count; redniBroj++)
            {
                if(trenutniCvor.jednak(Tornjevi.posjeceniCvorovi[redniBroj])) return true;
            }
            return false;
        }
        
        //rekurzivno u listu za crtanje stavlja čvorove
        public static void napuniListuZaCrtanje(Cvor trenutniCvor)
        {
            Tornjevi.ListaZaCrtati.Insert(0, trenutniCvor);
           // Cvor noviCvor = new Cvor();
            for (int redniBroj = 0; redniBroj < Tornjevi.posjeceniCvorovi.Count; redniBroj++)
                if (trenutniCvor.identifikacijskiBrojRoditelja == Tornjevi.posjeceniCvorovi[redniBroj].identifikacijskiBroj)
                {
                    trenutniCvor = Tornjevi.posjeceniCvorovi[redniBroj];
                    break;
                }
            if (trenutniCvor.identifikacijskiBroj == 1) Tornjevi.ListaZaCrtati.Insert(0, trenutniCvor);
            else napuniListuZaCrtanje(trenutniCvor);
        }
        
    }
   
   }

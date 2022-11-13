using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using Db4objects.Db4o;
using Db4objects.Db4o.Query;
using Db4objects.Db4o.Linq;
using Db4objects.Db4o.NativeQueries;

namespace ConsoleApplication1
{
    class Program : Manage
    {
        static IObjectContainer dataBase = Db4oFactory.OpenFile(Manage.YapFileName);

        static void Main(string[] args)
        {
            //UpisiNoveUBazu();

            #region Jednostavni upiti
            #region QBE
            Console.WriteLine("Obavljam QBE za pilote");
            IObjectSet rezultatQBE = dataBase.QueryByExample(typeof(Pilot));
            ListResult(rezultatQBE);
            Console.WriteLine();
            #endregion

            #region NQ
            Console.WriteLine("Dohvacam po imenu");
            string ime = Console.ReadLine();

            //Dohvacanje svih pilota koji imaju ime ucitano iz konzole
            IList<Pilot> rezultatNQ = dataBase.Query<Pilot>(delegate(Pilot pilot)
            {
                return pilot.Ime == ime;
            });
            foreach (Pilot p in rezultatNQ)
            {
                Console.WriteLine("{0} {1} {2} {3} {4}", p.Ime, p.Prezime, p.Sifra, p.Momcad.Naziv, p.Vrsta);
            }

            Console.WriteLine();
            #endregion

            #region SODA

            Console.WriteLine("SODA upit");
            string prviSodaString = Console.ReadLine();
            string drugiSodaStrnig = Console.ReadLine();
            IQuery query = dataBase.Query();
            query.Constrain(typeof(Pilot));
            query.Descend("_ime").Constrain(prviSodaString).Or(query.Descend("_ime").Constrain(drugiSodaStrnig));

            IObjectSet rezultatSodaUpita = query.Execute();
            ListResult(rezultatSodaUpita);
            Console.WriteLine();

            #endregion

            #region LINQ
            Console.WriteLine("LINQ upit");
            string linqString = Console.ReadLine();

            IEnumerable<Pilot> rezultatLINQUpita = from Pilot p in dataBase
                                                   where p.Ime == linqString
                                                   select p;
            ListResult(rezultatLINQUpita
            Console.WriteLine();
            #endregion
            #endregion

            #region (malo)Slozeniji upiti
            #region QBE
            //Dohvacamo pilota preko drzave
            Drzava drzavaSlozenijiQBE = new Drzava();
            drzavaSlozenijiQBE.Naziv = "Hrvatska";
            Pilot pilotSlozenijiQBE = new Pilot();
            pilotSlozenijiQBE.Drzava = drzavaSlozenijiQBE;

            Console.WriteLine("Slozeniji QBE\nTrazimo sve vozace iz Hrvatske\n");
            IObjectSet rezultatSlozenijegQBE = dataBase.QueryByExample(pilotSlozenijiQBE);
            ListResult(rezultatSlozenijegQBE);
            Console.WriteLine();
            #endregion

            #region NQ

            Drzava drzavaSlozenijiNQ = new Drzava();
            drzavaSlozenijiQBE.Naziv = "Hrvatska";

            //Pilot pilotSlozenijiNQ = new Pilot();
            //pilotSlozenijiNQ.Drzava = drzavaSlozenijiNQ;

            IList<Drzava> rezultatDrzavaSlozenijiNQ = dataBase.Query<Drzava>(delegate(Drzava drzava)
            {
                return drzava.Naziv == "Hrvatska";
            });

            //ako postoji drzava imena Hrvatska onda trazi pilote iz te drzave
            if(rezultatDrzavaSlozenijiNQ.Count > 0)
            {
                Console.WriteLine("Slozeniji NQ\nTrazimo vozace iz Hrvatske\n");
                IList<Pilot> rezultatSlozenijegNQ = dataBase.Query<Pilot>(delegate(Pilot pilot)
                {
                    return pilot.Drzava.Naziv == rezultatDrzavaSlozenijiNQ[0].Naziv;
                });
                ListResult(rezultatSlozenijegNQ);
                Console.WriteLine();
            }
            #endregion

            #region SODA
            //Definiramo upit za dohvacanje drzave
            //Ovo je vec malo teze kemijanje. Ovakvo nesto nece sigurno biti ;)
            //Isto se radi i u LINQ upitima.
            //Buduci da ne znam kako se preko samog naziva drzave dokopati pilota isao sam za svaku
            //pronadenu drzavu traziti onaj element koji ju sadrzi
            IQuery slozenijiSODAUpitDrzava = dataBase.Query();
            slozenijiSODAUpitDrzava.Constrain(typeof(Drzava));
            slozenijiSODAUpitDrzava.Descend("_naziv").Constrain("Hrvatska");

            IObjectSet rezultatDrzavaSlozenijiSODA = slozenijiSODAUpitDrzava.Execute();

            //Ako smo pronasli drzavu dohvacamo pilote iz te drzave
            if (rezultatDrzavaSlozenijiSODA.Count > 0)
            {
                Console.WriteLine("Slozeniji SODA\nTrazimo vozace iz Hrvatske \n");

                for (int i = 0; i < rezultatDrzavaSlozenijiSODA.Count; i++)
                {
                    IQuery slozenijiSODAUpitPilot = dataBase.Query();
                    slozenijiSODAUpitPilot.Constrain(typeof(Pilot));
                    slozenijiSODAUpitPilot.Descend("_drzava").Constrain(rezultatDrzavaSlozenijiSODA[i]);

                    IObjectSet rezultatPilotSlozenijiSODA = slozenijiSODAUpitPilot.Execute();
                    ListResult(rezultatPilotSlozenijiSODA);  
                }
            }
            #endregion

            #region  LINQ
            Console.WriteLine("LINQ upit");
            IEnumerable<Drzava> rezultatDrzavaSlozenijeLINQ = from Drzava d in dataBase
                                                   where d.Naziv == "Hrvatska"
                                                   select d;

            foreach (Drzava drzavaUSlozenijemLINQ in rezultatDrzavaSlozenijeLINQ)
            {
                IEnumerable<Pilot> rezultatLINQUpita = from Pilot p in dataBase
                                                       where p.Drzava == drzavaUSlozenijemLINQ
                                                       select p;
                ListResult(rezultatLINQUpita);
            }
            
            Console.WriteLine();
            #endregion
            #endregion
        }

        public static void UpisiNoveUBazu()
        {
            for (int i = 0; i < 4; i++)
            {
                Pilot pilot = new Pilot();
                Console.WriteLine(YapFileName);

                Console.WriteLine("Ime pilota:");
                pilot.Ime = Console.ReadLine();

                Console.WriteLine("Prezime pilota:");
                pilot.Prezime = Console.ReadLine();

                Console.WriteLine("Sifra pilota:");
                pilot.Sifra = Convert.ToInt32(Console.ReadLine());

                Console.WriteLine("Drzava pilota:");
                Drzava drzava = new Drzava();
                drzava.Naziv = Console.ReadLine();
                pilot.Drzava = drzava;

                Console.WriteLine("Momcad pilota:");
                Momcad momcad = new Momcad();
                momcad.Naziv = Console.ReadLine();
                pilot.Momcad = momcad;

                Console.WriteLine("Bodovi pilota:");
                pilot.Bodovi = Convert.ToInt32(Console.ReadLine());

                Console.WriteLine("Vrsta pilota:");
                pilot.Vrsta = Console.ReadLine();

                dataBase.Store(pilot);

            }
        }
    }
}

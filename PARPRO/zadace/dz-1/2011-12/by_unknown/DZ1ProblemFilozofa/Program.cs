using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using MPI;

namespace DZ1ProblemFilozofa
{
   
    class Program
    {
        public const int MAXSLEEPINGTIME = 6;
        public const int MAXSEATINGTIME = 5001;
        public const bool IMAMVILICU = true;
        public const bool NEMAMVILICU = false;
        public const string RAZMAK = "\t\t\t\t\t";
        static void Main(string[] args)
        {
            using (new MPI.Environment(ref args))
            {
                Vilica LijevaVilica = null;
                Vilica DesnaVilica = null;
                bool lijeviToken = false;
                bool desniToken = false;
                int lijeviSusjed = -1;
                int desniSusjed = -1;
                string pomak = "";

                //Inicijalizacija
                
                Intracommunicator comm = Communicator.world;
                int idProcesa = comm.Rank;
                lijeviSusjed = (idProcesa - 1);
                lijeviSusjed = lijeviSusjed >= 0 ? lijeviSusjed : (comm.Size - 1);
                desniSusjed = (idProcesa + 1);
                desniSusjed = desniSusjed <= (comm.Size - 1) ? desniSusjed : 0;
                
                for (int w = 0; w < idProcesa; w++)
                { pomak += RAZMAK; }
                System.Console.WriteLine(pomak+"Filozof"+idProcesa);
               
                if (idProcesa == 0)
                {
                    LijevaVilica = new Vilica(IMAMVILICU);
                    DesnaVilica = new Vilica(IMAMVILICU);
                }
                else if (idProcesa == (comm.Size - 1))
                {
                    DesnaVilica = new Vilica(NEMAMVILICU);
                    LijevaVilica = new Vilica(NEMAMVILICU);
                    lijeviToken = true;
                    desniToken = true;
                }
                else
                {
                    DesnaVilica = new Vilica(IMAMVILICU);
                    LijevaVilica = new Vilica(NEMAMVILICU);
                    lijeviToken = true;
                }

                /*********************************************/
                //Nakon inicijalizacije beskonacno ponavljaj

                while (true)
                {
                    bool PorukaOdLijevogSusjeda = false;
                    bool PorukaOdDesnogSusjeda = false;
                    //Misli
                    Random rand = new Random();
                    int sleepingTime = rand.Next(MAXSLEEPINGTIME);
                    System.Console.WriteLine(pomak+"Mislim" + idProcesa);
                    for (int j = 0; j < sleepingTime; j++)
                    {
                      
                        PorukaOdLijevogSusjeda = ProvjeriPorukeSusjeda(comm, lijeviSusjed);
                        PorukaOdDesnogSusjeda = ProvjeriPorukeSusjeda(comm, desniSusjed);
                        if (PorukaOdLijevogSusjeda)
                        {
                            comm.Receive<bool>(lijeviSusjed, 0);
                            lijeviToken = true;
                        }
                        if (PorukaOdDesnogSusjeda)
                        {
                            comm.Receive<bool>(desniSusjed, 0 );
                            desniToken=true;
                        }
                        if (lijeviToken)
                        {
                            OdluciStoSaVilicom(comm, LijevaVilica, lijeviSusjed);
                        }
                        if (desniToken)
                        {
                            OdluciStoSaVilicom(comm,DesnaVilica,desniSusjed);
                        }
                        System.Threading.Thread.Sleep(1000);
                    }
                    
                    //Gladan
                    System.Console.WriteLine(pomak+"Gladan" + idProcesa);
                   while (true)
                   {
                       //Pogledaj jel netko šta treba
                       PorukaOdDesnogSusjeda = false; PorukaOdDesnogSusjeda = false;
                       PorukaOdLijevogSusjeda = ProvjeriPorukeSusjeda(comm, lijeviSusjed);
                       PorukaOdDesnogSusjeda = ProvjeriPorukeSusjeda(comm, desniSusjed);
                       if (PorukaOdLijevogSusjeda)
                       {
                           comm.Receive<bool>(lijeviSusjed, 0);
                           lijeviToken = true;
                       }
                       if (PorukaOdDesnogSusjeda)
                       {
                           comm.Receive<bool>(desniSusjed, 0);
                           desniToken = true;
                       }
                       if (lijeviToken)
                       {
                           OdluciStoSaVilicom(comm, LijevaVilica, lijeviSusjed);
                       }
                       if (desniToken)
                       {
                           OdluciStoSaVilicom(comm, DesnaVilica, desniSusjed);
                       }
                       //Pogledaj svoje osobne potrebe
                         if (LijevaVilica.ImamVilicu && DesnaVilica.ImamVilicu)
                            {
                             break;
                            }
                         else
                         {
                             if (!LijevaVilica.ImamVilicu)
                             {
                                 if (SaljeLiNetkoVilicu(comm, lijeviSusjed))
                                 {
                                     System.Console.WriteLine(pomak + "PrimamVilicu" + lijeviSusjed);
                                     comm.Receive<bool>(lijeviSusjed, 1);
                                     LijevaVilica.ImamVilicu = true;
                                     LijevaVilica.OcistiVilicu();
                                 }
                             }
                             if (!LijevaVilica.ImamVilicu)
                             {
                                 if (lijeviToken)
                                 {
                                     TraziVilicu(comm, lijeviSusjed);
                                     lijeviToken = false;

                                 }
                             }
                             if (!DesnaVilica.ImamVilicu)
                             {
                                 if (SaljeLiNetkoVilicu(comm, desniSusjed))
                                 {
                                     System.Console.WriteLine(pomak + "PrimamVilicu" + desniSusjed);
                                     comm.Receive<bool>(desniSusjed, 1);
                                     DesnaVilica.ImamVilicu = true;
                                     DesnaVilica.OcistiVilicu();  
                                 }
                             }
                             if (!DesnaVilica.ImamVilicu)
                             {
                                 if (desniToken)
                                 {
                                     TraziVilicu(comm, desniSusjed);
                                     desniToken = false;
                                 }
                             }
                             
                         }
                      
                   }


                    //Jedi
                    rand = new Random();
                    int eatingTime = rand.Next(MAXSEATINGTIME);
                    System.Console.WriteLine(pomak+"Jedem" + idProcesa);
                    LijevaVilica.ZaprljajVilicu(); DesnaVilica.ZaprljajVilicu();
                    System.Threading.Thread.Sleep(eatingTime);

                    //Provjeri treba li netko vilicu
                    PorukaOdDesnogSusjeda = false; PorukaOdDesnogSusjeda = false;
                    PorukaOdLijevogSusjeda = ProvjeriPorukeSusjeda(comm, lijeviSusjed);
                    PorukaOdDesnogSusjeda = ProvjeriPorukeSusjeda(comm, desniSusjed);
                    if (PorukaOdLijevogSusjeda)
                    {
                        comm.Receive<bool>(lijeviSusjed, 0);
                        lijeviToken = true;
                    }
                    if (PorukaOdDesnogSusjeda)
                    {
                        comm.Receive<bool>(desniSusjed, 0);
                        desniToken = true;
                    }
                    if (lijeviToken)
                    {
                        OdluciStoSaVilicom(comm, LijevaVilica, lijeviSusjed);
                    }
                    if (desniToken)
                    {
                        OdluciStoSaVilicom(comm, DesnaVilica, desniSusjed);
                    }
                }
            }
        }


       static private void TraziVilicu(Intracommunicator comm, int idSusjeda)
       {
           comm.Send<bool>(true, idSusjeda, 0);
           string pomak="";
           for (int l = 0; l < comm.Rank; l++)
           { pomak += RAZMAK; }
           System.Console.WriteLine(pomak+"TrazimVilicu" + idSusjeda);
       }

       static private bool ProvjeriPorukeSusjeda(Intracommunicator comm, int susjed)
       {
           var flag = comm.ImmediateProbe(susjed, 0);
           if (flag != null)
           { return true; }
           return false;
       }

       static private void OdluciStoSaVilicom(Intracommunicator comm, Vilica Vilica, int susjed)
       {
           if (Vilica.ImamVilicu)
           {
               if (Vilica.Stanje == StanjeVilice.cisto)
               {
                   return;
               }
               else if (Vilica.Stanje == StanjeVilice.prljavo)
               {
                   string pomak = "";
                   Vilica.ImamVilicu = false;
                   for (int p = 0; p < comm.Rank; p++)
                   { pomak += RAZMAK; }
                   System.Console.WriteLine(pomak + "SaljemVilicu" + susjed);
                   comm.Send<bool>(true, susjed, 1); 
               }
           }
       }

       static private bool SaljeLiNetkoVilicu(Intracommunicator comm, int susjed)
       {
           var flag = comm.ImmediateProbe(susjed, 1);
           if (flag !=null)
           { return true; }
           return false;
       }
    
    }
}

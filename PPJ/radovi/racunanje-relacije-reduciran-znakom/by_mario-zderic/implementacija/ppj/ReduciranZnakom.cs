using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace WindowsFormsApplication1
{
    class ReduciranZnakom
    {

        public static string run(Produkcija[] a)
        {


            
            //stvaranje polja gdje su svi završni i nezavršni znakovi gramatike
            //potrebno za izgradnju tablica
            string rez="";
            char[] svi = new char[100];
            int i = 0;


            foreach (Produkcija p in a)
            {
                char[] pom = p.Get().ToCharArray();
                svi[i] = pom[0];
                i++;
            }



            foreach (Produkcija p in a)
            {
                int j = p.Getb();
                for (int k = 0; k < j; k++)
                {
                    char[] c = p.GetProd(k).ToCharArray();
                    for (int l = 0; l < c.Length; l++)
                    {
                        if (!PostojiLi(c[l], svi))
                        {
                            if (!c[l].Equals('$'))
                            {
                                svi[i] = c[l];
                                i++;
                            }
                        }
                    }
                }
            }

            svi = IzreziVisak(svi, i);
            //stvaranje "Hasha". Treba nam kad imamo određeni znak da se dobije indeks
            //toga znaka u polju svi
            Hash h = new Hash(svi);
            




            //inicijalizacija tablica
            bool[,] ZapocinjeZnakom = new bool[svi.Length, svi.Length];
            bool[,] IzravnoIspredZnaka = new bool[svi.Length, svi.Length];
            bool[,] Kraj = new bool[svi.Length, svi.Length];
            bool[,] Ispred = new bool[svi.Length, svi.Length + 1];
            bool[,] ReduciranZnakom = new bool[svi.Length, svi.Length + 1];
            char[] PrazniNezavrsni = new char[30];

            i = 0;

            //Traženje praznih nezavršnih znakova
            foreach (Produkcija p in a)
            {

                for (int j = 0; j < p.Getb(); j++)
                {
                    if (p.GetProd(j) == "$")
                    {
                        char[] c = p.Get().ToCharArray();
                        PrazniNezavrsni[i] = c[0];
                        i++;
                    }
                }
            }
            PrazniNezavrsni = IzreziVisak(PrazniNezavrsni, i);


            //popunjavanje tablice ZapocinjeIzravnoZnakom
            foreach (Produkcija p in a)
            {

                for (int j = 0; j < p.Getb(); j++)
                {
                    char[] c = p.GetProd(j).ToCharArray();
                    char[] d = p.Get().ToCharArray();
                    int n = 0, m = 0;


                    if (c[0].Equals('$')) continue;
                    m = h.GetInt(d[0]);
                    n = h.GetInt(c[0]);
                    ZapocinjeZnakom[m, n] = true;
                    
                    //ako je prvi znak lijeve strane produkcije praza
                    for (int k = 0; Prazan(c[k], PrazniNezavrsni) && k < c.Length - 1; k++)
                    {
                        n = h.GetInt(c[k + 1]);
                        ZapocinjeZnakom[m, n] = true;
                    }



                }

            }

            // petlja za pretvaranje ZapočinjeIzravnoZnakom u ZapočinjeZnakom
            for (int j = 0; j < svi.Length; j++)
            {
                ZapocinjeZnakom[j, j] = true;
                for (int k = 0; k < svi.Length; k++)
                {
                    if (ZapocinjeZnakom[j, k])
                        for (int l = 0; l < svi.Length; l++)
                        {
                            if (ZapocinjeZnakom[k, l]) ZapocinjeZnakom[j, l] = true;

                        }
                }
            }

            //popunjavanje tablice IzravnoIspredZnaka

            foreach (Produkcija p in a)
            {

                for (int j = 0; j < p.Getb(); j++)
                {
                    char[] c = p.GetProd(j).ToCharArray();

                    int n = 0, m = 0;

                    for (int k = 0; k < c.Length - 1; k++)
                    {
                        if (c[k].Equals('$') || c[k + 1].Equals('$')) break;
                        m = h.GetInt(c[k]);
                        n = h.GetInt(c[k + 1]);
                        IzravnoIspredZnaka[m, n] = true;
                        
                        //ako je slijedeći znak prazan
                        for (int l = k + 1; l < c.Length - 1 && Prazan(c[l], PrazniNezavrsni); l++)
                        {
                            n = h.GetInt(c[l + 1]);
                            IzravnoIspredZnaka[m, n] = true;
                        }

                    }

                }

            }

            //popunjavanje tablice IzravaniKraj
            foreach (Produkcija p in a)
            {

                for (int j = 0; j < p.Getb(); j++)
                {
                    char[] c = p.GetProd(j).ToCharArray();
                    char[] d = p.Get().ToCharArray();
                    int n = 0, m = 0;

                    if (c[c.Length - 1].Equals('$')) continue;
                    m = h.GetInt(c[c.Length - 1]);
                    n = h.GetInt(d[0]);
                    Kraj[m, n] = true;
                    
                    for (int k = c.Length - 1; Prazan(c[k], PrazniNezavrsni) && k > 0; k--)
                    {
                        m = h.GetInt(c[k - 1]);
                        Kraj[m, n] = true;
                    }



                }

            }

            //petlja za pretvaranje iz IzravniKraj u Kraj
            for (int j = 0; j < svi.Length; j++)
            {
                Kraj[j, j] = true;
                for (int k = 0; k < svi.Length; k++)
                {
                    if (Kraj[j, k])
                        for (int l = 0; l < svi.Length; l++)
                        {
                            if (Kraj[l, j]) Kraj[l, k] = true;

                        }
                }
            }

            
            
            //popunjavanje tablice Ispred
            for (int A = 0; A < svi.Length; A++)
            {
                for (int X = 0; X < svi.Length; X++)
                {
                    if (Kraj[A, X])
                        for (int Y = 0; Y < svi.Length; Y++)
                            if (IzravnoIspredZnaka[X, Y])
                                for (int B = 0; B < svi.Length; B++)
                                    if (ZapocinjeZnakom[Y, B]) Ispred[A, B] = true;


                }
            }

            //Proširenje relacije Ispredoznakom kraja niza
            for (int j = 0; j < svi.Length; j++)
            {
                if (Kraj[j, 0]) Ispred[j, svi.Length] = true;
            }

            
            
            //popunjavanje tablice ReduciranZnakom


            foreach (Produkcija p in a)
            {

                for (int j = 0; j < p.Getb(); j++)
                {
                    char[] c = p.GetProd(j).ToCharArray();
                    char[] d = p.Get().ToCharArray();
                    int n = 0, m = 0;

                    if (c[c.Length - 1].Equals('$')) continue;
                    m = h.GetInt(c[c.Length - 1]);
                    n = h.GetInt(d[0]);
                    for (int k = 0; k < svi.Length + 1; k++)
                    {
                        if (Ispred[n, k]) ReduciranZnakom[m, k] = true;
                        
                    }
                        //ako je zadnji znak u produkciji prazan
                    for (int l = c.Length - 1; Prazan(c[l], PrazniNezavrsni) && l > 0; l--)
                    {
                        m = h.GetInt(c[l - 1]);
                        for (int k = 0; k < svi.Length + 1; k++)
                        {
                            if (Ispred[n, k]) ReduciranZnakom[m, k] = true;

                        }
                    }
                }

            }
            //dodavanje para (<S>,_)
            ReduciranZnakom[0, svi.Length] = true;

            //pretvaranje tablice ReduciranZnakom u string za ispis
            for (int k = 0; k < svi.Length; k++)
                for (int j = 0; j <= svi.Length; j++)
                {
                    if (ReduciranZnakom[k, j] && j == svi.Length) rez += "(" + svi[k] +","+ "_) ";
                    else if (ReduciranZnakom[k, j]) rez += "(" + svi[k] + ","+svi[j] + ") ";
                }

            return rez;
        }
        
        

        
        
        
        
        
        private static bool Prazan(char p, char[] PrazniNezavrsni)
        {
            for (int i = 0; i < PrazniNezavrsni.Length; i++) 
            {
                if (PrazniNezavrsni[i] == p) return true;
            }
            return false;
        } 
        
        
        
        
        
        private static char[] IzreziVisak(char[] c, int i)
        {
            char[] r= new char[i];
            for (int j = 0; j < i; j++)
                r[j] = c[j];
            return r;
        }

       
        
        
        private static bool PostojiLi(char p, char[] svi)
        {
            

            for (int i = 0; i < svi.Length; i++) 
            {
                if (svi[i] == p) return true;
            
            }
            return false;
        }
    }
}

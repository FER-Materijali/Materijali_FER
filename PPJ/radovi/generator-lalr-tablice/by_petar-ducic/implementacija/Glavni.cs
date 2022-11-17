using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace SSP
{
    class Glavni
    {
        public static List<Redak_Tablica> PRODUKCIJE = new List<Redak_Tablica>();
        public static List<Redak_Tablica> PRIJELAZI = new List<Redak_Tablica>();
        public static List<Redak_Tablica> STAVKE = new List<Redak_Tablica>();
        public static List <Redak_Tablica> STAVKE2 = new List<Redak_Tablica>();
        public static List<Redak_Tablica> ZAPOCINJE = new List<Redak_Tablica>();
        public static bool zastava101=false;
        public static List<Redak_Tablica> PRIJELAZI2 = new List<Redak_Tablica>();
        public static List<Redak_Tablica> PRIJELAZI3 = new List<Redak_Tablica>();
        public static List<Redak_Tablica> DKA = new List<Redak_Tablica>();
        public static List<string> DKA2 = new List<string>();
        public static List<int> BROJAC = new List<int>();
        public static List<string> DKA_LINIJA=new List<string>();
        public static char poc;
        public static List<char> ZAVRSNI= new List<char>();
        public static List<char> NEZAVRSNI= new List<char>();
        public static List<char> STANJA = new List<char>();




        
   

        public static void Produkcije_u_stavke()
        {
            int i,j;
            if (zastava101) return;
            string exePath = System.IO.Path.GetDirectoryName(System.Windows.Forms.Application.ExecutablePath);

            PRODUKCIJE = PopuniPROD(Form1.chosenFile);//prepisuju se redci iz ulazne datoteke u listu PRODUKCIJE

            StreamWriter w = new StreamWriter(exePath + "\\STAVKE.txt");
            for (i = 0; i < PRODUKCIJE.Count; i++)              //popunjava se datoteka LR(0) stavki
            {
                for (j = 3; PRODUKCIJE[i].naziv.Length >= j; j++)
                {
                   w.WriteLine(PRODUKCIJE[i].naziv.Insert(j, "*"));
                }
            }
            w.Close();
            ZAVRSNI.Add('~');
            for (i = 0; i < PRODUKCIJE.Count; i++)//popunjavaju se liste zavrsnih i nezavrsnih znakova, koristiti ce se kasnije pri generiranju tablice
            {
                popuniNEZAVRSNE(PRODUKCIJE[i].naziv);
                popuniZAVRSNE(PRODUKCIJE[i].naziv);
            }

        }
        public static void popuniZAVRSNE(string ulaz)//prolazi kroz ulazni niz te ako vec ne postoji odredeni zavrsni znak, dodaje ga u listu ZAVRSNI.
        {                                                       //posto se u ulaznoj datoteci ne nalazi znak kraja niza, on se dodaje prije svih, u 51 redu
            int br = 0;
            
            for (int i = 0; i < ulaz.Length; i++)
            {
                if(ulaz[i]<'a'||ulaz[i]>'z')
                    continue;
                for (br = 0; br < ZAVRSNI.Count; br++)
                    if (ulaz[i].Equals(ZAVRSNI[br]))
                        break;
                if (br == ZAVRSNI.Count)
                    ZAVRSNI.Add(ulaz[i]);
            }
        }
        public static void popuniNEZAVRSNE(string ulaz)
        {
            int br = 0;
            for (int i = 0; i < ulaz.Length; i++)
            {
                if (ulaz[i] < 'A' || ulaz[i] > 'Z')
                    continue;
                for (br = 0; br < NEZAVRSNI.Count; br++)
                    if (ulaz[i].Equals(NEZAVRSNI[br]))
                        break;
                if (br == NEZAVRSNI.Count)
                    NEZAVRSNI.Add(ulaz[i]);
            }
           
        }
                
        public static void napraviPrijelaze()
        {
            int i;
            if (zastava101) return;

            string exePath = System.IO.Path.GetDirectoryName(System.Windows.Forms.Application.ExecutablePath);
            STAVKE = popuniSTAVKE(exePath + "\\STAVKE.txt");
            ZAPOCINJE = popuniZAPOCINJE(Form1.zapocinje);

            StreamWriter w = new StreamWriter(exePath + "\\epsilon-NKA.txt");

            poc = STAVKE[0].naziv[0];
            STAVKE2.Add(new Redak_Tablica("q0", "{}"));

            for (i = 0; i < STAVKE.Count; i++)
            {
                if (STAVKE[i].naziv[0].Equals(poc) && STAVKE[i].naziv[3].Equals('*'))
                {
                    PRIJELAZI.Add(new Redak_Tablica("q0{}", 'E', STAVKE[i].naziv + "{~}"));
                    w.WriteLine("q0  E  " + STAVKE[i].naziv + "{~}");
                    STAVKE2.Add(new Redak_Tablica(STAVKE[i].naziv, "{~}"));//dodaje se pocetno stanje q0 i prijelaz

                }
            }

            for (i = 0; i < STAVKE2.Count; i++)
            {
                int a = STAVKE2[i].naziv.IndexOf('*') + 1;
                if (STAVKE2[i].naziv.Contains('*') && !(STAVKE2[i].naziv.EndsWith("*")))//za prijelaze gdje se tocka pomice u desno
                {
                    string stara = STAVKE2[i].naziv;
                    string nova = "";

                    for (int j = 0; j < STAVKE.Count; j++)
                        if (STAVKE[j].naziv.Equals(STAVKE2[i].naziv))
                            nova = STAVKE[j + 1].naziv;

                    Redak_Tablica nesto1 = new Redak_Tablica(nova, STAVKE2[i].zavrsni);
                    Redak_Tablica pre = new Redak_Tablica(STAVKE2[i].naziv + STAVKE2[i].zavrsni, STAVKE2[i].naziv[a], nova + STAVKE2[i].zavrsni);
                    int k, b;
                    for (b = 0; b < PRIJELAZI.Count; b++)
                        if (pre.stanje1 == PRIJELAZI[b].stanje1 && pre.prijelaz == PRIJELAZI[b].prijelaz && pre.stanje2 == PRIJELAZI[b].stanje2)
                            break;
                    if (b == PRIJELAZI.Count)
                    {
                        PRIJELAZI.Add(new Redak_Tablica(STAVKE2[i].naziv + STAVKE2[i].zavrsni, STAVKE2[i].naziv[a], nova + STAVKE2[i].zavrsni));
                        w.WriteLine(STAVKE2[i].naziv + STAVKE2[i].zavrsni + "  " + STAVKE2[i].naziv[a] + "  " + nova + STAVKE2[i].zavrsni);

                        for (k = 0; k < STAVKE2.Count; k++)
                            if (nesto1.naziv == STAVKE2[k].naziv && nesto1.zavrsni == STAVKE2[k].zavrsni)
                                break;

                        if (k == STAVKE2.Count)
                        {
                            STAVKE2.Add(new Redak_Tablica(nova, STAVKE2[i].zavrsni));
                        }

                    }
                }
                if (STAVKE2[i].naziv.Length > a)        //za epsilon prijelaze
                {
                    if (STAVKE2[i].naziv[a] >= 'A' && STAVKE2[i].naziv[a] <= 'Z')
                    {
                        if (STAVKE2[i].naziv.Length == (a + 1))
                        {
                            for (int j = 0; j < STAVKE.Count; j++)
                            {
                                if (STAVKE2[i].naziv[a].Equals(STAVKE[j].naziv[0]) && STAVKE[j].naziv[3].Equals('*'))
                                {
                                    Redak_Tablica nesto = new Redak_Tablica(STAVKE[j].naziv, STAVKE2[i].zavrsni);
                                    Redak_Tablica pre = new Redak_Tablica(STAVKE2[i].naziv + STAVKE2[i].zavrsni, 'E', STAVKE[j].naziv + STAVKE2[i].zavrsni);
                                    int k, b;
                                    for (b = 0; b < PRIJELAZI.Count; b++)
                                        if (pre.stanje1 == PRIJELAZI[b].stanje1 && pre.prijelaz == PRIJELAZI[b].prijelaz && pre.stanje2 == PRIJELAZI[b].stanje2)
                                            break;
                                    if (b == PRIJELAZI.Count)
                                    {
                                        PRIJELAZI.Add(new Redak_Tablica(STAVKE2[i].naziv + STAVKE2[i].zavrsni, 'E', STAVKE[j].naziv + STAVKE2[i].zavrsni));
                                        w.WriteLine(STAVKE2[i].naziv + STAVKE2[i].zavrsni + "  E  " + STAVKE[j].naziv + STAVKE2[i].zavrsni);
                                        for (k = 0; k < STAVKE2.Count; k++)
                                            if (nesto.naziv == STAVKE2[k].naziv && nesto.zavrsni == STAVKE2[k].zavrsni)
                                                break;
                                        if (k == STAVKE2.Count)
                                        {
                                            STAVKE2.Add(new Redak_Tablica(STAVKE[j].naziv, STAVKE2[i].zavrsni));
                                        }
                                    }
                                }
                            }
                        }
                        else if (STAVKE2[i].naziv[a + 1] <= 'z' && STAVKE2[i].naziv[a + 1] >= 'a')//
                        {
                            string zav = "{" + STAVKE2[i].naziv[a + 1].ToString() + "}";
                            for (int j = 0; j < STAVKE.Count; j++)
                            {
                                if (STAVKE2[i].naziv[a].Equals(STAVKE[j].naziv[0]) && STAVKE[j].naziv[3].Equals('*'))
                                {
                                    Redak_Tablica nesto = new Redak_Tablica(STAVKE[j].naziv, zav);
                                    Redak_Tablica pre = new Redak_Tablica(STAVKE2[i].naziv + STAVKE2[i].zavrsni, 'E', STAVKE[j].naziv + zav);
                                    int k, b;
                                    for (b = 0; b < PRIJELAZI.Count; b++)
                                        if (pre.stanje1 == PRIJELAZI[b].stanje1 && pre.prijelaz == PRIJELAZI[b].prijelaz && pre.stanje2 == PRIJELAZI[b].stanje2)
                                            break;
                                    if (b == PRIJELAZI.Count)
                                    {
                                        PRIJELAZI.Add(new Redak_Tablica(STAVKE2[i].naziv + STAVKE2[i].zavrsni, 'E', STAVKE[j].naziv + zav));
                                        w.WriteLine(STAVKE2[i].naziv + STAVKE2[i].zavrsni + "  E  " + STAVKE[j].naziv + zav);

                                        for (k = 0; k < STAVKE2.Count; k++)
                                            if (nesto.naziv == STAVKE2[k].naziv && nesto.zavrsni == STAVKE2[k].zavrsni)
                                                break;
                                        if (k == STAVKE2.Count)
                                        {
                                            STAVKE2.Add(new Redak_Tablica(STAVKE[j].naziv, zav));
                                        }

                                    }
                                }
                            }
                        }
                        else    
                        {
                            string zav="";
                            for (int j = 0; j < ZAPOCINJE.Count; j++)
                            {
                                if (STAVKE2[i].naziv[a + 1].Equals(ZAPOCINJE[j].nez_znak))//za ZAPOCINJE
                                {
                                    zav = ZAPOCINJE[j].zavrsni;
                                    if (prazni_niz(STAVKE2[i].naziv.Substring(a + 1)))//za slučaj da desna strana od * generira prazan niz
                                         zav=zav.Insert(1,"~,");
                                    break;
                                }
                            }
                            for (int j = 0; j < STAVKE.Count; j++)
                            {
                                if (STAVKE2[i].naziv[a].Equals(STAVKE[j].naziv[0]) && STAVKE[j].naziv[3].Equals('*'))
                                {
                                    Redak_Tablica nesto = new Redak_Tablica(STAVKE[j].naziv, zav);
                                    Redak_Tablica pre = new Redak_Tablica(STAVKE2[i].naziv + STAVKE2[i].zavrsni, 'E', STAVKE[j].naziv + zav);
                                    int k, b;
                                    for (b = 0; b < PRIJELAZI.Count; b++)
                                        if (pre.stanje1 == PRIJELAZI[b].stanje1 && pre.prijelaz == PRIJELAZI[b].prijelaz && pre.stanje2 == PRIJELAZI[b].stanje2)
                                            break;
                                    if (b == PRIJELAZI.Count)
                                    {
                                        PRIJELAZI.Add(new Redak_Tablica(STAVKE2[i].naziv + STAVKE2[i].zavrsni, 'E', STAVKE[j].naziv + zav));
                                        w.WriteLine(STAVKE2[i].naziv + STAVKE2[i].zavrsni + "  E  " + STAVKE[j].naziv + zav);
                                        for (k = 0; k < STAVKE2.Count; k++)
                                            if (nesto.naziv == STAVKE2[k].naziv && nesto.zavrsni == STAVKE2[k].zavrsni)
                                                break;
                                        if (k == STAVKE2.Count)
                                        {
                                            STAVKE2.Add(new Redak_Tablica(STAVKE[j].naziv, zav));
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            w.Close();
         }

        public static void Napravi_DKA()
        {
            if (zastava101) return;
            int i;
            string exePath = System.IO.Path.GetDirectoryName(System.Windows.Forms.Application.ExecutablePath);
            StreamWriter w = new StreamWriter(exePath + "\\DKA.txt");
            char DKA = '0';

            for(i=0;i<PRIJELAZI.Count;i++)
               PRIJELAZI2.Add(new Redak_Tablica(PRIJELAZI[i].stanje1,PRIJELAZI[i].prijelaz,PRIJELAZI[i].stanje2));
            for (i = 0; i < PRIJELAZI2.Count; i++)
            {
                if (PRIJELAZI2[i].stanje1.Equals("q0{}"))
                    PRIJELAZI2[i].stanje1=PRIJELAZI2[i].stanje1.Insert(0, DKA.ToString());
                string a = PRIJELAZI2[i].stanje1;
            }
            for (i = 0; i < PRIJELAZI2.Count; i++)
            {
                char poc = PRIJELAZI2[i].stanje1[0];
                char poc2 = PRIJELAZI2[i].stanje2[0];
                if (poc >= '0' && poc <= '9' && poc2 >= '0' && poc2 <= '9')//ako je poc i odredisno stanje već grupirano, ide dalje
                    continue;
                else if (poc >= '0' && poc <= '9')//trazi stanja koja imaju poc stanje grupirano, a odredisno jos ne
                {
                    int brojac;
                    do//beskonačna petlja dok se nesto mijenja među prijelazima. 
                    {
                        brojac = 0;
                        for (int k = 0; k < PRIJELAZI2.Count; k++)//trazi epsilon prijelaze i upisuje prefiks stanja gdje pripada
                        {
                            if (PRIJELAZI2[k].stanje1[0].Equals(poc) && PRIJELAZI2[k].prijelaz.Equals('E'))
                            {
                                if (PRIJELAZI2[k].stanje2[0] > '9' || PRIJELAZI2[k].stanje2[0] < '0')
                                {
                                    for (int l = 0; l < PRIJELAZI2.Count; l++)
                                    {
                                        if (l == k) continue;
                                        if (PRIJELAZI2[l].stanje1.Equals(PRIJELAZI2[k].stanje2))
                                        {
                                            PRIJELAZI2[l].stanje1 = PRIJELAZI2[l].stanje1.Insert(0, poc.ToString());
                                            brojac++;
                                        }
                                        else if (PRIJELAZI2[k].stanje2.Equals(PRIJELAZI2[l].stanje1.Substring(1)))
                                        {
                                            string nesto = "";
                                            nesto = PRIJELAZI2[l].stanje1.Remove(0, 1);
                                            nesto = nesto.Insert(0, poc.ToString());
                                            PRIJELAZI2.Add(new Redak_Tablica(nesto, PRIJELAZI2[l].prijelaz, PRIJELAZI2[l].stanje2));
                                            brojac++;
                                        }
                                    }
                                        PRIJELAZI2[k].stanje2=PRIJELAZI2[k].stanje2.Insert(0, poc.ToString());
                                        

                                    
                                }
                            }
                        }
                    }
                    while (brojac > 0);
                }
                else//prvi put uvijek ide ovdje. ako nista nije promijenjeno
                {
                    DKA++;
                    PRIJELAZI2[i].stanje1=PRIJELAZI2[i].stanje1.Insert(0, DKA.ToString());
                    int brojac;
                    for(int z=0;z<PRIJELAZI2.Count;z++)
                        if (PRIJELAZI2[z].stanje1.Equals(PRIJELAZI2[i].stanje1.Substring(1)))
                            PRIJELAZI2[z].stanje1=PRIJELAZI2[z].stanje1.Insert(0, DKA.ToString());
                    do
                    {
                        brojac = 0;
                        for (int k = 0; k < PRIJELAZI2.Count; k++)
                        {
                            if (PRIJELAZI2[k].stanje1[0].Equals(DKA) && PRIJELAZI2[k].prijelaz.Equals('E'))
                            {
                                if (PRIJELAZI2[k].stanje2[0] > '9' || PRIJELAZI2[k].stanje2[0] < '0')
                                {
                                    for (int l = 0; l < PRIJELAZI2.Count; l++)
                                    {
                                        if (l == k) continue;
                                        if (PRIJELAZI2[l].stanje1.Equals(PRIJELAZI2[k].stanje2))
                                        {
                                            PRIJELAZI2[l].stanje1 = PRIJELAZI2[l].stanje1.Insert(0, DKA.ToString());
                                            brojac++;
                                        }
                                        else if (PRIJELAZI2[k].stanje2.Equals(PRIJELAZI2[l].stanje1.Substring(1)))
                                        {
                                            string nesto = "",nes="";
                                            nesto = PRIJELAZI2[l].stanje1.Remove(0, 1);
                                            nesto = nesto.Insert(0, DKA.ToString());
                                            nes = PRIJELAZI2[l].stanje2;
                                            if (nes[0] >= '0' && nes[0] <= '9')
                                                nes = nes.Remove(0,1);
                                            int v = 0;
                                            for(v=0;v<PRIJELAZI2.Count;v++)
                                                if (PRIJELAZI2[v].stanje1.Equals(nesto)&&PRIJELAZI2[v].stanje2.Equals(nes)&&PRIJELAZI2[v].prijelaz.Equals(PRIJELAZI2[l].prijelaz))
                                                    break;
                                            if (v==PRIJELAZI2.Count)
                                            PRIJELAZI2.Add(new Redak_Tablica(nesto, PRIJELAZI2[l].prijelaz, nes));
                                            brojac++;
                                        }
                                    }
                                        PRIJELAZI2[k].stanje2=PRIJELAZI2[k].stanje2.Insert(0, DKA.ToString());
                             
                                }
                            }
                        }
                    }
                    while (brojac > 0);
                
                    
                }
            }
            for (i = 0; i < PRIJELAZI2.Count; i++)//popunjavaju se stanja koja jos nisu popunjena, zavrsna stanja koja nikako nemogu ici u druga stanja
            {
                bool zast = true,zas=true;
                if (PRIJELAZI2[i].stanje2[0] >= '0' && PRIJELAZI2[i].stanje2[0] <= '9')
                    continue;
                int p;
                for (p = 0; p < PRIJELAZI2.Count; p++)
                {
                    if (PRIJELAZI2[p].stanje1.Substring(1).Equals(PRIJELAZI2[i].stanje2) && zast)
                    {
                        PRIJELAZI2[i].stanje2 = PRIJELAZI2[i].stanje2.Insert(0, PRIJELAZI2[p].stanje1[0].ToString());
                        zast = false;
                        zas = false;
                    }
                    else if (PRIJELAZI2[p].stanje1.Substring(1).Equals(PRIJELAZI2[i].stanje2))
                    {
                        PRIJELAZI2.Add(new Redak_Tablica(PRIJELAZI2[i].stanje1, PRIJELAZI2[i].prijelaz, PRIJELAZI2[p].stanje1.Substring(1)));
                        zas=false;
                    }
                }
                if (zas==true)
                {
                    int u;
                    for(u=0;u<PRIJELAZI2.Count;u++)
                        if (PRIJELAZI2[u].stanje2.Substring(1).Equals(PRIJELAZI2[i].stanje2))
                            break;
                    if(u==PRIJELAZI2.Count)
                    {
                        DKA++;
                        PRIJELAZI2[i].stanje2 = PRIJELAZI2[i].stanje2.Insert(0, DKA.ToString());
                    }
                    else
                        PRIJELAZI2[i].stanje2=PRIJELAZI2[u].stanje2;
                }
            }
            for (i = 0; i < PRIJELAZI2.Count; i++)//ispis
                if(!PRIJELAZI2[i].prijelaz.Equals('E'))
                
                    w.WriteLine(PRIJELAZI2[i].stanje1 + " " + PRIJELAZI2[i].prijelaz.ToString() + " " + PRIJELAZI2[i].stanje2);
            w.Close();
            for (i = 0; i < PRIJELAZI2.Count; i++)
                if (PRIJELAZI2[i].prijelaz != 'E')
                    PRIJELAZI3.Add(new Redak_Tablica(PRIJELAZI2[i].stanje1, PRIJELAZI2[i].prijelaz, PRIJELAZI2[i].stanje2));

            PopuniDKA();
            if (Form1.LALR) Spoji_DKA();//ukoliko je označeno da korisnik zeli lalr ovo se obavlja.
            for (i = 0; i < PRIJELAZI3.Count; i++)
            {
                if (!STANJA.Contains(PRIJELAZI3[i].stanje1[0]))
                    STANJA.Add(PRIJELAZI3[i].stanje1[0]);
                if (!STANJA.Contains(PRIJELAZI3[i].stanje2[0]))
                    STANJA.Add(PRIJELAZI3[i].stanje2[0]);
            }
            STANJA.Sort();

            Form1.NapraviTablicu();           
        }


        public static List<Redak_Tablica> PopuniDKA()//pune se stanja DKA
        {
            string exePath = System.IO.Path.GetDirectoryName(System.Windows.Forms.Application.ExecutablePath);
            StreamWriter w = new StreamWriter(exePath + "\\STANJA.txt");
            StreamWriter w2 = new StreamWriter(exePath + "\\BROJAC.txt");
            
            int i,j;
            for (i=0;i<PRIJELAZI2.Count;i++)
            {
                for(j=0;j<DKA2.Count;j++)
                    if (DKA2[j].Equals(PRIJELAZI2[i].stanje1))
                        break;
                if (j==DKA2.Count)
                    DKA2.Add(PRIJELAZI2[i].stanje1);
                for(j=0;j<DKA2.Count;j++)
                    if (DKA2[j].Equals(PRIJELAZI2[i].stanje2))
                        break;
                if (j==DKA2.Count)
                    DKA2.Add(PRIJELAZI2[i].stanje2);
            }
            DKA2.Sort();
       
            for (i=0;i<DKA2.Count;i++)
            {
                j=DKA2[i].IndexOf('{');
                
                DKA.Add(new Redak_Tablica(DKA2[i].Remove(j),DKA2[i].Substring(j)));
                w.WriteLine(DKA[i].naziv+" "+DKA[i].zavrsni);
            }
            w.Close();
            for (i = 0; i < DKA.Count; i++)
            {
                if (DKA[i].naziv[0].ToString().Equals((BROJAC.Count-1).ToString()))
                {
                    BROJAC[DKA[i].naziv[0]-48]++;
                    continue;
                }
                else
                {
                    BROJAC.Add(1);
                }

            }
            for (i = 0; i < BROJAC.Count; i++)
            {
                w2.Write(i + ",(" + BROJAC[i] + ")");
                for(j=0;j<DKA.Count;j++)
                     if(DKA[j].naziv[0]-48==i)
                          w2.Write(" "+DKA[j].naziv.Substring(1));
                w2.WriteLine();
            }
            w2.Close();

            return DKA;
       }

        public static void Spoji_DKA()   //stanja koja bez zavrsnih znakova izgledaju isto, mijenjaju ime u manje od dva ponudena
        {
            string naziv;
            int i = 0;
            string exePath = System.IO.Path.GetDirectoryName(System.Windows.Forms.Application.ExecutablePath);
            StreamWriter w = new StreamWriter(exePath + "\\DKA_LALR.txt");
            StreamReader r = new StreamReader(exePath + "\\BROJAC.txt");
            StreamWriter z = new StreamWriter(exePath + "\\STANJA_LALR.txt");
            do
            {
                i++;
                naziv = r.ReadLine();
                if (naziv == null) break;
                DKA_LINIJA.Add(naziv);
            } while (naziv != null);

            r.Close();
            
            
            for(i=0;i<DKA_LINIJA.Count;i++)
            {
                for(int j=i+1;j<DKA_LINIJA.Count;j++)
                {
                    if (DKA_LINIJA[i].Substring(1).Equals(DKA_LINIJA[j].Substring(1)))
                    {
                        for (int k = 0; k < PRIJELAZI3.Count; k++)
                        {
                            if (PRIJELAZI3[k].stanje1[0].Equals((char)(j + 48)))
                                PRIJELAZI3[k].stanje1 = PRIJELAZI3[k].stanje1.Replace((char)(j + 48),(char)(i + 48));
                            if (PRIJELAZI3[k].stanje2[0].Equals((char)(j + 48)))
                                PRIJELAZI3[k].stanje2 = PRIJELAZI3[k].stanje2.Replace((char)(j + 48), (char)(i + 48));
                        }
                        for (int k=0;k<DKA.Count;k++)
                            if (DKA[k].naziv[0].Equals((char)(j+48)))
                                DKA[k].naziv = DKA[k].naziv.Replace((char)(j + 48), (char)(i + 48));

                    }
                }
            }
            for(i=0;i<PRIJELAZI3.Count;i++)
                  w.WriteLine(PRIJELAZI3[i].stanje1+" "+PRIJELAZI3[i].prijelaz+" "+PRIJELAZI3[i].stanje2);
            w.Close();
            for (i = 0; i < DKA.Count; i++)
                z.WriteLine(DKA[i].naziv + " " + DKA[i].zavrsni);
            z.Close();
            
            
            
        }


        


        public static List<Redak_Tablica> PopuniPROD(string path)
        {
            string naziv;
            int i = 0;

            StreamReader r = new StreamReader(path);               

            do
            {
                i++;
                naziv = r.ReadLine();                              
                if (naziv == null) break;                          
                PRODUKCIJE.Add(new Redak_Tablica(naziv));          
            } while (naziv != null);

            r.Close();
            return PRODUKCIJE;
        }
        public static List<Redak_Tablica> popuniSTAVKE(string path)
        {
            string naziv;
            int i = 0;

            StreamReader r = new StreamReader(path);

            do
            {
                i++;
                naziv = r.ReadLine();
                if (naziv == null) break;
                STAVKE.Add(new Redak_Tablica(naziv));
            } while (naziv != null);

            r.Close();
            return STAVKE;
        }

        public static List<Redak_Tablica> popuniZAPOCINJE(string path)
        {
            string naziv;
            int i = 0;
            char znak;

            StreamReader r = new StreamReader(path);

            do
            {
                i++;
                naziv = r.ReadLine();
                if (naziv == null) break;
                znak = naziv[0];
                naziv=naziv.Substring(2);
                ZAPOCINJE.Add(new Redak_Tablica(znak, naziv));
            } while (naziv != null);

            r.Close();
            return ZAPOCINJE;
        }




        public static bool prazni_niz(string ulaz)
        {
            for (int i = 0; i < ulaz.Length; i++)
            {
                if (ulaz[i] < 'A' || ulaz[i] > 'Z')
                    return false;
                for (int j=0; j < PRODUKCIJE.Count; j++)
                    {
                        if (ulaz[i] == PRODUKCIJE[j].naziv[0] && PRODUKCIJE[j].naziv.Length == 3)
                        {
                            ulaz=ulaz.Remove(i, 1);
                            i = i - 1;
                            break;
                        }
                    }
                if(ulaz.Length==0) return true;

            }
            for (int i = 0; i < ulaz.Length; i++)
            {
                for (int j = 0; j < PRODUKCIJE.Count; j++)
                {
                    if (PRODUKCIJE[j].naziv[0] == ulaz[i])
                    {
                        int k;
                        string ul = ulaz[i].ToString();
                        for (k = 3; k < PRODUKCIJE[j].naziv.Length; k++)
                        {
                            if (PRODUKCIJE[j].naziv[k] < 'A' || PRODUKCIJE[j].naziv[k] > 'Z')
                                break;
                        }
                        if (k == PRODUKCIJE[j].naziv.Length)
                            ulaz = ulaz.Replace(ul, PRODUKCIJE[j].naziv.Substring(3));
                    }
                }
            }
            for (int i = 0; i < ulaz.Length; i++)
            {
                if (ulaz[i] < 'A' || ulaz[i] > 'Z')
                    return false;
                for (int j=0; j < PRODUKCIJE.Count; j++)
                {
                    if (ulaz[i] == PRODUKCIJE[j].naziv[0] && PRODUKCIJE[j].naziv.Length == 3)
                    {
                        ulaz=ulaz.Remove(i, 1);
                        i--;
                        break;
                    }
                }
                if (ulaz.Length == 0) return true;

            }
            return false;    

        }
    }
}

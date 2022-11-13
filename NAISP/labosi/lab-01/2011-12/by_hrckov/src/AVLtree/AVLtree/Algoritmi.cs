using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Runtime.InteropServices;
using System.Drawing;

namespace AVLtree
{
    public static class Algoritmi
    {
        public static Cvor root;

        #region Dodavanje
        public static bool UcitajDatoteku(string path)
        {
            StreamReader fs = new StreamReader(path);
            string file = fs.ReadToEnd();
            List<int> listaBrojeva = new List<int>();
            string[] brojevi = file.Split(' ');
            for (int i = 0; i < brojevi.Length; i++)
            {
                int broj;
                if(int.TryParse(brojevi[i],out broj) && broj>=0)
                {                    
                    listaBrojeva.Add(Convert.ToInt32(broj));
                }
            }

            root = null;
            foreach (int i in listaBrojeva)
            {
                root=DodajCvor(root, i);
                PostaviVisine(tmpCvor);
            }
            fs.Close();
            return true;
        }

        public static Cvor tmpCvor;

        public static Cvor DodajCvor(Cvor cvor, int broj,Cvor roditelj=null)
        {
            if (cvor == null)
            {
                Cvor novi = new Cvor(broj);
                novi.Roditelj = roditelj;
                tmpCvor = novi;
                return novi;
            }
            else
            {
                if (broj < cvor.Podatak)
                {
                    cvor.LijevoDijete = DodajCvor(cvor.LijevoDijete, broj, cvor);
                }
                else if(broj>cvor.Podatak)
                {
                    cvor.DesnoDijete = DodajCvor(cvor.DesnoDijete, broj, cvor);
                }
                return cvor;
            }
        }

        public static void PostaviVisine(Cvor cvor)
        {
            Cvor pomocni = cvor;
            while (pomocni.Roditelj != null)
            {                 
                if (pomocni.Roditelj.LijevoDijete == pomocni)
                {
                    pomocni.Roditelj.VisinaLijevo = pomocni.Visina + 1;
                    if (ProvjeriFR(pomocni))
                    {
                        break;
                    }
                    if (pomocni.Roditelj == null /*|| pomocni.Roditelj.VisinaLijevo <= pomocni.Roditelj.VisinaDesno*/)
                    {
                        break;
                    }
                }
                if(pomocni.Roditelj.DesnoDijete == pomocni)
                {
                    pomocni.Roditelj.VisinaDesno = pomocni.Visina + 1;
                    if (ProvjeriFR(pomocni))
                    {
                        break;
                    }
                    if (pomocni.Roditelj==null/* ||pomocni.Roditelj.VisinaLijevo >= pomocni.Roditelj.VisinaDesno*/)
                    {
                        break;
                    }
                }
                pomocni = pomocni.Roditelj;
            }
        }

        public static bool ProvjeriFR(Cvor cvor)
        {
            if (cvor.Roditelj!=null && cvor.Roditelj.FR == 2)
            {
                if (cvor.FR == 1)
                {
                    Cvor pom1 = cvor.Roditelj;
                    Cvor pom2 = cvor;

                    LijevaRotacija(cvor.Roditelj, cvor);
                    pom1.PostaviVisine();
                    pom2.PostaviVisine();
                    return true;
                }
                if (cvor.FR == -1)
                {
                    Cvor djed = cvor.Roditelj;
                    Cvor pom = cvor.LijevoDijete;
                    
                    DesnaRotacija(cvor, pom);
                    LijevaRotacija(djed, pom);
                    cvor.PostaviVisine();
                    djed.PostaviVisine();
                    pom.PostaviVisine();
                    return true;
                }
            }
            if (cvor.Roditelj != null && cvor.Roditelj.FR == -2)
            {
                if (cvor.FR == 1)
                {
                    Cvor djed = cvor.Roditelj;
                    Cvor pom = cvor.DesnoDijete;
                    
                    LijevaRotacija(cvor, pom);
                    DesnaRotacija(djed, pom);
                    cvor.PostaviVisine();
                    djed.PostaviVisine();
                    pom.PostaviVisine();
                    return true;
                }
                if (cvor.FR == -1)
                {
                    Cvor pom1 = cvor.Roditelj;
                    Cvor pom2 = cvor;

                    DesnaRotacija(cvor.Roditelj, cvor);
                    pom1.PostaviVisine();
                    pom2.PostaviVisine();
                    return true;
                }
            }

            if (cvor.Roditelj != null && cvor.Roditelj.FR == 0)
            {
                return true;
            }
            return false;
        }
        #endregion
        #region Crtanje
        const int radius = 30;
        public static Graphics graphicsObj;

        public static void CrtajSve(Cvor cvor,int razina,int y, int x)
        {
            if (cvor == null) { return; }
            int sirina;
            sirina = (int)Sucelje.width / (int)Math.Pow(2, (double)razina); 
            cvor.Graf = new CvorGraph(y, x,cvor.Podatak);
            cvor.Graf.FR = cvor.FR;
            //cvor.Graf.vl = cvor.VisinaLijevo;
            //cvor.Graf.vd = cvor.VisinaDesno;
            Pen myPen = new Pen(System.Drawing.Color.Red, 2);
            //Pen myPen1 = new Pen(Color.SlateGray, 1);
            //graphicsObj.DrawLine(myPen1, new Point(0, y), new Point(Sucelje.width, y));
            if (cvor.LijevoDijete != null)
            {
                graphicsObj.DrawLine(myPen,new Point(x,y),new Point(x-sirina/2,y+radius+5));
                CrtajSve(cvor.LijevoDijete,razina + 1, y+radius+5, x-sirina/2);
            }
            if (cvor.DesnoDijete != null)
            {
                graphicsObj.DrawLine(myPen, new Point(x, y), new Point(x + sirina / 2, y + radius + 5));
                CrtajSve(cvor.DesnoDijete, razina + 1, y + radius + 5, x + sirina / 2);
            }
            cvor.Graf.CrtajCvor();
        }


        #endregion
        #region Rotacije
        static void DesnaRotacija(Cvor roditelj, Cvor dijete)
        {
            if (roditelj.Roditelj != null)
            {
                if (roditelj.Roditelj.DesnoDijete == roditelj)
                {
                    roditelj.Roditelj.DesnoDijete = dijete;
                }
                else if (roditelj.Roditelj.LijevoDijete == roditelj)
                {
                    roditelj.Roditelj.LijevoDijete = dijete;
                }
            }
            else
            {
                root = dijete;
            }
            roditelj.LijevoDijete = dijete.DesnoDijete;
            dijete.DesnoDijete = roditelj;

            dijete.Roditelj = roditelj.Roditelj;
            roditelj.Roditelj = dijete;
            try
            {
                roditelj.LijevoDijete.Roditelj = roditelj;
            }
            catch { }
        }

        static void LijevaRotacija(Cvor roditelj, Cvor dijete)
        {
            if (roditelj.Roditelj != null)
            {
                if (roditelj.Roditelj.DesnoDijete == roditelj)
                {
                    roditelj.Roditelj.DesnoDijete = dijete;
                }
                else if (roditelj.Roditelj.LijevoDijete == roditelj)
                {
                    roditelj.Roditelj.LijevoDijete = dijete;
                }
            }
            else
            {
                root = dijete;
            }
            roditelj.DesnoDijete = dijete.LijevoDijete;
            dijete.LijevoDijete = roditelj;

            dijete.Roditelj = roditelj.Roditelj;
            roditelj.Roditelj = dijete;
            try
            {
                roditelj.DesnoDijete.Roditelj = roditelj;
            }
            catch { }
        }
        #endregion

        #region Brisanje
        public static Cvor NadjiCvor(int podatak)
        {
            Cvor pomocni = root;
            while (pomocni != null)
            {
                if (podatak < pomocni.Podatak)
                {
                    pomocni = pomocni.LijevoDijete;
                }
                else if (podatak > pomocni.Podatak)
                {
                    pomocni = pomocni.DesnoDijete;
                }
                else
                {
                    return pomocni;
                }
            }
            return null;
        }

        static Cvor dohvatiZadnjeg(Cvor cvor)
        {
            Cvor zadnji=cvor;
            if (zadnji.LijevoDijete == null)
            {
                return zadnji;
            }
            else
            {
                zadnji = zadnji.LijevoDijete;
            }
            while (zadnji.DesnoDijete != null)
            {
                zadnji = zadnji.DesnoDijete;
            }
            return zadnji;
        }

        public static void IzbrisiCvor(int podatak)
        {
            Cvor delCvor = null;
            Cvor zamjenski = null;
            if ((delCvor = NadjiCvor(podatak)) == null)
            {
                return;
            }
            zamjenski = dohvatiZadnjeg(delCvor);

            if (zamjenski == delCvor)
            {
                if (delCvor.Roditelj == null)
                { 
                    root = null;
                    return;
                }
                //nema lijevo podstablo
                if (zamjenski.Roditelj.LijevoDijete == zamjenski)
                {
                    zamjenski.Roditelj.LijevoDijete = zamjenski.DesnoDijete;                    
                }
                else
                {
                    zamjenski.Roditelj.DesnoDijete = zamjenski.DesnoDijete;
                }
                try
                {
                    zamjenski.DesnoDijete.Roditelj = zamjenski.Roditelj;
                }
                catch { }
                PostaviVisineDel(zamjenski.Roditelj);
                return;
            }

            //ima lijevo podstablo
            delCvor.Podatak = zamjenski.Podatak;

            if (zamjenski.Roditelj.LijevoDijete == zamjenski)
            {//ako je prvi susjedni lijevi
                zamjenski.Roditelj.LijevoDijete = zamjenski.LijevoDijete;
            }
            else
            {
                zamjenski.Roditelj.DesnoDijete = zamjenski.LijevoDijete;
            }
            try
            {
                zamjenski.LijevoDijete.Roditelj = zamjenski.Roditelj;
            }
            catch { }


            PostaviVisineDel(zamjenski.Roditelj);

                        
        }

        static void PostaviVisineDel(Cvor cvor)
        {
            if (cvor == null) { return; }
            cvor.PostaviVisine();
            Cvor tmp1;
            Cvor tmp2;
            Cvor tmp3;
            switch (cvor.FR)
            {
                case 0: PostaviVisineDel(cvor.Roditelj);
                    return;
                case 1: return;
                case -1:return;

                case 2:
                    switch(cvor.DesnoDijete.FR)
                    {
                        case 0:
                            tmp1=cvor;
                            tmp2=cvor.DesnoDijete;
                            LijevaRotacija(cvor,cvor.DesnoDijete);
                            PostaviVisineDel(tmp1);
                            PostaviVisineDel(tmp2);
                            return;

                        case 1:
                            tmp1=cvor;
                            tmp2=cvor.DesnoDijete;
                            LijevaRotacija(cvor,cvor.DesnoDijete);
                            PostaviVisineDel(tmp1);
                            PostaviVisineDel(tmp2);
                            return;

                        case -1:
                            tmp1 = cvor;
                            tmp2 = cvor.DesnoDijete;
                            tmp3 = cvor.DesnoDijete.LijevoDijete;
                            DesnaRotacija(tmp2, tmp3);
                            LijevaRotacija(tmp1, tmp3);
                            PostaviVisineDel(tmp1);
                            PostaviVisineDel(tmp2);
                            PostaviVisineDel(tmp3);
                            return;
                    }
                    break;
                
                case -2:
                    switch(cvor.LijevoDijete.FR)
                    {
                        case 0:
                            tmp1=cvor;
                            tmp2 = cvor.LijevoDijete;
                            DesnaRotacija(cvor, cvor.LijevoDijete);
                            PostaviVisineDel(tmp1);
                            PostaviVisineDel(tmp2);
                            return;

                        case -1:
                            tmp1=cvor;
                            tmp2 = cvor.LijevoDijete;
                            DesnaRotacija(cvor, cvor.LijevoDijete);
                            PostaviVisineDel(tmp1);
                            PostaviVisineDel(tmp2);
                            return;
                            
                        case 1:
                            tmp1 = cvor;
                            tmp2 = cvor.LijevoDijete;
                            tmp3 = cvor.LijevoDijete.DesnoDijete;
                            LijevaRotacija(tmp2, tmp3);
                            DesnaRotacija(tmp1, tmp3);
                            PostaviVisineDel(tmp1);
                            PostaviVisineDel(tmp2);
                            PostaviVisineDel(tmp3);
                            return;

                    }
                    break;

            }
        }
        #endregion
    }
}

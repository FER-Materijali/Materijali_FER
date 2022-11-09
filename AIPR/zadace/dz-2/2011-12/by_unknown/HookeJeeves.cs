using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace APR___lab2
{
    public class HookeJeeves
    {
        // samo tekstualni prikaz koji se prikaže na formi
        public static string korisnickaFunkcija = "(x[0] - 1)*(x[0]-1) + (x[1] - 1)*(x[1]-1)";


        List<double> pocetnaTocka;
        List<double> vektorPomaka;
        List<double> vektorPreciznosti;

        // ulazni podaci za funkciju "Ž" (x1-p1)^2 + (x2-p2)^2 + ... + (xn-pn)^2 (proizvoljne duljine)
        List<double> podaci;

        // Konstruktor
        public HookeJeeves(List<double> _pocetnaTocka, List<double> _vektorPomaka, List<double> _vektorPreciznosti)
        {
            pocetnaTocka = VratiKopijuListe(_pocetnaTocka);
            vektorPomaka = VratiKopijuListe(_vektorPomaka);
            vektorPreciznosti = VratiKopijuListe(_vektorPreciznosti);
        }

        // Pokretanje s podacima za funkciju "Ž", rb-redni broj funkcije, txtBox - ispis koraka
        public void PokreniAlgoritam(int rb, List<double> _podaci, TextBox txtBox)
        {
            podaci = VratiKopijuListe(_podaci);
            PokreniAlgoritam(rb, txtBox);
        }

        // Algoritam, rb - redni broj funkcije, txtBox - ispis koraka
        public void PokreniAlgoritam(int rb, TextBox txtBox)
        {
            /*************************************ISPIS*******************************************/
            txtBox.Text = "   Xb      Xp      Xn       dx" + Environment.NewLine + Environment.NewLine;
            /*************************************************************************************/
            List<double> xB, xP, xN, dx, e ;
            xP = xB = VratiKopijuListe(pocetnaTocka);
            dx = VratiKopijuListe(vektorPomaka);
            e = VratiKopijuListe(vektorPreciznosti);

            bool uvjet = true;
            do
            {

                xN = Istrazi(xP, dx, rb);
                /*************************************ISPIS*******************************************/
                txtBox.Text += ListaUString(xB) + "  ";
                txtBox.Text += ListaUString(xP) + "  ";
                txtBox.Text += ListaUString(xN) + "  ";
                txtBox.Text += "  " + dx[0];
                txtBox.Text += Environment.NewLine;
                /*************************************************************************************/

                if (F(rb, xN) < F(rb, xB))
                {
                    for (int i = 0; i < xP.Count; i++)
                    {
                        xP[i] = 2 * xN[i] - xB[i];
                    }
                    xB = VratiKopijuListe(xN);
                }
                else
                {
                    SmanjiDx(dx);
                    xP = VratiKopijuListe(xB);
                }

                uvjet = true;

                for (int i = 0; i < xB.Count; i++)
                    if (dx[i] > e[i])
                        uvjet = false;
            }
            while (!uvjet);


            /**************************************ISPIS*****************************************/
            txtBox.Text += Environment.NewLine+Environment.NewLine +  "RJEŠENJE:" + Environment.NewLine + ListaUString(xB);
            /*************************************************************************************/

            return;
        }

        // pomoćna funkcija
        private string ListaUString(List<double> lista)
        {
            string izlaz = "(";
            for (int i=0; i< lista.Count-1; i++)
            {
                izlaz += String.Format("{0}, ", lista[i]);
            }
            izlaz += lista[lista.Count-1] + ")";
            return izlaz;
        }

        // pretraživanje okolice točke xP s pomakom dx u funkciji s rednim brojem rb
        private List<double> Istrazi(List<double> xP, List<double> dx, int rb)
        {
            List<double> x = VratiKopijuListe(xP);
            for (int i = 0; i < x.Count; i++)
            {
                double P = F(rb, x);
                x[i] += dx[i];
                double N = F(rb, x);
                if (N > P)
                {
                    x[i] -= 2 * dx[i];
                    N = F(rb, x);
                    if (N > P)
                        x[i] += dx[i];
                }
            }
            return x;
        }

        // pomoćna Funkcija
        private static List<double> VratiKopijuListe(List<double> lista)
        {
            List<double> kopija = new List<double>();
            for (int i = 0; i < lista.Count; i++)
            {
                kopija.Add(lista[i]);
            }
            return kopija;
        }

        // pomoćna Funkcija
        private void SmanjiDx(List<double> lista)
        {
            for (int i = 0; i < lista.Count; i++)
            {
                lista[i] /= 2.0;
            }
        }


        // definicije funkcija
        #region FUNKCIJE

        private double Funkcija1(List<double> x)
        {
            if (x.Count != 2) throw new Exception("F1 error");
            return 10 * (x[0]*x[0] - x[1]) * (x[0]*x[0] - x[1]) + (1 - x[0]) * (1 - x[0]);

        }

        private double Funkcija2(List<double> x)
        {
            if (x.Count != 2) throw new Exception("F2 error");
            return (x[0] - 4) * (x[0] - 4) + 4 * (x[1] - 2) * (x[1] - 2);
        }

        private double Funkcija3(List<double> x, List<double> p)
        {
            double suma=0;
            for (int i = 0; i < x.Count; i++)
            {
                suma += (x[i] - p[i]) * (x[i] - p[i]);
            }
            return suma;
        }

        private double Funkcija4(List<double> x)
        {
            if (x.Count != 2) throw new Exception("F4 error");
            return Math.Abs((x[0] - x[1]) * (x[0] + x[1])) + Math.Sqrt(x[0] * x[0] + x[1] * x[1]);
        }

        private double FunkcijaKorisnik(List<double> x)
        {
            if (x.Count != 2) throw new Exception("F1 error");
            korisnickaFunkcija = "(x[0] - 1)(x[0]-1) + (x[1] - 1)(x[1]-1)";
            return (x[0] - 1)*(x[0]-1) + (x[1] - 1)*(x[1]-1);
        }

        double F(int i, List<double> vektor)
        {
            switch(i)
            {
                case 1:
                    return Funkcija1(vektor);
                case 2:
                    return Funkcija2(vektor);
                case 3:
                    return Funkcija3(vektor, podaci);
                case 4:
                    return Funkcija4(vektor);
                case 5:
                    return FunkcijaKorisnik(vektor);
                default:
                    return 0;
            }
        }

        #endregion

        

    }
}

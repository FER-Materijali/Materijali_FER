using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace APR___lab2
{
    public class Box
    {
        List<double> pocetnaTocka;
        double koeficijentRefleksije;
        double preciznost;
        List<double> podaci;
        int indeksFunkcije;

        string nl = Environment.NewLine;

        EksplicitnoOgranicenje eks = new EksplicitnoOgranicenje(-100,100);
        ImplicitnoOgranicenje imp = new ImplicitnoOgranicenje();

        public Box(List<double> _pocetnaTocka, double _koeficijentRefleksije, double _preciznost)
        {
            pocetnaTocka = VratiKopijuListe(_pocetnaTocka);
            koeficijentRefleksije = _koeficijentRefleksije;
            preciznost = _preciznost;
        }

        private static List<double> VratiKopijuListe(List<double> lista)
        {
            List<double> kopija = new List<double>();
            for (int i = 0; i < lista.Count; i++)
            {
                kopija.Add(lista[i]);
            }
            return kopija;
        }

        public void PokreniAlgoritam(int rb, List<double> _podaci, TextBox txtBox)
        {
            podaci = VratiKopijuListe(_podaci);
            PokreniAlgoritam(rb, txtBox);
        }

        public void PokreniAlgoritam(int rb, TextBox txtBox)
        {
            indeksFunkcije = rb;
            Random random = new Random();
            if (!ZadovoljavaSvaOgranicenja(pocetnaTocka))
                throw new Exception("Točka ne zadovoljavana sva ograničenja!");

            List<double> X0 = VratiKopijuListe(pocetnaTocka);
            List<List<double>> X_2N = new List<List<double>>();

            List<double> Xc = VratiKopijuListe(X0);
            
            int n= X0.Count;

            for (int t = 0; t < 2 * n; t++)
            {
                X_2N.Add(new List<double>());
                for (int i = 0; i < n; i++)
                {
                    
                    X_2N[t].Add(0.0);
                    X_2N[t][i] = eks.DonjaGranica + random.NextDouble() * (eks.GornjaGranica - eks.DonjaGranica);                 
                }

                //ispis
                string s = "Generirani: " + ListaUString(X_2N[t]) + nl;
                txtBox.Text += s;

                while (!imp.Zadovoljava(X_2N[t]))
                {
                    X_2N[t]=PomakniTocku(X_2N[t], Xc);
                }
                

                Xc = IzracunajCentroid(X_2N);
                
                //ispis
                string sss = "Xc: " + ListaUString(Xc) + nl;
                txtBox.Text += sss;
            }

            bool uvjet = true;
            do
            {
                int h = IndeksNajlosijeg(X_2N);
                int h2 = IndeksDrugogNajlosijeg(X_2N, h);
                Xc = IzracunajCentroidBezNajlosijeg(X_2N, h);
                List<double> Xr = VratiXr(Xc, X_2N[h], koeficijentRefleksije);

                for (int i = 0; i < Xc.Count; i++)
                {
                    if (Xr[i] < eks.DonjaGranica)
                    {
                        Xr[i] = eks.DonjaGranica;
                    }
                    else if (Xr[i] > eks.GornjaGranica)
                    {
                        Xr[i] = eks.GornjaGranica;
                    }
                }

                while (!imp.Zadovoljava(Xr) || !eks.Zadovoljava(Xr))
                {
                    Xr = PomakniTocku(Xr, Xc);
                }
                if (F(indeksFunkcije, Xr) > F(indeksFunkcije, X_2N[h2]))
                {
                    Xr = PomakniTocku(Xr, Xc);
                }
                X_2N[h] = Xr;

                uvjet = true;
                for (int i = 0; i < Xc.Count; i++)
                    if (Math.Abs(X_2N[h][i] - Xc[i]) > preciznost)
                        uvjet = false;

            }
            while (!uvjet);
            txtBox.Text += nl+ nl + "Rezultat: " +  ListaUString(Xc);

        }

        public List<double> VratiXr(List<double> _Xc, List<double> _Xh, double k)
        {
            List<double> rez = new List<double>();
            for (int i = 0; i < _Xc.Count; i++)
            {
                rez.Add(0);
                rez[i] = (1.0 + k) * _Xc[i] - k * _Xh[i];
            }
            return rez;
        }

        public int IndeksNajlosijeg(List<List<double>> tocke)
        {
            int najlosiji = 0;
            double H = F(indeksFunkcije, tocke[najlosiji]);
            for (int i = 1; i < tocke.Count; i++)
            {
                if (F(indeksFunkcije, tocke[i]) > H)
                {
                    najlosiji = i;
                    H = F(indeksFunkcije, tocke[i]);
                }
            }
            return najlosiji;
        }

        public int IndeksDrugogNajlosijeg(List<List<double>> tocke, int indeksNajlosijeg)
        {
            int drugiNajlosiji;
            double H;
            if (indeksNajlosijeg == 0)
            {
                drugiNajlosiji = 1;
            }
            else
            {
                drugiNajlosiji = 0;
            }
            H = F(indeksFunkcije, tocke[drugiNajlosiji]);


            for (int i = 0; i < tocke.Count; i++)
            {
                if (i == indeksNajlosijeg) continue;
                if (F(indeksFunkcije, tocke[i]) > H)
                {
                    drugiNajlosiji = i;
                    H = F(indeksFunkcije, tocke[i]);
                }
            }
            return drugiNajlosiji;
        }


        public List<double> IzracunajCentroid(List<List<double>> liste)
        {
            List<double> centroid = new List<double>();
            for (int i = 0; i < liste[0].Count; i++)
            {
                centroid.Add(0);
            }
            foreach (List<double> lista in liste)
            {
                for (int i = 0; i < lista.Count; i++)
                {
                    centroid[i] += lista[i];
                }
            }
            for (int i = 0; i < centroid.Count; i++)
            {
                centroid[i] /= liste.Count;
            }
            return centroid;
        }

        public List<double> IzracunajCentroidBezNajlosijeg(List<List<double>> liste, int indeksNajlosijeg)
        {
            List<double> centroid = new List<double>();
            for (int i = 0; i < liste[0].Count; i++)
            {
                centroid.Add(0);
            }
            for (int i=0; i< liste.Count; i++)
            {
                if (i == indeksNajlosijeg) continue;
                for (int j = 0; j < liste[0].Count; j++)
                {
                    centroid[j] += liste[i][j];
                }
            }
            for (int i = 0; i < centroid.Count; i++)
            {
                centroid[i] /= (liste.Count-1);
            }
            return centroid;
        }



        public List<double> PomakniTocku(List<double> t1, List<double> t2)
        {
            List<double> tx = VratiKopijuListe(t1);
            if (t1.Count != t2.Count)
                throw new Exception("Nevaljalo korigiranje točke, različita dimenzionalnost!");
            Random rand = new Random();
            for (int i = 0; i < t1.Count; i++)
            {
                tx[i] = /*rand.NextDouble() */ 0.5 * (tx[i] + t2[i]);
            }
            return tx;
        }


                   

        bool ZadovoljavaSvaOgranicenja(List<double> x)
        {
            if (eks.Zadovoljava(x) && imp.Zadovoljava(x))
                return true;
            else return false;
        }

        private string ListaUString(List<double> lista)
        {
            string izlaz = "(";
            for (int i = 0; i < lista.Count - 1; i++)
            {
                izlaz += String.Format("{0}, ", lista[i]);
            }
            izlaz += lista[lista.Count - 1] + ")";
            return izlaz;
        }


        #region FUNKCIJE


        private double Funkcija1(List<double> x)
        {
            if (x.Count != 2) throw new Exception("F2 error");
            return (x[0] - 4) * (x[0] - 4) + 4 * (x[1] - 2) * (x[1] - 2);
        }

        private double Funkcija2(List<double> x, List<double> p)
        {
            double suma = 0;
            for (int i = 0; i < x.Count; i++)
            {
                suma += (x[i] - p[i]) * (x[i] - p[i]);
            }
            return suma;
        }


        double F(int i, List<double> vektor)
        {
            switch (i)
            {
                case 1:
                    return Funkcija1(vektor);
                case 2:
                    return Funkcija2(vektor, podaci);
                default:
                    return 0;
            }
        }

        #endregion
    }
}

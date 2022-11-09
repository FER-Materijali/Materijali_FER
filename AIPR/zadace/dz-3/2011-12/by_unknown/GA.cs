using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace GenetskiApr
{
    public class GA
    {
        int velicinaPopulacije;
        int brojVrijednostiUKromosomu;
        int brojZnamenkiPreciznostiRjesenja;

        double vjerojatnostMutacijeKromosoma;
        int donjaGranicaVrijednosti;
        int gornjaGranicaVrijednosti;

        int redniBrojNajbolje;

        int oznakaFunkcije = 0;
        const int velicinaTurnira = 3;

        List<Kromosom> kromosomi = new List<Kromosom>();
        public TextBox tb = null;

        string nl = Environment.NewLine;
        Random random = new Random();

        public List<double> p;



        
        // KONSTRUKTOR
        public GA(int _velicinaPopulacije, int _brojVrijednostiUKromosomu, int _brojZnamenkiPreciznosti, int _donjaGranicaVrijednosti, int _gornjaGranicaVrijednosti, double _vjerojatnostMutacije, int _oznakaFunkcije, TextBox _tb, List<double> _p)
        {
            velicinaPopulacije = _velicinaPopulacije;
            brojVrijednostiUKromosomu = _brojVrijednostiUKromosomu;
            brojZnamenkiPreciznostiRjesenja = _brojZnamenkiPreciznosti;
            vjerojatnostMutacijeKromosoma = _vjerojatnostMutacije;
            donjaGranicaVrijednosti = _donjaGranicaVrijednosti;
            gornjaGranicaVrijednosti = _gornjaGranicaVrijednosti;
            oznakaFunkcije = _oznakaFunkcije;
            tb = _tb;
            p = _p;

            GenerirajPocetnuGeneraciju();
            redniBrojNajbolje = VratiIndeksNajboljeJedinke();
        }


        private void GenerirajPocetnuGeneraciju()
        {
            for (int i = 0; i< velicinaPopulacije; i++)
            {
                Kromosom kromosom = new Kromosom(donjaGranicaVrijednosti, gornjaGranicaVrijednosti, brojZnamenkiPreciznostiRjesenja, brojVrijednostiUKromosomu);
                kromosomi.Add(kromosom);
            }
        }

        public void IzvediAlgoritam(int brojIzvodjenja)
        {
            for (int i = 0; i < brojIzvodjenja; i++)
            {
                ProvediKorakAlgoritma();
            }

            //PROVJERE!
            int indeksNajbolje = VratiIndeksNajboljeJedinke();
            tb.Text += "Najbolja: " + kromosomi[indeksNajbolje].ToString() + nl;


            int x = kromosomi[indeksNajbolje].vrijednosti.Length + 1;
            ;
            IspisKromosoma();
        }

        private int VratiIndeksNajboljeJedinke()
        {
            double min = F(kromosomi[0]);
            int redniBroj = 0;
            
            for (int i = 1; i < kromosomi.Count; i++)
            {
                if (F(kromosomi[i]) < min)
                {
                    min = F(kromosomi[i]);
                    redniBroj = i;
                }
            }
            //tb.Text += "najbolja: " + kromosomi[redniBroj].ToString() + F(kromosomi[redniBroj]) + nl;
            return redniBroj;
        }

        public void ProvediKorakAlgoritma()
        {
            // SELEKCIJA ZA TURNIR
            Random random = new Random(DateTime.Now.Millisecond);
            List<Kromosom> turnirskaLista = new List<Kromosom>();
            List<int> redniBrojevi = new List<int>();

            // slučajni odabir 3 jedinke
            while (redniBrojevi.Count < velicinaTurnira)
            {
                int broj = random.Next(0, velicinaPopulacije);
                if (!redniBrojevi.Contains(broj))
                {
                    redniBrojevi.Add(broj);
                }
            }

            foreach (int broj in redniBrojevi)
            {
                turnirskaLista.Add(kromosomi[broj]);
            }

            // traženje najgore jedinke
            double maxVrijednost = F(turnirskaLista[0]) ;
            int redniBroj = 0;

            for (int i = 1; i < velicinaTurnira; i++)
            {
                if (F(turnirskaLista[i]) > maxVrijednost)
                {
                    redniBroj = i;
                    maxVrijednost = F(turnirskaLista[i]);
                }
            }

            List<int> roditelji = new List<int>();

            for (int i = 0; i < velicinaTurnira; i++)
            {
                if (i != redniBroj)
                {
                    roditelji.Add(i);
                }
            }

            //KRIŽANJE
            ObaviKrizanje(turnirskaLista[redniBroj], turnirskaLista[roditelji[0]], turnirskaLista[roditelji[1]]);
            //MUTACIJA
            turnirskaLista[redniBroj].Mutacija(vjerojatnostMutacijeKromosoma);
            if (F(turnirskaLista[redniBroj]) < F(kromosomi[redniBrojNajbolje]))
            {
                redniBrojNajbolje = redniBrojevi[redniBroj];
                //tb.Text += kromosomi[redniBrojNajbolje].ToString() + nl;
                //tb.Text += "najbolja: " + kromosomi[redniBrojNajbolje].ToString() + F(kromosomi[redniBrojNajbolje]) + nl;
            }


        }

        private void ObaviKrizanje(Kromosom dijete, Kromosom roditelj1, Kromosom roditelj2)
        {
            int duljinaVrijednosti = (int)Math.Ceiling( Math.Log( ((double)(gornjaGranicaVrijednosti-donjaGranicaVrijednosti) * Math.Pow(10.0, brojZnamenkiPreciznostiRjesenja) + 1)));
            int[] binarniPrikazDjeteta = new int[duljinaVrijednosti*brojVrijednostiUKromosomu];

            for (int i = 0; i < duljinaVrijednosti*brojVrijednostiUKromosomu; i++)
            {
                int v1 = roditelj1.binarniPrikaz[i];
                int v2 = roditelj2.binarniPrikaz[i];

                //binarniPrikazDjeteta[i] = v1 + v2 - v1 * v2;
                if (v1 == v2)
                    binarniPrikazDjeteta[i] = v1;
                else binarniPrikazDjeteta[i] = random.Next(0, 2);
            }

            dijete.PostaviBinarniPrikazIOsvjezi(binarniPrikazDjeteta);      
        }


        private void IspisKromosoma()
        {
            string ispis = "";
            for (int i = 0; i < velicinaPopulacije; i++)
            {
                ispis += kromosomi[i].ToString() + nl;
            }
            tb.Text += ispis;
        }


        #region FUNKCIJE

        private double Funkcija1(double[] x)
        {
            double suma = 0;
            for (int i = 0; i < x.Length; i++)
            {
                suma += (x[i] - p[i]) * (x[i] - p[i]);
            }
            return suma;
        }
        private double Funkcija2(double[] x)
        {
            return Math.Abs((x[0] - x[1]) * (x[0] + x[1])) + Math.Sqrt(x[0] * x[0] + x[1] * x[1]);
        }

        private double Funkcija3(double[] x)
        {
            double zbrojKvadrata = 0;
            foreach (double vrijednost in x)
                zbrojKvadrata += Math.Pow(vrijednost, 2);

            return -0.5 + (Math.Pow(Math.Sin(Math.Pow(zbrojKvadrata, 0.5)), 2) - 0.5) / Math.Pow((1.0 + 0.001 * zbrojKvadrata), 2);
        }

        private double Funkcija4(double[] x)
        {
            double zbrojKvadrata = 0;
            foreach (double vrijednost in x)
                zbrojKvadrata += Math.Pow(vrijednost, 2);

            return Math.Pow(zbrojKvadrata, 0.25) * (Math.Pow(Math.Sin(50 * Math.Pow(zbrojKvadrata, 0.1)), 2) + 1.0);
        }

        


        private double FunkcijaKorisnik(Kromosom kromosom)
        {
            double[] vrijednosti = kromosom.vrijednosti;
            double x1 = vrijednosti[0];
            double x2 = vrijednosti[1];
            return (x1 * x1 + x2 * x2);
        }


        double F(Kromosom kromosom)
        {
            switch (oznakaFunkcije)
            {
                case 1:
                    return Funkcija1(kromosom.vrijednosti);
                case 2:
                    return Funkcija2(kromosom.vrijednosti);
                case 3:
                    return Funkcija3(kromosom.vrijednosti);
                case 4:
                    return Funkcija4(kromosom.vrijednosti);
                case 0:
                    return FunkcijaKorisnik(kromosom);
                default:
                    return 0;
            }
        }

        #endregion



    }
}

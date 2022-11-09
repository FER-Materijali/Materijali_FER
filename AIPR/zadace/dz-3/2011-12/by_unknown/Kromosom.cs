using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GenetskiApr
{
    public class Kromosom
    {
        private int donjaGranica;
        private int gornjaGranica;
        private int brojZnamenkiPreciznosti;

        private int duljinaVrijednosti;

        private int brojVrijednosti;
        public double[] vrijednosti;

        public int[] binarniPrikaz;

        static Random random = new Random(DateTime.Now.Millisecond);

        public List<double> vrijednostiP;

        


        public Kromosom(int _donjaGranica, int _gornjaGranica, int _brojZnamenkiPreciznosti, int _brojVrijednosti)
        {
            donjaGranica = _donjaGranica;
            gornjaGranica = _gornjaGranica;
            brojZnamenkiPreciznosti = _brojZnamenkiPreciznosti;
            brojVrijednosti = _brojVrijednosti;
            vrijednosti = new double[brojVrijednosti];

            duljinaVrijednosti = (int)Math.Ceiling( Math.Log( ((double)(gornjaGranica-donjaGranica) * Math.Pow(10.0, brojZnamenkiPreciznosti) + 1)));
            binarniPrikaz= new int[duljinaVrijednosti*brojVrijednosti];

            Generiraj();
            ;
        }

        public void Generiraj()
        {
            for (int i = 0; i < brojVrijednosti; i++)
            {
                for (int j = 0; j < duljinaVrijednosti; j++)
                {
                    binarniPrikaz[i * duljinaVrijednosti + j] = random.Next(0, 2);
                }
                int temp = PretvoriBinarniPrikazUDekadskuVrijednost(binarniPrikaz, i * duljinaVrijednosti, (i + 1) * duljinaVrijednosti);
                vrijednosti[i] = PretvoriUDomenskuVrijednost(temp);
            }
        }

        private int PretvoriBinarniPrikazUDekadskuVrijednost(int[] binarniPrikaz, int pocetak, int kraj)
        {
            int suma = 0;
            int b = 0;
            for (int i = pocetak; i < kraj; i++)
            {
                int potencija = kraj - pocetak - 1;
                suma += (int)Math.Pow(2, potencija - b) * binarniPrikaz[i];
                b++;
            }
            return suma;
        }

        private double PretvoriUDomenskuVrijednost(int broj)
        {
            return ((broj / (Math.Pow(2, duljinaVrijednosti) -1)) * (gornjaGranica - donjaGranica) + donjaGranica);
        }

        public void PostaviBinarniPrikazIOsvjezi(int[] _binarniPrikaz)
        {
            binarniPrikaz = _binarniPrikaz;
            for (int i = 0; i < brojVrijednosti; i++)
            {
                int temp = PretvoriBinarniPrikazUDekadskuVrijednost(binarniPrikaz, i * duljinaVrijednosti, (i + 1) * duljinaVrijednosti);
                vrijednosti[i] = PretvoriUDomenskuVrijednost(temp);
            }
        }

        public override string ToString()
        {
            string x="";
            foreach (double v in vrijednosti)
            {
                x += String.Format("{0,10:#0.000000}", v) + " ";
                //String.Format("{0}, ", lista[i]);
                //String.Format("{0,7:#0.000}"
            }
            return x;
        }

        public void Mutacija(double vjerojatnostMutacije)
        {
            for (int i = 0; i < binarniPrikaz.Length; i++)
            {
                if (random.NextDouble() < vjerojatnostMutacije)
                {
                    binarniPrikaz[i] = 1 - binarniPrikaz[i];
                }
            }
        }












    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace APR___lab4
{
    public class RungeKutta
    {
        Matrica A, B, X0;
        double T, I;
        int korakIspisa;
        TextBox tb;

        Matrica m1, m2, m3, m4;
        string nl = Environment.NewLine;


        public RungeKutta(Matrica _A, Matrica _B, Matrica _X, double _T, double _I, int _korakIspisa, TextBox _tbIspis)
        {
            A = _A;
            B = _B;
            X0 = _X;
            T = _T;
            I = _I;
            korakIspisa = _korakIspisa;
            tb = _tbIspis;

            // Ispis matrica
            tb.Text = "Matrica A: " + nl;
            tb.Text += A.ToFormatString() + nl;
            tb.Text += "Matrica B: " + nl;
            tb.Text += B.ToFormatString() + nl;
            tb.Text += "Početno stanje: " + nl;
            tb.Text += X0.ToFormatString() + nl;
            tb.Text += nl + "* * * * * * * * * Izvođenje algoritma * * * * * * * * *" + nl + nl;

        }

        public void PokreniAlgoritam()
        {

            List<Matrica> listaMatricaX = new List<Matrica>();
            listaMatricaX.Add(X0);
            int indeksZadnjeMatrice = 0;

            double preostaliInterval = I;
            while (Math.Abs(preostaliInterval) >= Math.Pow(10, -6))
            {

                m1 = A * (listaMatricaX[indeksZadnjeMatrice] + B);
                m2 = A * (listaMatricaX[indeksZadnjeMatrice] + (T / 2) * m1) + B;
                m3 = A * (listaMatricaX[indeksZadnjeMatrice] + (T / 2) * m2) + B;
                m4 = A * (listaMatricaX[indeksZadnjeMatrice] + T * m3) + B;

                Matrica Xi = listaMatricaX[indeksZadnjeMatrice] + (T / 6) * (m1 + 2 * m2 + 2 * m3 + m4);

                listaMatricaX.Add(Xi);
                indeksZadnjeMatrice++;

                if (indeksZadnjeMatrice % korakIspisa == 0)
                {
                    tb.Text += "T= " + T*indeksZadnjeMatrice + nl + Xi.ToFormatString() + nl + nl;
                }

                preostaliInterval -= T;
            }

            // Kreiranje Matlab datoteke

            System.IO.TextWriter pisac = new System.IO.StreamWriter("RungeKutta.m");
            pisac.Write("y=[");

            for (int i = 0; i < listaMatricaX[0].brojRedaka; i++)
            {
                foreach (Matrica m in listaMatricaX)
                {
                    pisac.Write(m[i, 0].ToString().Replace(',', '.') + " ");
                }
                if (i != listaMatricaX[0].brojRedaka - 1)
                    pisac.Write(";");
            }
            pisac.Write("];\nt=[");

            int brojacZaIspis = 0;
            double krajIntervala = I;

            while (Math.Abs(krajIntervala) > Math.Pow(10, -7))
            {
                pisac.Write((brojacZaIspis * T).ToString().Replace(',', '.') + "  ");
                brojacZaIspis++;
                krajIntervala -= T;
            }

            pisac.Write((brojacZaIspis * T).ToString() + " ");

            pisac.Write("];\n");

            pisac.WriteLine("\nsubplot(3,1,1), plot (t,y); \n xlabel('Vrijeme'); \n ylabel('Vrijednost varijabli stanja');" +
                          " title ('Runge-Kutta', 'FontWeight','bold', 'Color','blue'); axis([" + "0 " + I.ToString().Replace(',', '.') + " min(min(y)) max(max(y))])");
            pisac.Close();

        }

    }
}

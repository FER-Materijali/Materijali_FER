using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace APR___lab4
{
    public class TrapezniPostupak
    {
        Matrica A, B, X0;
        double T, I;
        int korakIspisa;
        TextBox tb;

        string nl = Environment.NewLine;

        public TrapezniPostupak(Matrica _A, Matrica _B, Matrica _X, double _T, double _I, int _korakIspisa, TextBox _tbIspis)
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
            Matrica J = Matrica.KreirajJedinicnuMatricu(A.brojRedaka);


            Matrica R = J - (T / 2) * A; 
            R = R.VratiInverz();
            Matrica S = R;
            R = R * (J + (T / 2) * A);
            S = S * ((T / 2) * B);

            List<Matrica> listaMatricaX = new List<Matrica>();
            listaMatricaX.Add(X0);
            int indeksZadnjeMatrice = 0;

            double preostaliInterval = I;

            while (Math.Abs(preostaliInterval) >= Math.Pow(10, -6))
            {

                Matrica Xi = R * listaMatricaX[indeksZadnjeMatrice] + S;

                listaMatricaX.Add(Xi);

                indeksZadnjeMatrice++;

                if (indeksZadnjeMatrice % korakIspisa == 0)
                {
                    tb.Text += "T= " + T * indeksZadnjeMatrice + nl + Xi.ToFormatString() + nl + nl;
                }

                preostaliInterval -= T;

            }


            // Kreiranje Matlab datoteke

            System.IO.TextWriter pisac = new System.IO.StreamWriter("Trapezna.m");
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

            pisac.WriteLine("\nsubplot(3,1,2), plot (t,y); \n xlabel('Vrijeme'); \n ylabel('Vrijednost varijabli stanja');" +
                          " title ('Trapezni postupak', 'FontWeight','bold', 'Color','red'); axis([" + "0 " + I.ToString().Replace(',', '.') + " min(min(y)) max(max(y))])");
            pisac.Close();
        }
    }
}

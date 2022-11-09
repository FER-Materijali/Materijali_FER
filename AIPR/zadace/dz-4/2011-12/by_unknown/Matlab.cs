using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace APR___lab4
{
    static class Matlab
    {
        public static void KreirajMatlabDatoteku (Matrica _A, Matrica _X, double _IntZav, string _rezultat)
        {
            Matrica A = _A;
            Matrica X = _X;


            System.IO.TextWriter datotekaMatSustava = new System.IO.StreamWriter("datMatSustava.m");

            datotekaMatSustava.Write("function yTocka = datMatSustava (t,y)\nyTocka = [");

            for (int i = 0; i < A.brojRedaka; i++)
            {
                for (int j = 0; j < A.brojStupaca; j++)
                    datotekaMatSustava.Write(A[i, j].ToString().Replace(',', '.') + " ");

                if (i != A.brojRedaka - 1)
                    datotekaMatSustava.Write(";");
            }

            datotekaMatSustava.Write("]*y;\nend");
            datotekaMatSustava.Close();


            System.IO.TextWriter datotekaMatlabRjesenja = new System.IO.StreamWriter(_rezultat);


            datotekaMatlabRjesenja.Write("function "+_rezultat.Substring(0,_rezultat.Length-2)+" \nt0=0;\ntkraj="+ _IntZav.ToString().Replace(',', '.')+";\ny0=[");

            for (int i = 0; i < X.brojRedaka; i++)
            {
                datotekaMatlabRjesenja.Write(X[i, 0].ToString().Replace(',', '.')+" ");

                if (i != X.brojRedaka - 1)
                    datotekaMatlabRjesenja.Write(";");

            }

            datotekaMatlabRjesenja.Write("];\n[t2, y2] = ode23(@datMatSustava, [t0, tkraj], y0);\nsubplot(3,1,3), " +
                "plot (t2,y2); \nxlabel('Vrijeme'); \nylabel('Vrijednost varijabli stanja'); \ntitle ('ode23', 'FontWeight','bold', 'Color','blue');" 
                 +"\naxis([0 "+_IntZav.ToString().Replace(',', '.'));

            datotekaMatlabRjesenja.WriteLine(" min(min(y2)) max(max(y2))])");


            datotekaMatlabRjesenja.Close();



        }
    }
}

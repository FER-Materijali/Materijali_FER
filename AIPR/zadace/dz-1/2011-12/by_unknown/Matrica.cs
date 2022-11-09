using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace APR___lab1
{
    public class Matrica
    {
        public int brojRedaka, brojStupaca;
        private double[,] matrica;

        public static double konstantaUsporedbe = 0.0001;

        // Konstruktor
        public Matrica(int _brojRedaka, int _brojStupaca)
        {
            if ((_brojRedaka < 1) || (_brojStupaca < 1))
                throw new Exception("Dimenzije matrice nisu važeće!");

            matrica = new double[_brojRedaka, _brojStupaca];
            brojRedaka = _brojRedaka;
            brojStupaca = _brojStupaca;
        }

        // Indekser
        public double this[int i, int j]
        {
            get
            {
                if (i < 0 || i >= brojRedaka)
                    throw new Exception("Pokušali ste pristupiti nepostojećem retku matrice!");
                if (j < 0 || j >= brojStupaca)
                    throw new Exception("Pokušali ste pristupiti nepostojećem stupcu matrice!");
                return matrica[i, j];
            }
            set
            {
                if (i < 0 || i >= brojRedaka)
                    throw new Exception("Pokušali ste zapisati vrijednost u nepostojeći redak matrice!");
                if (j < 0 || j >= brojStupaca)
                    throw new Exception("Pokušali ste zapisati vrijednost u nepostojeći stupac matrice!");
                matrica[i, j] = value;
            }
        }

        // Nadjačavanje metode ToString
        public override string ToString()
        {
            string matricaString = "";
            for (int i = 0; i < brojRedaka; i++)
            {
                for (int j = 0; j < brojStupaca; j++)
                {
                    if (j < brojStupaca - 1)
                    {
                        //matricaString += String.Format("{0,5:0.###}", matrica[i, j]) + " ";
                        matricaString += String.Format("{0,7:#0.000}", matrica[i, j]) + " ";
                    }
                    //else matricaString += String.Format("{0,5:0.###}", matrica[i, j]);
                    else matricaString += String.Format("{0,7:#0.000}", matrica[i, j]);
                }
                if (i < brojRedaka - 1)
                {
                    matricaString += Environment.NewLine;
                }
            }
            return matricaString;
        }

        // Siroviji ispis :)
        public string ToFormatString()
        {
            string matricaString = "";
            for (int i = 0; i < brojRedaka; i++)
            {
                for (int j = 0; j < brojStupaca; j++)
                {
                    if (j < brojStupaca - 1)
                    {
                        matricaString += matrica[i, j] + " ";
                    }
                    else matricaString += matrica[i, j];
                }
                if (i < brojRedaka - 1)
                {
                    matricaString += Environment.NewLine;
                }
            }
            return matricaString;
        }


        // Nadjačavanje operatora
        #region Nadjačavanje operatora

        //m3=m1+m2
        public static Matrica operator +(Matrica m1, Matrica m2)
        {
            // provjere dimenzija
            if ((m1.brojRedaka != m2.brojRedaka) || (m1.brojStupaca != m2.brojStupaca))
                throw new Exception("Matrice nisu kompatibilne za zbrajanje!");
            Matrica m3 = new Matrica(m1.brojRedaka, m1.brojStupaca);
            for (int i = 0; i < m1.brojRedaka; i++)
            {
                for (int j = 0; j < m1.brojStupaca; j++)
                {
                    m3[i, j] = m1[i, j] + m2[i, j];
                }
            }
            return m3;
        }

        //m3=m1-m2
        public static Matrica operator -(Matrica m1, Matrica m2)
        {
            // provjere dimenzija
            if ((m1.brojRedaka != m2.brojRedaka) || (m1.brojStupaca != m2.brojStupaca))
                throw new Exception("Matrice nisu kompatibilne za oduzimanje!");
            Matrica m3 = new Matrica(m1.brojRedaka, m1.brojStupaca);
            for (int i = 0; i < m1.brojRedaka; i++)
            {
                for (int j = 0; j < m1.brojStupaca; j++)
                {
                    m3[i, j] = m1[i, j] - m2[i, j];
                }
            }
            return m3;
        }

        //m3=m1*m2 (matrično)
        public static Matrica operator *(Matrica m1, Matrica m2)
        {
            // provjere dimenzija
            if (m1.brojStupaca != m2.brojRedaka)
                throw new Exception("Matrice nisu kompatibilne za množenje!");
            Matrica m3 = new Matrica(m1.brojRedaka, m2.brojStupaca);
            for (int i = 0; i < m1.brojRedaka; i++)
            {
                for (int j = 0; j < m2.brojStupaca; j++)
                {
                    m3[i, j] = 0;
                    for (int k = 0; k < m1.brojStupaca; k++)
                    {
                        m3[i, j] += m1[i, k] * m2[k, j];
                    }
                }
            }
            return m3;
        }

        //m3=c*m2 (skalarno)
        public static Matrica operator *(double skalar, Matrica m2)
        {
            Matrica m3 = new Matrica(m2.brojRedaka, m2.brojStupaca);
            for (int i = 0; i < m2.brojRedaka; i++)
            {
                for (int j = 0; j < m2.brojStupaca; j++)
                {
                    m3[i, j] = m2[i, j] * skalar;

                }
            }
            return m3;
        }

        //m3=m2*c (skalarno)
        public static Matrica operator *(Matrica m2, double skalar)
        {
            Matrica m3 = new Matrica(m2.brojRedaka, m2.brojStupaca);
            for (int i = 0; i < m2.brojRedaka; i++)
            {
                for (int j = 0; j < m2.brojStupaca; j++)
                {
                    m3[i, j] = m2[i, j] * skalar;

                }
            }
            return m3;
        }

        // m1==m2?
        public static bool operator ==(Matrica m1, Matrica m2)
        {
            if ((m1.brojRedaka != m2.brojRedaka) || (m1.brojStupaca != m2.brojStupaca))
                return false;
            for (int i = 0; i < m1.brojRedaka; i++)
            {
                for (int j = 0; j < m1.brojStupaca; j++)
                {
                    if (Math.Abs(m1[i, j] - m2[i, j]) > konstantaUsporedbe)
                        return false;
                }
            }
            return true;
        }

        // m1!=m2?
        public static bool operator !=(Matrica m1, Matrica m2)
        {
            // provjere dimenzija
            return (!(m1 == m2));
        }

        #endregion

        //Vraća kopiju matrice
        public Matrica VratiKopiju()
        {
            Matrica matricaKopija = new Matrica(brojRedaka, brojStupaca);
            for (int i = 0; i < brojRedaka; i++)
            {
                for (int j = 0; j < brojStupaca; j++)
                {
                    matricaKopija[i, j] = this[i, j];
                }
            }
            return matricaKopija;
        }

        //Zapisivanje u datoteku
        public void ZapisiUDatoteku(string adresaDatoteke)
        {
            TextWriter pisac = null;
            try
            {
                pisac = new StreamWriter(adresaDatoteke);
                pisac.Write(this.ToFormatString());
                pisac.Close();
            }

            catch
            {
                throw new Exception("Zapisivanje matrice u datoteku " + adresaDatoteke + " nije uspjelo!");
            }
        }

        // Učitavanje iz datoteke
        static public Matrica UcitajIzDatoteke(string adresaDatoteke)
        {
            List<double> listaUcitanihBrojeva = new List<double>();
            string ucitaniRedak;
            int brojRedaka = 0, brojStupaca = 0, provjeraBrojaStupaca=0;
            StreamReader citac = null;
            citac = new StreamReader(adresaDatoteke);
            while ((ucitaniRedak = citac.ReadLine()) != null)
            {
                brojRedaka++;
                foreach (string element in ucitaniRedak.Split(' ', '\t'))
                {
                    try
                    {
                        listaUcitanihBrojeva.Add(double.Parse(element));
                    }
                    catch
                    {
                        throw new Exception("Element matrice koju pokušavate iščitati iz datoteke nije broj!");
                    }
                    provjeraBrojaStupaca++;
                }
                if (brojRedaka==1)
                {
                    brojStupaca = listaUcitanihBrojeva.Count;
                }
                else
                {
                    if (provjeraBrojaStupaca != brojStupaca)
                    {
                        throw new Exception("Matrica nije učitana. Neispravno zadan oblik matrice u datoteci " + adresaDatoteke + "!");
                    }
                }
                provjeraBrojaStupaca = 0;
            }

            citac.Close();

            Matrica matrica = new Matrica(brojRedaka, brojStupaca);

            for (int i = 0; i < brojRedaka; i++)
            {
                for (int j = 0; j < brojStupaca; j++)
                {
                    matrica[i, j] = listaUcitanihBrojeva[i * brojStupaca + j];
                }
            }
            return matrica;
        }

        // Transponiranje
        public Matrica VratiTransponiranuMatricu()
        {
            Matrica transponiranaMatrica = new Matrica(this.brojStupaca, this.brojRedaka);

            for (int i = 0; i < brojRedaka; i++)
            {
                for (int j = 0; j < brojStupaca; j++)
                {
                    transponiranaMatrica[j, i] = this[i, j];
                }
            }
            return transponiranaMatrica;
        }

        // Stvaranje jedinične matrice
        static public Matrica KreirajJedinicnuMatricu(int dimenzija)
        {
            if (dimenzija < 1)
            {
                throw new Exception("Dimenzija zadane jedinične matrice mora biti veća od 0!");
            }

            Matrica jedinicnaMatrica = new Matrica(dimenzija, dimenzija);
            for (int i = 0; i < dimenzija; i++)
            {
                for (int j = 0; j < dimenzija; j++)
                {
                    if (i != j)
                    {
                        jedinicnaMatrica[i, j] = 0;
                    }
                    else
                    {
                        jedinicnaMatrica[i, j] = 1;
                    }
                }
            }
            return jedinicnaMatrica;
        }

        // Supstitucija unaprijed
        public Matrica SupstitucijaUnaprijed(Matrica b)
        {
            if (b.brojStupaca > 1)
                throw new Exception("Ulazni parametar supstitucije unaprijed mora biti ''okomiti'' vektor (dimenzija nx1)!");
            if (b.brojRedaka != this.brojRedaka)
                throw new Exception("Ulazni vektor supstitucije unaprijed nije valjane dimenzije!");
            Matrica vektorY = b.VratiKopiju();
            for (int i = 0; i < brojRedaka - 1;i++ )
            {
                for (int j = i + 1; j < brojRedaka; j++)
                {
                    vektorY[j,0] -= this[j, i] * vektorY[i,0];
                }
            }
            return vektorY;
        }

        // Supstitucija unatrag
        public Matrica SupstitucijaUnatrag(Matrica y)
        {
            if (y.brojStupaca > 1)
                throw new Exception("Ulazni parametar supstitucije unatrag mora biti ''okomiti'' vektor (dimenzija nx1)!");
            if (y.brojRedaka != this.brojRedaka)
                throw new Exception("Ulazni vektor supstitucije unatrag nije valjane dimenzije!");

            Matrica vektorX = y.VratiKopiju();

            for (int i=brojRedaka-1; i>=0; i--)
            {
                if (Math.Abs(this[i, i]) < Matrica.konstantaUsporedbe)
                {
                    throw new Exception("Postupak zaustavljen u supstituciji unatrag jer je pivot manji od zadane granice!");
                }
                vektorX[i,0] /= this[i,i];
                for (int j = 0; j < i; j++ )
                {
                    vektorX[j, 0] -= this[j, i] * vektorX[i, 0];
                }
            }
            return vektorX;
        }

        // Pomoćna metoda za popunjivanje matrice iz liste
        public void NapuniMatricu(double[] lista)
        {
            if (lista.Length != brojRedaka * brojStupaca)
                throw new Exception("Nije zadan ispravan broj elemenata!");
            for (int i = 0; i < brojRedaka; i++)
            {
                for (int j = 0; j < brojStupaca; j++)
                {
                    matrica[i, j] = lista[i * brojStupaca + j];
                }
            }
        }

        // provjerava je li matrica vektor
        public bool JeLiVektor()
        {
            if ((brojRedaka == 1) || (brojStupaca == 1))
                return true;
            else return false;
        }

        // LU Dekompozicija (prima uvjet zaustavljanja)
        public Matrica DekompozicijaLU(double usporedniUvjetZaustavljanja)
        {
            if (this.brojRedaka != this.brojStupaca)
            {
                throw new Exception("LU dekompozicija izvediva je samo na kvadratnoj matrici!");
                return null;
            }
            Matrica radnaMatrica = this.VratiKopiju();
            for (int i = 0; i < this.brojRedaka - 1; i++)
            {
                for (int j = i + 1; j < this.brojStupaca; j++)
                {
                    if (Math.Abs(radnaMatrica[i, i]) < usporedniUvjetZaustavljanja)
                    {
                        throw new Exception("LU dekompozicija je zaustavljena jer je detektiran stožerni element manji od zadane granice!");
                    }
                    radnaMatrica[j, i] /= radnaMatrica[i, i];
                    for (int k = i + 1; k < brojRedaka; k++)
                    {
                        radnaMatrica[j, k] -= radnaMatrica[j, i] * radnaMatrica[i, k];
                    }
                }
            }

            return radnaMatrica;
        }

        // LU Dekompozicija (uvjet zaustavljanja je default)
        public Matrica DekompozicijaLU()
        {
            if (this.brojRedaka != this.brojStupaca)
            {
                throw new Exception("LU dekompozicija izvediva je samo na kvadratnoj matrici!");
                //return null;
            }

            Matrica radnaMatrica = this.VratiKopiju();
            for (int i = 0; i < this.brojRedaka - 1; i++)
            {
                for (int j = i + 1; j < this.brojStupaca; j++)
                {
                    if (Math.Abs(radnaMatrica[i, i]) < konstantaUsporedbe)
                    {
                        throw new Exception("LU dekompozicija je zaustavljena jer je detektiran stožerni element manji od zadane granice!");
                    }
                    radnaMatrica[j, i] /= radnaMatrica[i, i];
                    for (int k = i + 1; k < brojRedaka; k++)
                    {
                        radnaMatrica[j, k] -= radnaMatrica[j, i] * radnaMatrica[i, k];
                    }
                }
            }

            //if (Math.Abs(radnaMatrica[brojRedaka - 1, brojStupaca - 1]) < konstantaUsporedbe)
            //    throw new Exception("LU dekompozicija je zaustavljenja jer je detektiran stožerni element manji od zadane granice!");

            return radnaMatrica;
        }

        // LUP Dekompozicija ()
        public Matrica DekompozicijaLUP(out Matrica permutacijskiVektor)
        {

            permutacijskiVektor = new Matrica(1, brojRedaka);

            Matrica radnaMatrica = this.VratiKopiju();
            for (int i = 0; i < brojRedaka; i++)
            {
                permutacijskiVektor[0, i] = i;
            }

            for (int i = 0; i < brojRedaka - 1; i++)
            {
                int pivot = i;
                for (int j = i + 1; j < brojRedaka; j++)
                {
                    if (Math.Abs(radnaMatrica[j, i]) > Math.Abs(radnaMatrica[pivot, i]))
                        pivot = j;
                }
                if (Math.Abs(radnaMatrica[pivot, i]) < Matrica.konstantaUsporedbe)
                {
                    throw new Exception("LUP dekompozicija je zaustavljena jer je detektiran stožerni element manji od zadane granice!");
                }
                radnaMatrica = radnaMatrica.ZamijeniRetke(i, pivot);
                permutacijskiVektor = permutacijskiVektor.ZamijeniStupce(i, pivot);

                for (int j = i + 1; j < brojRedaka; j++)
                {
                    radnaMatrica[j, i] /= radnaMatrica[i, i];
                    for (int k = i + 1; k < brojRedaka; k++)
                    {
                        radnaMatrica[j, k] -= radnaMatrica[j, i] * radnaMatrica[i, k];
                    }
                }
            }
            //if (Math.Abs(radnaMatrica[brojRedaka - 1, brojStupaca - 1]) < konstantaUsporedbe)
            //    throw new Exception("LUP dekompozicija je zaustavljena jer je detektiran stožerni element manji od zadane granice!");
            return radnaMatrica;
        }

        // Zamjena dva retka
        public Matrica ZamijeniRetke(int i, int j)
        {
            Matrica modificiranaMatrica = this.VratiKopiju();
            for (int k = 0; k < brojStupaca; k++)
            {
                modificiranaMatrica[i, k] = this[j, k];
                modificiranaMatrica[j, k] = this[i, k];
            }
            return modificiranaMatrica;
        }

        // Zamjena dva stupca
        public Matrica ZamijeniStupce(int i, int j)
        {
            Matrica modificiranaMatrica = this.VratiKopiju();
            for (int k = 0; k < brojRedaka; k++)
            {
                modificiranaMatrica[k, i] = this[k, j];
                modificiranaMatrica[k, j] = this[k, i];
            }
            return modificiranaMatrica;
        }

        // Iz LU matrice očitava i vraća matricu L
        public Matrica VratiMatricuL()
        {
            Matrica matricaL = new Matrica(brojRedaka, brojStupaca);

            for (int i = 0; i < brojRedaka; i++)
            {
                for (int j = 0; j < brojStupaca; j++)
                {
                    if (i == j)
                    {
                        matricaL[i, j] = 1;
                    }
                    else if (i > j)
                    {
                        matricaL[i, j] = this[i, j];
                    }
                    else
                    {
                        matricaL[i, j] = 0;
                    }
                }
            }
            return matricaL;
        }

        // Iz LU matrice očitava i vraća matricu U
        public Matrica VratiMatricuU()
        {
            Matrica matricaU = new Matrica(brojRedaka, brojStupaca);

            for (int i = 0; i < brojRedaka; i++)
            {
                for (int j = 0; j < brojStupaca; j++)
                {
                    if (i <= j)
                    {
                        matricaU[i, j] = this[i, j];
                    }
                    else
                    {
                        matricaU[i, j] = 0;
                    }
                }
            }
            return matricaU;
        }

        // Vrati permutirani vektor
        public Matrica VratiPermutiraniVektor(Matrica vektorPermutacije)
        {
            Matrica radniVektor = this.VratiKopiju();
            for (int i = 0; i < brojRedaka; i++)
            {
                radniVektor[i, 0] = this[(int)vektorPermutacije[0, i], 0];
            }
            return radniVektor;
        }

    }
}
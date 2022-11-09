using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace APR___lab1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        public Matrica A;
        public Matrica x;
        public Matrica b;

        public string nl = Environment.NewLine;

        private void button1_Click(object sender, EventArgs e)
        {
            //Matrica matrica;
            //matrica = Matrica.UcitajIzDatoteke("matrica.txt");

            //textBox1.Text = matrica.ToString();


            //Matrica A = new Matrica(2, 3);
            //A.NapuniMatricu(new double[] {1,2,3, 4,5,6});
            //A *= 2;
            //A.ZapisiUDatoteku("nekaj.txt");
            //txtMatricaA.Text = A.ToString();
            //txtMatricaA.Text += Environment.NewLine + Environment.NewLine;
            //txtMatricaA.Text += (A.Transponiraj()).Transponiraj().ToString();


            A = Matrica.UcitajIzDatoteke("matricaA.txt");
            txtMatricaA.Text = A.ToString();
            b = Matrica.UcitajIzDatoteke("vektorB.txt");
            txtVektorB.Text = b.ToString();
            Matrica permVektor;
            Matrica Adek = A.DekompozicijaLUP(out permVektor);
            MessageBox.Show(Adek.ToString());
            Matrica y_ = Adek.SupstitucijaUnaprijed(b.VratiPermutiraniVektor(permVektor));
            //MessageBox.Show(Adek.ToString());
            Matrica x = Adek.SupstitucijaUnatrag(y_);
            txtVektorX.Text = x.ToString();


        }

        private void btnUcitajA_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.Filter = "Tekstualna datoteka|*.txt";
            ofd.Title = "Odaberite matricu A";

            if (ofd.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    A = Matrica.UcitajIzDatoteke(ofd.FileName);
                    txtMatricaA.Text = A.ToString();
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, "Greška!");
                }

            }
        }

        private void btnUcitajB_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.Filter = "Tekstualna datoteka|*.txt";
            ofd.Title = "Odaberite vektor B";

            if (ofd.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    b = Matrica.UcitajIzDatoteke(ofd.FileName);
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, "Greška!");
                    return;
                }

                if (b.JeLiVektor())
                {
                    txtVektorB.Text = b.ToString();
                    return;
                }
                else
                {
                    MessageBox.Show("Učitana matrica nije vektor!", "Greška");
                    txtVektorB.Text = "";
                }
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            txtKonstantaUsporedbe.Text = Matrica.konstantaUsporedbe.ToString();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string stringBroj = txtKonstantaUsporedbe.Text;
            try
            {
                Matrica.konstantaUsporedbe = double.Parse(stringBroj);
                txtKonstantaUsporedbe.Text = Matrica.konstantaUsporedbe.ToString();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Neispravan oblik konstante usporedbe!", "Greška");
                txtKonstantaUsporedbe.Text = Matrica.konstantaUsporedbe.ToString();
            }

        }

        private void btnLUP_Click(object sender, EventArgs e)
        {
            txtRezultati.Text = "";
            try
            {
                if ((object)A == null)
                    throw new Exception("Potrebno je učitati matricu A!");
                if ((object)b == null)
                    throw new Exception("Potrebno je učitati vektor b!");
                if (A.brojRedaka != b.brojRedaka)
                    throw new Exception("Dimenzije matrice i vektora nisu kompatibilne za nastavak LUP dekompozicije!");

                Matrica permVektor;
                Matrica Adek = A.DekompozicijaLUP(out permVektor);

                /**/ txtRezultati.Text += "LUP Dekompozicija matrice A" + nl;
                /**/ txtRezultati.Text += Adek.ToString() + nl;
                /**/ txtRezultati.Text += "Matrica L" + nl;
                /**/ txtRezultati.Text += Adek.VratiMatricuL().ToString() + nl;
                /**/ txtRezultati.Text += "Matrica U" + nl;
                /**/ txtRezultati.Text += Adek.VratiMatricuU().ToString() + nl;
                /**/ txtRezultati.Text += "Permutacijski vektor" + nl;
                /**/ txtRezultati.Text += permVektor.ToString() + nl;
                /**/ txtRezultati.Text += "Vektor y' nakon permutacije" + nl;
                /**/ txtRezultati.Text += b.VratiPermutiraniVektor(permVektor).ToString() + nl;

                Matrica y_ = Adek.SupstitucijaUnaprijed(b.VratiPermutiraniVektor(permVektor));

                /**/ txtRezultati.Text += "Vektor y' nakon supstitucije unaprijed" + nl;
                /**/ txtRezultati.Text += y_.ToString();

                x = Adek.SupstitucijaUnatrag(y_);

                /**/ txtVektorX.Text = x.ToString();

                /**/txtRezultati.Text += nl + "Sustav ima rješenje!";
            }
            catch (Exception ex)
            {
                txtRezultati.Text += "Proces rješavanja zaustavljen!!" + nl;
                txtRezultati.Text += ex.Message;
            }  
        }

        private void btnLU_Click(object sender, EventArgs e)
        {
            txtRezultati.Text = "";
            try
            {
                if ((object)A == null)
                    throw new Exception("Potrebno je učitati matricu A!");
                if ((object)b == null)
                    throw new Exception("Potrebno je učitati vektor b!");
                if (A.brojRedaka != b.brojRedaka)
                    throw new Exception("Dimenzije matrice i vektora nisu kompatibilne za nastavak LU dekompozicije!");

                Matrica Adek = A.DekompozicijaLU();

                /**/ txtRezultati.Text += "LU Dekompozicija matrice A" + nl;
                /**/ txtRezultati.Text += Adek.ToString() + nl;
                /**/ txtRezultati.Text += "Matrica L" + nl;
                /**/ txtRezultati.Text += Adek.VratiMatricuL().ToString() + nl;
                /**/ txtRezultati.Text += "Matrica U" + nl;
                /**/ txtRezultati.Text += Adek.VratiMatricuU().ToString() + nl;
                /**/

                Matrica y_ = Adek.SupstitucijaUnaprijed(b);

                /**/ txtRezultati.Text += "Vektor y nakon supstitucije unaprijed" + nl;
                /**/ txtRezultati.Text += y_.ToString();

                x = Adek.SupstitucijaUnatrag(y_);

                /**/ txtVektorX.Text = x.ToString();

                /**/ txtRezultati.Text += nl + "Sustav ima rješenje!";
            }
            catch (Exception ex)
            {
                txtRezultati.Text += "Proces rješavanja zaustavljen!!" + nl;
                txtRezultati.Text += ex.Message;
            }
        }

        private void btnPohraniUDatoteku_Click(object sender, EventArgs e)
        {
            try
            {
                if ((object) x == null)
                {
                    throw new Exception("Vektor X nije definiran!");
                }
                SaveFileDialog sfd = new SaveFileDialog();
                sfd.Filter = "Tekstualna datoteka|*.txt";
                sfd.Title = "Pohranite vektor X";
                sfd.FileName = "Matrica";

                if (sfd.ShowDialog() == DialogResult.OK)
                {
                    x.ZapisiUDatoteku(sfd.FileName);
                    MessageBox.Show("Matrica je uspješno zapisana u datoteku: " + nl + sfd.FileName + nl + ":D");
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Greška!");
            }
        }

        private void label8_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Uskršnje jajce :)   10.1.2012.", "Maxur");
        }

    }
}

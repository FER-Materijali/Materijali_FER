using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Text.RegularExpressions;

namespace GenetskiApr
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            textBox1.Text = "";

            int oznakaFunkcije = 0;
            int populacija = int.Parse(tbPopulacija.Text);
            int max = int.Parse(tbMax.Text);
            int min = int.Parse(tbMin.Text);
            double mutacija = double.Parse(tbMutacija.Text);
            int preciznost = int.Parse(tbPreciznost.Text);
            int brojVrijednosti = 2;
            int N = int.Parse(tbN.Text);


            if (rb1.Checked)
            {
                oznakaFunkcije = 1;
                brojVrijednosti = 5;
            }
            else if (rb2.Checked)
            {
                oznakaFunkcije = 2;
                brojVrijednosti = 2;
            }
            else if (rb3.Checked)
            {
                oznakaFunkcije = 3;
                brojVrijednosti = int.Parse(tbVrijednosti.Text);
            }
            else if (rb4.Checked)
            {
                oznakaFunkcije = 4;
                brojVrijednosti = int.Parse(tbVrijednosti.Text);
            }




            GA genetski = new GA(populacija, brojVrijednosti, preciznost, min, max, mutacija, oznakaFunkcije, textBox1, KreirajListuBrojevaIzTeksta(tbP.Text));
            genetski.tb = textBox1;
            if (oznakaFunkcije == 1)
                genetski.p = KreirajListuBrojevaIzTeksta(tbP.Text);

            
            
            genetski.IzvediAlgoritam(100000);


        }

        public List<double> KreirajListuBrojevaIzTeksta(string tekst)
        {
            MatchCollection realniBrojevi = Regex.Matches(tekst, @"-?[0-9]+,?[0-9]*");
            List<double> listaBrojeva = new List<double>();

            foreach (Match realniBroj in realniBrojevi)
            {
                listaBrojeva.Add(Convert.ToDouble(realniBroj.Value));
            }
            return listaBrojeva;
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label9_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Uskršnje jajce :)   10.1.2012.", "Maxur");
        }


    }
}

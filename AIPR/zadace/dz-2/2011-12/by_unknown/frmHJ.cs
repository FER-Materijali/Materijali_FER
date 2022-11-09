using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Text.RegularExpressions;

namespace APR___lab2
{
    public partial class frmHJ : Form
    {
        public frmHJ()
        {
            InitializeComponent();
        }

        List<double> pocetnaTocka = new List<double>();
        List<double> vektorPomaka = new List<double>();
        List<double> vektorPreciznosti = new List<double>();

        private void btnUcitaj_Click(object sender, EventArgs e)
        {
            string stringPocetnaTocka = txtPocetnaTocka.Text;
            string stringVektorPomaka = txtVektorPomaka.Text;
            string stringVektorPreciznosti = txtVektorPreciznosti.Text;

            pocetnaTocka = KreirajListuBrojevaIzTeksta(stringPocetnaTocka);
            vektorPomaka = KreirajListuBrojevaIzTeksta(stringVektorPomaka);
            vektorPreciznosti = KreirajListuBrojevaIzTeksta(stringVektorPreciznosti);

            if (pocetnaTocka.Count == 0 || vektorPomaka.Count == 0 || vektorPreciznosti.Count == 0)
            {
                MessageBox.Show("Neispravni učitani parametri!");
                btnPokreni.Enabled = false;
                return;
            }
            if ((pocetnaTocka.Count != vektorPomaka.Count) || (vektorPomaka.Count != vektorPreciznosti.Count))
            {
                MessageBox.Show("Neispravni učitani parametri!");
                btnPokreni.Enabled = false;
                return;
            }
            btnPokreni.Enabled = true;
            
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

        private void btnPokreni_Click(object sender, EventArgs e)
        {
            txtPrikaz.Text = "";
            HookeJeeves HJ = new HookeJeeves(pocetnaTocka, vektorPomaka, vektorPreciznosti);
            int rbr=1;
            List<double> lista = new List<double>();
            if (rb1.Checked == true)
                rbr = 1;
            if (rb2.Checked == true)
                rbr = 2;
            if (rb3.Checked == true)
            {
                rbr = 3;
                lista = KreirajListuBrojevaIzTeksta(txtPx.Text);
            }

            if (rb4.Checked == true)
                rbr = 4;          
            if (rb5.Checked == true)
                rbr = 5;
            try
            {
                switch (rbr)
                {
                    case 1:
                    case 2:
                    case 4:
                    case 5:
                        HJ.PokreniAlgoritam(rbr, txtPrikaz);
                        break;
                    case 3:
                        HJ.PokreniAlgoritam(rbr, lista, txtPrikaz);
                        break;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message + Environment.NewLine + ex.Source);
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            rb5.Text = HookeJeeves.korisnickaFunkcija;
        }

    }
}

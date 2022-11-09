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
    public partial class frmB : Form
    {
        public frmB()
        {
            InitializeComponent();
        }

        List<double> pocetnaTocka;
        double koeficijentRefleksije;
        double preciznost;

        private void btnUcitaj_Click(object sender, EventArgs e)
        {
            string stringPocetnaTocka = txtPocetnaTocka.Text;
            string stringKoeficijentRefleksije = txtKoeficijentRefleksije.Text;
            string stringPreciznost = txtPreciznost.Text;

            pocetnaTocka = KreirajListuBrojevaIzTeksta(stringPocetnaTocka);
            koeficijentRefleksije = double.Parse(stringKoeficijentRefleksije);
            preciznost = double.Parse(stringPreciznost);

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
            Box B = new Box(pocetnaTocka, koeficijentRefleksije, preciznost);
            int rbr = 1;
            List<double> lista = new List<double>();
            if (rb1.Checked == true)
                rbr = 1;
            if (rb2.Checked == true)
            {
                rbr = 2;
                lista = KreirajListuBrojevaIzTeksta(txtPx.Text);
            }

            try
            {
                switch (rbr)
                {
                    case 1:
                        B.PokreniAlgoritam(rbr, txtPrikaz);
                        break;
                    case 2:
                        B.PokreniAlgoritam(rbr, lista, txtPrikaz);
                        break;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message + Environment.NewLine + ex.Source);
            }
        }
    }
}

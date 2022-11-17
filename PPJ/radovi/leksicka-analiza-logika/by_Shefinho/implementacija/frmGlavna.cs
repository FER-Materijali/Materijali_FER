using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Text.RegularExpressions;

namespace SSP_PPJ_62
{
    public partial class frmGlavna : Form
    {
        /// <summary>
        /// Konstruktor forme
        /// </summary>
        public frmGlavna()
        {
            InitializeComponent();
            //event handleri za pritisak na tipku na tipkovinici i klik miša; 
            //koriste se za ispis pozicije kursora u polju za unos teksta (tbUnos)
            tbUnos.KeyUp += new KeyEventHandler(tbUnos_KeyUp);
            tbUnos.MouseClick += new MouseEventHandler(tbUnos_MouseClick);
            //primjeri ulaznih podataka potrebnih za pokretanje programa:
            tbUnos.Text = "~(t+f*t)+(~f*t)";
        }

        void tbUnos_MouseClick(object sender, MouseEventArgs e)
        {
            KursorUpadate();
        }

        void tbUnos_KeyUp(object sender, KeyEventArgs e)
        {
            KursorUpadate();
        }

        /// <summary>
        /// Ispisuje trenutnu poziciju kursora u polju za unos teksta (tbUnos)
        /// </summary>
        private void KursorUpadate()
        {
            int pozicija = tbUnos.SelectionStart;
            int i = 0, n = 1;
            if (pozicija != 0)
            {
                foreach (char c in tbUnos.Text)
                {
                    i++;
                    if (c == '\n') n++;
                    if (i == pozicija) break;
                }
            }
            lbKursor.Text = "Položaj kursora: linija " + n.ToString();
        }

        private void btnInfo_Click(object sender, EventArgs e)
        {
            MessageBox.Show(
            "SSP, teža inačica" + Environment.NewLine +
            "Autor: Shefinho" + Environment.NewLine +
            "Siječanj 2009.",
            "62. zadatak, PPJ");
        }

        /// <summary>
        /// Pokreće rad jezičnog procesora
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnKreni_Click(object sender, EventArgs e)
        {
            tbIzlaz.Text = "";
            string[] izrazi = Regex.Split(tbUnos.Text, "\r\n");
            int i = 1;
            
            foreach (string izraz in izrazi)
            {
                string buffer = izraz.Replace(" ", "");
                buffer = buffer.Replace("\t", "");
                buffer = buffer.Replace("f", "F");
                buffer = buffer.Replace("t", "T");
                
                if (buffer != "")
                {
                    tbIzlaz.Text += "Linija " + i.ToString() + ":\r\n";
                    LeksickiAnalizator la = new LeksickiAnalizator(buffer);
                    if (la.Analiziraj())
                    {
                        tbIzlaz.Text += "Leksika OK.\r\n";
                        SintaksniAnalizator sa = new SintaksniAnalizator(buffer);
                        if (sa.Analiziraj())
                        {
                            tbIzlaz.Text += "Sintaksa OK.\r\n";
                            GeneratorTroadrMedjukoda gtm = new GeneratorTroadrMedjukoda(sa.getSintaksnoStablo());
                            if (checkBox1.Checked) tbIzlaz.Text += "\r\nAtributno sintaskno stablo:\r\n" + sa.Ispisi();
                            if (checkBox2.Checked) tbIzlaz.Text += "\r\nNiz semantičkih akcija:\r\n" + gtm.IspisiNizSemantickihAkcija();
                            if (checkBox3.Checked) tbIzlaz.Text += "\r\nNiz pomaknutih semantičkih akcija:\r\n" + gtm.IspisiNizSemantickihAkcija2();
                            tbIzlaz.Text += "\r\nKod:\r\n" + gtm.getKod();
                        }
                        else tbIzlaz.Text += "Sintaksna greška.";
                    }
                    else tbIzlaz.Text += "Leksička greška";
                    tbIzlaz.Text += "\r\n\r\n";
                }
                i++;
            }
        }
    }
}

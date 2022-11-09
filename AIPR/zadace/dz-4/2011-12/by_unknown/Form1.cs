using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace APR___lab4
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Matrica A = new Matrica(2, 2);
            A.NapuniMatricu(new double[] { 1, 1, 1, 1});
            Matrica inverz = null;
            try
            {
                inverz = A.VratiInverz();
                tbEkran.Text = inverz.ToFormatString();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            Matrica A = Matrica.UcitajIzDatoteke(tbA.Text);
            Matrica B = Matrica.UcitajIzDatoteke(tbB.Text);
            Matrica X = Matrica.UcitajIzDatoteke(tbX.Text);
            double T = double.Parse(tbT.Text);
            double I = double.Parse(tbI.Text);
            int korakIspisa = int.Parse(tbIspis.Text);


            if (rbRungeKutta.Checked)
            {
                RungeKutta rungeKuttaPostupak = new RungeKutta(A, B, X, T, I, korakIspisa, tbEkran);
                rungeKuttaPostupak.PokreniAlgoritam();
            }
            else
            {
                TrapezniPostupak trapezniPostupak = new TrapezniPostupak(A, B, X, T, I, korakIspisa, tbEkran);
                trapezniPostupak.PokreniAlgoritam();
            }

            // MATLAB POSAO
            try
            {
                Matlab.KreirajMatlabDatoteku(Matrica.UcitajIzDatoteke(tbA.Text), Matrica.UcitajIzDatoteke(tbX.Text), double.Parse(tbI.Text), "MatlabOde23.m");
            }
            catch
            {
                MessageBox.Show("Pogrešan unos parametara.");
            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            
        }

        private void label7_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Uskršnje jajce :)  11.1.2012.", "Maxur");
        }
    }
}

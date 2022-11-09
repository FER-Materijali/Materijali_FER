using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace APR___lab2
{
    public partial class frmMain : Form
    {
        public frmMain()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            frmHJ form = new frmHJ();
            form.ShowDialog();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            frmB form = new frmB();
            form.ShowDialog();
        }

        private void label1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Uskršnje jajce :)   10.1.2012.", "Maxur");
        }
    }
}

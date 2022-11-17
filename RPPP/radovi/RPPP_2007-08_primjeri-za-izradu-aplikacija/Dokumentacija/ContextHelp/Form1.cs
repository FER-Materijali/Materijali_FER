using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace ContextHelp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void ZbrojiButton_Click(object sender, EventArgs e)
        {
            ZbrojLabel.Text = ((double)(numericUpDown1.Value + numericUpDown2.Value)).ToString();
        }
    }
}
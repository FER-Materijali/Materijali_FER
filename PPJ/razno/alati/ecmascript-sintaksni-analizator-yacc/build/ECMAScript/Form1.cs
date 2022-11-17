using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace ListCollection
{
    public partial class Forma : Form
    {
        public Forma()
        {
            InitializeComponent();
        }

        

        private void datotekaToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // Create an Open File dialog box  
            OpenFileDialog openfile = new OpenFileDialog();
            // Set up filters and options
            openfile.Filter = "All Files (*.*)|*.*";
            // Check result of dialog box after it closes
            if (openfile.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                // Read in ANSI characters to edit buffer
                editbox.Text = File.ReadAllText(openfile.FileName);
                
            }

        }

        public Scanner mojSkener;

        private void Analiziraj_gumb_Click(object sender, EventArgs e)
        {
            editbox.Enabled = false;
            Glavni.mojaForma.OutputBox.Text = "";
            KROSdataGrid.Rows.Clear();
            KonstDataGrid.Rows.Clear();
            IdentDataGrid.Rows.Clear();
            UZdataGrid.Rows.Clear();
            mojSkener = new Scanner();
            mojSkener.Analiziraj();
            if(Glavni.mojaForma.OutputBox.Text == "")
                Glavni.mojaForma.OutputBox.Text = Glavni.mojaForma.OutputBox.Text + "Program uspjesno analiziran bez greske!" + Environment.NewLine;
            editbox.Enabled = true;
            
        }

        
    }
}

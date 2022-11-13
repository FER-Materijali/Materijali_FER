using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Diagnostics;


namespace AVLtree
{
    public partial class Sucelje : Form
    {
        public static int width;
        public Sucelje()
        {
            InitializeComponent();
            Algoritmi.graphicsObj = drawPanel.CreateGraphics();
            width = drawPanel.Width;
        }
        #region Button Click
        private void openFileBtn_Click(object sender, EventArgs e)
        {
            OpenFileDialog open = new OpenFileDialog();
            open.CheckFileExists = true;
            if (open.ShowDialog() == DialogResult.OK)
            {
                Algoritmi.UcitajDatoteku(open.FileName);
                Algoritmi.CrtajSve(Algoritmi.root, 1, 50, drawPanel.Width / 2);
                
            }
        }

        private void addBtn_Click(object sender, EventArgs e)
        {
            if (nodeBox.Text.Length != 0)
            {
                Stopwatch sw = new Stopwatch();
                sw.Start();
                Algoritmi.root = Algoritmi.DodajCvor(Algoritmi.root, Convert.ToInt32(nodeBox.Text));
                Algoritmi.PostaviVisine(Algoritmi.tmpCvor);
                sw.Stop();
                timeLabel.Text = sw.ElapsedMilliseconds.ToString() + " ms";
                Algoritmi.graphicsObj.Clear(Color.DimGray);
                Algoritmi.CrtajSve(Algoritmi.root, 1, 50, drawPanel.Width / 2);                
            }
            nodeBox.Text = "";
        }

        private void deleteBtn_Click(object sender, EventArgs e)
        {
            if (delBox.Text.Length != 0)
            {
                Stopwatch sw = new Stopwatch();
                sw.Start();
                Algoritmi.IzbrisiCvor(Convert.ToInt32(delBox.Text));
                sw.Stop();
                timeLabel.Text = sw.ElapsedMilliseconds.ToString() + " ms";
                Algoritmi.graphicsObj.Clear(Color.DimGray);
                Algoritmi.CrtajSve(Algoritmi.root, 1, 50, drawPanel.Width / 2);
            }
            delBox.Text = "";
        }

        private void findBtn_Click(object sender, EventArgs e)
        {
            Stopwatch sw = new Stopwatch();
            sw.Start();
            Cvor found = Algoritmi.NadjiCvor(Convert.ToInt32(findBox.Text));
            sw.Stop();
            timeLabel.Text = sw.ElapsedMilliseconds.ToString() + " ms";
            Algoritmi.graphicsObj.Clear(Color.DimGray);
            Algoritmi.CrtajSve(Algoritmi.root, 1, 50, drawPanel.Width / 2);
            found.Graf.CrtajCvor(false);
            findBox.Text = "";
        }

        private void clearBtn_Click(object sender, EventArgs e)
        {
            Algoritmi.graphicsObj.Clear(Color.DimGray);
            Algoritmi.root = null;
            timeLabel.Text = "0";
        }
        #endregion

        #region Trigger events
        private void nodeBox_Validating(object sender, CancelEventArgs e)
        {
            var izBoxa = nodeBox.Text;
            int broj;
            
            if (izBoxa.Length != 0 && !int.TryParse(izBoxa, out broj))
            {
                if (broj < 0)
                {
                    e.Cancel = true;
                    errorProvider1.SetError(nodeBox, "Upisani broj nije iz skupa prirodnih brojeva!");
                }
                else
                {
                    e.Cancel = true;
                    errorProvider1.SetError(nodeBox, "Upisana vrijednost nije broj");
                }
            }
            else
            {
                errorProvider1.Clear();
            }
        }

        private void textBox1_Validating(object sender, CancelEventArgs e)
        {
            var izBoxa = delBox.Text;
            int broj;

            if (izBoxa.Length != 0 && !int.TryParse(izBoxa, out broj))
            {
                if (broj < 0)
                {
                    e.Cancel = true;
                    errorProvider1.SetError(nodeBox, "Upisani broj nije iz skupa prirodnih brojeva!");
                }
                else
                {
                    e.Cancel = true;
                    errorProvider1.SetError(delBox, "Upisana vrijednost nije broj");
                }
            }
            else
            {
                errorProvider1.Clear();
            }
        }

        private void findBox_Validating(object sender, CancelEventArgs e)
        {
            var izBoxa = findBox.Text;
            int broj;

            if (izBoxa.Length != 0 && !int.TryParse(izBoxa, out broj))
            {
                if (broj < 0)
                {
                    e.Cancel = true;
                    errorProvider1.SetError(nodeBox, "Upisani broj nije iz skupa prirodnih brojeva!");
                }
                else
                {
                    e.Cancel = true;
                    errorProvider1.SetError(delBox, "Upisana vrijednost nije broj");
                }
            }
            else
            {
                errorProvider1.Clear();
            }

        }

        private void drawPanel_Paint(object sender, PaintEventArgs e)
        {
            Algoritmi.graphicsObj.Clear(Color.DimGray);
            Algoritmi.CrtajSve(Algoritmi.root, 1, 50, drawPanel.Width / 2);

        }
        
        #endregion

    }
}

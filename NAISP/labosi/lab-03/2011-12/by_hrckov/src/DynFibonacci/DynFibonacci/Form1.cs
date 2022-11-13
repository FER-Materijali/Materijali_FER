using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Diagnostics;

namespace DynFibonacci
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            selectedrb = radioButton1;
            radioButton1.Checked = true;
        }
                
        private void button1_Click(object sender, EventArgs e)
        {
            int n = 0;
            int.TryParse(textBox1.Text, out n);
            double fibn = 0;
            tmpList = new List<double>();
            tmpList.Add(0);
            tmpList.Add(1);
            Stopwatch sw = new Stopwatch();
            sw.Start();
            if (selectedrb == radioButton1)
            {
                fibn = fibMathDef(n);
            }
            else if (selectedrb == radioButton2)
            {
                fibn = fibTopDown(n);
            }
            else if (selectedrb == radioButton3)
            {
                fibn = fibBottomUp(n);
            }
            sw.Stop();
           
            label1.Text = "fib(" + n.ToString() + ") = " + fibn.ToString();
            timeLabel.Text = "Elapsed time = " + sw.Elapsed.ToString() + "ms";             
        }

        private double fibMathDef(int n)
        {
            if (n == 0)
            {
                return 0;
            }
            if (n == 1)
            {
                return 1;
            }
            return fibMathDef(n - 1) + fibMathDef(n - 2);
        }

        List<double> tmpList;
        private double fibTopDown(int n)
        {
            if (tmpList.Count - 1 < n)
            {
                tmpList.Add(fibTopDown(n - 1) + fibTopDown(n - 2));
            }
            return tmpList[n];
        }

        private double fibBottomUp(int n)
        {
            double prevFib = 0;
            double curFib = 1;
            if (n == 0)
            {
                return 0;
            }

            for (int i = 0; i < (n - 1); i++)
            {
                double newFib = prevFib + curFib;
                prevFib = curFib;
                curFib = newFib;                
            }
            return curFib;
        }

        private void textBox1_Validating(object sender, CancelEventArgs e)
        {            
            var izBoxa = textBox1.Text;
            double broj;
            
            if (izBoxa.Length != 0 && !double.TryParse(izBoxa, out broj))
            {
                if (broj < 0)
                {
                    e.Cancel = true;
                    errorProvider1.SetError(textBox1, "Upisani broj nije iz skupa prirodnih brojeva!");
                }
                else
                {
                    e.Cancel = true;
                    errorProvider1.SetError(textBox1, "Upisana vrijednost nije broj");
                }
            }
            else
            {
                if (izBoxa.Length != 0)
                {
                    broj = Convert.ToInt64(izBoxa);
                    if (broj > 1476)
                    {
                        e.Cancel = true;
                        errorProvider1.SetError(textBox1, "Upisani broj je veci od 1476!");
                    }
                    else
                    {
                        errorProvider1.Clear();
                    }
                }
            }
           
        }

        RadioButton selectedrb;
        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            RadioButton rb = sender as RadioButton;

            if (rb == null)
            {
                MessageBox.Show("Sender is not a RadioButton");
                return;
            }

            if (rb.Checked)
            {
                selectedrb = rb;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}

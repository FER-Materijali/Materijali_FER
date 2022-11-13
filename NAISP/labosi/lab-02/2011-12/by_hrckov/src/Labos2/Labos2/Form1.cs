using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Labos2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            listView1.Columns.Add("Generacija", 20);
            for (int i = 0; i < velicinaGeneracije; i++)
            {
                listView1.Columns.Add("Jedinka " + (i + 1).ToString(), 250);
            }
        }

        int brojGeneracija = 10;
        int velicinaGeneracije = 10;

        Dictionary<int, Kromosom> kromosomi;
        System.Diagnostics.Stopwatch sw;

        private void button1_Click(object sender, EventArgs e)
        {
            sw = new System.Diagnostics.Stopwatch();
            sw.Start();
            Kromosom.duljina = Convert.ToInt32(textBox1.Text);
            Kromosom.preciznost = Convert.ToInt32(textBox2.Text);
            Kromosom.MutateP = Convert.ToInt32(textBox3.Text);
            velicinaGeneracije = Convert.ToInt32(textBox4.Text);
            brojGeneracija = Convert.ToInt32(textBox5.Text);
            int faktorMutacije = Convert.ToInt32(textBox6.Text);
            listView1.Items.Clear();
            kromosomi = new Dictionary<int,Kromosom>();
            for (int i = 0; i < velicinaGeneracije; i++)
            {
                Kromosom.MutateP += 1 * faktorMutacije; ;
                Kromosom kromosom = new Kromosom();
                kromosom.Init();
                while(kromosomi.ContainsKey(kromosom.Dobrota))
                {
                    kromosom.Init();                    
                }
                kromosomi.Add(kromosom.Dobrota, kromosom);
            }
            evolution();
            sw.Stop();
            label10.Text ="t = " +  ((double)sw.ElapsedMilliseconds/1000).ToString() + " sec";
            Kromosom max = kromosomi[kromosomi.Keys.Max()];
            label1.Text = "x = " + max.X.ToString();
            label2.Text = "y = " + max.Y.ToString();
            label3.Text = "z = " + ((double)max.Dobrota / 10000000).ToString();

        }

        private void evolution()
        {
            int maxTrajanje = Convert.ToInt32(textBox7.Text) * 1000;
            Random rand = new Random();
            for (int i = 0; i < brojGeneracija; i++)
            {
                Dictionary<int, Kromosom> sorted = (from krom in kromosomi orderby krom.Key ascending select krom).ToDictionary(pair => pair.Key, pair => pair.Value);
                Dictionary<int, Kromosom> tmp = new Dictionary<int, Kromosom>();
                int lowValue = 1;
                int totalValue = 0;
                foreach (var nes in sorted)
                {
                    totalValue += lowValue;
                    tmp.Add(totalValue, nes.Value);
                    lowValue += 1;
                }
                Kromosom najbolji = sorted.Last().Value;
                sorted = new Dictionary<int, Kromosom>();
                sorted.Add(najbolji.Dobrota, najbolji);
                while(sorted.Count!=velicinaGeneracije)
                {
                    int rand1;
                    int rand2;
                    do
                    {
                        rand1 = rand.Next(0, totalValue);
                        rand2 = rand.Next(0, totalValue);
                    }
                    while (rand1 == rand2);
                    Kromosom k1=null;
                    Kromosom k2=null;
                    foreach (var nes in tmp)
                    {
                        if (nes.Key > rand1 && k1==null)
                        {
                            k1 = nes.Value;
                        }
                        if (nes.Key > rand2 && k2==null)
                        {
                            k2 = nes.Value;
                        }
                    }                    
                    Tuple<Kromosom, Kromosom> tmpKromi = Kromosom.Krizaj(k1, k2);
                    try
                    {
                        sorted.Add(tmpKromi.Item1.Dobrota, tmpKromi.Item1);
                        if (sorted.Count == velicinaGeneracije)
                        {
                            break;
                        }
                    }
                    catch { }
                    try
                    {
                        sorted.Add(tmpKromi.Item2.Dobrota, tmpKromi.Item2);
                        if (sorted.Count == velicinaGeneracije)
                        {
                            break;
                        }
                    }
                    catch { }
                    if (sw.ElapsedMilliseconds > maxTrajanje && maxTrajanje!=0)
                    {
                        return;   
                    }
                    
                }
                ListViewItem red = new ListViewItem();
                red.Text = i.ToString();
                foreach (var nes in kromosomi)
                {
                    red.SubItems.Add("x=" + nes.Value.X.ToString() + ", y=" + nes.Value.Y.ToString() + ", z=" + nes.Value.Z.ToString());
                }
                listView1.Items.Add(red);
                kromosomi = sorted;

                
            }
        }

        #region validacije
        private void textBox1_Validating(object sender, CancelEventArgs e)
        {
            var izBoxa = textBox1.Text;
            int broj;

            if (izBoxa.Length != 0 && !int.TryParse(izBoxa, out broj))
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
                errorProvider1.Clear();
            }
        }

        private void textBox2_Validating(object sender, CancelEventArgs e)
        {
            var izBoxa = textBox2.Text;
            int broj;

            if (izBoxa.Length != 0 && !int.TryParse(izBoxa, out broj))
            {
                if (broj < 0)
                {
                    e.Cancel = true;
                    errorProvider1.SetError(textBox2, "Upisani broj nije iz skupa prirodnih brojeva!");
                }
                else
                {
                    e.Cancel = true;
                    errorProvider1.SetError(textBox2, "Upisana vrijednost nije broj");
                }
            }
            else
            {
                errorProvider1.Clear();
            }
        }

        private void textBox3_Validating(object sender, CancelEventArgs e)
        {
            var izBoxa = textBox3.Text;
            int broj;

            if (izBoxa.Length != 0 && !int.TryParse(izBoxa, out broj))
            {
                if (broj < 0)
                {
                    e.Cancel = true;
                    errorProvider1.SetError(textBox3, "Upisani broj nije iz skupa prirodnih brojeva!");
                }
                else
                {
                    e.Cancel = true;
                    errorProvider1.SetError(textBox3, "Upisana vrijednost nije broj");
                }
            }
            else
            {
                errorProvider1.Clear();
            }
        }

        private void textBox4_Validating(object sender, CancelEventArgs e)
        {
            var izBoxa = textBox4.Text;
            int broj;

            if (izBoxa.Length != 0 && !int.TryParse(izBoxa, out broj))
            {
                if (broj < 0)
                {
                    e.Cancel = true;
                    errorProvider1.SetError(textBox4, "Upisani broj nije iz skupa prirodnih brojeva!");
                }
                else
                {
                    e.Cancel = true;
                    errorProvider1.SetError(textBox4, "Upisana vrijednost nije broj");
                }
            }
            else
            {
                errorProvider1.Clear();
            }
        }

        private void textBox5_Validating(object sender, CancelEventArgs e)
        {
            var izBoxa = textBox5.Text;
            int broj;

            if (izBoxa.Length != 0 && !int.TryParse(izBoxa, out broj))
            {
                if (broj < 0)
                {
                    e.Cancel = true;
                    errorProvider1.SetError(textBox5, "Upisani broj nije iz skupa prirodnih brojeva!");
                }
                else
                {
                    e.Cancel = true;
                    errorProvider1.SetError(textBox5, "Upisana vrijednost nije broj");
                }
            }
            else
            {
                errorProvider1.Clear();
            }
        }

        private void textBox6_Validating(object sender, CancelEventArgs e)
        {
            var izBoxa = textBox5.Text;
            int broj;

            if (izBoxa.Length != 0 && !int.TryParse(izBoxa, out broj))
            {
                if (broj < 0)
                {
                    e.Cancel = true;
                    errorProvider1.SetError(textBox5, "Upisani broj nije iz skupa prirodnih brojeva!");
                }
                else
                {
                    e.Cancel = true;
                    errorProvider1.SetError(textBox5, "Upisana vrijednost nije broj");
                }
            }
            else
            {
                errorProvider1.Clear();
            }
        }

        private void textBox7_Validating(object sender, CancelEventArgs e)
        {
            var izBoxa = textBox5.Text;
            int broj;

            if (izBoxa.Length != 0 && !int.TryParse(izBoxa, out broj))
            {
                if (broj < 0)
                {
                    e.Cancel = true;
                    errorProvider1.SetError(textBox5, "Upisani broj nije iz skupa prirodnih brojeva!");
                }
                else
                {
                    e.Cancel = true;
                    errorProvider1.SetError(textBox5, "Upisana vrijednost nije broj");
                }
            }
            else
            {
                errorProvider1.Clear();
            }
        }
        #endregion
    }
}

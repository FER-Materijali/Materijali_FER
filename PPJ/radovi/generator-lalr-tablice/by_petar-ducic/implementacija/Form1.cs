using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace SSP
{
    public partial class Form1 : Form
    {
            public Form1()
        {
            InitializeComponent();
            this.Controls.Add(Tablica);
        }
           
        private void button1_Click(object sender, EventArgs e)  //pritiskom na tipku pozivaju se sve funkcije potrebne
        {
            
            if(Glavni.zastava101)//ako je vec generirana tablica, pritiskom na t izlazi iz programa
                Close();
            else if (zapoc && prod && oznaceno)//ako su ucitane produkcije i zapocinje i oznacena vrsta parsera, kreće na posao
            {
                Glavni.Produkcije_u_stavke();
                Glavni.napraviPrijelaze();
                Glavni.Napravi_DKA();
                Glavni.zastava101 = true;
                textBox1.Text = "Uspješno obavljeno";
                if (LALR) label2.Show();
                else label3.Show();
                this.AutoSize = true;
                button1.Text = "Izađi";
                openToolStripMenuItem.Enabled = false;
              
            }
            else textBox1.Text = "Potražite 'Pomoć'";
            
        }


      

        public static TableLayoutPanel Tablica = new TableLayoutPanel();//tablica koja se generira ovisno o broju redaka/stupaca

        public static void NapraviTablicu()
        {
            List<Label> Labela=new List<Label>();//lista labela, kojjima se puni tablica.
            Tablica.CellBorderStyle = TableLayoutPanelCellBorderStyle.Single;
            Tablica.ColumnCount = Glavni.NEZAVRSNI.Count + Glavni.ZAVRSNI.Count + 1;
            Tablica.RowCount = 1+Glavni.STANJA.Count;
            int redaka = Tablica.RowCount;
            int stupaca = Tablica.ColumnCount;
            Tablica.BringToFront();
            Tablica.Padding = new System.Windows.Forms.Padding(0,0,0,0);
            Tablica.Location = new Point(238, 48);
            Tablica.AutoSize = true;
           

            int i = 0,j = 0;

            
                        
            for (j = 0; j < Tablica.RowCount; j++)
            {
                for (i = 0; i < Tablica.ColumnCount; i++)//popunjavanje tablice ovisno o mjestu
                {
                    Labela.Add(new Label());
                    if (i == 0 && j == 0)
                    {
                        Labela[j * stupaca + i].Text = "STANJE";
                        Tablica.Controls.Add(Labela[j * stupaca + i], i, j);
                    }
                    else if (i > 0 && i < (Glavni.ZAVRSNI.Count + 1) && j == 0)
                    {
                        Labela[j * stupaca + i].Text = "AKCIJA(" + Glavni.ZAVRSNI[i - 1] + ")";
                        Tablica.Controls.Add(Labela[j * stupaca + i], i, j);
                    }
                    else if (i > (Glavni.ZAVRSNI.Count) && i < (Glavni.ZAVRSNI.Count + 1 + Glavni.NEZAVRSNI.Count) && j == 0)
                    {
                        Labela[j * stupaca + i].Text = "NOVO STANJE("+Glavni.NEZAVRSNI[i - 1 - Glavni.ZAVRSNI.Count]+")";
                        Tablica.Controls.Add(Labela[j * stupaca + i],i,j);
                    }
                    else if (i == 0 && j > 0)
                    {
                        Labela[j * stupaca + i].Text = "[" + Glavni.STANJA[j - 1]+"]";
                        Tablica.Controls.Add(Labela[j * stupaca + i], i, j);
                    }
                    else//za akcije reduciraj/prihvati(ukoliko je stanje pocetno)
                    {
                        for (int l = 0; l < Glavni.DKA.Count; l++)
                        {
                            if (Glavni.DKA[l].naziv[0].Equals(Glavni.STANJA[j - 1])&&Glavni.DKA[l].naziv.EndsWith("*"))
                            {
                                if (i > 0 && i < (Glavni.ZAVRSNI.Count + 1))
                                {
                                    if (Glavni.DKA[l].zavrsni.Contains(Glavni.ZAVRSNI[i - 1]))
                                    {
                                        if (Glavni.DKA[l].naziv[1].Equals(Glavni.poc))
                                        {
                                            Labela[j * stupaca + i].Text = "Prihvati ";
                                            Tablica.Controls.Add(Labela[j * stupaca + i], i, j);
                                        }
                                        else
                                        {
                                            Labela[j * stupaca + i].Text = "Reduciraj " + Glavni.DKA[l].naziv.Remove(Glavni.DKA[l].naziv.Length - 1).Substring(1);
                                            Tablica.Controls.Add(Labela[j * stupaca + i], i, j);
                                        }
                                    }
                                }
                            }
                        }
                        for (int l = 0; l < Glavni.PRIJELAZI3.Count; l++)
                        {
                            if (i > 0 && i < (Glavni.ZAVRSNI.Count + 1))
                            {
                                if (Glavni.PRIJELAZI3[l].stanje1[0].Equals(Glavni.STANJA[j - 1])
                                    && Glavni.PRIJELAZI3[l].prijelaz.Equals(Glavni.ZAVRSNI[i - 1]))
                                {
                                    Labela[j * stupaca + i].Text = "Pomakni " + Glavni.PRIJELAZI3[l].stanje2[0];
                                    Tablica.Controls.Add(Labela[j * stupaca + i], i, j);
                                }
                            }
                            else if (i > (Glavni.ZAVRSNI.Count) && i < (Glavni.ZAVRSNI.Count + 1 + Glavni.NEZAVRSNI.Count))
                            {
                                if (Glavni.PRIJELAZI3[l].stanje1[0].Equals(Glavni.STANJA[j - 1])
                                    && Glavni.PRIJELAZI3[l].prijelaz.Equals(Glavni.NEZAVRSNI[i - 1 - Glavni.ZAVRSNI.Count]))
                                {
                                    Labela[j * stupaca + i].Text = "Stavi " + Glavni.PRIJELAZI3[l].stanje2[0];
                                    Tablica.Controls.Add(Labela[j * stupaca + i], i, j);
                                }
                            }
                        }
                    }
                }
            }
            
        }
        
        public static string chosenFile = "";
        public static string zapocinje = "";
        public static bool zapoc = false, prod=false;
        

        private void produkcijeToolStripMenuItem1_Click(object sender, EventArgs e) //browse dijagram
        {
            openFD.InitialDirectory = "C";
            openFD.FileName = "";
            openFD.Title = "Otvori produkcije";
            openFD.Filter = "Text Files|*txt";
            if (openFD.ShowDialog() != DialogResult.Cancel)
            {

                chosenFile = openFD.FileName;
                prod = true;
            }
        }
        
      

       

        public static bool LALR = true;
        private static bool oznaceno = false;
      
        private void radioButton1_CheckedChanged(object sender, EventArgs e) //odabir LALR
        {
            if (radioButton1.Checked)
            {
                oznaceno = true;
                LALR = true;
                radioButton2.Checked = false;
            }
            else radioButton1.Checked = false;
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)//odabir kanonski
        {
            if (radioButton2.Checked)
            {
                oznaceno = true;
                radioButton2.Checked = true;
                LALR = false;
                radioButton1.Checked = false;
            }
            else radioButton2.Checked = false;
        
        }



        private void zAPOCINJESkupToolStripMenuItem_Click(object sender, EventArgs e)
        {
            openFD.InitialDirectory = "C";
            openFD.FileName = "";
            openFD.Title = "Otvori ZAPOČINJE skup";
            openFD.Filter = "Text Files|*txt";
            if (openFD.ShowDialog() != DialogResult.Cancel)
            {

                zapocinje = openFD.FileName;
                zapoc = true;

            }
        }

        private void pomoćToolStripMenuItem1_Click_1(object sender, EventArgs e)
        {

            if (!Glavni.zastava101) MessageBox.Show("Ovaj program generira tablicu LALR parsera za zadane produkcije i 'ZAPOčINJE' skupove."
                + "\nDa bi mogao početi raditi, potrebno je učitati .txt datoteke u kojima su upisane produkcije i 'ZAPOčINJE' skupovi\n i označiti želite li generirati tablicu LALR ili kanonskog parsera.");
            else MessageBox.Show("Nažalost, ovaj je program za jednokratnu upotrebu. Ukoliko želite generirati neku drugu tablicu, pokrenite program ispočetka.");
       
        }

        private void općenitoToolStripMenuItem1_Click_1(object sender, EventArgs e)
        {
            MessageBox.Show("Generator tablice LALR parsera\nSamostalni studentski projekt iz predmeta 'Prevođenje programskih jezika'\nAutor: Petar Dučić\nFakultet Elektrotehnike i Računarstva\n2008-2009, Zagreb, Hrvatska\nKontakt: petar.ducic@fer.hr");

        }

       


        

        
       

       
       

      
    
       

     
        
        
        

        
        

       

    


       


     
    }
}

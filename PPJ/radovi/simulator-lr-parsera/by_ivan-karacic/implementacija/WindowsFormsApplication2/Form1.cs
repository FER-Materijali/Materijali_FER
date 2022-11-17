using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace WindowsFormsApplication2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent(); 
        }

        class Parser
        {
            
            string[,] formiranaTablica = new string[30, 30];
            public string tablica = null; //ime datoteke iz koje čitamo prijelaze
            public string produkcija = null; //ime datoteke iz koje čitamo produkcije
            string[] redukcija = new string[30];//tablica redukcija
            Stack<string> stog = new Stack<string>();

            public void obradaUlaznogNiza(string ulazniNiz, TextBox textBoxAkcija, TextBox textBoxStanjeNaStogu)
            {
                string ispis = "";
                int trenutniZnak = 0;
                string stanje = "0";
                ulazniNiz += "!"; // oznaka kraja niza
                stog.Push("0"); //Stavljamo početno stanje
                while (trenutniZnak < ulazniNiz.Length)
                {

                    int stupac = 0;
                    int i = 0;
                    string akcija = "";
                    string redukcijaNaStog = "";
                    int brojZnakovaZaSkidanje = 0;
                    string zadanaRedukcija = "";
                    stupac = 0;

                    //Trazimo ulazni znak u Tablici
                    try
                    {
                        while (ulazniNiz[trenutniZnak].ToString().CompareTo(formiranaTablica[0, stupac]) != 0)
                            stupac++;
                    }
                    catch
                    {
                        textBoxAkcija.Text += "Niz se odbacuje!\r\n";
                        textBoxAkcija.Text += "Ucitani znak \"" + ulazniNiz[trenutniZnak] + "\" ne postoji u gramatici";
                        break;
                    }

                    //Gledamo koju akciju moramo obaviti
                    akcija = formiranaTablica[Convert.ToInt32(stanje) + 1, stupac];

                    if (akcija[0].CompareTo('p') == 0)
                    {
                        stog.Push(ulazniNiz[trenutniZnak].ToString());
                        try
                        {
                            stanje = akcija.Substring(1, akcija.Length - 1); //spremamo novo stanje
                        }
                        catch
                        {
                            textBoxAkcija.Text += "Niz se odbacuje!";
                            break;
                        }
                        stog.Push(stanje);
                        trenutniZnak++;
                        textBoxAkcija.Text += "Produkcija p" + stanje;
                        textBoxAkcija.Text += "\r\n";
                        foreach (string s in stog)
                            textBoxStanjeNaStogu.Text += s.ToString() + " | ";
                        textBoxStanjeNaStogu.Text += "\r\n";
                    }
                    if (akcija[0].CompareTo('r') == 0)
                    {
                        if (akcija.Substring(akcija.Length - 1, 1).ToString().CompareTo("P") != 0)
                        {
                            i = 0;
                            try
                            {
                                stanje = akcija.Substring(1, akcija.Length - 1);
                                zadanaRedukcija = redukcija[Convert.ToInt32(stanje) - 1];
                                if (zadanaRedukcija.CompareTo(null) == 0)
                                {
                                    textBoxAkcija.Text += "Niz se odbacuje!";
                                    textBoxAkcija.Text += "\r\n";
                                    textBoxAkcija.Text += "Greska s tablicama!";
                                    break;
                                }
                            }
                            catch
                            {
                                textBoxAkcija.Text += "Niz se odbacuje!";
                                textBoxAkcija.Text += "\r\n";
                                textBoxAkcija.Text += "Greska s tablicama!";
                                break;
                            }
                            if (zadanaRedukcija[0].CompareTo('<') == 0)
                                while (zadanaRedukcija[i].CompareTo('>') != 0)
                                {
                                    redukcijaNaStog += zadanaRedukcija[i];
                                    i++;
                                }
                            else
                            {
                                textBoxAkcija.Text += "Niz se odbacuje!\r\n";
                                textBoxAkcija.Text += "Moguce greske s tablicom";
                                break;
                            }
                            redukcijaNaStog += zadanaRedukcija[i];
                            i = 0;
                            while (i < zadanaRedukcija.Length)
                            {
                                if (zadanaRedukcija[i].CompareTo(',') == 0)
                                    brojZnakovaZaSkidanje++;
                                i++;
                            }
                            try
                            {
                                for (i = 0; i < brojZnakovaZaSkidanje * 2; i++)
                                    stog.Pop();
                            }
                            catch
                            {
                                textBoxAkcija.Text += "Niz se odbacuje!\r\n";
                                textBoxAkcija.Text += "Greska na stogu!";
                                break;
                            }
                            string novoStanjeNaStogu = stog.Peek();
                            stog.Push(redukcijaNaStog);
                            textBoxAkcija.Text += "Redukcija r" + stanje + "(" + zadanaRedukcija + ")";
                            textBoxAkcija.Text += "\r\n";

                            try
                            {
                                while (redukcijaNaStog.CompareTo(formiranaTablica[0, stupac]) != 0)
                                    stupac++;
                                akcija = formiranaTablica[Convert.ToInt32(novoStanjeNaStogu) + 1, stupac];
                                stanje = akcija.Substring(1, akcija.Length - 1); //spremamo novo stanje
                            }
                            catch
                            {
                                textBoxAkcija.Text += "Niz se odbacuje!";
                                break;
                            }
                            stog.Push(stanje);

                            foreach (string s in stog)
                                textBoxStanjeNaStogu.Text += s.ToString() + " | ";
                            textBoxStanjeNaStogu.Text += "\r\n";
                        }
                        else
                        {
                            i = 0;
                            try
                            {
                                stanje = akcija.Substring(1, akcija.Length - 2);
                                zadanaRedukcija = redukcija[Convert.ToInt32(stanje) - 1];
                                if (zadanaRedukcija.CompareTo(null) == 0)
                                {
                                    textBoxAkcija.Text += "Niz se odbacuje!";
                                    textBoxAkcija.Text += "\r\n";
                                    textBoxAkcija.Text += "Greska s tablicama!";
                                    break;
                                }
                            }
                            catch
                            {
                                textBoxAkcija.Text += "Niz se odbacuje!";
                                textBoxAkcija.Text += "\r\n";
                                textBoxAkcija.Text += "Greska s tablicama!";
                                break;
                            }
                            if (zadanaRedukcija[0].CompareTo('<') == 0)
                                while (zadanaRedukcija[i].CompareTo('>') != 0)
                                {
                                    redukcijaNaStog += zadanaRedukcija[i];
                                    i++;
                                }
                            else
                            {
                                textBoxAkcija.Text += "Niz se odbacuje!\r\n";
                                textBoxAkcija.Text += "Moguce greske s tablicom";
                                break;
                            }
                            redukcijaNaStog += zadanaRedukcija[i];
                            i = 0;
                            while (i < zadanaRedukcija.Length)
                            {
                                if (zadanaRedukcija[i].CompareTo(',') == 0)
                                    brojZnakovaZaSkidanje++;
                                i++;
                            }
                            try
                            {
                                for (i = 0; i < brojZnakovaZaSkidanje * 2; i++)
                                    stog.Pop();
                            }
                            catch
                            {
                                textBoxAkcija.Text += "Niz se odbacuje!\r\n";
                                textBoxAkcija.Text += "Greska na stogu!";
                                break;
                            }
                            string novoStanjeNaStogu = stog.Peek();
                            stog.Push(redukcijaNaStog);

                            textBoxAkcija.Text += "Redukcija r" + stanje + "(" + zadanaRedukcija + ")";
                            textBoxAkcija.Text += "\r\n";
                            foreach (string s in stog)
                                textBoxStanjeNaStogu.Text += s.ToString() + " | ";
                            textBoxStanjeNaStogu.Text += "\r\n";
                        }
                    }
                    if (akcija.ToString().CompareTo("P") == 0)
                    {
                        textBoxAkcija.Text += "Niz se prihvaca!";
                        break;
                    }
                    if (akcija.ToString().CompareTo("o") == 0)
                    {
                        textBoxAkcija.Text += "Niz se odbacuje!\r\n";
                        textBoxAkcija.Text += "Ne postoji akcija za znak \"" + ulazniNiz[trenutniZnak]+ "\"!";
                        break;
                    }
                    if (ulazniNiz[trenutniZnak].ToString().CompareTo("!") == 0 && stog.Peek().CompareTo("<S>") == 0)
                    {
                        textBoxAkcija.Text += "Niz se prihvaca!";
                        trenutniZnak++;
                    }
                }
            }

            #region Priprema
            public void UcitajTablice()
            {
                OpenFileDialog tablicaPrijelaza = new OpenFileDialog();
                tablicaPrijelaza.Title = "Unos tablice prijelaza";
                tablicaPrijelaza.Filter = ".txt file|*.txt";
                tablicaPrijelaza.InitialDirectory = Application.StartupPath;
                DialogResult result = tablicaPrijelaza.ShowDialog();
                if (result == System.Windows.Forms.DialogResult.OK)
                {
                    tablica = tablicaPrijelaza.FileName;
                }
                else if (result == System.Windows.Forms.DialogResult.Cancel)
                {
                    tablica = null;
                }
            }

            public void UcitajProdukcije()
            {
                OpenFileDialog tablicaProdukcija = new OpenFileDialog();
                tablicaProdukcija.Title = "Unos produkcija";
                tablicaProdukcija.Filter = ".txt file|*.txt";
                tablicaProdukcija.InitialDirectory = Application.StartupPath;
                DialogResult result = tablicaProdukcija.ShowDialog();
                if (result == System.Windows.Forms.DialogResult.OK)
                {
                    produkcija = tablicaProdukcija.FileName;
                }
                else if (result == System.Windows.Forms.DialogResult.Cancel)
                {
                    produkcija = null;
                }
            }

            public void stvoriDKA()
            {
                string line;
                char[] breaks = new char[1];
                breaks[0] = '\t';
                try
                {
                    using (StreamReader sr = new StreamReader(tablica))
                    {
                        int redak = 0;
                        while ((line = sr.ReadLine()) != null)
                        {
                            int stupac = 0;
                            foreach (string frag in line.Split(breaks))
                            {
                                if (frag.Length > 0)
                                {
                                    formiranaTablica[redak, stupac] = frag;
                                }
                                stupac++;
                            }
                            redak++;
                        }

                    }
                }
                catch
                {
                    MessageBox.Show("Greska kod tablice prijelaza");
                }
                try
                {
                    using (StreamReader sr = new StreamReader(produkcija))
                    {
                        int i = 0;
                        while ((line = sr.ReadLine()) != null)
                        {
                            redukcija[i] = line;
                            i++;
                        }
                    }
                }
                catch
                {
                    MessageBox.Show("Greska kod produkcja");
                }
            }
            #endregion
        }

        private void buttonParsiraj_Click_1(object sender, EventArgs e)
        {
            if (textBoxUlazniNiz.Text.Length > 0)
            {
                labelGreskaNiz.Text = "";
                textBoxAkcija.Clear();
                textBoxStanjeNaStogu.Clear();
                Parser parser = new Parser();
                parser.UcitajTablice();
                if (!(parser.tablica == null))
                    parser.UcitajProdukcije();
                    if (!(parser.produkcija == null))
                    {
                        parser.stvoriDKA();
                        parser.obradaUlaznogNiza(textBoxUlazniNiz.Text.ToString(), textBoxAkcija, textBoxStanjeNaStogu);
                    }
            }
            else
            {
                labelGreskaNiz.Text = "Niste unijeli ulazni niz!";
            }
        }
    }

}

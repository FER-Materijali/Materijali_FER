using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Text.RegularExpressions;
using System.Diagnostics;

namespace PPJ_SSP
{
    /*PPJ-SSP, teža inačica, 3.zadatak
    rookie, xxxx xxx xxx*/
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //otvaranje txt dokumenta - ulazne gramatike
            openFileDialog1.InitialDirectory = Environment.CurrentDirectory;
            openFileDialog1.FileName = "";
            openFileDialog1.Filter = "Text files|*.txt";
            if (openFileDialog1.ShowDialog(this) != DialogResult.OK) return;

            //ucitavanje produkcija iz txt dokumenta, brisanje svog teksta sa box-ova1 i 2 i onda ispis ulazne gramatike na box1
            FileInfo sourceFile = new FileInfo(openFileDialog1.FileName);
            StreamReader reader = sourceFile.OpenText();
            richTextBox1.Text = "";
            richTextBox2.Text = "";
            richTextBox1.Text = reader.ReadToEnd() + "\n";
            reader.Close();

            //promjena teksta na status bar-u
            string currentFileName = openFileDialog1.FileName;
            currentFileName = Regex.Replace(currentFileName, ".*\\\\", "");
            toolStripStatusLabel1.Text = "File " + currentFileName + " successfully opened.";

        }

        private void convertToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //brisanje svog teksta sa box-a2
            richTextBox2.Text = "";

            //provjera da li je ucitan dokument
            if (richTextBox1.Text == "")
            {
                MessageBox.Show("Open the text file first!", "No input grammar", MessageBoxButtons.OK, MessageBoxIcon.Information);
                openToolStripMenuItem_Click(null, null);
                return;
            }

            int i, j, n = 0;
            int br = 0;
            string[] prod = new string[150];
            string temp_znak;

            //ucitavanje svake produkcije iz txt dokumenta u svoj string
            FileInfo sourceFile = new FileInfo(openFileDialog1.FileName);
            StreamReader reader = sourceFile.OpenText();
            while (true)
            {
                prod[n] = reader.ReadLine();
                if (prod[n] == null || prod[n] == "") break;
                n++; //broj produkcija
            }

            if (richTextBox1.Find("Broj produkcija je: ", RichTextBoxFinds.NoHighlight) == -1) richTextBox1.Text += "\nBroj produkcija je: " + n + "\n";

            //razrješavanje izravno lijeve rekurzije
            for (i = 0; i < n; i++) //prolazi kroz sve ulazne produkcije
            {
                temp_znak = "z"; //temp_znak je inicijalno postavljen na random vrijednost završnog znaka("z"); produkcije ne započinju završnim znakovima                
                try
                {
                    temp_znak = prod[i].Substring(prod[i].IndexOf(">->") + 3, prod[i].IndexOf(">", prod[i].IndexOf(">->") + 3) + 1 - (prod[i].IndexOf(">->") + 3)); //nezavršni znak na krajnje lijevom mjestu na desnoj strani produckije ili niz znakova na tom mjestu,što provjeravamo u sljedečem if-u
                }
                catch { }

                if (prod[i][prod[i].IndexOf(">->") + 3].Equals('<') && (prod[i].StartsWith(temp_znak) || prod[i].StartsWith("*" + temp_znak))) //trazi rekurziju u određenoj produkciji; ukoliko iza strelice "->" slijedi "<",znaci da se u temp_znak nalazi nezavršni znak
                {
                    br++; //broj rekurzija
                    for (j = 0; j < n; j++) //ponovo prolazi kroz sve produkcije i primjenjuje algoritam za razrješenje te određene rekurzije
                    {
                        if (prod[j].StartsWith(temp_znak) || prod[j].StartsWith("*" + temp_znak)) //trazi produkcije koje započinju lijevo rekurzivnim nezavršnim znakom
                        {
                            if (prod[j].Substring(prod[j].IndexOf(">->") + 3).StartsWith(temp_znak))
                            {
                                if (prod[j].StartsWith("*"))
                                {
                                    prod[j] = "*<Ponovi" + br + ">->" + prod[j].Substring(prod[j].IndexOf(">", prod[j].IndexOf(">->") + 3) + 1) + "<Ponovi" + br + ">"; //zamjena produkcija poput *<A>-><A>αi
                                }
                                else prod[j] = "<Ponovi" + br + ">->" + prod[j].Substring(prod[j].IndexOf(">", prod[j].IndexOf(">->") + 3) + 1) + "<Ponovi" + br + ">"; //zamjena produkcija poput <A>-><A>αi
                            }
                            else
                            {
                                prod[j] = prod[j] + "<Ponovi" + br + ">"; //zamjena produkcija poput <A>->βj
                            }
                        }
                    }
                    prod[n] = "<Ponovi" + br + ">->" + "epsilon"; //dodavanje epsilon produkcije
                    n++; //broj produkcija se povečava za 1 zbog dodane epsilon produkcije
                }
            }
            toolStripStatusLabel1.Text = br + " left recursions eliminated, "; //poruka za status bar


            //zamjena nezavršnih znakova
            string[] pom = new string[150]; //pomoćno polje stringova
            int k = 0;
            br = 0;
            for (i = 0; i < n; i++) //prolazi kroz sve ulazne produkcije
            {
                if (prod[i].StartsWith("*")) //traži označene produkcije, u njima se vrši zamjena nezavršnih znakova
                {
                    br++; //broj nezavršnih znakova koji se zamjenjuju
                    prod[i] = prod[i].Remove(0, 1);
                    temp_znak = prod[i].Substring(prod[i].IndexOf(">->") + 3, prod[i].IndexOf(">", prod[i].IndexOf(">->") + 3) + 1 - (prod[i].IndexOf(">->") + 3)); //nezavršni znak koji čemo mijenjati na krajnje lijevom mjestu na desnoj strani produckije; sve produkcije označene zvjezdicom trebaju imati nezavršni znak na tom mjestu

                    for (j = 0; j < n; j++) //ponovo prolazi kroz sve produkcije, tako da se nezavršni znak zamijeni svim odgovarajućim desnim stranama produkcija
                    {
                        if (prod[j].StartsWith(temp_znak)) //traži odgovarajuće produkcije koje započinju traženim nezavršnim znakom
                        {
                            while (true) //ne izlazi se iz petlje dok se ne zapise produkcija u pomoćno polje
                            {
                                if (pom[k] == null || pom[k] == "") //za slaganje produkcija po nekom redoslijedu, ako je mjesto k u pomoćnom polju slobodno, zapisati produkciju na njega
                                {
                                    pom[k] = prod[i].Replace(temp_znak, prod[j].Substring(prod[j].IndexOf(">->") + 3)); //zapisati tako da se zamijeni nezavršni znak sa desnom stranom odgovarajuće produkcije
                                    k++; //mjesto k je sad popunjeno,zato k++
                                    break;
                                }
                                else
                                {
                                    k++; //ako mjesto k nije slobodno,k++
                                }
                            }
                        }
                    }
                }
                else //ako produkcija nije označena,samo se prepiše na sljedeće slobodno mjesto
                {
                    while (true)
                    {
                        if (pom[k] == null || pom[k] == "")
                        {
                            pom[k] = prod[i];
                            k++;
                            break;
                        }
                        else
                        {
                            k++;
                        }
                    }
                }
            }
            n = k; //novi broj produkcija
            prod = pom;
            toolStripStatusLabel1.Text += br + " left corners substituted "; //poruka za status bar


            //lijevo izlučivanje
            int max;
            int len;
            br = 0;
            for (i = 0; i < n; i++) //prolazi kroz sve ulazne produkcije
            {
                for (j = i + 1; j < n; j++)
                {
                    max = 0; //max je duljina podniza počevši od početka, koji prva i druga produkcija imaju jednak
                    len = prod[i].IndexOf(">->") + 3 + 1; //len je duljina podniza,početno ju postavljamo na duljinu koja obuhvaća lijevu stranu produkcije, strelicu "->" i prvi znak desne strane produkcije
                    while (true) //beskonačna petlja
                    {
                        if (string.Compare(prod[i], 0, prod[j], 0, len) == 0) //usporedba dvije produkcije, da li je imaju lijevu stranu i prvi znak desne strane jednak?
                        {
                            if (prod[i][len - 1] != '<')
                            {
                                max = len; //ako je lijeva strana i prvi znak desne strane jednak,i znak nije '<', tj.početak nezavršnog, onda je ovo nova max duljina
                                len++; //poveča se duljina podniza za 1,te se u sljedečem if-u uspoređuju lijeva strana produkcija i dva znaka desne strane itd.
                            }
                            else
                            {
                                len = prod[i].IndexOf(">", len - 1) + 1; //inače,duljini se doda duljina nezavršnog znaka,te se u sljedećem if-u uspoređuje lijeva strana i cijeli prvi nezavršni znak desne strane itd.
                            }
                        }
                        else break; //čim podniz dvije produkcije nije jednak,izlazimo iz petlje
                    }
                    if (max != 0) //ukoliko max nije 0, znači da dvije produkcije imaju barem jedan znak desne strane jednak, tj. jednak im je dio: <A>->α
                    {
                        br++; //broj različitih <Nastavak> znakova
                        if (prod[i].Substring(max).Length == 0) //ako iza podniza koji je jednak dvjema produkcijama ne slijedi ništa
                        {
                            prod[i] += "epsilon"; //dodamo epsilon na kraj
                        }
                        prod[n] = "<Nastavak" + br + ">->" + prod[i].Substring(max); //na kraj se doda nova produkcija <Nastavak>->β1
                        n++; //te se zbog toga ukupni broj produkcija poveća za 1
                        if (prod[j].Substring(max).Length == 0)
                        {
                            prod[j] += "epsilon";
                        }
                        prod[j] = "<Nastavak" + br + ">->" + prod[j].Substring(max); //produkcija se zamijeni zamijeni s <Nastavak>->β2
                        prod[i] = prod[i].Substring(0, max) + "<Nastavak" + br + ">"; //produkcija se zamijeni zamijeni s <A>->α<Nastavak>
                        for (k = j + 1; k < n; k++) //prolaženje kroz ostale produkcije
                        {
                            if (string.Compare(prod[i], 0, prod[k], 0, max) == 0) //traženje onih koje imaju jednak podniz točno iste duljine max kao i dvije produkcije kod kojih smo već obavili zamijenu; sprječava da se za sljedeću produkciju koja ima isti početni dio <A>->α poveća brojač za znak <Nastavak>
                            {
                                if (prod[k].Substring(max).Length == 0)
                                {
                                    prod[k] += "epsilon";
                                }
                                prod[k] = "<Nastavak" + br + ">->" + prod[k].Substring(max); ////produkcija se zamijeni zamijeni s <Nastavak>->βn
                            }
                        }
                    }
                }
            }
            toolStripStatusLabel1.Text += "and " + br + " left factorings transformed."; //poruka za status bar

            //ispis dobivene LL(1) gramatike po redu
            for (i = 0; i < n; i++)
            {
                if (!prod[i].StartsWith("<Ponovi") && !prod[i].StartsWith("<Nastavak")) richTextBox2.Text += prod[i] + "\n"; //prvo produkcije čija se lijeva strana nije mijenjala
            }
            for (j = 1; j < n; j++)
            {
                for (i = 0; i < n; i++)
                {
                    if (prod[i].StartsWith("<Ponovi" + j)) richTextBox2.Text += prod[i] + "\n"; //onda produkcije koje počinju znakovima <Ponovi1>, <Ponovi2> ...
                }
            }
            for (j = 1; j < n; j++)
            {
                for (i = 0; i < n; i++)
                {
                    if (prod[i].StartsWith("<Nastavak" + j)) richTextBox2.Text += prod[i] + "\n"; //i na kraju one koje počinju znakovima <Nastavak1>, <Nastavak2> ...
                }
            }

            richTextBox2.Text += "\nBroj produkcija je: " + n + "\n";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            convertToolStripMenuItem_Click(null, null);
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void helpToolStripMenuItem1_Click(object sender, EventArgs e)
        {
           try
            {
                Process.Start(Environment.CurrentDirectory + @"\PPJ-SSP-vs40782.pdf");
            }
            catch (Exception ex)
            {
                MessageBox.Show("Unable to open help!\n\nSystem message:\n" + ex.Message, "Error!");
            }
        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form About = new AboutBox1();
            About.ShowDialog(this);
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            openToolStripMenuItem_Click(null, null);
        }

        private void toolStripButton2_Click(object sender, EventArgs e)
        {
            convertToolStripMenuItem_Click(null, null);
        }

        private void toolStripButton3_Click(object sender, EventArgs e)
        {
            helpToolStripMenuItem1_Click(null, null);
        }

    }
}

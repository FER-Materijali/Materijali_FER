using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace SSP
{
    public partial class Form1 : Form
    {
        #region Privatne varijable klase
        List<SSP.Klase.Produkcija> produkcije = new List<SSP.Klase.Produkcija>();
        List<SSP.Klase.Znak> prazniNezavrsniZnakovi = new List<SSP.Klase.Znak>();
        List<SSP.Klase.Znak> sviZnakovi = new List<SSP.Klase.Znak>();
        #endregion

        /// <summary>
        /// Konstruktor forme, inicijalizira svoje varijeble
        /// </summary>
        public Form1()
        {
            InitializeComponent();
        }

        /// <summary>
        /// Ispuni TextBox produkcijama sa zadanog URL-a
        /// </summary>
        /// <param name="url">Url .txt datoteke u kojoj se nalazi gramatika</param>
        private void ispuniTextBoxProdukcije(string url)
        {
            if (url != null && url != "")
            {
                TextReader tr = new StreamReader(url);
                richTextBoxProdukcijeGramatike.Text = tr.ReadToEnd();
            }
        }
        /// <summary>
        /// Ispuni listu produkcija
        /// </summary>
        private void ispuniListuProdukcija()
        {
            produkcije.Clear();

            foreach (string produkcija in richTextBoxProdukcijeGramatike.Text.Split('\n'))
            {
                if (produkcija != "")
                {
                    produkcije.Add(new Klase.Produkcija(produkcija));
                }
            }
        }
        /// <summary>
        /// Ispuni listu Praznih znakova
        /// </summary>
        private void ispuniPrazneNezavrsneZnakove()
        {
            bool promjna = true;
            prazniNezavrsniZnakovi.Clear();

            List<SSP.Klase.Produkcija> pomocneProdukcije = new List<SSP.Klase.Produkcija>(produkcije);


            //Prvo stavljamo u listu praznih znakova sve epsilon produkcije
            for (int i = 0; i < pomocneProdukcije.Count; i++ )
            {
                //Produkcija je epsilon produkcija ako s desne strane imamo samo jendan znak i taj znak je epsilon
                if (pomocneProdukcije[i].desnaStranaProdukcije.Count == 1 && pomocneProdukcije[i].desnaStranaProdukcije[0].epsilon == true)
                {
                    prazniNezavrsniZnakovi.Add(pomocneProdukcije[i].lijevaStranaProdukcije);

                    pomocneProdukcije.Remove(pomocneProdukcije[i]);

                    i--;
                }
            }

            //Ako su svi znakovi desne strane produkcije u listi praznih znakova,
            //onda sse lista praznih nadopuni njezinom lijevom stranom. Algoritam se
            //nastavlja sve dok je moguce prosiriti listu praznih znakova novim
            // bezavrsnim znakom
            while (promjna)
            {
                promjna = false;
                bool sviPrazni;

                for (int i = 0; i < pomocneProdukcije.Count; i++)
                {
                    sviPrazni = true;

                    foreach (Klase.Znak y in pomocneProdukcije[i].desnaStranaProdukcije)
                    {
                        if (postojiLiPrazanZnakUListi(y) == false)
                        {
                            sviPrazni = false;
                        }
                    }

                    if (sviPrazni)
                    {
                        prazniNezavrsniZnakovi.Add(pomocneProdukcije[i].lijevaStranaProdukcije);

                        pomocneProdukcije.Remove(pomocneProdukcije[i]);

                        i--;
                    }
                }
            }
        }
        /// <summary>
        /// Ispuni listu svih znakova
        /// </summary>
        private void ispuniListuZnakova()
        {
            sviZnakovi.Clear();

            //Prolazi kroz sve produkcije i provjerava znakove u produkciji
            //Ako nisu u listi svih znakova stavi ih
            foreach (SSP.Klase.Produkcija produkcija in produkcije)
            {
                //Provjera znakova lijeve strane produkcije
                if (postojiLiZnakUListi(produkcija.lijevaStranaProdukcije) == false)
                {
                    sviZnakovi.Add(produkcija.lijevaStranaProdukcije);
                }

                //Provjera znakova desne strane produkcije
                foreach (SSP.Klase.Znak znak in produkcija.desnaStranaProdukcije)
                {
                    if (postojiLiZnakUListi(znak) == false && znak.epsilon == false)
                    {
                        sviZnakovi.Add(znak);
                    }
                }
            }

            SSP.Klase.ZnakComperer zc = new SSP.Klase.ZnakComperer();

            sviZnakovi.Sort(zc);
        }
        /// <summary>
        /// Inicjalizira tablicu Ispred(stupce i redove)
        /// </summary>
        private void ispuniDataGrid()
        {
            DataGridViewTextBoxColumn c;
            DataGridViewRow r;

            #region Stupci
            foreach (SSP.Klase.Znak znak in sviZnakovi)//Za svaki znak doda jedan stupac
            {
                c = new DataGridViewTextBoxColumn();

                c.Name = znak.znak;
                c.HeaderCell.Value = znak.znak;
                c.Width = 30;

                dataGridView1.Columns.Add(c);
            }

            c = new DataGridViewTextBoxColumn();//Dodatni stupac za znak kraja niza _|_

            c.Name = "_|_";
            c.HeaderCell.Value = "_|_";
            c.Width = 30;

            dataGridView1.Columns.Add(c);
            #endregion

            #region Redovi
            foreach (SSP.Klase.Znak znak in sviZnakovi)//Za svaki znak doda jedan redak
            {
                r = new DataGridViewRow();

                r.HeaderCell.Value = znak.znak;

                dataGridView1.Rows.Add(r);
            }

            dataGridView1.Select();
            #endregion
        }
        /// <summary>
        /// Ispuni text box sa skupon SLIJEDI za sve prazne nezavrsne znakove
        /// </summary>
        private void ispuniTextBoxPNZ()
        {
            foreach (SSP.Klase.Znak znak in prazniNezavrsniZnakovi)
            {
                richTextBoxPNZ.Text += "SLIJEDI (<" + znak.znak + ">) = {" + skupSlijedi(znak.znak) + " }\n";
            }
        }
        /// <summary>
        /// Oznaci prazne nezavrsne znakove u tablici Ispred
        /// </summary>
        private void slectDataGrid()
        {
            dataGridView1.CurrentCell.Selected = false;

            for (int i = 0; i < dataGridView1.Rows.Count - 1; i++)
            {
                SSP.Klase.Znak znak = new SSP.Klase.Znak((string)dataGridView1.Rows[i].HeaderCell.Value);
                
                if (postojiLiPrazanZnakUListi(znak))
                {
                    dataGridView1.Rows[i].Selected = true;
                }
            }
        }

        #region Pomocne funkcije
        /// <summary>
        /// Provjerava postoji li zadani znak u listi praznih nezavrsnih znakova
        /// </summary>
        /// <param name="znak">Znak koji provjeravamo</param>
        /// <returns>true - ako postoji; false - ako ne postoji</returns>
        private bool postojiLiPrazanZnakUListi(Klase.Znak znak)
        {
            foreach (Klase.Znak x in prazniNezavrsniZnakovi)
            {
                if (x.znak == znak.znak)
                {
                    return true;
                }
            }

            return false;
        }
        /// <summary>
        /// Provjerava postoji li zadani znak u listi svih znakova
        /// </summary>
        /// <param name="znak">Znak koji provjeravamo</param>
        /// <returns>true - ako postoji; false - ako ne postoji</returns>
        private bool postojiLiZnakUListi(Klase.Znak znak)
        {
            foreach (Klase.Znak x in sviZnakovi)
            {
                if (x.znak == znak.znak)
                {
                    return true;
                }
            }

            return false;
        }
        /// <summary>
        /// Vrati indeks reda zadanog znaka u tablice Ispred
        /// </summary>
        /// <param name="znak">Znak kojemu trazimo indeks</param>
        /// <returns>indeks znaka</returns>
        private int indexRedaZaZnak(string znak)
        {
            for (int i = 0; i < dataGridView1.Rows.Count; i++)
            {
                if ((string)dataGridView1.Rows[i].HeaderCell.Value == znak)
                    return i;
            }
            return -1;
        }
        /// <summary>
        /// Vrati indeks stuopca zadanog znaka u tablice Ispred
        /// </summary>
        /// <param name="znak">Znak kojemu trazimo indeks</param>
        /// <returns>indeks znaka</returns>
        private int indexStupcaZaZnak(string znak)
        {
            for (int i = 0; i < dataGridView1.Columns.Count; i++)
            {
                if ((string)dataGridView1.Columns[i].HeaderCell.Value == znak)
                    return i;
            }
            return -1;
        }
        /// <summary>
        /// Za zadani znak napravi string skupa sljijedi, skup procita iz tablice Ispred
        /// </summary>
        /// <param name="znak">Znak za koji trazi skup slijedi</param>
        /// <returns>Skup slijedi u string obliku</returns>
        private string skupSlijedi(string znak)
        {
            string slijedi = "", temp;

            for (int i = 0; i < dataGridView1.Rows.Count; i++)
            {
                if ((string)dataGridView1.Rows[i].HeaderCell.Value == znak)
                {
                    for (int j = 0; j < dataGridView1.Columns.Count; j++)
                    {
                        if ((string)dataGridView1.Rows[i].Cells[j].Value == "1")
                        {
                            temp = (string)dataGridView1.Columns[j].HeaderCell.Value;
                            if (temp == temp.ToLower())
                            {
                                slijedi += ", " + temp;
                            }
                        }
                    }
                }
            }

            return slijedi.Trim().TrimStart(',');
        }
        /// <summary>
        /// Ispuni sve stupce u tablici Ispred osim zadnjeg stupca
        /// </summary>
        private void ispuniStupce()
        {
            //Prodje kroz sve produkcije te za sve znakove na lijevim stranama produkcija oznacava koji je njihov znak ispred
            //Ako je taj znak Nezavrsni onda oznacava da je ispred i svaki znak s kojim taj nezavrsni znak moze zavrsiti
            foreach(SSP.Klase.Produkcija produkcija in produkcije)
            {
                for (int i = produkcija.desnaStranaProdukcije.Count - 1; i > 0; i--)
                {
                    for (int j = i - 1; j > 0; j--)
                    {
                       if (postojiLiPrazanZnakUListi(produkcija.desnaStranaProdukcije[j]) == true)
                        {
                            dataGridView1.Rows[indexRedaZaZnak(produkcija.desnaStranaProdukcije[j - 1].znak)].Cells[indexStupcaZaZnak(produkcija.desnaStranaProdukcije[i].znak)].Value = "1";

                            foreach (SSP.Klase.Znak znak in zavrsavaSa(produkcija.desnaStranaProdukcije[j - 1].znak, 30))
                            {
                                dataGridView1.Rows[indexRedaZaZnak(znak.znak)].Cells[indexStupcaZaZnak(produkcija.desnaStranaProdukcije[i].znak)].Value = "1";
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                    dataGridView1.Rows[indexRedaZaZnak(produkcija.desnaStranaProdukcije[i - 1].znak)].Cells[indexStupcaZaZnak(produkcija.desnaStranaProdukcije[i].znak)].Value = "1";
                    foreach (SSP.Klase.Znak znak in zavrsavaSa(produkcija.desnaStranaProdukcije[i - 1].znak, 30))
                    {
                        dataGridView1.Rows[indexRedaZaZnak(znak.znak)].Cells[indexStupcaZaZnak(produkcija.desnaStranaProdukcije[i].znak)].Value = "1";
                    }
                }
            }

            bool promjena = true;
            int indexStupca1, indexStupca2;

            //Prolazi lijevim stranama svih produkcije te kopira sve jedinice iz stupca lijeve strane gramatike u stupac trenutnog znaka. 
            //Kada dodje do zavrsog znaka ili epsilona zavrsava s prolaskom lijeve strane te produkcije
            //Postupak se ponavlja sve dok je moguce kopirati nove jedinice na prazna mjesta
            while (promjena)
            {
                promjena = false;

                foreach (SSP.Klase.Produkcija produkcija in produkcije)
                {
                    indexStupca1 = indexStupcaZaZnak(produkcija.lijevaStranaProdukcije.znak);

                    #region prvi znak
                    if (produkcija.desnaStranaProdukcije[0].epsilon == true)
                        continue;
                        
                    indexStupca2 = indexStupcaZaZnak(produkcija.desnaStranaProdukcije[0].znak);

                    for (int j = 0; j < dataGridView1.Rows.Count; j++)
                    {
                        if ((string)dataGridView1.Rows[j].Cells[indexStupca2].Value != "1")
                        {
                            if ((string)dataGridView1.Rows[j].Cells[indexStupca1].Value == "1")
                            {
                                dataGridView1.Rows[j].Cells[indexStupca2].Value = "1";
                                promjena = true;
                            }
                        }
                    }
                    #endregion

                    #region ostali znakovi
                    for (int i = 0; i < produkcija.desnaStranaProdukcije.Count - 1; i++)
                    {
                        if (postojiLiPrazanZnakUListi(produkcija.desnaStranaProdukcije[i]) )
                        {
                            indexStupca2 = indexStupcaZaZnak(produkcija.desnaStranaProdukcije[i + 1].znak);
                            

                            for (int j = 0; j < dataGridView1.Rows.Count; j++)
                            {
                                if ((string)dataGridView1.Rows[j].Cells[indexStupca2].Value != "1")
                                {
                                    if ((string)dataGridView1.Rows[j].Cells[indexStupca1].Value == "1")
                                    {
                                        dataGridView1.Rows[j].Cells[indexStupca2].Value = "1";
                                        promjena = true;
                                    }
                                }
                            }

                            
                        }
                        else
                        {
                            break;
                        }
                    }
                    #endregion
                }
            }
        }
        /// <summary>
        /// Ispuni zadnji stupac tablice Ispred
        /// </summary>
        private void ispuniZadnjiStupac()
        {
            bool prosireno = true;

            dataGridView1.Rows[0].Cells[dataGridView1.Rows[0].Cells.Count - 1].Value = "1";

            //Za sve nezavrsne znakove koji mogu doci na kraj niza stavlja 1 na kraju njihovog reda u tablici Ispred
            while (prosireno)
            {
                prosireno = false;

                foreach (SSP.Klase.Produkcija produkcija in produkcije)
                {
                    if ((string)dataGridView1.Rows[indexRedaZaZnak(produkcija.lijevaStranaProdukcije.znak)].Cells[dataGridView1.Rows[indexRedaZaZnak(produkcija.lijevaStranaProdukcije.znak)].Cells.Count - 1].Value != "1")
                    {
                        foreach (SSP.Klase.Produkcija produkcija2 in produkcije)
                        {
                            if ((string)dataGridView1.Rows[indexRedaZaZnak(produkcija2.lijevaStranaProdukcije.znak)].Cells[dataGridView1.Rows[indexRedaZaZnak(produkcija2.lijevaStranaProdukcije.znak)].Cells.Count - 1].Value == "1")
                            {
                                for (int i = produkcija2.desnaStranaProdukcije.Count - 1; i >= 0; i--)
                                {
                                    
                                    if (produkcija.lijevaStranaProdukcije.znak == produkcija2.desnaStranaProdukcije[i].znak || (produkcija2.desnaStranaProdukcije[i].zavrsni && produkcija2.desnaStranaProdukcije[i].epsilon == false))
                                    {
                                        dataGridView1.Rows[indexRedaZaZnak(produkcija2.desnaStranaProdukcije[i].znak)].Cells[dataGridView1.Rows[indexRedaZaZnak(produkcija2.desnaStranaProdukcije[i].znak)].Cells.Count - 1].Value = "1";
                                        if (produkcija2.desnaStranaProdukcije[i].zavrsni == false)
                                        {
                                            prosireno = true;
                                            break;
                                        }
                                        break;
                                    }
                                    else if (postojiLiPrazanZnakUListi(produkcija2.desnaStranaProdukcije[i]))
                                    {
                                        continue;
                                    }
                                    else
                                    {
                                        break;
                                    }
                                }
                                if (prosireno)
                                {
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        /// <summary>
        /// Za zadani nezavrsni znak vrati sve znakove s kojim taj nezavrsni znak moze zavrsiti.
        /// Broj nam sluzi da ne bi usli u beskonacnu petlju
        /// </summary>
        /// <param name="nezavrsniZnak">Nezavrsni znak za kojega trazimo znakove s kojima zavrsava</param>
        /// <param name="broj">Postaviti na 15 ili vise</param>
        private List<SSP.Klase.Znak> zavrsavaSa(string nezavrsniZnak, int broj)
        {
            if (broj == 0) return new List<SSP.Klase.Znak>();

            List<SSP.Klase.Znak> lista = new List<SSP.Klase.Znak>();

            foreach(SSP.Klase.Produkcija produkcija in produkcije)
            {
                if (nezavrsniZnak == produkcija.lijevaStranaProdukcije.znak)
                {
                    for (int i = produkcija.desnaStranaProdukcije.Count - 1; i >= 0; i--)
                    {
                        if (produkcija.desnaStranaProdukcije[i].epsilon == true)
                        {
                            break;
                        }
                        else if (postojiLiPrazanZnakUListi(produkcija.desnaStranaProdukcije[i]) == true)
                        {
                            if (postojiLiZnakUListi(lista, produkcija.desnaStranaProdukcije[i].znak) == false)
                            {
                                lista.Add(produkcija.desnaStranaProdukcije[i]);
                            }

                            foreach (SSP.Klase.Znak znak in zavrsavaSa(produkcija.desnaStranaProdukcije[i].znak, broj - 1))
                            {
                                if(postojiLiZnakUListi(lista, znak.znak) == false )
                                {
                                    lista.Add(znak);
                                }
                            }

                            continue;
                        }
                        else
                        {
                            if (produkcija.desnaStranaProdukcije[i].zavrsni == true)
                            {
                                if (postojiLiZnakUListi(lista, produkcija.desnaStranaProdukcije[i].znak) == false)
                                {
                                    lista.Add(produkcija.desnaStranaProdukcije[i]);
                                }
                            }
                            else
                            {
                                if (postojiLiZnakUListi(lista, produkcija.desnaStranaProdukcije[i].znak) == false)
                                {
                                    lista.Add(produkcija.desnaStranaProdukcije[i]);
                                }
                                foreach (SSP.Klase.Znak znak in zavrsavaSa(produkcija.desnaStranaProdukcije[i].znak, broj - 1))
                                {
                                    if (postojiLiZnakUListi(lista, znak.znak) == false)
                                    {
                                        lista.Add(znak);
                                    }
                                }
                            }
                            break;
                        }
                    }
                }
            }

            return lista;
        }
        /// <summary>
        /// Provjerava postoji li zadani znak u zadanoj listi
        /// </summary>
        /// <param name="lista">Lista u kojoj trazimo znak</param>
        /// <param name="znak">Znak koji provjeravamo</param>
        /// <returns>true - ako postoji; false - ako ne postoji</returns>
        private bool postojiLiZnakUListi(List<SSP.Klase.Znak> lista, string znak)
        {
            foreach (SSP.Klase.Znak z in lista)
            {
                if (z.znak == znak)
                {
                    return true;
                }
            }
            return false;
        }
        #endregion

        /// <summary>
        /// Ispuni tablicu ispred pomocu produkcija zadane gramatike
        /// </summary>
        private void ispuniIspred()
        {
            ispuniStupce();

            ispuniZadnjiStupac();
        }

        #region click EventHandler-i
        /// <summary>
        /// Generira tablicu Ispred i skup SLIJEDI za praazne nezavrsne znakove i prikaze ih u formi
        /// </summary>
        private void buttonTablicaIspred_Click_1(object sender, EventArgs e)
        {
            if (richTextBoxProdukcijeGramatike.Text != "")
            {
                #region Resetira formu
                dataGridView1.Visible = true;
                dataGridView1.Rows.Clear();
                dataGridView1.Columns.Clear();
                richTextBoxPNZ.Text = "";
                #endregion

                //Ispuni listiu produkcija iz tex boxa u kojem se nalaze produkcije gramatike
                ispuniListuProdukcija();
                //Ispuni listiu praznih nezavrsnih znakova koji se nalaze u gramatici
                ispuniPrazneNezavrsneZnakove();
                //Ispuni listu sa svim znakovima 
                ispuniListuZnakova();
                //Inicijalizira stupce i retke tablice Ispred
                ispuniDataGrid();

                //Ispuni tablicu s jedinicama na odredenim mjestima
                ispuniIspred();

                //Ispuni text box sa skupvima slijedi praznih nezavršnih znakova
                //Te skupove procitamo iz tablice Ispred
                ispuniTextBoxPNZ();

                //Selektira(oboja plavon bojom) redove praznih nezavrsnih znakova
                slectDataGrid();
            }
        }
        /// <summary>
        /// Zatvori aplikaciju
        /// </summary>
        private void izlazToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }
        /// <summary>
        /// Ucitat novu gramatiku iz odabrane .txt datoteke
        /// </summary>
        private void učitajGramatikuToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FileDialog folder = new OpenFileDialog();
            folder.Filter = "Files of type (*.txt)|*.txt";
            folder.InitialDirectory = Directory.GetCurrentDirectory();
            folder.ShowDialog();
            ispuniTextBoxProdukcije(folder.FileName);
            folder.Dispose();

            dataGridView1.Rows.Clear();
            dataGridView1.Columns.Clear();
            richTextBoxPNZ.Text = "";
        }
        #endregion
    }
}
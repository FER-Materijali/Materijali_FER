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
        }

        private void parsirajGram1Button_Click(object sender, EventArgs e)
        {
            //GRAMATIKA:
            #region Inicijalizacija Gramatike
            Dictionary<String, string> gramatikaDict = new Dictionary<string, string>();
            gramatikaDict.Add("<S>1", "(<A><S>)");
            gramatikaDict.Add("<S>2", "(b)");
            gramatikaDict.Add("<A>1", "(<S>a<A>)");
            gramatikaDict.Add("<A>2", "(a)");
            #endregion


            //TABLICA STAVI:
            #region Inicijalizacija tablice Stavi
            string[,] tablicaStaviMx = new string[11, 8];
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    tablicaStaviMx[i, j] = "0";
                }
            }

            tablicaStaviMx[0, 1] = "a"; tablicaStaviMx[0, 2] = "b"; tablicaStaviMx[0, 3] = "("; tablicaStaviMx[0, 4] = ")"; tablicaStaviMx[0, 5] = "<S>"; tablicaStaviMx[0, 6] = "<A>";
            tablicaStaviMx[1, 0] = "a1"; tablicaStaviMx[1, 3] = "(1"; tablicaStaviMx[1, 6] = "<A>2";
            tablicaStaviMx[2, 0] = "a2"; tablicaStaviMx[2, 3] = "(1"; tablicaStaviMx[2, 4] = ")4"; 
            tablicaStaviMx[3, 0] = "b1"; tablicaStaviMx[3, 3] = "(1"; tablicaStaviMx[3, 4] = ")2"; 
            tablicaStaviMx[4, 0] = "(1"; tablicaStaviMx[4, 1] = "a2"; tablicaStaviMx[4, 2] = "b1"; tablicaStaviMx[4, 3] = "(1"; tablicaStaviMx[4, 5] = "<S>2"; tablicaStaviMx[4, 6] = "<A>1";
            tablicaStaviMx[5, 0] = "<S>1"; tablicaStaviMx[5, 3] = "(1"; tablicaStaviMx[5, 4] = ")1"; 
            tablicaStaviMx[6, 0] = "<S>2"; tablicaStaviMx[6, 1] = "a1"; tablicaStaviMx[6, 3] = "(1";
            tablicaStaviMx[7, 0] = "<S>3"; tablicaStaviMx[7, 3] = "(1";
            tablicaStaviMx[8, 0] = "<A>1"; tablicaStaviMx[8, 3] = "(1"; tablicaStaviMx[8, 5] = "<S>1";
            tablicaStaviMx[9, 0] = "<A>2"; tablicaStaviMx[9, 3] = "(1"; tablicaStaviMx[9, 4] = ")3";
            tablicaStaviMx[10, 0] = "V"; tablicaStaviMx[10, 3] = "(1"; tablicaStaviMx[10, 5] = "<S>3";
            #endregion

            //TABLICA POMAKNI/REDUCIRAJ
            #region Inicijalizacija tablice POMAKNI/REDUCIRAJ
            string[,] tablicaPomRedMx = new string[15, 6];

            for (int i = 0; i < 15; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    tablicaPomRedMx[i, j] = "P";
                }
            }
            tablicaPomRedMx[0, 1] = "("; tablicaPomRedMx[0, 2] = "a"; tablicaPomRedMx[0, 3] = "b"; tablicaPomRedMx[0, 4] = ")"; tablicaPomRedMx[0, 5] = "T";
            tablicaPomRedMx[1, 0] = "a1"; tablicaPomRedMx[1, 5] = "O";
            tablicaPomRedMx[2, 0] = "a2"; tablicaPomRedMx[2, 5] = "O";
            tablicaPomRedMx[3, 0] = "b1"; tablicaPomRedMx[3, 5] = "O";
            tablicaPomRedMx[4, 0] = "(1"; tablicaPomRedMx[4, 5] = "O";
            tablicaPomRedMx[5, 0] = ")1"; tablicaPomRedMx[5, 1] = "R4"; tablicaPomRedMx[5, 2] = "R4"; tablicaPomRedMx[5, 3] = "R4"; tablicaPomRedMx[5, 4] = "R4"; tablicaPomRedMx[5, 5] = "R4";
            tablicaPomRedMx[6, 0] = ")2"; tablicaPomRedMx[6, 1] = "R3"; tablicaPomRedMx[6, 2] = "R3"; tablicaPomRedMx[6, 3] = "R3"; tablicaPomRedMx[6, 4] = "R3"; tablicaPomRedMx[6, 5] = "R3";
            tablicaPomRedMx[7, 0] = ")3"; tablicaPomRedMx[7, 1] = "R5"; tablicaPomRedMx[7, 2] = "R5"; tablicaPomRedMx[7, 3] = "R5"; tablicaPomRedMx[7, 4] = "R5"; tablicaPomRedMx[7, 5] = "R5";
            tablicaPomRedMx[8, 0] = ")4"; tablicaPomRedMx[8, 1] = "R3"; tablicaPomRedMx[8, 2] = "R3"; tablicaPomRedMx[8, 3] = "R3"; tablicaPomRedMx[8, 4] = "R3"; tablicaPomRedMx[8, 5] = "R3";
            tablicaPomRedMx[9, 0] = "<S>1"; tablicaPomRedMx[9, 5] = "O";
            tablicaPomRedMx[10, 0] = "<S>2"; tablicaPomRedMx[10, 5] = "O";
            tablicaPomRedMx[11, 0] = "<S>3"; tablicaPomRedMx[11, 5] = "A";
            tablicaPomRedMx[12, 0] = "<A>1"; tablicaPomRedMx[12, 5] = "O";
            tablicaPomRedMx[13, 0] = "<A>2"; tablicaPomRedMx[13, 5] = "O";
            tablicaPomRedMx[14, 0] = "V"; tablicaPomRedMx[14, 5] = "O";
            tablicaPomRedMx[0, 0] = "0";

            #endregion

            string ulazniNiz = gram1UlazniNizBox.Text;

            if (ulazniNiz.Length < 1)
            {
                MessageBox.Show("Ulazni niz mora biti unesen!!!!", "GRESKA", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
            else
            {
                ulazniNiz += "T";

                string text = parsirajUlazniNizZadanomGramatikom(gramatikaDict, tablicaStaviMx,tablicaPomRedMx, ulazniNiz);
                gram1OutputReslutLabel.Text = text;
            }

        }

        private void parsirajGram2Button_Click(object sender, EventArgs e)
        {
            //GRAMATIKA:
            #region Inicijalizacija Gramatike 2:
            Dictionary<String, string> gramatika2Dict = new Dictionary<string, string>();
            gramatika2Dict.Add("<S>1", "(b<A><S><B>)");
            gramatika2Dict.Add("<S>2", "(b<A>)");
            gramatika2Dict.Add("<A>1", "(d<S>ca)");
            gramatika2Dict.Add("<A>2", "(e)");
            gramatika2Dict.Add("<B>1", "(c<A>a)");
            gramatika2Dict.Add("<B>2", "(c)");
            #endregion

            //TABLICA STAVI:
            #region Inicijalizacija tablice STAVI:
            string[,] tablicastaviMX = new string[16, 12];
            for (int i = 0; i < 16; i++)
            {
                for (int j = 0; j < 12; j++)
                {
                    tablicastaviMX[i, j] = "0";
                }
            }

            tablicastaviMX[0, 1] = "a"; tablicastaviMX[0, 2] = "b"; tablicastaviMX[0, 3] = "c"; tablicastaviMX[0, 4] = "d"; tablicastaviMX[0, 5] = "e"; tablicastaviMX[0, 6] = "("; tablicastaviMX[0, 7] = ")"; tablicastaviMX[0, 8] = "<S>"; tablicastaviMX[0, 9] = "<A>"; tablicastaviMX[0, 10] = "<B>";
            tablicastaviMX[1, 0] = "a1"; tablicastaviMX[1, 6] = "(1"; tablicastaviMX[1, 7] = ")3"; tablicastaviMX[1, 11] = "6";
            tablicastaviMX[2, 0] = "a2"; tablicastaviMX[2, 6] = "(1"; tablicastaviMX[2, 7] = ")5"; tablicastaviMX[2, 11] = "5";
            tablicastaviMX[3, 0] = "b1"; tablicastaviMX[3, 6] = "(1"; tablicastaviMX[3, 9] = "<A>1";
            tablicastaviMX[4, 0] = "c1"; tablicastaviMX[4, 1] = "a1"; tablicastaviMX[4, 6] = "(1";
            tablicastaviMX[5, 0] = "c2"; tablicastaviMX[5, 6] = "(1"; tablicastaviMX[5, 7] = ")6"; tablicastaviMX[5, 9] = "<A>2"; tablicastaviMX[5, 11] = "3";
            tablicastaviMX[6, 0] = "d1"; tablicastaviMX[6, 6] = "(1"; tablicastaviMX[6, 8] = "<S>2";
            tablicastaviMX[7, 0] = "e1"; tablicastaviMX[7, 6] = "(1"; tablicastaviMX[7, 7] = ")4"; tablicastaviMX[7, 11] = "3";
            tablicastaviMX[8, 0] = "(1"; tablicastaviMX[8, 2] = "b1"; tablicastaviMX[8, 3] = "c2"; tablicastaviMX[8, 4] = "d1"; tablicastaviMX[8, 5] = "e1"; tablicastaviMX[8, 6] = "(1";
            tablicastaviMX[9, 0] = "<S>1"; tablicastaviMX[9, 6] = "(1"; tablicastaviMX[9, 10] = "<B>1";
            tablicastaviMX[10, 0] = "<S>2"; tablicastaviMX[10, 3] = "c1"; tablicastaviMX[10, 6] = "(1";
            tablicastaviMX[11, 0] = "<S>3"; tablicastaviMX[11, 6] = "(1";
            tablicastaviMX[12, 0] = "<A>1"; tablicastaviMX[12, 6] = "(1"; tablicastaviMX[12, 7] = ")2"; tablicastaviMX[12, 8] = "<S>1"; tablicastaviMX[12, 11] = "4";
            tablicastaviMX[13, 0] = "<A>2"; tablicastaviMX[13, 1] = "a2"; tablicastaviMX[13, 6] = "(1";
            tablicastaviMX[14, 0] = "<B>1"; tablicastaviMX[14, 6] = "(1"; tablicastaviMX[14, 7] = ")1"; tablicastaviMX[14, 11] = "6";
            tablicastaviMX[15, 0] = "V"; tablicastaviMX[15, 6] = "(1"; tablicastaviMX[15, 8] = "<S>3";

            #endregion

            //TABLICA POMAKNI/REDUCIRAJ
            #region Inicijalizacija tablice POMAKNI/REDUCIRAJ
            string[,] tablicaPomRedMx = new string[22, 9];
            tablicaPomRedMx[0, 0] = "0"; tablicaPomRedMx[0, 1] = "("; tablicaPomRedMx[0, 2] = "a"; tablicaPomRedMx[0, 3] = "b"; tablicaPomRedMx[0, 4] = "c"; tablicaPomRedMx[0, 5] = "d"; tablicaPomRedMx[0, 6] = "e"; tablicaPomRedMx[0, 7] = ")"; tablicaPomRedMx[0, 8] = "T";
            tablicaPomRedMx[1, 0] = "a1"; tablicaPomRedMx[2, 0] = "a2"; tablicaPomRedMx[3, 0] = "b1"; tablicaPomRedMx[4, 0] = "c1"; tablicaPomRedMx[5, 0] = "c2"; tablicaPomRedMx[6, 0] = "d1"; tablicaPomRedMx[7, 0] = "e1"; tablicaPomRedMx[8, 0] = ")1"; tablicaPomRedMx[9, 0] = ")2"; tablicaPomRedMx[10, 0] = ")3"; tablicaPomRedMx[11, 0] = ")4"; tablicaPomRedMx[12, 0] = ")5"; tablicaPomRedMx[13, 0] = ")6"; tablicaPomRedMx[14, 0] = "<S>1"; tablicaPomRedMx[15, 0] = "<S>2"; tablicaPomRedMx[16, 0] = "<S>3"; tablicaPomRedMx[17, 0] = "<A>1"; tablicaPomRedMx[18, 0] = "<A>2"; tablicaPomRedMx[19, 0] = "<B>1"; tablicaPomRedMx[20, 0] = "(1"; tablicaPomRedMx[21, 0] = "V";

            for (int i = 1; i < 22; i++)
            {
                for (int j = 1; j < 9; j++)
                {
                    tablicaPomRedMx[i, j] = "P";
                }
            }

            for (int i = 1; i < 22; i++)
            {
                tablicaPomRedMx[i, 8] = "O";
            }

            for (int i = 1; i < 9; i++)
            {
                tablicaPomRedMx[8, i] = "R6";
                tablicaPomRedMx[9, i] = "R4";
                tablicaPomRedMx[10, i] = "R6";
                tablicaPomRedMx[11, i] = "R3";
                tablicaPomRedMx[12, i] = "R5";
                tablicaPomRedMx[13, i] = "R3";
            }

            tablicaPomRedMx[16, 8] = "A";


            #endregion


            string ulazniNiz = gram2UlazniNiz.Text;

            if (ulazniNiz.Length < 1)
            {
                MessageBox.Show("Ulazni niz mora biti unesen!!!!", "GRESKA", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
            else
            {
                ulazniNiz += "T";

                string text = parsirajUlazniNizZadanomGramatikom(gramatika2Dict, tablicastaviMX, tablicaPomRedMx, ulazniNiz);
                gram2OutputReslutLabel.Text = text;
            }
        }

        private void parsirajGram3Button_Click(object sender, EventArgs e)
        {
            //GRAMATIKA:
            #region Inicijalizacija Gramatike
            Dictionary<String, string> gramatikaDict = new Dictionary<string, string>();
            gramatikaDict.Add("S1", "(L)");
            gramatikaDict.Add("S2", "x");
            gramatikaDict.Add("L1", "S");
            gramatikaDict.Add("L2", "L,S");
            #endregion


            //TABLICA STAVI:
            #region Inicijalizacija tablice Stavi
            string[,] tablicaStaviMx = new string[8, 8];
            for (int i = 0; i < 7; i++)
            {
                for (int j = 0; j < 7; j++)
                {
                    tablicaStaviMx[i, j] = "0";
                }
            }

            tablicaStaviMx[0, 1] = "("; tablicaStaviMx[0, 2] = ")"; tablicaStaviMx[0, 3] = "x"; tablicaStaviMx[0, 4] = "S"; tablicaStaviMx[0, 5] = "L"; tablicaStaviMx[0, 6] = ",";
            tablicaStaviMx[1, 0] = "(1"; tablicaStaviMx[1, 1] = "(1"; tablicaStaviMx[1, 3] = "x1"; tablicaStaviMx[1, 4] = "S1"; tablicaStaviMx[1, 5] = "L1";
            tablicaStaviMx[2, 0] = ",1"; tablicaStaviMx[2, 1] = "(1"; tablicaStaviMx[2, 3] = "x1"; tablicaStaviMx[2, 4] = "S2";
            tablicaStaviMx[3, 0] = "S3"; tablicaStaviMx[3, 1] = "(1"; tablicaStaviMx[3, 3] = "x1"; tablicaStaviMx[3, 4] = "S1";
            tablicaStaviMx[4, 0] = "L1"; tablicaStaviMx[4, 1] = "(1"; tablicaStaviMx[4, 2] = ")1"; tablicaStaviMx[4, 3] = "x1"; tablicaStaviMx[4, 4] = "S1"; tablicaStaviMx[4, 6] = ",1";
            tablicaStaviMx[5, 0] = "L2"; tablicaStaviMx[5, 1] = "(1"; tablicaStaviMx[5, 3] = "x1"; tablicaStaviMx[5, 4] = "S1"; tablicaStaviMx[5, 6] = ",1";
            tablicaStaviMx[6, 0] = "V"; tablicaStaviMx[6, 1] = "(1"; tablicaStaviMx[6, 3] = "x1"; tablicaStaviMx[6, 4] = "S3";

            #endregion

            // TABLICA Pomakni/Reduciraj
            #region Inicijalizacija tablice POMAKNI/REDICURAJ
            string[,] tablicaPomRedMx = new string[11,6];
            for (int i = 1; i < 11; i++)
            {
                for (int j = 1; j < 6; j++)
                {
                    tablicaPomRedMx[i, j] = "0";
                }
            }
            for (int i = 0; i < 11; i++)
            {
                tablicaPomRedMx[i, 5] = "O";
            }

            tablicaPomRedMx[0, 0] = "0"; tablicaPomRedMx[0, 1] = "("; tablicaPomRedMx[0, 2] = ")"; tablicaPomRedMx[0, 3] = "x"; tablicaPomRedMx[0, 4] = ","; tablicaPomRedMx[0, 5] = "T";
            tablicaPomRedMx[1, 0] = "x1"; tablicaPomRedMx[2, 0] = "(1"; tablicaPomRedMx[3, 0] = ")1"; tablicaPomRedMx[4, 0] = ",1"; tablicaPomRedMx[5, 0] = "S1"; tablicaPomRedMx[6, 0] = "S2"; tablicaPomRedMx[7, 0] = "S3"; tablicaPomRedMx[8, 0] = "L1"; tablicaPomRedMx[9, 0] = "L2"; tablicaPomRedMx[10, 0] = "V";
            tablicaPomRedMx[2, 1] = "P"; tablicaPomRedMx[2, 3] = "P"; tablicaPomRedMx[4, 1] = "P"; tablicaPomRedMx[4, 3] = "P"; tablicaPomRedMx[8, 1] = "P"; tablicaPomRedMx[8, 2] = "P"; tablicaPomRedMx[8, 4] = "P"; tablicaPomRedMx[9, 2] = "P"; tablicaPomRedMx[9, 4] = "P"; tablicaPomRedMx[10, 1] = "P"; tablicaPomRedMx[10, 3] = "P";
            
            for (int i = 1; i < 6; i++)
            {
                tablicaPomRedMx[1, i] = "R1";
                tablicaPomRedMx[3, i] = "R3";
                tablicaPomRedMx[5, i] = "R1";
                tablicaPomRedMx[6, i] = "R3";
            }
            tablicaPomRedMx[7, 5] = "A";

            #endregion



            string ulazniNiz = gram3UlazniNizBox.Text;

            if (ulazniNiz.Length < 1)
            {
                MessageBox.Show("Ulazni niz mora biti unesen!!!!", "GRESKA", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
            else
            {
                ulazniNiz += "T"; //Kraj niza

                string text = parsirajUlazniNizZadanomGramatikom(gramatikaDict, tablicaStaviMx, tablicaPomRedMx, ulazniNiz);
                gram3OutputReslutLabel.Text = text;
            }

                       




        }

        public string parsirajUlazniNizZadanomGramatikom(Dictionary<string, string> gramatika, string[,] tablicaST, string[,] tablicaPR, string ulaz)
        {
            #region PARSIRANJE

            Dictionary<string, string> gramatikaDict = gramatika;
            string[,] tablicaStaviMx = tablicaST;
            string[,] tablicaPomRedMx = tablicaPR;

            bool odbaci = false;
            bool prihvati = false;

            string ulazniNiz = ulaz;
            char znakUlaznogNiza;

            int ulazniNizBrojac = 0;

            Stack<string> stog = new Stack<string>();
            stog.Push("V");

            string znakStoga = "";

            while (ulazniNizBrojac < ulazniNiz.Length)
            {

                if (prihvati == false && odbaci == false)
                {

                    znakUlaznogNiza = ulazniNiz[ulazniNizBrojac];
                    znakStoga = stog.Peek();

                    int lokacijaUlaznogZnakaPR = pronadiMjestoZaUlazniZnak(znakUlaznogNiza.ToString(), tablicaPomRedMx);
                    int lokacijaZnakaSaStogaPR = pronadiMjestoZaZnakStoga(znakStoga, tablicaPomRedMx);

                    if(lokacijaUlaznogZnakaPR == 0 || lokacijaZnakaSaStogaPR == 0)
                    {
                        odbaci = true;
                        MessageBox.Show("Unešeni niz se NE prihvaca!!!", "Notification", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                        break;
                    }

                    string akcija = tablicaPomRedMx[lokacijaZnakaSaStogaPR, lokacijaUlaznogZnakaPR];

                    //REDUKCIJA:

                    
                    if (akcija.Substring(0, 1) == "R")
                    #region REDUCIRAJ:
                    {
                        int reduciraj = int.Parse(akcija.Substring(1, 1));
                        string reduciraniNiz = "";
                        string reversedReduciraniNiz = "";

                        for (int j = 0; j < reduciraj; j++)
                        {
                            //string niz = stog.Pop().Substring(0, 1);

                            string niz = stog.Pop();
                            string skraceniNiz = "";
                            if (niz == "V")
                            {
                                reversedReduciraniNiz += niz;
                            }
                            else
                            {
                                skraceniNiz = niz.Substring(0, niz.Length - 1);
                                reversedReduciraniNiz = skraceniNiz + reversedReduciraniNiz;
                            }
                        }
                        /*
                        for (int k = 0; k < reversedReduciraniNiz.Length; k++)
                        {
                            reduciraniNiz += reversedReduciraniNiz[reversedReduciraniNiz.Length - k - 1];
                        }*/
                        reduciraniNiz = reversedReduciraniNiz;

                        string znakKojemPripadaReduciraniNiz = "";

                        foreach (KeyValuePair<string, string> dict in gramatikaDict)
                        {
                            if (dict.Value == reduciraniNiz)
                            {
                                znakKojemPripadaReduciraniNiz = dict.Key;
                            }
                        }

                        string noviZnakStoga = stog.Peek();

                        znakKojemPripadaReduciraniNiz = znakKojemPripadaReduciraniNiz.Substring(0, (znakKojemPripadaReduciraniNiz.Length - 1));


                        int lokUlZnaka = pronadiMjestoZaUlazniZnak(znakKojemPripadaReduciraniNiz, tablicaStaviMx);
                        int lokZnStg = pronadiMjestoZaZnakStoga(noviZnakStoga, tablicaStaviMx);

                        if (tablicaStaviMx[lokZnStg, lokUlZnaka] == "0")
                        {
                            odbaci = true;
                            MessageBox.Show("Unešeni niz se NE prihvaca!!!", "Notification", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                            break;
                        }

                        stog.Push(tablicaStaviMx[lokZnStg, lokUlZnaka]);

                    } 
                    #endregion

                    else if (akcija == "O" || akcija == "0")
                    #region ODBACI:
                    {
                        odbaci = true;
                        MessageBox.Show("Uneseni niz se NE prihvaca!!!", "Notification", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                        break;
                    } 
                    #endregion
                        
                    else if (akcija == "P")
                    #region POMAKNI
                    {
                        int lokacijaUlaznogZnakaSTAVI = pronadiMjestoZaUlazniZnak(znakUlaznogNiza.ToString(), tablicaStaviMx);
                        int lokacijaZnakaSaStogaSTAVI = pronadiMjestoZaZnakStoga(znakStoga, tablicaStaviMx);

                        if (tablicaStaviMx[lokacijaZnakaSaStogaSTAVI, lokacijaUlaznogZnakaSTAVI] == "0")
                        {
                            odbaci = true;
                            MessageBox.Show("Uneseni niz se NE prihvaca!!!", "Notification", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                            break;
                        }

                        stog.Push(tablicaStaviMx[lokacijaZnakaSaStogaSTAVI, lokacijaUlaznogZnakaSTAVI]);
                        ulazniNizBrojac++;

                    } 
                    #endregion

                    else if (akcija == "A")
                    #region PRIHVATI:
                    {
                        prihvati = true;
                        MessageBox.Show("Unešeni niz se prihvaca!!!", "Notification", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                    } 
                    #endregion
 
                }
                else break;
            }
            
            if (prihvati == true)
            {
                return "Unešeni niz se prihvaca";
            }
            else return "Unešeni niz se NE prihvaca";
            
            #endregion

        }

        public int pronadiMjestoZaUlazniZnak(string znak, string[,] tablicaStavi)
        {
            #region Pronadi

            string znakZaNaci = znak;
            string[,] tablicaPretrazivanja = tablicaStavi;

            int brojac;
            int lokacijaUlaznogZnaka = 0;


            for (brojac = 1; brojac < tablicaPretrazivanja.GetLength(1); brojac++)
            {
                if (tablicaPretrazivanja[0, brojac] == znakZaNaci)
                {
                    lokacijaUlaznogZnaka = brojac;
                    break;
                }

            }
            if (lokacijaUlaznogZnaka == 0)
            {
                //MessageBox.Show("greska");       
            }
            return lokacijaUlaznogZnaka;
            

            #endregion
        }

        public int pronadiMjestoZaZnakStoga(string znak, string[,] tablicaStavi)
        {
            #region Pronadi

            string znakZaNaci = znak;
            string[,] tablicaPretrazivanja = tablicaStavi;

            int lokacijaZnakaSaStoga = 0;
            int brojac;
            int j = 0;
            while (true)
            {
                if (tablicaPretrazivanja[j, 0] == "V") break;
                else j++;
            }
            int velicina = j;

            for (brojac = 1; brojac <= velicina; brojac++)
            {
                if (tablicaPretrazivanja[brojac, 0] == znakZaNaci)
                {
                    lokacijaZnakaSaStoga = brojac;

                    break;
                }
            }

            if (lokacijaZnakaSaStoga == 0)
            {
                //MessageBox.Show("Greska");
            }

            return lokacijaZnakaSaStoga;
           

            #endregion
        }

    }
}

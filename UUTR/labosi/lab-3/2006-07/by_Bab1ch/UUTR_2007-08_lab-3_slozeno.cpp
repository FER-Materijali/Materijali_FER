//Inicijali su db, ulazni znakovi {d,b,a,i,n,c,j,l,e}


using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace UTR1
{
    public partial class Form1 : Form
    {
        List<char> traka = new List<char>();
        int ptraka = 0;
        int stanje = 0;

        private int prijelaz(int st, char znak)
        {   
            char nznak=znak;
            char smjer=\\'N\\';

            switch (stanje)
            {
                case 0:
                    if (znak == \\'b\\') { st = 1; nznak = \\'*\\'; smjer = \\'R\\'; }
                    if (znak == \\'d\\') { st = 5; nznak = \\'*\\'; smjer = \\'R\\'; }
                    if (znak == \\'a\\') { st = 0; nznak = \\'a\\'; smjer = \\'R\\'; }
                    if (znak == \\'n\\') { st = 0; nznak = \\'n\\'; smjer = \\'R\\'; }
                    if (znak == \\'i\\') { st = 0; nznak = \\'i\\'; smjer = \\'R\\'; }
                    if (znak == \\'j\\') { st = 0; nznak = \\'j\\'; smjer = \\'R\\'; }
                    if (znak == \\'e\\') { st = 0; nznak = \\'e\\'; smjer = \\'R\\'; }
                    if (znak == \\'l\\') { st = 0; nznak = \\'l\\'; smjer = \\'R\\'; }
                    if (znak == \\'c\\') { st = 0; nznak = \\'c\\'; smjer = \\'R\\'; }
                    if (znak == \\'X\\') { st = 0; nznak = \\'X\\'; smjer = \\'R\\'; }
                    if (znak == \\'B\\') { st = 9; nznak = \\'!\\'; smjer = \\'L\\'; }
                    break;

                case 1:
                    if (znak == \\'d\\') { st = 2; nznak = \\'X\\'; smjer = \\'R\\'; }
                    if (znak == \\'b\\') { st = 1; nznak = \\'b\\'; smjer = \\'R\\'; }                    
                    if (znak == \\'a\\') { st = 1; nznak = \\'a\\'; smjer = \\'R\\'; }
                    if (znak == \\'n\\') { st = 1; nznak = \\'n\\'; smjer = \\'R\\'; }
                    if (znak == \\'i\\') { st = 1; nznak = \\'i\\'; smjer = \\'R\\'; }
                    if (znak == \\'j\\') { st = 1; nznak = \\'j\\'; smjer = \\'R\\'; }
                    if (znak == \\'e\\') { st = 1; nznak = \\'e\\'; smjer = \\'R\\'; }
                    if (znak == \\'l\\') { st = 1; nznak = \\'l\\'; smjer = \\'R\\'; }
                    if (znak == \\'c\\') { st = 1; nznak = \\'c\\'; smjer = \\'R\\'; }
                    if (znak == \\'X\\') { st = 1; nznak = \\'X\\'; smjer = \\'R\\'; }
                    if (znak == \\'B\\') { st = 10; nznak = \\'?\\'; smjer = \\'L\\'; }
                    break;

                case 2:
                    if (znak == \\'d\\') { st = 3; nznak = \\'X\\'; smjer = \\'R\\'; }
                    if (znak == \\'b\\') { st = 2; nznak = \\'b\\'; smjer = \\'R\\'; }
                    if (znak == \\'a\\') { st = 2; nznak = \\'a\\'; smjer = \\'R\\'; }
                    if (znak == \\'n\\') { st = 2; nznak = \\'n\\'; smjer = \\'R\\'; }
                    if (znak == \\'i\\') { st = 2; nznak = \\'i\\'; smjer = \\'R\\'; }
                    if (znak == \\'j\\') { st = 2; nznak = \\'j\\'; smjer = \\'R\\'; }
                    if (znak == \\'e\\') { st = 2; nznak = \\'e\\'; smjer = \\'R\\'; }
                    if (znak == \\'l\\') { st = 2; nznak = \\'l\\'; smjer = \\'R\\'; }
                    if (znak == \\'c\\') { st = 2; nznak = \\'c\\'; smjer = \\'R\\'; }
                    if (znak == \\'X\\') { st = 2; nznak = \\'X\\'; smjer = \\'R\\'; }
                    if (znak == \\'B\\') { st = 10; nznak = \\'?\\'; smjer = \\'L\\'; }
                    break;

                case 3:
                    if (znak == \\'d\\') { st = 4; nznak = \\'X\\'; smjer = \\'L\\'; }
                    if (znak == \\'b\\') { st = 3; nznak = \\'b\\'; smjer = \\'R\\'; }
                    if (znak == \\'a\\') { st = 3; nznak = \\'a\\'; smjer = \\'R\\'; }
                    if (znak == \\'n\\') { st = 3; nznak = \\'n\\'; smjer = \\'R\\'; }
                    if (znak == \\'i\\') { st = 3; nznak = \\'i\\'; smjer = \\'R\\'; }
                    if (znak == \\'j\\') { st = 3; nznak = \\'j\\'; smjer = \\'R\\'; }
                    if (znak == \\'e\\') { st = 3; nznak = \\'e\\'; smjer = \\'R\\'; }
                    if (znak == \\'l\\') { st = 3; nznak = \\'l\\'; smjer = \\'R\\'; }
                    if (znak == \\'c\\') { st = 3; nznak = \\'c\\'; smjer = \\'R\\'; }
                    if (znak == \\'X\\') { st = 3; nznak = \\'X\\'; smjer = \\'R\\'; }
                    if (znak == \\'B\\') { st = 10; nznak = \\'?\\'; smjer = \\'L\\'; }
                    break;

                case 4:
                    if (znak == \\'*\\') { st = 0; nznak = \\'*\\'; smjer = \\'R\\'; }
                    if (znak == \\'d\\') { st = 4; nznak = \\'d\\'; smjer = \\'L\\'; }
                    if (znak == \\'b\\') { st = 4; nznak = \\'b\\'; smjer = \\'L\\'; }
                    if (znak == \\'a\\') { st = 4; nznak = \\'a\\'; smjer = \\'L\\'; }
                    if (znak == \\'n\\') { st = 4; nznak = \\'n\\'; smjer = \\'L\\'; }
                    if (znak == \\'i\\') { st = 4; nznak = \\'i\\'; smjer = \\'L\\'; }
                    if (znak == \\'j\\') { st = 4; nznak = \\'j\\'; smjer = \\'L\\'; }
                    if (znak == \\'e\\') { st = 4; nznak = \\'e\\'; smjer = \\'L\\'; }
                    if (znak == \\'l\\') { st = 4; nznak = \\'l\\'; smjer = \\'L\\'; }
                    if (znak == \\'c\\') { st = 4; nznak = \\'c\\'; smjer = \\'L\\'; }
                    if (znak == \\'X\\') { st = 4; nznak = \\'X\\'; smjer = \\'L\\'; }
                    
                    break;

                case 5:
                    if (znak == \\'d\\') { st = 6; nznak = \\'X\\'; smjer = \\'R\\'; }
                    if (znak == \\'b\\') { st = 5; nznak = \\'b\\'; smjer = \\'R\\'; }
                    if (znak == \\'a\\') { st = 5; nznak = \\'a\\'; smjer = \\'R\\'; }
                    if (znak == \\'n\\') { st = 5; nznak = \\'n\\'; smjer = \\'R\\'; }
                    if (znak == \\'i\\') { st = 5; nznak = \\'i\\'; smjer = \\'R\\'; }
                    if (znak == \\'j\\') { st = 5; nznak = \\'j\\'; smjer = \\'R\\'; }
                    if (znak == \\'e\\') { st = 5; nznak = \\'e\\'; smjer = \\'R\\'; }
                    if (znak == \\'l\\') { st = 5; nznak = \\'l\\'; smjer = \\'R\\'; }
                    if (znak == \\'c\\') { st = 5; nznak = \\'c\\'; smjer = \\'R\\'; }
                    if (znak == \\'X\\') { st = 5; nznak = \\'X\\'; smjer = \\'R\\'; }
                    if (znak == \\'B\\') { st = 10; nznak = \\'?\\'; smjer = \\'L\\'; }
                    break;

                case 6:
                    if (znak == \\'d\\') { st = 7; nznak = \\'X\\'; smjer = \\'l\\'; }
                    if (znak == \\'b\\') { st = 6; nznak = \\'b\\'; smjer = \\'R\\'; }
                    if (znak == \\'a\\') { st = 6; nznak = \\'a\\'; smjer = \\'R\\'; }
                    if (znak == \\'n\\') { st = 6; nznak = \\'n\\'; smjer = \\'R\\'; }
                    if (znak == \\'i\\') { st = 6; nznak = \\'i\\'; smjer = \\'R\\'; }
                    if (znak == \\'j\\') { st = 6; nznak = \\'j\\'; smjer = \\'R\\'; }
                    if (znak == \\'e\\') { st = 6; nznak = \\'e\\'; smjer = \\'R\\'; }
                    if (znak == \\'l\\') { st = 6; nznak = \\'l\\'; smjer = \\'R\\'; }
                    if (znak == \\'c\\') { st = 6; nznak = \\'c\\'; smjer = \\'R\\'; }
                    if (znak == \\'X\\') { st = 6; nznak = \\'X\\'; smjer = \\'R\\'; }
                    if (znak == \\'B\\') { st = 10; nznak = \\'?\\'; smjer = \\'L\\'; }
                    break;

                case 7:
                    if (znak == \\'*\\') { st = 8; nznak = \\'*\\'; smjer = \\'R\\'; }
                    if (znak == \\'d\\') { st = 7; nznak = \\'d\\'; smjer = \\'L\\'; }
                    if (znak == \\'b\\') { st = 7; nznak = \\'b\\'; smjer = \\'L\\'; }
                    if (znak == \\'a\\') { st = 7; nznak = \\'a\\'; smjer = \\'L\\'; }
                    if (znak == \\'n\\') { st = 7; nznak = \\'n\\'; smjer = \\'L\\'; }
                    if (znak == \\'i\\') { st = 7; nznak = \\'i\\'; smjer = \\'L\\'; }
                    if (znak == \\'j\\') { st = 7; nznak = \\'j\\'; smjer = \\'L\\'; }
                    if (znak == \\'e\\') { st = 7; nznak = \\'e\\'; smjer = \\'L\\'; }
                    if (znak == \\'l\\') { st = 7; nznak = \\'l\\'; smjer = \\'L\\'; }
                    if (znak == \\'c\\') { st = 7; nznak = \\'c\\'; smjer = \\'L\\'; }
                    if (znak == \\'X\\') { st = 7; nznak = \\'X\\'; smjer = \\'L\\'; }
                    break;

                case 8:
                    if (znak == \\'b\\') { st = 4; nznak = \\'X\\'; smjer = \\'L\\'; }
                    if (znak == \\'d\\') { st = 8; nznak = \\'d\\'; smjer = \\'R\\'; }
                    if (znak == \\'a\\') { st = 8; nznak = \\'a\\'; smjer = \\'R\\'; }
                    if (znak == \\'n\\') { st = 8; nznak = \\'n\\'; smjer = \\'R\\'; }
                    if (znak == \\'i\\') { st = 8; nznak = \\'i\\'; smjer = \\'R\\'; }
                    if (znak == \\'j\\') { st = 8; nznak = \\'j\\'; smjer = \\'R\\'; }
                    if (znak == \\'e\\') { st = 8; nznak = \\'e\\'; smjer = \\'R\\'; }
                    if (znak == \\'l\\') { st = 8; nznak = \\'l\\'; smjer = \\'R\\'; }
                    if (znak == \\'c\\') { st = 8; nznak = \\'c\\'; smjer = \\'R\\'; }
                    if (znak == \\'X\\') { st = 8; nznak = \\'X\\'; smjer = \\'R\\'; }
                    if (znak == \\'B\\') { st = 10; nznak = \\'?\\'; smjer = \\'L\\'; }
                    break;
            }

            // ispis
            string tmp1="", tmp2="";
            int j;
            for(j=0; j<ptraka; j++)tmp1 += traka[j];
            for(j=ptraka+1; j<traka.Count; j++) tmp2 += traka[j];
            lstIspis.Items.Add("Traka: " + tmp1 + "   " + traka[ptraka] + "   " + tmp2);

            traka[ptraka] = nznak;
            if (smjer == \\'L\\') ptraka--;
            if (smjer == \\'R\\') ptraka++;
            //if (ptraka + 1 == traka.Count) traka.Add(\\'B\\');
            
            return st;
        }

        private byte Turing()
        {         
            while (stanje != 10 && stanje != 9)
            {
                stanje = prijelaz(stanje, traka[ptraka]);
                Application.DoEvents();
            }
            return 0;
        }


        private void cmdUcitaj_Click(object sender, EventArgs e)
        {
            string tmp;
            char[] separator = new char[] {\\'\t\\', \\'\n\\', \\' \\', (char)13};
            string[] nizovi;
            int j;
            string tmp1 = "";

            tmp = System.IO.File.ReadAllText("lab3.txt");
            nizovi = tmp.Split(separator,StringSplitOptions.RemoveEmptyEntries);

            for (int i=0; i < nizovi.Length; i++)
            {
                lstIspis.Items.Add("Niz zapisan na traci: " + nizovi[i]);
                for (int z = 0; z < nizovi[i].Length; z++) traka.Add(nizovi[i][z]);
                Turing();                
                for (j = 0; j < traka.Count; j++) tmp1 += traka[j];
                if (stanje == 9) lstIspis.Items.Add("Zadani niz se prihvaca\tTraka: " + tmp1);
                else lstIspis.Items.Add("Zadani niz se NE prihvaca\t Traka: " + tmp1);
            }
        }

        private void cmdObrisi_Click(object sender, EventArgs e)
        {
            lstIspis.Items.Clear();
            ptraka = 0;
            stanje = 0;
            traka = new List<char>();
        }

        public Form1()
        {
            InitializeComponent();
        }
    }
}
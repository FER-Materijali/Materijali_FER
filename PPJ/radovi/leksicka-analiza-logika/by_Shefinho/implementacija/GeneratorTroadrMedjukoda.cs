using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace SSP_PPJ_62
{
    class SemantickaAkcija
    {
        public string akcija;
        public int op1;
        public int op2;
        public int op3;

        public SemantickaAkcija(string akcija, int op1, int op2, int op3)
        {
            this.akcija = akcija;
            this.op1 = op1;
            this.op2 = op2;
            this.op3 = op3;
        }
    }

    class SemantickiAnalizator
    {
        private List<SemantickaAkcija> NizSemantickihAkcija;

        public SemantickiAnalizator(List<Cvor> SintaksnoStablo)
        {
            NizSemantickihAkcija = new List<SemantickaAkcija>();
            foreach (Cvor cv in SintaksnoStablo)
                if (cv.getIzlazniZavrsni())
                    NizSemantickihAkcija.Add(new SemantickaAkcija(cv.getNaziv(), cv.op1, cv.op2, cv.op3));
        }
        
        public List<SemantickaAkcija> getNizSemantickihAkcija() { return NizSemantickihAkcija; }
    }

    class GeneratorTroadrMedjukoda 
    {
        private string kod;
        private List<SemantickaAkcija> NizSemantickihAkcija;
        private List<SemantickaAkcija> NizSemantickihAkcija2;

        public GeneratorTroadrMedjukoda(List<Cvor> SintaksnoStablo)
        {
            kod = "";
            SemantickiAnalizator seman = new SemantickiAnalizator(SintaksnoStablo);
            NizSemantickihAkcija = seman.getNizSemantickihAkcija();
            GenerirajKod(); 
        }

        private void GenerirajKod()
        {
            //napravi deep copy:
            NizSemantickihAkcija2 = new List<SemantickaAkcija>();
            foreach (SemantickaAkcija akc in NizSemantickihAkcija)
                NizSemantickihAkcija2.Add(new SemantickaAkcija(akc.akcija, akc.op1, akc.op2, akc.op3));

            //varijabla koja pamti trenutnu vrijednost globalnog indeksa u slučajevima kad se vrši pomak:
            int a;

            foreach (SemantickaAkcija akc in NizSemantickihAkcija2)
            {
                switch (akc.akcija)
                {
                    case "Pridruzi0":
                        kod += "R" + akc.op3.ToString() + " := 0\r\n";
                        break;

                    case "Pridruzi1":
                        kod += "R" + akc.op3.ToString() + " := 1\r\n";
                        break;

                    case "Konjunkcija":
                        kod += "R" + akc.op3.ToString() + " := R" + akc.op1.ToString() + " * R" + akc.op2.ToString() + "\r\n";
                        break;

                    case "Negacija":
                        kod += "R" + akc.op3.ToString() + " := R" + akc.op1.ToString() + " - 1\r\n";
                        kod += "R" + (akc.op3+1).ToString() + " := R" + akc.op3.ToString() + " * (-1)\r\n";
                        //obavi pomak:
                        a = akc.op3;
                        foreach (SemantickaAkcija akc2 in NizSemantickihAkcija2)
                        {
                            if (akc2.op1 >= a) akc2.op1 += 1;
                            if (akc2.op2 >= a) akc2.op2 += 1;
                            if (akc2.op3 >= a) akc2.op3 += 1;
                        }
                        break;

                    case "Disjunkcija":
                        kod += "R" + akc.op3.ToString() + " := R" + akc.op1.ToString() + " - 1\r\n";
                        kod += "R" + (akc.op3+1).ToString() + " := R" + akc.op3.ToString() + " * (-1)\r\n";
                        kod += "R" + (akc.op3+2).ToString() + " := R" + akc.op2.ToString() + " - 1\r\n";
                        kod += "R" + (akc.op3+3).ToString() + " := R" + (akc.op3+2).ToString() + " * (-1)\r\n";
                        kod += "R" + (akc.op3+4).ToString() + " := R" + (akc.op3+1).ToString() + " * R" + (akc.op3+3).ToString() + "\r\n";
                        kod += "R" + (akc.op3+5).ToString() + " := R" + (akc.op3+4).ToString() + " - 1\r\n";
                        kod += "R" + (akc.op3+6).ToString() + " := R" + (akc.op3+5).ToString() + " * (-1)\r\n";
                        //obavi pomak:
                        a = akc.op3;
                        foreach (SemantickaAkcija akc2 in NizSemantickihAkcija2)
                        {
                            if (akc2.op1 >= a) akc2.op1 += 6;
                            if (akc2.op2 >= a) akc2.op2 += 6;
                            if (akc2.op3 >= a) akc2.op3 += 6;
                        }
                        break;

                    default:
                        break;
                }
            }
        }

        public string getKod() { return kod; }

        public string IspisiNizSemantickihAkcija()
        {
            string buffer = "";
            foreach (SemantickaAkcija akc in NizSemantickihAkcija)
                buffer += akc.akcija + "(" + akc.op1.ToString() + ", " + akc.op2.ToString() + ", " + akc.op3.ToString() + ")\r\n";
            return buffer;
        }

        public string IspisiNizSemantickihAkcija2()
        {
            string buffer = "";
            foreach (SemantickaAkcija akc in NizSemantickihAkcija2)
                buffer += akc.akcija + "(" + akc.op1.ToString() + ", " + akc.op2.ToString() + ", " + akc.op3.ToString() + ")\r\n";
            return buffer;
        }
    }
}
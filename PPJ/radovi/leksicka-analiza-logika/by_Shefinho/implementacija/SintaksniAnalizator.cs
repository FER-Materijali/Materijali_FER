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
    class Cvor
    {
        private int ID;
        private int IDroditelja;
        private List<int> ID_eviDjece;
        private List<Cvor> Djeca;
        private bool IzlazniZavrsni;
        private string naziv;
        public int op1;
        public int op2;
        public int op3; 

        /// <summary>
        /// Konstruktor za izlazni završni znak
        /// </summary>
        /// <param name="ID"></param>
        /// <param name="IDroditelja"></param>
        /// <param name="naziv"></param>
        /// <param name="op1"></param>
        /// <param name="op2"></param>
        /// <param name="op3"></param>
        public Cvor(int ID, int IDroditelja, string naziv, int op1, int op2, int op3)
        {
            this.ID = ID;
            this.IDroditelja = IDroditelja;
            this.IzlazniZavrsni = true;
            this.naziv = naziv;
            this.ID_eviDjece = new List<int>();
            this.Djeca = new List<Cvor>();
            this.op1 = op1;
            this.op2 = op2;
            this.op3 = op3;
        }

        /// <summary>
        /// Konstruktor za završne i nezavršne znakove
        /// </summary>
        /// <param name="ID"></param>
        /// <param name="IDroditelja"></param>
        /// <param name="naziv"></param>
        public Cvor(int ID, int IDroditelja, string naziv)
        {
            this.ID = ID;
            this.IDroditelja = IDroditelja;
            this.IzlazniZavrsni = false;
            this.naziv = naziv;
            this.ID_eviDjece = new List<int>();
            this.Djeca = new List<Cvor>();
        }

        public int getID() { return ID; }
        public int getIDroditelja() { return IDroditelja; }
        public bool getIzlazniZavrsni() { return IzlazniZavrsni; }
        public string getNaziv() { return naziv; }
        public List<int> getID_eviDjece() { return ID_eviDjece; }
        public List<Cvor> getDjeca() { return Djeca; } 

        public void DodajDijete(Cvor cv)
        {
            this.ID_eviDjece.Add(cv.getID());
            this.Djeca.Add(cv);
        }

    }

    class SintaksniAnalizator
    {
        private string ulazniNiz;
        private int ulaz;
        private bool greska;
        private int globalniID;
        private int globalniIndeks;
        private List<Cvor> SintaksnoStablo;

        public SintaksniAnalizator(string LeksJedinke)
        {
            ulazniNiz = LeksJedinke;
            ulaz = 0;
            greska = false;
            globalniID = 1;
            globalniIndeks = 1;
            SintaksnoStablo = new List<Cvor>();
        }

        public List<Cvor> getSintaksnoStablo() { return SintaksnoStablo; }

        public bool Analiziraj()
        {
            izraz1(1);
            if (ulaz != ulazniNiz.Length) greska = true;
            else Povezi();
            return !greska; 
        }

        public void Povezi()
        {
            foreach (Cvor cv1 in SintaksnoStablo)
                foreach (Cvor cv2 in SintaksnoStablo)
                    if ((cv1.getID() != cv2.getID()) && (cv1.getID() == cv2.getIDroditelja()))
                        cv1.DodajDijete(cv2);
        }

        public string Ispisi()
        {
            string buffer = "";
            foreach (Cvor cv1 in SintaksnoStablo)
            {
                buffer += "Naziv: " + cv1.getNaziv() + "\r\n";
                buffer += "ID: " + cv1.getID().ToString() + "\r\n";
                buffer += "ID roditelja: " + cv1.getIDroditelja().ToString() + "\r\n";
                buffer += "ID-evi djece: ";
                foreach (int id in cv1.getID_eviDjece())
                    buffer += id.ToString() + ", ";
                buffer += "\r\n\r\n";
            }
            return buffer;
        }

        private void izraz1(int id_roditelja)
        {
            int mojID;
            SintaksnoStablo.Add(new Cvor(globalniID, id_roditelja, "izraz1"));
            mojID = globalniID;
            globalniID++;
            izraz2(mojID);
            ponovi1(mojID, globalniIndeks-1);
        }

        private void ponovi1(int id_roditelja, int a)
        {
            int mojID;
            if (ulaz < ulazniNiz.Length)
            {
                if (ulazniNiz[ulaz] == '+')
                {
                    SintaksnoStablo.Add(new Cvor(globalniID, id_roditelja, "ponovi1"));
                    mojID = globalniID;
                    globalniID++;
                    SintaksnoStablo.Add(new Cvor(globalniID, mojID, "+"));
                    globalniID++;
                    ulaz++;
                    if (ulaz < ulazniNiz.Length)
                    {
                        izraz2(mojID);
                        ponovi1(mojID, globalniIndeks-1);
                        SintaksnoStablo.Add(new Cvor(globalniID, mojID, "Disjunkcija", a, globalniIndeks-1, globalniIndeks));
                        globalniID++;
                        globalniIndeks++;
                    }
                    else greska = true;
                }
            }
        }

        private void izraz2(int id_roditelja)
        {
            int mojID;
            SintaksnoStablo.Add(new Cvor(globalniID, id_roditelja, "izraz2"));
            mojID = globalniID;
            globalniID++;
            izraz3(mojID);
            ponovi2(mojID, globalniIndeks-1);
        }

        private void ponovi2(int id_roditelja, int a)
        {
            int mojID;
            if (ulaz < ulazniNiz.Length)
            {
                if (ulazniNiz[ulaz] == '*')
                {
                    SintaksnoStablo.Add(new Cvor(globalniID, id_roditelja, "ponovi2"));
                    mojID = globalniID;
                    globalniID++;
                    SintaksnoStablo.Add(new Cvor(globalniID, mojID, "*"));
                    globalniID++;
                    ulaz++;
                    if (ulaz < ulazniNiz.Length)
                    {
                        izraz3(mojID);
                        ponovi2(mojID, globalniIndeks-1);
                        SintaksnoStablo.Add(new Cvor(globalniID, mojID, "Konjunkcija", a, globalniIndeks-1, globalniIndeks));
                        globalniID++;
                        globalniIndeks++;
                    }
                    else greska = true;
                }
            }
        }

        private void izraz3(int id_roditelja)
        {
            int mojID;
            if (ulaz < ulazniNiz.Length)
            {
                SintaksnoStablo.Add(new Cvor(globalniID, id_roditelja, "izraz3"));
                mojID = globalniID;
                globalniID++;
                if (ulazniNiz[ulaz] == '~')
                {
                    SintaksnoStablo.Add(new Cvor(globalniID, mojID, "~"));
                    globalniID++;
                    ulaz++;
                    izraz4(mojID);
                    SintaksnoStablo.Add(new Cvor(globalniID, mojID, "Negacija", globalniIndeks-1, 0, globalniIndeks));
                    globalniID++;
                    globalniIndeks++;
                }
                else izraz4(mojID);
            }
        }

        private void izraz4(int id_roditelja)
        {
            int mojID;
            if (ulaz < ulazniNiz.Length)
            {
                SintaksnoStablo.Add(new Cvor(globalniID, id_roditelja, "izraz4"));
                mojID = globalniID;
                globalniID++;
                switch (ulazniNiz[ulaz])
                {
                    case 'T':
                        SintaksnoStablo.Add(new Cvor(globalniID, mojID, "T"));
                        globalniID++;
                        ulaz++;
                        SintaksnoStablo.Add(new Cvor(globalniID, mojID, "Pridruzi1", 0, 0, globalniIndeks));
                        globalniID++;
                        globalniIndeks++;
                        return;
                    
                    case 'F':
                        SintaksnoStablo.Add(new Cvor(globalniID, mojID, "F"));
                        globalniID++;
                        ulaz++;
                        SintaksnoStablo.Add(new Cvor(globalniID, mojID, "Pridruzi0", 0, 0, globalniIndeks));
                        globalniID++;
                        globalniIndeks++;
                        return;
                    
                    case '(':
                        SintaksnoStablo.Add(new Cvor(globalniID, mojID, "("));
                        globalniID++;
                        ulaz++;
                        if (ulaz < ulazniNiz.Length)
                        {
                            izraz1(mojID);
                        }
                        else greska = true;
                        if (ulaz < ulazniNiz.Length)
                        {
                            if (ulazniNiz[ulaz] == ')')
                            {
                                SintaksnoStablo.Add(new Cvor(globalniID, mojID, ")"));
                                globalniID++;
                                ulaz++;
                            }
                            else greska = true;
                        }
                        else greska = true;
                        return;
                    
                    default:
                        greska = true;
                        return;
                }
            }
            else greska = true;
        }
    }
}
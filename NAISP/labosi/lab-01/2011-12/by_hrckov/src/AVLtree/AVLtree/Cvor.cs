using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AVLtree
{
    public class Cvor
    {
        int podatak;
        public Cvor LijevoDijete;
        public Cvor DesnoDijete;
        public Cvor Roditelj;
        int visinaLijevo;
        int visinaDesno;
        public CvorGraph Graf;

        public int VisinaDesno
        {
            get { return visinaDesno; }
            set { visinaDesno = value; }
        }

        public int VisinaLijevo
        {
            get { return visinaLijevo; }
            set { visinaLijevo = value; }
        }

        public int Podatak
        {
            get { return podatak; }
            set { podatak = value; }
        }

        public int FR
        {
            get { return visinaDesno - visinaLijevo; }
        }

        public Cvor(int broj)
        {
            podatak = broj;
            LijevoDijete = null;
            DesnoDijete = null;
            Roditelj = null;
            visinaLijevo = 0;
            visinaDesno = 0;
        }

        public int Visina
        {
            get {return Math.Max(visinaDesno,visinaLijevo); }
        }

        public void PostaviVisine()
        {
            try
            {
                visinaLijevo = LijevoDijete.Visina +1;                
            }
            catch 
            {
                visinaLijevo = 0;
            }
            try
            {
                visinaDesno = DesnoDijete.Visina +1;
            }
            catch
            {
                visinaDesno = 0;
            }
        }

       

       
    }
}

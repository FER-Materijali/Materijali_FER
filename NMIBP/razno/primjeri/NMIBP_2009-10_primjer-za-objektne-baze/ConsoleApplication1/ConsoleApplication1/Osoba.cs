using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    public class Osoba
    {
		#region Fields (5) 

        protected Drzava _drzava;
        protected String _ime;
        protected Momcad _momcad;
        protected String _prezime;
        protected int _sifra;

		#endregion Fields 

		#region Properties (5) 

        public Drzava Drzava
        {
            get { return _drzava; }
            set { _drzava = value; }
        }

        public String Ime
        {
            get { return _ime; }
            set { _ime = value; }
        }

        public Momcad Momcad
        {
            get { return _momcad; }
            set { _momcad = value; }
        }

        public String Prezime
        {
            get { return _prezime; }
            set { _prezime = value; }
        }

        public int Sifra
        {
            get { return _sifra; }
            set { _sifra = value; }
        }

		#endregion Properties 
    }
}

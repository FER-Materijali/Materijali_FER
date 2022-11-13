using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    public class Momcad
    {
		#region Fields (5) 

        int _bodovi;
        Osoba _direktor;
        Drzava _drzava;
        String _naziv;
        List<Pilot> _piloti;

		#endregion Fields 

		#region Properties (5) 

        public int Bodovi
        {
            get { return _bodovi; }
            set { _bodovi = value; }
        }

        internal Osoba Direktor
        {
            get { return _direktor; }
            set { _direktor = value; }
        }

        internal Drzava Drzava
        {
            get { return _drzava; }
            set { _drzava = value; }
        }

        public String Naziv
        {
            get { return _naziv; }
            set { _naziv = value; }
        }

internal List<Pilot> Piloti
{
    get { return _piloti; }
    set { _piloti = value; }
}

		#endregion Properties 
    }
}

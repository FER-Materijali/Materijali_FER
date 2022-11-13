using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    public class Pilot : Osoba
    {
		#region Fields (2) 

        int _bodovi;
        String _vrsta;

		#endregion Fields 

		#region Constructors (2) 

        public Pilot(string ime, int bodovi)
        {
            this.Ime = ime;
            this.Bodovi = bodovi;
        }

        public Pilot()
        { }

		#endregion Constructors 

		#region Properties (2) 

        public int Bodovi
        {
            get { return _bodovi; }
            set { _bodovi = value; }
        }

        public String Vrsta
        {
            get { return _vrsta; }
            set { _vrsta = value; }
        }

		#endregion Properties 
    }
}

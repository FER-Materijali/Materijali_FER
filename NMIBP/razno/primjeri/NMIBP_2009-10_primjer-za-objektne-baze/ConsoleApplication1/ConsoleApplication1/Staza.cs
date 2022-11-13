using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    public class Staza
    {
		#region Fields (3) 

        Drzava _drzava;
        String _naziv;
        long _rekord;

		#endregion Fields 

		#region Properties (3) 

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

        public long Rekord
        {
            get { return _rekord; }
            set { _rekord = value; }
        }

		#endregion Properties 
    }
}

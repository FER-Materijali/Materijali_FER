using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    public class Drzava
    {
		#region Fields (2) 

        String _naziv;
        String _oznaka;

		#endregion Fields 

		#region Properties (2) 

        public String Naziv
        {
            get { return _naziv; }
            set { _naziv = value; }
        }

        public String Oznaka
        {
            get { return _oznaka; }
            set { _oznaka = value; }
        }

		#endregion Properties 
    }
}

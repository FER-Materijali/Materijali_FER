using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    public class Plasman
    {
		#region Fields (3) 

        int _bodovi;
        Pilot _pilot;
        int _pozicija;

		#endregion Fields 

		#region Properties (3) 

        public int Bodovi
        {
            get { return _bodovi; }
            set { _bodovi = value; }
        }

        internal Pilot Pilot
        {
            get { return _pilot; }
            set { _pilot = value; }
        }

        public int Pozicija
        {
            get { return _pozicija; }
            set { _pozicija = value; }
        }

		#endregion Properties 
    }
}

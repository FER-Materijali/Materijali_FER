using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    public class Utrka
    {
		#region Fields (4) 

        DateTime _datum;
        String _naziv;
        List<Plasman> _rezultati;
        Staza _staza;

		#endregion Fields 

		#region Properties (4) 

        public DateTime Datum
        {
            get { return _datum; }
            set { _datum = value; }
        }

        public String Naziv
        {
            get { return _naziv; }
            set { _naziv = value; }
        }

        internal List<Plasman> Rezultati
        {
            get { return _rezultati; }
            set { _rezultati = value; }
        }

        internal Staza Staza
        {
            get { return _staza; }
            set { _staza = value; }
        }

		#endregion Properties 
    }
}
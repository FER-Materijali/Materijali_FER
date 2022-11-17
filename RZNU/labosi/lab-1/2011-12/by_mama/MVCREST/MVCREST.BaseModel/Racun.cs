using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MVCREST.BaseModel
{
    public class Racun
    {
        private long _id;
        public virtual long Id
        {
            get { return _id; }
            set { _id = value; }
        }

        private string _brojRacuna;
        public virtual string BrojRacuna
        {
            get { return _brojRacuna; }
            set { _brojRacuna = value; }
        }

        private float _stanjeRacuna;
        public virtual float StanjeRacuna
        {
            get { return _stanjeRacuna; }
            set { _stanjeRacuna = value; }
        }

        private Osoba _vlasnik;
        public virtual Osoba Vlasnik
        {
          get { return _vlasnik; }
          set { _vlasnik = value; }
        }

        public Racun() { }

        public Racun(long inId, string inBrojRacuna, 
            float inStanjeRacuna, Osoba inVlasnik)
        {
            _id = inId;
            _brojRacuna = inBrojRacuna;
            _stanjeRacuna = inStanjeRacuna;
            _vlasnik = inVlasnik;
        }
    }
}

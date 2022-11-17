using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MVCREST.BaseModel
{
    public class Osoba
    {
        private long _id;
        public virtual long Id
        {
            get { return _id; }
            set { _id = value; }
        }
        
        private string _ime;
        public virtual string Ime
        {
            get { return _ime; }
            set { _ime = value; }
        }

        private string _prezime;
        public virtual string Prezime
        {
            get { return _prezime; }
            set { _prezime = value; }
        }

        private IList<Racun> _racuni;
        public virtual IList<Racun> Racuni
        {
          get { return _racuni; }
          set { _racuni = value; }
        }
        
        public Osoba() 
        {
            _racuni = new List<Racun>();
        }

        public Osoba(long inId, string inIme, 
            string inPrezime)
        {
            _id = inId;
            _ime = inIme;
            _prezime = inPrezime;
            _racuni = new List<Racun>();
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using MVCREST.BaseModel;

namespace MVCREST.Service.Models
{
    public class JSONOdgovorOsoba
    {
        public Odgovor Odgovor
        {
            get;
            set;
        }

        private Osoba _osoba;
        public Osoba Osoba
        {
            get
            {
                return _osoba;
            }
            set
            {
                _osoba = value;
                if (_osoba != null)
                {
                    if(_osoba.Racuni!=null)
                    {
                        foreach (Racun r in _osoba.Racuni)
                        {
                            r.Vlasnik = null;
                        }
                    }
                }
            }
        }

        public JSONOdgovorOsoba() { }
    }
}
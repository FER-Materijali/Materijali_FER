using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using MVCREST.BaseModel;

namespace MVCREST.Service.Models
{
    public class JSONOdgovorOsobe
    {
        public Odgovor Odgovor
        {
            get;
            set;
        }

        private List<Osoba> _osobe;
        public List<Osoba> Osobe
        {
            get
            {
                return _osobe;
            }
            set
            {
                _osobe = value;
                if (_osobe != null)
                {
                    foreach (Osoba o in _osobe)
                    {
                        o.Racuni=null;
                    }
                }
            }
        }

        public JSONOdgovorOsobe()
        {
            _osobe = new List<Osoba>();
        }
    }
}
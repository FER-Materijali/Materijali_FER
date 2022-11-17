using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace MVCREST.Service.Models
{
    public class Odgovor
    {
        public const string USPJEH = "Uspjeh";
        public const string GRESKA = "Greška";

        private string _tip;
        public string Tip
        {
            get { return _tip; }
            set { _tip = value; }
        }

        private string _text;
        public string Text
        {
            get { return _text; }
            set { _text = value; }
        }

        private string _kljuc;
        public string Kljuc
        {
            get { return _kljuc; }
            set { _kljuc = value; }
        }

        public Odgovor() 
        {
            _text = null;
            _tip = null;
            _kljuc = null;
        }
    }
}
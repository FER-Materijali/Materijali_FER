using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SSP.Klase
{
    class Produkcija
    {
        #region Privatne varijable klase
        Znak lijevaStranaProdukcijeVar;
        List<Znak> desnaStranaProdukcijeVar = new List<Znak>();
        #endregion

        /// <summary>
        /// Konstruktor koji prima string produkcije i ispuni privatne varijable objekta
        /// </summary>
        public Produkcija(string produkcija)
        {
            produkcija = produkcija.Trim();
            
            if (produkcija != "")
            {
                string bla = produkcija.Substring(0, produkcija.LastIndexOf('-'));
                lijevaStranaProdukcijeVar = new Znak(bla);

                produkcija = produkcija.Remove(0, produkcija.LastIndexOf("->") + 2);

                foreach (string x in produkcija.Split())
                {
                    if (x != "")
                    {
                        desnaStranaProdukcijeVar.Add(new Znak(x));
                    }
                }
            }
        }

        /// <summary>
        /// Znak lijeve strane produkcije
        /// </summary>
        public Znak lijevaStranaProdukcije
        {
            get { return lijevaStranaProdukcijeVar; }
        }
        /// <summary>
        /// Znakovi desne strane produkcije
        /// </summary>
        public List<Znak> desnaStranaProdukcije
        {
            get { return desnaStranaProdukcijeVar; }
        }
    }
}

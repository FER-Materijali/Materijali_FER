using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SSP.Klase
{
    class Znak
    {
        #region Privatne varijable klase
        string znakVar;
        bool zavrsniVar;
        bool epsilonVar;
        #endregion

        /// <summary>
        /// Konstruktor koji ispuni privatne varijable kao epsilon
        /// </summary>
        public Znak()
        {
            epsilonVar = true;
        }
        /// <summary>
        /// Konstruktor koji ispuni privatne varijable po zadanom stringu
        /// </summary>
        public Znak(string znak)
        {
            znak = znak.Trim();
            if (znak[0] == '<')
            {
                znakVar = znak.TrimStart('<').TrimEnd('>');
                zavrsniVar = false;
                epsilonVar = false;
            }
            else if (znak == "$")
            {
                znakVar = "$";
                zavrsniVar = true;
                epsilonVar = true;
            }
            else
            {
                znakVar = znak;
                zavrsniVar = true;
                epsilonVar = false;
            }
        }

        /// <summary>
        /// Vrati string znak
        /// </summary>
        public string znak
        {
            get { return znakVar; }
        }
        /// <summary>
        /// Vrati je li znak zavrsni
        /// </summary>
        public bool zavrsni
        {
            get { return zavrsniVar; }
        }
        /// <summary>
        /// Vrati je li znak epsilon
        /// </summary>
        public bool epsilon
        {
            get { return epsilonVar; }
        }
    }

}

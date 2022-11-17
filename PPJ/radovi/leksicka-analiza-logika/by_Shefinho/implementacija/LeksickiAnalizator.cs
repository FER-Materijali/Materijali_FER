using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace SSP_PPJ_62
{
    class LeksickiAnalizator
    {
        private string buffer;

        public LeksickiAnalizator(string ulazniNiz) { buffer = ulazniNiz; }

        /// <summary>
        /// Trivijalna leksička analiza
        /// </summary>
        /// <returns>True ako je niz ispravan, inače false</returns>
        public bool Analiziraj()
        {
            bool OK = true;
            int i;
            
            for (i = 0; i < buffer.Length; i++)
            {
                if ( (buffer[i] != 'T') && (buffer[i] != 'F') && (buffer[i] != '(') && (buffer[i] != ')') &&
                     (buffer[i] != '+') && (buffer[i] != '*') && (buffer[i] != '~') )
                {
                    OK = false;
                    break;
                }
            }
            return OK;
        }
    }
}
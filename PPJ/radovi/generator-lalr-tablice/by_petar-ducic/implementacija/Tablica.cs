using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SSP
{
    class Redak_Tablica
    {
        public string naziv, stanje1, stanje2, zavrsni;
        public char prijelaz, nez_znak;
        public int stanje, komada;
        public Redak_Tablica(string produkcija)
        {
           naziv = produkcija;
        }
        public Redak_Tablica(string stanje, char pri, string sranje)
        {
            stanje1 = stanje;
            stanje2 = sranje;
            prijelaz = pri;
        }
        public Redak_Tablica(string stavka, string zav_znak)
        {
            naziv = stavka;
            zavrsni = zav_znak;
        }
        public Redak_Tablica(char znak, string zav_znak)
        {
            zavrsni = zav_znak;
            nez_znak = znak;
        }
        public Redak_Tablica(int st, int br)
        {
            komada=br;
            stanje = st; 
        }
   
    }

}

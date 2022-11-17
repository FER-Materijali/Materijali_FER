using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Hanojski_tornjevi
{
    //globalne varijable
    class Tornjevi
    {
        public static int brojDiskova;
        public static int odabirAlgoritma;
        public static int brojacIdentifikacijskogBroja; //ID cvora
        public static List<Cvor> otvoreniCvorovi = new List<Cvor>();
        public static List<Cvor> posjeceniCvorovi = new List<Cvor>();
        public static List<Cvor> ListaZaCrtati = new List<Cvor>();
       
        public Tornjevi()
       {
       }
    }
}

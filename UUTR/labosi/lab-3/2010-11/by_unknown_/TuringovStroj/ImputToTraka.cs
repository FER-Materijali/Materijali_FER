using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace TuringovStroj
{
    public static class ImputToTraka
    {
        public static List<List<ZnakTrake>> UlazniNizovi(String path, List<ZnakTrake> ulazniZnakoviAutomata)
        {
            List<List<ZnakTrake>> ulazniNizovi = new List<List<ZnakTrake>>();
            List<String> retci = FiletoLines.UcitajRetkeDatoteke(path);

            foreach (String redak in retci)
            {
                List<ZnakTrake> znakovi = new List<ZnakTrake>();

                foreach (Char ch in redak)
                {
                    foreach (ZnakTrake zn in ulazniZnakoviAutomata)
                    {
                        if (zn.Znak == ch.ToString())
                        {
                            znakovi.Add(zn);
                            break;
                        }
                    }
                }
                znakovi.AddRange(dodajTisucuPraznihZnakova(znakovi.Count));
                ulazniNizovi.Add(znakovi);
            }
            return ulazniNizovi;
        }

        private static List<ZnakTrake> dodajTisucuPraznihZnakova(int postojecih)
        {
            List<ZnakTrake> tisucuPraznih = new List<ZnakTrake>();

            for (int i = postojecih; i <= 1000; i++)
            {
                tisucuPraznih.Add(TS.PraznaCelija);
            }
            return tisucuPraznih;
        }

    }
}

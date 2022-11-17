using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TuringovStroj
{
    public static class FileToTS
    {
        public static void UcitajAutomatIzDatoteke(String path)
        {
            List<String> retciDatoteke = FiletoLines.UcitajRetkeDatoteke(path);
            TS.SkupStanja = ProcitajStanjeAutomata(retciDatoteke[0]);
            TS.SkupZnakovaTrake = ProcitajZnakoveTrake(retciDatoteke[1]);
            TS.PraznaCelija = ProcitajZnakPrazneCelije(retciDatoteke[2]); // Rješenje je u tome da ovdje u ovoj fji upotrijebiš onu prvu referencu
            TS.PocetnoStanje = PostaviPocetnoStanje(retciDatoteke[3], TS.SkupStanja);
            TS.SkupPrihvatljivihStnaja = PostaviPrihvatljivaStanja(retciDatoteke[4], TS.SkupStanja);
            TS.FunkcijePrijelaza = PostaviFunkcijeprijelaza(retciDatoteke);
        }

        private static List<FunkcijePrijelaza> PostaviFunkcijeprijelaza(List<string> retciDatoteke)
        {
            List<FunkcijePrijelaza> funkcije = new List<FunkcijePrijelaza>();
            for (int i = 5; i < retciDatoteke.Count; i++)
            {
                funkcije.Add(GenerirajPrijelazeZaRedak(retciDatoteke[i]));
            }
            return funkcije;
        }

        private static FunkcijePrijelaza GenerirajPrijelazeZaRedak(string redak)
        {
            FunkcijePrijelaza funkcija = new FunkcijePrijelaza();
            String[] polje = redak.Split(new String[] { "->" }, StringSplitOptions.None);
            String lijeviDio = polje[0];
            String desniDio = polje[1];

            String[] dvojka = lijeviDio.Split(',');

            Stanje trenutnoStnaje = null;
            ZnakTrake znakTrake = null;

            foreach (Stanje st in TS.SkupStanja)
            {
                if (st.Ime == dvojka[0])
                    trenutnoStnaje = st;
            }

            foreach (ZnakTrake zn in TS.SkupZnakovaTrake)
            {
                if (zn.Znak == dvojka[1])
                    znakTrake = zn;
            }

            String[] trojka = desniDio.Split(',');

            Stanje novoStanje = null;
            ZnakTrake noviZnakTrake = null;


            foreach (Stanje st in TS.SkupStanja)
            {
                if (st.Ime == trojka[0])
                    novoStanje = st;
            }

            foreach (ZnakTrake zn in TS.SkupZnakovaTrake)
            {
                if (zn.Znak == trojka[1])
                    noviZnakTrake = zn;
            }

            if (trojka[2] == "L")
                funkcija.Pomak = PomakGlave.Lijevo;
            else
                funkcija.Pomak = PomakGlave.Desno;

            funkcija.TrenutnoStanje = trenutnoStnaje;
            funkcija.ZnakNaTraci = znakTrake;
            funkcija.SljedeceStanje = novoStanje;
            funkcija.ZnakNaTraciNovi = noviZnakTrake;

            return funkcija;
        }

        private static List<Stanje> PostaviPrihvatljivaStanja(string prihvatljivaStanja, List<Stanje> skupStanja)
        {
            List<Stanje> svaPrihvatljivaStnja = new List<Stanje>();
            List<String> stanjaStringovi = prihvatljivaStanja.Split(',').ToList();

            foreach (Stanje st in skupStanja)
            {
                if (stanjaStringovi.Contains(st.Ime))
                    svaPrihvatljivaStnja.Add(st);
            }
            return svaPrihvatljivaStnja;
        }

        private static Stanje PostaviPocetnoStanje(string pocetnoStanje, List<Stanje> listaSvihStanja)
        {
            foreach (Stanje str in listaSvihStanja)
            {
                if (str.Ime == pocetnoStanje)
                {
                    return str;
                }
            }
            return null;

        }

        private static ZnakTrake ProcitajZnakPrazneCelije(string blankZnak)
        {
            foreach (ZnakTrake znak in TS.SkupZnakovaTrake)
            {
                if (znak.Znak == blankZnak)
                {
                    return znak;
                }
            }
            return null;
        }

        private static List<ZnakTrake> ProcitajZnakoveTrake(string redakSaZnakovimaTrake)
        {
            List<ZnakTrake> znakoviTrake = new List<ZnakTrake>();
            List<String> znakoviTrakeStringovi = redakSaZnakovimaTrake.Split(',').ToList();

            foreach (String str in znakoviTrakeStringovi)
            {
                znakoviTrake.Add(new ZnakTrake(str));
            }
            return znakoviTrake;
        }

        private static List<Stanje> ProcitajStanjeAutomata(string redakSaStanjima)
        {
            List<Stanje> ListaSaStanjima = new List<Stanje>();
            List<String> stanjaStringovi = redakSaStanjima.Split(',').ToList();

            foreach (String str in stanjaStringovi)
            {
                ListaSaStanjima.Add(new Stanje(str));
            }
            return ListaSaStanjima;
        }
    }
}

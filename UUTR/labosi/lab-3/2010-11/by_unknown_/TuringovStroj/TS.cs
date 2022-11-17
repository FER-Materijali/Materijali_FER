using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml.Serialization;

namespace TuringovStroj
{
    public class TS
    {
        public static List<Stanje> SkupStanja;
        public static List<ZnakTrake> SkupZnakovaTrake;
        public static ZnakTrake PraznaCelija;
        public static Stanje PocetnoStanje;
        public static List<FunkcijePrijelaza> FunkcijePrijelaza;
        public static List<Stanje> SkupPrihvatljivihStnaja;

        public Stanje TrenutnoStanje;
        public List<ZnakTrake> Traka;
        public Boolean NizPrihvaca = false;
        public int Glava = 0;
/*
        public void Simuliraj()
        {
            while (postojiPrijelaz(TrenutnoStanje, Traka, Glava))
            {
                Printer.StanjeAutomata(this);
                foreach (FunkcijePrijelaza funkcija in TS.FunkcijePrijelaza)
                {
                    if (funkcija.TrenutnoStanje == TrenutnoStanje && funkcija.ZnakNaTraci == Traka[Glava])
                    {
                        TrenutnoStanje = funkcija.SljedeceStanje;
                        Traka[Glava] = funkcija.ZnakNaTraciNovi;
                        if (funkcija.Pomak.Smijer == "L") Glava--;
                        else Glava++;

                        //ispisi prijelaz
                        Printer.Prijelaz(this, funkcija);

                        break;
                    }
                }
                if (TS.SkupPrihvatljivihStnaja.Contains(TrenutnoStanje))
                    NizPrihvaca = true;
            }
            Printer.RezultatSimulacije(this, NizPrihvaca);
        }
*/
/*
        private Boolean postojiPrijelaz(Stanje TrenutnoStanje, List<ZnakTrake> Traka, int Glava)
        {
            foreach (FunkcijePrijelaza funkcije in TS.FunkcijePrijelaza)
            {
                if (funkcije.TrenutnoStanje == TrenutnoStanje && funkcije.ZnakNaTraci == Traka[Glava])
                    return true;
            }
            return false;
        }
*/
        public void Simuliraj()
        {
            FunkcijePrijelaza prijelaz;
            TrenutnoStanje = TS.PocetnoStanje;

            try
            {
                while ((prijelaz = dohvatiPrijelaz()) != null)
                {
                    TrenutnoStanje = prijelaz.SljedeceStanje;
                    Traka[Glava] = prijelaz.ZnakNaTraciNovi;
                    Glava += (prijelaz.Pomak == PomakGlave.Lijevo ? -1 : 1);
                   /* if (Glava < 0)
                        Glava = 1;
                    */
                    Printer.Prijelaz(this, prijelaz);
                }
            }
            catch (IndexOutOfRangeException)
            {
                Printer.IspisiDaSiIzasaoIzTrake();
            }

            if (TS.SkupPrihvatljivihStnaja.Contains(TrenutnoStanje))
                NizPrihvaca = true;

            Printer.RezultatSimulacije(this, NizPrihvaca);
        }

        private FunkcijePrijelaza dohvatiPrijelaz()
        {
            foreach (FunkcijePrijelaza funkcija in TS.FunkcijePrijelaza)
            {
                if (funkcija.TrenutnoStanje == TrenutnoStanje && funkcija.ZnakNaTraci == Traka[Glava]) // ovdje  se ispituje pokazuju li na isti obj i to je pravilo probleme
                    return funkcija;
            }

            return null;
        }

    }
}

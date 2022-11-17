using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace TuringovStroj
{
    public static class Printer
    {
        private static StreamWriter writer;

        public static void PostaviIzlaznuDatoteku(String file)
        {
            writer = new StreamWriter(file);
        }
        public static void Prijelaz(TS automat, FunkcijePrijelaza prijelaz)
        {
                writer.WriteLine(prijelaz);
        }
        public static void RezultatSimulacije(TS automat, Boolean prihvacen)
        {
            writer.WriteLine(prihvacen ? "NIZ PRIHVACEN" : "NIZ ODBIJEN");
        }
        public static void StanjeAutomata(TS automat)
        {
            writer.WriteLine("({0})", automat.TrenutnoStanje);
        }
        public static void NemaPrijelaza(TS automat)
        {
            writer.WriteLine("Nema prijelaza za trenutni kontekst automata.");
        }
        public static void ZatvoriDatoteku()
        {
            if (writer != null)
                writer.Close();
        }
        public static void Zavrsetak()
        {
            return; // ovo moras dovrsiti jos....
        }

        public static void IspisiDaSiIzasaoIzTrake()
        {
            writer.WriteLine("Glava je izasla van trake");
        }
    }
}

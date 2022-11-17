using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.IO;

namespace TuringovStroj
{
    class Program
    {
        static void Main(string[] args)
        {
            FileToTS.UcitajAutomatIzDatoteke("automat.txt");
            List<List<ZnakTrake>>ulazniNizovi= ImputToTraka.UlazniNizovi("ulazi.txt", TS.SkupZnakovaTrake);
            obrisiPrivremenedatoteke();

            for (int i = 0; i < ulazniNizovi.Count; i++)
            {
                simulirajUlazniNiz(ulazniNizovi[i], i);
            }
        }

        private static void simulirajUlazniNiz(List<ZnakTrake> list,int i)
        {
 	        Printer.PostaviIzlaznuDatoteku("out-" + i + ".txt");
            TS mainTS = new TS();
            mainTS.Traka = list;
            mainTS.Simuliraj();
            Printer.ZatvoriDatoteku();
        }

        private static void obrisiPrivremenedatoteke()
        {
 	        List<FileInfo> textFiles = new DirectoryInfo(Directory.GetCurrentDirectory()).GetFiles("*.txt").ToList();
            foreach (FileInfo file in textFiles)
	        {
                if (file.Name.StartsWith("out-"))
                    file.Delete();
	        }
        }
    }
}

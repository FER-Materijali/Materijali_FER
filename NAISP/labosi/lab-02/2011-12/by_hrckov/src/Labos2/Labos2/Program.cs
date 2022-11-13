using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;
/*
	Napisati program (poželjno C, C++, C# ili Java) koji će genetskim algoritmom riješiti proizvoljan problem. 
	cilj je da student ovlada evolucijskom strategijom kao takvom pa problem sam po sebi može biti i vrlo jednostavan
    (npr. maksimizacija funkcije kao na predavanjima ili sl.), glavno da se vidi uspješnost usvajanja obrađenog gradiva
	za kolokviranje vježbe važno je pregledno i jasno opisati model problema i ideju rješenja, dakle građu kromosoma, 
    stvaranje polazne populacije, načine križanja i mutacija, kriterij vrednovanja jedinki, stvaranje nove generacije, 
    kontrolu konvergencije algoritma itd.
 * 
 * 
 * znacajke ovog GA su:  koristi se linearna normalizacija dobrote, vjerojatnost mutacije linearno raste sa svakom generacijom, 
 * odabrani bit uvijek mutira, elitizam najbolje jedinke, zabranjeno je stvaranje duplikata kromosoma, krizanje se izvodi
 * sa jednom perkidnom tockom, 

*/
namespace Labos2
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
    }
}

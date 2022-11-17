//#define debug

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

/*      tipovi zagrada
             * 1 = obična zagrada
             * 2 = zagrada sa epsilonom "$"
             * 3 = zagrada sa kleenom "()*" */
 
namespace SSP_Simulator_LEXa
{
    class MainClass
    {
        /*
         * Dvostruka lista "List<List<string>> prijelazi" sadrži liste prijelaza pojedinih
         * DKA automata koje se generiraju iz proizvoljno zadanih regularnih izraza. Pojedini DKA
         * obrađuje jedan regularni izraz.
         */
         
        static public List<List<string>> zagrade = new List<List<string>>();    // lista izraza u zagradama na 0-toj razini
        static public List<string> tipoviZagrada = new List<string>();          // lista tipova zagrada na 0-toj razini 
        static public List<string> prihvatljivostZagrada = new List<string>();  // lista prihvatljivosti zagrada -||-
        static public List<List<string>> prijelazi = new List<List<string>>();  // gorenavedeno :-}
        static public List<string> prihvatljivaStanja = new List<string>();     // lista prihvatljivih stanja za svaki DKA automat

        static void Main(string[] args)
        {
            string[] linije = File.ReadAllLines("regularniIzrazi.txt") ;
            string[] imenaDefinicije = new string[linije.Length] ;  // lijeve strane regularnih izraza
            string[] izrazDefinicije = new string[linije.Length] ;  // desne strane regularnih izraza
            int[] brojZagrada = new int[linije.Length] ;            // broj zagrada 0-te razine u pojedinom regularnom izrazu

            for (int i = 0; i < linije.Length; i++)
            {
                string[] pom = linije[i].Split(' ');
                imenaDefinicije[i] = pom[0];
                izrazDefinicije[i] = pom[1];
            }

            Parsiranje parsiranje = new Parsiranje() ;
            
            
            for ( int i = 0 ; i < linije.Length ; i++ )
            {
                brojZagrada[i] = parsiranje.odrediBrojITipZagrada(izrazDefinicije[i].ToCharArray(), i);
                parsiranje.odrediPrihvatljivost( tipoviZagrada[i].Replace(" ", "") );
                parsiranje.brojStanja = 0;
                parsiranje.parsirajIzraz(i); 
            }

            Simulator simulator = new Simulator();

            simulator.SimulatorMain();

#if debug

                for (int i = 0; i < linije.Length; i++)
                {
                    Console.WriteLine("\n   " + brojZagrada[i] + "   ");
                    Console.WriteLine("Tipovi : " + tipoviZagrada[i]);
                    Console.WriteLine("prihvatljivost zagrada --> " + prihvatljivostZagrada[i]);
                    Console.WriteLine("prihvatljiva stanja --> " + prihvatljivaStanja[i]);

                }
                foreach (List<string> lista in prijelazi)
                {
                    foreach (string str in lista)
                        Console.WriteLine(str);
                    Console.WriteLine("");
                }
#endif
                Console.WriteLine("\n\n\n               KRAJ!!!");
            Console.Read();
        }
    }
}

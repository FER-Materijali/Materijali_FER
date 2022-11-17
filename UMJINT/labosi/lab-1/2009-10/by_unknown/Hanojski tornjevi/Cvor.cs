using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Hanojski_tornjevi
{
    class Cvor
    {
        public int[][] naStapuDisk;
        public int identifikacijskiBroj;
        public int identifikacijskiBrojRoditelja;

        //rezerviranje memorije
        public Cvor() 
        {
            this.naStapuDisk = new int[3][];
            for (int stap = 0; stap < naStapuDisk.Length; stap++)
            {
                naStapuDisk[stap] = new int[Tornjevi.brojDiskova];
            }
        }

        //iscrtavanje cvora na ekran
        public static void crtajCvor(Cvor trenutniCvor)
        {
            for (int brojStapa = 1; brojStapa <= 3; brojStapa++)
            {
                Console.Write("\n" + brojStapa + ". stap  I-");
                for (int brojDiska = Tornjevi.brojDiskova; brojDiska > 0; brojDiska--)
                {
                    if (trenutniCvor.naStapuDisk[brojStapa-1][brojDiska-1] == 1)
                        Console.Write(brojDiska);
                }
                Console.WriteLine("\n\n");
                
            }
            // Console.WriteLine("\n");
        }
        
        //uspoređuje čvorove, vraća false ako nisu jednaki, inače true
        public bool jednak(Cvor trenutniCvor)
        {
            for(int brojStapa = 0; brojStapa < 3; brojStapa++)
            {
                for(int brojDiska = 0 ; brojDiska< Tornjevi.brojDiskova ; brojDiska++)
                {
                    if (this.naStapuDisk[brojStapa][brojDiska] != trenutniCvor.naStapuDisk[brojStapa][brojDiska])
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        
    }
    
}

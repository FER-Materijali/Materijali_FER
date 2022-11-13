using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        

        static void Main(string[] args)
        {
            AVL avl = new AVL();
            TextReader tr;
            string datoteka= "C:\\Users\\zvone\\Desktop\\faks\\4.god\\1.semestar\\NASP\\labosi\\brojevi.txt";
            try
            {
                datoteka = args[0];
            }
            catch
            {
                
            }
            try
            {
                tr = File.OpenText(datoteka);
            }
            catch
            {
                return;
            }

            

            
            string redak;
            redak = tr.ReadLine();
            while (redak != null)
            {
                avl.add(int.Parse(redak));
                redak = tr.ReadLine();
            }
            
            avl.preOrder();
            while (true)
            {
                Console.WriteLine("Upisite broj koji zelite upisati");
                try
                {
                    int broj = Convert.ToInt32(Console.ReadLine());
                    avl.add(broj);
                    avl.preOrder();
                }
                catch
                {
                    Console.WriteLine("Krivo uneseni podatak");
                }
            }
        }
    }
}

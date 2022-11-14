using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOuP2lab6
{
    class Program
    {
        static void Main(string[] args)
        {
            MyDBase db = new ConcDBase();
            LoggingDecorator ld = new LoggingDecorator("var/tmp/mybase.log", db);
            ExceptionDecorator ed = new ExceptionDecorator(ld);
            
            MyDBase.Param upit;
            upit.table = "Posao";
            upit.column = "NazPgrešaosao";
            upit.key = "zguba";

            try
            {
                ed.Query(upit);
            }
            catch
            {
                Console.WriteLine("Iznimka u izvrsavanju upita");
            }

            Console.ReadLine();
        }
    }
}

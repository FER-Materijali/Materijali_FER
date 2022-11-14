using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
namespace OOuP2lab6
{
    class LoggingDecorator : Decorator
    {
        private StreamWriter writer;

        public LoggingDecorator(string file, MyDBase dbase) : base(dbase)
        {
            writer = new StreamWriter(file, true);
        }

        public override int Query(Param p)
        {
            writer.WriteLine("Upit:"+p.table+" "+p.column+" "+p.key);
            writer.Flush();
            return database.Query(p);
        }
    }
}

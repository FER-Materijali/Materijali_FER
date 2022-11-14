using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOuP2lab6
{
    abstract class Decorator : MyDBase
    {
        public MyDBase database;

        public Decorator(MyDBase myDBase)
        {
            database = myDBase;
        }
    }
}

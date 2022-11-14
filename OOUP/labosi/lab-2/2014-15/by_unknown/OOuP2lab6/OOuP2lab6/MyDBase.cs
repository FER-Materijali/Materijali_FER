using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOuP2lab6
{
    abstract class MyDBase
    {
        public struct Param
        {
            public string table;
            public string column;
            public string key;
        }
        public abstract int Query(Param p);
    }
}

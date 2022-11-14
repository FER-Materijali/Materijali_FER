using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOuP2lab6
{
    class ExceptionDecorator : Decorator
    {
        public ExceptionDecorator(MyDBase dbase)
            : base(dbase)
        {
        }

        public override int Query(Param p)
        {
            int i = database.Query(p);
            if (i < 0)
            {
                throw new Exception();
            }
            return i;
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOuP2lab6
{
    class ConcDBase : MyDBase
    {
        List<Param> data;
        public ConcDBase() : base()
        {
            //ovo je neka nepotrebna glupost samo eto tako da Query ima neku svrhu osim returnanja -1 ili 0
            data = new List<Param>();
            Param upit = new Param();
            upit.table = "Posao";
            upit.column = "NazPosao";
            upit.key = "zguba";
            data.Add(upit);
            Param a = new Param();
            a.table = "Posao";
            a.column = "NazPosao";
            a.key = "skola";
            data.Add(a);

        }

        public override int Query(Param p)
        {
            if (data.Contains(p))
            {
                return 0;
            }
            else
            {
                return -1;
            }
        }
    }
}

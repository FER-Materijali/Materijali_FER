using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
namespace OOuP2lab5
{
    class ZapisnikDatuma : Observer
    {
        private StreamWriter writer;

        public ZapisnikDatuma(SlijedBrojeva sb) : base(sb)
        {
            writer = new StreamWriter("log.txt", true);
        }

        public override void Update()
        {
            writer.Write(DateTime.Now.ToString());
            foreach (int i in slijedBrojeva.dajBrojeve())
            {
                writer.Write(i+" ");
            }
            writer.WriteLine("");
            writer.Flush();
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOuP2lab5
{
    class TipkovnickiIzvor : IIzvorBrojeva
    {
        public TipkovnickiIzvor()
        {

        }

        public int UcitajBroj()
        {
            try
            {
                Console.Write("Broj sa tipkovnice:");
                return int.Parse(Console.ReadLine());
            }
            catch
            {
                return -1;
            }
            //return -1;
        }
    }
}

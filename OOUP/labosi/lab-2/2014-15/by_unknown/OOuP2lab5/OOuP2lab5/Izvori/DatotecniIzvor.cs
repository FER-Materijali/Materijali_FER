using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
namespace OOuP2lab5
{
    class DatotecniIzvor : IIzvorBrojeva
    {
        private StreamReader reader;

        public DatotecniIzvor(string file)
        {
            try
            {
                reader = new StreamReader(file);
            }
            catch
            {
                Console.WriteLine("Pogreška učitavanja izvora");
            }
        }
        public int UcitajBroj()
        {
            string line;
            if ((line = reader.ReadLine()) != null)
            {
                try{
                    return int.Parse(line);
                }
                catch{
                    return -1;
                }
            }
            else
            {
                return -1;
            }
            
        }
    }
}

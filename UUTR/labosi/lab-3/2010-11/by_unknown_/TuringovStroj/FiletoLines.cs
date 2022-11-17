using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace TuringovStroj
{
    public static class FiletoLines
    {
        public static List<String> UcitajRetkeDatoteke(String path)
        {
            List<String> retciDatoteke = new List<string>();

            using (StreamReader file = new StreamReader(path))
            {
                while (true)
                {
                    String line = file.ReadLine();
                    if (line != null)
                        retciDatoteke.Add(line);
                    else
                        break;
                }
            }
            return retciDatoteke;
        }
    }
}

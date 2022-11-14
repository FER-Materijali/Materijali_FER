using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOuP2lab5
{
    class Program
    {
        static void Main(string[] args)
        {
            SlijedBrojeva sb = new SlijedBrojeva(new DatotecniIzvor("izvor.txt"));
            ZapisnikDatuma zd = new ZapisnikDatuma(sb);
            IspisSume is_ = new IspisSume(sb);
            IspisProsjeka ip = new IspisProsjeka(sb);
            IspisMedijana im = new IspisMedijana(sb);
            sb.Kreni();
            Console.ReadLine();
        }
    }
}

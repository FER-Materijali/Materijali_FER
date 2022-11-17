using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TuringovStroj
{
    public class FunkcijePrijelaza
    {
        public Stanje TrenutnoStanje;
        public ZnakTrake ZnakNaTraci;

        public Stanje SljedeceStanje;
        public ZnakTrake ZnakNaTraciNovi;
        public PomakGlave Pomak;

        public override string ToString()
        {
            return String.Format("{0},{1}->{2},{3},{4}", TrenutnoStanje, ZnakNaTraci,
                SljedeceStanje, ZnakNaTraciNovi, Pomak);
        }
    }
}

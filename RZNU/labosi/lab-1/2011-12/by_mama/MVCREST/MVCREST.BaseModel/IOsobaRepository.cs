using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MVCREST.BaseModel
{
    public interface IOsobaRepository
    {
        void Dodaj(Osoba inOsoba);
        Osoba Dohvati(long inId);
        List<Osoba> DohvatiSve();
    }
}

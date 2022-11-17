using System;
using System.Collections.Generic;
using System.Text;
using System.Data;

using NTier;

namespace Firma
{
  // Poslovni objekt za listu mjesta
  public class MjestoList : BusinessBaseList<Mjesto>
  {
    #region Constructors & Init
    public MjestoList()
    {
    }

    // Kreira listu objekata èitanjem podataka iz baze
    public static MjestoList CreateNew(IDataReader dr)
    {
      MjestoList rez = new MjestoList();
      while (dr.Read())
      {
        rez.Add(Mjesto.CreateNew(dr));
      }
      return rez;
    }
    #endregion
  }
}

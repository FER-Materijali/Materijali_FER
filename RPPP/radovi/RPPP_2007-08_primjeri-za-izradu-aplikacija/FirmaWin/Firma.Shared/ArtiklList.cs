using System;
using System.Collections.Generic;
using System.Text;
using System.Data;

using NTier;

namespace Firma
{
  // Poslovni objekt za listu artikala
  public class ArtiklList : BusinessBaseList<Artikl>
  {
    #region Constructors & Init
    public ArtiklList()
    {
    }

    // Kreira listu objekata èitanjem podataka iz baze
    public static ArtiklList CreateNew(IDataReader dr)
    {
      ArtiklList rez = new ArtiklList();
      while (dr.Read())
      {
        rez.Add(Artikl.CreateNew(dr));
      }
      return rez;
    }
    #endregion
  }
}

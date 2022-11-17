using System;
using System.Collections.Generic;
using System.Text;
using System.Data;

using NTier;

namespace Firma
{
  // Poslovni objekt za listu stavaka
  public class StavkaList : BusinessBaseList<Stavka>
  {
    #region Constructors & Init
    public StavkaList()
    {
    }

    // Kreira listu objekata èitanjem podataka iz baze
    public static StavkaList CreateNew(IDataReader dr)
    {
      StavkaList rez = new StavkaList();
      while (dr.Read())
      {
        rez.Add(Stavka.CreateNew(dr));
      }
      return rez;
    }
    #endregion
  }
}

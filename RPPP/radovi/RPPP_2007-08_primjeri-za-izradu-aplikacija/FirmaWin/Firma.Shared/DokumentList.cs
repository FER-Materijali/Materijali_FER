using System;
using System.Collections.Generic;
using System.Text;
using System.Data;

using NTier;

namespace Firma
{
  // Poslovni objekt za listu dokumenata
  public class DokumentList : BusinessBaseList<Dokument>
  {
    #region Constructors & Init
    public DokumentList()
    {
    }

    // Kreira listu objekata èitanjem podataka iz baze
    public static DokumentList CreateNew(IDataReader dr, IStavkaDalProvider stavkaDalProvider)
    {
      DokumentList rez = new DokumentList();
      if (dr != null)
      {
        while (dr.Read())
        {
          Dokument item = new Dokument();
          item.Load(dr, stavkaDalProvider);
          rez.Add(item);
        }
      }
      return rez;
    }
    #endregion
  }
}

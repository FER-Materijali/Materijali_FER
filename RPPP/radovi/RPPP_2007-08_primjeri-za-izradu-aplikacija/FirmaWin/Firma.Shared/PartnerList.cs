using System;
using System.Collections.Generic;
using System.Text;
using System.Data;

using NTier;

namespace Firma
{
  // Poslovni objekt za listu partnera
  public class PartnerList : BusinessBaseList<Partner>
  {
    #region Constructors & Init
    public PartnerList()
    {
    }

    // Kreira listu objekata èitanjem podataka iz baze
    public static PartnerList CreateNew(IDataReader dr)
    {
      PartnerList rez = new PartnerList();
      while (dr.Read())
      {
        rez.Add(Partner.CreateNew(dr));
      }
      return rez;
    }
    #endregion
  }
}

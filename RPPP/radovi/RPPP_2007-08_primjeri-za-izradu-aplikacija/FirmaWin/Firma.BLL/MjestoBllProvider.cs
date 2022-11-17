using System;
using System.Collections.Generic;
using System.Text;
using System.Collections;

using NTier;

namespace Firma
{
  // BLL klasa za mjesto
  public class MjestoBllProvider : IBllObject
  {
    #region DAL Object
    // DAL sloj
    private MjestoDalProvider dal = new MjestoDalProvider();
    #endregion

    #region Fetch
    // Dohvat mjesta po razlièitim kriterijima
    
    public MjestoList FetchAll()
    {
      return dal.FetchAll();
    }

    public Mjesto Fetch(int idMjesta)
    {
      return dal.Fetch(idMjesta);
    }
    #endregion

    #region SaveChanges
    // Spremanje izmjena
    public void SaveChanges(IList changedItems)
    {
      foreach (Mjesto item in changedItems)
      {
        // Ako je poslovni objekt izmijenjen validiraj ispravnost objekta.
        // Ako objekt nije ispravan bacit æe se exception.
        if (item.IsDirty && (item.State == BusinessObjectState.New 
          || item.State == BusinessObjectState.Modified))
          Validate(item);
      }

      // Proslijedi DAL sloju na spremanje u bazu
      dal.SaveChanges((List<Mjesto>)changedItems);
    }
    #endregion

    #region Business Rules
    public void Validate(Mjesto target)
    {
      // Nije implementirano 
    }

    public void Validate(object businessObject, string propertyName)
    {
      // Nije implementirano 
    }
    #endregion
  }
}

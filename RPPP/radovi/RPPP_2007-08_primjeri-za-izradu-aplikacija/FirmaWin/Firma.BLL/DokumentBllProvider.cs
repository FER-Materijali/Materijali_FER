using System;
using System.Collections.Generic;
using System.Text;
using System.Collections;

using NTier;

namespace Firma
{
  // BLL klasa za dokument
  public class DokumentBllProvider : IBllObject
  {
    #region DAL Object
    // DAL sloj
    private DokumentDalProvider dal = new DokumentDalProvider();
    #endregion

    #region Fetch
    // Dohvat dokumenta po razlièitim kriterijima

    public DokumentList FetchAll()
    {
      return dal.FetchAll();
    }

    public Dokument Fetch(int brDokumenta, string vrDokumenta)
    {
      return dal.Fetch(brDokumenta, vrDokumenta);
    }

    public Dokument Fetch(int idDokumenta)
    {
      return dal.Fetch(idDokumenta);
    }
    #endregion

    #region SaveChanges
    // Spremanje izmjena
    public void SaveChanges(IList changedItems)
    {
      foreach (Dokument item in changedItems)
      {
        // Ako je poslovni objekt izmijenjen validiraj ispravnost objekta.
        // Ako objekt nije ispravan bacit æe se exception.
        if (item.IsDirty && (item.State == BusinessObjectState.New
                          || item.State == BusinessObjectState.Modified))
          Validate(item);
      }

      // Proslijedi DAL sloju na spremanje u bazu
      dal.SaveChanges((List<Dokument>)changedItems);
    }
    #endregion

    #region Business Rules
    // Validacija svih svojstava poslovnog objekta
    public void Validate(Dokument target)
    {
      Validate(target, "BrDokumenta");
      Validate(target, "VrDokumenta");
      Validate(target, "DatDokumenta");
      Validate(target, "IdPartnera");
      Validate(target, "IdPrethDokumenta");
      Validate(target, "PostoPorez");
    }

    // Validacija pojedinog svojstva poslovnog objekta. Ukoliko
    // poslovno pravilo nije zadovoljeno, metoda baca iznimku.
    public void Validate(object businessObject, string propertyName)
    {
      Dokument target = (Dokument)businessObject;

      switch (propertyName)
      {
        case "BrDokumenta":
          {
            if (!target.BrDokumenta.HasValue)
              throw new Exception("Broj dokumenta je obavezno polje!");

            if (target.State == BusinessObjectState.New)
            {
              if (!string.IsNullOrEmpty(target.VrDokumenta) 
                && Fetch(target.BrDokumenta.Value, target.VrDokumenta) != null)
                throw new Exception("Dokument veæ postoji!");
            }

            break;
          }
        case "VrDokumenta":
          {
            if (string.IsNullOrEmpty(target.VrDokumenta))
              throw new Exception("Vrsta dokumenta je obavezno polje!");

            if (target.State == BusinessObjectState.New)
            {
              if (target.BrDokumenta.HasValue 
                && Fetch(target.BrDokumenta.Value, target.VrDokumenta) != null)
                throw new Exception("Dokument veæ postoji!");
            }

            break;
          }
        case "DatDokumenta":
          {
            if (!target.DatDokumenta.HasValue)
              throw new Exception("Datum je obavezno polje!");

            break;
          }
        case "IdPartnera":
          {
            if (!target.IdPartnera.HasValue)
              throw new Exception("Partner je obavezno polje!");

            if ((new PartnerBllProvider()).Fetch(target.IdPartnera.Value) == null)
              throw new Exception("Partner ne postoji!");

            break;
          }
        case "IdPrethDokumenta":
          {
            if (target.IdPrethDokumenta.HasValue 
              && Fetch(target.IdPrethDokumenta.Value) == null)
              throw new Exception("Dokument ne postoji!");

            break;
          }
        case "PostoPorez":
          {
            if (target.PostoPorez.HasValue
              && target.PostoPorez.Value < 0)
              throw new Exception("Neispravan porez!");

            break;
          }
        default: break;
      }
    }
    #endregion
  }
}

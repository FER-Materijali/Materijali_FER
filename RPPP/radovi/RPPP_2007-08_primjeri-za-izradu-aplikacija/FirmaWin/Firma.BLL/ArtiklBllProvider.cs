using System;
using System.Collections.Generic;
using System.Text;
using System.Collections;

using NTier;

namespace Firma
{
  // BLL klasa za artikl
  public class ArtiklBllProvider : IBllObject
  {
    #region DAL Object
    // DAL sloj
    private ArtiklDalProvider dal = new ArtiklDalProvider();
    #endregion

    #region Fetch
    // Dohvat artikla po razlièitim kriterijima

    public ArtiklList FetchAll()
    {
      return dal.FetchAll();
    }

    public Artikl Fetch(int sifArtikla)
    {
      return dal.Fetch(sifArtikla);
    }

    public Artikl Fetch(string nazArtikla)
    {
      return dal.Fetch(nazArtikla);
    }
    #endregion

    #region SaveChanges
    // Spremanje izmjena
    public void SaveChanges(IList changedItems)
    {
      foreach (Artikl item in changedItems)
      {
        // Ako je poslovni objekt izmijenjen validiraj ispravnost objekta.
        // Ako objekt nije ispravan bacit æe se exception.
        if (item.IsDirty && (item.State == BusinessObjectState.New 
                         || item.State == BusinessObjectState.Modified))
          Validate(item);
      }

      // Proslijedi DAL sloju na spremanje u bazu
      dal.SaveChanges((List<Artikl>)changedItems);
    }
    #endregion

    #region Business Rules
    // Validacija svih svojstava poslovnog objekta
    public void Validate(Artikl target)
    {
      Validate(target, "SifArtikla");
      Validate(target, "NazArtikla");
      Validate(target, "JedMjere");
      Validate(target, "CijArtikla");
      Validate(target, "ZastUsluga");
      Validate(target, "SlikaArtikla");
    }

    // Validacija pojedinog svojstva poslovnog objekta. 
    // Ukoliko poslovno pravilo nije zadovoljeno, metoda baca iznimku.
    public void Validate(object businessObject, string propertyName)
    {
      Artikl target = (Artikl)businessObject;

      switch (propertyName)
      {
        case "SifArtikla":
          {
            if (!target.SifArtikla.HasValue)
              throw new Exception("Šifra artikla je obavezno polje!");

            if (target.State == BusinessObjectState.New)
            {
              Artikl a = Fetch(target.SifArtikla.Value);
              if (a != null)
                throw new Exception(string.Format("Artikl {0} veæ postoji.", a.SifArtikla.Value));
            }

            break;
          }
      case "NazArtikla":
          {
            if (string.IsNullOrEmpty(target.NazArtikla))
              throw new Exception("Naziv artikla je obavezno polje!");

            if (target.State == BusinessObjectState.New 
              || (!string.IsNullOrEmpty(target.NazArtiklaOriginal) && !target.NazArtikla.Equals(target.NazArtiklaOriginal)))
            {
              Artikl a = Fetch(target.NazArtikla.Trim());
              if (a != null)
                throw new Exception(string.Format("Artikl '{0}' veæ postoji!", a.SifArtikla.Value));
            }

            if (target.NazArtikla.Length > 255)
              throw new Exception(string.Format("Maksimalna duljina naziva je {0}.", 255));

            break;
          }
        case "JedMjere":
          {
            if (string.IsNullOrEmpty(target.JedMjere))
              throw new Exception("Jedinica mjere je obavezno polje!");

            if (target.NazArtikla.Length > 255)
              throw new Exception(string.Format("Maksimalna duljina je {0}.", 255));

            break;
          }
        case "CijArtikla":
          {
            if (!target.CijArtikla.HasValue || target.CijArtikla.Value <= 0)
              throw new Exception("Cijena mora biti veæa od 0!");

            break;
          }
        default: break;
      }
    }
    #endregion
  }
}

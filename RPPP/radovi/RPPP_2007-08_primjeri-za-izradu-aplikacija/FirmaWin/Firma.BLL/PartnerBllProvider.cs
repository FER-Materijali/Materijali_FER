using System;
using System.Collections.Generic;
using System.Text;
using System.Collections;

using NTier;

namespace Firma
{
  // BLL klasa za partnera
  public class PartnerBllProvider : IBllObject
  {
    #region DAL Object
    // DAL sloj
    private PartnerDalProvider dal = new PartnerDalProvider();
    #endregion

    #region Fetch
    // Dohvat partnera po razlièitim kriterijima

    public PartnerList FetchAll()
    {
      return dal.FetchAll();
    }

    public Partner Fetch(int idPartnera)
    {
      return dal.Fetch(idPartnera);
    }

    public Partner FetchByJMBG(string jmbg)
    {
      return dal.FetchByJMBG(jmbg);
    }

    public Partner FetchByMatBr(string matBr)
    {
      return dal.FetchByMatBr(matBr);
    }
    #endregion

    #region SaveChanges
    // Spremanje izmjena
    public void SaveChanges(IList changedItems)
    {
      foreach (Partner item in changedItems)
      {
        // Ako je poslovni objekt izmijenjen validiraj ispravnost objekta.
        // Ako objekt nije ispravan bacit æe se exception.
        if (item.IsDirty && (item.State == BusinessObjectState.New
                          || item.State == BusinessObjectState.Modified))
          Validate(item);
      }

      // Proslijedi DAL sloju na spremanje u bazu
      dal.SaveChanges((List<Partner>)changedItems);
    }
    #endregion

    #region Business Rules
    // Validacija svih svojstava poslovnog objekta
    public void Validate(Partner target)
    {
      Validate(target, "IdPartnera");
      Validate(target, "TipPartnera");
      Validate(target, "IdMjestaPartnera");
      Validate(target, "AdrPartnera");
      Validate(target, "IdMjestaIsporuke");
      Validate(target, "AdrIsporuke");

      Validate(target, "JMBG");
      Validate(target, "PrezimeOsobe");
      Validate(target, "ImeOsobe");

      Validate(target, "MatBrTvrtke");
      Validate(target, "NazivTvrtke");
    }

    // Validacija pojedinog svojstva poslovnog objekta. Ukoliko
    // poslovno pravilo nije zadovoljeno, metoda baca iznimku.
    public void Validate(object businessObject, string propertyName)
    {
      Partner target = (Partner)businessObject;

      switch (propertyName)
      {
        case "TipPartnera":
          {
            if (target.TipPartnera == TipPartnera.Nedefinirano)
              throw new Exception("Tip partnera je obavezno polje!");

            break;
          }
        case "IdMjestaPartnera":
          {
            if (target.IdMjestaPartnera.HasValue
              && (new MjestoBllProvider()).Fetch(target.IdMjestaPartnera.Value) == null)
              throw new Exception("Mjesto ne postoji!");

            break;
          }
        case "IdMjestaIsporuke":
          {
            if (target.IdMjestaIsporuke.HasValue
              && (new MjestoBllProvider()).Fetch(target.IdMjestaIsporuke.Value) == null)
              throw new Exception("Mjesto ne postoji!");

            break;
          }
        case "AdrPartnera":
          {
            if (!string.IsNullOrEmpty(target.AdrPartnera) && target.AdrPartnera.Length > 50)
              throw new Exception(string.Format("Maksimalna duljina je {0}.", 50));

            break;
          }
        case "AdrIsporuke":
          {
            if (!string.IsNullOrEmpty(target.AdrIsporuke) && target.AdrIsporuke.Length > 50)
              throw new Exception(string.Format("Maksimalna duljina je {0}.", 50));

            break;
          }
        case "JMBG":
          {
            if (target.TipPartnera == TipPartnera.Osoba)
            {
              if (string.IsNullOrEmpty(target.JMBG))
                throw new Exception("JMBG je obavezno polje!");

              if (target.JMBG.Length != 13)
                throw new Exception(string.Format("Duljina JMBG treba biti {0}.", 13));

              if (!System.Text.RegularExpressions.Regex.IsMatch(target.JMBG, "^[0-9]*$"))
                throw new Exception("Neispravan unos!");

              Partner p = FetchByJMBG(target.JMBG);
              if (p != null)
              {
                if (target.State == BusinessObjectState.New
                  || target.State == BusinessObjectState.Modified && !p.IdPartnera.Equals(target.IdPartnera))
                  throw new Exception("Partner s istim JMBG veæ postoji!");
              }

            }
            break;
          }
        case "PrezimeOsobe":
          {
            if (target.TipPartnera == TipPartnera.Osoba)
            {
              if (string.IsNullOrEmpty(target.PrezimeOsobe))
                throw new Exception("Prezime osobe je obavezno polje!");

              if (target.PrezimeOsobe.Length > 20)
                throw new Exception(string.Format("Maksimalna duljina je {0}.", 20));
            }
            break;
          }
        case "ImeOsobe":
          {
            if (target.TipPartnera == TipPartnera.Osoba)
            {
              if (string.IsNullOrEmpty(target.ImeOsobe))
                throw new Exception("Ime osobe je obavezno polje!");

              if (target.ImeOsobe.Length > 20)
                throw new Exception(string.Format("Maksimalna duljina je {0}.", 20));
            }
            break;
          }
        case "MatBrTvrtke":
          {
            if (target.TipPartnera == TipPartnera.Tvrtka)
            {
              if (string.IsNullOrEmpty(target.MatBrTvrtke))
                throw new Exception("Matièni broj je obavezno polje!");

              if (target.MatBrTvrtke.Length > 30)
                throw new Exception(string.Format("Maksimalna duljina je {0}.", 30));

              if (!System.Text.RegularExpressions.Regex.IsMatch(target.MatBrTvrtke, "^[0-9]*$"))
                throw new Exception("Neispravan unos!");

              Partner p = FetchByMatBr(target.MatBrTvrtke);
              if (p != null)
              {
                if (target.State == BusinessObjectState.New
                  || target.State == BusinessObjectState.Modified && !p.IdPartnera.Equals(target.IdPartnera))
                  throw new Exception("Partner s istim matiènim brojem veæ postoji!");
              }
            }
            break;
          }
        case "NazivTvrtke":
          {
            if (target.TipPartnera == TipPartnera.Tvrtka)
            {
              if (string.IsNullOrEmpty(target.NazivTvrtke))
                throw new Exception("Naziv tvrtke je obavezno polje!");

              if (target.NazivTvrtke.Length > 50)
                throw new Exception(string.Format("Maksimalna duljina je {0}.", 50));
            }
            break;
          }
        default: break;
      }
    }
    #endregion
  }
}

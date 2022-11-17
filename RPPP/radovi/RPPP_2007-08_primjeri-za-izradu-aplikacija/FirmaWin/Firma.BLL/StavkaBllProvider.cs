using System;
using System.Collections.Generic;
using System.Text;
using System.Collections;

using NTier;

namespace Firma
{
  // BLL klasa za partnera
  public class StavkaBllProvider : IBllObject
  {
    #region DAL Object
    // Ne koristi se jer sa spremanjem i dohvatom stavaka rukuje zaglavlje
    #endregion

    #region Fetch
    // Ne koristi se jer sa spremanjem i dohvatom stavaka rukuje zaglavlje
    #endregion

    #region SaveChanges
    public void SaveChanges(IList changes)
    {
      // Ne koristi se jer sa spremanjem i dohvatom stavaka rukuje zaglavlje
      throw new NotSupportedException();
    }
    #endregion

    #region Business Rules
    // Validacija svih svojstava poslovnog objekta
    public void Validate(Artikl target)
    {
      Validate(target, "JedCijArtikla");
      Validate(target, "KolArtikla");
      Validate(target, "PostoRabat");
    }

    // Validacija pojedinog svojstva poslovnog objekta. Ukoliko
    // poslovno pravilo nije zadovoljeno, metoda baca iznimku.
    public void Validate(object businessObject, string propertyName)
    {
      Stavka target = (Stavka)businessObject;

      switch (propertyName)
      {
        case "JedCijArtikla":
          {
            if (!target.JedCijArtikla.HasValue)
              throw new Exception("Cijena je obavezno polje!");

            if (target.JedCijArtikla.Value < 0)
              throw new Exception("Neispravan unos!");

            break;
          }
        case "KolArtikla":
          {
            if (!target.KolArtikla.HasValue)
              throw new Exception("Kolièina je obavezno polje!");

            if (target.KolArtikla.Value < 0)
              throw new Exception("Neispravan unos!");

            break;
          }
        case "PostoRabat":
          {
            if (!target.PostoRabat.HasValue)
              throw new Exception("Rabat je obavezno polje!");

            if (target.PostoRabat.Value < 0)
              throw new Exception("Neispravan unos!");

            break;
          }
        default: break;
      }
    }
    #endregion
  }
}

using System;
using System.Collections.Generic;
using System.Text;
using System.Data;

using NTier;

namespace Firma
{
  // Poslovni objekt mjesta
  public class Mjesto : BusinessBase
  {
    #region Constructors
    public Mjesto()
    {
    }

    // Stvara novi objekt èitanjem iz podataka baze
    public static Mjesto CreateNew(IDataReader dr)
    {
      Mjesto rez = new Mjesto();
      rez.Load(dr);
      return rez;
    }
    #endregion

    #region Load
    // punjenje instance podacima it èitaèa
    protected override void DoLoad(IDataReader dr)
    {
      this.idMjesta = dr["IdMjesta"] == DBNull.Value ? (int?)null : (int?)dr["IdMjesta"];
      this.oznDrzave = dr["OznDrzave"] == DBNull.Value ? string.Empty : (string)dr["OznDrzave"];
      this.nazMjesta = dr["NazMjesta"] == DBNull.Value ? string.Empty : (string)dr["NazMjesta"];
      this.postBrMjesta = dr["PostBrMjesta"] == DBNull.Value ? (int?)null : (int?)dr["PostBrMjesta"];
      this.postNazMjesta = dr["PostNazMjesta"] == DBNull.Value ? string.Empty : (string)dr["PostNazMjesta"];
      this.nazDrzave = dr["NazDrzave"] == DBNull.Value ? string.Empty : (string)dr["NazDrzave"];
    }
    #endregion

    #region Fields
    // Polja u bazi
    private int? idMjesta;
    private string oznDrzave = string.Empty;
    private string nazMjesta = string.Empty;
    private int? postBrMjesta;
    private string postNazMjesta = string.Empty;
    private string nazDrzave = string.Empty;
    #endregion

    #region Properties
    public int? IdMjesta
    {
      get { return idMjesta; }
      set
      {
        if (InEditMode)
        {
          idMjesta = value;
          PropertyHasChanged("IdMjesta");
        }
      }
    }

    public string OznDrzave
    {
      get { return oznDrzave; }
      set
      {
        if (InEditMode)
        {
          oznDrzave = value;
          PropertyHasChanged("OznDrzave");
        }
      }
    }

    public string NazMjesta
    {
      get { return nazMjesta; }
      set
      {
        if (InEditMode)
        {
          nazMjesta = value;
          PropertyHasChanged("NazMjesta");
        }
      }
    }

    public int? PostBrMjesta
    {
      get { return postBrMjesta; }
      set
      {
        if (InEditMode)
        {
          postBrMjesta = value;
          PropertyHasChanged("PostBrMjesta");
        }
      }
    }

    public string PostNazMjesta
    {
      get { return postNazMjesta; }
      set
      {
        if (InEditMode)
        {
          postNazMjesta = value;
          PropertyHasChanged("PostNazMjesta");
        }
      }
    }

    public string NazDrzave
    {
      get { return nazDrzave; }
      set
      {
        if (InEditMode)
        {
          nazDrzave = value;
          PropertyHasChanged("NazDrzave");
        }
      }
    }

    // polja za povezivanje na combo box (Lookup)
    public string DisplayText
    {
      get
      {
        return string.Format("{0}, {1}, {2} ({3})", NazMjesta, PostBrMjesta, OznDrzave, NazDrzave);
      }
    }
    #endregion

    #region Backup / Restore
    // Pohrana originalnih vrijednosti kako bi se mogao napraviti
    // poništenje unosa
    protected override void DoBackup(object backupObject)
    {
      // Nije implementirano jer se u primjeru ne obavlja spremanje/izmjena 
      throw new NotImplementedException();
    }

    // Vraæanje originalnih vrijednosti (poništenje izmjena)
    protected override void DoRestore(object backupObject)
    {
      // Nije implementirano jer se u primjeru ne obavlja spremanje/izmjena 
      throw new NotImplementedException();
    }
    #endregion

    #region Validation
    // Validacija svih svojstava poslovnog objekta
    public override void Validate()
    {
      // Nije implementirano jer se u primjeru ne obavlja spremanje/izmjena 
      throw new NotImplementedException();
    }
    #endregion

    #region Object Overrides
    public override string ToString()
    {
      return DisplayText;
    }
    #endregion
  }
}

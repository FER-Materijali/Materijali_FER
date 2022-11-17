using System;
using System.Collections.Generic;
using System.Text;
using System.Data;

using NTier;

namespace Firma
{
  // Poslovni objekt poslovnog partnera
  public class Partner : BusinessBase
  {
    #region Constructors
    public Partner()
    {
    }

    // Stvara novi objekt èitanjem iz podataka baze
    public static Partner CreateNew(IDataReader dr)
    {
      Partner rez = new Partner();
      rez.Load(dr);
      return rez;
    }
    #endregion

    #region Load
    // punjenje instance podacima it èitaèa
    protected override void DoLoad(IDataReader dr)
    {
      this.idPartnera = dr["IdPartnera"] == DBNull.Value ? (int?)null : (int?)dr["IdPartnera"];
      this.tipPartnera = dr["TipPartnera"] == DBNull.Value ? TipPartnera.Nedefinirano : TipPartneraConverter.FromString(dr["TipPartnera"].ToString());
      this.idMjestaPartnera = dr["IdMjestaPartnera"] == DBNull.Value ? (int?)null : (int?)dr["IdMjestaPartnera"];
      this.idMjestaIsporuke = dr["IdMjestaIsporuke"] == DBNull.Value ? (int?)null : (int?)dr["IdMjestaIsporuke"];
      this.adrPartnera = dr["AdrPartnera"] == DBNull.Value ? string.Empty : (string)dr["AdrPartnera"];
      this.adrIsporuke = dr["AdrIsporuke"] == DBNull.Value ? string.Empty : (string)dr["AdrIsporuke"];

      this.matBrTvrtke = dr["MatBrTvrtke"] == DBNull.Value ? string.Empty : (string)dr["MatBrTvrtke"];
      this.nazivTvrtke = dr["NazivTvrtke"] == DBNull.Value ? string.Empty : (string)dr["NazivTvrtke"];

      this.jmbg = dr["JMBG"] == DBNull.Value ? string.Empty : (string)dr["JMBG"];
      this.prezimeOsobe = dr["PrezimeOsobe"] == DBNull.Value ? string.Empty : (string)dr["PrezimeOsobe"];
      this.imeOsobe = dr["ImeOsobe"] == DBNull.Value ? string.Empty : (string)dr["ImeOsobe"];
    }
    #endregion

    #region Fields
    // Polja u bazi
    private int? idPartnera;
    private int? idMjestaPartnera;
    private int? idMjestaIsporuke;
    private string adrPartnera = string.Empty;
    private string adrIsporuke = string.Empty;
    private TipPartnera tipPartnera = TipPartnera.Nedefinirano;

    private string matBrTvrtke = string.Empty;
    private string nazivTvrtke = string.Empty;

    private string jmbg = string.Empty;
    private string prezimeOsobe = string.Empty;
    private string imeOsobe = string.Empty;
    #endregion

    #region Properties
    public int? IdPartnera
    {
      get { return idPartnera; }
      set
      {
        if (InEditMode)
        {
          idPartnera = value;
          PropertyHasChanged("IdPartnera");
        }
      }
    }

    public int? IdMjestaPartnera
    {
      get { return idMjestaPartnera; }
      set
      {
        if (InEditMode)
        {
          idMjestaPartnera = value;
          PropertyHasChanged("IdMjestaPartnera");
        }
      }
    }

    public int? IdMjestaIsporuke
    {
      get { return idMjestaIsporuke; }
      set
      {
        if (InEditMode)
        {
          idMjestaIsporuke = value;
          PropertyHasChanged("IdMjestaIsporuke");
        }
      }
    }

    public string AdrPartnera
    {
      get { return adrPartnera; }
      set
      {
        if (InEditMode)
        {
          adrPartnera = value;
          PropertyHasChanged("AdrPartnera");
        }
      }
    }

    public string AdrIsporuke
    {
      get { return adrIsporuke; }
      set
      {
        if (InEditMode)
        {
          adrIsporuke = value;
          PropertyHasChanged("AdrIsporuke");
        }
      }
    }

    public TipPartnera TipPartnera
    {
      get { return tipPartnera; }
      set
      {
        if (InEditMode)
        {
          tipPartnera = value;
          PropertyHasChanged("TipPartnera");
        }
      }
    }

    public string MatBrTvrtke
    {
      get { return matBrTvrtke; }
      set
      {
        if (InEditMode)
        {
          matBrTvrtke = value;
          PropertyHasChanged("MatBrTvrtke");
        }
      }
    }

    public string NazivTvrtke
    {
      get { return nazivTvrtke; }
      set
      {
        if (InEditMode)
        {
          nazivTvrtke = value;
          PropertyHasChanged("NazivTvrtke");
        }
      }
    }

    public string JMBG
    {
      get { return jmbg; }
      set
      {
        if (InEditMode)
        {
          jmbg = value;
          PropertyHasChanged("JMBG");
        }
      }
    }

    public string PrezimeOsobe
    {
      get { return prezimeOsobe; }
      set
      {
        if (InEditMode)
        {
          prezimeOsobe = value;
          PropertyHasChanged("PrezimeOsobe");
        }
      }
    }

    public string ImeOsobe
    {
      get { return imeOsobe; }
      set
      {
        if (InEditMode)
        {
          imeOsobe = value;
          PropertyHasChanged("ImeOsobe");
        }
      }
    }

    // polja za povezivanje na combo box (Lookup)
    public string Naziv
    {
      get
      {
        if (tipPartnera == TipPartnera.Osoba)
        {
          return string.Format("{0} {1} ({2})", prezimeOsobe.Trim(), imeOsobe.Trim(), jmbg.Trim());
        }
        else if (tipPartnera == TipPartnera.Tvrtka)
        {
          return string.Format("{0} ({1})", this.nazivTvrtke.Trim(), this.matBrTvrtke.Trim());
        }
        else
        {
          return "Partner";
        }
      }
    }
    #endregion

    #region Backup / Restore
    // Pohrana originalnih vrijednosti kako bi se mogao napraviti
    // poništenje unosa
    protected override void DoBackup(object backupObject)
    {
      Partner bak = (Partner)backupObject;

      bak.idPartnera = idPartnera;
      bak.idMjestaPartnera = idMjestaPartnera;
      bak.idMjestaIsporuke = idMjestaIsporuke;
      bak.adrPartnera = adrPartnera;
      bak.adrIsporuke = adrIsporuke;

      bak.matBrTvrtke = matBrTvrtke;
      bak.nazivTvrtke = nazivTvrtke;

      bak.jmbg = jmbg;
      bak.prezimeOsobe = prezimeOsobe;
      bak.imeOsobe = imeOsobe;
    }

    // Vraæanje originalnih vrijednosti (poništenje izmjena)
    protected override void DoRestore(object backupObject)
    {
      Partner bak = (Partner)backupObject;

      idPartnera = bak.idPartnera;
      idMjestaPartnera = bak.idMjestaPartnera;
      idMjestaIsporuke = bak.idMjestaIsporuke;
      adrPartnera = bak.adrPartnera;
      adrIsporuke = bak.adrIsporuke;

      matBrTvrtke = bak.matBrTvrtke;
      nazivTvrtke = bak.nazivTvrtke;

      jmbg = bak.jmbg;
      prezimeOsobe = bak.prezimeOsobe;
      imeOsobe = bak.imeOsobe;
    }
    #endregion

    #region Validation
    // Validacija svih svojstava poslovnog objekta
    public override void Validate()
    {
      DoValidation("IdPartnera");
      DoValidation("IdMjestaPartnera");
      DoValidation("IdMjestaIsporuke");
      DoValidation("AdrPartnera");
      DoValidation("AdrIsporuke");
      DoValidation("TipPartnera");
      DoValidation("MatBrTvrtke");
      DoValidation("NazivTvrtke");
      DoValidation("JMBG");
      DoValidation("PrezimeOsobe");
      DoValidation("ImeOsobe");
    }
    #endregion

    #region System.Object Overrides
    public override string ToString()
    {
      if (tipPartnera == TipPartnera.Osoba)
      {
        return string.Format("{0}, {1}", prezimeOsobe.Trim(), imeOsobe.Trim());
      }
      else if (tipPartnera == TipPartnera.Tvrtka)
      {
        return string.Format("{0} ({1})", this.nazivTvrtke.Trim(), this.matBrTvrtke.Trim());
      }
      else
      {
        return "Partner";
      }
    }
    #endregion
  }
}

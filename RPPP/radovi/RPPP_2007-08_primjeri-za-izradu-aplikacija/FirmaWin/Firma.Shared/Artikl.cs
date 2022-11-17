using System;
using System.Collections.Generic;
using System.Text;
using System.Data;

using NTier;

namespace Firma
{
  // Poslovni objekt artikl
  public class Artikl : BusinessBase
  {
    #region Constructors
    public Artikl()
    {
    }

    // Stvara novi objekt èitanjem iz podataka baze
    public static Artikl CreateNew(IDataReader dr)
    {
      Artikl rez = new Artikl();
      rez.Load(dr);
      return rez;
    }
    #endregion

    #region Load
    // Punjenje objekta iz èitaèa
    protected override void DoLoad(IDataReader dr)
    {
      this.sifArtikla = dr["SifArtikla"] == DBNull.Value ? (int?)null : (int?)dr["SifArtikla"];
      this.nazArtikla = dr["NazArtikla"] == DBNull.Value ? string.Empty : (string)dr["NazArtikla"];
      this.jedMjere = dr["JedMjere"] == DBNull.Value ? string.Empty : (string)dr["JedMjere"];
      this.cijArtikla = dr["CijArtikla"] == DBNull.Value ? (decimal?)null : (decimal?)dr["CijArtikla"];
      this.zastUsluga = dr["ZastUsluga"] == DBNull.Value ? (bool?)null : (bool?)dr["ZastUsluga"];
      this.slikaArtikla = dr["SlikaArtikla"] == DBNull.Value ? null : (byte[])dr["SlikaArtikla"];
    }
    #endregion

    #region Fields
    // Polja u bazi
    private int? sifArtikla;
    private string nazArtikla = string.Empty;
    private string jedMjere = string.Empty;
    private decimal? cijArtikla;
    private bool? zastUsluga;
    private byte[] slikaArtikla;

    // Naziv se može mijenjati pa je potrebna verzija prije izmjene
    // radi ispravne validacije duplog unosa
    private string nazArtiklaOriginal = string.Empty;
    #endregion

    #region Properties
    public string NazArtiklaOriginal
    {
      get { return nazArtiklaOriginal; }
    }

    [GenericForm("Šifra")]
    public int? SifArtikla
    {
      get { return sifArtikla; }
      set
      {
        if (InEditMode)
        {
          sifArtikla = value;
          PropertyHasChanged("SifArtikla");
        }
      }
    }

    [GenericForm("Naziv")]
    public string NazArtikla
    {
      get { return nazArtikla; }
      set
      {
        if (InEditMode)
        {
          if (string.IsNullOrEmpty(nazArtiklaOriginal))
            nazArtiklaOriginal = nazArtikla;

          nazArtikla = value;
          PropertyHasChanged("NazArtikla");
        }
      }
    }

    [GenericForm("Jed. mjere")]
    public string JedMjere
    {
      get { return jedMjere; }
      set
      {
        if (InEditMode)
        {
          jedMjere = value;
          PropertyHasChanged("JedMjere");
        }
      }
    }

    [GenericForm("Cijena", "N2", System.Windows.Forms.HorizontalAlignment.Right)]
    public decimal? CijArtikla
    {
      get { return cijArtikla; }
      set
      {
        if (InEditMode)
        {
          cijArtikla = value;
          PropertyHasChanged("CijArtikla");
        }
      }
    }

    [GenericForm("Usluga")]
    public bool? ZastUsluga
    {
      get { return zastUsluga; }
      set
      {
        if (InEditMode)
        {
          zastUsluga = value;
          PropertyHasChanged("ZastUsluga");
        }
      }
    }

    public byte[] SlikaArtikla
    {
      get { return slikaArtikla; }
      set
      {
        if (InEditMode)
        {
          slikaArtikla = value;
          PropertyHasChanged("SlikaArtikla");
        }
      }
    }

    // polja za povezivanje na combo box (Lookup)
    public string LookupSifra
    {
      get
      {
        if (sifArtikla.HasValue)
        {
          return sifArtikla.Value.ToString() + " " + nazArtikla.Trim();
        }
        else
        {
          return string.Empty;
        }
      }
    }

    // polja za povezivanje na combo box (Lookup)
    public string LookupNaziv
    {
      get
      {
        return nazArtikla + " " + (sifArtikla.HasValue ? sifArtikla.Value.ToString() : string.Empty);
      }
    }
    #endregion

    #region Backup / Restore
    // Pohrana originalnih vrijednosti kako bi se mogao napraviti
    // poništenje unosa
    protected override void DoBackup(object backupObject)
    {
      Artikl bak = (Artikl)backupObject;

      bak.sifArtikla = sifArtikla;
      bak.nazArtikla = nazArtikla;
      bak.jedMjere = jedMjere;
      bak.cijArtikla = cijArtikla;
      bak.zastUsluga = zastUsluga;
      bak.slikaArtikla = slikaArtikla;
    }

    // Vraæanje originalnih vrijednosti (poništenje izmjena)
    protected override void DoRestore(object backupObject)
    {
      Artikl bak = (Artikl)backupObject;

      sifArtikla = bak.sifArtikla;
      nazArtikla = bak.nazArtikla;
      jedMjere = bak.jedMjere;
      cijArtikla = bak.cijArtikla;
      zastUsluga = bak.zastUsluga;
      slikaArtikla = bak.slikaArtikla;
    }
    #endregion

    #region Validation
    // Validacija svih svojstava poslovnog objekta
    public override void Validate()
    {
      DoValidation("SifArtikla");
      DoValidation("NazArtikla");
      DoValidation("JedMjere");
      DoValidation("CijArtikla");
      DoValidation("ZastUsluga");
      DoValidation("SlikaArtikla");
    }
    #endregion

    #region State
    // Izvodi se nakon promjene stanja objekta
    protected override void AfterStateChanged()
    {
      base.AfterStateChanged();
      this.nazArtiklaOriginal = string.Empty;
    }
    #endregion

    #region System.Object Overrides
    public override string ToString()
    {
      return this.SifArtikla.ToString() + ", " + this.NazArtikla;
    }
    #endregion
  }
}

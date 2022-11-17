using System;
using System.Collections.Generic;
using System.Text;
using System.Data;

using NTier;

namespace Firma
{
  // Poslovni objekt stavke dokumenta
  public class Stavka : BusinessBase
  {
    #region Constructors
    public Stavka()
    {
      this.postoRabat = 0;
      this.kolArtikla = 1;
    }

    // Stvara novi objekt èitanjem iz podataka baze
    public static Stavka CreateNew(IDataReader dr)
    {
      Stavka rez = new Stavka();
      rez.Load(dr);
      return rez;
    }
    #endregion

    #region Load
    // punjenje instance podacima it èitaèa
    protected override void DoLoad(IDataReader dr)
    {
      this.idDokumenta = dr["IdDokumenta"] == DBNull.Value ? (int?)null : (int?)dr["IdDokumenta"];
      this.sifArtikla = dr["SifArtikla"] == DBNull.Value ? (int?)null : (int?)dr["SifArtikla"];
      this.kolArtikla = dr["KolArtikla"] == DBNull.Value ? (decimal?)null : (decimal?)dr["KolArtikla"];
      this.jedCijArtikla = dr["JedCijArtikla"] == DBNull.Value ? (decimal?)null : (decimal?)dr["JedCijArtikla"];
      this.postoRabat = dr["PostoRabat"] == DBNull.Value ? (decimal?)null : (decimal?)dr["PostoRabat"];

      this.nazArtikla = dr["NazArtikla"] == DBNull.Value ? string.Empty : (string)dr["NazArtikla"];
      this.jedMjereArtikla = dr["JedMjereArtikla"] == DBNull.Value ? string.Empty : (string)dr["JedMjereArtikla"];
    }
    #endregion

    #region Fields
    // Polja u bazi
    private int? idDokumenta;
    private int? sifArtikla;
    private decimal? kolArtikla;
    private decimal? jedCijArtikla;
    private decimal? postoRabat;
    private string nazArtikla = string.Empty;
    private string jedMjereArtikla = string.Empty;
    #endregion

    #region Properties
    public int? IdDokumenta
    {
      get { return idDokumenta; }
      set
      {
        if (InEditMode)
        {
          idDokumenta = value;
          PropertyHasChanged("IdDokumenta");
        }
      }
    }

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

    public decimal? KolArtikla
    {
      get { return kolArtikla; }
      set
      {
        if (InEditMode)
        {
          kolArtikla = value;
          PropertyHasChanged("KolArtikla");
          PropertyHasChanged("Iznos");
        }
      }
    }

    
    public decimal? JedCijArtikla
    {
      get { return jedCijArtikla; }
      set
      {
        if (InEditMode)
        {
          jedCijArtikla = value;
          PropertyHasChanged("JedCijArtikla");
          PropertyHasChanged("Iznos");
        }
      }
    }

    public decimal? PostoRabat
    {
      get { return postoRabat; }
      set
      {
        if (InEditMode)
        {
          postoRabat = value;
          PropertyHasChanged("PostoRabat");
          PropertyHasChanged("Iznos");
        }
      }
    }

    public string NazArtikla
    {
      get { return nazArtikla; }
      set
      {
        if (InEditMode)
        {
          nazArtikla = value;
          PropertyHasChanged("NazArtikla");
        }
      }
    }

    public string JedMjereArtikla
    {
      get { return jedMjereArtikla; }
      set
      {
        if (InEditMode)
        {
          jedMjereArtikla = value;
          PropertyHasChanged("JedMjereArtikla");
        }
      }
    }
    #endregion

    #region Calculated Properties
    public decimal? Iznos
    {
      get
      {
        if (kolArtikla.HasValue && jedCijArtikla.HasValue && postoRabat.HasValue)
        {
          return kolArtikla.Value * (1m - postoRabat.Value) * jedCijArtikla.Value;
        }
        else
        {
          return null;
        }
      }
    }
    #endregion

    #region Backup / Restore
    // Pohrana originalnih vrijednosti kako bi se mogao napraviti
    // poništenje unosa
    protected override void DoBackup(object backupObject)
    {
      Stavka bak = (Stavka)backupObject;

      bak.idDokumenta = idDokumenta;
      bak.sifArtikla = sifArtikla;
      bak.kolArtikla = kolArtikla;
      bak.jedCijArtikla = jedCijArtikla;
      bak.postoRabat = postoRabat;
      bak.nazArtikla = nazArtikla;
      bak.jedMjereArtikla = jedMjereArtikla;
    }

    // Vraæanje originalnih vrijednosti (poništenje izmjena)
    protected override void DoRestore(object backupObject)
    {
      Stavka bak = (Stavka)backupObject;

      idDokumenta = bak.idDokumenta;
      sifArtikla = bak.sifArtikla;
      kolArtikla = bak.kolArtikla;
      jedCijArtikla = bak.jedCijArtikla;
      postoRabat = bak.postoRabat;
      nazArtikla = bak.nazArtikla;
      jedMjereArtikla = bak.jedMjereArtikla;
    }
    #endregion

    #region Validation
    // Validacija svih svojstava poslovnog objekta
    public override void Validate()
    {
      DoValidation("SifArtikla");
      DoValidation("KolArtikla");
      DoValidation("JedCijArtikla");
      DoValidation("PostoRabat");
    }
    #endregion

    #region Originalne vrijednosti potrebne za ispravno spremanje izmjena
    private int? idDokumenta_Original;
    public int? IdDokumenta_Original
    {
      get { return idDokumenta_Original; }
    }

    private int? sifArtikla_Original;
    public int? SifArtikla_Original
    {
      get { return sifArtikla_Original; }
    }

    protected override void AfterEdit()
    {
      base.AfterEdit();
      idDokumenta_Original = idDokumenta;
      sifArtikla_Original = sifArtikla;
    }
    #endregion
  }
}

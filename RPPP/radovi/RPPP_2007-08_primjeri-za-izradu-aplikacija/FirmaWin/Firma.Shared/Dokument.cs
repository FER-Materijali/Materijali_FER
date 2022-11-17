using System;
using System.Collections.Generic;
using System.Text;
using System.Data;
using System.ComponentModel;

using NTier;

namespace Firma
{
  // Poslovni objekt dokumenta
  public class Dokument : BusinessBase
  {
    #region Constructors
    public Dokument()
    {
      // Inicijalizacija praznih stavaka
      stavke = new StavkaList();
      stavke.ListChanged += new ListChangedEventHandler(Stavke_ListChanged);
      datDokumenta = DateTime.Now;
    }

    // Stvara novi objekt èitanjem iz podataka baze.
    // Automatski se uèitavaju stavke pa je potrebno predati i DAL objekt stavaka.
    public static Dokument CreateNew(IDataReader dr, IStavkaDalProvider stavkaDalProvider)
    {
      Dokument rez = new Dokument();
      rez.Load(dr, stavkaDalProvider);
      return rez;
    }
    #endregion

    #region Load
    // Punjenje objekta iz èitaèa.
    // Automatski se uèitavaju stavke pa je potrebno predati i DAL objekt stavaka.
    public void Load(IDataReader dr, IStavkaDalProvider stavkaDalProvider)
    {
      Load(dr);
      if (idDokumenta.HasValue)
      {
        stavke = stavkaDalProvider.FetchAll(idDokumenta.Value);
      }
      else
      {
        stavke = new StavkaList();
      }
      stavke.ListChanged += new ListChangedEventHandler(Stavke_ListChanged);
      SetState(BusinessObjectState.Unmodified);
    }

    // punjenje instance podacima it èitaèa
    protected override void DoLoad(IDataReader dr)
    {
      this.idDokumenta = dr["IdDokumenta"] == DBNull.Value ? (int?)null : (int?)dr["IdDokumenta"];
      this.vrDokumenta = dr["VrDokumenta"] == DBNull.Value ? string.Empty : (string)dr["VrDokumenta"];
      this.brDokumenta = dr["BrDokumenta"] == DBNull.Value ? (int?)null : (int?)dr["BrDokumenta"];
      this.datDokumenta = dr["DatDokumenta"] == DBNull.Value ? (DateTime?)null : (DateTime?)dr["DatDokumenta"];
      this.idPartnera = dr["IdPartnera"] == DBNull.Value ? (int?)null : (int?)dr["IdPartnera"];
      this.idPrethDokumenta = dr["IdPrethDokumenta"] == DBNull.Value ? (int?)null : (int?)dr["IdPrethDokumenta"];
      this.postoPorez = dr["PostoPorez"] == DBNull.Value ? (decimal?)null : (decimal?)dr["PostoPorez"];
    }
    #endregion

    #region Fields
    // Polja u bazi
    private int? idDokumenta;
    private string vrDokumenta = string.Empty;
    private int? brDokumenta;
    private DateTime? datDokumenta;
    private int? idPartnera;
    private int? idPrethDokumenta;
    private decimal? postoPorez;
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

    public string VrDokumenta
    {
      get { return vrDokumenta; }
      set
      {
        if (InEditMode)
        {
          vrDokumenta = value;
          PropertyHasChanged("VrDokumenta");
        }
      }
    }

    public int? BrDokumenta
    {
      get { return brDokumenta; }
      set
      {
        if (InEditMode)
        {
          brDokumenta = value;
          PropertyHasChanged("BrDokumenta");
        }
      }
    }

    public DateTime? DatDokumenta
    {
      get { return datDokumenta; }
      set
      {
        if (InEditMode)
        {
          datDokumenta = value;
          PropertyHasChanged("DatDokumenta");
        }
      }
    }

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

    public int? IdPrethDokumenta
    {
      get { return idPrethDokumenta; }
      set
      {
        if (InEditMode)
        {
          idPrethDokumenta = value;
          PropertyHasChanged("IdPrethDokumenta");
        }
      }
    }

    public decimal? PostoPorez
    {
      get { return postoPorez; }
      set
      {
        if (InEditMode)
        {
          postoPorez = value;
          PropertyHasChanged("PostoPorez");
          OnPropertyChanged("IznosDokumenta");
        }
      }
    }
    #endregion

    #region Calculated Properties
    public decimal? IznosDokumenta
    {
      get
      {
        decimal rez = 0;
        foreach (Stavka s in this.stavke)
        {
          if (s.Iznos.HasValue)
            rez += s.Iznos.Value;
        }

        if (postoPorez.HasValue)
        {
          rez *= (1m + postoPorez.Value);
        }
        return rez;
      }
    }

    public string LookupText
    {
      get { return this.ToString(); }
    }
    #endregion

    #region Stavke
    private StavkaList stavke;

    public StavkaList Stavke
    {
      get { return stavke; }
    }

    private void Stavke_ListChanged(object sender, ListChangedEventArgs e)
    {
      // Kad se promijeni stavka osvježiti iznos dokumenta...
      OnPropertyChanged("IznosDokumenta");
    }
    #endregion

    #region Backup / Restore
    // Pohrana originalnih vrijednosti kako bi se mogao napraviti
    // poništenje unosa
    protected override void DoBackup(object backupObject)
    {
      Dokument bak = (Dokument)backupObject;

      bak.idDokumenta = idDokumenta;
      bak.vrDokumenta = vrDokumenta;
      bak.brDokumenta = brDokumenta;
      bak.datDokumenta = datDokumenta;
      bak.idPartnera = idPartnera;
      bak.idPrethDokumenta = idPrethDokumenta;

      // Backupirati svaku stavku
      bak.stavke = new StavkaList();
      foreach (Stavka s in stavke)
        bak.stavke.Add(s);
    }

    // Vraæanje originalnih vrijednosti (poništenje izmjena)
    protected override void DoRestore(object backupObject)
    {
      Dokument bak = (Dokument)backupObject;

      idDokumenta = bak.idDokumenta;
      vrDokumenta = bak.vrDokumenta;
      brDokumenta = bak.brDokumenta;
      datDokumenta = bak.datDokumenta;
      idPartnera = bak.idPartnera;
      idPrethDokumenta = bak.idPrethDokumenta;

      stavke.Clear();
      foreach (Stavka s in bak.stavke)
        stavke.Add(s);
    }
    #endregion

    #region Validation
    // Validacija svih svojstava poslovnog objekta
    public override void Validate()
    {
      DoValidation("VrDokumenta");
      DoValidation("BrDokumenta");
      DoValidation("DatDokumenta");
      DoValidation("IdPartnera");
      DoValidation("IdPrethDokumenta");
    }
    #endregion

    #region BusinessBase Overrides
    // Izvodi se nakon ulaska u stanje izmjene
    protected override void AfterEdit()
    {
      base.AfterEdit();
      foreach (Stavka s in stavke)
        s.Edit();
    }

    // Izvodi se nakon spremanja
    protected override void AfterSaveChanges()
    {
      base.AfterSaveChanges();
      foreach (Stavka s in stavke)
        s.SaveChanges();
    }

    // Izvodi se nakon odustajanja od izmjena
    protected override void AfterCancelChanges()
    {
      base.AfterCancelChanges();
      foreach (Stavka s in stavke)
        s.CancelChanges();
    }

    // Dokument se mijenjao ako se promijenila i samo jedna stavka
    [Browsable(false)]
    public override bool IsDirty
    {
      get
      {
        return stavke.IsDirty || base.IsDirty;
      }
    }
    #endregion

    #region System.Object Overrides
    public override string ToString()
    {
      if (brDokumenta.HasValue && !string.IsNullOrEmpty(vrDokumenta))
      {
        return vrDokumenta + " " + brDokumenta.Value.ToString() + " - " + datDokumenta;
      }
      else
      {
        return "Dokument";
      }
    }
    #endregion
  }
}

using System;
using System.Collections.Generic;
using System.Text;
using System.ComponentModel;
using System.Data;

namespace NTier
{
  // Osnovna klasa iz koje se izvode sve poslovne klase
  public abstract class BusinessBase :
      INotifyPropertyChanged,
      IEditableObject,
      IDataErrorInfo,
      IBusinessObject
  {
    #region Constructors
    protected BusinessBase()
    {
    }
    #endregion

    #region State
    // Objekt nije uèitan iz baze. To je novi, prazni objekt
    private BusinessObjectState state = BusinessObjectState.New;

    // Koristi se za postavljanje stanja objekta.
    // Objekt samo sam sebi može mijenjati stanje.
    protected void SetState(BusinessObjectState newState)
    {
      if (state != newState)
      {
        state = newState;
        AfterStateChanged();
        OnPropertyChanged("State");
        OnPropertyChanged("InEditMode");
      }
    }

    protected virtual void AfterStateChanged()
    {
      // Moguænost proširenja funkcionalnosti u
      // izvedenim klasama preoptereæivanjem metode
    }

    #region Properties
    [Browsable(false)]
    public BusinessObjectState State
    {
      get { return state; }
    }

    [Browsable(false)]
    public bool InEditMode
    {
      get { return State != BusinessObjectState.Unmodified; }
    }
    #endregion
    #endregion

    #region INotifyPropertyChanged Members
    // Omoguæuje data-binding

    private PropertyChangedEventHandler propertyChanged;

    public event PropertyChangedEventHandler PropertyChanged
    {
      add { propertyChanged += value; }
      remove { propertyChanged -= value; }
    }

    protected void OnPropertyChanged(string propertyName)
    {
      if (propertyChanged != null)
        propertyChanged.Invoke(this, new PropertyChangedEventArgs(propertyName));
    }
    #endregion

    #region EditableObject
    // Omoguæuje BeginEdit, CancelEdit i EndEdit
    private bool inEdit = false;

    [Browsable(false)]
    public bool InEdit
    {
      get { return inEdit; }
    }

    private object backupObject;

    #region IEditableObject Members
    void IEditableObject.BeginEdit()
    {
      if (!InEditMode)
        return;

      if (!inEdit)
      {
        Backup();
        inEdit = true;
      }
    }

    void IEditableObject.CancelEdit()
    {
      if (!InEditMode)
        return;

      if (inEdit)
      {
        Restore();
        inEdit = false;
      }
    }

    void IEditableObject.EndEdit()
    {
      if (!InEditMode)
        return;

      if (inEdit)
      {
        BackupEmptyObject();
        inEdit = false;
      }
    }
    #endregion

    #region Backup / Restore
    // Pohrana vrijednosti svojstava kako bi se mogao napraviti rollback
    private void Backup()
    {
      BackupEmptyObject();

      BusinessBase bak = (BusinessBase)backupObject;
      bak.state = state;

      // Backup fieldova u podklasi
      DoBackup(bak);
    }

    // Vraæanje pohranjenih vrijednosti
    private void Restore()
    {
      BusinessBase bak = (BusinessBase)backupObject;
      state = bak.state;

      // Restore fieldova u podklasi
      DoRestore(bak);

      // Refresh prekršenih poslovnih pravila
      Validate();
      // Refresh GUI-a dojavom da su se property-i promijenili
      OnPropertyChanged(string.Empty);
    }

    private void BackupEmptyObject()
    {
      // Stvara novu instancu klase kao prazni objekt
      backupObject = Activator.CreateInstance(this.GetType());
    }

    protected abstract void DoBackup(object backupObject);
    protected abstract void DoRestore(object backupObject);
    #endregion
    #endregion

    #region DataErrorInfo
    // Omoguæuje suradnju s DataProvider komponentom

    // Popis pogrešaka (svojstvo, pogreška)
    private Dictionary<string, string> errors = new Dictionary<string, string>();

    // Uklanja informacije o pogreškama
    public void ClearErrors()
    {
      errors.Clear();
      OnPropertyChanged(string.Empty);
    }

    // Postavlja tekst pogreške za odreðeno svojstvo
    protected void SetError(string propertyName, string errorMessage)
    {
      if (errors.ContainsKey(propertyName))
      {
        errors[propertyName] = errorMessage;
      }
      else
      {
        errors.Add(propertyName, errorMessage);
      }
    }

    #region IDataErrorInfo Members
    string IDataErrorInfo.Error
    {
      get
      {
        string rez = string.Empty;

        foreach (KeyValuePair<string, string> e in errors)
        {
          if (!string.IsNullOrEmpty(e.Value))
            rez += e.Value + Environment.NewLine;
        }

        return rez.Trim();
      }
    }

    string IDataErrorInfo.this[string columnName]
    {
      get
      {
        if (errors.ContainsKey(columnName))
          return errors[columnName];

        return string.Empty;
      }
    }
    #endregion
    #endregion

    #region BLL Object
    // BLL sloj

    private NeedBllObjectEventHandler needBllObject;

    public event NeedBllObjectEventHandler NeedBllObject
    {
      add { needBllObject += value; }
      remove { needBllObject -= value; }
    }

    protected IBllObject OnNeedBllObject()
    {
      if (needBllObject != null)
        return needBllObject.Invoke();

      return null;
    }

    [Browsable(false)]
    public bool HasBllObject
    {
      get { return needBllObject != null; }
    }
    #endregion

    #region IsDirty
    // Oznaèava je li objekt promjenjen

    private bool isDirty;

    [Browsable(false)]
    public virtual bool IsDirty
    {
      get { return isDirty; }
    }
    #endregion

    #region PropertyHasChanged
    public abstract void Validate();

    // Obavlja validaciju traženog svojstva
    public void Validate(string propertyName)
    {
      DoValidation(propertyName);
    }

    // Izvodi se kad se promjenilo
    protected void PropertyHasChanged(string propertyName)
    {
      isDirty = true;
      // Osvježavanje data-binding-om
      OnPropertyChanged(propertyName);

      // Validacija
      DoValidation(propertyName);
    }

    protected void DoValidation(string propertyName)
    {
      // BLL sloj
      IBllObject bll = OnNeedBllObject();
      if (bll != null)
      {
        string error = string.Empty;
        try
        {
          // Validiraj
          bll.Validate(this, propertyName);
        }
        catch (Exception err)
        {
          // Validacijsko pravilo nije zadovoljeno
          error = err.Message;
        }

        SetError(propertyName, error);
        OnPropertyChanged(propertyName);
      }
      else
      {
        // Ako BLL sloj nije dostupan neæemo raditi validaciju
        // poslovnih pravila. To nam ne smeta jer æe se pravila
        // ionako validirati u BLL sloju prije spremanja (prosljeðivanja
        // u DAL sloj). Ovo je implementirano samo kako bi GUI bio više
        // user-frendly (IDataErrorInfo implementacija)
      }
    }
    #endregion

    #region Edit / Cancel / Save / Delete
    // Oznaèava objekt za brisanje
    public void Delete()
    {
      SetState(BusinessObjectState.Deleted);
      isDirty = true;
    }

    // Prebacuje objekt u stanje izmjene
    public void Edit()
    {
      SetState(BusinessObjectState.Modified);
      (this as IEditableObject).BeginEdit();
      AfterEdit();
    }

    protected virtual void AfterEdit()
    {
    }

    // Prekid unosa/izmjene i zanemarivanje uèinjenih promjena
    public void CancelChanges()
    {
      (this as IEditableObject).CancelEdit();
      if (State != BusinessObjectState.New)
      {
        SetState(BusinessObjectState.Unmodified);
      }
      else
      {
        if (parent != null)
        {
          parent.CancelNew(parent.IndexOf(this));
          parent = null;
        }
      }

      AfterCancelChanges();
    }

    protected virtual void AfterCancelChanges()
    {
    }

    // Oznaèava objekt spremljenim u bazu
    public void SaveChanges()
    {
      (this as IEditableObject).EndEdit();
      SetState(BusinessObjectState.Unmodified);
      AfterSaveChanges();
    }

    protected virtual void AfterSaveChanges()
    {
    }
    #endregion

    #region List
    // Veza na listu u kojoj se (eventualno) nalazi objekt

    private IBusinessObjectList parent;

    public void SetParent(IBusinessObjectList parent)
    {
      this.parent = parent;
    }
    #endregion

    #region Load
    // Uèitavanje objekta iz baze
    public void Load(IDataReader dr)
    {
      DoLoad(dr);

      // Objekt je uèitan iz baze
      SetState(BusinessObjectState.Unmodified);
    }

    // U podklasi implementira uèitavanje vrijednosti svojstava
    protected abstract void DoLoad(IDataReader dr);
    #endregion
  }
}

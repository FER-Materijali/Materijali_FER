using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Diagnostics;

using NTier;

namespace Firma
{
  public partial class BaseForm : Form, IBusinessObjectForm
  {
    #region Constructors
    protected BaseForm()
    {
      InitializeComponent();

      StatusBar.Funkcija = "Pregled";
    }
    #endregion

    #region Binding & Current Business Object
    private BindingSource mainBindingSource;
    [Browsable(true), Category("Data")] // Property, Data
    public BindingSource MainBindingsource
    {
      get { return mainBindingSource; }
      set { mainBindingSource = value; }
    }

    [Browsable(false)] // da ga ne stavlja u Property prozor
    public object Selected
    {
      get
      {
        if (mainBindingSource != null)
          return mainBindingSource.Current;

        return null;
      }
    }
    #endregion

    #region StatusBar
    private StatusBarInfo statusBar = new StatusBarInfo();
    [Browsable(false)]
    public StatusBarInfo StatusBar
    {
      get { return statusBar; }
    }
    #endregion

    #region KeyDown
    // Iz nekog (nepoznatog) razloga glavna forma primi dogaðaj s tipkovnice umjesto forme dijete.
    // Metodu poziva glavna forma koja delegira KeyDown na aktivnu child formu

    protected internal void InvokeKeyDown(KeyEventArgs e)
    {
      OnKeyDown(e);
    }

    private void BaseForm_KeyDown(object sender, KeyEventArgs e)
    {
      // Definicija tipki može se staviti u datoteku s postavkama aplikacije
      e.Handled = true;
      switch (e.KeyCode)
      {
        case Keys.Home: First(); break;
        case Keys.PageUp: Previous(); break;
        case Keys.PageDown: Next(); break;
        case Keys.End: Last(); break;
        case Keys.F1: ShowHelp(); break;
        case Keys.F2: New(); break;
        case Keys.F3: Edit(); break;
        case Keys.F4: e.Handled = false; break; // Ovo je win shortcut za combo-box. To je OK za lookup.
        case Keys.F5: Zoom(); break;
        case Keys.F6: EditDetails(); break;
        case Keys.F7: Delete(); break;
        case Keys.F10:
          {
            if (!InEditMode)
            {
              DialogResult = DialogResult.OK;
              Close();
            }
            else
            {
              SaveChanges();
            }
            break;
          }
        case Keys.Escape:
          {
            if (!InEditMode)
            {
              DialogResult = DialogResult.Cancel;
              Close();
            }
            else
            {
              if (State != BusinessObjectState.New && 
                  mainBindingSource != null &&
                  mainBindingSource.Current != null && 
                  ((IBusinessObject)mainBindingSource.Current).InEdit)
              {
                mainBindingSource.CancelEdit();
              }
              else
              {
                CancelChanges();
              }
            }
            break;
          }
        default: e.Handled = false; break;
      }
    }
    #endregion

    #region State
    private BusinessObjectState state = BusinessObjectState.Unmodified;
    [Browsable(false)]
    public BusinessObjectState State
    {
      get { return state; }
      protected set
      {
        state = value;
        AfterStateChanged();
        OnNeedToolbarRefresh();
        OnPropertyChanged("InEditMode");
        OnPropertyChanged("State");
      }
    }

    protected virtual void AfterStateChanged()
    {
      // Za sluèaj potrebe implementacije dodatne funkcionalnosti
      // za promjenu stanja forme
    }

    // Odreðuje nalazi li se forma u stanju unosa/izmjene
    [Browsable(false)]
    public bool InEditMode
    {
      get { return State == BusinessObjectState.New 
                || State == BusinessObjectState.Modified; }   
    }
    #endregion

    #region CanDo... Properties
    // Svojstva koja odreðuju može li se obaviti neka akcija nad objektom.
    // Koriste se i za osvježavanje prikaza toolbara (RefreshToolbar). 

    public bool CanDoFirst
    {
      get { return mainBindingSource != null && !InEditMode && mainBindingSource.Position > 0; }
    }

    public bool CanDoPrevious
    {
      get { return mainBindingSource != null && !InEditMode && mainBindingSource.Position > 0; }
    }

    public bool CanDoNext
    {
      get { return mainBindingSource != null && !InEditMode && mainBindingSource.Position < mainBindingSource.Count - 1; }
    }

    public bool CanDoLast
    {
      get { return mainBindingSource != null && !InEditMode && mainBindingSource.Position < mainBindingSource.Count - 1; }
    }

    public bool CanDoNew
    {
      get { return !InEditMode && mainBindingSource != null; }
    }

    public bool CanDoEdit
    {
      get { return !InEditMode && mainBindingSource != null && mainBindingSource.Current != null; }
    }

    public bool CanDoDelete
    {
      get { return !InEditMode && mainBindingSource != null && mainBindingSource.Current != null; }
    }

    public bool CanDoCancelChanges
    {
      get { return InEditMode && mainBindingSource != null && mainBindingSource.Current != null; }
    }

    public bool CanDoSaveChanges
    {
      get { return InEditMode && mainBindingSource != null && mainBindingSource.Current != null; }
    }
    #endregion

    #region New / Edit / Save / Cancel / Delete
    // postupci promjene stanja objekta
    // obavi - prikaži status - "završi"
    public void Delete()
    {
      if (CanDoDelete && MessageBox.Show("Želite li zaista obrisati trenutni zapis?", "Potvrda brisanja", MessageBoxButtons.YesNo, MessageBoxIcon.Question, MessageBoxDefaultButton.Button2) == DialogResult.Yes)
      {
        DoDelete();

        StatusBar.Funkcija = "Pregled";
        StatusBar.Message = "Zapis obrisan.";
        StatusBar.IsError = false;

        OnNeedToolbarRefresh();
      }
    }

    protected virtual void DoDelete()
    {
      // Mora biti implementirano u podklasama
      throw new NotSupportedException();
    }

    public virtual void New()
    {
      if (CanDoNew)
      {
        State = BusinessObjectState.New;
        mainBindingSource.AddNew();

        if (focusOnNew != null)
          focusOnNew.Focus();

        StatusBar.Funkcija = "Novi unos";
        StatusBar.Message = string.Empty;
        StatusBar.IsError = false;

        AfterNew();

        OnNeedToolbarRefresh();
      }
    }

    protected virtual void AfterNew()
    {
      // Za specifièno ponašanje forme kad uðe u stanje izmjene
    }

    public void CancelChanges()
    {
      if (CanDoCancelChanges)
      {
        ((IBusinessObject)mainBindingSource.Current).CancelChanges();
        State = BusinessObjectState.Unmodified;
        StatusBar.Funkcija = "Pregled";
        StatusBar.Message = "Unos prekinut.";
        StatusBar.IsError = false;

        OnNeedToolbarRefresh();
      }
    }

    public void SaveChanges()
    {
      if (CanDoSaveChanges)
      {
        try
        {
          this.Validate();
          DoSaveChanges();
          ((IBusinessObject)mainBindingSource.Current).SaveChanges();
          State = BusinessObjectState.Unmodified;
          StatusBar.Funkcija = "Pregled";
          StatusBar.Message = "Spremljeno.";
          StatusBar.IsError = false;

          OnNeedToolbarRefresh();
        }
        catch (Exception err)
        {
          MessageBox.Show(err.Message, "Pogreška", MessageBoxButtons.OK, MessageBoxIcon.Error);
        }
      }
    }

    protected virtual void DoSaveChanges()
    {
      // Mora biti implementirano u podklasama
      throw new NotSupportedException();
    }

    public void Edit()
    {
      if (CanDoEdit)
      {
        ((IBusinessObject)mainBindingSource.Current).Edit();
        State = BusinessObjectState.Modified;

        if (focusOnEdit != null)
          focusOnEdit.Focus();

        StatusBar.Funkcija = "Izmjena";
        StatusBar.Message = string.Empty;
        StatusBar.IsError = false;

        AfterEdit();

        OnNeedToolbarRefresh();
      }
    }

    protected virtual void AfterEdit()
    {
      // Za specifièno ponašanje forme kad uðe u stanje izmjene
    }
    #endregion

    #region Ostale operacije
    protected virtual void ShowHelp()
    {
      //MessageBox.Show("Nema vam pomoæi :-)", "Pomoæ?", MessageBoxButtons.OK, MessageBoxIcon.Information);
    }

    protected virtual void Zoom()
    {
      // Za implementiranje funkcionalnosti skoka u drugi prozor
    }

    protected virtual void EditDetails()
    {
      // Za implementaciju automatskog pokretanja editiranja stavaka
    }
    #endregion

    #region Navigacija
    public virtual void First()
    {
      // Odlazak na drugi zapis moguæ je ako ne traje unos/izmjena
      if (mainBindingSource != null && !InEditMode)
      {
        mainBindingSource.MoveFirst();
        OnNeedToolbarRefresh();
      }
    }

    public virtual void Previous()
    {
      // Odlazak na drugi zapis moguæ je ako ne traje unos/izmjena
      if (mainBindingSource != null && !InEditMode)
      {
        mainBindingSource.MovePrevious();
        OnNeedToolbarRefresh();
      }
    }

    public virtual void Next()
    {
      // Odlazak na drugi zapis moguæ je ako ne traje unos/izmjena
      if (mainBindingSource != null && !InEditMode)
      {
        mainBindingSource.MoveNext();
        OnNeedToolbarRefresh();
      }
    }

    public virtual void Last()
    {
      // Odlazak na drugi zapis moguæ je ako ne traje unos/izmjena
      if (mainBindingSource != null && !InEditMode)
      {
        mainBindingSource.MoveLast();
        OnNeedToolbarRefresh();
      }
    }
    #endregion

    #region INotifyPropertyChanged Members
    // Implementira se zbog data-bindinga

    private PropertyChangedEventHandler propertyChanged;
    [Category("Property Changed")]
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

    #region Activated / Deactivated / Closed
    // stanja forme unutar MDI suèelja
    private void BaseForm_Activated(object sender, EventArgs e)
    {
      StatusBar.RefreshStatusBar();
    }

    private void BaseForm_Deactivate(object sender, EventArgs e)
    {
      StatusBar.ClearStatusBar();
    }

    private void BaseForm_FormClosed(object sender, FormClosedEventArgs e)
    {
      StatusBar.ClearStatusBar();
    }
    #endregion

    #region Form Property Changed
    // promjena svojstva Caption forme
    private void BaseForm_TextChanged(object sender, EventArgs e)
    {
      if (DesignMode)
        return;

      // Osvježavam status-bar
      StatusBar.NazivModula = this.Text;
    }
    #endregion

    #region Control Focus
    private Control focusOnNew;
    private Control focusOnEdit;

    // Kontrola koja æe dobiti fokus kada zapoène unos novog zapisa
    [Browsable(true), Category("Behavior")]
    public Control FocusOnNew
    {
      get { return focusOnNew; }
      set { focusOnNew = value; }
    }

    // Kontrola koja æe dobiti fokus kada zapoène izmjena trenutnog zapisa
    [Browsable(true), Category("Behavior")]
    public Control FocusOnEdit
    {
      get { return focusOnEdit; }
      set { focusOnEdit = value; }
    }
    #endregion

    #region Toolbar Refresh
    // Na event se veže glavni toolbar forme. Korisit se za refresh toolbara.

    private EventHandler needToolbarRefresh;
    public event EventHandler NeedToolbarRefresh
    {
      add { needToolbarRefresh += new EventHandler(value); }
      remove { needToolbarRefresh -= new EventHandler(value); }
    }

    protected void OnNeedToolbarRefresh()
    {
      if (needToolbarRefresh != null)
        needToolbarRefresh.Invoke(this, new EventArgs());
    }
    #endregion
  }
}
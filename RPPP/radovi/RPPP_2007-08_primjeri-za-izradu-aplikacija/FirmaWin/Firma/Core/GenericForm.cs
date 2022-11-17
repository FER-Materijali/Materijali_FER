using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Collections;
using System.Reflection;

using NTier;

namespace Firma
{
  public partial class GenericForm : BaseForm
  {
    #region Vars
    // Tip poslovnog objekta
    private Type boType;
    #endregion

    #region BLL
    // BLL sloj
    private IBllObject bll;

    // Metoda preko koje æe poslovni objekt doæi do BLL sloja kako bi obavio validaciju unosa
    private IBllObject NeedBllObject()
    {
      return bll;
    }
    #endregion

    #region Constructors
    public GenericForm(string formTitle, object dataSource, IBllObject bllObject, Type boType)
    {
      InitializeComponent();

      this.bll = bllObject;
      this.Text = formTitle;
      this.boType = boType;
      SetupForm(dataSource, boType);

      State = BusinessObjectState.Unmodified;
    }
    #endregion

    #region Form Layout
    // Postavlja kontrole na formu
    private void SetupForm(object dataSource, Type boType)
    {
      // Inicijalna pozicija kontrole
      Point controlPos = new Point(100, 40);
      // Inicijalna pozicija labele
      Point labelPos = new Point(12, 40);

      bindingSource.DataSource = dataSource;

      // Dohvat svih javnih svojstava poslovnog objekta
      PropertyInfo[] props = boType.GetProperties(BindingFlags.Instance | BindingFlags.Public);
      foreach (PropertyInfo prop in props)
      {
        // Je li svojstvo oznaèeno atributom za prikaz na univerzalnoj formi?
        if (Attribute.IsDefined(prop, typeof(GenericFormAttribute)))
        {
          GenericFormAttribute atr = (GenericFormAttribute)Attribute.GetCustomAttribute(prop, typeof(GenericFormAttribute));

          // Kreiranje kontrole za svojstvo
          Control c = null;
          if (prop.PropertyType.Equals(typeof(bool)) || prop.PropertyType.Equals(typeof(bool?)))
          {
            c = new CheckBox();
            c.DataBindings.Add(new Binding("CheckState", bindingSource, prop.Name, true));
          }
          else if (prop.PropertyType.Equals(typeof(DateTime)) || prop.PropertyType.Equals(typeof(DateTime?)))
          {
            c = new DateTimePicker();
            c.DataBindings.Add(new Binding("Value", bindingSource, prop.Name));
          }
          else if (prop.PropertyType.Equals(typeof(byte[])))
          {
            // Nije podržano pa æu zanemariti. Koristi se u formi artikla za spremanje slike.
            // Ako se u klasi Artikl implementira svojstvo tipa Image onda bi se mogla dodati
            // PictureBox kontrola. Tip byte[] je preopæenit.
          }
          else
          {
            c = new TextBox();
            (c as TextBox).TextAlign = atr.TextAlignment;
            if (string.IsNullOrEmpty(atr.DisplayFormat))
            {
              c.DataBindings.Add(new Binding("Text", bindingSource, prop.Name, true));
            }
            else
            {
              c.DataBindings.Add(new Binding("Text", bindingSource, prop.Name, true, DataSourceUpdateMode.OnValidation, string.Empty, atr.DisplayFormat));
            }
          }

          if (c == null)
            continue;

          // Kreiranje labele za svojstvo
          Label l = new Label();
          l.Text = atr.DisplayName;

          // Postavljanje kontrole i labele na formu
          this.Controls.Add(l);
          l.Location = labelPos;
          labelPos.Y += 26;

          c.Width = 300;
          this.Controls.Add(c);
          c.Location = controlPos;
          controlPos.Y += 26;

          l.SendToBack();

          c.Enter += new EventHandler(ControlEnter);
          c.Leave += new EventHandler(ControlLeave);

          if (FocusOnNew == null)
          {
            FocusOnNew = c;
            FocusOnEdit = c;
          }
        }
      }
    }
    #endregion

    #region Business Object Changed
    private void bindingSource_CurrentChanged(object sender, EventArgs e)
    {
      // Ako sam dohvatio novi objekt koji još nema referencu na BLL... ažuriraj
      if (bindingSource.Current != null && bindingSource.Current is IBusinessObject && !((IBusinessObject)bindingSource.Current).HasBllObject)
      {
        ((IBusinessObject)bindingSource.Current).NeedBllObject += new NeedBllObjectEventHandler(NeedBllObject);
      }
    }
    #endregion

    #region Spremanje i brisanje
    // Spremanje svih izmjena
    protected override void DoSaveChanges()
    {
      bll.SaveChanges(((IBusinessObjectList)bindingSource.DataSource).GetChanges());
    }

    // Brisanje
    protected override void DoDelete()
    {
      // Uklanjanje poslovnog objekta iz liste dohvaæenih objekata (oznaèava objekt obrisanim)
      bindingSource.RemoveCurrent();
      // Sprema izmjene u bazu. Objekti oznaèeni za brisanje biti æe uklonjeni iz baze.
      bll.SaveChanges(((IBusinessObjectList)bindingSource.DataSource).GetChanges());
    }
    #endregion

    #region Ponašanje forme
    private void ClearError()
    {
      // Obriši sve oznake za pogrešku
      errorProvider.Clear();
      StatusBar.IsError = false;
      StatusBar.Message = string.Empty;
    }

    // Izvodi se nakon što forma uðe u stanje izmjene
    protected override void AfterEdit()
    {
      base.AfterEdit();
      ((IBusinessObject)bindingSource.Current).ClearErrors();
    }

    // Izvodi se nakon što forma uðe u stanje novog unosa
    protected override void AfterNew()
    {
      base.AfterNew();
      ((IBusinessObject)bindingSource.Current).ClearErrors();
    }

    // Osvježavanje kontrola
    private void GenericForm_PropertyChanged(object sender, PropertyChangedEventArgs e)
    {
      if (e.PropertyName.Equals("InEditMode"))
      {
        foreach (Control c in this.Controls)
        {
          if (c is TextBox || c is DateTimePicker || c is CheckBox)
            c.Enabled = InEditMode;
        }
      }
    }

    // Ako nema pogreške oèisti kontrolu, inaèe...
    private void ControlEnter(object sender, EventArgs e)
    {
      if (InEditMode)
      {
        string error = errorProvider.GetError(sender as Control);
        StatusBar.IsError = !string.IsNullOrEmpty(error);
        StatusBar.Message = error;
      }
      else
      {
        ClearError();
      }
    }

    private void ControlLeave(object sender, EventArgs e)
    {
      // Sa NULL vrijednostima osnovne .NET kontrole imaju problema.
      // Problem je što se brisanjem teksta neæe postaviti NULL odnosno string.Empty o odreðeni property

      // Ova metoda zaobilazi ovaj nedostatak koji je inaèe riješen u veæini 3rd party komponentama

      if (bindingSource.Current != null)
      {
        if (sender is TextBox && string.IsNullOrEmpty((sender as TextBox).Text))
        {
          Utils.SetNull(sender as Control, "Text", bindingSource.Current);
        }
        else if (sender is ComboBox && string.IsNullOrEmpty((sender as ComboBox).Text))
        {
          Utils.SetNull(sender as Control, "SelectedValue", bindingSource.Current);
        }
        else if (sender is DateTimePicker && string.IsNullOrEmpty((sender as DateTimePicker).Text))
        {
          Utils.SetNull(sender as Control, "Value", bindingSource.Current);
        }
      }

      StatusBar.IsError = false;
      StatusBar.Message = string.Empty;
    }
    #endregion
  }
}
using System;
using System.ComponentModel;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using System.Windows.Forms;

namespace Firma
{
  // Glavni toolbar forme. Zamjena za BindingNavigator kontrolu.
  public partial class FormToolbar : ToolStrip
  {
    #region Constructors
    public FormToolbar()
    {
      InitializeComponent();
      InitButtons();
    }

    public FormToolbar(IContainer container)
    {
      container.Add(this);

      InitializeComponent();
      InitButtons();
    }
    #endregion

    #region Form
    // Forma s kojom komunicira toolbar. 
    // Property se postavlja u dizajnu forme.
    private IBusinessObjectForm f;
    public IBusinessObjectForm Form
    {
      get { return f; }
      set
      {
        if (f != value)
        {
          if (f != null)
          {
            // da ne izazove curenje memorije
            f.NeedToolbarRefresh -= new EventHandler(f_NeedToolbarRefresh);
          }
          f = value;
          f.NeedToolbarRefresh += new EventHandler(f_NeedToolbarRefresh);

          RefreshToolbar();
        }
      }
    }

    private void f_NeedToolbarRefresh(object sender, EventArgs e)
    {
      RefreshToolbar();
    }
    #endregion

    #region Buttons
    private void InitButtons()
    {
      // Inicijalizacija buttona kontrole.
      // Buttoni su dodani u toolbar kroz designer kontrole.

      RefreshToolbar();

      btnFirst.Click += new EventHandler(btnFirst_Click);
      btnPrevious.Click += new EventHandler(btnPrevious_Click);
      btnNext.Click += new EventHandler(btnNext_Click);
      btnLast.Click += new EventHandler(btnLast_Click);

      btnNew.Click += new EventHandler(btnNew_Click);
      btnEdit.Click += new EventHandler(btnEdit_Click);
      btnDelete.Click += new EventHandler(btnDelete_Click);

      btnSave.Click += new EventHandler(btnSave_Click);
      btnCancel.Click += new EventHandler(btnCancel_Click);
    }

    // Osvježava toolbar
    public void RefreshToolbar()
    {
      this.Enabled = f != null;

      btnFirst.Enabled = f != null ? f.CanDoFirst : false;
      btnPrevious.Enabled = f != null ? f.CanDoPrevious : false;
      btnNext.Enabled = f != null ? f.CanDoNext : false;
      btnLast.Enabled = f != null ? f.CanDoLast : false;

      btnNew.Enabled = f != null ? f.CanDoNew : false;
      btnEdit.Enabled = f != null ? f.CanDoEdit : false;
      btnDelete.Enabled = f != null ? f.CanDoDelete : false;

      btnSave.Enabled = f != null ? f.CanDoSaveChanges : false;
      btnCancel.Enabled = f != null ? f.CanDoCancelChanges : false;
    }

    #region Button Click
    private void btnCancel_Click(object sender, EventArgs e)
    {
      if (f != null)
        f.CancelChanges();
    }

    private void btnSave_Click(object sender, EventArgs e)
    {
      if (f != null)
        f.SaveChanges();
    }

    private void btnDelete_Click(object sender, EventArgs e)
    {
      if (f != null)
        f.Delete();
    }

    private void btnEdit_Click(object sender, EventArgs e)
    {
      if (f != null)
        f.Edit();
    }

    private void btnNew_Click(object sender, EventArgs e)
    {
      if (f != null)
        f.New();
    }

    private void btnLast_Click(object sender, EventArgs e)
    {
      if (f != null)
        f.Last();
    }

    private void btnNext_Click(object sender, EventArgs e)
    {
      if (f != null)
        f.Next();
    }

    private void btnPrevious_Click(object sender, EventArgs e)
    {
      if (f != null)
        f.Previous();
    }

    private void btnFirst_Click(object sender, EventArgs e)
    {
      if (f != null)
        f.First();
    }
    #endregion
    #endregion
  }
}
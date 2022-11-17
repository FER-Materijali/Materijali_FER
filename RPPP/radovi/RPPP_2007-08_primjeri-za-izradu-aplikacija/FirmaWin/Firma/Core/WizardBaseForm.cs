using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

using NTier;

namespace Firma
{
  // Osnovna forma za sve wizard forme
  public partial class WizardBaseForm : Form
  {
    #region Vars
    protected WizardResult result = WizardResult.Cancel;
    #endregion

    #region Constructors
    public WizardBaseForm()
    {
      InitializeComponent();
    }
    #endregion

    #region Methods
    public WizardResult ShowWizard()
    {
      this.ShowDialog();
      return result;
    }
    #endregion

    private void WizardBaseForm_Load(object sender, EventArgs e)
    {
      Cursor.Current = Cursors.WaitCursor;
    }

    private void WizardBaseForm_Activated(object sender, EventArgs e)
    {
      Cursor.Current = Cursors.Default;
    }

    private void WizardBaseForm_FormClosing(object sender, FormClosingEventArgs e)
    {
      if (result == WizardResult.Next || result == WizardResult.Previous)
        Cursor.Current = Cursors.WaitCursor;
    }
  }
}
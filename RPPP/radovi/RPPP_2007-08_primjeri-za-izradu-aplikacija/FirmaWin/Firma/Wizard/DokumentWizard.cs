using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;

namespace Firma
{
  // Wizard unosa dokumenta
  public class DokumentWizard : IDisposable
  {
    // Pokreæe wizard unosa dokumenta
    public static void Run()
    {
      using (DokumentWizard dok = new DokumentWizard()) { }
    }

    #region Constructros
    private DokumentWizard()
    {
      ShowPartner();
    }
    #endregion

    #region Wizard Steps
    private PartnerWizardForm p;
    private void ShowPartner()
    {
      Cursor.Current = Cursors.WaitCursor;

      if (p == null)
        p = new PartnerWizardForm();
      Cursor.Current = Cursors.WaitCursor;
      WizardResult rez = p.ShowWizard();
      if (rez == WizardResult.Next)
      {
        ShowDokument();
      }
    }

    private DokumentWizardForm d;
    private void ShowDokument()
    {
      Cursor.Current = Cursors.WaitCursor;

      if (d == null)
        d = new DokumentWizardForm();

      d.SetPartner(p.Partner);
      WizardResult rez = d.ShowWizard();
      if (rez == WizardResult.Previous)
      {
        ShowPartner();
      }
    }
    #endregion

    #region IDisposable Members
    void IDisposable.Dispose()
    {
      if (d != null)
        d.Dispose();

      if (p != null)
        p.Dispose();
    }
    #endregion
  }
}

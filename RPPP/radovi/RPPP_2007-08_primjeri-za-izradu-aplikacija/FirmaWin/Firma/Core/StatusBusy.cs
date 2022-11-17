using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;

namespace Firma
{
  // Klasa koja mijenja znaèku miša 
  // da bi se korisniku dojavilo da mora prièekati.
  // Koristi se...
      // using(new StatusBusy()) // postavi znaèku na Wait
      // {
      //   ...
      // } // vrati kursor na staro
  // naredba using definira doseg nakon kojeg æe objekt biti uništen
  public class StatusBusy : IDisposable
  {
    private Cursor c;

    public StatusBusy()
    {
      this.c = Cursor.Current;
      Cursor.Current = Cursors.WaitCursor;
    }

    #region IDisposable Members
    void IDisposable.Dispose()
    {
      Cursor.Current = this.c;
    }
    #endregion
  }
}

using System;
using System.Collections.Generic;
using System.Windows.Forms;
using System.Threading;
using System.Security.Principal;

namespace Firma
{
  static class Program
  {
    /// <summary>
    /// The main entry point for the application.
    /// </summary>
    [STAThread]
    static void Main()
    {
      Application.EnableVisualStyles();
      Application.SetCompatibleTextRenderingDefault(false);

      LogInForm login = new LogInForm();
      if (login.ShowDialog() == DialogResult.OK)
      {
        FirmaApp.User = login.Username;
      }
      else
      {
        return;
      }

      Application.Run(new MainForm());
    }
  }
}
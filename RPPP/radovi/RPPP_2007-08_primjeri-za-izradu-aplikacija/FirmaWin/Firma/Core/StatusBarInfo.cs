using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;

namespace Firma
{
  // Wrapper oko statusne trake na glavnoj formi
  public class StatusBarInfo
  {
    #region Vars
    private string nazivModula = string.Empty;
    private string funkcija = string.Empty;
    private string message = string.Empty;
    private bool isError = false;
    #endregion

    #region Properties
    public string NazivModula
    {
      get { return nazivModula; }
      set
      {
        nazivModula = value;
        RefreshStatusBar();
      }
    }

    public string Funkcija
    {
      get { return funkcija; }
      set
      {
        funkcija = value;
        RefreshStatusBar();
      }
    }

    public string Message
    {
      get { return message; }
      set
      {
        message = value;
        RefreshStatusBar();
      }
    }

    public string User
    {
      get { return "Korisnik: " + FirmaApp.User; }
    }

    public bool IsError
    {
      get { return isError; }
      set
      {
        isError = value;
        RefreshStatusBar();
      }
    }
    #endregion

    #region StatusBar Methods
    public void RefreshStatusBar()
    {
      if (MainForm.Instance != null)
      {
        MainForm.Instance.SetStatusBar(this);
      }
    }

    public void ClearStatusBar()
    {
      if (MainForm.Instance != null)
      {
        MainForm.Instance.ClearStatusBar();
      }
    }
    #endregion
  }
}

using System;
using System.Data;
using System.Configuration;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;

/// <summary>
/// Summary description for RezultatAutorizacije
/// </summary>
public class RezultatAutorizacije
{
  private bool autorizirana;
  private string brojTransakcije = "";
  private string greska = "";

  public bool Autorizirirana
  {
    get { return autorizirana; }
    set { autorizirana = value; }
  }

  public string BrojTransakcije
  {
    get { return brojTransakcije; }
    set { brojTransakcije = value; }
  }

  public string Greska
  {
    get { return greska; }
    set { greska = value; }
  }


  public RezultatAutorizacije()
  {
  }
}

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
/// Summary description for PodaciOKartici
/// </summary>
public class PodaciOKartici
{
  public enum VrstaKartice
  {
    MasterCard, Visa, AmericanExpress, Diners
  }

  private string imePrezime;
  private string brojKartice;
  private int godinaVazenja;
  private int mjesecVazenja;
  private VrstaKartice vrsta;
  private decimal iznos;

  public decimal Iznos
  {
    get { return iznos; }
    set { iznos = value; }
  }

  public VrstaKartice Vrsta
  {
    get { return vrsta; }
    set { vrsta = value; }
  }

  public int MjesecVazenja
  {
    get { return mjesecVazenja; }
    set { mjesecVazenja = value; }
  }

  public int GodinaVazenja
  {
    get { return godinaVazenja; }
    set { godinaVazenja = value; }
  }

  public string BrojKartice
  {
    get { return brojKartice; }
    set { brojKartice = value; }
  }

  public string ImePrezime
  {
    get { return imePrezime; }
    set { imePrezime = value; }
  }

  public PodaciOKartici()
  {

  }
}

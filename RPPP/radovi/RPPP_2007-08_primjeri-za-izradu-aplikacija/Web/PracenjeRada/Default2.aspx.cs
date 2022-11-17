using System;
using System.Data;
using System.Configuration;
using System.Collections;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;

public partial class Default2 : System.Web.UI.Page
{
  protected void Page_Load(object sender, EventArgs e)
  {
    string ime = (string)Session["Ime"];
    if (ime != null)
    {
      lblIme.Text = ime;
      lblDatum.Text = ((DateTime)Session["DatumUnosaImena"]).ToString("dd.MM.yyyy HH:mm:ss");
    }
    else
    {
      lblIme.Text = "U session nije pospremljeno nikakvo ime";
    }
  }
}

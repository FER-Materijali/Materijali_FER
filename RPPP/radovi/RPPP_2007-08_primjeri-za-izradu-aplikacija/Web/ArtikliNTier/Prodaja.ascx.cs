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
using System.Drawing;

public partial class Prodaja : System.Web.UI.UserControl
{
  private Color labelColor;

  public Color LabelColor {
    get { return labelColor; }
    set { labelColor = value; }
  }
	
  protected void Page_Load(object sender, EventArgs e)
  {
    lblBrojNarudzbi.ForeColor = labelColor;
    PodaciWebService.PodaciOProdaji podaci = new PodaciWebService.PodaciOProdaji();
    lblBrojNarudzbi.Text = podaci.BrojNarudzbi().ToString();            
  }
}

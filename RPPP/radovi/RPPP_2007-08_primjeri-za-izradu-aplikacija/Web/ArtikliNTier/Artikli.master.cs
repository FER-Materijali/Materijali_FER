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

public partial class Artikli : System.Web.UI.MasterPage 
{
  protected void Page_Load(object sender, EventArgs e) 
  {
    Control c = LoadControl("Prodaja.ascx");
    ((Prodaja)c).LabelColor = System.Drawing.Color.Red;
    Panel1.Controls.Add(c);
  }
}

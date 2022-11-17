using System;
using System.Data;
using System.Configuration;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;
using System.Globalization;

public partial class _Default : System.Web.UI.Page
{
  protected void Page_Load(object sender, EventArgs e)
  {
    Response.Write("Server name: " + Server.MachineName + "<br/>");
    Response.Write("Zahtjev došao s adrese: " + Request.UserHostAddress + "<br/>");
    Response.Write("User: " + User.Identity.Name + "<br/>");
  }
  protected void btnKreni_Click(object sender, EventArgs e)
  {
    Response.Redirect("Default2.aspx");
  }
  protected void btnSpremi_Click(object sender, EventArgs e)
  {
    Trace.Write("Poèetak metode");
    if (tbIme.Text.Trim() != string.Empty)
    {
      Session["Ime"] = tbIme.Text.Trim();
      Session["DatumUnosaImena"] = DateTime.Now;
      Trace.Warn("Poèinje sleep");
      System.Threading.Thread.Sleep(2500);
      Trace.Warn("Sleep završio");
    }
    Trace.Write("Kraj");
  }
}

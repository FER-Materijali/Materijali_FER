using System;
using System.Data;
using System.Configuration;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;
using System.Resources;


public partial class _Default : System.Web.UI.Page
{
  protected void Page_Load(object sender, EventArgs e)
  {
    //lblPozdrav.Text = GetGlobalResourceObject("Poruke", "PozdravnaPoruka").ToString();      
    lblPozdrav.Text = Resources.Poruke.PozdravnaPoruka;

    lblDatum.Text = HttpContext.GetLocalResourceObject("~/Ostalo", "TekstZaDatum").ToString();
    lblDatum.Text += " " + DateTime.Now.ToString();

  }

  protected override void InitializeCulture()
  {
    string culture = Session["Culture"] as string;
    if (culture != null)
    {
      Page.Culture = culture;
      Page.UICulture = culture;
    }
    base.InitializeCulture();
  }

  protected void ddlOdabir_SelectedIndexChanged(object sender, EventArgs e)
  {
    lblOdabranaStavka.Text = this.GetLocalResourceObject("TekstZaOdabranuStavku").ToString();
    lblOdabranaStavka.Text += ddlOdabir.SelectedValue;
  }
  protected void btnHR_Click(object sender, EventArgs e)
  {
    Session["Culture"] = "hr-HR";
    Response.Redirect(Request.Url.OriginalString);
  }
  protected void btnEN_Click(object sender, EventArgs e)
  {
    Session["Culture"] = "en-US";
    Response.Redirect(Request.Url.OriginalString);
  }
}

using System;
using System.Data;
using System.Configuration;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;
using System.Drawing;

public partial class _Default : System.Web.UI.Page 
{
  //pozicija cijene unutar GridView-a
  const int POZICIJA_CIJENE = 3;
  //niske cijene se bojaju jednom bojom, visoke drugom, a sve ostale treæom bojo
  const int GRANICA_NISKE_CIJENE = 150;
  const int GRANICA_VISOKE_CIJENE = 300;
  //Color ne može biti const
  static readonly Color BOJA_NISKIH = Color.Green;
  static readonly Color BOJA_VISOKIH = Color.Red;
  static readonly Color BOJA_OSTALIH = Color.Blue;

  protected void Page_Load(object sender, EventArgs e)
  {
    //hlPlacanje.Visible = GridViewKosarica.Rows.Count > 0;
  }

  protected void GridView1_RowCommand(object sender, GridViewCommandEventArgs e)
  {
    if (e.CommandName == "Stavi")
    {
      GridView gridView = e.CommandSource as GridView;
      int Rbr = int.Parse(e.CommandArgument.ToString());

      //prva varijanta -> podatak se nalazi negdje u gridu (npr. u 0.stupcu), može biti i skriven
      //GridViewRow row = gridView.Rows[Rbr];
      //int SifArtikla = int.Parse(row.Cells[0].Text); 

      //druga varijanta -> preko primarnog kljuèa
      int SifArtikla = (int)gridView.DataKeys[Rbr].Value;

      KosaricaController.DodajUKosaricu(SifArtikla);

      //osvježi košaricu
      GridViewKosarica.DataBind();
      //hlPlacanje.Visible = GridViewKosarica.Rows.Count > 0;
    }
  }

  protected void btnPlacanje_Click(object sender, EventArgs e)
  {

  }

	protected void GridViewArtikli_RowDataBound(object sender, GridViewRowEventArgs e) {
		if (e.Row.RowType == DataControlRowType.DataRow) {
			//dohvati cijenu artikla    
			Firma.Artikl artikl = (Firma.Artikl)e.Row.DataItem;
			decimal? cijena = artikl.CijArtikla;
			//cijena je èetvrta po redu

			TableCell cell = e.Row.Cells[POZICIJA_CIJENE];
			if (cijena < GRANICA_NISKE_CIJENE) {
				cell.ForeColor = BOJA_NISKIH;
			}
			else if (cijena < GRANICA_VISOKE_CIJENE) {
				cell.ForeColor = BOJA_VISOKIH;
			}
			else {
				cell.ForeColor = BOJA_OSTALIH;
			}
		}
	}
}

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
using System.Collections.Generic;
using System.Data.SqlClient;

public partial class DataBindingFromDB : System.Web.UI.Page
{
  protected string MyProperty {
    get 
    {
      return "Trenutno je: " + DateTime.Now.ToString();
    }
  }

  protected void Page_Load(object sender, EventArgs e) 
  {
    lblTrenutniDatum.DataBind();
    //ako se postavke povezivanja nalaze su u aspx stranici
    lbxJezici.DataBind();

    //povezivanje iz koda:
    //using (IDataReader reader = DohvatiJezikeIzBaze()) 
    //{
    //  lbxJezici.DataSource = reader;
    //  lbxJezici.DataTextField = "NazJezika";
    //  lbxJezici.DataValueField = "IdJezika";
    //  lbxJezici.DataBind();
    //}
  }

  protected void rblStatus_SelectedIndexChanged(object sender, EventArgs e) 
  {
    RadioButtonList rbl = (RadioButtonList)sender;
    if (rbl.SelectedValue == "S") 
    {
      lblGodinaStudija.Visible = tbGodinaStudija.Visible = GodinaValidator1.Enabled = true;
    }
    else 
    {
      lblGodinaStudija.Visible = tbGodinaStudija.Visible = GodinaValidator1.Enabled = false;
    }

  }
  protected void btnPosalji_Click(object sender, EventArgs e) 
  {
    List<string> ListaJezika = new List<string>();
    foreach (ListItem item in lbxJezici.Items) 
    {
      if (item.Selected)
      {
        ListaJezika.Add(item.Text);
      }
    }
    int? godinaStudija = new Nullable<int>();
    if (tbGodinaStudija.Visible)
    {
      godinaStudija = int.Parse(tbGodinaStudija.Text);
    }
    string komentar = tbKomentar.Text;

    PosaljiKomentar.Posalji(ListaJezika, komentar, godinaStudija);
  }
  
  protected IDataReader DohvatiJezikeIzBaze() {
    string connectionString = ConfigurationManager.ConnectionStrings["MojaKonekcija"].ConnectionString;
    SqlConnection connection = new SqlConnection(connectionString);    
    SqlCommand command = new SqlCommand("SELECT * FROM Jezik", connection);
    connection.Open();
    return command.ExecuteReader(CommandBehavior.CloseConnection);    
  }

}

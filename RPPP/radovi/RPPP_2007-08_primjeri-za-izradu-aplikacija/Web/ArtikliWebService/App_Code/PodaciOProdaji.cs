using System;
using System.Web;
using System.Collections;
using System.Web.Services;
using System.Web.Services.Protocols;
using System.Data.SqlClient;
using System.Data;
using System.Configuration;


/// <summary>
/// Summary description for PodaciOProdaji
/// </summary>
[WebService(Namespace = "http://www.zpr.fer.hr/rppp")]
[WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
public class PodaciOProdaji : System.Web.Services.WebService
{

  public PodaciOProdaji()
  {
    //Uncomment the following line if using designed components 
    //InitializeComponent(); 
  }

  [WebMethod]
  public int BrojNarudzbi()
  {
    string connectionString = ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString;
    using (SqlConnection connection = new SqlConnection(connectionString))
    {
      SqlCommand command = new SqlCommand("SELECT COUNT(*) FROM dbo.Dokument WHERE VrDokumenta='R'", connection);
      command.CommandType = CommandType.Text;
      connection.Open();
      int brojNarudzbi = int.Parse(command.ExecuteScalar().ToString());
      return brojNarudzbi;
    }
  }

}


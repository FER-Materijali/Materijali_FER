using System;
using System.Collections.Generic;
using System.Text;
using System.Data.SqlClient;
using System.Configuration;
using System.Data;

namespace Firma
{
  public class SecurityDalProvider
  {
    public bool IsAuthenticated(string username, string password)
    {
      using (SqlConnection db = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString))
      {
        using (SqlCommand cmd = db.CreateCommand())
        {
          cmd.CommandText = "[dbo].[ap_Login]";
          cmd.CommandType = CommandType.StoredProcedure;
          cmd.Parameters.Add(new SqlParameter("@Username", username));
          cmd.Parameters.Add(new SqlParameter("@Password", password));

          db.Open();
          try
          {
            return Convert.ToInt32(cmd.ExecuteScalar()) == 1;
          }
          catch
          {
            return false;
          }
        }
      }
    }
  }
}

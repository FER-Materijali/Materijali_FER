using System;
using System.Collections.Generic;
using System.Text;
using System.Data;
using System.Data.SqlClient;
using System.Configuration;

using NTier;

namespace Firma
{
  // DAL klasa za mjesto
  public class MjestoDalProvider
  {
    #region Constructors
    public MjestoDalProvider()
    {
    }
    #endregion

    #region Fetch
    // Dohvat mjesta po razlièitim kriterijima

    public MjestoList FetchAll()
    {
      using (SqlConnection db = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString))
      {
        using (SqlCommand cmd = db.CreateCommand())
        {
          cmd.CommandText = "[dbo].[ap_MjestoList_R]";
          cmd.CommandType = CommandType.StoredProcedure;

          db.Open();
          using (SqlDataReader dr = cmd.ExecuteReader())
          {
            return MjestoList.CreateNew(dr);
          }
        }
      }
    }

    public Mjesto Fetch(int idMjesta)
    {
      using (SqlConnection db = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString))
      {
        using (SqlCommand cmd = db.CreateCommand())
        {
          cmd.CommandText = "[dbo].[ap_Mjesto_R]";
          cmd.CommandType = CommandType.StoredProcedure;
          cmd.Parameters.Add(new SqlParameter("@IdMjesta", idMjesta));

          db.Open();
          using (SqlDataReader dr = cmd.ExecuteReader())
          {
            if (dr != null && dr.Read())
            {
              return Mjesto.CreateNew(dr);
            }
            else
            {
              return null;
            }
          }
        }
      }
    }
    #endregion

    #region Save
    public void SaveChanges(List<Mjesto> changedItems)
    {
      // nije implementirano jer u primjeru nema unosa/izmjene podataka o mjestima
    }
    #endregion
  }
}

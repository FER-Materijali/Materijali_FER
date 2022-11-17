using System;
using System.Collections.Generic;
using System.Text;
using System.Data;
using System.Data.SqlClient;
using System.Configuration;

using NTier;

namespace Firma
{
  // DAL klasa za artikl
  public class ArtiklDalProvider
  {
    #region Constructors
    public ArtiklDalProvider()
    {
    }
    #endregion

    #region Fetch
    // Dohvat artikala po razlièitim kriterijima

    public ArtiklList FetchAll()
    {
      using (SqlConnection db = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString))
      {
        using (SqlCommand cmd = db.CreateCommand())
        {
          cmd.CommandText = "[dbo].[ap_ArtiklList_R]";
          cmd.CommandType = CommandType.StoredProcedure;

          db.Open();
          using (SqlDataReader dr = cmd.ExecuteReader())
          {
            return ArtiklList.CreateNew(dr);
          }
        }
      }
    }

    public Artikl Fetch(string nazArtikla)
    {
      return Fetch(null, nazArtikla);
    }

    public Artikl Fetch(int sifArtikla)
    {
      return Fetch(sifArtikla, null);
    }

    private Artikl Fetch(object sifArtikla, object nazArtikla)
    {
      using (SqlConnection db = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString))
      {
        using (SqlCommand cmd = db.CreateCommand())
        {
          cmd.CommandText = "[dbo].[ap_Artikl_R]";
          cmd.CommandType = CommandType.StoredProcedure;
          cmd.Parameters.Add(new SqlParameter("@SifArtikla", sifArtikla != null ? sifArtikla : DBNull.Value));
          cmd.Parameters.Add(new SqlParameter("@NazArtikla", nazArtikla != null ? nazArtikla : DBNull.Value));

          db.Open();
          using (SqlDataReader dr = cmd.ExecuteReader())
          {
            if (dr != null && dr.Read())
            {
              return Artikl.CreateNew(dr);
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
    // Spremanje izmjena u bazu
    public void SaveChanges(List<Artikl> changedItems)
    {
      using (SqlConnection db = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString))
      {
        db.Open();
        // Zapoèni transakciju
        using (SqlTransaction trans = db.BeginTransaction())
        {
          try
          {
            foreach (Artikl item in changedItems)
            {
              // Ako poslovni objekt nije mijenjan nemoj spremati
              if (!item.IsDirty)
                continue;

              using (SqlCommand cmd = db.CreateCommand())
              {
                cmd.Transaction = trans;
                switch (item.State)
                {
                  case BusinessObjectState.New: Insert(item, cmd); break;
                  case BusinessObjectState.Modified: Update(item, cmd); break;
                  case BusinessObjectState.Deleted: Delete(item, cmd); break;
                  default: break;
                }
              }
            }
            // Potvrdi transakciju
            trans.Commit();
          }
          catch (Exception err)
          {
            // Ako je došlo do pogreške poništi transakciju
            // i proslijedi pogrešku u BLL sloj.
            trans.Rollback();
            throw err;
          }
        }
      }
    }

    // Obavlja INSERT
    private void Insert(Artikl item, SqlCommand cmd)
    {
      cmd.CommandText = "[dbo].[ap_Artikl_C]";
      cmd.CommandType = CommandType.StoredProcedure;

      cmd.Parameters.Add(new SqlParameter("@SifArtikla", SqlDbType.Int)).Value = item.SifArtikla.HasValue ? (object)item.SifArtikla.Value : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@NazArtikla", SqlDbType.NVarChar)).Value = !string.IsNullOrEmpty(item.NazArtikla) ? (object)item.NazArtikla : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@JedMjere", SqlDbType.NVarChar)).Value = !string.IsNullOrEmpty(item.JedMjere) ? (object)item.JedMjere : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@CijArtikla", SqlDbType.Decimal)).Value = item.CijArtikla.HasValue ? (object)item.CijArtikla.Value : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@ZastUsluga", SqlDbType.Bit)).Value = item.ZastUsluga.HasValue ? (object)item.ZastUsluga.Value : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@SlikaArtikla", SqlDbType.VarBinary)).Value = item.SlikaArtikla != null ? (object)item.SlikaArtikla : DBNull.Value;

      cmd.ExecuteNonQuery();
    }

    // Obavlja UPDATE
    private void Update(Artikl item, SqlCommand cmd)
    {
      cmd.CommandText = "[dbo].[ap_Artikl_U]";
      cmd.CommandType = CommandType.StoredProcedure;

      cmd.Parameters.Add(new SqlParameter("@SifArtikla", SqlDbType.Int)).Value = item.SifArtikla.HasValue ? (object)item.SifArtikla.Value : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@NazArtikla", SqlDbType.NVarChar)).Value = !string.IsNullOrEmpty(item.NazArtikla) ? (object)item.NazArtikla : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@JedMjere", SqlDbType.NVarChar)).Value = !string.IsNullOrEmpty(item.JedMjere) ? (object)item.JedMjere : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@CijArtikla", SqlDbType.Decimal)).Value = item.CijArtikla.HasValue ? (object)item.CijArtikla.Value : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@ZastUsluga", SqlDbType.Bit)).Value = item.ZastUsluga.HasValue ? (object)item.ZastUsluga.Value : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@SlikaArtikla", SqlDbType.VarBinary)).Value = item.SlikaArtikla != null ? (object)item.SlikaArtikla : DBNull.Value;

      cmd.ExecuteNonQuery();
    }

    // Obavlja DELETE
    private void Delete(Artikl item, SqlCommand cmd)
    {
      cmd.CommandText = "[dbo].[ap_Artikl_D]";
      cmd.CommandType = CommandType.StoredProcedure;

      cmd.Parameters.Add(new SqlParameter("@SifArtikla", SqlDbType.Int)).Value = item.SifArtikla.HasValue ? (object)item.SifArtikla.Value : DBNull.Value;

      cmd.ExecuteNonQuery();
    }
    #endregion
  }
}

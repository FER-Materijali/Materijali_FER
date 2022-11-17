using System;
using System.Collections.Generic;
using System.Text;
using System.Data;
using System.Data.SqlClient;
using System.Configuration;

using NTier;

namespace Firma
{
  // DAL klasa za partnera
  public class PartnerDalProvider
  {
    #region Constructors
    public PartnerDalProvider()
    {
    }
    #endregion

    #region Fetch
    // Dohvat partnera po razlièitim kriterijima

    public PartnerList FetchAll()
    {
      using (SqlConnection db = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString))
      {
        using (SqlCommand cmd = db.CreateCommand())
        {
          cmd.CommandText = "[dbo].[ap_PartnerList_R]";
          cmd.CommandType = CommandType.StoredProcedure;

          db.Open();
          using (SqlDataReader dr = cmd.ExecuteReader())
          {
            return PartnerList.CreateNew(dr);
          }
        }
      }
    }

    public Partner Fetch(int idPartnera)
    {
      using (SqlConnection db = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString))
      {
        using (SqlCommand cmd = db.CreateCommand())
        {
          cmd.CommandText = "[dbo].[ap_Partner_R]";
          cmd.CommandType = CommandType.StoredProcedure;
          cmd.Parameters.Add(new SqlParameter("@IdPartnera", idPartnera));
          foreach (SqlParameter param in cmd.Parameters)
          {
            if (param.Value == null)
              param.Value = DBNull.Value;
          }

          db.Open();
          using (SqlDataReader dr = cmd.ExecuteReader())
          {
            if (dr != null && dr.Read())
            {
              return Partner.CreateNew(dr);
            }
            else
            {
              return null;
            }
          }
        }
      }
    }

    public Partner FetchByJMBG(string jmbg)
    {
      using (SqlConnection db = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString))
      {
        using (SqlCommand cmd = db.CreateCommand())
        {
          cmd.CommandText = "[dbo].[ap_Partner_R]";
          cmd.CommandType = CommandType.StoredProcedure;
          cmd.Parameters.Add(new SqlParameter("@JMBG", jmbg));
          foreach (SqlParameter param in cmd.Parameters)
          {
            if (param.Value == null)
              param.Value = DBNull.Value;
          }

          db.Open();
          using (SqlDataReader dr = cmd.ExecuteReader())
          {
            if (dr != null && dr.Read())
            {
              return Partner.CreateNew(dr);
            }
            else
            {
              return null;
            }
          }
        }
      }
    }

    public Partner FetchByMatBr(string matBr)
    {
      using (SqlConnection db = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString))
      {
        using (SqlCommand cmd = db.CreateCommand())
        {
          cmd.CommandText = "[dbo].[ap_Partner_R]";
          cmd.CommandType = CommandType.StoredProcedure;
          cmd.Parameters.Add(new SqlParameter("@MatBr", matBr));
          foreach (SqlParameter param in cmd.Parameters)
          {
            if (param.Value == null)
              param.Value = DBNull.Value;
          }

          db.Open();
          using (SqlDataReader dr = cmd.ExecuteReader())
          {
            if (dr != null && dr.Read())
            {
              return Partner.CreateNew(dr);
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
    public void SaveChanges(List<Partner> changedItems)
    {
      using (SqlConnection db = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString))
      {
        db.Open();
        // Zapoèni transakciju
        using (SqlTransaction trans = db.BeginTransaction())
        {
          try
          {
            foreach (Partner item in changedItems)
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
    private void Insert(Partner item, SqlCommand cmd)
    {
      cmd.CommandText = "[dbo].[ap_Partner_C]";
      cmd.CommandType = CommandType.StoredProcedure;

      cmd.Parameters.Add(new SqlParameter("@IdPartnera", SqlDbType.Int));
      cmd.Parameters["@IdPartnera"].Direction = ParameterDirection.Output;

      cmd.Parameters.Add(new SqlParameter("@TipPartnera", SqlDbType.NVarChar)).Value = item.TipPartnera != TipPartnera.Nedefinirano ? (object)item.TipPartnera : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@IdMjestaPartnera", SqlDbType.Int)).Value = item.IdMjestaPartnera.HasValue ? (object)item.IdMjestaPartnera.Value : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@AdrPartnera", SqlDbType.NVarChar)).Value = !string.IsNullOrEmpty(item.AdrPartnera) ? (object)item.AdrPartnera : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@IdMjestaIsporuke", SqlDbType.Int)).Value = item.IdMjestaIsporuke.HasValue ? (object)item.IdMjestaIsporuke.Value : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@AdrIsporuke", SqlDbType.NVarChar)).Value = !string.IsNullOrEmpty(item.AdrIsporuke) ? (object)item.AdrIsporuke : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@MatBrTvrtke", SqlDbType.NVarChar)).Value = !string.IsNullOrEmpty(item.MatBrTvrtke) ? (object)item.MatBrTvrtke : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@NazivTvrtke", SqlDbType.NVarChar)).Value = !string.IsNullOrEmpty(item.NazivTvrtke) ? (object)item.NazivTvrtke : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@JMBG", SqlDbType.NVarChar)).Value = !string.IsNullOrEmpty(item.JMBG) ? (object)item.JMBG : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@PrezimeOsobe", SqlDbType.NVarChar)).Value = !string.IsNullOrEmpty(item.PrezimeOsobe) ? (object)item.PrezimeOsobe : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@ImeOsobe", SqlDbType.NVarChar)).Value = !string.IsNullOrEmpty(item.ImeOsobe) ? (object)item.ImeOsobe : DBNull.Value;

      cmd.ExecuteNonQuery();

      item.IdPartnera = (int?)cmd.Parameters["@IdPartnera"].Value;
    }

    // Obavlja UPDATE
    private void Update(Partner item, SqlCommand cmd)
    {
      cmd.CommandText = "[dbo].[ap_Partner_U]";
      cmd.CommandType = CommandType.StoredProcedure;

      cmd.Parameters.Add(new SqlParameter("@IdPartnera", SqlDbType.Int)).Value = item.IdPartnera.HasValue ? (object)item.IdPartnera.Value : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@TipPartnera", SqlDbType.NVarChar)).Value = item.TipPartnera != TipPartnera.Nedefinirano ? (object)item.TipPartnera : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@IdMjestaPartnera", SqlDbType.Int)).Value = item.IdMjestaPartnera.HasValue ? (object)item.IdMjestaPartnera.Value : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@AdrPartnera", SqlDbType.NVarChar)).Value = !string.IsNullOrEmpty(item.AdrPartnera) ? (object)item.AdrPartnera : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@IdMjestaIsporuke", SqlDbType.Int)).Value = item.IdMjestaIsporuke.HasValue ? (object)item.IdMjestaIsporuke.Value : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@AdrIsporuke", SqlDbType.NVarChar)).Value = !string.IsNullOrEmpty(item.AdrIsporuke) ? (object)item.AdrIsporuke : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@MatBrTvrtke", SqlDbType.NVarChar)).Value = !string.IsNullOrEmpty(item.MatBrTvrtke) ? (object)item.MatBrTvrtke : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@NazivTvrtke", SqlDbType.NVarChar)).Value = !string.IsNullOrEmpty(item.NazivTvrtke) ? (object)item.NazivTvrtke : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@JMBG", SqlDbType.NVarChar)).Value = !string.IsNullOrEmpty(item.JMBG) ? (object)item.JMBG : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@PrezimeOsobe", SqlDbType.NVarChar)).Value = !string.IsNullOrEmpty(item.PrezimeOsobe) ? (object)item.PrezimeOsobe : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@ImeOsobe", SqlDbType.NVarChar)).Value = !string.IsNullOrEmpty(item.ImeOsobe) ? (object)item.ImeOsobe : DBNull.Value;

      cmd.ExecuteNonQuery();
    }

    // Obavlja DELETE
    private void Delete(Partner item, SqlCommand cmd)
    {
      cmd.CommandText = "[dbo].[ap_Partner_D]";
      cmd.CommandType = CommandType.StoredProcedure;

      cmd.Parameters.Add(new SqlParameter("@IdPartnera", SqlDbType.Int)).Value = item.IdPartnera.HasValue ? (object)item.IdPartnera.Value : DBNull.Value;

      cmd.ExecuteNonQuery();
    }
    #endregion
  }
}

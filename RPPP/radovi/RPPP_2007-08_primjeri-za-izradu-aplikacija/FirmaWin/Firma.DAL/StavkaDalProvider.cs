using System;
using System.Collections.Generic;
using System.Text;
using System.Data;
using System.Data.SqlClient;
using System.Configuration;

using NTier;

namespace Firma
{
  // DAL klasa za stavku dokumenta
  public class StavkaDalProvider : IStavkaDalProvider
  {
    #region Constructors
    public StavkaDalProvider()
    {
    }
    #endregion

    #region Fetch
    // Dohvat stavaka za odreðeni dokument
    public StavkaList FetchAll(int idDokumenta)
    {
      using (SqlConnection db = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString))
      {
        using (SqlCommand cmd = db.CreateCommand())
        {
          cmd.CommandText = "[dbo].[ap_StavkaList_R]";
          cmd.CommandType = CommandType.StoredProcedure;
          cmd.Parameters.Add(new SqlParameter("@IdDokumenta", idDokumenta));

          db.Open();
          using (SqlDataReader dr = cmd.ExecuteReader())
          {
            return StavkaList.CreateNew(dr);
          }
        }
      }
    }
    #endregion

    #region Save
    // Spremanje izmjena u bazu
    public void SaveChanges(List<Stavka> changedItems, SqlConnection masterDb, SqlTransaction masterTrans)
    {
      // Ako sa konekcijom na bazu i transakcijom ne upravlja iz
      // zaglavlja stvori novu konekciju. Inaèe koristi konekciju i transakciju zaglavlja.
      SqlConnection db = masterDb == null ? new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString) : masterDb;
      SqlTransaction trans = masterTrans;

      try
      {
        // Ako sa konekcijom na bazu i transakcijom ne upravlja iz
        // zaglavlja otvori konekciju i zapoèni transakciju.
        if (masterDb == null)
        {
          db.Open();
          trans = db.BeginTransaction();
        }

        try
        {
          foreach (Stavka item in changedItems)
          {
            // Ako poslovni objekt nije mijenjan nemoj spremati
            if (!item.IsDirty)
              continue;

            SqlCommand cmd = db.CreateCommand();
            cmd.Transaction = trans;
            switch (item.State)
            {
              case BusinessObjectState.New: Insert(item, cmd); break;
              case BusinessObjectState.Modified: Update(item, cmd); break;
              case BusinessObjectState.Deleted: Delete(item, cmd); break;
              default: break;
            }
          }
          // Ako sa konekcijom na bazu i transakcijom ne upravlja iz
          // zaglavlja potvrdi transakciju.
          if (masterDb == null)
          {
            trans.Commit();
          }
        }
        catch (Exception err)
        {
          // Ako je došlo do pogreške a sa konekcijom na bazu i 
          // transakcijom se ne upravlja iz zaglavlja,
          // poništi transakciju.
          if (masterDb == null)
          {
            trans.Rollback();
          }
          // Proslijedi pogrešku.
          throw err;
        }

      }
      finally
      {
        // Ako sa konekcijom na bazu i transakcijom ne upravlja iz
        // zaglavlja zatvori konekciju.
        if (masterDb == null)
        {
          trans.Dispose();
          db.Close();
          db.Dispose();
        }
      }
    }

    // Obavlja INSERT
    private void Insert(Stavka item, SqlCommand cmd)
    {
      cmd.CommandText = "[dbo].[ap_Stavka_C]";
      cmd.CommandType = CommandType.StoredProcedure;

      cmd.Parameters.Add(new SqlParameter("@IdDokumenta", SqlDbType.Int)).Value = item.IdDokumenta.HasValue ? (object)item.IdDokumenta.Value : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@SifArtikla", SqlDbType.Int)).Value = item.SifArtikla.HasValue ? (object)item.SifArtikla.Value : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@KolArtikla", SqlDbType.Decimal)).Value = item.KolArtikla.HasValue ? (object)item.KolArtikla.Value : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@JedCijArtikla", SqlDbType.Decimal)).Value = item.JedCijArtikla.HasValue ? (object)item.JedCijArtikla.Value : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@PostoRabat", SqlDbType.Decimal)).Value = item.PostoRabat.HasValue ? (object)item.PostoRabat.Value : DBNull.Value;

      cmd.ExecuteNonQuery();
    }

    // Obavlja UPDATE
    private void Update(Stavka item, SqlCommand cmd)
    {
      cmd.CommandText = "[dbo].[ap_Stavka_U]";
      cmd.CommandType = CommandType.StoredProcedure;

      cmd.Parameters.Add(new SqlParameter("@IdDokumenta", SqlDbType.Int)).Value = item.IdDokumenta.HasValue ? (object)item.IdDokumenta.Value : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@SifArtikla", SqlDbType.Int)).Value = item.SifArtikla.HasValue ? (object)item.SifArtikla.Value : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@KolArtikla", SqlDbType.Decimal)).Value = item.KolArtikla.HasValue ? (object)item.KolArtikla.Value : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@JedCijArtikla", SqlDbType.Decimal)).Value = item.JedCijArtikla.HasValue ? (object)item.JedCijArtikla.Value : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@PostoRabat", SqlDbType.Decimal)).Value = item.PostoRabat.HasValue ? (object)item.PostoRabat.Value : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@IdDokumenta_Original", SqlDbType.Int)).Value = item.IdDokumenta_Original.HasValue ? (object)item.IdDokumenta_Original.Value : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@SifArtikla_Original", SqlDbType.Int)).Value = item.SifArtikla_Original.HasValue ? (object)item.SifArtikla_Original.Value : DBNull.Value;

      cmd.ExecuteNonQuery();
    }

    // Obavlja DELETE
    private void Delete(Stavka item, SqlCommand cmd)
    {
      cmd.CommandText = "[dbo].[ap_Stavka_D]";
      cmd.CommandType = CommandType.StoredProcedure;

      cmd.Parameters.Add(new SqlParameter("@IdDokumenta", SqlDbType.Int)).Value = item.IdDokumenta.HasValue ? (object)item.IdDokumenta.Value : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@SifArtikla", SqlDbType.Int)).Value = item.SifArtikla.HasValue ? (object)item.SifArtikla.Value : DBNull.Value;

      cmd.ExecuteNonQuery();
    }
    #endregion
  }
}

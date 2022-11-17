using System;
using System.Collections.Generic;
using System.Text;
using System.Data.SqlClient;
using System.Configuration;
using System.Data;

using NTier;

namespace Firma
{
  // DAL klasa za dokument
  public class DokumentDalProvider
  {
    #region Vars
    // DAL klasa za stavke dokumenta
    private StavkaDalProvider dalStavka = new StavkaDalProvider();
    #endregion

    #region Constructors
    public DokumentDalProvider()
    {
    }
    #endregion

    #region Fetch
    // Dohvat dokumenata po razlièitim kriterijima

    public DokumentList FetchAll()
    {
      using (SqlConnection db = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString))
      {
        using (SqlCommand cmd = db.CreateCommand())
        {
          cmd.CommandText = "[dbo].[ap_DokumentList_R]";
          cmd.CommandType = CommandType.StoredProcedure;

          db.Open();
          using (SqlDataReader dr = cmd.ExecuteReader())
          {
            // Uèitavanje rezultantnog skupa u listu dokumenata.
            // DAL objekt stavaka se predaje konstruktoru 
            // jer za svaki uèitani dokument treba uèitati i njegove stavke.
            return DokumentList.CreateNew(dr, dalStavka);
          }
        }
      }
    }

    public Dokument Fetch(int brDokumenta, string vrDokumenta)
    {
      using (SqlConnection db = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString))
      {
        using (SqlCommand cmd = db.CreateCommand())
        {
          cmd.CommandText = "[dbo].[ap_Dokument_R]";
          cmd.CommandType = CommandType.StoredProcedure;
          cmd.Parameters.Add(new SqlParameter("@BrDokumenta", brDokumenta));
          cmd.Parameters.Add(new SqlParameter("@VrDokumenta", vrDokumenta));

          db.Open();
          using (SqlDataReader dr = cmd.ExecuteReader())
          {
            if (dr != null && dr.Read())
            {
              return Dokument.CreateNew(dr, dalStavka);
            }
            else
            {
              return null;
            }
          }
        }
      }
    }

    public Dokument Fetch(int idDokumenta)
    {
      using (SqlConnection db = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString))
      {
        using (SqlCommand cmd = db.CreateCommand())
        {
          cmd.CommandText = "[dbo].[ap_Dokument_R_IdDokumenta]";
          cmd.CommandType = CommandType.StoredProcedure;
          cmd.Parameters.Add(new SqlParameter("@IdDokumenta", idDokumenta));

          db.Open();
          using (SqlDataReader dr = cmd.ExecuteReader())
          {
            if (dr != null && dr.Read())
            {
              return Dokument.CreateNew(dr, dalStavka);
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
    public void SaveChanges(List<Dokument> changedItems)
    {
      using (SqlConnection db = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString))
      {
        db.Open();
        // Zapoèni transakciju
        using (SqlTransaction trans = db.BeginTransaction())
        {
          try
          {
            foreach (Dokument item in changedItems)
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
    private void Insert(Dokument item, SqlCommand cmd)
    {
      cmd.CommandText = "[dbo].[ap_Dokument_C]";
      cmd.CommandType = CommandType.StoredProcedure;

      cmd.Parameters.Add(new SqlParameter("@VrDokumenta", SqlDbType.NVarChar)).Value = !string.IsNullOrEmpty(item.VrDokumenta) ? (object)item.VrDokumenta : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@BrDokumenta", SqlDbType.Int)).Value = item.BrDokumenta.HasValue ? (object)item.BrDokumenta.Value : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@DatDokumenta", SqlDbType.DateTime)).Value = item.DatDokumenta.HasValue ? (object)item.DatDokumenta.Value : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@IdPartnera", SqlDbType.Int)).Value = item.IdPartnera.HasValue ? (object)item.IdPartnera.Value : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@IdPrethDokumenta", SqlDbType.Int)).Value = item.IdPrethDokumenta.HasValue ? (object)item.IdPrethDokumenta.Value : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@PostoPorez", SqlDbType.Decimal)).Value = item.PostoPorez.HasValue ? (object)item.PostoPorez.Value : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@IznosDokumenta", SqlDbType.Decimal)).Value = item.IznosDokumenta.HasValue ? (object)item.IznosDokumenta.Value : DBNull.Value;

      // Posebno dodavanje OUTPUT parametra
      cmd.Parameters.Add(new SqlParameter("@IdDokumenta", SqlDbType.Int));
      cmd.Parameters["@IdDokumenta"].Direction = ParameterDirection.Output;

      cmd.ExecuteNonQuery();

      // Dohvat OUTPUT vrijednosti
      item.IdDokumenta = (int?)cmd.Parameters["@IdDokumenta"].Value;

      // Spremanje stavaka. Spremanje se obavlja na istoj
      // konekciji, u istoj transakciji.
      SaveChangesOnStavke(item, cmd.Connection, cmd.Transaction);
    }

    // Obavlja UPDATE
    private void Update(Dokument item, SqlCommand cmd)
    {
      cmd.CommandText = "[dbo].[ap_Dokument_U]";
      cmd.CommandType = CommandType.StoredProcedure;

      cmd.Parameters.Add(new SqlParameter("@IdDokumenta", SqlDbType.Int)).Value = item.IdDokumenta.HasValue ? (object)item.IdDokumenta.Value : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@DatDokumenta", SqlDbType.DateTime)).Value = item.DatDokumenta.HasValue ? (object)item.DatDokumenta.Value : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@IdPartnera", SqlDbType.Int)).Value = item.IdPartnera.HasValue ? (object)item.IdPartnera.Value : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@IdPrethDokumenta", SqlDbType.Int)).Value = item.IdPrethDokumenta.HasValue ? (object)item.IdPrethDokumenta.Value : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@PostoPorez", SqlDbType.Decimal)).Value = item.PostoPorez.HasValue ? (object)item.PostoPorez.Value : DBNull.Value;
      cmd.Parameters.Add(new SqlParameter("@IznosDokumenta", SqlDbType.Decimal)).Value = item.IznosDokumenta.HasValue ? (object)item.IznosDokumenta.Value : DBNull.Value;

      cmd.ExecuteNonQuery();

      // Spremanje stavaka. Spremanje se obavlja na istoj
      // konekciji, u istoj transakciji.
      SaveChangesOnStavke(item, cmd.Connection, cmd.Transaction);
    }

    // Obavlja DELETE
    private void Delete(Dokument item, SqlCommand cmd)
    {
      cmd.CommandText = "[dbo].[ap_Dokument_D]";
      cmd.CommandType = CommandType.StoredProcedure;

      cmd.Parameters.Add(new SqlParameter("@IdDokumenta", SqlDbType.Int)).Value = item.IdDokumenta.HasValue ? (object)item.IdDokumenta.Value : DBNull.Value;

      cmd.ExecuteNonQuery();
    }

    // Spremanje svake stavke
    private void SaveChangesOnStavke(Dokument target, SqlConnection db, SqlTransaction trans)
    {
      foreach (Stavka s in target.Stavke)
      {
        if (!s.IdDokumenta.Equals(target.IdDokumenta))
        {
          s.IdDokumenta = target.IdDokumenta;
        }
      }

      // Spremanje stavke. Spremanje se obavlja na istoj
      // konekciji, u istoj transakciji.
      dalStavka.SaveChanges(target.Stavke.GetChanges(), db, trans);
    }
    #endregion
  }
}

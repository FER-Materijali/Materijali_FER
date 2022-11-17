using System;
using System.Data;
using System.Web;
using System.Collections;
using System.Web.Services;
using System.Web.Services.Protocols;
using System.ComponentModel;
using System.Data.SqlClient;
using System.Configuration;
using System.Collections.Generic;

using Firma;

namespace FirmaServis
{
  /// <summary>
  /// Summary description for Service1
  /// </summary>
  [WebService(Namespace = "http://tempuri.org/")]
  [WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
  [ToolboxItem(false)]
  public class Service1 : System.Web.Services.WebService
  {

    [WebMethod]
    public StavkaList DohvatiStavkeUkupno(DateTime DatumOd, DateTime DatumDo)
    {
      string upit =
        "SELECT TOP 10 Stavka.SifArtikla AS Sifra, Artikl.NazArtikla AS Naziv, SUM(KolArtikla) AS Kolicina " +
        "FROM Dokument, Stavka, Artikl " +
        "WHERE Stavka.IdDokumenta = Dokument.IdDokumenta " +
        "AND Artikl.SifArtikla = Stavka.SifArtikla " +
        "AND Dokument.DatDokumenta >= '" + DatumOd.Year.ToString() + "-" + DatumOd.Month.ToString() + "-" + DatumOd.Day.ToString() + "' " +
        "AND Dokument.DatDokumenta <= '" + DatumDo.Year.ToString() + "-" + DatumDo.Month.ToString() + "-" + DatumDo.Day.ToString() + "' " +
        "AND Dokument.VrDokumenta = 'O' " +
        "GROUP BY Stavka.SifArtikla, Artikl.NazArtikla " +
        "ORDER BY Kolicina DESC";

      SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ToString());
      conn.Open();
      SqlCommand cmd = new SqlCommand(upit, conn);
      SqlDataReader reader = cmd.ExecuteReader();
      StavkaList lista = new StavkaList();

      while (reader.Read())
      {
        Stavka s = new Stavka();
        s.SifArtikla = (int?)reader["Sifra"];
        s.NazArtikla = (string)reader["Naziv"];
        s.KolArtikla = (decimal?)reader["Kolicina"];
        lista.Add(s);
      }

      conn.Close();
      return lista;
    }


    [WebMethod]
    public void NapraviNarudzbu(Stavka[] listaStavki)
    {
      DokumentList dokumenti = new DokumentList();
      Dokument dok = dokumenti.AddNew();

      dok.VrDokumenta = "N";
      dok.DatDokumenta = DateTime.Now;
      dok.PostoPorez = 0;
      dok.BrDokumenta = NaredniBrDokumenta();
      dok.IdPartnera = 0;

      foreach (Stavka s in listaStavki)
      {
        Stavka nova = dok.Stavke.AddNew();
        nova.SifArtikla = s.SifArtikla;
        nova.JedCijArtikla = 0;
        nova.KolArtikla = s.KolArtikla;
        nova.NazArtikla = s.NazArtikla;
        nova.PostoRabat = 0;
      }

      DokumentBllProvider dokumentBll = new DokumentBllProvider();
      dokumentBll.SaveChanges(dokumenti.GetChanges());
    }


    private int NaredniBrDokumenta()
    {
      SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ToString());
      conn.Open();
      SqlCommand cmd = new SqlCommand("SELECT MAX(BrDokumenta)+1 from Dokument", conn);
      int broj = (int)cmd.ExecuteScalar();
      conn.Close();
      return broj;
    }
  }
}

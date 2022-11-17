using System;
using System.Data;
using System.Configuration;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;
using System.Collections.Generic;
using System.ComponentModel;
using Firma;

/// <summary>
/// Summary description for KosaricaController
/// </summary>
public class KosaricaController
{
  public static void DodajUKosaricu(int SifraArtikla)
  {
    Firma.ArtiklBllProvider bllProvider = new Firma.ArtiklBllProvider();
    Artikl artikl = bllProvider.Fetch(SifraArtikla);
    Stavka stavka = new Stavka();
    stavka.SifArtikla = SifraArtikla;
    stavka.JedCijArtikla = artikl.CijArtikla;
    stavka.JedMjereArtikla = artikl.JedMjere;
    stavka.NazArtikla = artikl.NazArtikla;
    stavka.KolArtikla = 1;

    List<Stavka> kosarica = HttpContext.Current.Session["Kosarica"] as List<Stavka>;
    if (kosarica == null)
    {
      kosarica = new List<Stavka>();
      HttpContext.Current.Session["Kosarica"] = kosarica;
    }
    //potraži da li se navedeni artikl veæ nalazi u košarici
    for (int i = 0; i < kosarica.Count; i++)
    {
      if (kosarica[i].SifArtikla == SifraArtikla)
      {
        kosarica[i].KolArtikla++;
        return;
      }
    }
    
    kosarica.Add(stavka);
  }

  [DataObjectMethod(DataObjectMethodType.Select, true)]
  public static List<Stavka> DohvatiArtikle()
  {
    List<Stavka> kosarica = HttpContext.Current.Session["Kosarica"] as List<Stavka>;
    if (kosarica == null)
    {
      return new List<Stavka>();
    }
    else
    {
      return kosarica;
    }
  }

  [DataObjectMethod(DataObjectMethodType.Delete, true)]
  public static void IzbrisiArtikl(int SifArtikla)
  {
    List<Stavka> kosarica = HttpContext.Current.Session["Kosarica"] as List<Stavka>;
    if (kosarica != null)
    {
      int pos = -1;
      for (int i = 0; i < kosarica.Count; i++)
      {
        if (kosarica[i].SifArtikla == SifArtikla)
        {
          pos = i;
          break;
        }
      }
      if (pos != -1)
      {
        kosarica.RemoveAt(pos);
      }
    }
  }

  [DataObjectMethod(DataObjectMethodType.Update, true)]
  public static void AzurirajKolicinu(int KolArtikla, int SifArtikla)
  {
    List<Stavka> kosarica = HttpContext.Current.Session["Kosarica"] as List<Stavka>;
    if (kosarica != null)
    {
      for (int i = 0; i < kosarica.Count; i++)
      {
        if (kosarica[i].SifArtikla == SifArtikla)
        {
          kosarica[i].KolArtikla = KolArtikla;
          return;
        }
      }
    }
  }

  public static void ObrisiSve()
  {
    HttpContext.Current.Session["Kosarica"] = null;
  }

  public static decimal Ukupno()
  {
    decimal sum = 0;
    List<Stavka> kosarica = HttpContext.Current.Session["Kosarica"] as List<Stavka>;
    if (kosarica != null)
    {
      foreach (Stavka stavka in kosarica)
      {
        sum += stavka.Iznos.Value;
      }
    }
    return sum;
  }
}

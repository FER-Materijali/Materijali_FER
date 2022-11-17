using System;
using System.Web;
using System.Web.Services;
using System.Web.Services.Protocols;

[WebService(Namespace = "http://www.zpr.fer.hr/rppp")]
[WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
public class AutorizacijaKartica : System.Web.Services.WebService
{
  public AutorizacijaKartica()
  {

    //Uncomment the following line if using designed components 
    //InitializeComponent(); 
  }

  [WebMethod]
  public RezultatAutorizacije Autorizacija(PodaciOKartici podaci)
  {
    RezultatAutorizacije rezultat = new RezultatAutorizacije();
    rezultat.Autorizirirana = false;
    bool ok = _ProvjeriDatumKartice(podaci.GodinaVazenja, podaci.MjesecVazenja);
    if (!ok)
    {
      rezultat.Greska = "Valjanost kartice je istekla";
      return rezultat;
    }
    switch (podaci.Vrsta)
    {
      case PodaciOKartici.VrstaKartice.AmericanExpress:
        //prvi broj mora biti 1                
        rezultat.Autorizirirana = podaci.BrojKartice[0] == '1';
        break;
      case PodaciOKartici.VrstaKartice.Diners:
        //prvi broj mora biti 2                
        rezultat.Autorizirirana = podaci.BrojKartice[0] == '2';
        break;
      case PodaciOKartici.VrstaKartice.MasterCard:
        //prvi broj mora biti 3                
        rezultat.Autorizirirana = podaci.BrojKartice[0] == '3';
        break;
      case PodaciOKartici.VrstaKartice.Visa:
        //prvi broj mora biti 4                
        rezultat.Autorizirirana = podaci.BrojKartice[0] == '4';
        break;
    }
    if (!rezultat.Autorizirirana)
    {
      rezultat.Greska = "Autorizacija odbijena";
    }
    return rezultat;

  }

  private bool _ProvjeriDatumKartice(int godina, int mjesec)
  {
    bool ok;
    DateTime datum = DateTime.Now;
    if (godina < datum.Year)
    {
      ok = false;
    }
    else if (godina > datum.Year)
    {
      ok = true;
    }
    else if (mjesec < datum.Month)
    {
      ok = false;
    }
    else
    {
      ok = true;
    }
    return ok;
  }

}

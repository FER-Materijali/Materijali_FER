using System;
using System.Data;
using System.Configuration;
using System.Collections;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;
using System.IO;
using System.Net.Mail;
using System.Net.Configuration;
using System.Web.Configuration;
using System.Collections.Generic;

public partial class Placanje : System.Web.UI.Page
{
  const int POSTARINA_POSTOM = 30;
  const int POSTARINA_KURIRSKOM_DOSTAVOM = 90;
  protected void Page_Load(object sender, EventArgs e)
  {
    if (KosaricaController.DohvatiArtikle().Count == 0) 
    {
      Response.Redirect("Default.aspx");
    }
    decimal postarina = IzracunPostarine();
    lblPostarina.Text = lblPostarina2.Text = postarina.ToString("0.00");
    lblUkupnaCijena.Text = lblUkupnaCijena2.Text = (KosaricaController.Ukupno() + postarina).ToString("0.00");
  }
  protected void btnDohvatiPodatke_Click(object sender, EventArgs e)
  {
    string mbr = tbMBR.Text.Trim();
    if (mbr != string.Empty)
    {
      //pronaæi da li navedeni kupac postoji
      Firma.PartnerBllProvider partnerBllProvider = new Firma.PartnerBllProvider();
      Firma.Partner partner = null;
      if (mbr.Length == 13) 
      {
        partner = partnerBllProvider.FetchByJMBG(mbr);
      } 
      else 
      {
        partner = partnerBllProvider.FetchByMatBr(mbr);
      } 

      if (partner != null)
      {
        tbAdresaRacuna.Text = partner.AdrPartnera;
        tbAdresaIsporuke.Text = partner.AdrIsporuke;
        tbImePrezime.Text = partner.Naziv;
      }
    }
  }

  protected void Wizard1_FinishButtonClick(object sender, WizardNavigationEventArgs e)
  {

    AuthorizationWebService.PodaciOKartici podaci = new AuthorizationWebService.PodaciOKartici();
    string vrsta = ddlVrstaKartice.SelectedValue;
    switch (vrsta)
    {
      case "MC":
        podaci.Vrsta = AuthorizationWebService.VrstaKartice.MasterCard;
        break;
      case "Diners":
        podaci.Vrsta = AuthorizationWebService.VrstaKartice.Diners;
        break;
      case "AMEX":
        podaci.Vrsta = AuthorizationWebService.VrstaKartice.AmericanExpress;
        break;
      case "Visa":
        podaci.Vrsta = AuthorizationWebService.VrstaKartice.Visa;
        break;
    }
    podaci.MjesecVazenja = int.Parse(ddlMjesec.SelectedValue);
    podaci.GodinaVazenja = int.Parse(ddlGodina.SelectedValue);
    podaci.ImePrezime = tbVlasnik.Text.Trim();
    if (podaci.ImePrezime == string.Empty)
    {
      lblGreska.Text = "Potrebno je unijeti ime i prezime vlasnika kartice";
      lblGreska.Visible = true;
      e.Cancel = true;
      return;
    }
    podaci.BrojKartice = tbBrojKartice.Text.Trim();
    if (podaci.BrojKartice == string.Empty)
    {
      lblGreska.Text = "Potrebno je unijeti broj kartice";
      lblGreska.Visible = true;
      e.Cancel = true;
      return;
    }

    //raèunanje iznosa:
    podaci.Iznos = KosaricaController.Ukupno();
    podaci.Iznos += IzracunPostarine();

    //pokušaj autorizacije
    AuthorizationWebService.AutorizacijaKartica ws = new AuthorizationWebService.AutorizacijaKartica();
    AuthorizationWebService.RezultatAutorizacije rezultat = ws.Autorizacija(podaci);
    if (rezultat.Autorizirirana)
    {
      //treba povezati u ovom trenutku, jer æe prilikom automatskog povezivanja košarica biti prazna
      RacunRepeater.DataBind();
      PopuniRacun(rezultat.BrojTransakcije);
      try 
      {
        PosaljiEmail();
        lblEmailGreska.Visible = false;
      }
      catch (Exception exc) 
      {
        lblEmailGreska.Visible = true;
        lblEmailGreska.Text = exc.Message;
      }
      KosaricaController.ObrisiSve();
    }
    else
    {
      e.Cancel = true;
      lblGreska.Text = rezultat.Greska;
      lblGreska.Visible = true;
    }

  }

  private void PopuniRacun(string BrojAutorizacije)
  {
    lblDatum.Text = DateTime.Now.ToString("dd.MM.yyyy HH:mm");
    //o kojem se partneru radi - novi ili postojeæi?
    string mbr = tbMBR.Text.Trim();
    string naziv = tbImePrezime.Text.Trim();

	  Firma.PartnerBllProvider partnerBllProvider = new Firma.PartnerBllProvider();
    Firma.Partner partner = null;
    if (mbr.Length == 13) 
    {
      partner = partnerBllProvider.FetchByJMBG(mbr);
    }
    else 
    {
      partner = partnerBllProvider.FetchByMatBr(mbr);
    }
	
    if (partner == null)
    {
      partner = new Firma.Partner();
      //ako matièni broj ima 13 znakova, onda se radi o osobi
      if (mbr.Length == 13)
      {
        partner.TipPartnera = Firma.TipPartnera.Osoba;
        partner.JMBG = mbr;
        //razdvoji ime i prezime (jednostavnosti radi, neka sadrži samo jedno ime
        
        string prezime = naziv;
        string ime = "";
        int ind = naziv.LastIndexOf(' ');
        if (ind != -1)
        {
          prezime = naziv.Substring(ind + 1);
          ime = naziv.Substring(0, ind);
        }
        partner.ImeOsobe = ime;
        partner.PrezimeOsobe = prezime;
      }
      else
      {
        partner.TipPartnera = Firma.TipPartnera.Tvrtka;
        partner.MatBrTvrtke = mbr;
        partner.NazivTvrtke = tbImePrezime.Text.Trim();
      }      
    }
        
    partner.AdrIsporuke = tbAdresaIsporuke.Text.Trim();
    partner.AdrPartnera = tbAdresaRacuna.Text.Trim();
    List<Firma.Partner> lp = new List<Firma.Partner>(); 
    lp.Add(partner);
    partnerBllProvider.SaveChanges(lp);

    Firma.DokumentBllProvider dokumentBllProvider = new Firma.DokumentBllProvider();
    Firma.Dokument dokument = new Firma.Dokument();
    dokument.IdPartnera = partner.IdPartnera;
    dokument.VrDokumenta = "R";
    //generiraj sljedeæi broj dokumenta
    int BrDokumenta = 0;
    foreach(Firma.Dokument doc in dokumentBllProvider.FetchAll())
    {
      if (doc.VrDokumenta == "R" && doc.BrDokumenta.HasValue && doc.BrDokumenta.Value > BrDokumenta) 
      {
        BrDokumenta = doc.BrDokumenta.Value;      
      }
    }    
    dokument.BrDokumenta = BrDokumenta + 1;
    foreach (Firma.Stavka stavka in KosaricaController.DohvatiArtikle()) 
    {
      dokument.Stavke.Add(stavka);      
    }
    List<Firma.Dokument> ld = new List<Firma.Dokument>(); 
    ld.Add(dokument);
    dokumentBllProvider.SaveChanges(ld);
   
    //popuni raèun za ispis
    lblBrojRacuna.Text = dokument.IdDokumenta.ToString();
    lblKupac.Text = partner.Naziv;
    lblMaticniBroj.Text = partner.TipPartnera == Firma.TipPartnera.Osoba ? partner.JMBG : partner.MatBrTvrtke;
    lblAdresaRacuna.Text = partner.AdrPartnera;
    lblAdresaIsporuke.Text = partner.AdrIsporuke;
    lblBrojAutorizacije.Text = BrojAutorizacije;
    lblNacinDostave.Text = ddlVrstaDostave.SelectedValue == "KD" ? "Kurirska dostava" : "Poštom";

  }

  private void PosaljiEmail()
  {
    StringWriter sw = new StringWriter();
    HtmlTextWriter writer = new HtmlTextWriter(sw);

    //da ne idemo ponovo redom kreirati sve, uzmimo veæ iscrtani repeater
    RacunPanel.RenderControl(writer);

    MailMessage message = new MailMessage();
    message.To.Add(tbEmail.Text.Trim());
    message.Subject = ConfigurationManager.AppSettings["MailSubject"];
    message.IsBodyHtml = true;
    message.Body = sw.ToString();

    SmtpClient client = new SmtpClient();
    client.Send(message);
  }

  private decimal IzracunPostarine()
  {
    decimal postarina = 0;
    switch (ddlVrstaDostave.SelectedValue)
    {
      case "P":
        postarina = POSTARINA_POSTOM;
        break;
      case "KD":
        postarina = POSTARINA_KURIRSKOM_DOSTAVOM;
        break;
    }
    return postarina;
  }
  protected void Wizard1_NextButtonClick(object sender, WizardNavigationEventArgs e)
  {
    if (e.CurrentStepIndex == 0)
    {
      //provjera e-mail adrese
      string emailPattern = @"\w+([-+.']\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*";
      System.Text.RegularExpressions.Regex validator = new System.Text.RegularExpressions.Regex(emailPattern);


      if (!validator.IsMatch(tbEmail.Text) || tbMBR.Text.Trim() == string.Empty
          || tbAdresaIsporuke.Text.Trim() == string.Empty
          || tbAdresaRacuna.Text.Trim() == string.Empty || tbImePrezime.Text.Trim() == string.Empty)
      {

        lblPodaciNepotpuni.Visible = true;
        e.Cancel = true;
      }
      else
      {
        lblPodaciNepotpuni.Visible = false;
      }

    }
  }
}

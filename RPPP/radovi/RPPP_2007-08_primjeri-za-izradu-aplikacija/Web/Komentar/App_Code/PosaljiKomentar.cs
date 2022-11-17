using System;
using System.Data;
using System.Configuration;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;
using System.Net.Mail;
using System.IO;
using System.Net.Mime;
using System.Collections.Generic;
using System.Text;
using System.Net.Configuration;
using System.Web.Configuration;

/// <summary>
/// Summary description for PosaljiKomentar
/// </summary>
public class PosaljiKomentar
{
  public static void Posalji(List<string> ListaJezika, string Komentar, int? GodinaStudija) 
  {
    MailMessage message = new MailMessage();
    message.To.Add(message.From.Address);
      
    message.Subject = ConfigurationManager.AppSettings["MailSubject"];
    message.IsBodyHtml = false;
    message.Body = "Komentar na web stranicu nalazi se u privitku";
    message.Body += "\r\nPoslano s adrese: " + HttpContext.Current.Request.UserHostAddress;

    StringBuilder sb = new StringBuilder();    
    if (ListaJezika.Count > 0) 
    {
      sb.AppendLine("Jezici koje autor komentara poznaje:");
      foreach(string s in ListaJezika)
        sb.AppendLine(s);
    }
    if (GodinaStudija.HasValue)
    {
      sb.AppendLine("Student je na " + GodinaStudija.Value + " godini.");
    }
    else
    {
      sb.AppendLine("Autor komentara je obièni posjetitelj");
    }

    sb.AppendLine("Komentar:");
    sb.AppendLine(Komentar);

    byte[] buffer = Encoding.Default.GetBytes(sb.ToString());
    using (MemoryStream stream = new MemoryStream(buffer)) 
    {
      Attachment attachment = new Attachment(stream, MediaTypeNames.Text.Plain);
      attachment.Name = "komentar.txt";
      message.Attachments.Add(attachment);
      SmtpClient client = new SmtpClient();
      client.Send(message);
    }               
  }
}

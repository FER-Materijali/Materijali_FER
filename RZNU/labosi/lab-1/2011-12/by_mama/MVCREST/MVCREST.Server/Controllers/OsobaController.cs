using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using MVCREST.Service.Models;
using System.Net;
using System.Text;
using System.Web.Script.Serialization;
using System.Collections.Specialized;

namespace MVCREST.Server.Controllers
{    
    public class OsobaController : Controller
    {
        //izmijeniti ovisno o portu na kojem se servis pokrece!!!
        private string domenaServisa = "http://localhost:38550";

        //prikaz svih osoba
        public ActionResult Index()
        {
            WebClient webClient = new WebClient();
            webClient.Headers["User-Agent"] = Request.UserAgent;
            string responseData = Encoding.UTF8.GetString(
                webClient.DownloadData(domenaServisa + "/api/Osobe/Index"));
            JavaScriptSerializer deserializer=new JavaScriptSerializer();
            JSONOdgovorOsobe odgovor = deserializer.Deserialize<JSONOdgovorOsobe>(responseData);

            return View(odgovor);
        }

        //prikaz određene osobe
        public ActionResult Prikazi(long? id)
        {
            if (id == null)
                return RedirectToAction("Index");
            WebClient webClient = new WebClient();
            webClient.Headers["User-Agent"] = Request.UserAgent;
            string responseData = Encoding.UTF8.GetString(
                webClient.DownloadData(domenaServisa + "/api/Osobe/Index/" + id));
            JavaScriptSerializer deserializer = new JavaScriptSerializer();
            JSONOdgovorOsoba odgovor = deserializer.Deserialize<JSONOdgovorOsoba>(responseData);

            return View(odgovor);
        }

        //prikazi dodavanje osobe
        public ActionResult Dodaj()
        {
            return View();
        }

        //izvrsi dodavanje osobe
        [HttpPost]
        public ActionResult Dodaj(ViewModelOsoba model)
        {
            NameValueCollection postData = new NameValueCollection();
            postData["ime"] = model.Ime;
            postData["prezime"] = model.Prezime;

            WebClient webClient = new WebClient();
            webClient.Headers["User-Agent"] = Request.UserAgent;            
            string responseData = Encoding.UTF8.GetString(
                webClient.UploadValues(domenaServisa + "/api/Osobe/Index", "POST", postData));
            JavaScriptSerializer deserializer = new JavaScriptSerializer();
            Odgovor odgovor = deserializer.Deserialize<Odgovor>(responseData);

            if (odgovor.Tip == Odgovor.GRESKA)
            {
                ModelState.AddModelError(odgovor.Kljuc, odgovor.Text);
                return View(model);
            }
            else
            {
                return RedirectToAction("Index");
            }            
        }
    }
}

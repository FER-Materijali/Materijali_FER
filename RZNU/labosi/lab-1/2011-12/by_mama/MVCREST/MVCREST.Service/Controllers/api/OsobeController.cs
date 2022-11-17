using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using MVCREST.BaseModel;
using MVCREST.DataAccessLayer.Repos;
using MVCREST.Service.Models;

namespace MVCREST.Service.Controllers.api
{
    public class OsobeController : Controller
    {               
        public JsonResult Index(long? id)
        {
            //Dohvat jedne osobe
            if (id != null)
            {
                JSONOdgovorOsoba odgovor = new JSONOdgovorOsoba();
                odgovor.Osoba = OsobaRepository.Instance.Dohvati((long)id);
                if (odgovor.Osoba != null)
                {
                    odgovor.Odgovor = new Odgovor()
                    {
                        Tip = Odgovor.USPJEH,
                        Text = "Uspješan dohvat jedne osobe."
                    };
                }
                else
                {
                    odgovor.Odgovor = new Odgovor()
                    {
                        Tip = Odgovor.GRESKA,
                        Text = "Osoba ne postoji."
                    };
                }
                return Json(odgovor, JsonRequestBehavior.AllowGet);
            }
            else//Dohvat svih osoba
            {
                JSONOdgovorOsobe odgovor = new JSONOdgovorOsobe();
                odgovor.Odgovor = new Odgovor()
                {
                    Tip = Odgovor.USPJEH,
                    Text = "Uspješan dohvat svih osoba."
                };
                odgovor.Osobe = OsobaRepository.Instance.DohvatiSve();
                return Json(odgovor, JsonRequestBehavior.AllowGet);
            }
        }

        //Unos nove osobe
        [HttpPost]
        public JsonResult Index(ViewModelOsoba model)
        {
            Odgovor odgovor = new Odgovor();
            if (!string.IsNullOrEmpty(model.Ime))
            {
                if (!string.IsNullOrEmpty(model.Prezime))
                {
                    Osoba osoba = new Osoba(0, model.Ime, model.Prezime);
                    OsobaRepository.Instance.Dodaj(osoba);
                    odgovor.Tip = Odgovor.USPJEH;
                    odgovor.Text = "Osoba uspješno dodana.";
                }
                else
                {
                    odgovor.Tip = Odgovor.GRESKA;
                    odgovor.Text = "Prezime ne smije biti prazno!";
                    odgovor.Kljuc = "Prezime";
                }
            }
            else
            {
                odgovor.Tip = Odgovor.GRESKA;
                odgovor.Text = "Ime ne smije biti prazno!";
                odgovor.Kljuc = "Ime";
            }

            return Json(odgovor, JsonRequestBehavior.AllowGet);
        }
    }
}

using Portal.Data;
using Portal.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Portal.Controllers
{
    public class HomeController : Controller
    {

        private Database db = new Database();

        public ActionResult Index()
        {
            return View(db.GetNews(5));
        }

        public ActionResult Add()
        {
            return View();
        }

        [HttpPost]
        public ActionResult AddComment(int? id, string text)
        {
            db.AddComment(text, id.Value);
            return RedirectToAction(nameof(Index));
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Add([Bind(Include = "Headline, Text, Author")]AddVM vm, HttpPostedFileBase upload)
        {
            var news = new News { Headline = vm.Headline, Text = vm.Text, Author = vm.Author };
            if (upload != null && upload.ContentLength > 0)
            {
                using (var reader = new System.IO.BinaryReader(upload.InputStream))
                {
                    news.Picture = reader.ReadBytes(upload.ContentLength);
                }
            }
            db.Add(news);
            return RedirectToAction(nameof(Index));
        }
    }
}
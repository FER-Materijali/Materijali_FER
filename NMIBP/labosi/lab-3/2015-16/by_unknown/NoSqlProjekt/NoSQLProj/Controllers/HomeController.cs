using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using DatabaseLayer;
using NoSQLProj.Models;
using System.Drawing;

namespace NoSQLProj.Controllers
{
    public class HomeController : Controller
    {
        private Baza baza = new Baza();
        public ActionResult Index(string comment = "")
        {               
            var result = baza.vratiVijesti(10);
            List<Article> rezultati = new List<Article>();
            foreach (var item in result)
	        {
                Article pomoc = new Article();
                pomoc.id = item.id;
                pomoc.author = item.author;
                pomoc.headline = item.headline;
                pomoc.text = item.text;
                if(item.picture != null)
                    pomoc.picture = item.picture;
                pomoc.comments = new List<Comment>();

                if (item.comments != null)
                {
                    foreach(var comm in item.comments){
                        Comment pom = new Comment();
                        pom.text = comm.text;
                        pom.timestamp = comm.timestamp;
                        pomoc.comments.Add(pom);
                    }
                }
                rezultati.Add(pomoc);
            }

            comment = "";
            return View(rezultati);
        }

        [HttpPost]
        public ActionResult Index(string comment, string id)
        {
            if (comment != "")
            {
                baza.unesiKomentar(comment, int.Parse(id));
            }

            comment = "";
            return RedirectToAction("Index", "Home");
        }


        public ActionResult Add()
        {
            return View();
        }

        // POST: Images/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Add(HttpPostedFileBase upload, [Bind(Include = "headline,text,author,picture")] Article article)
        {
            if (upload != null && upload.ContentLength > 0)
            {
                using (var reader = new System.IO.BinaryReader(upload.InputStream))
                {
                    article.picture = reader.ReadBytes(upload.ContentLength);
                }
            }
            var bazaArticle = new Result
            {
                author = article.author,
                headline = article.headline,
                text = article.text,
                picture = article.picture
            };
            baza.unesiVijest(bazaArticle);

            return RedirectToAction("Index", "Home");
        }

    }
}
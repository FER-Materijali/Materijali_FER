using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace MVCREST.Service.Controllers
{
    public class apiController : Controller
    {
        public ActionResult Index()
        {
            return View();
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Routing;

namespace MVCREST.Service
{
    // Note: For instructions on enabling IIS6 or IIS7 classic mode, 
    // visit http://go.microsoft.com/?LinkId=9394801

    public class MvcApplication : System.Web.HttpApplication
    {
        public static void RegisterGlobalFilters(GlobalFilterCollection filters)
        {
            filters.Add(new HandleErrorAttribute());
        }

        public static void RegisterRoutes(RouteCollection routes)
        {
            routes.IgnoreRoute("{resource}.axd/{*pathInfo}");

            //Ruta za prikaz i objašnjenja APIja
            //moguće adrese:
            //http://domena
            //http://domena/api
            //http://domena/api/Index
            routes.MapRoute(
                "Default",
                "{controller}/{action}",
                new { controller = "api", action = "Index" } // Parameter defaults
            );

            //Ruta za osobe (dohvat i izmjena)
            //POST api/Osobe/Index -> dodavanje
            //GET api/Osobe/Index -> dohvat svih
            //GET api/Osobe/Index/1 -> dohvat s id 1
            routes.MapRoute(
                "OsobaRes", // Route name
                "api/Osobe/Index/{id}", // URL with parameters
                new { controller = "Osobe", action = "Index", id = UrlParameter.Optional } // Parameter defaults
            );
        }

        protected void Application_Start()
        {
            AreaRegistration.RegisterAllAreas();

            RegisterGlobalFilters(GlobalFilters.Filters);
            RegisterRoutes(RouteTable.Routes);
        }
    }
}
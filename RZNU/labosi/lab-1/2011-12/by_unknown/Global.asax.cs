using System;
using System.ServiceModel.Activation;
using System.Web;
using System.Web.Routing;
using System.Data.Entity;
using FilmInfoService.Model;
using FilmInfoService.DAL;

namespace FilmInfoService
{
    public class Global : HttpApplication
    {
        void Application_Start(object sender, EventArgs e)
        {
            Database.SetInitializer<ServiceDBContext>( new FilmInfoInitializer() );
            RegisterRoutes();            
        }

        private void RegisterRoutes()
        {
            // Edit the base address of Service1 by replacing the "Service1" string below
            RouteTable.Routes.Add(new ServiceRoute("Filminfo", new WebServiceHostFactory(), typeof(Filminfo)));
        }
    }
}

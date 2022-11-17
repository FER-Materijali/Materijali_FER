using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.ServiceModel.Activation;
using System.ServiceModel.Web;
using System.Text;
using FilmInfoService.Model;
using FilmInfoService.DAL;
using System.Data.Entity;
using System.Web;
using System.IO;

namespace FilmInfoService
{
    [ServiceContract]
    [AspNetCompatibilityRequirements(RequirementsMode = AspNetCompatibilityRequirementsMode.Allowed)]
    [ServiceBehavior(InstanceContextMode = InstanceContextMode.PerCall)]
    public class Filminfo
    {
        ServiceDBContext db = new ServiceDBContext();

        private void Log()
        {
            string browserName = HttpContext.Current.Request.Browser.Type;
            string uri = HttpContext.Current.Request.Url.AbsolutePath.Substring(9);

            string path = HttpContext.Current.Server.MapPath("/") + "log.txt";
            StreamWriter log = new StreamWriter( path, true);
            log.WriteLine(uri + "\t" + browserName);
            log.Close();
        }

        [WebGet(UriTemplate = "/stats/popular", ResponseFormat = WebMessageFormat.Json)]
        public List<String> GetPopularityStats()
        {
            string path = HttpContext.Current.Server.MapPath("/") + "hadoopParse.txt";
            StreamReader hadoop = new StreamReader(path);
            List< VisitStats > popular = new List< VisitStats >();
            while (!hadoop.EndOfStream)
            {
                popular.Add( new VisitStats( hadoop.ReadLine().Split('\t') ) );
            }
            popular.Sort();

            List<String> output = new List<String>();
            foreach (VisitStats pop in popular)
                output.Add(pop.ToString());

            return output;
        }
      
        [WebGet(UriTemplate = "/directors", ResponseFormat = WebMessageFormat.Json)]
        public List<Director> GetDirectors()
        {
            Log();
            return db.Directors.ToList();
        }

        [WebGet(UriTemplate = "/directors/{name}", ResponseFormat = WebMessageFormat.Json)]
        public List<Director> GetDirectorsByName(string name)
        {
            Log();
            return db.Directors.Where(u => u.Name.Equals(name)).ToList();
        }

        [WebGet(UriTemplate = "/directors/_{surname}", ResponseFormat = WebMessageFormat.Json)]
        public List<Director> GetDirectorsBySurname(string surname)
        {
            Log();
            return db.Directors.Where(u => u.Surname.Equals(surname)).ToList();
        }

        [WebGet(UriTemplate = "/directors/{name}_{surname}", ResponseFormat = WebMessageFormat.Json)]
        public Director GetDirector(string name, string surname)
        {
            Log();
            return db.Directors.SingleOrDefault(d => d.Name.Equals(name) && d.Surname.Equals(surname));
        }

        [WebGet(UriTemplate = "/dbreset")]
        public void ResetDB()
        {
            List<Director> ds = db.Directors.ToList();
            foreach (Director d in ds) db.Directors.Remove(d);
            db.SaveChanges();
            List<Film> fs = db.Films.ToList();
            foreach (Film f in fs) db.Films.Remove(f);
            db.SaveChanges();
            FilmInfoInitializer.Populate(db);
        }

        [WebInvoke(Method = "POST", UriTemplate = "/directors", RequestFormat = WebMessageFormat.Json, ResponseFormat = WebMessageFormat.Json)]
        public void PostDirector(Director director)
        {
            Log();
            db.Directors.Add(director);
            db.SaveChanges();
        }

        [WebInvoke(Method = "PUT", UriTemplate = "/directors/{name}_{surname}", RequestFormat = WebMessageFormat.Json)]
        public Director UpdateDirectorByName(string name, string surname, Director director)
        {
            Log();
            Director dir = db.Directors.Single(d => d.Name.Equals(name) && d.Surname.Equals(surname) );
            dir.Name = director.Name;
            dir.Surname = director.Surname;
            dir.Gender = director.Gender;
            db.SaveChanges();
            return dir;
        }

        [WebInvoke(Method = "PUT", UriTemplate = "/directors/{id}", RequestFormat = WebMessageFormat.Json)]
        public Director UpdateDirectorById(string id, Director director)
        {
            Log();
            int ID = int.Parse(id);
            Director dir = db.Directors.Single( d => d.ID == ID );
            dir.Name = director.Name;
            dir.Surname = director.Surname;
            dir.Gender = director.Gender;
            db.SaveChanges();
            return dir;
        }

        [WebInvoke(Method = "PUT", UriTemplate = "/directors", RequestFormat = WebMessageFormat.Json)]
        public List<Director> UpdateDirectors(List<Director> directors)
        {
            Log();
            foreach (Director director in directors)
            {
                Director dir = db.Directors.Single(d => d.ID == director.ID );
                dir.Name = director.Name;
                dir.Surname = director.Surname;
                dir.Gender = director.Gender;
            }
            db.SaveChanges();
            return directors;
        }

        [WebInvoke(Method = "DELETE", UriTemplate = "/directors/{name}_{surname}", ResponseFormat = WebMessageFormat.Json)]
        public Director DeleteDirectorByName(string name, string surname)
        {
            Director dir = db.Directors.SingleOrDefault(d => d.Name.Equals(name) && d.Surname.Equals(surname));
            if (dir != null)
                return DeleteDirector("" + dir.ID);
            else return dir;
        }

        [WebInvoke(Method = "DELETE", UriTemplate = "/directors/{id}", ResponseFormat = WebMessageFormat.Json)]
        public Director DeleteDirector(string id)
        {
            Log();
            int dirId =  int.Parse(id);
            Director dirToRemove = db.Directors.SingleOrDefault(d => d.ID == dirId);
            if (dirToRemove != null)
            {
                db.Directors.Remove(dirToRemove);

                List<Film> filmByDirector = db.Films.Where(f => f.Director == dirId).ToList();
                foreach (Film f in filmByDirector)
                    db.Films.Remove(f);

                db.SaveChanges();
            }
            return dirToRemove;
        }

        [WebGet(UriTemplate = "/films", ResponseFormat = WebMessageFormat.Json)]
        public List<Film> GetFilms()
        {
            Log();
            return db.Films.ToList();
        }

        [WebGet(UriTemplate = "/films/{id}", ResponseFormat = WebMessageFormat.Json)]
        public Film GetFilmsById(string id)
        {
            Log();
            int ID = int.Parse(id);
            return db.Films.SingleOrDefault(f => f.ID == ID);
        }

        [WebGet(UriTemplate = "/films/d_{id}", ResponseFormat = WebMessageFormat.Json)]
        public List<Film> GetFilmsByDirectorId(string id)
        {
            Log();
            int ID = int.Parse(id);
            return db.Films.Where(f => f.Director == ID).ToList();
        }

        [WebInvoke(Method = "POST", UriTemplate = "/films/{name}_{surname}", RequestFormat = WebMessageFormat.Json, ResponseFormat = WebMessageFormat.Json)]
        public void PostFilm(string name, string surname, List<Film> f)
        {
            Log();
            Director director = db.Directors.SingleOrDefault(d => d.Name.Equals(name) && d.Surname.Equals(surname));
            if (director != null)
            {
                foreach (Film film in f)
                {
                    film.Director = director.ID;
                    db.Films.Add(film);
                }
                db.SaveChanges();
            }
        }

        [WebInvoke(Method = "PUT", UriTemplate = "/films/{id}", RequestFormat = WebMessageFormat.Json)]
        public Film UpdateFilm(string id, Film film)
        {
            Log();
            int ID = int.Parse(id);
            Film targetFilm = db.Films.SingleOrDefault(f => f.ID == ID);
            if (targetFilm != null)
            {
                targetFilm.Title = film.Title;
                targetFilm.Director = film.Director;
                targetFilm.IMDBID = film.IMDBID;
                targetFilm.Year = film.Year;
                db.SaveChanges();
            }
            return targetFilm;
        }

        [WebInvoke(Method = "PUT", UriTemplate = "/films", RequestFormat = WebMessageFormat.Json)]
        public List<Film> UpdateFilms(List<Film> films)
        {
            Log();
            foreach (Film film in films)
            {
                Film targetFilm = db.Films.Single(f => f.ID == film.ID);
                targetFilm.Title = film.Title;
                targetFilm.Director = film.Director;
                targetFilm.IMDBID = film.IMDBID;
                targetFilm.Year = film.Year;
            }
            db.SaveChanges();
            return films;
        }

        [WebInvoke(Method = "DELETE", UriTemplate = "/films/{id}")]
        public Film DeleteFilm(string id)
        {
            Log();
            int ID = int.Parse(id);
            Film filmToRemove = db.Films.Single(f => f.ID == ID);
            if (filmToRemove != null)
            {
                db.Films.Remove( filmToRemove );
            }
            db.SaveChanges();
            return filmToRemove;
        }

    }
}

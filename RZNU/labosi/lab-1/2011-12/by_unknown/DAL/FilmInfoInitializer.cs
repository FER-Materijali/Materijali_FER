using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data.Entity;
using FilmInfoService.Model;

namespace FilmInfoService.DAL
{
    public class FilmInfoInitializer :  DropCreateDatabaseIfModelChanges<ServiceDBContext>
    {
        protected override void Seed(ServiceDBContext context)
        {
            Populate(context);
        }

        public static void Populate(ServiceDBContext context)
        {
            var directors = new List<Director>
            {
                new Director(){ Name="James", Surname="Cameron", Gender="M", ID=1 },
                new Director(){ Name="Steven", Surname="Spielberg", Gender="M", ID=2 },
                new Director(){ Name="Mary", Surname="Harron", Gender="F", ID=3},
                new Director(){ Name="James", Surname="L.Brooks", Gender="M", ID=4 }
            };
            directors.ForEach(d => context.Directors.Add(d));
            context.SaveChanges();

            var films = new List<Film>
            {
                new Film(){ Title="Avatar", Year=2009, Director=1, IMDBID="tt0499549" },
                new Film(){ Title="Titanic", Year=1997, Director=1, IMDBID="tt0120338" },
                new Film(){ Title="Aliens", Year=1986, Director=1, IMDBID="tt0090605" },

                new Film(){ Title="Schindler's List", Year=1993, Director=2, IMDBID="tt0108052" },
                new Film(){ Title="Catch Me If You Can", Year=2002, Director=2, IMDBID="tt0264464" },
                new Film(){ Title="Artificial Intelligence: AI", Year=2001, Director=2, IMDBID="tt0212720" },

                new Film(){ Title="I Shot Andy Warhol", Year=1996, Director=3, IMDBID="tt0116594" },
                new Film(){ Title="American Psycho", Year=2000, Director=3, IMDBID="tt0144084" },
                new Film(){ Title="The Notorious Bettie Page", Year=2005, Director=3, IMDBID="tt0404802" },

                new Film(){ Title="The Simpsons Movie", Year=2007, Director=4, IMDBID="tt0462538"}

            };
            films.ForEach(f => context.Films.Add(f));
            context.SaveChanges();
        }

    }
}
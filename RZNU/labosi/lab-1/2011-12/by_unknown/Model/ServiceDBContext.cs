using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data.Entity;

namespace FilmInfoService.Model
{
    public class ServiceDBContext : DbContext
    {
        public DbSet<Director> Directors { get; set; }
        public DbSet<Film> Films { get; set; }        
    }
}
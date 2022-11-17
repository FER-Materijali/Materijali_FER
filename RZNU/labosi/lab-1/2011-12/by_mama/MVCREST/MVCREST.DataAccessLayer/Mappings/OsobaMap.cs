using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using MVCREST.BaseModel;
using FluentNHibernate.Mapping;

namespace MVCREST.DataAccessLayer.Mappings
{
    public class OsobaMap : ClassMap<Osoba>
    {
        public OsobaMap()
        {
            Not.LazyLoad();
            Table("Osoba");

            Id(x => x.Id)
                .Column("Id")
                .GeneratedBy
                .Native();

            Map(x => x.Ime)
                .Column("Ime")
                .Not.Nullable();

            Map(x => x.Prezime)
                .Column("Prezime")
                .Not.Nullable();

            /*Bilo kad bih mapirali i racune*/
            /*HasMany<Racun>(x => x.Racuni).
                Table("Racun").
                KeyColumn("Vlasnik").
                Inverse().
                Cascade.Delete().
                Not.LazyLoad();*/
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Reflection;
using NHibernate;
using NHibernate.Cfg;
using NHibernate.Driver;
using NHibernate.Dialect;
using NHibernate.Connection;
using FluentNHibernate.Cfg.Db;
using FluentNHibernate;
using NHibernate.Tool.hbm2ddl;
using MVCREST.DataAccessLayer.Mappings;

namespace MVCREST.DataAccessLayer
{
    public class NHibernateHelper
    {
        private static ISessionFactory _sessionFactory;
        public static ISession OpenSession()
        {
            if (_sessionFactory == null)
            {
                Configuration configuration = new Configuration();
                configuration.SetProperty("connection.provider", 
                    "NHibernate.Connection.DriverConnectionProvider");
                configuration.SetProperty("connection.driver_class", 
                    "NHibernate.Driver.SqlClientDriver");
                configuration.SetProperty("dialect", 
                    "NHibernate.Dialect.MsSql2008Dialect");
                configuration.SetProperty("connection.connection_string", 
                    @"Data Source=MARKO-PC\SQL2008DE;Initial Catalog=
                    RESTTEST;Integrated Security=True");
                configuration.SetProperty("query.substitutions", 
                    "true=1;false=0");
                configuration.SetProperty("proxyfactory.factory_class", 
                    "NHibernate.ByteCode.Castle.ProxyFactoryFactory, NHibernate.ByteCode.Castle");
                configuration.AddMappingsFromAssembly(typeof(OsobaMap).Assembly);
                _sessionFactory = configuration.BuildSessionFactory();
            }
            return _sessionFactory.OpenSession();
        }
    }
}

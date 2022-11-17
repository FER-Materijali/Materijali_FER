using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using MVCREST.BaseModel;
using NHibernate;
using NHibernate.Linq;

namespace MVCREST.DataAccessLayer.Repos
{
    public class OsobaRepository : IOsobaRepository
    {
        #region Singleton Pattern

        private static OsobaRepository _instance = null;
        public static IOsobaRepository Instance
        {
            get
            {
                if (_instance == null)
                    _instance = new OsobaRepository();
                return _instance;
            }
        }

        private OsobaRepository() { }

        #endregion

        public void Dodaj(Osoba inOsoba)
        {
            using (ISession session = NHibernateHelper.OpenSession())
            using (ITransaction transaction = session.BeginTransaction())
            {
                session.Save(inOsoba);
                transaction.Commit();
            }
        }

        public Osoba Dohvati(long inId)
        {
            using (ISession session = NHibernateHelper.OpenSession())
            using (ITransaction transaction = session.BeginTransaction())
            {
                return (from osoba in session.Linq<Osoba>() 
                        where osoba.Id == inId
                        select osoba).FirstOrDefault();
            }
        }

        public List<Osoba> DohvatiSve()
        {
            using (ISession session = NHibernateHelper.OpenSession())
            using (ITransaction transaction = session.BeginTransaction())
            {
                return session.Linq<Osoba>().ToList();
            }
        }
    }
}

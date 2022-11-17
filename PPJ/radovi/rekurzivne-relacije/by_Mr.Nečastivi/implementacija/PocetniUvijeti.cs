using System.Collections.Generic;

namespace SSPsucelje
{
    class PocetniUvijeti
    {
        private List<Uvjet> listaUvjeta; //lista u kojoj se nalaze svi uvjeti 
        private Uvjet noviUvjet;
        private List<int> listaMjesta;  //lista u kojoj su svi postavljeni početni uvjeti 


        public PocetniUvijeti()   //konstruktor stvara listu za uvjete i klasu za punjenje liste
        {
            noviUvjet = new Uvjet();
            listaUvjeta = new List<Uvjet>();
            listaMjesta = new List<int>();
        }

        public void DodajUvjet (int mjesto, int vrijednost) //funkcija puni klasu i dodaje tu klasu u listu 
        {
            noviUvjet.Mjesto = mjesto;
            noviUvjet.Vrijednost = vrijednost;

            listaUvjeta.Add(noviUvjet);  //uvjet se dodaje na listu
            listaMjesta.Add(mjesto);     //zapisuje se da je postavljen uvjet za zadano mjesto 
        }

        public int VratiUvjet(int mjesto)  //za zadano mjesto funkcija vraća vrijednost početnog uvjeta
        {
            foreach (Uvjet u in listaUvjeta)
            {
                if (u.Mjesto == mjesto)
                {
                    return u.Vrijednost;
                }

            }
            return -1;  //greška
        }
       
        public bool SadrziUvjet(int n) //vraca true ako je zadan pocetni uvjet za n
        {
            return listaMjesta.Contains(n);
        }

        public void ObrisiUvjete()
        {
            listaUvjeta.Clear();
            listaMjesta.Clear();
        }
    }

    struct Uvjet
    {
        private int mjesto;      //za koji član vrjedi uvjet
        private int vrijednost;  //koja je vrijednost člana

        public int Mjesto
        {
            get { return mjesto; }
            set { mjesto = value; }
        }
        

        public int Vrijednost
        {
            get { return vrijednost; }
            set { vrijednost = value; }
        }
    }
}

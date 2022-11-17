using System;
using System.Windows;
using System.Collections.Generic;

namespace SSPsucelje
{
    class Tablica
    {
        private string niz;
        private int index;              //index pročitanog znaka u nizu
        private int konstanta;          //vrijednost pročitane konstante ispred funkcije ili na kraju relacije
        private char operacija;         //procitani operator ispred funkcije
        private Konstanta zavrsnaKonstanta;

        private List<Funkcija> listaZnakova;

        #region Properties za privatne varijable

        internal Konstanta ZavrsnaKonstanta
        {
            get { return zavrsnaKonstanta; }
            set { ; }
        }
        
        internal List<Funkcija> ListaZnakova
        {
            get { return listaZnakova; }
            set { ; }
        }
        #endregion

        public Tablica(string niz)  //konstruktor prima ulazni niz znakova  
        {
            this.niz = niz;
            index = 0;
            konstanta = 1;   //po defaultu konstanta ispred svake rekurzivne relacije je 1
            operacija = '+';            
            zavrsnaKonstanta = new Konstanta();
            zavrsnaKonstanta.Postoji = false;

            listaZnakova = new List<Funkcija>();

            AnalizirajNiz();
        }

        #region Pozivi funkcija za analiziranje niza

        private void AnalizirajNiz()  
        {
            UcitajFunkciju();

            ProcitajZnakJednakosti();

            UcitajKonstantu();

            UcitajFunkciju();

            while (niz[index]!= ';')  //čita se dok se ne dođe do kraja niza
            {
                UcitajOperator();

                UcitajKonstantu();

                if (niz[index] != ';')  //ako je došao do kraja niza, a nije pročitana funkcija prije ';' postoji konstanta na završetku 
                {
                    UcitajFunkciju();
                }

                else
                {
                    UcitajZavrsnuKonstantu();
                }
            }

        }
        #endregion


        #region Funkcije za analiziranje niza

        private void UcitajFunkciju()
        {
            PreskociRazmake();

            if (niz[index] == 'f' && niz[index + 1] == '(')  //ako je pročitan prvi zapis funkcije 
                {
                    index++;

                    Funkcija novaFunkcija = new Funkcija();  //struktura za spremanje pročitanih funkcija

                    novaFunkcija.Sadržaj = AnalizirajArgument();  //analiza argumenta funkcije
                    novaFunkcija.Konstanta = konstanta;
                    novaFunkcija.Operacija = operacija;
                    listaZnakova.Add(novaFunkcija);

                    konstanta = 1;   //konstanta se vraca na default vrijednost

                }
            else
            {
                throw new ArgumentOutOfRangeException(); 
            }           
            

            PreskociRazmake();
        }
        

        private void PreskociRazmake()
        {
            while (niz[index] == ' ')  //preskakanje razmaka
            {
                index++;
            }
            
        }

        private void ProcitajZnakJednakosti()
        {
            if (niz[index] == '=')  //pročitan znak jednakosti 
            {
                index++;
            }
        }

        private void UcitajKonstantu()
        {
            PreskociRazmake();

            string broj = "";

            while (niz[index] >= '0' && niz[index] <= '9')  //sve dok je pročitana brojka se zapisuje u string 
            {
                broj += niz[index];
                index++;
            }

            if (broj != "") //ako je nešto pročitano zapisuje se u konstantu
            {
                konstanta = Int32.Parse(broj);
            }

            PreskociRazmake();
        }

        private void UcitajZavrsnuKonstantu()  //ako postoji zavrsna konstanta zapisuje se u strukturu
        {
            zavrsnaKonstanta.Postoji = true;

            zavrsnaKonstanta.Operacija= operacija;
            zavrsnaKonstanta.Vrijednost = konstanta;


        } 
        
        private string AnalizirajArgument()  //analiziranje argumenata funkcije
        {
            string rezultat ="";

            index++;  //čita se prvi znak
            if (niz[index] == 'n' || (niz[index] >= '0' && niz[index] <= '9') || niz[index] == '-')  //ako je pročitani znak brojka n ili - sprema se u rezultat
            {
                rezultat += niz[index];
            }

            if (niz[index + 1] == ')') //ako je slijedeći znak kraj argumenta
            {
                index++;
                index++; //index preskače ')' i pomiče se na novi znak  
                return rezultat;
            }


            do
            {
                index++;    //čita se novi znak

                if (niz[index] == 'n' || (niz[index] >= '0' && niz[index] <= '9') || niz[index] == '+' || niz[index] == '-' || niz[index] == '*' || niz[index] == '/')
                {                  //pročitani znak može bit n brojka ili operator
                    rezultat += niz[index];
                }

            } while (niz[index+1] != ')');  //ako slijedeći znak nije kraj niza i ako nije kraj argumenta funkcije čita se novi znak 

            index++; 
            index++; //index preskače ')' i pomiče se na novi znak  
            return rezultat;
        }

        private void UcitajOperator()  //funkcija za ucitavanje operatora
        {
            if (niz[index] == '+' || niz[index] == '-' || niz[index] == '*' || niz[index] == '/')
            {
                operacija = (char)niz[index];
                index++;
            }
            PreskociRazmake();

        }

        #endregion



    }

    struct Funkcija
    {
        private string sadržaj;  //string za sadržaj znaka 
        private int konstanta;   // zapis konstante ispred definicije funkcije
        private char operacija;   //operator ispred funkcije

        

        #region Properties za privatne varijable
        
        public string Sadržaj
        {
            get { return sadržaj; }
            set { sadržaj = value; }
        }

        public char Operacija
        {
            get { return operacija; }
            set { operacija = value; }
        }


        public int Konstanta
        {
            get { return konstanta; }
            set { konstanta = value; }
        }
        #endregion

    }

    struct Konstanta
    {
        private int vrijednost;
        private char operacija;
        private bool postoji;  //ako postoji konstanta nakon zapisa funkcija


        #region Properties za privatne varijable

        public char Operacija
        {
            get { return operacija; }
            set { operacija =value; }
        }

        public int Vrijednost
        {
            get { return vrijednost; }
            set { vrijednost = value; }
        }

        public bool Postoji
        {
            get { return postoji; }
            set { postoji = value; }
        }
        #endregion
    }
}



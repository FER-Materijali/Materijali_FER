using System;

namespace SSPsucelje
{
    class Interpretator
    {
        private Tablica tablica;
        private PocetniUvijeti uvjeti;

        private Int16 brojacPozivaRekurzije;  //brojač poziva funkcije za izračun rekurzije
        

        public Interpretator(Tablica tablica, PocetniUvijeti uvjeti) //konstruktor prima tablicu znakova, n koji izračunavamo i početne uvjete
        {
            this.tablica = tablica;
            this.uvjeti = uvjeti;

            brojacPozivaRekurzije = 0;

        }
        #region Funkcija za izracunavanje rekurzivnih relacija

        public int Izracunaj(int n)  //funkcija za izracunavanje rekurzija
        {
            brojacPozivaRekurzije++;
            int rezultat = 0;

            if (brojacPozivaRekurzije > 5000)    // baca exception ako dođe do beskonačne petlje i stackoverflow-a
            {
               throw new ArgumentException();
            }

            if (uvjeti.SadrziUvjet(n))  //ako je zadan pocetni uvjet rekurzija vraća njegovu vrijednost  
            {
                return uvjeti.VratiUvjet(n);
            }

            for (int i = 1; i < tablica.ListaZnakova.Count; i++)  //ako nije zadan uvjet za n, uvrštava se u ostale relacije i one se sve pozivaju
            {
                int konstanta = tablica.ListaZnakova[i].Konstanta;
                char operacija = tablica.ListaZnakova[i].Operacija;
                int vrijednost = IzracunajArgument(tablica.ListaZnakova[i].Sadržaj, n);

                switch (operacija)  //poziva se rekurzivna relacija ovisno o operaciji koja joj prethodi
                {
                    case '+':
                        rezultat += konstanta * Izracunaj(vrijednost);
                        break;
                        
                    case '-':
                        rezultat -= konstanta * Izracunaj(vrijednost);
                        break;
                      
                    case '*':
                        rezultat *= konstanta * Izracunaj(vrijednost);
                        break;
                        
                    case '/':
                        rezultat /= konstanta * Izracunaj(vrijednost);
                        break;
                        
                    default:
                        break;

                }                
            }

            if (tablica.ZavrsnaKonstanta.Postoji) //ako postoji konstanta nakon funkcija njezina se vrijednost dodaje rezultatu
            {

                int vrijednost = tablica.ZavrsnaKonstanta.Vrijednost;
                char operacija = tablica.ZavrsnaKonstanta.Operacija;

                switch (operacija)
                {
                    case '+':
                        rezultat += vrijednost;
                        break;

                    case '-':
                        rezultat -= vrijednost;
                        break;

                    case '*':
                        rezultat *= vrijednost;
                        break;

                    case '/':
                        rezultat /= vrijednost;
                        break;

                    default:
                        break;
                }

            }

            return rezultat;

        }
        #endregion


        #region Funkcija za izracunavanje vrijednosti unutar argumenata relacije

        private int IzracunajArgument(string sadrzaj, int n) //funkcija koja izračunava vrijednost unutar zagrada za zadani n
        {
            int vrijednost = 0;
            string prvaKonstanta = "";               //rezultat = a*n <operacija> b
            char opereracija = '+'; 
            string drugaKonstanta = "";

            int a, b;
            int i = 0;


            while (sadrzaj[i] != 'n')    //učitava se prva konstanta
            {
                prvaKonstanta += sadrzaj[i];
                i++;
                
            }



            if (sadrzaj[i] == 'n')  
            {
                if (i < sadrzaj.Length)
                {
                    i++;
                }
            }

            if (sadrzaj[i] == '+' || sadrzaj[i] == '-' || sadrzaj[i] == '*' || sadrzaj[i] == '/') //učitava se operator
            {
                opereracija = sadrzaj[i];
                i++;
            }

            while (i < sadrzaj.Length)  //učitavanje druge konstante
            {
                drugaKonstanta += sadrzaj[i];
                i++;
            }

            if (prvaKonstanta != "")  //ako je pročitana prva konstanta
            {
                a = Int32.Parse(prvaKonstanta); // ona se upisuje u a
            }
            else
            {
                a = 1;         //inače je 1 i ne utjeće na rezultat
            }

            if (drugaKonstanta != "")
            {
                b = Int32.Parse(drugaKonstanta);
            }
            else
            {
                b = 0;           //druga konstanta ako nije pročitana je 0 da ne utječe na rezultat 
            }


            switch (opereracija)
            {
                case '+':
                    vrijednost = a * n + b;
                    break;
                case '-':
                    vrijednost = a * n - b;
                    break;
                case '*':
                    vrijednost = a * n * b;
                    break;
                case '/':
                    vrijednost = a * n / b;
                    break;
                default:
                    vrijednost = 0;
                    break;
                    
            } 

            return vrijednost;
        }
        #endregion

    }
}

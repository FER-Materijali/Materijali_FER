public class Automat
    {
        private Boolean return_value = false;
        public string stog = "K";
        public string ulazni_znakovi = "";
        int stanje = 0;

        public void Dodaj_na_stog(string str)
        {
            stog = stog + str;
        }

        public char Skini_sa_stoga()
        {
            char tmp = \\'E\\';
            if (stog.Length > 0)
            {
                tmp = stog[stog.Length - 1];
                stog = stog.Remove(stog.Length - 1);
            }
            return tmp;
        }

        public char Ucitaj_znak()
        {
            char tmp = \\'E\\';
            if (ulazni_znakovi.Length > 0)
            {
                tmp = ulazni_znakovi[0];
                ulazni_znakovi = ulazni_znakovi.Substring(1);                
            }
            return tmp;
        }

        public Automat(int Stanje, string Stog, string Ulazni_znakovi)
        {
            stanje = Stanje;
            stog = Stog;
            ulazni_znakovi = Ulazni_znakovi;         
        }

        public Boolean Pokreni_automat()
        {
            while (ulazni_znakovi.Length > 0 && !return_value) stanje = Prijelazi(stanje, Ucitaj_znak(), Skini_sa_stoga());
            if (Skini_sa_stoga() == \\'K\\' && stanje == 1) return_value = true;
            return return_value;           
        }

        public int Prijelazi(int Stanje,char Znak,char Znak_stog)
        {
            string tmp_ispis = "";
            ispisi("Ucitani znak: " + Znak);
            ispisi("Trenutno stanje: q" + stanje.ToString());
            ispisi("Stog: " + stog+Znak_stog);
            
            tmp_ispis = "Prijelaz d(q"+stanje + ", " + Znak + ", " + Znak_stog + ") = (q" + stanje + ", " +
                            Znak + Znak_stog.ToString() + ")";

            if (stanje == 0)
            {
                    if (Znak_stog == Znak)
                    {
                        tmp_ispis = tmp_ispis + ", (q1, E)";                        
                        Automat automat2 = new Automat(1, stog, ulazni_znakovi);
                        if(automat2.Pokreni_automat()) return_value = true;
                    }
                    Dodaj_na_stog(Znak_stog.ToString() + Znak);
                
            }
            else if (stanje == 1)
            {
                if (Znak != Znak_stog)
                {
                    ulazni_znakovi = "";
                }
            }

            ispisi(tmp_ispis);
            ispisi("Novo stanje: q" + stanje);
            ispisi("Novo stanje stoga: " + stog);
            ispisi("");
            return stanje;
        }

        private void ispisi(string str)
        {
            Console.WriteLine(str);
        }
        
    }
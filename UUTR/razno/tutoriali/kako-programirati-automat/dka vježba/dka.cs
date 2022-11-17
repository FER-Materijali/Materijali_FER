using System;

namespace dka_vježba
{
    class dka
    {
        // tablica sa prijelazima automata
 
        private string[][] prijelazi = new string[][]
            {new string[] {"0", "1", "2"},
             new string[] {"q0", "q1", "q0"},
             new string[] {"q0", "q2", "q0"},
             new string[] {"q2", "q2", "q2"}};

        // varijable za čuvanje stanja automata

        private string novo_stanje;
        private string trenutno_stanje;

        // dodatni konstruktor sa definiranim početnim stanjem

        public dka(string pocetno_stanje)
        {
            trenutno_stanje = pocetno_stanje;
        }

        // metoda za ispis tablice stanja
        
        public void ispis_tablice_stanja()
        {
            for (int i = 0; i < prijelazi[i].Length; i++)
            {
                for (int j = 0; j < prijelazi[i].Length; j++)
                    Console.Write("{0} \t", prijelazi[i][j]);
                
                Console.WriteLine();
            }
        }

        // glavna metoda - funkcija prijelaza
            
        public void funkcija_prijelaza(string ulazni_niz)
        {
            int index_znaka;
            int index_stanja;

            for (int i = 0; i < ulazni_niz.Length; i++)     //prolazimo svaki znak u ulaznom nizu
            {

                /* sada moramo prilagoditi ulazne znakove indeksu
                 * polja iz kojeg očitamo sljedeće stanje.
                 * index znaka će biti okomiti stupci u tablici, a
                 * index stanja vodoravni redovi. na tu foru možemo iz 
                 * trenutnog stanja i nekog ulaznog znaka dobiti sljedeće
                 * stanje. 
                 * 
                 * prvo na index znaka. ovdje imamo sreće da su poredani znakovi 
                 * 0,1,2 pa ih možemo odma koristiti kao index naše tablice. 
                 * jedino moramo pretvoriti znak u broj i to se radi sa Parse
                 * funkcijom
                 * 
                 * index stanja je malo kompliciraniji. opet imamo stanja q0-q2
                 * primjetite da se nakon znaka q u nazivu stanja nalazi njegov
                 * index. znači trebamo samo extractat taj index tako da se 
                 * pomaknemo za 1 od početka naziva. to onda pretvorimo u broj
                 * gore navedenom metodom zbog uređenja tablice nam indexi stanja 
                 * počinju od 1, a ne od 0 pa moramo dodati ovaj +1 */
 
                index_znaka = int.Parse(ulazni_niz[i].ToString());
                index_stanja = int.Parse(trenutno_stanje[1].ToString()) + 1;

                /* još nešto... traže nas utr-ovci da ispisujemo svaki korak automata
                 * pa evo im sve informacije :) */

                Console.WriteLine("\nTrenutno stanje: {0}, ulazni znak: {1}", trenutno_stanje, ulazni_niz[i]);

                // sada odredimo novo stanje preko onih indexa gore

                novo_stanje = prijelazi[index_stanja][index_znaka];

                Console.WriteLine("\nNovo stanje: {0}", novo_stanje);

                // postavimo novo stanje kao trenutno za sljedeći korak for petlje

                trenutno_stanje = novo_stanje;

                /* ako se dogodi da smo u zabranjenom stanju q2 (2 uzastopne jedinice) 
                 * završavamo rad jer se niz ne prihvaća */
                if (trenutno_stanje == "q2")
                {
                    Console.ForegroundColor = ConsoleColor.Yellow;  

                    // ovo vas ne treba zamarati. malo se igramo bojicama ;)

                    Console.WriteLine("\nZadani niz se ne prihvaća");
                    break;
                }

                // ako smo prošli zadnji znak i sve je OK ispišemo da se niz prihvaća

                if (i == ulazni_niz.Length - 1)
                {
                    Console.ForegroundColor = ConsoleColor.Green;
                    Console.WriteLine("\nUlazni niz se prihvaća :]");
                }

            }            
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SSP_Simulator_LEXa
{
    class Parsiranje
    {
        public int brojStanja;

        private string prihvatljivaStanja;
        private List<int> početnaStanja = new List<int>();
        private List<int> počSta = new List<int>();
        private List<string> ugniježđeneZagrade;
        private List<int> tipoviUgnijeđenihZagrada;
        private List<int> prihvatljivstiUgniježđenihZagrada;

        public int odrediBrojITipZagrada(char[] izraz, int brIzraza) // MainClass
        {
            int brZag = 0 , razina = 0 ;
            string podniz = "" , tipoviZagrada = "" ;

            MainClass.zagrade.Add(new List<string>());
            MainClass.prijelazi.Add(new List<string>());
    
            for (int i = 0; i < izraz.Length; i++ )
            {
                // ********** određivanje tipova zagrada i izraza koje one sadrže *******************

                if (razina > 1)
                    podniz += izraz[i] ;
                else if ( razina == 1 && izraz[i] != ')' )
                    podniz += izraz[i] ;
                else if ( razina == 1 && izraz[i] == ')' )
                {
                    if ( ( i + 1 ) < izraz.Length && izraz[i + 1] == '*')
                            tipoviZagrada += "3 " ;
                    else if ( sadržiEpsilon ( podniz.ToCharArray() ) == false )
                        tipoviZagrada += "1 " ;
                    else if ( sadržiEpsilon(podniz.ToCharArray()) )
                        tipoviZagrada += "2 " ;
                    MainClass.zagrade[brIzraza].Add( podniz ) ;
                    podniz = "" ;
                }

                // ********** određivanje broja zagrada ******************

                if (izraz[i] == '(' & razina == 0)
                {
                    brZag++;
                    razina++;
                }
                else if (izraz[i] == ')')
                    razina--;
                else if (izraz[i] == '(')
                    razina++;
            }
            
            tipoviZagrada = tipoviZagrada.Remove(tipoviZagrada.Length - 1);
            MainClass.tipoviZagrada.Add(tipoviZagrada);

            return brZag;
        }

        private bool sadržiEpsilon(char[] podniz) // gotovo :-}
        {
            int razina = 0 ;

            for (int i = 0; i < podniz.Length; i++)
            {
                if (podniz[i] == '(' & razina == 0)
                {
                    razina++;
                }
                else if (podniz[i] == ')')
                    razina--;
                else if (podniz[i] == '(')
                    razina++;
                
                if ( razina == 0 && podniz[i] == '$' )
                    return true ;
            }
            return false ;
        }

        public void odrediPrihvatljivost( string tipovi ) // MainClass
        {
            string prihvatljivost = "" ;
            for ( int i = 0 ; i < tipovi.Length ; i++ )
            {
                if (i >= tipovi.LastIndexOf('1'))
                    prihvatljivost += "1";
                else
                    prihvatljivost += "0";
            }
            MainClass.prihvatljivostZagrada.Add(prihvatljivost);
        }

        public string zamijeniNadovezivanje( char[] zagrada) // Univerzalna metoda
        {
            int razina = 0 ;
            string pom = "";
            for (int i = 0; i < zagrada.Length; i++)
            {
                if (razina == 0 && zagrada[i] == '|')
                    zagrada[i] = '%';
                if (zagrada[i] == '(')
                    razina++;
                else if ( zagrada[i] == ')')
                    razina--;
                pom += zagrada[i];
            }
            return pom;
        }

        public void parsirajIzraz(int brojIzraza) // MainClass
        {
            string[] tipoviZag = MainClass.tipoviZagrada[brojIzraza].Split(' ') ;
            int tipZag, prih;
            
            početnaStanja = new List<int>();
            početnaStanja.Add(brojStanja);
            prihvatljivaStanja = "" ;

            for (int brojZagrade = 0; brojZagrade < MainClass.zagrade[brojIzraza].Count; brojZagrade++)
            {
                string parsiranaZagrada = zamijeniNadovezivanje(MainClass.zagrade[brojIzraza][brojZagrade].ToCharArray());
                tipZag = tipoviZag[brojZagrade][0] - 48;
                prih = MainClass.prihvatljivostZagrada[brojIzraza][brojZagrade] - 48;

                switch (tipZag)
                {
                    case 1:
                        foreach ( int početnoStanje in početnaStanja )
                        parsirajObicnuZagradu( parsiranaZagrada, brojIzraza, početnoStanje, ++brojStanja, prih );
                        continue ;
                    case 2 :
                        for ( int i = 0; i < početnaStanja.Count; i++ )
                            parsirajEpsilonZagradu(parsiranaZagrada, brojIzraza, početnaStanja[i], prih);
                        početnaStanja = počSta;
                        continue;
                    case 3 :
                        foreach (int početnoStanje in početnaStanja)
                            parsirajKleenZagradu(parsiranaZagrada, brojIzraza, početnoStanje, prih);
                        continue;
                }
            }
            MainClass.prihvatljivaStanja.Add(prihvatljivaStanja.Remove(prihvatljivaStanja.Length-1));
        }

        public void parsirajObicnuZagradu(string zagrada, int brojIzraza, int pocetnoStanje, int završnoStanje, int prihv)
        {
            string[] izrazi = zagrada.Split('%');

            if ( prihv == 1 )
                prihvatljivaStanja += brojIzraza + "-" + završnoStanje.ToString() + " ";

            početnaStanja = new List<int>() ;
            početnaStanja.Add(završnoStanje) ;

            foreach (string izraz in izrazi)
            {
                /*
                if (izraz.StartsWith("(") == true)
                {
                    parsirajUgniježđenuZagradu(izraz, brojIzraza, završnoStanje, prihv);
                    continue;
                }
                 
                else */
                if (izraz.Length == 1)
                    MainClass.prijelazi[brojIzraza].Add(brojIzraza + "-" + pocetnoStanje + " "+izraz+" " + brojIzraza+"-"+završnoStanje);
                else
                {
                    for (int i = 0; i < izraz.Length; i++)
                    {
                        if (i == 0)
                            MainClass.prijelazi[brojIzraza].Add(brojIzraza + "-" + pocetnoStanje + " " + izraz[i] + " " + brojIzraza + "-"+ ++brojStanja);
                        else if (i == izraz.Length - 1)
                            MainClass.prijelazi[brojIzraza].Add(brojIzraza + "-" + brojStanja + " " + izraz[i] + " " + brojIzraza + "-" + završnoStanje);
                        else
                            MainClass.prijelazi[brojIzraza].Add(brojIzraza + "-" + brojStanja + " " + izraz[i] + " " + brojIzraza+"-"+ ++brojStanja);
                    }
                }
            }
        }

        public void parsirajEpsilonZagradu(string zagrada, int brojIzraza, int pocetnoStanje, int prihv)
        {
            počSta = new List<int>() ;
            string[] izrazi = zagrada.Split('%') ;
            
            foreach (string izraz in izrazi)
            {
                if (izraz == "$")
                {
                    počSta.Add(pocetnoStanje);
                    continue;
                }
                 /*
                if (izraz.StartsWith("(") == true)
                {
                    parsirajUgniježđenuZagradu(izraz, brojIzraza, -1,  prihv);
                    continue;
                }
                 */
                else if (izraz.Length == 1)
                {
                    MainClass.prijelazi[brojIzraza].Add(brojIzraza + "-" + pocetnoStanje + " " + izraz + " " + brojIzraza + "-" + ++brojStanja);
                    počSta.Add(brojStanja);
                    if (prihv == 1)
                        prihvatljivaStanja += brojIzraza + "-" + brojStanja.ToString() + " ";
                }
                else
                {
                    for (int i = 0; i < izraz.Length; i++)
                    {
                        if (i == 0)
                            MainClass.prijelazi[brojIzraza].Add(brojIzraza + "-" + pocetnoStanje + " " + izraz[i] + " " + brojIzraza+"-" + ++brojStanja);
                        else if (i == izraz.Length - 1)
                        {
                            MainClass.prijelazi[brojIzraza].Add(brojIzraza + "-" + brojStanja + " " + izraz[i] + " " + brojIzraza + "-" + ++brojStanja);
                            počSta.Add(brojStanja);
                            if (prihv == 1)
                                prihvatljivaStanja += brojIzraza + "-" + brojStanja.ToString() + " ";
                        }
                        else
                        {
                            MainClass.prijelazi[brojIzraza].Add(brojIzraza + "-" + brojStanja + " " + izraz[i] + " " + brojIzraza + "-" + ++brojStanja);
                        }
                    }
                }
            }
        }

        public void parsirajKleenZagradu(string zagrada, int brojIzraza, int pocetnoStanje, int prihv)
        {
            List<int> završnaS = new List<int>();
            List<int> početnaS = new List<int>();
            List<int> pojedinaS = new List<int>();

            string[] izrazi = zagrada.Split('%');

            foreach (string izraz in izrazi)
            {
                /*
                if (izraz.StartsWith("(") == true)
                {
                    parsirajUgniježđenuZagradu(izraz, brojIzraza, -1, prihv);
                    continue;
                }
                 * 
                else*/
                if (izraz.Length == 1)
                {
                    MainClass.prijelazi[brojIzraza].Add(brojIzraza + "-" + pocetnoStanje + " " + izraz + " " + brojIzraza + "-" + ++brojStanja);
                    MainClass.prijelazi[brojIzraza].Add(brojIzraza + "-" + brojStanja + " " + izraz + " " + brojIzraza + "-" + brojStanja);
                    if (prihv == 1)
                        prihvatljivaStanja += brojIzraza + "-" + brojStanja.ToString() + " ";
                    pojedinaS.Add(brojStanja);
                }
                else
                {
                    for (int i = 0; i < izraz.Length; i++)
                    {
                        if (i == 0)
                        {
                            MainClass.prijelazi[brojIzraza].Add(brojIzraza + "-" + pocetnoStanje + " " + izraz[i] + " " + brojIzraza + "-" + ++brojStanja);
                            završnaS.Add(brojStanja);
                        }
                        else if (i == izraz.Length - 1)
                        {
                            MainClass.prijelazi[brojIzraza].Add(brojIzraza + "-" + brojStanja + " " + izraz[i] + " " + brojIzraza + "-" + ++brojStanja);
                            if (prihv == 1)
                                prihvatljivaStanja += brojIzraza + "-" + brojStanja.ToString() + " ";
                            početnaS.Add(brojStanja);
                        }
                        else
                        {
                            MainClass.prijelazi[brojIzraza].Add(brojIzraza + "-" + brojStanja + " " + izraz[i] + " " +brojIzraza+"-"+ ++brojStanja);
                        }
                    }
                }
            }
            foreach (int pocetno in početnaS )
                foreach ( int završno in završnaS )
                    foreach ( string izraz in izrazi )
                        if (izraz.Length > 1)
                        {
                            Console.WriteLine("dodani prijelz--> " + brojIzraza + "-" + pocetno + " " + izraz[0] + " " + brojIzraza + "-" + završno);
                            MainClass.prijelazi[brojIzraza].Add(brojIzraza + "-" + pocetno + " " + izraz[0] + " " +brojIzraza+"-"+završno);
                        }
            foreach (int završno in završnaS)
                foreach (int pocetno in pojedinaS)
                    foreach ( string izraz in izrazi )
                        if (izraz.Length > 1)
                        {
                            MainClass.prijelazi[brojIzraza].Add(brojIzraza + "-" + pocetno + " " + izraz[0] + " " + brojIzraza + "-" + završno);
                        }
            foreach (int pocetno in početnaS )
                foreach (int završno in pojedinaS)
                    foreach (string izraz in izrazi)
                        if (izraz.Length == 1)
                        {
                            MainClass.prijelazi[brojIzraza].Add(brojIzraza + "-" + pocetno + " " + izraz[0] + " " + brojIzraza + "-" + završno);
                        }
            for (int pocZav = 0 ; pocZav < pojedinaS.Count ; pocZav++ )
            {
                int pom = 0;
                foreach (string izraz in izrazi)
                    if (izraz.Length == 1)
                    {
                        if ( pocZav != pom )
                        MainClass.prijelazi[brojIzraza].Add(brojIzraza + "-" + pojedinaS[pocZav] + " " + izraz[0] + " " + brojIzraza + "-" +pojedinaS[pom] );
                        pom++;
                    }
            }
        }
        
    }
}

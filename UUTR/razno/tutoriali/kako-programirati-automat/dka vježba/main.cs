using System;

namespace dka_vježba
{
    class main
    {
        static int Main()
        {
            dka automat = new dka("q0");    //stvaramo instancu automata sa poèetnim stanjem Q0

            Console.WriteLine("Upiši niz za provjeru: ");   //upis niza
            string ulaz = Console.ReadLine();

            //provjeravamo da li niz sadržava znakove iz abecede {0,1,2}

            for (int i = 0; i < ulaz.Length; i++)
            {
                if (ulaz[i] != '0' && ulaz[i] != '1' && ulaz[i] != '2')
                {
                    Console.ForegroundColor = ConsoleColor.Red;
                    Console.WriteLine("\nGreška: Nije upisan valjani znak");
                    Console.ForegroundColor = ConsoleColor.Gray;
                    Console.WriteLine("\nEnter za izlaz");
                    Console.ReadLine();
                    return 1;
                }
            }

            //pokrenemo automat

            automat.funkcija_prijelaza(ulaz);

            //završen posao

            Console.ForegroundColor = ConsoleColor.Gray;
            Console.WriteLine("\nEnter za izlaz");
            Console.ReadLine();
            return 0;
        }
    }

}
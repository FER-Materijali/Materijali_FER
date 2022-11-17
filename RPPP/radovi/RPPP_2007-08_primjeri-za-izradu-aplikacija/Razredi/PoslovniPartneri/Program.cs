using System;
using System.Collections.Generic;
using System.Text;


class Program
{
  static void Main(string[] args)
  {
    PoslovniPartner[] ListaPoslovnihPartnera = new PoslovniPartner[2];


    //Probati prevesti s MaticniBroj veæi/manji od 13, odnosno 7 znamenki...
    try
    {
      ListaPoslovnihPartnera[0] = new Osoba("1234567891123", "Adresa 1", "Adresa 2", "Osoba1Ime", "Osoba1Prezime");
      ListaPoslovnihPartnera[1] = new Tvrtka("1234567", "Adresa 1", "Adresa 2", "Tvrtka1Naziv");
      foreach (PoslovniPartner p in ListaPoslovnihPartnera)
      {
        Console.WriteLine("************************");
        Console.WriteLine(p.ToString());
        Console.WriteLine("************************");
      }
    }
    catch (Exception e)
    {
      Console.WriteLine(e.Message);
    }

  }
}



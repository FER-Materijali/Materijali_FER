using System;
using System.Collections.Generic;
using System.Text;

namespace CentraliziraniSustav
{
  class SustavObradeIznimki
  {
    // Centralizirani sustav za obradu iznimki*/
    public static void ReportError(Exception iznimka)
    {
      Console.WriteLine("Neocekvana iznimka:  " + iznimka.Message);
      Console.WriteLine("Mjesto Iznimke:");
      Console.WriteLine(iznimka.StackTrace);
      Console.WriteLine("\nPritisni tipku...");
      Console.ReadLine();
    }

    static void Main(string[] args)
    {
      // Los primjer - zanemarivanje iznimke
      try
      {
        //...
        // puno koda
        //...
      }

      catch (Exception ANYexception)
      {
        //prazne "catch" blokove treba izbjegavati
      }


      // Dobar primjer
      try
      {
        //...
        // puno koda
        //...
        Exception ex = new Exception("\"Poruka iznimke...\"");
        throw ex;
      }

      catch (Exception ANYexception)
      {
        ReportError(ANYexception);
      }
    }
  }
}

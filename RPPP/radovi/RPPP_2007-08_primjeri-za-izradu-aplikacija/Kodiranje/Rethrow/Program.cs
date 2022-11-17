using System;
using System.Collections.Generic;
using System.Text;

namespace Rethrow
{
  class Program
  {
    static void Main(string[] args)
    {
      try
      {
        RethrowException();
      }
      catch (Exception e)
      {
        Console.WriteLine("Main: " + e.Message);
      }

    }

    static void RethrowException()
    {
      try
      {
        // poziv bilo koje naredbe ili postupka koji izaziva iznimku
        throw new Exception("Iznimka je baèena!");
      }
      catch (Exception e)
      {
        Console.WriteLine("Rethrow: " + e.Message);
        throw;
      }
      finally
      {
        Console.WriteLine("Finally RethrowException");
      }
    }

  }
}

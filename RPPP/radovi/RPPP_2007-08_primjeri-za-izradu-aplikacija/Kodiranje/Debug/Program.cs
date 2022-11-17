#define RAZVOJ //definiramo simbol
using System;
using System.Collections.Generic;
using System.Text;

namespace Debug
{
  class Program
  {
    static void Main(string[] args)
    {

#if (RAZVOJ)

      //...
      // kod za debugiranje
      //...

      Console.WriteLine("Poruka UNUTAR koda za debugiranje!");

      Console.WriteLine("\nPress any key!");
      Console.ReadLine();
#endif

      //...
      Console.WriteLine("Poruka IZVAN koda za debugiranje!");

      Console.WriteLine("\nPress any key!");
      Console.ReadLine();
    }
  }
}


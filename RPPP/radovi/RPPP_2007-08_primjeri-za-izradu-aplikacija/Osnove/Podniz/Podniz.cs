using System;
using System.Collections.Generic;

class Podniz
{
  static void Main(string[] args)
  {
    string[] ListaStringova = new string[] 
        { "Jabuka", "Neboder", "Stablo", "Prozor" };
    string podniz = "ab";

    foreach (string s in ListaStringova)
    {
      if (s.Contains(podniz))
      {
        Console.WriteLine(s);
      }
    }
  }
}


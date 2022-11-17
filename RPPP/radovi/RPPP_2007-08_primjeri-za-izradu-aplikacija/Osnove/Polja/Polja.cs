using System;
using System.Collections;

class Nizovi
{
  public static void Main(string[] args)
  {
    int[] a = new int[10];
    int[] b = new int[] { 1, 2, 3 };
    int[] c = { 1, 2, 3 };

    Console.WriteLine("Polje kao niz odreðene duljine");
    for (int i = 0; i < b.Length; i++)
    {
      Console.Write(b[i] + " ");
    }

    int n = 3;
    int[] d = new int[n];
    d[0] = 10;
    d[1] = 11;
    d[2] = 12;

    Console.WriteLine("\nPolje kao kolekcija objekata");
    foreach (int br in d)
    {
      Console.Write(br + " ");
    }
    Console.WriteLine();
  }
}

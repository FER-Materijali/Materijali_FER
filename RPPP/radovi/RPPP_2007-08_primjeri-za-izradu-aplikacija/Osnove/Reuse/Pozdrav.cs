using System;

public class Pozdrav
{
  public Pozdrav()
  {
    Poziv("iz lokalnog");
  }

  public static void Poziv(string poruka)
  {
    System.Console.WriteLine("Pozdrav " + poruka);
  }
}


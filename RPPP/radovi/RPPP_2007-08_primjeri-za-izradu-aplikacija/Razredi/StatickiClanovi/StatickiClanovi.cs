using System;

class StaticRazred
{
  private static int brojac = 0;

  public static int Brojac
  {
    get { return brojac; } //dopustamo samo dohvat
  }

  public StaticRazred()
  {
    brojac++;
  }

  public static int Zbroji(int x, int y)
  {
    return x + y;
  }
}


class StatickiClanovi
{
  static void Main(string[] args)
  {

    Console.WriteLine("Brojac na poèetku: {0}", StaticRazred.Brojac);

    StaticRazred s1 = new StaticRazred();
    StaticRazred s2 = new StaticRazred();

    Console.WriteLine("Brojac na kraju: {0}", StaticRazred.Brojac);


    Console.WriteLine("Zbroj {0} + {1} = {2}", 5, 3, StaticRazred.Zbroji(5, 3));
  }
}


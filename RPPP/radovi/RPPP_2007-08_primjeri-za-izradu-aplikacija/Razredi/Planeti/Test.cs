using System;

class Test
{

  static void Main(string[] args)
  {

    Planet Zemlja = new Planet(6378, 9.81, "Zemlja");
    Planet Saturn = new Planet(60268, 8.96, "Saturn");

    Console.WriteLine("Ukupan broj planeta (za sada): " + Planet.GetCount());

  }

}


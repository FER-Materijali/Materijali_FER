using System;
using System.Collections;
using System.Collections.Generic;

class Temperatura
{
  private float T;
  public float Celsius
  {
    get { return T - 273.16f; }
    set { T = value + 273.16f; }
  }
  public float Fahrenheit
  {
    get { return 9f / 5 * Celsius + 32; }
    set { Celsius = (5f / 9) * (value - 32); }
  }
}

class TemperaturaCollection
{
  private Temperatura[] nizTemperatura;
  private int brElemenata;
  private int maxBrElemenata;

  public TemperaturaCollection(int MaxBrElemenata)
  {
    nizTemperatura = new Temperatura[MaxBrElemenata];
    maxBrElemenata = MaxBrElemenata;
    brElemenata = 0;
  }

  public void Add(Temperatura t)
  {
    if (brElemenata < maxBrElemenata)
    {
      nizTemperatura[brElemenata] = t;
      brElemenata++;
    }
    else throw new Exception("Pogreška!");
  }

  public Temperatura this[int index]   // Indekser
  {
    set
    {
      if (index >= 0 && index < nizTemperatura.Length)
        nizTemperatura[index] = value;
      else throw new Exception("Pogreška!");
    }
    get
    {
      if (index >= 0 && index < nizTemperatura.Length)
        return nizTemperatura[index];
      else throw new Exception("Pogreška!");
    }
  }
}

class SvojstvaIndekseri
{
  static void Main()
  {
    Temperatura X = new Temperatura();
    X.Fahrenheit = 70;
    Console.WriteLine("{0} = {1}", X.Fahrenheit, X.Celsius);
    X.Celsius = 36.5f;
    Console.WriteLine("{0} = {1}", X.Fahrenheit, X.Celsius);


    Temperatura Y = new Temperatura();
    Y.Fahrenheit = 60;

    TemperaturaCollection DnevneTemperature = new TemperaturaCollection(3);
    DnevneTemperature.Add(X);
    DnevneTemperature.Add(Y);

    Console.WriteLine("Dnevna t0: {0}", DnevneTemperature[0].Celsius);
    Console.WriteLine("Dnevna t1: {0}", DnevneTemperature[1].Celsius);

    DnevneTemperature[1] = X;

    Console.WriteLine("Dnevna t0: {0}", DnevneTemperature[0].Celsius);
    Console.WriteLine("Dnevna t1: {0}", DnevneTemperature[1].Celsius);


  }
}

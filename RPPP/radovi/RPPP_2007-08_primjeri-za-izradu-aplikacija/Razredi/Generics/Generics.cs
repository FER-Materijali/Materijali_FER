using System;
using System.Collections.Generic;
using System.Text;

namespace Generics
{

   // vlastiti genericki razred
  public class Stog<T>
  {
    readonly int maxVelicina;
    int vrh = 0;
    T[] elementi;
    public Stog()
      : this(100)
    { }
    public Stog(int velicina)
    {
      maxVelicina = velicina;
      elementi = new T[maxVelicina];
    }
    public void Stavi(T element)
    {
      if (vrh >= maxVelicina)
        throw new StackOverflowException();
      elementi[vrh] = element;
      vrh++;
    }
    public T Skini()
    {
      vrh--;
      if (vrh >= 0)
      {
        return elementi[vrh];
      }
      else
      {
        vrh = 0;
        throw new InvalidOperationException("Stog je prazan!");
      }
    }
  }


  class Generics
  {
    static void Main(string[] args)
    {
      // koristenje stoga
      Stog<int> stogInt = new Stog<int>();
      stogInt.Stavi(5);
      stogInt.Stavi(7);
      stogInt.Stavi(9);

      Console.WriteLine(stogInt.Skini().ToString());

      Stog<string> stogString = new Stog<string>();
      stogString.Stavi("jedan");
      stogString.Stavi("dva");

      Console.WriteLine(stogString.Skini().ToString());


      // koristenje gotovih generickih razreda (System.Collection.Generics)

      List<string> listaString = new List<string>();
      listaString.Add("jedan");
      listaString.Add("dva");
      listaString.Add("tri");

      string trazeni;

      do
      {
        Console.WriteLine("Traženi element liste: ");
        trazeni = Console.ReadLine();

        if (listaString.Contains(trazeni))
          Console.WriteLine("Element postoji u listi na " + listaString.IndexOf(trazeni) + ". mjestu.");
        else Console.WriteLine("Element ne postoji u listi!");
      }
      while (listaString.Contains(trazeni));



    }
  }
}

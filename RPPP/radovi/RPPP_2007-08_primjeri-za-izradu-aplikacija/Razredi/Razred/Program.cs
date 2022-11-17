using System;

class Razred
{
  public int var = 0;
  public const int konst = 1;
  public readonly int neDiraj;

  public Razred()
  {
    Console.WriteLine("Konstruktor 1");
    neDiraj = 0;
  }
  public Razred(int neDiraj0)
  {
    Console.WriteLine("Konstruktor 2");
    neDiraj = neDiraj0;
  }
  public Razred(int neDiraj0, int var0)
  {
    Console.WriteLine("Konstruktor 3");
    neDiraj = neDiraj0;
    var = var0;
  }
  ~Razred()
  {
    Console.WriteLine("Destruktor");
  }

}
class PristupClanu
{
  static void Main(string[] args)
  {

    const int D = Razred.konst + 1;
    Console.WriteLine("konst = " + Razred.konst);
    Console.WriteLine("D = " + D);

    //Razred.var +=1;
    //Console.WriteLine(Razred.var);
    //Console.WriteLine(Razred.neDiraj);

    Razred r1 = new Razred();
    r1.var += 1;
    Console.WriteLine("var = " + r1.var);

    Razred r2 = new Razred(13);
    Console.WriteLine("var = " + r2.var);
    Console.WriteLine("neDiraj = " + r2.neDiraj);


    Razred r3 = new Razred(13, 7);
    Console.WriteLine("var = " + r3.var);
    Console.WriteLine("neDiraj = " + r3.neDiraj);


    //Razred.neDiraj +=1;
    //Console.WriteLine(Razred.konst);


    Razred x = r3;
    x.var = 99;
    Console.WriteLine("var = " + x.var);
    Console.WriteLine("neDiraj = " + x.neDiraj);
  }
}

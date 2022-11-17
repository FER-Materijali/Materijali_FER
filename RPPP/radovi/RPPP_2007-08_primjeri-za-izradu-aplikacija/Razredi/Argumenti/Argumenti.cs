// U razvojnom suèelju argumenti se zadaju u
// Project Properties / Configuration / Debugging / Start Options
using System;

class Argumenti
{
  public static void DumpParameters(params object[] args)
  {
    Console.WriteLine("Params: ");
    for (int iArg = 0; iArg < args.Length; iArg++)
      Console.WriteLine("{0}:{1}", iArg, args[iArg]);

    // alternativa s foreach
    //foreach(object o in args)
    //  Console.WriteLine("{0}:{1}", o.GetHashCode(), o);
  }

  static void Main(params string[] args)
  {
    DumpParameters(args);
    DumpParameters("jen", "dva", 3);
    DumpParameters();
  }
}




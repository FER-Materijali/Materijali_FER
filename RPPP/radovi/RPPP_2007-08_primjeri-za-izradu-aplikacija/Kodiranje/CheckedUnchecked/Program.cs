using System;
using System.Collections.Generic;
using System.Text;

namespace CheckedUnchecked
{
  class Program
  {
    [STAThread]
    static void Main(string[] args)
    {
      Counter counter1 = new Counter(1, true);
      Counter counter2 = new Counter(1, true);

#if true
      counter1.EnableCheck = false;
#endif
      // bez provjere preljeva
      
      for (int i = 1; i < 15; i++)
      {
        counter1 *= i;
        Console.WriteLine(i + " " + counter1.Value);
      }
      
      try
      {
        // provjera preljeva
        for (int i = 1; i < 15; i++)
        {
          counter2 *= i;
          Console.WriteLine(i + " " + counter2.Value);
        }
      }
      catch (Exception e)
      {
        Console.WriteLine("Exception: {0}", e.Message);
      }
      Console.ReadLine();
    }
  }
}

class Counter
{
  public int Value = 0;
  public bool EnableCheck = false; // zastavica provjere

  public Counter(int val, bool enableCheck)
  {
    this.Value = val;
    this.EnableCheck = enableCheck;
  }

  public static Counter operator *(Counter op1, int op2)
  {
    int newVal;

    if (op1.EnableCheck)
      // množenje uz provjeru
      newVal = checked(op1.Value * op2);

    else
      // množenje bez provjere
      newVal = unchecked(op1.Value * op2);

    return new Counter(newVal, op1.EnableCheck);
  }
}

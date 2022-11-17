using System;
using System.Collections.Generic;
using System.Text;

namespace TryCatch
{
  class Program
  {
    static void Main(string[] args)
    {

      try
      {

#if true
        int x = 0;
        int y = 10 / x;
#endif
        int[] a = { 1, 2, 3 };
        Console.WriteLine(a[3].ToString());
      }
#if false
      catch(DivideByZeroException e)
      {
          Console.WriteLine("Dijeljenje s 0. " + e.Message);
      }
      catch(IndexOutOfRangeException e)
      {
          Console.WriteLine("Indeks izvan granica polja. " + e.Message);
      }
#endif
      catch (Exception e)
      {
        Console.WriteLine("Pogreška. " + e.Message);
      }
      finally
      {
        Console.WriteLine("Napokon.\n");
      }

    }
  }
}

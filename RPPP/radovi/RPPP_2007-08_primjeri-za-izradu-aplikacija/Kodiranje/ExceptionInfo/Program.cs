using System;
using System.Collections.Generic;
using System.Text;

namespace ExceptionInfo
{
  class Program
  {
    static void Main(string[] args)
    {
      int input;

      while ((input = DisplayMenu()) != 5)
      {
        if (input == 1 || input == 2)
        {
          ThrowException(input);
        }
        else
        {
          try
          {
            ThrowException(input);
          }
          catch (ApplicationException e)
          {
            Console.WriteLine("Aplikacijska iznimka:");
            DisplayExceptionInformation(e);
          }
          catch (SystemException e)
          {
            Console.WriteLine("Sistemska iznimka:");
            DisplayExceptionInformation(e);
          }
          catch (Exception e)
          {
            Console.WriteLine("Nepoznata pogreška:");
            DisplayExceptionInformation(e);
          }
        }
      }
    }

    static void DisplayExceptionInformation(Exception e)
    {
      Console.WriteLine("Izvor: {0}", e.Source);
      Console.WriteLine("Postupak: {0}", e.TargetSite);
      Console.WriteLine("Poruka: {0}", e.Message);
      Console.WriteLine("Trag: {0}", e.StackTrace);
      if (e.HelpLink != null)
        Console.WriteLine("Help Link: {0}", e.HelpLink);
    }

    static void ThrowException(int input)
    {
      switch (input)
      {
        case 1:
        case 3:
          {
            throw new SystemException("Case" + input.ToString());
          }
        case 2:
        case 4:
          {
            throw new ApplicationException("Case" + input.ToString());
          }
        default:
          {
            throw new ArgumentException("Case" + input.ToString());
          }
      }
    }

    static int DisplayMenu()
    {
      int input = 0;

      Console.WriteLine("1) Baci sistemsku");
      Console.WriteLine("2) Baci aplikacijsku");
      Console.WriteLine("3) Baci i uhvati sistemsku");
      Console.WriteLine("4) Baci i uhvati aplikacijsku");
      Console.WriteLine("5) Kraj");

      Console.Write("Proba iznimki: ");

      try
      {
        input = Int32.Parse(Console.ReadLine());
      }
      catch
      {
        Console.WriteLine("Unesi broj!\n");
        return DisplayMenu();
      }
      return input;
    }
  }
}

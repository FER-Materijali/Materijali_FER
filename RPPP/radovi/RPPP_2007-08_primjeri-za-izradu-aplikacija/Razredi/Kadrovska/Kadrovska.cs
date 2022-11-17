// nasljedni polimorfizam

using System;

namespace Kadrovska
{
  class Kadrovska
  {
    [STAThread]
    static void Main(string[] args)
    {
      Kadar personal = new Kadar();

      personal.Isplata();

    } // end of method Main

  } // end of class Kadrovska

} // end of namespace

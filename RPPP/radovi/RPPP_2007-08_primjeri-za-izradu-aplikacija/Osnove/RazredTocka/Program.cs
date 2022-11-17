using System;

class Test
{
  static void Main(string[] args)
  {
    Tocka t = new Tocka(1, -2);
    Console.WriteLine("Toèka ({0},{1}) je u {2}.kvadrantu.", t.cx, t.cy, t.Kvadrant());
  }
}

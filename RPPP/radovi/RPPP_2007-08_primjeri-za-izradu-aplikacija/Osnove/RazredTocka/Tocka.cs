using System;

class Tocka
{
  //varijable
  public int cx;
  public int cy;

  //konstruktor
  public Tocka(int x, int y)
  {
    cx = x;
    cy = y;
  }

  //javna metoda
  public int Kvadrant()
  {
    if (cx > 0)
    {
      if (cy > 0) return 1;
      else return 4;
    }
    else
    {
      if (cy > 0) return 2;
      else return 3;
    }
  }
}

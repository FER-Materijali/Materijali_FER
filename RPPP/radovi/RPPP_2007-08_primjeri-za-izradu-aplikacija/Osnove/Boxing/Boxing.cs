using System;

class Boxing
{
  static public void Main()
  {
    long l = 9600;
    object o = l;
    ShowObject(o);
    o = 4096;
    ShowObject(o);
    Point point = new Point(42, 96);
    ShowObject(point);
    clsBox test = new clsBox();
    ShowObject(test);
  }
  static public void ShowObject(object o)
  {
    if (o is int)
      Console.WriteLine("The object is an integer");
    if (o is long)
      Console.WriteLine("The object is a long");
    if (o is Point)
      Console.WriteLine("The object is a Point structure");
    if (o is clsBox)
      Console.WriteLine("The object is a clsBox class object");
    Console.WriteLine("The value of object is " + o + "\r\n");
  }
}

struct Point
{
  public int cx;
  public int cy;

  public Point(int x, int y)
  {
    cx = x;
    cy = y;
  }

  public override string ToString()
  {
    return ("(" + cx + ", " + cy + ")");
  }
}

class clsBox
{
  public override string ToString()
  {
    return ("\"-- clsBox --\"");
  }
}

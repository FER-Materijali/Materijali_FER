using System;
interface IPoint
{
  // Property signatures:
  int x { get; set; }
  int y { get; set; }
}

class MyPoint : IPoint
{
  // Fields:
  private int myX;
  private int myY;

  // Constructor:   
  public MyPoint(int x, int y)
  {
    myX = x;
    myY = y;
  }

  // Properties:
  public int x
  {
    get { return myX; }
    set { myX = value; }
  }
  public int y
  {
    get { return myY; }
    set { myY = value; }
  }
}

class InterfaceMain
{
  private static void PrintPoint(IPoint p)
  {
    Console.WriteLine(
      "MyPoint: x={0}, y={1}",
      p.x, p.y);
  }

  public static void Main()
  {
    MyPoint p = new MyPoint(2, 3);
    PrintPoint(p);
  }
}


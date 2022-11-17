using System;
public class Kalkulator
{
  private int result;

  public Kalkulator()
  {
    result = 0;
  }
  public Kalkulator(int x)
  {
    result = x;
  }

  public void displayResult()
  {
    Console.WriteLine("Result = {0}", result);
  }
  public void add(int x)
  {
    result = result + x;
  }
  public void subtract(int x)
  {
    result = result - x;
  }
}

class Test
{
  public static void Main(string[] args)
  {
    Kalkulator mC = new Kalkulator(90);
    mC.displayResult();
    mC.add(45);
    mC.displayResult();
    mC.subtract(35);
    mC.displayResult();
    mC.subtract(110);
    mC.displayResult();
  }
}


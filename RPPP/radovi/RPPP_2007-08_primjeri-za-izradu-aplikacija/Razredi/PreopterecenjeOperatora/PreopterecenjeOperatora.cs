using System;

public class ComplexNumber
{
  private int re;
  private int im;

  public ComplexNumber() { }
  public ComplexNumber(int a, int b)
  {
    re = a;
    im = b;
  }

  public override string ToString()
  {
    return "( " + re +
      (im < 0 ? " - " + (im * -1) :
      " + " + im) + "i )";
  }

  public int Re
  {
    get { return re; }
    set { re = value; }
  }

  public int Im
  {
    get { return im; }
    set { im = value; }
  }

  // overload the addition operator
  // note the static modifier
  public static ComplexNumber operator +(ComplexNumber x, ComplexNumber y)
  {
    return new ComplexNumber(x.Re + y.Re, x.Im + y.Im);
  }

  // provide alternative to overloaded + operator
  public static ComplexNumber Add(ComplexNumber x, ComplexNumber y)
  {
    return x + y;
  }

  // overload the subtraction operator
  public static ComplexNumber operator -(ComplexNumber x, ComplexNumber y)
  {
    return new ComplexNumber(x.Re - y.Re, x.Im - y.Im);
  }

  // provide alternative to overloaded - operator
  public static ComplexNumber Subtract(ComplexNumber x, ComplexNumber y)
  {
    return x - y;
  }

  // overload the multiplication operator
  public static ComplexNumber operator *(ComplexNumber x, ComplexNumber y)
  {
    return new ComplexNumber(x.Re * y.Re - x.Im * y.Im, x.Re * y.Im + y.Re * x.Im);
  }

  // provide alternative to overloaded * operator
  public static ComplexNumber Multiply(ComplexNumber x, ComplexNumber y)
  {
    return x * y;
  }

}



class OperatorOverload
{
  static void Main(string[] args)
  {
    ComplexNumber x = new ComplexNumber(10, 20);
    ComplexNumber y = new ComplexNumber(30, 40);

    Console.WriteLine(x + " + " + y + " = " + (x + y));
    Console.WriteLine(x + " - " + y + " = " + (x - y));
    Console.WriteLine(x + " * " + y + " = " + (x * y));

    Console.WriteLine(x + " + " + y + " = " + ComplexNumber.Add(x, y));
    Console.WriteLine(x + " - " + y + " = " + ComplexNumber.Subtract(x, y));
    Console.WriteLine(x + " * " + y + " = " + ComplexNumber.Multiply(x, y));

  }
}

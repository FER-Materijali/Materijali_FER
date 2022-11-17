using System;
using System.Windows.Forms;

/// <summary>
/// Summary description for Class1
/// </summary>
public class Osoba
{
  private string jmbg;
  public string JMBG
  {
    get { return jmbg; }
    set { jmbg = value; }
  }

  bool VratiPare(string name)
  {
    string fullMessage = "Vrati pare " + name;
    DateTime currTime = DateTime.Now;
    fullMessage += fullMessage + " u " + currTime.ToString();
    MessageBox.Show(fullMessage);
    bool showResult = true;
    if (showResult == true)
    {
      for (int i = 0; i < 10; i++)
      {
        // radi
      }
    }

    return true;
  }
}

public class MojaMatka
{
  private const short BrojDanaTjedna = 7;
  public const double PI = 3.14159;
  public const float PDV = 0.22f;
}

public enum Barjak
{
  Crven = 1, Bijeli = 2, Plavi = 3
}
public class Krumpir
{ }

public class PoljeKrumpira
{
  const int VelicinaPolja = 100;
  Krumpir[] polje = new Krumpir[VelicinaPolja];

  PoljeKrumpira()
  {
    for (int i = 0; i < polje.Length; ++i)
    {
      polje[i] = new Krumpir();
    }
  }
}

public class Program
{
  static void Main(string[] args)
  {
    float f = 3.14f;
    bool b;
    if (f == 3.14)
    {
      b = true;
    }

    f = 10 * 0.01f;
    if (f == 0.1)
    {
      b = true;
    }
  }
}


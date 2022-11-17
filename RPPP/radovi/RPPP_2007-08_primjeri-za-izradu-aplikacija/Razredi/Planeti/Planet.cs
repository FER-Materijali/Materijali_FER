
class Planet
{
  private int radijus;
  private double gravitacija;
  private string ime;
  private static int count;

  public int Radijus
  {
    get { return radijus; }
  }
  public double Gravitacija
  {
    get { return gravitacija; }
  }
  public string Ime
  {
    get { return ime; }
    set { ime = value; }
  }


  public Planet(int r, double g, string n)
  {
    radijus = r;
    gravitacija = g;
    ime = n;

    count++;
  }

  public static int GetCount()
  {
    return count;
  }

}


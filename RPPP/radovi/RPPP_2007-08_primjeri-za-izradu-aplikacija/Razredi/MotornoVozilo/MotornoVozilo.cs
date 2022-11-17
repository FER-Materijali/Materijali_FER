using System;

// razred MotornoVozilo (bazni razred)
class MotornoVozilo
{
  // atributi
  private string model;
  public string Model
  {
    get { return model; }
    set { model = value; }
  }

  private double snaga;
  public double Snaga
  {
    get { return snaga; }
    set { snaga = value; }
  }

  // konstruktor
  public MotornoVozilo(string model, double snaga)
  {
    this.model = model;
    this.snaga = snaga;
  }

  // metoda (zajednicka svim vozilima)
  public void DajGas()
  {
    Console.WriteLine(model + " daje gas!");
  }

  // metoda (koju izvedene klase implementiraju svaka na svoj nacin)
  public virtual void Start()
  {
    Console.Write("Start... ");
  }

}

// razred Automobil (izveden iz razreda MotornoVozilo)
class Automobil : MotornoVozilo
{
  // dodatni atribut
  private int brVrata;

  public int BrVrata
  {
    get { return brVrata; }
    set { brVrata = value; }
  }

  // konstruktor
  public Automobil(string model, double snaga, int brVrata)
    : base(model, snaga)  // poziv baznog konstruktora
  {
    this.brVrata = brVrata;
  }

  // nadjaèavanje bazne metode Start() 
  public override void Start()
  {
    Console.WriteLine("Kreæe automobil: " + Model);
  }

  // dodatna metoda za Automobil
  public void VeziPojas()
  {
    Console.WriteLine("Veži pojas!");
  }

}


// razred Motocikl (izveden iz razreda MotornoVozilo)
class Motocikl : MotornoVozilo
{

  // dodatni atribut
  private bool prikolica;

  public bool Prikolica
  {
    get { return prikolica; }
    set { prikolica = value; }
  }

  // konstruktor
  public Motocikl(string model, double snaga, bool prikolica)
    : base(model, snaga)  // poziv baznog konstruktora
  {
    this.prikolica = prikolica;
  }

  // nadjaèavanje bazne metode 
  public override void Start()
  {
    // ... tu bi trebala doci drugacija implementacija nego kod automobila
    Console.WriteLine("Kreæe motocikl: " + Model);
  }

}

public class Program
{
  public static void Main()
  {
    MotornoVozilo v = new MotornoVozilo("BWM", 133);
    v.Start();

    // objekt tipa Automobil
    Automobil auto = new Automobil("Toyota Corolla", 100, 5);
    Console.WriteLine("auto.model = " + auto.Model);
    Console.WriteLine("auto.snaga = " + auto.Snaga);
    Console.WriteLine("auto.brVrata = " + auto.BrVrata);

    auto.VeziPojas();
    auto.Start();
    auto.DajGas();

    // objekt tipa Motocikl
    Motocikl moto = new Motocikl("Toyota Corolla", 100, false);
    Console.WriteLine("moto.model = " + moto.Model);
    Console.WriteLine("moto.snaga = " + moto.Snaga);
    Console.WriteLine("moto.prikolica = " + moto.Prikolica);

    moto.Start();
    moto.DajGas();

  }

}

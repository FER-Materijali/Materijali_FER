using System;
using System.Collections.Generic;
using System.Text;

namespace Agregacija
{
  class Program
  {
    static void Main(string[] args)
    {
      Firma f = new Firma();
      Djelatnik d = new Djelatnik();
      f.Zaposli(d);
      f = null;
      // nezaposlen
      Console.WriteLine(d.ToString());

      StudentskaSluzba s = new StudentskaSluzba();
      s = null;
      GC.Collect(); // azuriramo stanje u memoriji
      Console.WriteLine("Studomat?");

    }
  }

  #region Firma
  class Firma
  {
    int brojDjelatnika = 0;
    private Djelatnik[] nadnicar = new Djelatnik[3];
    public void MolimPovisicu(Djelatnik d) { }

    public void Zaposli(Djelatnik d) 
    { 
      nadnicar[brojDjelatnika++] = d; 
    }

    ~Firma()
    {
      Console.WriteLine("Bankrotiram");
    }
  }

  class Djelatnik
  {
    private Firma vlasnik;
    private Djelatnik sef;
    private Djelatnik[] sluga;
    public void OtpustenSi() { }
    ~Djelatnik()
    {
      System.Console.WriteLine("Umirovljen");
      ;
    }
  }
  #endregion

  #region Studentska
  public class Studomat
  {
    public Studomat() { Console.WriteLine("Studomat jedan"); }
    ~Studomat() { Console.WriteLine("Studomat nijedan"); }
    void prijaviIspit() { }
    void odjaviIspit() { }
  };

  class StudentskaSluzba
  {
    private Studomat[] studomati;
    public StudentskaSluzba()
    {
      studomati = new Studomat[3];
      studomati[0] = new Studomat();
    }
    ~StudentskaSluzba()
    {
      studomati[0] = null;
      // delete[] studomati;
    }
    void dohvatiStudomat() { }
    void dohvatiSveStudomate() { }
    void azurirajStudomat() { }
    void azurirajSveStudomate() { }
  }
  #endregion
}

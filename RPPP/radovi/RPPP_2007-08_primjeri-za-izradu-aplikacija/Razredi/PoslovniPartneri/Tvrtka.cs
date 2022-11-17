using System;
using System.Collections.Generic;
using System.Text;


class Tvrtka : PoslovniPartner
{
  private string naziv;

  public string Naziv
  {
    get { return naziv; }
  }

  public Tvrtka(string maticniBroj, string adresaSjedista, string adresaIsporuke,
    string naziv)
    : base(maticniBroj, adresaSjedista, adresaIsporuke)
  {
    this.naziv = naziv;
  }

  //Override pišemo uvijek kada implementiramo abstract metode razreda kojeg nasljeðujemo
  public override string ToString()
  {
    return naziv + "\n" + base.ToString();
  }

  public override bool ValidacijaMaticnogBroja()
  {
    if (MaticniBroj.Length == 7) return true;
    else return false;
  }

}



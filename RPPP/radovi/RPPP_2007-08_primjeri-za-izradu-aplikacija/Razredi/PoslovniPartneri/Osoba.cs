using System;
using System.Collections.Generic;
using System.Text;
using System.Collections;


class Osoba : PoslovniPartner
{
  private string ime;
  private string prezime;

  public string Ime
  {
    get { return ime; }
  }
  public string Prezime
  {
    set { prezime = value; }
    get { return prezime; }
  }

  public Osoba(string maticniBroj, string adresaSjedista, string adresaIsporuke,
    string ime, string prezime)
    : base(maticniBroj, adresaSjedista, adresaIsporuke)
  {
    this.ime = ime;
    this.prezime = prezime;
  }

  public override string ToString()
  {
    return ime + " " + prezime + "\n" + base.ToString();
  }

  public override bool ValidacijaMaticnogBroja()
  {
    if (MaticniBroj.Length == 13) return true;
    else return false;
  }
}



using System;
using System.Collections.Generic;
using System.Text;
using System.Collections;


class Osoba
{
  PoslovniPartner poslovniPartner;
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
  {
    this.ime = ime;
    this.prezime = prezime;
    this.poslovniPartner = new PoslovniPartner(maticniBroj, adresaSjedista, adresaIsporuke);
  }

  public override string ToString()
  {
    return ime + " " + prezime + "\n" + poslovniPartner.ToString();
  }

}

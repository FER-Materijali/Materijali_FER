using System;
using System.Collections.Generic;
using System.Text;


abstract class PoslovniPartner
{
  private string maticniBroj;
  private string adresaSjedista;
  private string adresaIsporuke;

  public string MaticniBroj
  {
    get { return maticniBroj; }
  }
  public string AdresaSjedista
  {
    set { adresaSjedista = value; }
    get { return adresaSjedista; }
  }
  public string AdresaIsporuke
  {
    set { adresaIsporuke = value; }
    get { return adresaIsporuke; }
  }

  public PoslovniPartner(string maticniBroj, string adresaSjedista, string adresaIsporuke)
  {
    this.maticniBroj = maticniBroj;
    if (!this.ValidacijaMaticnogBroja()) throw new Exception("Pogreška unosa matiènog broja!");
    this.adresaSjedista = adresaSjedista;
    this.adresaIsporuke = adresaIsporuke;
  }

  //Override metode ToString() koja je nasljeðena iz razreda System.Object
  public override string ToString() //Ovu metodu nije potrebno implementirati u razredu koji nasljeðuje ovaj! Ukoliko je implementriamo potrebno je dodati kljuènu rijeè override!
  {
    return maticniBroj +
      "\nAdresa Sjedišta: \n" + adresaSjedista +
      "\nAdresa Isporuke: \n" + adresaIsporuke;
  }

  public abstract bool ValidacijaMaticnogBroja(); //Zbog abstract, ovu metodu potrebno je implementirati u razredu koji nasljeðuje ovaj! Takoðer, abstract znaèi da je neæemo implementirati ovdje!

}



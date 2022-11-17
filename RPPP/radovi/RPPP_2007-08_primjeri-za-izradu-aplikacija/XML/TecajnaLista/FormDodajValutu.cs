using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Xml;

namespace TecajnaLista
{
  public partial class FormDodajValutu : Form
  {
    string imeDatoteke;

    public FormDodajValutu(string imeDatoteke)
    {
      this.imeDatoteke = imeDatoteke;
      InitializeComponent();
    }

    private XmlElement NewElement(XmlDocument xmlDokument, string nazivElementa, string text)
    {
      XmlElement xmlElement = xmlDokument.CreateElement(nazivElementa);
      XmlText xmlText = xmlDokument.CreateTextNode(text);
      xmlElement.AppendChild(xmlText);
      return xmlElement;
    }

    private void buttonDodaj_Click(object sender, EventArgs e)
    {
      XmlDocument tecajnaLista = new XmlDocument();
      tecajnaLista.Load(imeDatoteke);

      XmlElement novaValuta = tecajnaLista.CreateElement("Currency");

      XmlElement nazivValute = NewElement(tecajnaLista, "Name", textBoxNaziv.Text);
      XmlElement jedinica = NewElement(tecajnaLista, "Unit", textBoxJedinica.Text);
      XmlElement kupovniEf = NewElement(tecajnaLista, "BuyRateCache", textBoxKupovniEf.Text);
      XmlElement kupovniDe = NewElement(tecajnaLista, "BuyRateForeign", textBoxKupovniDe.Text);
      XmlElement srednji = NewElement(tecajnaLista, "MeanRate", textBoxSrednji.Text);
      XmlElement prodajniDe = NewElement(tecajnaLista, "SellRateForeign", textBoxProdajniDe.Text);
      XmlElement prodajniEf = NewElement(tecajnaLista, "SellRateCache", textBoxProdajniEf.Text);

      novaValuta.AppendChild(nazivValute);
      novaValuta.AppendChild(jedinica);
      novaValuta.AppendChild(kupovniEf);
      novaValuta.AppendChild(kupovniDe);
      novaValuta.AppendChild(srednji);
      novaValuta.AppendChild(prodajniDe);
      novaValuta.AppendChild(prodajniEf);

      tecajnaLista.DocumentElement.FirstChild.AppendChild(novaValuta);

      tecajnaLista.Save(imeDatoteke);

      MessageBox.Show("Uspješno spremljeno!");
      this.Close();
    }
  }
}
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
  public partial class FormTecajnaLista : Form
  {
    string imeDatoteke;

    public FormTecajnaLista()
    {
      InitializeComponent();
    }

    private void buttonDodaj_Click(object sender, EventArgs e)
    {
      FormDodajValutu formaDodaj = new FormDodajValutu(imeDatoteke);
      formaDodaj.ShowDialog();
      UcitajXMLDoc();
      UcitajXMLSet();
    }

    private void buttonBrowse_Click(object sender, EventArgs e)
    {
      openFileDialogTecajnaLista.ShowDialog();
      textBoxDatoteka.Text = openFileDialogTecajnaLista.FileName;
    }

    private void buttonUcitaj_Click(object sender, EventArgs e)
    {
      imeDatoteke = textBoxDatoteka.Text;
      
      UcitajXMLDoc();
      UcitajXMLSet();

      buttonDodaj.Enabled = true;
      buttonWrite.Enabled = true;
    }

    private void UcitajXMLSet()
    {
      XmlDataDocument xmlLista = new XmlDataDocument();
      xmlLista.DataSet.ReadXml(new StreamReader(imeDatoteke), XmlReadMode.InferSchema);
      
      textBoxXMLSchema.Text = xmlLista.DataSet.GetXmlSchema();
      textBoxXML.Text = xmlLista.DataSet.GetXml();
      
      dataGridView1.DataSource = xmlLista.DataSet;
      dataGridView1.DataMember = xmlLista.DataSet.Tables[1].TableName; // 0-"ExchRate";
    }

    private void UcitajXMLDoc()
    {
      listView1.Items.Clear();

      // punimo tecajnuListu iz xml datoteke
      XmlDocument tecajnaLista = new XmlDocument();
      tecajnaLista.Load(imeDatoteke);

      // dohvacamo listu cvorova po nazivu oznake (currency - valuta)
      XmlNodeList listaValuta = tecajnaLista.GetElementsByTagName("Currency");

      // za svaki cvor dohvacamo ime, jedinicu, prodajni, srednji i kupovni tecaj
      foreach (XmlNode cvor in listaValuta)
      {
        XmlElement valuta = (XmlElement)cvor;

        XmlNode nazivValute = valuta.GetElementsByTagName("Name")[0];
        XmlNode jedinicaValute = valuta.GetElementsByTagName("Unit")[0];
        XmlNode kupovniEfektiva = valuta.GetElementsByTagName("BuyRateCache")[0];
        XmlNode kupovniDevize = valuta.GetElementsByTagName("BuyRateForeign")[0];
        XmlNode srednji = valuta.GetElementsByTagName("MeanRate")[0];
        XmlNode prodajniDevize = valuta.GetElementsByTagName("SellRateForeign")[0];
        XmlNode prodajniEfektiva = valuta.GetElementsByTagName("SellRateCache")[0];

        ListViewItem item = new ListViewItem(nazivValute.InnerText);
        item.SubItems.Add(jedinicaValute.InnerText);
        item.SubItems.Add(kupovniEfektiva.InnerText);
        item.SubItems.Add(kupovniDevize.InnerText);
        item.SubItems.Add(srednji.InnerText);
        item.SubItems.Add(prodajniDevize.InnerText);
        item.SubItems.Add(prodajniEfektiva.InnerText);

        listView1.Items.Add(item);
      }
    }

    private void buttonSpremi_Click(object sender, EventArgs e)
    {
      ((DataSet)dataGridView1.DataSource).WriteXml(@"c:\projects\tecajna.xsd", XmlWriteMode.WriteSchema); 
      ((DataSet)dataGridView1.DataSource).WriteXml(@"c:\projects\tecajna.xml", XmlWriteMode.IgnoreSchema);
      MessageBox.Show(@"c:\projects\tecajna.* Ok");
    }
  }
}
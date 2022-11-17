using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Skladiste
{
  public partial class Form1 : Form
  {

    int indeksTrenutnogRetka = 0;
    DateTime datumOd, datumDo;

    Servis.Service1 servis;
    DataTable tablica;

    enum Redak { SifArtikla, NazArtikla, KolArtikla, Kolicina };

    public Form1()
    {
      InitializeComponent();

      servis = new Servis.Service1();

    }


    private DataTable NapuniTablicu()
    {
      datumOd = dateTimePickerOd.Value;
      datumDo = dateTimePickerDo.Value;
      
      DataTable tablica = new DataTable();

      // stupci dobiveni iz objekta tipa Stavka
      tablica.Columns.Add("SifArtikla", typeof(int));
      tablica.Columns.Add("NazArtikla", typeof(string));
      tablica.Columns.Add("KolArtikla", typeof(decimal));
      // stupac s kolicinom za naruciti
      tablica.Columns.Add("Kolicina", typeof(decimal));

      try
      {
        Servis.Stavka[] lista = servis.DohvatiStavkeUkupno(datumOd, datumDo);
        foreach (Servis.Stavka stavka in lista)
        {
          tablica.Rows.Add(stavka.SifArtikla, stavka.NazArtikla, stavka.KolArtikla, 0);
        }      
      }
      catch (Exception ex)
      {
        MessageBox.Show(ex.Message);
      }

      return tablica;
    }


    //slanje stavki servisu
    private void menuItemNaruci_Click(object sender, EventArgs e)
    {
      try
      {
        List<Servis.Stavka> lista = new List<Servis.Stavka>();
        for (int i = 0; i < tablica.Rows.Count; i++)
        {
          DataRow redak = tablica.Rows[i];
          if ((decimal)redak[(int)Redak.Kolicina] > 0)
          {
            Servis.Stavka stavka = new Servis.Stavka();
            stavka.SifArtikla = (int)redak[(int)Redak.SifArtikla];
            stavka.NazArtikla = (string)redak[(int)Redak.NazArtikla];
            stavka.KolArtikla = (decimal)redak[(int)Redak.Kolicina];
            lista.Add(stavka);
          }
        }

        Servis.Stavka[] listaStavki = new Servis.Stavka[lista.Count];
        int pozicija = 0;
        foreach (Servis.Stavka s in lista)
        {
          listaStavki[pozicija] = s;
          pozicija++;
        }
        servis.NapraviNarudzbu(listaStavki);
        MessageBox.Show("Narudžba je zaprimljena!");
      }
      catch (Exception ex)
      {
        MessageBox.Show("Došlo je do pogreške: " + ex.Message);
      }

    }

    //prikaz detalja za editiranje
    private void dataGrid1_CurrentCellChanged(object sender, EventArgs e)
    {
      if ((indeksTrenutnogRetka = dataGrid1.CurrentRowIndex) >= 0)
      {
        labelNazivArtikla.Text = tablica.Rows[indeksTrenutnogRetka][(int)Redak.NazArtikla].ToString()
            + " (" + tablica.Rows[indeksTrenutnogRetka][(int)Redak.SifArtikla].ToString() + ")";
        textBoxKolicina.Text = tablica.Rows[indeksTrenutnogRetka][(int)Redak.Kolicina].ToString();
      }
    }

    //prikaz unesene vrijednosti za naruciti u gridu
    private void textBoxKolicina_LostFocus(object sender, EventArgs e)
    {
      tablica.Rows[indeksTrenutnogRetka][(int)Redak.Kolicina] = Convert.ToDecimal(textBoxKolicina.Text.ToString());
    }

    private void menuItemPrikazi_Click(object sender, EventArgs e)
    {
      dataGrid1.Enabled = true;
      panel1.Enabled = true;
      menuItemNaruci.Enabled = true;
      tablica = NapuniTablicu();
      dataGrid1.DataSource = tablica;
      dataGrid1_CurrentCellChanged(null, null);
    }

  }
}
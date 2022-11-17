using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Data.OleDb;
using System.Configuration;
using CrystalDecisions.CrystalReports.Engine;
using CrystalDecisions.Shared;

namespace DokumentiStavke
{


  public partial class DokumentiStavkeForm : Form
  {

    string connString = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=C:\\Projects\\Firma.mdb";

    public DokumentiStavkeForm()
    {
      InitializeComponent();

      OleDbDataAdapter adapterPartneri = new OleDbDataAdapter("SELECT IdOsobe AS IdPartnera, PrezimeOsobe + ' ' + ImeOsobe + '  (' + JMBG + ')'  AS NazivPartnera FROM Osoba UNION  SELECT IdTvrtke AS IdPartnera, NazivTvrtke + '  (' + MatBrTvrtke + ')' AS NazivPartner FROM Tvrtka", connString);
      DataTable tablicaPartneri = new DataTable();
      adapterPartneri.Fill(tablicaPartneri);
      comboBoxPartner.DataSource = tablicaPartneri;
      comboBoxPartner.DisplayMember = "NazivPartnera";
      comboBoxPartner.ValueMember = "IdPartnera";    

    }

    private void buttonIzvjestaj_Click(object sender, EventArgs e)
    {
      try
      {
        if (listViewDokumenti.CheckedItems.Count != 0)
        {
          ReportDocument reportRacun = new ReportDocument();
          reportRacun.Load(@"..\..\StavkeDokumenta.rpt");

          // postavljamo parametre (listu idDokumenta) po kojem ce se izvjesce puniti 
          ParameterValues parametri = new ParameterValues();
          foreach (ListViewItem item in listViewDokumenti.CheckedItems)
          {
            parametri.AddValue(item.Text);
          }

          reportRacun.SetParameterValue("idDok", parametri);
          reportViewer.ReportSource = reportRacun;
        }
      }
      catch (Exception ex)
      {
        MessageBox.Show("Došlo je do pogreške: " + ex.Message);
      }

    }

    private void buttonDokumenti_Click(object sender, EventArgs e)
    {
      FillDokumentList(comboBoxPartner.SelectedValue.ToString());
    }

    void FillDokumentList(string idPartnera)
    {

      OleDbConnection conn = new OleDbConnection(connString);
      conn.Open();

      OleDbCommand comm = new OleDbCommand("SELECT IdDokumenta, BrDokumenta, DatDokumenta, IznosDokumenta FROM Dokument WHERE IdPartnera = " + idPartnera, conn);
      OleDbDataReader reader = comm.ExecuteReader();

      listViewDokumenti.Items.Clear();

      while (reader.Read())
      {
        // id dokumenta
        ListViewItem item = new ListViewItem(reader[0].ToString());
        
        // broj dokumenta
        item.SubItems.Add(reader[1].ToString());
        
        // datum dokumenta - formatiramo ga za prikaz
        DateTime datum = (DateTime)reader[2];
        item.SubItems.Add(datum.Day.ToString() + "." + datum.Month.ToString() + "." + datum.Year.ToString());

        // iznos dokumenta - formatiramo ga za prikaz
        string iznos = String.Format("{0:C}", reader[3]);
        item.SubItems.Add(iznos.ToString());

        listViewDokumenti.Items.Add(item);
      }

      conn.Close();
    }


  }
}
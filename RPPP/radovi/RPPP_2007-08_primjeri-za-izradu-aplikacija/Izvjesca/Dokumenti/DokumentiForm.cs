using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Configuration;
using CrystalDecisions.CrystalReports.Engine;
using CrystalDecisions.Shared;
using System.Data.OleDb;

namespace Dokumenti
{
  public partial class DokumentiForm : Form
  {

    DataSetDokumenti dataSetDokumenti;
    string connString = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=C:\\Projects\\Firma.mdb";

    DateTime datumOd, datumDo;

    public DokumentiForm()
    {
      InitializeComponent();
      dataSetDokumenti = new DataSetDokumenti();

      OleDbDataAdapter adapterPartneri = new OleDbDataAdapter("SELECT IdOsobe AS IdPartnera, PrezimeOsobe + ' ' + ImeOsobe + '  (' + JMBG + ')'  as NazivPartnera FROM Osoba UNION  SELECT IdTvrtke as IdPartnera, NazivTvrtke + '  (' + MatBrTvrtke + ')' as NazivPartner FROM Tvrtka", connString);
      DataTable tablicaPartneri = new DataTable();
      adapterPartneri.Fill(tablicaPartneri);

      comboBoxPartneri.DataSource = tablicaPartneri;
      comboBoxPartneri.DisplayMember = "NazivPartnera";
      comboBoxPartneri.ValueMember = "IdPartnera";

      dateTimePickerDo.Value = DateTime.Now;
      dateTimePickerOd.Value = DateTime.Now.AddMonths(-1);

    }

    private void buttonDokumenti_Click(object sender, EventArgs e)
    {
      try
      {
        NapuniTablice();
        // Stvaranje objekta ReportDocument
        ReportDocument reportDokumenti = new ReportDocument();
        // Ucitavanje izvjesca
        reportDokumenti.Load(@"..\..\DokumentiPoDatumu.rpt");
        // Postavljanje izvora za izvjesce
        reportDokumenti.SetDataSource(dataSetDokumenti);

        //Postavljanje naslova izvjesca
        if (!checkBoxSviDatumi.Checked)
          reportDokumenti.SummaryInfo.ReportTitle = "Popis dokumenata po datumu\nza razdoblje  " + datumOd.ToShortDateString() + " do " + datumDo.ToShortDateString();
        else reportDokumenti.SummaryInfo.ReportTitle = "Popis svih dokumenata po datumu";

        if (!checkBoxSviPartneri.Checked)
          reportDokumenti.SummaryInfo.ReportTitle += "\n" + comboBoxPartneri.Text;

        // Postavljanje izvjesca na ReportViewer
        reportViewer.ReportSource = reportDokumenti;

      }
      catch (Exception ex)
      {
        MessageBox.Show("Došlo je do pogreške: " + ex.Message);
      }
    }

    private void buttonAdrese_Click(object sender, EventArgs e)
    {
      try
      {
        NapuniTablice();

        ReportDocument reportAdrese = new ReportDocument();

        reportAdrese.Load(@"..\..\AdresePartnera.rpt");
        reportAdrese.SetDataSource(dataSetDokumenti);

        reportViewer.ReportSource = reportAdrese;
      }
      catch (Exception ex)
      {
        MessageBox.Show("Došlo je do pogreške: " + ex.Message);
      }
    }

    private void NapuniTablice()
    {
      try
      {
        string dokumentUpit = "SELECT * FROM Dokument ";
        string partnerUpit = "SELECT DISTINCT vw_PoslovniPartner.* FROM vw_PoslovniPartner";

        if (!checkBoxSviDatumi.Checked)
        {

          datumOd = dateTimePickerOd.Value;
          datumDo = dateTimePickerDo.Value;
          if (datumDo < datumOd) throw new Exception("Neispravno unesen datum: Gornja granica treba biti veæa ili jednaka donjoj. ");

          string razdoblje = "WHERE (Dokument.DatDokumenta BETWEEN "
              + "#" + datumOd.Year.ToString() + "/" + datumOd.Month.ToString() + "/" + datumOd.Day.ToString() + "# AND "
              + "#" + datumDo.Year.ToString() + "/" + datumDo.Month.ToString() + "/" + datumDo.Day.ToString() + "#)";

          dokumentUpit += razdoblje;

          if (!checkBoxSviPartneri.Checked)
          {
            dokumentUpit += " AND Dokument.IdPartnera = " + comboBoxPartneri.SelectedValue.ToString();
            partnerUpit += " WHERE vw_PoslovniPartner.IdPartnera = " + comboBoxPartneri.SelectedValue.ToString();
          }
          else
          {
            partnerUpit += ", Dokument " + razdoblje + " AND vw_PoslovniPartner.IdPartnera=Dokument.IdPartnera";
          }
        }
        else if (!checkBoxSviPartneri.Checked)
        {
          dokumentUpit += " WHERE Dokument.IdPartnera = " + comboBoxPartneri.SelectedValue.ToString();
          partnerUpit += " WHERE vw_PoslovniPartner.IdPartnera = " + comboBoxPartneri.SelectedValue.ToString();
        }

        dataSetDokumenti.Clear();
        dataSetDokumenti.EnforceConstraints = false;
        OleDbDataAdapter daDokumenti = new OleDbDataAdapter(dokumentUpit, connString);
        daDokumenti.Fill(dataSetDokumenti.Dokument);

        OleDbDataAdapter daPartneri = new OleDbDataAdapter(partnerUpit, connString);
        daPartneri.Fill(dataSetDokumenti.vw_PoslovniPartner);
      }
      catch (Exception e)
      {
        throw e; // proslijedi pogresku, da se ne generira izvjestaj
      }
    }

    private void checkBoxSviDatumi_CheckedChanged(object sender, EventArgs e)
    {
      if (checkBoxSviDatumi.Checked)
      {
        dateTimePickerOd.Enabled = false;
        dateTimePickerDo.Enabled = false;
      }
      else
      {
        dateTimePickerOd.Enabled = true;
        dateTimePickerDo.Enabled = true;
      }
    }

    private void checkBoxSviPartneri_CheckedChanged(object sender, EventArgs e)
    {
      if (checkBoxSviPartneri.Checked)
        comboBoxPartneri.Enabled = false;
      else comboBoxPartneri.Enabled = true;
    }


  }
}
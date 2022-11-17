using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Configuration;
using System.Data.OleDb;
using System.Threading;


namespace MasterDetail
{
  public partial class DokumentStavka : Form
  {

    private OleDbCommand cmdCount;

    public DokumentStavka()
    {
      InitializeComponent();
    }

    #region Load

    private void DokumentStavka_Load(object sender, EventArgs e)
    {
      try
      {
        dataSetDokumentStavka.EnforceConstraints = false;

        oleDbDataAdapterDokument.Fill(dataSetDokumentStavka);
        oleDbDataAdapterStavka.Fill(dataSetDokumentStavka);
        oleDbDataAdapterPartnerJoin.Fill(dataSetDokumentStavka);
        oleDbDataAdapterArtikl.Fill(dataSetDokumentStavka);

#if false  // izraèunata polja, programski
        dataSetDokumentStavka.Stavka.Columns.Add(
            "UkCijArtikla", typeof(float),
            "JedCijArtikla * KolArtikla * (1 - PostoRabat)");
        dataSetDokumentStavka.Dokument.Columns.Add(
            new DataColumn(
            "UkIznosDokumenta", typeof(float),
            "Sum(Child(FK_Dokument_Stavka).UkCijArtikla) * (1 + PostoPorez)")
            );
        dataSetDokumentStavka.Dokument.Columns.Add(
            new DataColumn(
            "BrStavki", typeof(int),
            "Count(Child(FK_Dokument_Stavka).IdDokumenta)")
            );
#endif
       
        dokumentBindingSource.PositionChanged += new EventHandler(dokumentPositionChanged);

        BindData();

        UpdateDisplay();

      }
      catch (OleDbException ex)
      {
        MessageBox.Show("Pogreška rada s bazom: " + ex.Message);
        //this.Close();
      }
      catch (Exception ex)
      {
        MessageBox.Show("Pogreška: " + ex.Message);
      }
    }

    #endregion

    #region Povezivanje podataka
    void BindData()
    {
      textBoxIdDokumenta.DataBindings.Add("Text", dokumentBindingSource, "IdDokumenta");
      textBoxVrDokumenta.DataBindings.Add("Text", dokumentBindingSource, "VrDokumenta");
      textBoxBrDokumenta.DataBindings.Add("Text", dokumentBindingSource, "BrDokumenta");
      dateDatDokumenta.DataBindings.Add("Value", dokumentBindingSource, "DatDokumenta");
      textBoxPorez.DataBindings.Add("Text", dokumentBindingSource, "PostoPorez");

      textBoxBrStavki.DataBindings.Add("Text", dokumentBindingSource, "BrStavki");

      comboBoxPartner.DataSource = dataSetDokumentStavka.Osoba;
      comboBoxPartner.DisplayMember = "NazPartnera";
      comboBoxPartner.ValueMember = "IdPartnera";
      comboBoxPartner.DataBindings.Add(
        "SelectedValue", dokumentBindingSource, "IdPartnera");

#if false // kreirano u dizajnu
      //comboBoxIdPrethDokumenta.DataSource = fkDokumentDokumentBindingSource;
      //pristup temeljem stranog kljuèa reducirao bi broj kandidata 
      
      comboBoxIdPrethDokumenta.DataSource = prethDokumentDokumentBindingSource;
      comboBoxIdPrethDokumenta.DisplayMember = "NazDokumenta";
      comboBoxIdPrethDokumenta.ValueMember = "IdDokumenta";
      comboBoxIdPrethDokumenta.DataBindings.Add(
        "SelectedValue", dokumentBindingSource, "dokumentBindingSource - IdPrethDokumenta");
#endif
      
      // formatiranje i validacija
      Binding b = new Binding("Text", dokumentBindingSource, "UkIznosDokumenta");
      b.Format += new ConvertEventHandler(DecimalToCurrencyString);
      b.Parse += new ConvertEventHandler(CurrencyStringToDecimal);
      textBoxIznos.DataBindings.Add(b);
    }
    #endregion

    #region Navigacija

    private void buttonNext_Click(object sender, EventArgs e)
    {
      dokumentBindingSource.MoveNext();
    }

    private void buttonPrevious_Click(object sender, EventArgs e)
    {
      dokumentBindingSource.MovePrevious();
    }

    private void buttonLast_Click(object sender, EventArgs e)
    {
      dokumentBindingSource.MoveLast();
    }

    private void buttonFirst_Click(object sender, EventArgs e)
    {
      dokumentBindingSource.MoveFirst();
    }

    void UpdateDisplay()
    {
      if (dokumentBindingSource == null || dokumentBindingSource.Count == 0) return;

      labelPosition.Text = ((dokumentBindingSource.Position + 1).ToString()
                       + " od  "
                       + dokumentBindingSource.Count.ToString());
      //PrebrojiStavke();
    }

    private void dokumentPositionChanged(Object sender, EventArgs e)
    {
      if (dokumentBindingSource.Count == 0) return;

      UpdateDisplay();
    }
    #endregion

    #region Brojanje i postavljanje broja stavki (alternativno)

    // alternativno prebrojavanje stavki - upitom na bazu podataka
    void PrebrojiStavke()
    {
      oleDbConnection1.Open();
      cmdCount.Parameters["@IdDokumenta"].Value = textBoxIdDokumenta.Text;
      int cnt = (int)cmdCount.ExecuteScalar();
      oleDbConnection1.Close();
      textBoxBrStavki.Text = cnt.ToString();
    }

    void CommandBroji()
    {
      cmdCount = new OleDbCommand(
       "SELECT COUNT(*) AS Broj FROM Stavka WHERE "
       + " (IdDokumenta = @IdDokumenta)"
       , oleDbConnection1);

      cmdCount.Parameters.Add(
        new OleDbParameter("@IdDokumenta",
            OleDbType.Integer, 4, "IdDokumenta"));
    }

    #endregion

    #region Spremanje/Odustajanje

    private void buttonSpremi_Click(object sender, EventArgs e)
    { 
      // ažuriranje izvedene vrijednosti
      DataRow row = ((DataRowView)dokumentBindingSource.Current).Row;
      if (row["IznosDokumenta"] != row["ukIznosDokumenta"]) 
      {
        row["IznosDokumenta"] = row["ukIznosDokumenta"];
      }

      dokumentBindingSource.EndEdit();
      fKDokumentStavkaBindingSource.EndEdit(); 

      UpdateData();
    }

    void UpdateData()
    {
      try
      {
        if (dataSetDokumentStavka.HasChanges())
        {
          oleDbDataAdapterDokument.Update(dataSetDokumentStavka.Dokument);
          oleDbDataAdapterStavka.Update(dataSetDokumentStavka.Stavka);
        }
      }
      catch (OleDbException ex)
      {
        MessageBox.Show("Došlo je do pogreške kod rada s bazom: " + ex.Message);
      }
      catch (Exception ex)
      {
        MessageBox.Show("Došlo je do pogreške: " + ex.Message);
      }
    }

    private void buttonOdustani_Click(object sender, EventArgs e)
    {
      dokumentBindingSource.CancelEdit();
      fKDokumentStavkaBindingSource.CancelEdit();
      dataSetDokumentStavka.RejectChanges();
    }

    #endregion

    #region Postupci Format/Parse

    private void DecimalToCurrencyString(object sender, ConvertEventArgs cevent)
    {
      // The method converts only to string type. Test this using the DesiredType.
      if (cevent.DesiredType != typeof(string)) return;

      // Use the ToString method to format the value as currency ("c").
      try
      {
        cevent.Value = ((decimal)cevent.Value).ToString("c");
      }
      catch 
      {
        cevent.Value = ((decimal)0).ToString("c");
      }
    }

    private void CurrencyStringToDecimal(object sender, ConvertEventArgs cevent)
    {
      // The method converts back to decimal type only. 
      if (cevent.DesiredType != typeof(decimal)) return;

      // Converts the string back to decimal using the static Parse method.
      cevent.Value = Decimal.Parse(cevent.Value.ToString(), 
        System.Globalization.NumberStyles.Currency, null);
    }

    #endregion

    #region Ažuriranje jediniène cijene artikla

    private void dataGridViewStavke_CellEndEdit(object sender, DataGridViewCellEventArgs e)
    {
      if (e.ColumnIndex == 1) // odabran artikl
      {
        dataSetDokumentStavka.Artikl.DefaultView.Sort = "SifArtikla";
        DataRowView drv = (DataRowView)fKDokumentStavkaBindingSource.Current;
        DataRowView row = ((dataSetDokumentStavka.Artikl.DefaultView.FindRows(
             (((DataGridView)sender)["SifArtikla", 
             fKDokumentStavkaBindingSource.Position]).Value)))[0];

        drv["JedCijArtikla"] = row["CijArtikla"];

        drv.EndEdit();
      }
    }

    #endregion

  }
}
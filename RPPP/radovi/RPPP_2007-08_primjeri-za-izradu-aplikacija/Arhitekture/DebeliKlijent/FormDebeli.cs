using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace DebeliKlijent
{
  public partial class FormDebeli : Form
  {
    public FormDebeli()
    {
      InitializeComponent();
    }

    private void FormDebeli_Load(object sender, EventArgs e)
    {
      sqlDataAdapterPromet.Fill(dataSetDebeli.PrometPartnera);

      //dataGridViewPromet_CurrentCellChanged(null, null);
    }

    private void dataGridViewPromet_CurrentCellChanged(object sender, EventArgs e)
    {
      if (!this.Visible) return;
      if (dataGridViewPromet.CurrentRow == null) return;
      int idDokumenta = (int)dataGridViewPromet.CurrentRow.Cells[0].Value;

      string selectDokument = @"
				SELECT IdDokumenta, VrDokumenta, BrDokumenta, DatDokumenta, IznosDokumenta	
				FROM Dokument
				WHERE	Dokument.IdPartnera = " + idDokumenta.ToString();

      // dohvat detalja 
      SqlConnection conDokument = new SqlConnection(sqlConnection1.ConnectionString);
      conDokument.Open();
      SqlDataAdapter sqlDataAdapterDokument = new SqlDataAdapter(selectDokument, conDokument);
      DataSet dataSetDokument = new DataSet("DokumentPartnera"); 
      sqlDataAdapterDokument.Fill(dataSetDokument);
      dataGridViewDokument.DataSource = dataSetDokument.Tables[0];
    }

  }
}
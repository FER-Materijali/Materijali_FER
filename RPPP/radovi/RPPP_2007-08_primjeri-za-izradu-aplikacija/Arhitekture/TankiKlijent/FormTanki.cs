using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace TankiKlijent
{
  public partial class FormTanki : Form
  {
    public FormTanki()
    {
      InitializeComponent();
    }

    private void FormTanki_Load(object sender, EventArgs e)
    {
      SqlDataAdapter sqlDataAdapterPromet = new SqlDataAdapter("ap_PrometPartnera", sqlConnection1);
      DataSet dataSetPromet = new DataSet("PrometPartnera");
      sqlDataAdapterPromet.Fill(dataSetPromet);
      dataGridViewPromet.DataSource = dataSetPromet.Tables[0];
    }

    private void dataGridViewPromet_CurrentCellChanged(object sender, EventArgs e)
    {
      if (!this.Visible) return;
      if (dataGridViewPromet.CurrentRow == null) return;
      int idDokumenta = (int)dataGridViewPromet.CurrentRow.Cells[0].Value;

      // dohvat detalja 
      SqlConnection conDokument = new SqlConnection(sqlConnection1.ConnectionString);
      conDokument.Open();
      SqlDataAdapter sqlDataAdapterDokument = new SqlDataAdapter("ap_DokumentPartnera " + idDokumenta.ToString(), conDokument);
      DataSet dataSetDokument = new DataSet("DokumentPartnera");
      sqlDataAdapterDokument.Fill(dataSetDokument);
      dataGridViewDokument.DataSource = dataSetDokument.Tables[0];
    }
  }
}
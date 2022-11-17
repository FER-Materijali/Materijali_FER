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


namespace MasterDetailUntyped
{
  public partial class DatasetUntyped : Form
  {

    private DataViewManager dsView;
    private String connectionString;
    private DataSet dsUntyped;

    OleDbDataAdapter oleDbDataAdapterDokument;
    OleDbDataAdapter oleDbDataAdapterStavka;

    public DatasetUntyped()
    {
      InitializeComponent();

    }

    private void DokumentStavka_Load(object sender, EventArgs e)
    {
      CreateData();
      BindData();
    }

    void CreateData()
    {
      try
      {
        connectionString = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=C:\\Projects\\Firma.mdb;Persist Security Info=True";
        OleDbConnection cn = new OleDbConnection(connectionString);

        dsUntyped = new DataSet("DataSetUntyped");
        //dsUntyped.EnforceConstraints = false;

        // dodavanje tablica, punjenje tablica, mapiranje
        oleDbDataAdapterDokument = new OleDbDataAdapter(
          "SELECT IdOsobe AS IdPartnera, PrezimeOsobe+ImeOsobe AS Naziv, JMBG AS Broj FROM Osoba" +
          " UNION " +
          "SELECT IdTvrtke AS IdPartnera, NazivTvrtke AS Naziv, MatBrTvrtke AS Broj FROM Tvrtka",
          cn);
        oleDbDataAdapterDokument.TableMappings.Add("Table", "Partner");
        oleDbDataAdapterDokument.Fill(dsUntyped);

        #region DinamickiNapravljenaTablica
        oleDbDataAdapterStavka = new OleDbDataAdapter("SELECT * FROM Dokument", cn);

        DataTable dt = new DataTable("Dokument");
        dt.Columns.Add("IdDokumenta", typeof(int));
        dt.Columns.Add("VrDokumenta", typeof(string));
        dt.Columns.Add("BrDokumenta", typeof(int));
        dt.Columns.Add("DatDokumenta", typeof(System.DateTime));
        dt.Columns.Add("IdPartnera", typeof(int));
        //dt.Columns.Add("IznosDokumenta", typeof(decimal));

        dsUntyped.Tables.Add(dt);

        // ukoliko se ne navede, adapter generira shemu, unatoè mapping
        oleDbDataAdapterStavka.MissingSchemaAction = MissingSchemaAction.Ignore;

        //oleDbDataAdapterStavka.TableMappings.Add("Table", "Dokument");
        //oleDbDataAdapterStavka.TableMappings[0].ColumnMappings.Add("IdDokumenta","IdDokumenta");
        //oleDbDataAdapterStavka.TableMappings[0].ColumnMappings.Add("VrDokumenta","VrDokumenta");
        //oleDbDataAdapterStavka.TableMappings[0].ColumnMappings.Add("BrDokumenta","BrDokumenta");
        //oleDbDataAdapterStavka.TableMappings[0].ColumnMappings.Add("DatDokumenta","DatDokumenta");
        //oleDbDataAdapterStavka.TableMappings[0].ColumnMappings.Add("IdPartnera","IdPartnera");

        oleDbDataAdapterStavka.Fill(dsUntyped, "Dokument");

        // dinamicko kreiranje stranog kljuca
        //ForeignKeyConstraint fk;
        //fk = new System.Data.ForeignKeyConstraint("FK_Partner_Dokument",
        //dsUntyped.Tables["Partner"].Columns["IdPartnera"],
        //dsUntyped.Tables["Dokument"].Columns["Idpartnera"]);
        //dsUntyped.Tables["Dokument"].Constraints.Add(fk);

        // dinamicko kreiranje ogranicenja na jedinstvene vrijednosti
        UniqueConstraint uc;
        uc = new System.Data.UniqueConstraint("NewUnique",
             new DataColumn[] { 
                   dt.Columns["VrDokumenta"], 
                   dt.Columns["BrDokumenta"] }
                 , false);
        //     dt.Columns["IdDokumenta"]); // bez new
        dt.Constraints.Add(uc);

        #endregion

        // dodavanje veze FK_Dokument_Stavka
        DataRelation relOrdDet;
        DataColumn colMaster;
        DataColumn colDetail;

        colMaster = dsUntyped.Tables["Partner"].Columns["IdPartnera"];
        colDetail = dsUntyped.Tables["Dokument"].Columns["IdPartnera"];
        relOrdDet = new DataRelation("FK_Partner_Dokument", colMaster, colDetail);
        dsUntyped.Relations.Add(relOrdDet);

        //expression
        dsUntyped.Tables["Partner"].Columns.Add(
              new DataColumn(
                      "BrojDokumenata", typeof(float),
                      "Count(Child(FK_Partner_Dokument).IdDokumenta)")
            );
        // alternativa za tipove: Type.GetType("System.Float") //, ("System.Int32"), ("System.String")
      }
      catch (Exception ex)
      {
        MessageBox.Show(ex.Message);
      }
    }

    void BindData()
    {
      dsView = dsUntyped.DefaultViewManager;

      dataGridViewGlava.DataSource = dsView;
      dataGridViewGlava.DataMember = "Partner";

      dataGridViewStavke.DataSource = dsView;
      dataGridViewStavke.DataMember = "Partner.FK_Partner_Dokument";
    }
  }
}
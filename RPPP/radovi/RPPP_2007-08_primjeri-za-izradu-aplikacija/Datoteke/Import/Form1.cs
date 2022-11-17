using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Data.OleDb;
using System.Data.SqlClient;


namespace Import
{
  public partial class Form1 : Form
  {

    string datotekaConnString;
    string sqlConnString = @"Data Source=(local)\IVANA;Integrated Security=SSPI;Initial Catalog=Firma";

    OleDbConnection datotekaConn;
    SqlConnection sqlConn;

    string nazivTablice;
    string nazivLista;
    string folder = @"..\..\";
    string datoteka = "podaci.xls";
    
    List<string> stupciDatoteke;

    DataTable dt;
    SqlDataAdapter adapter;

    public Form1()
    {
      InitializeComponent();
      Init();
    }

    private void Init()
    {
      textBoxDatoteka.Text = folder + datoteka;
      PostaviDatotekaConnString();

      comboBoxList.DataSource = DohvatiListoveDatoteke();
      PostaviListove();

      comboBoxTablice.DataSource = DohvatiTabliceBaze();
      comboBoxTablice.Text = "Artikl";
    }

    private void PostaviDatotekaConnString()
    {
      string ekst = Ekstenzija(datoteka);
      datotekaConnString = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" + folder;
      if (ekst == ".xls")
      {
        datotekaConnString += datoteka + "; Extended Properties='Excel 8.0;HDR=Yes'";
      }
      else
      {
        datotekaConnString += "; Extended Properties='text;FMT=Delimited;HDR=Yes'";
      }
    }
    private void OtvoriSqlKonekciju()
    {
      if (sqlConn == null)
      {
        sqlConn = new SqlConnection(sqlConnString);
      }
      if (sqlConn.State != ConnectionState.Open)
      {
        sqlConn.Open();
      }
    }
    private void OtvoriDatotekaKonekciju()
    {
      if (datotekaConn == null || (datotekaConn.ConnectionString != datotekaConnString))
      {
        datotekaConn = new OleDbConnection(datotekaConnString);
      }
      if (datotekaConn.State != ConnectionState.Open)
      {
        datotekaConn.Open();
      }
    }
    private void ZatvoriKonekcije()
    {
      if (datotekaConn.State == ConnectionState.Open)
      {
        datotekaConn.Close();
      }
      if (sqlConn.State == ConnectionState.Open)
      {
        sqlConn.Close();
      }
    }

    // ako je datoteka excel dohvaca popis listova i prikazuje u comboBoxu, ako je .csv ne
    // nazivLista za excel: [sheet$], za csv naziv datoteke
    private void PostaviListove()
    {
      string ekst = Ekstenzija(datoteka);
      if (ekst == ".xls")
      {
        comboBoxList.Enabled = true;
        comboBoxList.DataSource = DohvatiListoveDatoteke();
        nazivLista = "[" + comboBoxList.Text + "]";
      }
      if (ekst == ".csv" || ekst == ".txt")
      {
        comboBoxList.Enabled = false;
        comboBoxList.DataSource = null;
        nazivLista = datoteka;
      }
    }

    private void buttonBrowseDatoteka_Click(object sender, System.EventArgs e)
    {
      OpenFileDialog fileDialog = new OpenFileDialog();
      fileDialog.AddExtension = true;
      fileDialog.InitialDirectory = ".";
      fileDialog.CheckFileExists = true;
      fileDialog.DefaultExt = ".xls";
      fileDialog.Filter = "Excel Files (*.xls)|*.xls|Text Files (*.csv;*.txt)|*.csv;*txt";
      fileDialog.Title = "Odaberite datoteku";

      if (fileDialog.ShowDialog(this) == DialogResult.OK)
      {
        PostaviFolderDatoteku(fileDialog.FileName);
        textBoxDatoteka.Text = fileDialog.FileName;

        PostaviDatotekaConnString();
        PostaviListove();
      }
    }

    private void PostaviFolderDatoteku(string put)
    {
      datoteka = put.Substring(put.LastIndexOf("\\") + 1, put.Length - put.LastIndexOf("\\") - 1);
      folder = put.Substring(0, put.LastIndexOf("\\") + 1);
    }

    private string Ekstenzija(string dat)
    {
      int indeks = dat.LastIndexOf(".");
      string ekstenzija = dat.Substring(indeks);
      return ekstenzija;
    }

    private void buttonMapiranje_Click(object sender, EventArgs e)
    {
      // prikupljamo oznaèene parametre (imena datoteke, tablice i lista)
      PrikupiParametre();

      // brišemo kontrole ako ih ima
      Control[] kontrole = this.Controls.Find("kontrolaMapiranje", false);
      foreach (Control kontrola in kontrole)
      {
        this.Controls.Remove(kontrola);
      }
      this.Controls.RemoveByKey("buttonPrebaci");

      // dodajemo user kontrole
      int y = 110;
      for (int i = 0; i < dt.Columns.Count; i++)
      {
        UserControlMapiranje mapiranje = new UserControlMapiranje();

        mapiranje.ComboBindingContext = new BindingContext();
        mapiranje.NazivStupcaText = dt.Columns[i].ColumnName;
        mapiranje.CheckBoxOstaloChanged += new UserControlMapiranje.CheckBoxChangedHandler(this.checkOstaloChanged);
        mapiranje.DataSource = stupciDatoteke;
        mapiranje.Name = "kontrolaMapiranje";
        mapiranje.Location = new Point(0, y);
        y += 30;

        // ako je stupac auto increment (identity), ne dopustamo editiranje
        if (dt.Columns[i].AutoIncrement) mapiranje.Onemoguci();

        this.Controls.Add(mapiranje);
      }

      buttonPrebaci.Enabled = true;

      this.Controls.Add(buttonPrebaci);
    }

    private void buttonPrebaci_Click(object sender, System.EventArgs args)
    {
      PrebaciPodatke();
    }


    private void PrikupiParametre()
    {
      PostaviFolderDatoteku(textBoxDatoteka.Text);
      PostaviDatotekaConnString();
      PostaviListove();

      nazivTablice = comboBoxTablice.Text;
      PostaviSchemuTablice();
      stupciDatoteke = DohvatiStupceDatoteke();
    }

    private void PrebaciPodatke()
    {
      try
      {
        OtvoriDatotekaKonekciju();
        OleDbCommand datotekaComm = new OleDbCommand("SELECT * FROM " + nazivLista, datotekaConn);
        OleDbDataReader datotekaReader = datotekaComm.ExecuteReader();

        // postavljamo insert i update naredbe za adapter (generirane uz pomoc CommandBuildera)
        SqlCommandBuilder sb = new SqlCommandBuilder(adapter);
        adapter.InsertCommand = sb.GetInsertCommand();
        adapter.UpdateCommand = sb.GetUpdateCommand();

        List<string> stupciMapirani;
        int brDodanihZapisa = 0;
        int brObnovljenihZapisa = 0;

        while (datotekaReader.Read())
        {
          stupciMapirani = DohvatiVrijednosti(datotekaReader);

          // ruèno sastavljamo select upit (po primarnom kljucu)
          adapter.SelectCommand.CommandText = SelectPoKljucu(stupciMapirani);

          // punimo datatable dobivenim retkom 
          dt.Clear();
          adapter.Fill(dt);

          // ako nema takvog retka, radimo insert
          if (dt.Rows.Count == 0)
          {
            DataTableInsert(stupciMapirani);
            brDodanihZapisa++;
          }
          // inaèe radimo update
          else
          {
            DataTableUpdate(stupciMapirani);
            brObnovljenihZapisa++;
          }
          // proslijedimo promjene na bazu
          adapter.Update(dt);
        }
        ZatvoriKonekcije();

        MessageBox.Show("Prijenos je uspješno obavljen!" + "\n" + "Dodano je " + brDodanihZapisa + " zapisa." + "\n" + "Obnovljeno je " + brObnovljenihZapisa + " zapisa.");
      }
      catch (Exception ex)
      {
        MessageBox.Show("Došlo je do pogreške: " + ex.Message);
      }
    }

    private string SelectPoKljucu(List<string> vrijednosti)
    {
      string select = "SELECT * FROM " + nazivTablice;
      for (int i = 0; i < dt.PrimaryKey.Length; i++)
      {
        string primarniKljuc = dt.PrimaryKey[i].ToString();
        string vrijednost = vrijednosti[dt.Columns.IndexOf(primarniKljuc)];
        if (i == 0)
        {
          select += " WHERE " + primarniKljuc + " = '" + vrijednost + "'";
        }
        else
        {
          select += " AND " + primarniKljuc + " = '" + vrijednost + "'";
        }
      }
      return select;
    }

    private void DataTableInsert(List<string> vrijednosti)
    {
      try
      {
        DataRow dr = dt.NewRow();
        for (int i = 0; i < vrijednosti.Count; i++)
        {
          if (vrijednosti[i] == "null")
          {
            dr[i] = DBNull.Value;
          }
          else
          {
            dr[i] = vrijednosti[i];
          }
        }
        dt.Rows.Add(dr);
      }
      catch (Exception ex)
      {
        throw new Exception("Došlo je do pogreške prilikom umetanja retka u DataTable. ", ex);
      }
    }

    private void DataTableUpdate(List<string> vrijednosti)
    {
      try
      {
        for (int i = 0; i < vrijednosti.Count; i++)
        {
          if (!dt.Columns[i].AutoIncrement)
          {
            if (vrijednosti[i] == "null")
            {
              dt.Rows[0][i] = DBNull.Value;
            }
            else
            {
              dt.Rows[0][i] = vrijednosti[i];
            }
          }
        }
      }
      catch (Exception ex)
      {
        throw new Exception("Došlo je do pogreške prilikom osvježavanja tablice. ", ex);
      }
    }


    private List<string> DohvatiListoveDatoteke()
    {
      List<string> listovi = new List<string>();
      try
      {
        OtvoriDatotekaKonekciju();

        // vraæa tablicu s nazivima tablica baze (sheetova excela)
        DataTable tablicaShema = datotekaConn.GetOleDbSchemaTable(OleDbSchemaGuid.Tables, null);
        foreach (DataRow row in tablicaShema.Rows)
        {
          listovi.Add(row["TABLE_NAME"].ToString());
        }
      }
      catch (Exception ex)
      {
        MessageBox.Show("Došlo je do pogreške prilikom dohvaæanja listova excel datoteke: " + ex.Message);
      }
      return listovi;
    }

    private List<string> DohvatiTabliceBaze()
    {
      List<string> tablice = new List<string>();

      try
      {
        OtvoriSqlKonekciju();

        SqlCommand dohvatiTablice = new SqlCommand("SELECT table_name FROM INFORMATION_SCHEMA.Tables WHERE table_type ='BASE TABLE'", sqlConn);
        SqlDataReader tabliceReader = dohvatiTablice.ExecuteReader();

        while (tabliceReader.Read())
        {
          tablice.Add(tabliceReader[0].ToString());
        }
        tabliceReader.Close();
      }
      catch (Exception ex)
      {
        MessageBox.Show("Došlo je do pogreške prilikom dohvaæanja tablica baze: " + ex.Message);
      }
      return tablice;
    }

    private List<string> DohvatiStupceDatoteke()
    {
      List<string> stupciDatoteke = new List<string>();
      try
      {
        OtvoriDatotekaKonekciju();
        OleDbCommand datotekaComm = new OleDbCommand("SELECT * FROM " + nazivLista, datotekaConn);

        OleDbDataReader datotekaReader = datotekaComm.ExecuteReader();

        for (int i = 0; i < datotekaReader.FieldCount; i++)
        {
          stupciDatoteke.Add(datotekaReader.GetName(i));
        }
      }
      catch (Exception ex)
      {
        MessageBox.Show("Došlo je do pogreške prilikom dohvaæanja naziva stupaca datoteke: " + ex.Message);
      }
      return stupciDatoteke;
    }

    private void PostaviSchemuTablice()
    {
#if true
      // dovlacimo schemu zeljene tablice (imamo informaciju o primarnom kljucu), tablica se NE puni podacima
      try
      {
        OtvoriSqlKonekciju();
        dt = new DataTable();
        adapter = new SqlDataAdapter("SELECT * FROM " + nazivTablice, sqlConn);
        adapter.FillSchema(dt, SchemaType.Source);


#else   
      ////ovo je jos jedan nacin dohvacanja stupaca - iz tablice INFORMATION_SCHEMA.Columns na SqlServeru
     
      OtvoriSqlKonekciju();

      SqlCommand dohvatiStupce = new SqlCommand("SELECT column_name FROM INFORMATION_SCHEMA.Columns WHERE table_name = '" + nazivTablice + "'", sqlConn);
      SqlDataReader stupciReader = dohvatiStupce.ExecuteReader();

      while (stupciReader.Read())
        stupciTablice.Add(stupciReader[0].ToString());

      stupciReader.Close();
      return stupciTablice;

#endif

      }
      catch (Exception ex)
      {
        MessageBox.Show("Došlo je do pogreške prilikom postavljanja scheme tablice: " + ex.Message);
      }

    }

    private List<string> DohvatiVrijednosti(OleDbDataReader reader)
    {
      List<string> vrijednosti = new List<string>();
      try
      {
        Control[] kontrole = this.Controls.Find("kontrolaMapiranje", false);
        foreach (Control kontrola in kontrole)
        {
          UserControlMapiranje k = (UserControlMapiranje)kontrola;
          if (k.OstaloChecked)
          {
            vrijednosti.Add(k.OstaloText);
          }
          else
          {
            vrijednosti.Add(reader[k.ComboText].ToString());
          }
        }
      }
      catch (Exception ex)
      {
        MessageBox.Show("Došlo je do pogreške prilikom dohvaæanja retka datoteke: " + ex.Message);
      }
      return vrijednosti;
    }



    private void checkOstaloChanged(UserControlMapiranje sender)
    {
      sender.UrediPrikaz();
    }


  }
}
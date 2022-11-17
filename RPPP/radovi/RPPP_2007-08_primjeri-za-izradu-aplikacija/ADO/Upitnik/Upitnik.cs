using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Data.OleDb;
using System.Data.SqlClient;

namespace QueryManager
{
  public partial class Upitnik : Form
  {

    string connString = "";

    const string connStringSQLCON = "Data Source=SERVER\\INSTANCA;Initial Catalog=BAZA;User Id=KORISNIK;Password=SIFRA;";
    const string connStringMSJET = "Provider=Microsoft.Jet.OLEDB.4.0;User ID=admin;Password=;Data Source=PUTDOBAZE;";
    const string connStringOLEDBSQL = "Provider=SQLOLEDB.1;Data Source=SERVER\\INSTANCA;Initial Catalog=BAZA;User Id=KORISNIK;Password=SIFRA;";

    OleDbConnection oleDbConnection;
    SqlConnection sqlConnection;
    IDbConnection konekcija;

    public Upitnik()
    {
      InitializeComponent();
    }

    private void buttonExecute_Click(object sender, EventArgs e)
    {
      Obavi();
    }

    private void buttonNonQuery_Click(object sender, EventArgs e)
    {
      ObaviNonQuery();
    }

    private void buttonScalar_Click(object sender, EventArgs e)
    {
      ObaviScalar();
    }

    private void QueryManager_Load(object sender, EventArgs e)
    {
      this.radioButtonSQLCON.Checked = true;
      radioButtonSQLCON_CheckedChanged(null, null);
    }

    void ClearForm()
    {
      listViewRezultat.Items.Clear();
      listViewRezultat.Columns.Clear();
    }

    private void buttonOpen_Click(object sender, EventArgs e)
    {
      Otvori();
      Postavi();
    }

    void Otvori()
    {
      connString = textBoxConnString.Text;

      try
      {
        if ((radioButtonSQLCON.Checked))
        {
          sqlConnection = new SqlConnection(connString);
          konekcija = sqlConnection;
        }
        else
        {
          oleDbConnection = new OleDbConnection(connString);
          konekcija = oleDbConnection;
        }
        konekcija.Open();
      }
      catch (Exception ex)
      {
        MessageBox.Show("Pogreška otvaranja: " + ex.Message);
      }
    }

    void Obavi()
    {
      ClearForm();

      IDataReader reader;

      try
      {
        if ((radioButtonSQLCON.Checked))
        {
          SqlCommand sqlCommand = new SqlCommand(textBoxUpit.Text, sqlConnection);
          SqlDataReader sqlReader = sqlCommand.ExecuteReader();
          reader = sqlReader;
        }
        else
        {
          OleDbCommand oleCommand = new OleDbCommand(textBoxUpit.Text, oleDbConnection);
          OleDbDataReader oleReader = oleCommand.ExecuteReader();
          reader = oleReader;
        }

        for (int i = 0; i < reader.FieldCount; i++)
          listViewRezultat.Columns.Add(reader.GetName(i), 100, HorizontalAlignment.Left);

        while (reader.Read())
        {
          ListViewItem listItem = new ListViewItem(reader[0].ToString());
          for (int i = 1; i < reader.FieldCount; i++)
            listItem.SubItems.Add(reader[i].ToString());

          listViewRezultat.Items.Add(listItem);
        }
        reader.Close();
      }
      catch (Exception ex)
      {
        MessageBox.Show("Pogreška obavljanja: " + ex.Message);
      }
    }

    void ObaviNonQuery()
    {
      ClearForm();

      IDbCommand command;
      int result;

      try
      {
        if ((radioButtonSQLCON.Checked))
        {
          SqlCommand sqlCommand = new SqlCommand(textBoxUpit.Text, sqlConnection);
          command = sqlCommand;
        }
        else
        {
          OleDbCommand oleCommand = new OleDbCommand(textBoxUpit.Text, oleDbConnection);
          command = oleCommand;
        }

        result = command.ExecuteNonQuery();

        listViewRezultat.Columns.Add("Rezultat", 100, HorizontalAlignment.Right);
        ListViewItem listItem = new ListViewItem(result.ToString());
        listViewRezultat.Items.Add(listItem);

      }
      catch (Exception ex)
      {
        MessageBox.Show("Pogreška obavljanja: " + ex.Message);
      }
    }

    void ObaviScalar()
    {
      ClearForm();

      IDbCommand command;

      try
      {
        if ((radioButtonSQLCON.Checked))
        {
          SqlCommand sqlCommand = new SqlCommand(textBoxUpit.Text, sqlConnection);
          command = sqlCommand;
        }
        else
        {
          OleDbCommand oleCommand = new OleDbCommand(textBoxUpit.Text, oleDbConnection);
          command = oleCommand;
        }

        object o = command.ExecuteScalar();

        listViewRezultat.Columns.Add("Rezultat", 100, HorizontalAlignment.Right);
        ListViewItem listItem = new ListViewItem(o.ToString());
        listViewRezultat.Items.Add(listItem);

      }
      catch (Exception ex)
      {
        MessageBox.Show("Pogreška obavljanja: " + ex.Message);
      }
    }

    void Zatvori()
    {
      try
      {
        konekcija.Close();
      }
      catch (Exception ex)
      {
        MessageBox.Show("Pogreška zatvaranja: " + ex.Message);
      }
      Postavi();
    }

    void Postavi()
    {
      bool kako;
      kako = (konekcija.State == ConnectionState.Open);
      buttonOpen.Enabled = !kako;
      buttonExecute.Enabled = kako;
      buttonNonQuery.Enabled = kako;
      buttonScalar.Enabled = kako;
      buttonClose.Enabled = kako;
    }

    private void radioButtonSQLCON_CheckedChanged(object sender, EventArgs e)
    {
      textBoxConnString.Text = connStringSQLCON;
    }

    private void radioButtonMSJET_CheckedChanged(object sender, EventArgs e)
    {
      textBoxConnString.Text = connStringMSJET;
    }

    private void radioButtonOLEDBSQL_CheckedChanged(object sender, EventArgs e)
    {
      textBoxConnString.Text = connStringOLEDBSQL;
    }

    private void buttonClose_Click(object sender, EventArgs e)
    {
      Zatvori();
    }

    #region MogloJeOvako
    /// <summary>
    /// varijanta u kojoj za svaki tip podatka (konekcije) 
    /// pišemo odgovarajuæe procedure za obradu dogaðaja
    /// </summary>
    void OtvoriMSJET()
    {
      try
      {
        oleDbConnection = new OleDbConnection(connString);
        oleDbConnection.Open();
      }
      catch (OleDbException ex)
      {
        MessageBox.Show("Došlo je do pogreške kod otvaranja konekcije: " + ex.Message);
      }
      catch (Exception ex)
      {
        MessageBox.Show("Došlo je do pogreške: " + ex.Message);
      }
    }

    void ZatvoriMSJET()
    {
      try
      {
        oleDbConnection.Close();
      }
      catch (OleDbException ex)
      {
        MessageBox.Show("Došlo je do pogreške kod zatvaranja konekcije: " + ex.Message);
      }
      catch (Exception ex)
      {
        MessageBox.Show("Došlo je do pogreške: " + ex.Message);
      }
    }

    void OtvoriSQLCON()
    {
      try
      {
        sqlConnection = new SqlConnection(connString);
        sqlConnection.Open();
      }
      catch (SqlException ex)
      {
        MessageBox.Show("Došlo je do pogreške kod otvaranja konekcije: " + ex.Message);
      }
      catch (Exception ex)
      {
        MessageBox.Show("Došlo je do pogreške: " + ex.Message);
      }

    }

    void ZatvoriSQLCON()
    {
      try
      {
        sqlConnection.Close();
      }
      catch (SqlException ex)
      {
        MessageBox.Show("Došlo je do pogreške kod zatvaranja konekcije: " + ex.Message);
      }
      catch (Exception ex)
      {
        MessageBox.Show("Došlo je do pogreške: " + ex.Message);
      }
    }

    void OtvoriOLEDBSQL()
    {
      try
      {
        oleDbConnection = new OleDbConnection(connString);
        oleDbConnection.Open();
      }
      catch (OleDbException ex)
      {
        MessageBox.Show("Došlo je do pogreške kod otvaranja konekcije: " + ex.Message);
      }
      catch (Exception ex)
      {
        MessageBox.Show("Došlo je do pogreške: " + ex.Message);
      }

    }

    void ZatvoriOLEDBSQL()
    {
      try
      {
        oleDbConnection.Close();
      }
      catch (OleDbException ex)
      {
        MessageBox.Show("Došlo je do pogreške kod zatvaranja konekcije: " + ex.Message);
      }
      catch (Exception ex)
      {
        MessageBox.Show("Došlo je do pogreške: " + ex.Message);
      }
    }

    void Otvori_OLD()
    {
      connString = textBoxConnString.Text;

      if (radioButtonMSJET.Checked) OtvoriMSJET();
      else if (radioButtonSQLCON.Checked) OtvoriSQLCON();
      else if (radioButtonOLEDBSQL.Checked) OtvoriOLEDBSQL();

      radioButtonMSJET.Enabled = false;
      radioButtonSQLCON.Enabled = false;
      radioButtonOLEDBSQL.Enabled = false;

      buttonOpen.Enabled = false;
      buttonClose.Enabled = true;
    }

    void Pokreni_OLD()
    {
      ClearForm();

      try
      {

        OleDbCommand command = new OleDbCommand(textBoxUpit.Text, oleDbConnection);
        OleDbDataReader reader = command.ExecuteReader();


        for (int i = 0; i < reader.FieldCount; i++)
          listViewRezultat.Columns.Add(reader.GetName(i), 100, HorizontalAlignment.Left);

        while (reader.Read())
        {

          ListViewItem listItem = new ListViewItem(reader[0].ToString());
          for (int i = 1; i < reader.FieldCount; i++)
            listItem.SubItems.Add(reader[i].ToString());

          listViewRezultat.Items.Add(listItem);

        }

      }
      catch (OleDbException ex)
      {
        MessageBox.Show("Došlo je do pogreške u radu s bazom: \n" + ex.Message);
      }
      catch (Exception ex)
      {
        MessageBox.Show("Došlo je do pogreške: " + ex.Message);
      }
    }
    #endregion

  }

}
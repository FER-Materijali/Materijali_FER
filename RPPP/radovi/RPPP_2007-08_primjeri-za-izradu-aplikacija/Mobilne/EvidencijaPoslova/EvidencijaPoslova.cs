using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Data.SqlServerCe;
using System.Xml;

namespace AppointmentList
{
  public partial class EvidencijaPoslova : Form
  {

    private static string xmlDataFile = @"Program Files\EvidencijaPoslova\raspored.xml";
    private static string sqlDataFile = @"My Documents\raspored.sdf";
    private static string sqlCEConnectionString = "Data Source = " + sqlDataFile;

    private DataTable zadatakDataTable;

    //private string[] vrijemeStringArray = { "09:00 AM", "10:00 AM", "11:00 AM", "12:00 AM", "01:00 PM", "02:00 PM", "03:00 PM", "04:00 PM" };
    private string[] vrijemeStringArray = { "09:00", "10:00", "11:00", "12:00", "13:00", "14:00", "15:00", "16:00" };

    public EvidencijaPoslova()
    {
      InitializeComponent();
    }

    private void AppointmentList_Load(object sender, System.EventArgs e)
    {

      //Hrvatska verzija dana u tjednu
      System.Globalization.CultureInfo hrvatski = System.Globalization.CultureInfo.GetCultureInfo("hr-HR");

      int day = (int)DateTime.Now.DayOfWeek;
      DanLabel.Text = hrvatski.DateTimeFormat.DayNames[day];
      //DatumLabel.Text = DateTime.Now.Day.ToString() + "." + DateTime.Now.Month.ToString() + "." + DateTime.Now.Year.ToString();
      DatumLabel.Text = DateTime.Now.ToString("dd.MM.yyyy");

      // Look to see if we have a SQL Server CE database already
      if (File.Exists(sqlDataFile))
      {
        // We have a SLQ CE database so use it
        GetDataFromSLQCE();
      }
      else if (File.Exists(xmlDataFile))
      {
        // We do nor have a SLQ CE databse so use the xml file
        GetDataFromXML();
      }
      else
      {
        CreateDatabase();
        GetDataFromSLQCE();
      }

      // Setup the controls
      SetControls();
    }

    private void GetDataFromXML()
    {
      try
      {
        DataSet ds = new DataSet();
        ds.ReadXml(xmlDataFile);
        zadatakDataTable = ds.Tables[0];
        zadatakDataTable.DefaultView.Sort = "vrijeme";
      }
      catch (Exception ex)
      {
        MessageBox.Show("GetDataFromXML Error: \n" + ex.Message);
      }
    }

    private void GetDataFromSLQCE()
    {

      // Create a datatable if we don't have one yet
      if (zadatakDataTable == null)
      {
        zadatakDataTable = new DataTable();
      }

      // Create a dataadapter to get the current data
      SqlCeDataAdapter zadatakDataAdapter = new SqlCeDataAdapter("Select vrijeme, naziv, posao from raspored order by vrijeme", new SqlCeConnection(sqlCEConnectionString));
      zadatakDataTable.Clear();
      zadatakDataAdapter.Fill(zadatakDataTable);
      zadatakDataAdapter.Dispose();
    }

    private void SetControls()
    {
      //Populate the times comboBox
      vrijemeComboBox.DataSource = vrijemeStringArray;

      // bind the data tables here
      rasporedListBox.DataSource = zadatakDataTable;
      rasporedListBox.DisplayMember = "vrijeme";

      // Bind the label and text box to show the type of appointment
      nazivRasporedTextBox.DataBindings.Add("Text", zadatakDataTable, "naziv");
      posaoValueDisplayLabel.DataBindings.Add("Text", zadatakDataTable, "posao");
    }

    private void SaveToXMLButton_Click(object sender, System.EventArgs e)
    {
      BuildXMLDoc();
    }

    private void BuildXMLDoc()
    {

      XmlDocument xmlDoc = new XmlDocument();
      XmlNode zadatakNode;
      XmlNode vrijemeNode;
      XmlNode nazivNode;
      XmlNode posaoNode;

      try
      {
        if (!File.Exists(xmlDataFile))
        {
          //kreiranje root elementa
          XmlDeclaration dec = xmlDoc.CreateXmlDeclaration("1.0", "utf-8", null);
          xmlDoc.AppendChild(dec);
          XmlElement root = xmlDoc.CreateElement("raspored");
          xmlDoc.AppendChild(root);
        }
        else
        {
          //otvaranje postojece datoteke
          xmlDoc.Load(xmlDataFile);
        }

        zadatakNode = xmlDoc.CreateElement("zadatak");
        xmlDoc.DocumentElement.AppendChild(zadatakNode);

        vrijemeNode = xmlDoc.CreateElement("vrijeme");
        vrijemeNode.InnerText = vrijemeComboBox.SelectedValue.ToString();
        zadatakNode.AppendChild(vrijemeNode);

        nazivNode = xmlDoc.CreateElement("naziv");
        nazivNode.InnerText = nazivTextBox.Text;
        zadatakNode.AppendChild(nazivNode);

        posaoNode = xmlDoc.CreateElement("posao");
        posaoNode.InnerText = posaoComboBox.SelectedItem.ToString();
        zadatakNode.AppendChild(posaoNode);


        //Create a FileStream obj so we can save the XML file.
        FileStream strmSaveToFile;

        strmSaveToFile = new FileStream(xmlDataFile, FileMode.OpenOrCreate, FileAccess.Write);

        //Instantiating a Datawriter obj so we can write the XML file to disk.
        StreamWriter wrDatawriter = new StreamWriter(strmSaveToFile);

        wrDatawriter.Write(xmlDoc.InnerXml);
        wrDatawriter.Close();

        MessageBox.Show("Spremljeno!");

        rasporedListBox.DataBindings.Clear(); //Clearing Bindings
        posaoValueDisplayLabel.DataBindings.Clear(); //Clearing Bindings
        nazivRasporedTextBox.DataBindings.Clear(); //Clearing Bindings

        // Clear the data entered
        nazivTextBox.Text = "";
        posaoComboBox.SelectedIndex = 0;
        vrijemeComboBox.SelectedIndex = 0;

        //Refreshing the form with the newly added appointment.
        GetDataFromXML();
        SetControls();
      }
      catch (Exception ex)
      {
        MessageBox.Show("Pogreška spremanja u XML datoteku!\n" + ex.Message);
      }
    }

    private void CreateDatabase()
    {
      // See if there is not a SLQ CE database
      if (!File.Exists(sqlDataFile))
      {
        // We need to create the SQL CE database
        SqlCeEngine newSqlDB = new SqlCeEngine(sqlCEConnectionString);
        newSqlDB.CreateDatabase();
        newSqlDB.Dispose();

        // We need to make the table we will use in the database
        SqlCeCommand makeTableCommand = new SqlCeCommand("CREATE TABLE raspored (vrijeme nvarchar(10) NULL, naziv nvarchar(50) NULL, posao nvarchar(25) NULL)", new SqlCeConnection(sqlCEConnectionString));
        makeTableCommand.Connection.Open();
        makeTableCommand.ExecuteNonQuery();
        makeTableCommand.Connection.Close();
        makeTableCommand.Dispose();

      }
    }

    private void SaveToSqlCEButton_Click(object sender, System.EventArgs e)
    {
      this.CreateDatabase();

      if (nazivTextBox.Text != "")
      {
        DataRow newRow = zadatakDataTable.NewRow();
        newRow["vrijeme"] = vrijemeComboBox.Text;
        newRow["naziv"] = nazivTextBox.Text;
        newRow["posao"] = posaoComboBox.Text;
        zadatakDataTable.Rows.Add(newRow);
      }

      SqlCeCommand newDataInsertCommand = new SqlCeCommand
        ("INSERT INTO raspored (vrijeme, naziv, posao) VALUES (?,?,?)",
        new SqlCeConnection(sqlCEConnectionString));

      newDataInsertCommand.Connection.Open();

      newDataInsertCommand.Parameters.Add("vrijeme", SqlDbType.NVarChar, 10);
      newDataInsertCommand.Parameters.Add("naziv", SqlDbType.NVarChar, 50);
      newDataInsertCommand.Parameters.Add("posao", SqlDbType.NVarChar, 25);

      // petlja za sluèaj da smo gomilali podatke u DataSet
      foreach (DataRow dr in zadatakDataTable.Rows)
      {
        if (dr.RowState == DataRowState.Added)
        {
          newDataInsertCommand.Parameters["vrijeme"].Value = dr["vrijeme"];
          newDataInsertCommand.Parameters["naziv"].Value = dr["naziv"];
          newDataInsertCommand.Parameters["posao"].Value = dr["posao"];

          newDataInsertCommand.ExecuteNonQuery();
        }
      }
      newDataInsertCommand.Connection.Close();
      newDataInsertCommand.Dispose();

      // skini zastavicu pohranjenima
      zadatakDataTable.AcceptChanges();
      zadatakDataTable.DefaultView.Sort = "vrijeme";

      // Clear the data entered
      nazivTextBox.Text = "";
      posaoComboBox.SelectedIndex = 0;
      vrijemeComboBox.SelectedIndex = 0;

    }
  }
}
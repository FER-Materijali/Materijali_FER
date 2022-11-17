using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

using System.Data.OleDb;
using System.IO;

namespace UnosArtikala
{
  public partial class Artikl : Form
  {
    public Artikl()
    {
      InitializeComponent();
    }

    private void Form1_Load(object sender, EventArgs e)
    {
      // da izbjegnemo problem veze na Stavka, koje nema u dataSetArtikli
      dataSetArtikli.EnforceConstraints = false;
      oleDbDataAdapter1.Fill(dataSetArtikli);

      listBoxArtikli.DataSource = dataSetArtikli.Artikl;
      listBoxArtikli.DisplayMember = "NazArtikla";

      BindData();
      UpdateDisplay();
    }

    private void listBoxArtikli_SelectedIndexChanged(object sender, EventArgs e)
    {
      if (artiklBindingSource != null)
      {
        artiklBindingSource.Position = listBoxArtikli.SelectedIndex;
        //UpdateDisplay();
      }
    }

    void BindData()
    {
      textBoxSifArtikla.DataBindings.Add("Text", artiklBindingSource, "SifArtikla");
      textBoxNazArtikla.DataBindings.Add("Text", artiklBindingSource, "NazArtikla");
      textBoxJedMjere.DataBindings.Add("Text", artiklBindingSource, "JedMjere");
      textBoxCijArtikla.DataBindings.Add("Text", artiklBindingSource, "CijArtikla");
      checkBoxUsluga.DataBindings.Add("Checked", artiklBindingSource, "ZastUsluga");
      
      //slika se ne može povezati na jednak nacin
      //pictureBoxArtikl.DataBindings.Add(new System.Windows.Forms.Binding("Image", this.artiklBindingSource, "SlikaArtikla", true));
      //stoga se osvježava metodom ShowPicture() pozvanom iz artiklPositionChanged

      artiklBindingSource.PositionChanged += new EventHandler(artiklPositionChanged);
    }

    private void ShowPicture()
    {
      pictureBoxArtikl.Image = null;
      if (((System.Data.DataRowView)artiklBindingSource.Current).Row["SlikaArtikla"] != DBNull.Value)
      {
        ImageConverter imageConverter = new ImageConverter();
        //pictureBoxArtikl.Image = (Image)imageConverter.ConvertFrom((byte[])row["SlikaArtikla"]);
        byte[] image = (byte[])((System.Data.DataRowView)artiklBindingSource.Current).Row["SlikaArtikla"];
        if (image != null)
        {
          pictureBoxArtikl.Image = (Image)imageConverter.ConvertFrom(image);
        };
      }
      #region deadOffice
      #if deadCode
          // verzija s offsetom koja radi za MS Access northwind primjer s bitmap image
          const int MSACCESSIMAGEOFFSET = 78;

          // get the new CategoryID using the BindingManager
          int sifArtikla = (int)dataSetArtikli.Tables["Artikl"].Rows[bmb.Position]["SifArtikla"];

          // create a connection
          //OleDbConnection conn = new OleDbConnection("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=c:\\projects\\Firma.mdb;");
          OleDbConnection conn = this.oleDbConnection1;
          // create a command to retrieve the  photo
          String sqlText = "SELECT SlikaArtikla FROM Artikl WHERE SifArtikla=" + sifArtikla;
          OleDbCommand cmd = new OleDbCommand(sqlText, conn);
     
          // retrieve the image from the database
          conn.Open();
          Byte[] image = null;
          try
          {
            image = (Byte[])cmd.ExecuteScalar();
          }
          catch { }
          conn.Close();

          if (image != null)
          {
            // write to a stream removing the image header
            MemoryStream ms = new MemoryStream();
            ms.Write(image, MSACCESSIMAGEOFFSET, image.Length - MSACCESSIMAGEOFFSET);
            // sqlClient - Load the image into the PictureBox from the stream.
            // photoPictureBox.Image = Image.FromStream(ms);
            // load the image into the PictureBox from the stream
            try
            {
              pictureBoxArtikl.Image = Image.FromStream(ms);
            }
            catch (Exception ex)
            {
              MessageBox.Show("Pogreška: " + ex.ToString());
            }
            ms.Close();
          }
      #endif
      #endregion
    }

    private void artiklPositionChanged(Object sender, EventArgs e)
    {
      if (artiklBindingSource.Count == 0) return;
      
      UpdateDisplay();
    }

    #region Navigacija

    private void buttonNext_Click(object sender, EventArgs e)
    {
      artiklBindingSource.MoveNext();
    }

    private void buttonPrevious_Click(object sender, EventArgs e)
    {
      artiklBindingSource.MovePrevious();
    }

    private void buttonLast_Click(object sender, EventArgs e)
    {
      artiklBindingSource.MoveLast();
    }

    private void buttonFirst_Click(object sender, EventArgs e)
    {
      artiklBindingSource.MoveFirst();
    }

    #endregion


    void UpdateDisplay()
    {
      if (artiklBindingSource == null || artiklBindingSource.Count == 0) return;
      if (listBoxArtikli.Items.Count == 0 || artiklBindingSource.Position >= listBoxArtikli.Items.Count) return;
      
      labelPosition.Text = ((artiklBindingSource.Position + 1).ToString()
                       + " od  "
                       + artiklBindingSource.Count.ToString());
      labelRowState.Text = GetCurrentRow().RowState.ToString();

      listBoxArtikli.SelectedIndex = artiklBindingSource.Position;

      ShowPicture();
    }

    private void buttonAdd_Click(object sender, EventArgs e)
    {
      artiklBindingSource.EndEdit();

      // kreiranje novog retka
      DataRow newRow = dataSetArtikli.Artikl.NewRow();

      // defaults
      newRow["SifArtikla"] = DBNull.Value;
      newRow["NazArtikla"] = DBNull.Value;
      newRow["JedMjere"] = DBNull.Value;
      newRow["CijArtikla"] = 0;
      newRow["ZastUsluga"] = false;
      newRow["SlikaArtikla"] = DBNull.Value;

      // dodavanje novog retka u DataTable
      dataSetArtikli.Artikl.Rows.Add(newRow);

      //UpdateDisplay();
      artiklBindingSource.Position = artiklBindingSource.Count - 1; 

    }

    private System.Data.DataRow GetCurrentRow()
    {
      if (artiklBindingSource.Count == 0) return null;

      return ((DataRowView)artiklBindingSource.Current).Row;

      ////loše: bmb.Position može biti -1
      //return (bmb.Position > -1 
      //  ? dataSetArtikli.Artikl.Rows[bmb.Position]
      //  : null
      //;
    }

    private void buttonUpdate_Click(object sender, EventArgs e)
    {
      // završava prethodno zapoèeto ureðivanje podataka
      artiklBindingSource.EndEdit(); 

      try
      {
        //DataRow zapis = GetCurrentRow();
        //if (zapis.RowState == DataRowState.Added
        //  || zapis.RowState == DataRowState.Modified)

        // postoji i kompliciranija varijanta s .GetChanges());
        if (dataSetArtikli.HasChanges())
        {
          if (!dataSetArtikli.HasErrors)
          {
            oleDbDataAdapter1.Update(dataSetArtikli.Artikl);
            // prikaz promijenjenog stanja retka
            UpdateDisplay();
            MessageBox.Show("Podaci pohranjeni u bazu podataka!");
          }
          else 
          {
            MessageBox.Show("Podaci sadrže pogreške!");
          }
        }
        else 
        {
          MessageBox.Show("Nema promjena za pohraniti!");
        }
      }
      catch (Exception ex)
      {
        MessageBox.Show("Pogreška:\n " + ex.ToString());
      }
    }

    private void buttonDelete_Click(object sender, EventArgs e)
    {
      try
      {
        // trenutni
        DataRow row = GetCurrentRow();
        // obriši
        row.Delete();
      }
      catch (Exception ex)
      {
        MessageBox.Show(ex.Message);
      }
      finally
      {
        UpdateDisplay();
      }
    }


    private void pictureBoxArtikl_Click(object sender, EventArgs e)
    {
      // Odabir datoteke sa slikom
      OpenFileDialog ofd = new OpenFileDialog();
      //ofd.InitialDirectory = System.IO.Path.GetTempPath();
      ofd.Filter = "Bitmap Files (*.bmp)|*.bmp|JPEG files (*.jpg)|*.jpg|" +
          "All files (*.*)|*.*";
      ofd.FilterIndex = 2;

      if (ofd.ShowDialog() == DialogResult.OK)
      {
        // Èitanje slike 
        FileStream fs = new FileStream(ofd.FileName, FileMode.Open, FileAccess.Read);
        Byte[] image = new Byte[fs.Length];
        fs.Read(image, 0, image.Length);
        try
        {
          // postavljanje svojstva Image PictureBox kontrole
          pictureBoxArtikl.Image = Image.FromStream(fs);

          ImageConverter imageConverter = new ImageConverter();

          System.Data.DataRowView drv;
          drv = (System.Data.DataRowView)artiklBindingSource.Current; 
          drv.Row.BeginEdit();

          //Spremanje slike

          //ImageConverter imageConverter = new ImageConverter();
          byte[] bytePhoto = null;
          bytePhoto = (byte[])imageConverter.ConvertTo(pictureBoxArtikl.Image, Type.GetType("System.Byte[]"));
          drv.Row["SlikaArtikla"] = bytePhoto;

          //this.Validate();
          artiklBindingSource.EndEdit();
          //dataSetArtikli.AcceptChanges();
          oleDbDataAdapter1.Update(dataSetArtikli.Artikl);
        }
        catch (Exception ex)
        {
          MessageBox.Show(ex.Message);
          image = null;
        }
        fs.Close();
      }
    }

    private void buttonCancel_Click(object sender, EventArgs e)
    {
      artiklBindingSource.EndEdit();  
      dataSetArtikli.RejectChanges();
      UpdateDisplay();

      //kod Cancel ostaje treperiti errorProvider ako je prije toga postojala pogreska
      this.errorProviderArtikl.Clear();
    }

    private void buttonFill_Click(object sender, EventArgs e)
    {
      this.dataSetArtikli.Artikl.Clear();
      this.oleDbDataAdapter1.Fill(dataSetArtikli.Artikl);
      //UpdateDisplay() bude pozvan zbog artiklBindingSource PositionChanged
    }

    private void buttonEdit_Click(object sender, EventArgs e)
    {
      System.Data.DataRow currRow;
      currRow = GetCurrentRow();
#if true 
      currRow["NazArtikla"] = "@#$!";
      // currRow[1] = "@#$!"; // manje jasna alternativa

      currRow["SifArtikla"] = "-1"; // izazove validaciju
#else // Privremeno obustavljanje validacije podataka  
      currRow.BeginEdit();
      currRow["SifArtikla"] = "-1";
      MessageBox.Show(currRow["SifArtikla",
        System.Data.DataRowVersion.Proposed].ToString());
      currRow.CancelEdit();
#endif
      UpdateDisplay();
    }

    private void buttonCommand_Click(object sender, EventArgs e)
    {
      try
      {
        System.Data.OleDb.OleDbCommand cmdUpdate;
        System.Data.DataRow currRow;

        currRow = GetCurrentRow();
        cmdUpdate = new OleDbCommand("UPDATE Artikl "
                  + " SET NazArtikla = '" + currRow["NazArtikla"]
                  + " " + DateTime.Now.ToString()
                  + "' WHERE SifArtikla=" + currRow["SifArtikla"]
                  , oleDbConnection1);

        this.oleDbConnection1.Open();
        cmdUpdate.ExecuteNonQuery();
        this.oleDbConnection1.Close();
      }
      catch (Exception ex)
      {
        MessageBox.Show("Pogreška:" + ex.Message);
      }
      finally
      {
        this.dataSetArtikli.AcceptChanges();
        UpdateDisplay();
        MessageBox.Show("Promjene ažurirane u bazi podataka!");
      }

    }

    private void buttonSave_Click(object sender, EventArgs e)
    {
      DataRow row = ((DataRowView)artiklBindingSource.Current).Row;

      if (!row.HasErrors)
      { 
        row.EndEdit();
        UpdateDisplay();
        MessageBox.Show("Podaci pohranjeni u skup podataka!");
      }
      else
      {
        row.CancelEdit();
        MessageBox.Show("Podaci su neispravni!");
      }
    }
  }
}
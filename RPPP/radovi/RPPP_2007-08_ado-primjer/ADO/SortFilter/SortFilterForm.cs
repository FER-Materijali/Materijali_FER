using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace SortFilter
{
  public partial class SortFilterForm : Form
  {
    DataView dvMjesta;
    private DataRow[] drFound;

    public SortFilterForm()
    {
      InitializeComponent();
      oleDbDataAdapterMjesta.Fill(dataSetMjesta);
    }

    private void buttonFilter_Click(object sender, EventArgs e)
    {
      try
      {
        dvMjesta.RowFilter = textBoxFilter.Text;

        dataGridView.DataSource = dvMjesta;
      }
      catch (Exception ex)
      {
        MessageBox.Show(ex.Message);
      }
    }


    private void buttonSort_Click(object sender, EventArgs e)
    {
      dvMjesta.Sort = textBoxSort.Text;

      dataGridView.DataSource = dvMjesta;
    }

    private void SortFilterForm_Load(object sender, EventArgs e)
    {
      dvMjesta = dataSetMjesta.MjestoDrzava.DefaultView;

      foreach (DataColumn col in dvMjesta.Table.Columns)
      {
        comboBoxColumns.Items.Add(col.ColumnName);
      }
    }

    private void buttonAddFilter_Click(object sender, EventArgs e)
    {
      StringBuilder sbFilter = new StringBuilder(textBoxFilter.Text);
      string polje = comboBoxColumns.Text;
      string uvjet = textBoxUvjet.Text;

      if (polje.Length > 0 && uvjet.Length > 0)
      {
        if (sbFilter.Length != 0)
        {
          sbFilter.Append(" AND ");
        }
        if (dvMjesta.Table.Columns[polje].DataType.Name == "String")
        {
          sbFilter.Append(polje + " LIKE '%" + uvjet + "%'");
        }
        else
        {
          sbFilter.Append(polje + " = " + uvjet);
        }
      }
      textBoxFilter.Text = sbFilter.ToString();
    }

    private void radioSort_CheckedChanged(object sender, EventArgs e)
    {
      RadioButton rButton = (RadioButton)sender;

      if (rButton.Checked)
      {
        if (textBoxSort.Text.Length > 0) textBoxSort.Text += ", ";
        textBoxSort.Text += rButton.Text;
        if (radioButtonSilazno.Checked) textBoxSort.Text += " DESC";
      }
    }

    private void buttonFind_Click(object sender, EventArgs e)
    {
      int idxFound;
      string strMessage;

      try
      {
        dvMjesta.Sort = comboBoxColumns.Text;
        textBoxSort.Text = dvMjesta.Sort;

        idxFound = dvMjesta.Find(textBoxUvjet.Text);
        strMessage = "Found: " + idxFound;
        if (idxFound >= 0)
        {
          strMessage += "\nIdMjesta: " +
            this.dvMjesta[idxFound]["IdMjesta"];
          strMessage += "\nNazMjesta: " +
            this.dvMjesta[idxFound]["NazMjesta"];
          strMessage += "\nOznDrzave: " +
            this.dvMjesta[idxFound]["OznDrzave"];
          MessageBox.Show(strMessage);
        }      
      }
      catch (Exception ex)
      {
        MessageBox.Show(ex.Message);
      }
    }

    private void buttonSelect_Click(object sender, EventArgs e)
    {
      try
      {
        drFound = this.dataSetMjesta.MjestoDrzava.Select(textBoxFilter.Text);

        dataGridView.DataSource = drFound;

        //foreach (System.Data.DataRow dr in drFound)
        //{
        //  lbClients.Items.Add(dr["NazMjesta"]);
        //}	        
      }
      catch (Exception ex)
      {
        ;//MessageBox.Show(ex.Message);
      }
    }
  }
}
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Data.OleDb;

namespace Transakcije
{
  public partial class TransakcijeForm : Form
  {
    System.Data.OleDb.OleDbTransaction trnNew;

    public TransakcijeForm()
    {
      InitializeComponent();
    }

    private void buttonBegin_Click(object sender, EventArgs e)
    {
      try
      {
        this.oleDbConnection.Open();
        trnNew = oleDbConnection.BeginTransaction();
        MessageBox.Show("Isolation Level: "
          + trnNew.IsolationLevel.ToString());
      }
      catch (Exception ex)
      {
        MessageBox.Show(ex.Message);
      }
    }

    private void buttonCommit_Click(object sender, EventArgs e)
    {
      try
      {
        trnNew.Commit();
        MessageBox.Show("Committed");
      }
      catch (Exception ex)
      {
        MessageBox.Show(ex.Message);
        //trnNew.Rollback();
      }
      finally
      {
        this.oleDbConnection.Close();
      }
    }

    private void buttonRollback_Click(object sender, EventArgs e)
    {
      try
      {
        trnNew.Rollback();
        MessageBox.Show("Rolled back");
      }
      catch (Exception ex)
      {
        MessageBox.Show(ex.Message);
      }
      finally
      {
        this.oleDbConnection.Close();
      }

    }

    private void TransakcijeForm_Load(object sender, EventArgs e)
    {

    }

    private void labelID_Click(object sender, EventArgs e)
    {

    }

    private void buttonExecute_Click(object sender, EventArgs e)
    {
      try
      {
        OleDbCommand oleCommand = new OleDbCommand(textSQL.Text, oleDbConnection);
        oleCommand.Transaction = trnNew;
        int result = oleCommand.ExecuteNonQuery();
      }
      catch (Exception ex)
      {
        MessageBox.Show(ex.Message);
      }
    }
  }
}
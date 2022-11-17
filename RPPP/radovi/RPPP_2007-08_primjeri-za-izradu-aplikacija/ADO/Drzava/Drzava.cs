using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Drzava
{
  public partial class DrzavaForm : Form
  {
    public DrzavaForm()
    {
      InitializeComponent();
    }

    private void drzavaBindingNavigatorSaveItem_Click(object sender, EventArgs e)
    {
      this.Validate();
      this.drzavaBindingSource.EndEdit();
      this.drzavaTableAdapter.Update(this.firmaDataSet.Drzava);
    }

    private void DrzavaForm_Load(object sender, EventArgs e)
    {
      this.drzavaTableAdapter.Fill(this.firmaDataSet.Drzava);
    }

    private void toolStripButtonLoad_Click(object sender, EventArgs e)
    {
      this.drzavaTableAdapter.Fill(this.firmaDataSet.Drzava);
    }

    private void toolStripButtonCancel_Click(object sender, EventArgs e)
    {
      firmaDataSet.RejectChanges();
    }

  }
}
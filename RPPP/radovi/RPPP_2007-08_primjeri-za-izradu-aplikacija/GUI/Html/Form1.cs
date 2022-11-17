using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Diagnostics;

namespace Html
{
  public partial class Form1 : Form
  {
    public Form1()
    {
      InitializeComponent();

      this.lbDragDropSource.Items.Add("<html>");
      this.lbDragDropSource.Items.Add("<head>");
      this.lbDragDropSource.Items.Add("<title>");
      this.lbDragDropSource.Items.Add("</title>");
      this.lbDragDropSource.Items.Add("</head>");
      this.lbDragDropSource.Items.Add("<body>");
      this.lbDragDropSource.Items.Add("</body>");
      this.lbDragDropSource.Items.Add("</html>");
    }

    private void lbDragDropSource_MouseDown(object sender, System.Windows.Forms.MouseEventArgs e)
    {
      Debug.WriteLine("source_MouseDown");

      int nSelectedIndex = lbDragDropSource.SelectedIndex;
      string strItem = (string)lbDragDropSource.Items[nSelectedIndex];

      DragDropEffects dde = lbDragDropSource.DoDragDrop(strItem,
        DragDropEffects.Copy);

      if (DragDropEffects.None == dde)
        MessageBox.Show("Our drag and drop offer was not accepted.");
    }

    private void txtMain_DragOver(object sender, System.Windows.Forms.DragEventArgs e)
    {
      Debug.WriteLine("target_DragOver");
      if (e.Data.GetDataPresent(typeof(string)))
      {
        e.Effect = DragDropEffects.Copy;
      }
    }

    private void txtMain_DragDrop(object sender, System.Windows.Forms.DragEventArgs e)
    {
      Debug.WriteLine("target_DragDrop");

      if (e.Data.GetDataPresent(typeof(string)))
      {
        string strData = (string)e.Data.GetData(typeof(string));
        // really simple - usually at cursor position
        txtMain.AppendText(strData);
      }
    }

    private void lbDragDropSource_QueryContinueDrag(object sender, System.Windows.Forms.QueryContinueDragEventArgs e)
    {
      // DO NOT DO THIS
      // e.Action = DragAction.Continue;
    }

    private void DragEnter(object sender, System.Windows.Forms.DragEventArgs e)
    {
      Debug.WriteLine("DragEnter");
    }

    private void DragLeave(object sender, System.EventArgs e)
    {
      Debug.WriteLine("DragLeave");
    }
  }
}
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Vjesala
{
  public partial class Form1 : Form
  {
    public Form1()
    {
      InitializeComponent();
    }

    private void butShow_Click(object sender, System.EventArgs e)
    {
      if (butShow.ImageList == null) butShow.ImageList = imageList1;

      if (butShow.ImageIndex == -1)
      {
        butShow.ImageIndex = 0;
      }
      else
      {
        butShow.ImageIndex = (butShow.ImageIndex + 1) % butShow.ImageList.Images.Count;
      }

      pictureBox1.Image = imageList1.Images[butShow.ImageIndex];
    }

    private void butAdd_Click(object sender, System.EventArgs e)
    {
      OpenFileDialog openFileDialog1 = new OpenFileDialog();
      if (openFileDialog1.ShowDialog() == DialogResult.OK)
        imageList1.Images.Add(Image.FromFile(openFileDialog1.FileName));
      openFileDialog1.Dispose();
    }


  }
}
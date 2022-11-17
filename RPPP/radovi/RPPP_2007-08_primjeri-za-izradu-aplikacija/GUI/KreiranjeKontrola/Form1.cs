using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace KreiranjeKontrola
{
  public partial class Form1 : Form
  {
    public Form1()
    {
      InitializeComponent();
    }

    private void Form1_Click(object sender, EventArgs e)
    {
      Button b = new Button();
      b.Text = "Gumb " + this.Controls.Count;
      Point mousePoint = PointToClient(MousePosition);
      b.Location = new Point(mousePoint.X, mousePoint.Y);

      b.Click += new System.EventHandler(this.ButtonClick);
      this.Controls.Add(b);
    }

    private void ButtonClick(object sender, System.EventArgs e)
    {
      MessageBox.Show(sender.ToString());
    }

  }
}
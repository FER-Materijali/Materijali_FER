using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Firma
{
  public partial class LogInForm : Form
  {
    private SecurityBllProvider sec = new SecurityBllProvider();

    public LogInForm()
    {
      InitializeComponent();
    }

    private void buttonOk_Click(object sender, EventArgs e)
    {
      if (sec.IsAuthenticated(textBoxKorisnik.Text, textBoxZaporka.Text))
      {
        DialogResult = DialogResult.OK;
        Close();
      }
      else
      {
        MessageBox.Show("Krivo korisnièko ime ili zaporka.", "Neuspjela autorizacija", 
          MessageBoxButtons.OK, MessageBoxIcon.Error);
      }
    }

    private void buttonCancel_Click(object sender, EventArgs e)
    {
      //DialogResult = DialogResult.Cancel;
      //Close();
    }

    public string Username
    {
      get { return textBoxKorisnik.Text; }
    }
  }
}
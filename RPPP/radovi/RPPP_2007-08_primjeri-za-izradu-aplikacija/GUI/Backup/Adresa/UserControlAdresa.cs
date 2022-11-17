using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;

namespace Adresa
{
  public partial class UserControlAdresa : UserControl
  {
    public UserControlAdresa()
    {
      InitializeComponent();
    }

    public int DrzavaSelectedIndex
    {
      get { return comboBoxDrzava.SelectedIndex; }
      set { comboBoxDrzava.SelectedIndex = value; }
    }

    public int MjestoSelectedIndex
    {
      get { return comboBoxMjesto.SelectedIndex; }
      set { comboBoxMjesto.SelectedIndex = value; }
    }

    public string DrzavaSelectedText
    {
      get { return comboBoxDrzava.SelectedText; }
      set { comboBoxDrzava.SelectedText = value; }
    }

    public string MjestoSelectedText
    {
      get { return comboBoxMjesto.SelectedText; }
      set { comboBoxMjesto.SelectedText = value; }
    }

    public object DrzavaDataSource
    {
      get { return comboBoxDrzava.DataSource; }
      set { comboBoxDrzava.DataSource = value; }
    }

    public object MjestoDataSource
    {
      get { return comboBoxMjesto.DataSource; }
      set { comboBoxMjesto.DataSource = value; }
    }

    public BindingContext DrzavaBindingContext
    {
      get { return comboBoxDrzava.BindingContext; }
      set { comboBoxDrzava.BindingContext = value; }
    }

    public BindingContext MjestoBindingContext
    {
      get { return comboBoxMjesto.BindingContext; }
      set { comboBoxMjesto.BindingContext = value; }
    }

    public string Adresa
    {
      get { return textBoxAdresa.Text; }
      set { textBoxAdresa.Text = value; }
    }

    public string GroupBoxText
    {
      get { return groupBox1.Text; }
      set { groupBox1.Text = value; }
    }

    public delegate void ComboBoxIndexChangedHandler();

    public event ComboBoxIndexChangedHandler MjestoIndexChanged;
    public event ComboBoxIndexChangedHandler DrzavaIndexChanged;


    protected virtual void OnDrzavaIndexChanged()
    {
      if (DrzavaIndexChanged != null)
      {
        DrzavaIndexChanged();
      }
    }

    protected virtual void OnMjestoIndexChanged()
    {
      if (MjestoIndexChanged != null)
      {
        MjestoIndexChanged();
      }
    }

    private void comboBoxDrzava_SelectedIndexChanged(object sender, EventArgs e)
    {
      OnDrzavaIndexChanged();
    }

    private void comboBoxMjesto_SelectedIndexChanged(object sender, EventArgs e)
    {
      OnMjestoIndexChanged();
    }


  }
}
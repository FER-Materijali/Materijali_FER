using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;

namespace Import
{
  public partial class UserControlMapiranje : UserControl
  {
    public UserControlMapiranje()
    {
      InitializeComponent();

    }

    public object DataSource
    {
      get { return comboBoxMapiranje.DataSource; }
      set { comboBoxMapiranje.DataSource = value; }
    }

    public string NazivStupcaText
    {
      get { return textBoxNazivStupcaTablice.Text; }
      set { textBoxNazivStupcaTablice.Text = value; }
    }

    public string OstaloText
    {
      get { return textBoxOstalo.Text; }
      set { textBoxOstalo.Text = value; }
    }

    public bool OstaloChecked
    {
      get { return checkBoxOstalo.Checked; }
      set { checkBoxOstalo.Checked = value; }
    }

    public string ComboText
    {
      get { return comboBoxMapiranje.Text; }
      set { comboBoxMapiranje.Text = value; }
    }

    public BindingContext ComboBindingContext
    {
      get { return comboBoxMapiranje.BindingContext; }
      set { comboBoxMapiranje.BindingContext = value; }
    }

    public void Onemoguci()
    {
      comboBoxMapiranje.Enabled = false; 
      checkBoxOstalo.Enabled = false; 
      textBoxOstalo.Enabled = false;
      textBoxNazivStupcaTablice.Enabled = false;
    }

    public void UrediPrikaz()
    {
      if (checkBoxOstalo.Checked)
      {
        textBoxOstalo.Enabled = true;
        comboBoxMapiranje.Enabled = false;
      }
      else 
      {
        textBoxOstalo.Enabled = false;
        comboBoxMapiranje.Enabled = true;
      }
    }

    public delegate void CheckBoxChangedHandler(UserControlMapiranje sender);
    public event CheckBoxChangedHandler CheckBoxOstaloChanged;


    protected virtual void OnCheckBoxOstaloChanged()
    {
      if (CheckBoxOstaloChanged != null)
      {
        CheckBoxOstaloChanged(this);
      }
    }

    private void checkBoxOstalo_CheckedChanged(object sender, EventArgs e)
    {
      OnCheckBoxOstaloChanged();
    }


  }
}

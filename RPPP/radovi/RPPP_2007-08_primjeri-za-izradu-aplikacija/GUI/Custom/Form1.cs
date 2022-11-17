using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Custom
{
  public partial class Form1 : Form
  {

    string[] listaDrzava = new string[4];
    string[][] listaGradova = new string[4][];

    public Form1()
    {
      InitializeComponent();
      
      listaDrzava[0] = "Hrvatska";
      listaDrzava[1] = "Njemaèka";
      listaDrzava[2] = "Italija";

      listaGradova[0] = new string[] { "Split", "Zagreb", "Dubrovnik" };
      listaGradova[1] = new string[] { "Koeln", "Berlin", "Frankfurt", "Muenchen" };
      listaGradova[2] = new string[] { "Rim", "Milano", "Napulj" };


      userControlAdresaSjedista.DrzavaBindingContext = new BindingContext();
      userControlAdresaIsporuke.DrzavaBindingContext = new BindingContext();
      userControlAdresaSjedista.MjestoBindingContext = new BindingContext();
      userControlAdresaIsporuke.MjestoBindingContext = new BindingContext();

      userControlAdresaSjedista.DrzavaDataSource = listaDrzava;
      userControlAdresaSjedista.DrzavaSelectedIndex = 0;
      userControlAdresaSjedista.MjestoDataSource = listaGradova[userControlAdresaSjedista.DrzavaSelectedIndex];


      userControlAdresaIsporuke.DrzavaDataSource = listaDrzava;
      userControlAdresaIsporuke.DrzavaSelectedIndex = 0;
      userControlAdresaIsporuke.MjestoDataSource = listaGradova[userControlAdresaIsporuke.DrzavaSelectedIndex];

    }


    private void userControlAdresaSjedista_DrzavaIndexChanged()
    {    
      userControlAdresaSjedista.MjestoDataSource = listaGradova[userControlAdresaSjedista.DrzavaSelectedIndex];
    }

    private void userControlAdresaIsporuke_DrzavaIndexChanged()
    {
      userControlAdresaIsporuke.MjestoDataSource = listaGradova[userControlAdresaIsporuke.DrzavaSelectedIndex];
    }

    private void button1_Click(object sender, EventArgs e)
    {
      MessageBox.Show("Spremljeno!");
    }

  }
}
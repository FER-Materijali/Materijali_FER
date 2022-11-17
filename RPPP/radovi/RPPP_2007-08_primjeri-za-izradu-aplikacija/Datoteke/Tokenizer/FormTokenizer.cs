using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace Tokenizer
{
  public partial class FormTokenizer : Form
  {

    public FormTokenizer()
    {
      InitializeComponent();
    }

    private void buttonBrowse_Click(object sender, EventArgs e)
    {
      if (openFileDialog.ShowDialog() == DialogResult.OK)
      {
        textBoxDatoteka.Text = openFileDialog.FileName;
      }
    }

    private void buttonPrikazi_Click(object sender, EventArgs e)
    {
      try
      {
        string nazivDatoteke = textBoxDatoteka.Text;
        char delimiter = textBoxDelimiter.Text.ToCharArray()[0];
        PrikaziPodatke(nazivDatoteke, delimiter);
      }
      catch (Exception ex)
      {
        MessageBox.Show("Došlo je do pogreške kod prikazivanja podataka: " + ex.Message);
      }

    }

    private void PrikaziPodatke(string nazivDatoteke, char delimiter)
    {
      try
      {
        StreamReader reader = new StreamReader(nazivDatoteke);

        string redak = reader.ReadLine();
        string[] lista = redak.Split(new char[] { delimiter });

        listViewPodaci.Clear();

        // postavljamo nazive stupaca (prvi redak datoteke)        
        for (int i = 0; i < lista.Length; i++)
        {
          listViewPodaci.Columns.Add(lista[i]);
        }

        // podaci (vrijednosti)
        while ((redak = reader.ReadLine()) != null)
        {
          lista = redak.Split(new char[] { delimiter });

          ListViewItem item = new ListViewItem(lista[0]);
          for (int i = 1; i < lista.Length; i++)
          {
            item.SubItems.Add(lista[i]);
          }
          listViewPodaci.Items.Add(item);
        }
        reader.Close();
      }
      catch (Exception ex)
      {
        MessageBox.Show("Došlo je do pogreške kod èitanja iz datoteke: " + ex.Message);
      }
    }

    private void SpremiPodatke(string nazivDatoteke, char delimiter)
    {
      try
      {
        StreamWriter writer = new StreamWriter(nazivDatoteke);

        for (int i = 0; i < listViewPodaci.Items.Count; i++)
        {
          string redak = listViewPodaci.Items[i].Text;
          for (int j = 0; j < listViewPodaci.Items[i].SubItems.Count; j++)
            redak += delimiter + listViewPodaci.Items[i].SubItems[j].Text;
          writer.WriteLine(redak);
        }
        writer.Close();
        MessageBox.Show("Podaci su uspješno pohranjeni u datoteku.");
      }
      catch (Exception ex)
      {
        MessageBox.Show("Došlo je do pogreške kod spremanja u datoteku: " + ex.Message);
      }
    }


    private void buttonBrowseNew_Click(object sender, EventArgs e)
    {
      if (saveFileDialog.ShowDialog() == DialogResult.OK)
      {
        textBoxDatotekaSpremi.Text = saveFileDialog.FileName;
      }
    }

    private void buttonSpremi_Click(object sender, EventArgs e)
    {
      try
      {
        string nazivDatoteke = textBoxDatotekaSpremi.Text;
        char delimiter = textBoxDelimiterSpremi.Text.ToCharArray()[0];
        SpremiPodatke(nazivDatoteke, delimiter);
      }
      catch (Exception ex)
      {
        MessageBox.Show("Došlo je do pogreške kod prikazivanja podataka: " + ex.Message);
      }
    }

  }
}
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Partner
{
  public partial class Form1 : Form
  {

    string[] listaDrzava = new string[4];
    string[][] listaGradova = new string[4][];

    System.ComponentModel.ComponentResourceManager resources;

    Font defaultFont;
    Color defaultColor;

    public Form1()
    {
      InitializeComponent();

      listaDrzava[0] = "Hrvatska";
      listaDrzava[1] = "Njemaèka";
      listaDrzava[2] = "Italija";

      listaGradova[0] = new string[] { "Split", "Zagreb", "Dubrovnik" };
      listaGradova[1] = new string[] { "Koeln", "Berlin", "Frankfurt", "Muenchen" };
      listaGradova[2] = new string[] { "Rim", "Milano", "Napulj" };

      comboBoxDrzava.DataSource = listaDrzava;
      comboBoxDrzava.SelectedIndex = 0;
      comboBoxMjesto.DataSource = listaGradova[comboBoxDrzava.SelectedIndex];


      resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
      pictureBoxSlika.Image = ((System.Drawing.Image)(resources.GetObject("nepoznato")));

      defaultFont = this.Font;
      defaultColor = this.BackColor;
    }



    #region Izbornik

    private void izaberiFontToolStripMenuItem_Click(object sender, EventArgs e)
    {
      if (fontDialog.ShowDialog() != DialogResult.Cancel)
      {
        this.Font = fontDialog.Font;
      }
    }

    private void defaultToolStripMenuItem_Click(object sender, EventArgs e)
    {
      this.Font = defaultFont;
      this.ForeColor = System.Drawing.SystemColors.ControlText;
    }

    private void izaberiPozadinuToolStripMenuItem_Click(object sender, EventArgs e)
    {
      if (colorDialogPozadina.ShowDialog() != DialogResult.Cancel)
      {
        this.BackColor = colorDialogPozadina.Color;
      }
    }

    private void defaultToolStripMenuItem1_Click(object sender, EventArgs e)
    {
      this.BackColor = defaultColor;
    }

    private void izaberiBojuToolStripMenuItem_Click(object sender, EventArgs e)
    {
      if (colorDialogTekst.ShowDialog() != DialogResult.Cancel)
      {
        this.ForeColor = colorDialogTekst.Color;
      }
    }

    private void printToolStripMenuItem_Click(object sender, EventArgs e)
    {

      if (printDialog.ShowDialog() != DialogResult.Cancel)
      {
        printDocument.PrinterSettings = printDialog.PrinterSettings;
        printDocument.Print();
      }
    }

    private void printDocument1_PrintPage(object sender, System.Drawing.Printing.PrintPageEventArgs e)
    {
      try
      {
        string tekstZaPrintanje = textBoxIme.Text + " " + textBoxPrezime.Text + " (" + textBoxJMBG.Text + ")\n"
          + textBoxAdresa.Text + ", " + comboBoxMjesto.Text + ", " + comboBoxDrzava.Text;

        //može se mijenjati margine, font, poziciju, ...
        e.Graphics.DrawString(tekstZaPrintanje, this.Font, Brushes.Black, new PointF(180, 50));
        e.Graphics.DrawImage(pictureBoxSlika.Image, new Rectangle(new Point(50, 50), new Size(100, 100)));
      }
      catch (Exception ex)
      {
        MessageBox.Show("Došlo je do pogreške: ", ex.Message);
      }
    }

    #endregion

    
    #region GradDrzava
    private void comboBoxDrzava_SelectedIndexChanged(object sender, EventArgs e)
    {
      comboBoxMjesto.DataSource = listaGradova[comboBoxDrzava.SelectedIndex];
    }
    #endregion


    #region IzborSlike
    private void buttonBrowseSlika_Click(object sender, EventArgs e)
    {
      if (openFileDialogSlika.ShowDialog() != DialogResult.Cancel)
      {
        string NazivSlike = openFileDialogSlika.FileName;
        Bitmap b = new Bitmap(NazivSlike);
        pictureBoxSlika.Image = b;
      }

    }
    #endregion


    #region Spremanje i odustajanje
    
    private void buttonSpremi_Click(object sender, EventArgs e)
    {
      if (this.ValidateChildren())
      {
        MessageBox.Show("Spremljeno!");
        OcistiFormu();
      }
    }

    private void buttonOdustani_Click(object sender, EventArgs e)
    {
      this.Close();
    }

    #endregion


    #region Validacija

    private void textBoxIme_Validating(object sender, CancelEventArgs e)
    {
      if (ValidacijaNaziv((TextBox)sender))
      {
        e.Cancel = false;
      }
      else 
      {
        e.Cancel = true;
      }
    }

    private void textBoxPrezime_Validating(object sender, CancelEventArgs e)
    {
      if (ValidacijaNaziv((TextBox)sender))
      {
        e.Cancel = false;
      }
      else
      {
        e.Cancel = true;
      }
    }

    private void textBoxAdresa_Validating(object sender, CancelEventArgs e)
    {
      if (ValidacijaAdresa())
      {
        e.Cancel = false;
      }
      else
      {
        e.Cancel = true;
      }
    }

    private void textBoxJMBG_Validating(object sender, CancelEventArgs e)
    {
      if (ValidacijaJMBG())
      {
        e.Cancel = false;
      }
      else
      {
        e.Cancel = true;
      }
    }

    private bool ValidacijaNaziv(TextBox textBox)
    {
      if (textBox.Text == "")
      {
        errorProvider.SetError(textBox, "Unesite ime/prezime.");
        return false;
      }
      else if (System.Text.RegularExpressions.Regex.IsMatch(textBox.Text, "[0-9]"))
      {
        errorProvider.SetError(textBox, "Ime/prezime treba biti valjanog fomata.");
        return false;
      }
      else
      {
        errorProvider.SetError(textBox, "");
        return true;
      }
    }

    private bool ValidacijaAdresa()
    {
      if (textBoxAdresa.Text == "")
      {
        errorProvider.SetError(textBoxAdresa, "Unesite adresu.");
        return false;
      }
      else
      {
        errorProvider.SetError(textBoxAdresa, "");
        return true;
      }
    }

    private bool ValidacijaJMBG()
    {
      if (textBoxJMBG.Text == "")
      {
        errorProvider.SetError(textBoxJMBG, "Unesite jedinstveni matièni broj.");
        return false;
      }
      if (System.Text.RegularExpressions.Regex.IsMatch(textBoxJMBG.Text, "[^0-9]") || ((textBoxJMBG.Text).Length != 13))
      {
        errorProvider.SetError(textBoxJMBG, "Jedinstveni matièni broj mora biti valjanog formata.");
        return false;
      }
      else
      {
        errorProvider.SetError(textBoxJMBG, "");
        return true;
      }
    }

    private void OcistiFormu()
    {
      try
      {
        textBoxIme.Text = "";
        textBoxPrezime.Text = "";
        textBoxJMBG.Text = "";
        textBoxAdresa.Text = "";
        pictureBoxSlika.Image = ((System.Drawing.Image)(resources.GetObject("nepoznato"))); 
        checkBoxPotvrda.Checked = false;
        comboBoxDrzava.SelectedIndex = 0;
        comboBoxMjesto.SelectedIndex = 0;
        radioButtonFizicka.Checked = true;
      }
      catch (Exception e)
      {
        MessageBox.Show("Došlo je do pogreške: ", e.Message);
      }
    }

    #endregion


  }
}
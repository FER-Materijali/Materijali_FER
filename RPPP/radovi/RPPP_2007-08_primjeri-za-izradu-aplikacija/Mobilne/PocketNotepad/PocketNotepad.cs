using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.IO;
using System.Windows.Forms;
using Microsoft.WindowsCE.Forms;

namespace Mobilne
{
  public partial class PocketNotepad : Form
  {
    public PocketNotepad()
    {
      InitializeComponent();
    }

    private void textBox_GotFocus(object sender, System.EventArgs e)
    {
      inputPanel.Enabled = true;
    }

    private void textBox_LostFocus(object sender, System.EventArgs e)
    {
      inputPanel.Enabled = false;
    }

    private void mnuExit_Click(object sender, System.EventArgs e)
    {
      if (hasChanges == true)
      {
        if (MessageBox.Show("Želite li spremiti promjene?", "Pocket Notepad", MessageBoxButtons.YesNo,
            MessageBoxIcon.Question, MessageBoxDefaultButton.Button1) == DialogResult.Yes)
        {

          if (Save() != DialogResult.OK)
            return;
        }
      }
      this.Close();
    }

    private DialogResult Save()
    {
      string saveName = fileName;
      DialogResult action = DialogResult.OK;

      if (hasChanges == false)
        return action;

      if (fileName == null)
      {
        action = saveFileDialog.ShowDialog();
        if (action == DialogResult.OK)
        {
          saveName = saveFileDialog.FileName;
          fileName = saveName;
        }
        else
        {
          return action;
        }
      }

      TextWriter tw = File.CreateText(saveName);
      tw.Write(textBox.Text);
      tw.Close();
      hasChanges = false;

      return action;
    }

    private void textBox_TextChanged(object sender, System.EventArgs e)
    {
      if (hasChanges == false)
        hasChanges = true;
    }

    private void mnuSave_Click(object sender, System.EventArgs e)
    {
      Save();
    }

    private void mnuSaveAs_Click(object sender, System.EventArgs e)
    {
      if (saveFileDialog.ShowDialog() == DialogResult.OK)
      {
        fileName = saveFileDialog.FileName;
        Save();
      }
    }

    private void mnuNew_Click(object sender, System.EventArgs e)
    {

      if (MessageBox.Show("Želite li spremiti promjene?", "Pocket Notepad", MessageBoxButtons.YesNo,
          MessageBoxIcon.Question, MessageBoxDefaultButton.Button1) == DialogResult.No)
      {
        if (Save() != DialogResult.OK)
          return;
      }

      textBox.Text = "";
      hasChanges = false;
      fileName = null;
    }

    private void mnuOpen_Click(object sender, System.EventArgs e)
    {

      if (MessageBox.Show("Želite li spremiti promjene?", "Pocket Notepad", MessageBoxButtons.YesNo,
            MessageBoxIcon.Question, MessageBoxDefaultButton.Button1) == DialogResult.Yes)
      {
        if (Save() != DialogResult.OK)
          return;
      }

      if (openFileDialog.ShowDialog() == DialogResult.OK)
      {
        TextReader tr = File.OpenText(openFileDialog.FileName);
        textBox.Text = tr.ReadToEnd();
        tr.Close();
        hasChanges = false;
        fileName = openFileDialog.FileName;
      }
    }

    private void mnuCut_Click(object sender, System.EventArgs e)
    {
      clipboard = textBox.SelectedText;
      textBox.Text = textBox.Text.Replace(textBox.SelectedText, "");
    }

    private void mnuCopy_Click(object sender, System.EventArgs e)
    {
      clipboard = textBox.SelectedText;
    }

    private void mnuPaste_Click(object sender, System.EventArgs e)
    {
      textBox.SelectedText = clipboard;
      textBox.ScrollToCaret();
    }

    private void menuItem1_Click(object sender, EventArgs e)
    {

    }

  }
}
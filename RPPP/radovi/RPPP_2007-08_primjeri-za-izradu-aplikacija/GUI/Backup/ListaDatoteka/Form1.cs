using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace ListaDatoteka
{
  public partial class Form1 : Form
  {

    ListViewItem oznaceniItem;

    public Form1()
    {
      InitializeComponent();
      
    }

    private void buttonBrowse_Click(object sender, EventArgs e)
    {
      if (folderBrowserDialog.ShowDialog() == DialogResult.OK)
        textBoxPut.Text = folderBrowserDialog.SelectedPath;
    }

    private void buttonIzlistaj_Click(object sender, EventArgs e)
    {   
      IsprazniFormu();
      PrikaziSveDokumente();
    }

    private void IsprazniFormu()
    {
      listView.Items.Clear();
      treeView.Nodes.Clear();
    }

    private void PrikaziSveDokumente()
    {
      if (tabControlLista.SelectedIndex == 0)
        PrikaziDokumenteListView(textBoxPut.Text);
      else
        PrikaziDokumenteTreeView(textBoxPut.Text, null);
    
    }

    private void PrikaziDokumenteListView(string imeDirektorija)
    {
      DirectoryInfo directoryInfo = new DirectoryInfo(imeDirektorija);
      FileSystemInfo[] listFiles = directoryInfo.GetFileSystemInfos();
     
      foreach (FileSystemInfo fileSystemInfo in listFiles)
      {

        if (fileSystemInfo is FileInfo)
        {
          ListViewItem listItem = new ListViewItem(fileSystemInfo.Name);
          listItem.SubItems.Add(((FileInfo)fileSystemInfo).DirectoryName);
          listItem.SubItems.Add(fileSystemInfo.Extension);
          listView.Items.Add(listItem);
        }
        if (fileSystemInfo is DirectoryInfo)
        {
          PrikaziDokumenteListView(fileSystemInfo.FullName);
        }
      }
    
    }

    private void PrikaziDokumenteTreeView(string imeDirektorija, TreeNode parentNode)
    {
      DirectoryInfo directoryInfo = new DirectoryInfo(imeDirektorija);
      FileSystemInfo[] listFiles = directoryInfo.GetFileSystemInfos();
      
      foreach (FileSystemInfo fileInfo in listFiles)
      {
        TreeNode treeItem = new TreeNode(fileInfo.Name);
        
        if (parentNode != null)
          parentNode.Nodes.Add(treeItem);
        else
          treeView.Nodes.Add(treeItem);

        if (fileInfo is DirectoryInfo)
        {
          PrikaziDokumenteTreeView(fileInfo.FullName, treeItem);
        }
      }

    }

    private void listView1_MouseDown(object sender, MouseEventArgs e)
    {
      if (e.Button == MouseButtons.Right)
      {
        oznaceniItem = listView.GetItemAt(e.X, e.Y);
        contextMenuStrip.Show(this, new Point(e.X, e.Y));
      }
    }

    private void detaljiToolStripMenuItem_Click(object sender, EventArgs e)
    {

      FileInfo datoteka = new FileInfo(oznaceniItem.SubItems[1].Text + "\\" + oznaceniItem.Text);
      string detalji =
        "Puno ime datoteke: " + datoteka.FullName + "\n"
        + "Ime direktorija: " + datoteka.DirectoryName + "\n"
        + "Ekstenzija: " + datoteka.Extension + "\n"
        + "Velièina: " + datoteka.Length + " B\n"
        + "Vrijeme stvaranja: " + datoteka.CreationTime + "\n"
        + "Vrijeme zadnje izmjene: " + datoteka.LastWriteTime + "\n"
        + "Vrijeme zadnjeg pristupanja: " + datoteka.LastAccessTime + "\n";
         
      MessageBox.Show(detalji, "Detalji - FileInfo");
    }


  }
}
namespace ListaDatoteka
{
  partial class Form1
  {
    /// <summary>
    /// Required designer variable.
    /// </summary>
    private System.ComponentModel.IContainer components = null;

    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
    protected override void Dispose(bool disposing)
    {
      if (disposing && (components != null))
      {
        components.Dispose();
      }
      base.Dispose(disposing);
    }

    #region Windows Form Designer generated code

    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    private void InitializeComponent()
    {
      this.components = new System.ComponentModel.Container();
      this.tabControlLista = new System.Windows.Forms.TabControl();
      this.tabPage1 = new System.Windows.Forms.TabPage();
      this.listView = new System.Windows.Forms.ListView();
      this.columnNazivDatoteke = new System.Windows.Forms.ColumnHeader();
      this.columnNazivDirektorija = new System.Windows.Forms.ColumnHeader();
      this.columnEkstenzija = new System.Windows.Forms.ColumnHeader();
      this.contextMenuStrip = new System.Windows.Forms.ContextMenuStrip(this.components);
      this.detaljiToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.tabPage2 = new System.Windows.Forms.TabPage();
      this.treeView = new System.Windows.Forms.TreeView();
      this.groupBox1 = new System.Windows.Forms.GroupBox();
      this.buttonIzlistaj = new System.Windows.Forms.Button();
      this.buttonBrowse = new System.Windows.Forms.Button();
      this.textBoxPut = new System.Windows.Forms.TextBox();
      this.labelPut = new System.Windows.Forms.Label();
      this.folderBrowserDialog = new System.Windows.Forms.FolderBrowserDialog();
      this.tabControlLista.SuspendLayout();
      this.tabPage1.SuspendLayout();
      this.contextMenuStrip.SuspendLayout();
      this.tabPage2.SuspendLayout();
      this.groupBox1.SuspendLayout();
      this.SuspendLayout();
      // 
      // tabControlLista
      // 
      this.tabControlLista.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                  | System.Windows.Forms.AnchorStyles.Left)
                  | System.Windows.Forms.AnchorStyles.Right)));
      this.tabControlLista.Controls.Add(this.tabPage1);
      this.tabControlLista.Controls.Add(this.tabPage2);
      this.tabControlLista.Location = new System.Drawing.Point(12, 106);
      this.tabControlLista.Name = "tabControlLista";
      this.tabControlLista.SelectedIndex = 0;
      this.tabControlLista.Size = new System.Drawing.Size(491, 258);
      this.tabControlLista.TabIndex = 0;
      // 
      // tabPage1
      // 
      this.tabPage1.Controls.Add(this.listView);
      this.tabPage1.Location = new System.Drawing.Point(4, 22);
      this.tabPage1.Name = "tabPage1";
      this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
      this.tabPage1.Size = new System.Drawing.Size(483, 232);
      this.tabPage1.TabIndex = 0;
      this.tabPage1.Text = "ListView";
      this.tabPage1.UseVisualStyleBackColor = true;
      // 
      // listView
      // 
      this.listView.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnNazivDatoteke,
            this.columnNazivDirektorija,
            this.columnEkstenzija});
      this.listView.ContextMenuStrip = this.contextMenuStrip;
      this.listView.Location = new System.Drawing.Point(16, 15);
      this.listView.Name = "listView";
      this.listView.Size = new System.Drawing.Size(452, 194);
      this.listView.TabIndex = 0;
      this.listView.UseCompatibleStateImageBehavior = false;
      this.listView.View = System.Windows.Forms.View.Details;
      this.listView.MouseDown += new System.Windows.Forms.MouseEventHandler(this.listView1_MouseDown);
      // 
      // columnNazivDatoteke
      // 
      this.columnNazivDatoteke.Text = "Naziv datoteke";
      this.columnNazivDatoteke.Width = 150;
      // 
      // columnNazivDirektorija
      // 
      this.columnNazivDirektorija.Text = "Naziv direktorija";
      this.columnNazivDirektorija.Width = 180;
      // 
      // columnEkstenzija
      // 
      this.columnEkstenzija.Text = "Ekstenzija";
      this.columnEkstenzija.Width = 100;
      // 
      // contextMenuStrip
      // 
      this.contextMenuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.detaljiToolStripMenuItem});
      this.contextMenuStrip.Name = "contextMenuStrip1";
      this.contextMenuStrip.Size = new System.Drawing.Size(108, 26);
      // 
      // detaljiToolStripMenuItem
      // 
      this.detaljiToolStripMenuItem.Name = "detaljiToolStripMenuItem";
      this.detaljiToolStripMenuItem.Size = new System.Drawing.Size(107, 22);
      this.detaljiToolStripMenuItem.Text = "Detalji";
      this.detaljiToolStripMenuItem.Click += new System.EventHandler(this.detaljiToolStripMenuItem_Click);
      // 
      // tabPage2
      // 
      this.tabPage2.Controls.Add(this.treeView);
      this.tabPage2.Location = new System.Drawing.Point(4, 22);
      this.tabPage2.Name = "tabPage2";
      this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
      this.tabPage2.Size = new System.Drawing.Size(483, 232);
      this.tabPage2.TabIndex = 1;
      this.tabPage2.Text = "TreeView";
      this.tabPage2.UseVisualStyleBackColor = true;
      // 
      // treeView
      // 
      this.treeView.Location = new System.Drawing.Point(16, 15);
      this.treeView.Name = "treeView";
      this.treeView.Size = new System.Drawing.Size(449, 202);
      this.treeView.TabIndex = 0;
      // 
      // groupBox1
      // 
      this.groupBox1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                  | System.Windows.Forms.AnchorStyles.Right)));
      this.groupBox1.Controls.Add(this.buttonIzlistaj);
      this.groupBox1.Controls.Add(this.buttonBrowse);
      this.groupBox1.Controls.Add(this.textBoxPut);
      this.groupBox1.Controls.Add(this.labelPut);
      this.groupBox1.Location = new System.Drawing.Point(12, 12);
      this.groupBox1.Name = "groupBox1";
      this.groupBox1.Size = new System.Drawing.Size(491, 88);
      this.groupBox1.TabIndex = 1;
      this.groupBox1.TabStop = false;
      this.groupBox1.Text = "Unesite direktorij";
      // 
      // buttonIzlistaj
      // 
      this.buttonIzlistaj.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)));
      this.buttonIzlistaj.Location = new System.Drawing.Point(397, 41);
      this.buttonIzlistaj.Name = "buttonIzlistaj";
      this.buttonIzlistaj.Size = new System.Drawing.Size(75, 23);
      this.buttonIzlistaj.TabIndex = 3;
      this.buttonIzlistaj.Text = "Izlistaj";
      this.buttonIzlistaj.UseVisualStyleBackColor = true;
      this.buttonIzlistaj.Click += new System.EventHandler(this.buttonIzlistaj_Click);
      // 
      // buttonBrowse
      // 
      this.buttonBrowse.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)));
      this.buttonBrowse.Location = new System.Drawing.Point(312, 41);
      this.buttonBrowse.Name = "buttonBrowse";
      this.buttonBrowse.Size = new System.Drawing.Size(75, 23);
      this.buttonBrowse.TabIndex = 2;
      this.buttonBrowse.Text = "Browse...";
      this.buttonBrowse.UseVisualStyleBackColor = true;
      this.buttonBrowse.Click += new System.EventHandler(this.buttonBrowse_Click);
      // 
      // textBoxPut
      // 
      this.textBoxPut.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)));
      this.textBoxPut.Location = new System.Drawing.Point(118, 43);
      this.textBoxPut.Name = "textBoxPut";
      this.textBoxPut.Size = new System.Drawing.Size(188, 20);
      this.textBoxPut.TabIndex = 1;
      // 
      // labelPut
      // 
      this.labelPut.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)));
      this.labelPut.AutoSize = true;
      this.labelPut.Location = new System.Drawing.Point(23, 46);
      this.labelPut.Name = "labelPut";
      this.labelPut.Size = new System.Drawing.Size(89, 13);
      this.labelPut.TabIndex = 0;
      this.labelPut.Text = "Put do direktorija:";
      // 
      // Form1
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.ClientSize = new System.Drawing.Size(520, 376);
      this.Controls.Add(this.groupBox1);
      this.Controls.Add(this.tabControlLista);
      this.Name = "Form1";
      this.Text = "Lista datoteka";
      this.tabControlLista.ResumeLayout(false);
      this.tabPage1.ResumeLayout(false);
      this.contextMenuStrip.ResumeLayout(false);
      this.tabPage2.ResumeLayout(false);
      this.groupBox1.ResumeLayout(false);
      this.groupBox1.PerformLayout();
      this.ResumeLayout(false);

    }

    #endregion

    private System.Windows.Forms.TabControl tabControlLista;
    private System.Windows.Forms.TabPage tabPage1;
    private System.Windows.Forms.TabPage tabPage2;
    private System.Windows.Forms.TreeView treeView;
    private System.Windows.Forms.GroupBox groupBox1;
    private System.Windows.Forms.Button buttonIzlistaj;
    private System.Windows.Forms.Button buttonBrowse;
    private System.Windows.Forms.TextBox textBoxPut;
    private System.Windows.Forms.Label labelPut;
    private System.Windows.Forms.FolderBrowserDialog folderBrowserDialog;
    private System.Windows.Forms.ListView listView;
    private System.Windows.Forms.ColumnHeader columnNazivDatoteke;
    private System.Windows.Forms.ColumnHeader columnNazivDirektorija;
    private System.Windows.Forms.ColumnHeader columnEkstenzija;
    private System.Windows.Forms.ContextMenuStrip contextMenuStrip;
    private System.Windows.Forms.ToolStripMenuItem detaljiToolStripMenuItem;
  }
}


namespace Partner
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
      this.labelIme = new System.Windows.Forms.Label();
      this.textBoxIme = new System.Windows.Forms.TextBox();
      this.labelPrezime = new System.Windows.Forms.Label();
      this.textBoxPrezime = new System.Windows.Forms.TextBox();
      this.panel1 = new System.Windows.Forms.Panel();
      this.buttonOdustani = new System.Windows.Forms.Button();
      this.checkBoxPotvrda = new System.Windows.Forms.CheckBox();
      this.textBoxJMBG = new System.Windows.Forms.TextBox();
      this.labelJMBG = new System.Windows.Forms.Label();
      this.textBoxAdresa = new System.Windows.Forms.TextBox();
      this.labelAdresa = new System.Windows.Forms.Label();
      this.labelMjesto = new System.Windows.Forms.Label();
      this.labelDrzava = new System.Windows.Forms.Label();
      this.comboBoxMjesto = new System.Windows.Forms.ComboBox();
      this.comboBoxDrzava = new System.Windows.Forms.ComboBox();
      this.buttonSpremi = new System.Windows.Forms.Button();
      this.buttonBrowseSlika = new System.Windows.Forms.Button();
      this.radioButtonPravna = new System.Windows.Forms.RadioButton();
      this.radioButtonFizicka = new System.Windows.Forms.RadioButton();
      this.labelTipPartnera = new System.Windows.Forms.Label();
      this.pictureBoxSlika = new System.Windows.Forms.PictureBox();
      this.openFileDialogSlika = new System.Windows.Forms.OpenFileDialog();
      this.menuStrip = new System.Windows.Forms.MenuStrip();
      this.toolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
      this.defaultToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.izaberiFontToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.izaberiBojuToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.pozadinaToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.defaultToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
      this.izaberiPozadinuToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.printToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
      this.errorProvider = new System.Windows.Forms.ErrorProvider(this.components);
      this.fontDialog = new System.Windows.Forms.FontDialog();
      this.colorDialogPozadina = new System.Windows.Forms.ColorDialog();
      this.colorDialogTekst = new System.Windows.Forms.ColorDialog();
      this.printDocument = new System.Drawing.Printing.PrintDocument();
      this.printDialog = new System.Windows.Forms.PrintDialog();
      this.panel1.SuspendLayout();
      ((System.ComponentModel.ISupportInitialize)(this.pictureBoxSlika)).BeginInit();
      this.menuStrip.SuspendLayout();
      ((System.ComponentModel.ISupportInitialize)(this.errorProvider)).BeginInit();
      this.SuspendLayout();
      // 
      // labelIme
      // 
      this.labelIme.AutoSize = true;
      this.labelIme.Location = new System.Drawing.Point(12, 24);
      this.labelIme.Name = "labelIme";
      this.labelIme.Size = new System.Drawing.Size(27, 13);
      this.labelIme.TabIndex = 0;
      this.labelIme.Text = "Ime:";
      // 
      // textBoxIme
      // 
      this.textBoxIme.Location = new System.Drawing.Point(67, 21);
      this.textBoxIme.Name = "textBoxIme";
      this.textBoxIme.Size = new System.Drawing.Size(172, 20);
      this.textBoxIme.TabIndex = 1;
      this.textBoxIme.Validating += new System.ComponentModel.CancelEventHandler(this.textBoxIme_Validating);
      // 
      // labelPrezime
      // 
      this.labelPrezime.AutoSize = true;
      this.labelPrezime.Location = new System.Drawing.Point(12, 50);
      this.labelPrezime.Name = "labelPrezime";
      this.labelPrezime.Size = new System.Drawing.Size(47, 13);
      this.labelPrezime.TabIndex = 2;
      this.labelPrezime.Text = "Prezime:";
      // 
      // textBoxPrezime
      // 
      this.textBoxPrezime.Location = new System.Drawing.Point(67, 47);
      this.textBoxPrezime.Name = "textBoxPrezime";
      this.textBoxPrezime.Size = new System.Drawing.Size(172, 20);
      this.textBoxPrezime.TabIndex = 2;
      this.textBoxPrezime.Validating += new System.ComponentModel.CancelEventHandler(this.textBoxPrezime_Validating);
      // 
      // panel1
      // 
      this.panel1.Controls.Add(this.buttonOdustani);
      this.panel1.Controls.Add(this.checkBoxPotvrda);
      this.panel1.Controls.Add(this.textBoxJMBG);
      this.panel1.Controls.Add(this.labelJMBG);
      this.panel1.Controls.Add(this.textBoxAdresa);
      this.panel1.Controls.Add(this.labelAdresa);
      this.panel1.Controls.Add(this.labelMjesto);
      this.panel1.Controls.Add(this.labelDrzava);
      this.panel1.Controls.Add(this.comboBoxMjesto);
      this.panel1.Controls.Add(this.comboBoxDrzava);
      this.panel1.Controls.Add(this.buttonSpremi);
      this.panel1.Controls.Add(this.buttonBrowseSlika);
      this.panel1.Controls.Add(this.radioButtonPravna);
      this.panel1.Controls.Add(this.radioButtonFizicka);
      this.panel1.Controls.Add(this.labelTipPartnera);
      this.panel1.Controls.Add(this.pictureBoxSlika);
      this.panel1.Controls.Add(this.labelIme);
      this.panel1.Controls.Add(this.textBoxIme);
      this.panel1.Controls.Add(this.labelPrezime);
      this.panel1.Controls.Add(this.textBoxPrezime);
      this.panel1.Location = new System.Drawing.Point(12, 38);
      this.panel1.Name = "panel1";
      this.panel1.Size = new System.Drawing.Size(437, 286);
      this.panel1.TabIndex = 8;
      // 
      // buttonOdustani
      // 
      this.buttonOdustani.DialogResult = System.Windows.Forms.DialogResult.Cancel;
      this.buttonOdustani.Location = new System.Drawing.Point(229, 248);
      this.buttonOdustani.Name = "buttonOdustani";
      this.buttonOdustani.Size = new System.Drawing.Size(131, 23);
      this.buttonOdustani.TabIndex = 12;
      this.buttonOdustani.Text = "Odustani";
      this.buttonOdustani.UseVisualStyleBackColor = true;
      this.buttonOdustani.Click += new System.EventHandler(this.buttonOdustani_Click);
      // 
      // checkBoxPotvrda
      // 
      this.checkBoxPotvrda.AutoSize = true;
      this.checkBoxPotvrda.Location = new System.Drawing.Point(67, 225);
      this.checkBoxPotvrda.Name = "checkBoxPotvrda";
      this.checkBoxPotvrda.Size = new System.Drawing.Size(174, 17);
      this.checkBoxPotvrda.TabIndex = 9;
      this.checkBoxPotvrda.Text = "Slanje raèuna na kuænu adresu";
      this.checkBoxPotvrda.UseVisualStyleBackColor = true;
      // 
      // textBoxJMBG
      // 
      this.textBoxJMBG.Location = new System.Drawing.Point(69, 78);
      this.textBoxJMBG.Name = "textBoxJMBG";
      this.textBoxJMBG.Size = new System.Drawing.Size(169, 20);
      this.textBoxJMBG.TabIndex = 3;
      this.textBoxJMBG.Validating += new System.ComponentModel.CancelEventHandler(this.textBoxJMBG_Validating);
      // 
      // labelJMBG
      // 
      this.labelJMBG.AutoSize = true;
      this.labelJMBG.Location = new System.Drawing.Point(12, 81);
      this.labelJMBG.Name = "labelJMBG";
      this.labelJMBG.Size = new System.Drawing.Size(39, 13);
      this.labelJMBG.TabIndex = 20;
      this.labelJMBG.Text = "JMBG:";
      // 
      // textBoxAdresa
      // 
      this.textBoxAdresa.Location = new System.Drawing.Point(67, 199);
      this.textBoxAdresa.Name = "textBoxAdresa";
      this.textBoxAdresa.Size = new System.Drawing.Size(169, 20);
      this.textBoxAdresa.TabIndex = 8;
      this.textBoxAdresa.Validating += new System.ComponentModel.CancelEventHandler(this.textBoxAdresa_Validating);
      // 
      // labelAdresa
      // 
      this.labelAdresa.AutoSize = true;
      this.labelAdresa.Location = new System.Drawing.Point(12, 202);
      this.labelAdresa.Name = "labelAdresa";
      this.labelAdresa.Size = new System.Drawing.Size(43, 13);
      this.labelAdresa.TabIndex = 18;
      this.labelAdresa.Text = "Adresa:";
      // 
      // labelMjesto
      // 
      this.labelMjesto.AutoSize = true;
      this.labelMjesto.Location = new System.Drawing.Point(12, 174);
      this.labelMjesto.Name = "labelMjesto";
      this.labelMjesto.Size = new System.Drawing.Size(41, 13);
      this.labelMjesto.TabIndex = 17;
      this.labelMjesto.Text = "Mjesto:";
      // 
      // labelDrzava
      // 
      this.labelDrzava.AutoSize = true;
      this.labelDrzava.Location = new System.Drawing.Point(12, 146);
      this.labelDrzava.Name = "labelDrzava";
      this.labelDrzava.Size = new System.Drawing.Size(44, 13);
      this.labelDrzava.TabIndex = 16;
      this.labelDrzava.Text = "Država:";
      // 
      // comboBoxMjesto
      // 
      this.comboBoxMjesto.FormattingEnabled = true;
      this.comboBoxMjesto.Location = new System.Drawing.Point(67, 171);
      this.comboBoxMjesto.Name = "comboBoxMjesto";
      this.comboBoxMjesto.Size = new System.Drawing.Size(169, 21);
      this.comboBoxMjesto.TabIndex = 7;
      // 
      // comboBoxDrzava
      // 
      this.comboBoxDrzava.FormattingEnabled = true;
      this.comboBoxDrzava.Location = new System.Drawing.Point(67, 143);
      this.comboBoxDrzava.Name = "comboBoxDrzava";
      this.comboBoxDrzava.Size = new System.Drawing.Size(169, 21);
      this.comboBoxDrzava.TabIndex = 6;
      this.comboBoxDrzava.SelectedIndexChanged += new System.EventHandler(this.comboBoxDrzava_SelectedIndexChanged);
      // 
      // buttonSpremi
      // 
      this.buttonSpremi.Location = new System.Drawing.Point(83, 248);
      this.buttonSpremi.Name = "buttonSpremi";
      this.buttonSpremi.Size = new System.Drawing.Size(131, 23);
      this.buttonSpremi.TabIndex = 11;
      this.buttonSpremi.Text = "Spremi";
      this.buttonSpremi.UseVisualStyleBackColor = true;
      this.buttonSpremi.Click += new System.EventHandler(this.buttonSpremi_Click);
      // 
      // buttonBrowseSlika
      // 
      this.buttonBrowseSlika.Location = new System.Drawing.Point(338, 192);
      this.buttonBrowseSlika.Name = "buttonBrowseSlika";
      this.buttonBrowseSlika.Size = new System.Drawing.Size(83, 23);
      this.buttonBrowseSlika.TabIndex = 10;
      this.buttonBrowseSlika.Text = "Browse...";
      this.buttonBrowseSlika.UseVisualStyleBackColor = true;
      this.buttonBrowseSlika.Click += new System.EventHandler(this.buttonBrowseSlika_Click);
      // 
      // radioButtonPravna
      // 
      this.radioButtonPravna.AutoSize = true;
      this.radioButtonPravna.Location = new System.Drawing.Point(136, 109);
      this.radioButtonPravna.Name = "radioButtonPravna";
      this.radioButtonPravna.Size = new System.Drawing.Size(59, 17);
      this.radioButtonPravna.TabIndex = 5;
      this.radioButtonPravna.Text = "Pravna";
      this.radioButtonPravna.UseVisualStyleBackColor = true;
      // 
      // radioButtonFizicka
      // 
      this.radioButtonFizicka.AutoSize = true;
      this.radioButtonFizicka.Checked = true;
      this.radioButtonFizicka.Location = new System.Drawing.Point(73, 109);
      this.radioButtonFizicka.Name = "radioButtonFizicka";
      this.radioButtonFizicka.Size = new System.Drawing.Size(58, 17);
      this.radioButtonFizicka.TabIndex = 4;
      this.radioButtonFizicka.TabStop = true;
      this.radioButtonFizicka.Text = "Fizièka";
      this.radioButtonFizicka.UseVisualStyleBackColor = true;
      // 
      // labelTipPartnera
      // 
      this.labelTipPartnera.AutoSize = true;
      this.labelTipPartnera.Location = new System.Drawing.Point(12, 111);
      this.labelTipPartnera.Name = "labelTipPartnera";
      this.labelTipPartnera.Size = new System.Drawing.Size(25, 13);
      this.labelTipPartnera.TabIndex = 9;
      this.labelTipPartnera.Text = "Tip:";
      // 
      // pictureBoxSlika
      // 
      this.pictureBoxSlika.Location = new System.Drawing.Point(259, 21);
      this.pictureBoxSlika.Name = "pictureBoxSlika";
      this.pictureBoxSlika.Size = new System.Drawing.Size(162, 165);
      this.pictureBoxSlika.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
      this.pictureBoxSlika.TabIndex = 8;
      this.pictureBoxSlika.TabStop = false;
      // 
      // menuStrip
      // 
      this.menuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripMenuItem1,
            this.pozadinaToolStripMenuItem,
            this.printToolStripMenuItem});
      this.menuStrip.Location = new System.Drawing.Point(0, 0);
      this.menuStrip.Name = "menuStrip";
      this.menuStrip.Size = new System.Drawing.Size(460, 24);
      this.menuStrip.TabIndex = 9;
      this.menuStrip.Text = "menuStrip1";
      // 
      // toolStripMenuItem1
      // 
      this.toolStripMenuItem1.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.defaultToolStripMenuItem,
            this.izaberiFontToolStripMenuItem,
            this.izaberiBojuToolStripMenuItem});
      this.toolStripMenuItem1.Name = "toolStripMenuItem1";
      this.toolStripMenuItem1.Size = new System.Drawing.Size(41, 20);
      this.toolStripMenuItem1.Text = "Font";
      // 
      // defaultToolStripMenuItem
      // 
      this.defaultToolStripMenuItem.Name = "defaultToolStripMenuItem";
      this.defaultToolStripMenuItem.Size = new System.Drawing.Size(154, 22);
      this.defaultToolStripMenuItem.Text = "Default";
      this.defaultToolStripMenuItem.Click += new System.EventHandler(this.defaultToolStripMenuItem_Click);
      // 
      // izaberiFontToolStripMenuItem
      // 
      this.izaberiFontToolStripMenuItem.Name = "izaberiFontToolStripMenuItem";
      this.izaberiFontToolStripMenuItem.Size = new System.Drawing.Size(154, 22);
      this.izaberiFontToolStripMenuItem.Text = "Izaberi font...";
      this.izaberiFontToolStripMenuItem.Click += new System.EventHandler(this.izaberiFontToolStripMenuItem_Click);
      // 
      // izaberiBojuToolStripMenuItem
      // 
      this.izaberiBojuToolStripMenuItem.Name = "izaberiBojuToolStripMenuItem";
      this.izaberiBojuToolStripMenuItem.Size = new System.Drawing.Size(154, 22);
      this.izaberiBojuToolStripMenuItem.Text = "Izaberi boju...";
      this.izaberiBojuToolStripMenuItem.Click += new System.EventHandler(this.izaberiBojuToolStripMenuItem_Click);
      // 
      // pozadinaToolStripMenuItem
      // 
      this.pozadinaToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.defaultToolStripMenuItem1,
            this.izaberiPozadinuToolStripMenuItem});
      this.pozadinaToolStripMenuItem.Name = "pozadinaToolStripMenuItem";
      this.pozadinaToolStripMenuItem.Size = new System.Drawing.Size(62, 20);
      this.pozadinaToolStripMenuItem.Text = "Pozadina";
      // 
      // defaultToolStripMenuItem1
      // 
      this.defaultToolStripMenuItem1.Name = "defaultToolStripMenuItem1";
      this.defaultToolStripMenuItem1.Size = new System.Drawing.Size(176, 22);
      this.defaultToolStripMenuItem1.Text = "Default";
      this.defaultToolStripMenuItem1.Click += new System.EventHandler(this.defaultToolStripMenuItem1_Click);
      // 
      // izaberiPozadinuToolStripMenuItem
      // 
      this.izaberiPozadinuToolStripMenuItem.Name = "izaberiPozadinuToolStripMenuItem";
      this.izaberiPozadinuToolStripMenuItem.Size = new System.Drawing.Size(176, 22);
      this.izaberiPozadinuToolStripMenuItem.Text = "Izaberi pozadinu...";
      this.izaberiPozadinuToolStripMenuItem.Click += new System.EventHandler(this.izaberiPozadinuToolStripMenuItem_Click);
      // 
      // printToolStripMenuItem
      // 
      this.printToolStripMenuItem.Name = "printToolStripMenuItem";
      this.printToolStripMenuItem.Size = new System.Drawing.Size(41, 20);
      this.printToolStripMenuItem.Text = "Print";
      this.printToolStripMenuItem.Click += new System.EventHandler(this.printToolStripMenuItem_Click);
      // 
      // errorProvider
      // 
      this.errorProvider.ContainerControl = this;
      // 
      // printDocument
      // 
      this.printDocument.PrintPage += new System.Drawing.Printing.PrintPageEventHandler(this.printDocument1_PrintPage);
      // 
      // printDialog
      // 
      this.printDialog.UseEXDialog = true;
      // 
      // Form1
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.BackColor = System.Drawing.SystemColors.Control;
      this.CancelButton = this.buttonOdustani;
      this.ClientSize = new System.Drawing.Size(460, 336);
      this.Controls.Add(this.panel1);
      this.Controls.Add(this.menuStrip);
      this.ForeColor = System.Drawing.SystemColors.ControlText;
      this.MainMenuStrip = this.menuStrip;
      this.Name = "Form1";
      this.Text = "Poslovni partner";
      this.panel1.ResumeLayout(false);
      this.panel1.PerformLayout();
      ((System.ComponentModel.ISupportInitialize)(this.pictureBoxSlika)).EndInit();
      this.menuStrip.ResumeLayout(false);
      this.menuStrip.PerformLayout();
      ((System.ComponentModel.ISupportInitialize)(this.errorProvider)).EndInit();
      this.ResumeLayout(false);
      this.PerformLayout();

    }

    #endregion

    private System.Windows.Forms.Label labelIme;
    private System.Windows.Forms.TextBox textBoxIme;
    private System.Windows.Forms.Label labelPrezime;
    private System.Windows.Forms.TextBox textBoxPrezime;
    private System.Windows.Forms.Panel panel1;
    private System.Windows.Forms.PictureBox pictureBoxSlika;
    private System.Windows.Forms.RadioButton radioButtonPravna;
    private System.Windows.Forms.RadioButton radioButtonFizicka;
    private System.Windows.Forms.Label labelTipPartnera;
    private System.Windows.Forms.Button buttonBrowseSlika;
    private System.Windows.Forms.OpenFileDialog openFileDialogSlika;
    private System.Windows.Forms.TextBox textBoxJMBG;
    private System.Windows.Forms.Label labelJMBG;
    private System.Windows.Forms.TextBox textBoxAdresa;
    private System.Windows.Forms.Label labelAdresa;
    private System.Windows.Forms.Label labelMjesto;
    private System.Windows.Forms.Label labelDrzava;
    private System.Windows.Forms.ComboBox comboBoxMjesto;
    private System.Windows.Forms.ComboBox comboBoxDrzava;
    private System.Windows.Forms.Button buttonSpremi;
    private System.Windows.Forms.MenuStrip menuStrip;
    private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem1;
    private System.Windows.Forms.ToolStripMenuItem pozadinaToolStripMenuItem;
    private System.Windows.Forms.ErrorProvider errorProvider;
    private System.Windows.Forms.ToolStripMenuItem izaberiFontToolStripMenuItem;
    private System.Windows.Forms.FontDialog fontDialog;
    private System.Windows.Forms.ToolStripMenuItem defaultToolStripMenuItem;
    private System.Windows.Forms.ToolStripMenuItem izaberiPozadinuToolStripMenuItem;
    private System.Windows.Forms.ColorDialog colorDialogPozadina;
    private System.Windows.Forms.ToolStripMenuItem defaultToolStripMenuItem1;
    private System.Windows.Forms.ToolStripMenuItem izaberiBojuToolStripMenuItem;
    private System.Windows.Forms.ColorDialog colorDialogTekst;
    private System.Windows.Forms.CheckBox checkBoxPotvrda;
    private System.Drawing.Printing.PrintDocument printDocument;
    private System.Windows.Forms.ToolStripMenuItem printToolStripMenuItem;
    private System.Windows.Forms.PrintDialog printDialog;
    private System.Windows.Forms.Button buttonOdustani;
  }
}



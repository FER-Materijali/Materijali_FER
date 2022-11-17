namespace Custom
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
      this.textBoxIme = new System.Windows.Forms.TextBox();
      this.textBoxPrezime = new System.Windows.Forms.TextBox();
      this.labelIme = new System.Windows.Forms.Label();
      this.labelPrezime = new System.Windows.Forms.Label();
      this.button1 = new System.Windows.Forms.Button();
      this.userControlAdresaIsporuke = new Adresa.UserControlAdresa();
      this.userControlAdresaSjedista = new Adresa.UserControlAdresa();
      this.SuspendLayout();
      // 
      // textBoxIme
      // 
      this.textBoxIme.Location = new System.Drawing.Point(59, 39);
      this.textBoxIme.Name = "textBoxIme";
      this.textBoxIme.Size = new System.Drawing.Size(168, 20);
      this.textBoxIme.TabIndex = 2;
      // 
      // textBoxPrezime
      // 
      this.textBoxPrezime.Location = new System.Drawing.Point(300, 39);
      this.textBoxPrezime.Name = "textBoxPrezime";
      this.textBoxPrezime.Size = new System.Drawing.Size(165, 20);
      this.textBoxPrezime.TabIndex = 3;
      // 
      // labelIme
      // 
      this.labelIme.AutoSize = true;
      this.labelIme.Location = new System.Drawing.Point(26, 42);
      this.labelIme.Name = "labelIme";
      this.labelIme.Size = new System.Drawing.Size(27, 13);
      this.labelIme.TabIndex = 4;
      this.labelIme.Text = "Ime:";
      // 
      // labelPrezime
      // 
      this.labelPrezime.AutoSize = true;
      this.labelPrezime.Location = new System.Drawing.Point(248, 42);
      this.labelPrezime.Name = "labelPrezime";
      this.labelPrezime.Size = new System.Drawing.Size(47, 13);
      this.labelPrezime.TabIndex = 5;
      this.labelPrezime.Text = "Prezime:";
      // 
      // button1
      // 
      this.button1.Location = new System.Drawing.Point(175, 215);
      this.button1.Name = "button1";
      this.button1.Size = new System.Drawing.Size(146, 23);
      this.button1.TabIndex = 6;
      this.button1.Text = "Spremi";
      this.button1.UseVisualStyleBackColor = true;
      this.button1.Click += new System.EventHandler(this.button1_Click);
      // 
      // userControlAdresaIsporuke
      // 
      this.userControlAdresaIsporuke.Adresa = "";
      this.userControlAdresaIsporuke.DrzavaDataSource = null;
      this.userControlAdresaIsporuke.DrzavaSelectedIndex = -1;
      this.userControlAdresaIsporuke.DrzavaSelectedText = "";
      this.userControlAdresaIsporuke.GroupBoxText = "Adresa isporuke:";
      this.userControlAdresaIsporuke.Location = new System.Drawing.Point(251, 65);
      this.userControlAdresaIsporuke.MjestoDataSource = null;
      this.userControlAdresaIsporuke.MjestoSelectedIndex = -1;
      this.userControlAdresaIsporuke.MjestoSelectedText = "";
      this.userControlAdresaIsporuke.Name = "userControlAdresaIsporuke";
      this.userControlAdresaIsporuke.Size = new System.Drawing.Size(231, 144);
      this.userControlAdresaIsporuke.TabIndex = 7;
      this.userControlAdresaIsporuke.DrzavaIndexChanged += new Adresa.UserControlAdresa.ComboBoxIndexChangedHandler(this.userControlAdresaIsporuke_DrzavaIndexChanged);
      // 
      // userControlAdresaSjedista
      // 
      this.userControlAdresaSjedista.Adresa = "";
      this.userControlAdresaSjedista.DrzavaDataSource = null;
      this.userControlAdresaSjedista.DrzavaSelectedIndex = -1;
      this.userControlAdresaSjedista.DrzavaSelectedText = "";
      this.userControlAdresaSjedista.GroupBoxText = "Adresa sjedišta:";
      this.userControlAdresaSjedista.Location = new System.Drawing.Point(14, 65);
      this.userControlAdresaSjedista.MjestoDataSource = null;
      this.userControlAdresaSjedista.MjestoSelectedIndex = -1;
      this.userControlAdresaSjedista.MjestoSelectedText = "";
      this.userControlAdresaSjedista.Name = "userControlAdresaSjedista";
      this.userControlAdresaSjedista.Size = new System.Drawing.Size(231, 144);
      this.userControlAdresaSjedista.TabIndex = 0;
      this.userControlAdresaSjedista.DrzavaIndexChanged += new Adresa.UserControlAdresa.ComboBoxIndexChangedHandler(this.userControlAdresaSjedista_DrzavaIndexChanged);
      // 
      // Form1
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.ClientSize = new System.Drawing.Size(499, 254);
      this.Controls.Add(this.userControlAdresaIsporuke);
      this.Controls.Add(this.button1);
      this.Controls.Add(this.labelPrezime);
      this.Controls.Add(this.labelIme);
      this.Controls.Add(this.textBoxPrezime);
      this.Controls.Add(this.textBoxIme);
      this.Controls.Add(this.userControlAdresaSjedista);
      this.Name = "Form1";
      this.Text = "Poslovni partner - Custom kontrole";
      this.ResumeLayout(false);
      this.PerformLayout();

    }

    #endregion

    private Adresa.UserControlAdresa userControlAdresaSjedista;
    private System.Windows.Forms.TextBox textBoxIme;
    private System.Windows.Forms.TextBox textBoxPrezime;
    private System.Windows.Forms.Label labelIme;
    private System.Windows.Forms.Label labelPrezime;
    private System.Windows.Forms.Button button1;
    private Adresa.UserControlAdresa userControlAdresaIsporuke;
  }
}


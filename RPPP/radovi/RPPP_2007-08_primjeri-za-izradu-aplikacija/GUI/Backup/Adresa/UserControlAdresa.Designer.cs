namespace Adresa
{
  partial class UserControlAdresa
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

    #region Component Designer generated code

    /// <summary>
    /// Required method for Designer support - do not modify 
    /// the contents of this method with the code editor.
    /// </summary>
    private void InitializeComponent()
    {
      this.groupBox1 = new System.Windows.Forms.GroupBox();
      this.comboBoxMjesto = new System.Windows.Forms.ComboBox();
      this.comboBoxDrzava = new System.Windows.Forms.ComboBox();
      this.textBoxAdresa = new System.Windows.Forms.TextBox();
      this.labelMjesto = new System.Windows.Forms.Label();
      this.labelDrzava = new System.Windows.Forms.Label();
      this.labelAdresa = new System.Windows.Forms.Label();
      this.groupBox1.SuspendLayout();
      this.SuspendLayout();
      // 
      // groupBox1
      // 
      this.groupBox1.Controls.Add(this.comboBoxMjesto);
      this.groupBox1.Controls.Add(this.comboBoxDrzava);
      this.groupBox1.Controls.Add(this.textBoxAdresa);
      this.groupBox1.Controls.Add(this.labelMjesto);
      this.groupBox1.Controls.Add(this.labelDrzava);
      this.groupBox1.Controls.Add(this.labelAdresa);
      this.groupBox1.Location = new System.Drawing.Point(13, 13);
      this.groupBox1.Name = "groupBox1";
      this.groupBox1.Size = new System.Drawing.Size(200, 116);
      this.groupBox1.TabIndex = 6;
      this.groupBox1.TabStop = false;
      this.groupBox1.Text = "groupBox1";
      // 
      // comboBoxMjesto
      // 
      this.comboBoxMjesto.FormattingEnabled = true;
      this.comboBoxMjesto.Location = new System.Drawing.Point(68, 75);
      this.comboBoxMjesto.Name = "comboBoxMjesto";
      this.comboBoxMjesto.Size = new System.Drawing.Size(121, 21);
      this.comboBoxMjesto.TabIndex = 11;
      this.comboBoxMjesto.SelectedIndexChanged += new System.EventHandler(this.comboBoxMjesto_SelectedIndexChanged);
      // 
      // comboBoxDrzava
      // 
      this.comboBoxDrzava.FormattingEnabled = true;
      this.comboBoxDrzava.Location = new System.Drawing.Point(68, 50);
      this.comboBoxDrzava.Name = "comboBoxDrzava";
      this.comboBoxDrzava.Size = new System.Drawing.Size(121, 21);
      this.comboBoxDrzava.TabIndex = 10;
      this.comboBoxDrzava.SelectedIndexChanged += new System.EventHandler(this.comboBoxDrzava_SelectedIndexChanged);
      // 
      // textBoxAdresa
      // 
      this.textBoxAdresa.Location = new System.Drawing.Point(68, 26);
      this.textBoxAdresa.Name = "textBoxAdresa";
      this.textBoxAdresa.Size = new System.Drawing.Size(121, 20);
      this.textBoxAdresa.TabIndex = 9;
      // 
      // labelMjesto
      // 
      this.labelMjesto.AutoSize = true;
      this.labelMjesto.Location = new System.Drawing.Point(17, 79);
      this.labelMjesto.Name = "labelMjesto";
      this.labelMjesto.Size = new System.Drawing.Size(41, 13);
      this.labelMjesto.TabIndex = 8;
      this.labelMjesto.Text = "Mjesto:";
      // 
      // labelDrzava
      // 
      this.labelDrzava.AutoSize = true;
      this.labelDrzava.Location = new System.Drawing.Point(17, 54);
      this.labelDrzava.Name = "labelDrzava";
      this.labelDrzava.Size = new System.Drawing.Size(41, 13);
      this.labelDrzava.TabIndex = 7;
      this.labelDrzava.Text = "Država";
      // 
      // labelAdresa
      // 
      this.labelAdresa.AutoSize = true;
      this.labelAdresa.Location = new System.Drawing.Point(17, 29);
      this.labelAdresa.Name = "labelAdresa";
      this.labelAdresa.Size = new System.Drawing.Size(43, 13);
      this.labelAdresa.TabIndex = 6;
      this.labelAdresa.Text = "Adresa:";
      // 
      // UserControlAdresa
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.Controls.Add(this.groupBox1);
      this.Name = "UserControlAdresa";
      this.Size = new System.Drawing.Size(231, 144);
      this.groupBox1.ResumeLayout(false);
      this.groupBox1.PerformLayout();
      this.ResumeLayout(false);

    }

    #endregion

    private System.Windows.Forms.GroupBox groupBox1;
    private System.Windows.Forms.ComboBox comboBoxMjesto;
    private System.Windows.Forms.ComboBox comboBoxDrzava;
    private System.Windows.Forms.TextBox textBoxAdresa;
    private System.Windows.Forms.Label labelMjesto;
    private System.Windows.Forms.Label labelDrzava;
    private System.Windows.Forms.Label labelAdresa;

  }
}

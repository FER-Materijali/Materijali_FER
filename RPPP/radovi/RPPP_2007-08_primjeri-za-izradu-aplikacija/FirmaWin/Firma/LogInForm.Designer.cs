namespace Firma
{
  partial class LogInForm
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
      this.textBoxKorisnik = new System.Windows.Forms.TextBox();
      this.label1 = new System.Windows.Forms.Label();
      this.label2 = new System.Windows.Forms.Label();
      this.buttonOk = new System.Windows.Forms.Button();
      this.buttonCancel = new System.Windows.Forms.Button();
      this.textBoxZaporka = new System.Windows.Forms.TextBox();
      this.SuspendLayout();
      // 
      // textBoxKorisnik
      // 
      this.textBoxKorisnik.Location = new System.Drawing.Point(102, 50);
      this.textBoxKorisnik.Name = "textBoxKorisnik";
      this.textBoxKorisnik.Size = new System.Drawing.Size(200, 20);
      this.textBoxKorisnik.TabIndex = 0;
      this.textBoxKorisnik.Text = "rppp";
      // 
      // label1
      // 
      this.label1.AutoSize = true;
      this.label1.Location = new System.Drawing.Point(21, 53);
      this.label1.Name = "label1";
      this.label1.Size = new System.Drawing.Size(75, 13);
      this.label1.TabIndex = 2;
      this.label1.Text = "Korisnièko ime";
      // 
      // label2
      // 
      this.label2.AutoSize = true;
      this.label2.Location = new System.Drawing.Point(21, 79);
      this.label2.Name = "label2";
      this.label2.Size = new System.Drawing.Size(47, 13);
      this.label2.TabIndex = 3;
      this.label2.Text = "Zaporka";
      // 
      // buttonOk
      // 
      this.buttonOk.Location = new System.Drawing.Point(81, 124);
      this.buttonOk.Name = "buttonOk";
      this.buttonOk.Size = new System.Drawing.Size(75, 23);
      this.buttonOk.TabIndex = 2;
      this.buttonOk.Text = "Potvrdi";
      this.buttonOk.UseVisualStyleBackColor = true;
      this.buttonOk.Click += new System.EventHandler(this.buttonOk_Click);
      // 
      // buttonCancel
      // 
      this.buttonCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
      this.buttonCancel.Location = new System.Drawing.Point(172, 124);
      this.buttonCancel.Name = "buttonCancel";
      this.buttonCancel.Size = new System.Drawing.Size(75, 23);
      this.buttonCancel.TabIndex = 3;
      this.buttonCancel.Text = "Odustani";
      this.buttonCancel.UseVisualStyleBackColor = true;
      this.buttonCancel.Click += new System.EventHandler(this.buttonCancel_Click);
      // 
      // textBoxZaporka
      // 
      this.textBoxZaporka.Location = new System.Drawing.Point(102, 76);
      this.textBoxZaporka.Name = "textBoxZaporka";
      this.textBoxZaporka.PasswordChar = '*';
      this.textBoxZaporka.Size = new System.Drawing.Size(200, 20);
      this.textBoxZaporka.TabIndex = 1;
      this.textBoxZaporka.Text = "rppp";
      this.textBoxZaporka.UseSystemPasswordChar = true;
      // 
      // LogInForm
      // 
      this.AcceptButton = this.buttonOk;
      this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.CancelButton = this.buttonCancel;
      this.ClientSize = new System.Drawing.Size(324, 205);
      this.ControlBox = false;
      this.Controls.Add(this.textBoxZaporka);
      this.Controls.Add(this.buttonCancel);
      this.Controls.Add(this.buttonOk);
      this.Controls.Add(this.label2);
      this.Controls.Add(this.label1);
      this.Controls.Add(this.textBoxKorisnik);
      this.Name = "LogInForm";
      this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
      this.Text = "Prijava na sustav";
      this.ResumeLayout(false);
      this.PerformLayout();

    }

    #endregion

    private System.Windows.Forms.TextBox textBoxKorisnik;
    private System.Windows.Forms.Label label1;
    private System.Windows.Forms.Label label2;
    private System.Windows.Forms.Button buttonOk;
    private System.Windows.Forms.Button buttonCancel;
    private System.Windows.Forms.TextBox textBoxZaporka;

  }
}
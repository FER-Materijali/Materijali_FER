namespace Import
{
  partial class UserControlMapiranje
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
      this.checkBoxOstalo = new System.Windows.Forms.CheckBox();
      this.textBoxOstalo = new System.Windows.Forms.TextBox();
      this.textBoxNazivStupcaTablice = new System.Windows.Forms.TextBox();
      this.comboBoxMapiranje = new System.Windows.Forms.ComboBox();
      this.SuspendLayout();
      // 
      // checkBoxOstalo
      // 
      this.checkBoxOstalo.AutoSize = true;
      this.checkBoxOstalo.Location = new System.Drawing.Point(189, 12);
      this.checkBoxOstalo.Name = "checkBoxOstalo";
      this.checkBoxOstalo.Size = new System.Drawing.Size(58, 17);
      this.checkBoxOstalo.TabIndex = 0;
      this.checkBoxOstalo.Text = "Drugo:";
      this.checkBoxOstalo.UseVisualStyleBackColor = true;
      this.checkBoxOstalo.CheckedChanged += new System.EventHandler(this.checkBoxOstalo_CheckedChanged);
      // 
      // textBoxOstalo
      // 
      this.textBoxOstalo.Enabled = false;
      this.textBoxOstalo.Location = new System.Drawing.Point(254, 10);
      this.textBoxOstalo.Name = "textBoxOstalo";
      this.textBoxOstalo.Size = new System.Drawing.Size(135, 20);
      this.textBoxOstalo.TabIndex = 1;
      // 
      // textBoxNazivStupcaTablice
      // 
      this.textBoxNazivStupcaTablice.Location = new System.Drawing.Point(421, 10);
      this.textBoxNazivStupcaTablice.Name = "textBoxNazivStupcaTablice";
      this.textBoxNazivStupcaTablice.ReadOnly = true;
      this.textBoxNazivStupcaTablice.Size = new System.Drawing.Size(150, 20);
      this.textBoxNazivStupcaTablice.TabIndex = 2;
      // 
      // comboBoxMapiranje
      // 
      this.comboBoxMapiranje.FormattingEnabled = true;
      this.comboBoxMapiranje.Location = new System.Drawing.Point(15, 10);
      this.comboBoxMapiranje.Name = "comboBoxMapiranje";
      this.comboBoxMapiranje.Size = new System.Drawing.Size(159, 21);
      this.comboBoxMapiranje.TabIndex = 3;
      // 
      // UserControlMapiranje
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.Controls.Add(this.comboBoxMapiranje);
      this.Controls.Add(this.textBoxNazivStupcaTablice);
      this.Controls.Add(this.textBoxOstalo);
      this.Controls.Add(this.checkBoxOstalo);
      this.Name = "UserControlMapiranje";
      this.Size = new System.Drawing.Size(590, 38);
      this.ResumeLayout(false);
      this.PerformLayout();

    }

    #endregion

    private System.Windows.Forms.CheckBox checkBoxOstalo;
    private System.Windows.Forms.TextBox textBoxOstalo;
    private System.Windows.Forms.TextBox textBoxNazivStupcaTablice;
    private System.Windows.Forms.ComboBox comboBoxMapiranje;
  }
}

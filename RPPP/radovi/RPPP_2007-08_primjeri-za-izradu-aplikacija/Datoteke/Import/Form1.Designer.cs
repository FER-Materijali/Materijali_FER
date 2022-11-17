namespace Import
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
      this.Excel = new System.Windows.Forms.GroupBox();
      this.comboBoxList = new System.Windows.Forms.ComboBox();
      this.buttonBrowseExcel = new System.Windows.Forms.Button();
      this.textBoxDatoteka = new System.Windows.Forms.TextBox();
      this.groupBox1 = new System.Windows.Forms.GroupBox();
      this.comboBoxTablice = new System.Windows.Forms.ComboBox();
      this.buttonMapiranje = new System.Windows.Forms.Button();
      this.buttonPrebaci = new System.Windows.Forms.Button();
      this.Excel.SuspendLayout();
      this.groupBox1.SuspendLayout();
      this.SuspendLayout();
      // 
      // Excel
      // 
      this.Excel.Controls.Add(this.comboBoxList);
      this.Excel.Controls.Add(this.buttonBrowseExcel);
      this.Excel.Controls.Add(this.textBoxDatoteka);
      this.Excel.Location = new System.Drawing.Point(3, 12);
      this.Excel.Name = "Excel";
      this.Excel.Size = new System.Drawing.Size(405, 58);
      this.Excel.TabIndex = 0;
      this.Excel.TabStop = false;
      this.Excel.Text = "Izvor - Excel ili CSV datoteka";
      // 
      // comboBoxList
      // 
      this.comboBoxList.FormattingEnabled = true;
      this.comboBoxList.Location = new System.Drawing.Point(274, 21);
      this.comboBoxList.Name = "comboBoxList";
      this.comboBoxList.Size = new System.Drawing.Size(121, 21);
      this.comboBoxList.TabIndex = 3;
      // 
      // buttonBrowseExcel
      // 
      this.buttonBrowseExcel.Location = new System.Drawing.Point(199, 19);
      this.buttonBrowseExcel.Name = "buttonBrowseExcel";
      this.buttonBrowseExcel.Size = new System.Drawing.Size(69, 23);
      this.buttonBrowseExcel.TabIndex = 1;
      this.buttonBrowseExcel.Text = "Odaberi...";
      this.buttonBrowseExcel.UseVisualStyleBackColor = true;
      this.buttonBrowseExcel.Click += new System.EventHandler(this.buttonBrowseDatoteka_Click);
      // 
      // textBoxDatoteka
      // 
      this.textBoxDatoteka.Location = new System.Drawing.Point(10, 21);
      this.textBoxDatoteka.Name = "textBoxDatoteka";
      this.textBoxDatoteka.Size = new System.Drawing.Size(184, 20);
      this.textBoxDatoteka.TabIndex = 0;
      // 
      // groupBox1
      // 
      this.groupBox1.Controls.Add(this.comboBoxTablice);
      this.groupBox1.Location = new System.Drawing.Point(414, 12);
      this.groupBox1.Name = "groupBox1";
      this.groupBox1.Size = new System.Drawing.Size(170, 58);
      this.groupBox1.TabIndex = 1;
      this.groupBox1.TabStop = false;
      this.groupBox1.Text = "Odredište - tablica baze";
      // 
      // comboBoxTablice
      // 
      this.comboBoxTablice.FormattingEnabled = true;
      this.comboBoxTablice.Location = new System.Drawing.Point(6, 21);
      this.comboBoxTablice.Name = "comboBoxTablice";
      this.comboBoxTablice.Size = new System.Drawing.Size(155, 21);
      this.comboBoxTablice.TabIndex = 0;
      // 
      // buttonMapiranje
      // 
      this.buttonMapiranje.Location = new System.Drawing.Point(322, 76);
      this.buttonMapiranje.Name = "buttonMapiranje";
      this.buttonMapiranje.Size = new System.Drawing.Size(124, 25);
      this.buttonMapiranje.TabIndex = 2;
      this.buttonMapiranje.Text = "Mapiraj";
      this.buttonMapiranje.UseVisualStyleBackColor = true;
      this.buttonMapiranje.Click += new System.EventHandler(this.buttonMapiranje_Click);
      // 
      // buttonPrebaci
      // 
      this.buttonPrebaci.Enabled = false;
      this.buttonPrebaci.Location = new System.Drawing.Point(452, 76);
      this.buttonPrebaci.Name = "buttonPrebaci";
      this.buttonPrebaci.Size = new System.Drawing.Size(124, 25);
      this.buttonPrebaci.TabIndex = 3;
      this.buttonPrebaci.Text = "Prebaci";
      this.buttonPrebaci.UseVisualStyleBackColor = true;
      this.buttonPrebaci.Click += new System.EventHandler(this.buttonPrebaci_Click);
      // 
      // Form1
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.ClientSize = new System.Drawing.Size(589, 532);
      this.Controls.Add(this.buttonPrebaci);
      this.Controls.Add(this.buttonMapiranje);
      this.Controls.Add(this.groupBox1);
      this.Controls.Add(this.Excel);
      this.Name = "Form1";
      this.Text = "Prijenos podataka";
      this.Excel.ResumeLayout(false);
      this.Excel.PerformLayout();
      this.groupBox1.ResumeLayout(false);
      this.ResumeLayout(false);

    }

    #endregion

    private System.Windows.Forms.GroupBox Excel;
    private System.Windows.Forms.Button buttonBrowseExcel;
    private System.Windows.Forms.TextBox textBoxDatoteka;
    private System.Windows.Forms.GroupBox groupBox1;
    private System.Windows.Forms.ComboBox comboBoxTablice;
    private System.Windows.Forms.Button buttonMapiranje;
    private System.Windows.Forms.ComboBox comboBoxList;
    private System.Windows.Forms.Button buttonPrebaci;
  }
}


namespace QueryManager
{
  partial class Upitnik
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
      this.textBoxUpit = new System.Windows.Forms.TextBox();
      this.listViewRezultat = new System.Windows.Forms.ListView();
      this.buttonExecute = new System.Windows.Forms.Button();
      this.label1 = new System.Windows.Forms.Label();
      this.label2 = new System.Windows.Forms.Label();
      this.groupBoxKonekcija = new System.Windows.Forms.GroupBox();
      this.buttonScalar = new System.Windows.Forms.Button();
      this.buttonNonQuery = new System.Windows.Forms.Button();
      this.buttonClose = new System.Windows.Forms.Button();
      this.buttonOpen = new System.Windows.Forms.Button();
      this.radioButtonMSJET = new System.Windows.Forms.RadioButton();
      this.radioButtonOLEDBSQL = new System.Windows.Forms.RadioButton();
      this.radioButtonSQLCON = new System.Windows.Forms.RadioButton();
      this.label3 = new System.Windows.Forms.Label();
      this.textBoxConnString = new System.Windows.Forms.TextBox();
      this.groupBoxUpit = new System.Windows.Forms.GroupBox();
      this.groupBoxKonekcija.SuspendLayout();
      this.groupBoxUpit.SuspendLayout();
      this.SuspendLayout();
      // 
      // textBoxUpit
      // 
      this.textBoxUpit.Location = new System.Drawing.Point(16, 29);
      this.textBoxUpit.Multiline = true;
      this.textBoxUpit.Name = "textBoxUpit";
      this.textBoxUpit.Size = new System.Drawing.Size(565, 63);
      this.textBoxUpit.TabIndex = 0;
      // 
      // listViewRezultat
      // 
      this.listViewRezultat.Location = new System.Drawing.Point(16, 121);
      this.listViewRezultat.Name = "listViewRezultat";
      this.listViewRezultat.Size = new System.Drawing.Size(565, 164);
      this.listViewRezultat.TabIndex = 1;
      this.listViewRezultat.UseCompatibleStateImageBehavior = false;
      this.listViewRezultat.View = System.Windows.Forms.View.Details;
      // 
      // buttonExecute
      // 
      this.buttonExecute.Enabled = false;
      this.buttonExecute.Location = new System.Drawing.Point(204, 115);
      this.buttonExecute.Name = "buttonExecute";
      this.buttonExecute.Size = new System.Drawing.Size(75, 23);
      this.buttonExecute.TabIndex = 2;
      this.buttonExecute.Text = "Obavi";
      this.buttonExecute.UseVisualStyleBackColor = true;
      this.buttonExecute.Click += new System.EventHandler(this.buttonExecute_Click);
      // 
      // label1
      // 
      this.label1.AutoSize = true;
      this.label1.Location = new System.Drawing.Point(13, 13);
      this.label1.Name = "label1";
      this.label1.Size = new System.Drawing.Size(51, 13);
      this.label1.TabIndex = 3;
      this.label1.Text = "SQL upit:";
      // 
      // label2
      // 
      this.label2.AutoSize = true;
      this.label2.Location = new System.Drawing.Point(13, 105);
      this.label2.Name = "label2";
      this.label2.Size = new System.Drawing.Size(75, 13);
      this.label2.TabIndex = 4;
      this.label2.Text = "Rezultat upita:";
      // 
      // groupBoxKonekcija
      // 
      this.groupBoxKonekcija.Controls.Add(this.buttonScalar);
      this.groupBoxKonekcija.Controls.Add(this.buttonNonQuery);
      this.groupBoxKonekcija.Controls.Add(this.buttonClose);
      this.groupBoxKonekcija.Controls.Add(this.buttonOpen);
      this.groupBoxKonekcija.Controls.Add(this.buttonExecute);
      this.groupBoxKonekcija.Controls.Add(this.radioButtonMSJET);
      this.groupBoxKonekcija.Controls.Add(this.radioButtonOLEDBSQL);
      this.groupBoxKonekcija.Controls.Add(this.radioButtonSQLCON);
      this.groupBoxKonekcija.Controls.Add(this.label3);
      this.groupBoxKonekcija.Controls.Add(this.textBoxConnString);
      this.groupBoxKonekcija.Location = new System.Drawing.Point(12, 24);
      this.groupBoxKonekcija.Name = "groupBoxKonekcija";
      this.groupBoxKonekcija.Size = new System.Drawing.Size(599, 154);
      this.groupBoxKonekcija.TabIndex = 5;
      this.groupBoxKonekcija.TabStop = false;
      this.groupBoxKonekcija.Text = "Postavke konekcije";
      // 
      // buttonScalar
      // 
      this.buttonScalar.Enabled = false;
      this.buttonScalar.Location = new System.Drawing.Point(406, 115);
      this.buttonScalar.Name = "buttonScalar";
      this.buttonScalar.Size = new System.Drawing.Size(75, 23);
      this.buttonScalar.TabIndex = 8;
      this.buttonScalar.Text = "Scalar";
      this.buttonScalar.UseVisualStyleBackColor = true;
      this.buttonScalar.Click += new System.EventHandler(this.buttonScalar_Click);
      // 
      // buttonNonQuery
      // 
      this.buttonNonQuery.Enabled = false;
      this.buttonNonQuery.Location = new System.Drawing.Point(305, 115);
      this.buttonNonQuery.Name = "buttonNonQuery";
      this.buttonNonQuery.Size = new System.Drawing.Size(75, 23);
      this.buttonNonQuery.TabIndex = 7;
      this.buttonNonQuery.Text = "NonQuery";
      this.buttonNonQuery.UseVisualStyleBackColor = true;
      this.buttonNonQuery.Click += new System.EventHandler(this.buttonNonQuery_Click);
      // 
      // buttonClose
      // 
      this.buttonClose.Enabled = false;
      this.buttonClose.Location = new System.Drawing.Point(507, 115);
      this.buttonClose.Name = "buttonClose";
      this.buttonClose.Size = new System.Drawing.Size(75, 23);
      this.buttonClose.TabIndex = 6;
      this.buttonClose.Text = "Zatvori";
      this.buttonClose.UseVisualStyleBackColor = true;
      this.buttonClose.Click += new System.EventHandler(this.buttonClose_Click);
      // 
      // buttonOpen
      // 
      this.buttonOpen.Location = new System.Drawing.Point(103, 115);
      this.buttonOpen.Name = "buttonOpen";
      this.buttonOpen.Size = new System.Drawing.Size(75, 23);
      this.buttonOpen.TabIndex = 5;
      this.buttonOpen.Text = "Otvori";
      this.buttonOpen.UseVisualStyleBackColor = true;
      this.buttonOpen.Click += new System.EventHandler(this.buttonOpen_Click);
      // 
      // radioButtonMSJET
      // 
      this.radioButtonMSJET.AutoSize = true;
      this.radioButtonMSJET.Location = new System.Drawing.Point(18, 79);
      this.radioButtonMSJET.Name = "radioButtonMSJET";
      this.radioButtonMSJET.Size = new System.Drawing.Size(148, 17);
      this.radioButtonMSJET.TabIndex = 4;
      this.radioButtonMSJET.Tag = "";
      this.radioButtonMSJET.Text = "OLEDB Access konekcija";
      this.radioButtonMSJET.UseVisualStyleBackColor = true;
      this.radioButtonMSJET.CheckedChanged += new System.EventHandler(this.radioButtonMSJET_CheckedChanged);
      // 
      // radioButtonOLEDBSQL
      // 
      this.radioButtonOLEDBSQL.AutoSize = true;
      this.radioButtonOLEDBSQL.Location = new System.Drawing.Point(18, 56);
      this.radioButtonOLEDBSQL.Name = "radioButtonOLEDBSQL";
      this.radioButtonOLEDBSQL.Size = new System.Drawing.Size(134, 17);
      this.radioButtonOLEDBSQL.TabIndex = 3;
      this.radioButtonOLEDBSQL.Text = "OLEDB SQL konekcija";
      this.radioButtonOLEDBSQL.UseVisualStyleBackColor = true;
      this.radioButtonOLEDBSQL.CheckedChanged += new System.EventHandler(this.radioButtonOLEDBSQL_CheckedChanged);
      // 
      // radioButtonSQLCON
      // 
      this.radioButtonSQLCON.AutoSize = true;
      this.radioButtonSQLCON.Checked = true;
      this.radioButtonSQLCON.Location = new System.Drawing.Point(18, 33);
      this.radioButtonSQLCON.Name = "radioButtonSQLCON";
      this.radioButtonSQLCON.Size = new System.Drawing.Size(95, 17);
      this.radioButtonSQLCON.TabIndex = 2;
      this.radioButtonSQLCON.TabStop = true;
      this.radioButtonSQLCON.Text = "SQL konekcija";
      this.radioButtonSQLCON.UseVisualStyleBackColor = true;
      this.radioButtonSQLCON.CheckedChanged += new System.EventHandler(this.radioButtonSQLCON_CheckedChanged);
      // 
      // label3
      // 
      this.label3.AutoSize = true;
      this.label3.Location = new System.Drawing.Point(176, 17);
      this.label3.Name = "label3";
      this.label3.Size = new System.Drawing.Size(91, 13);
      this.label3.TabIndex = 1;
      this.label3.Text = "ConnectionString:";
      // 
      // textBoxConnString
      // 
      this.textBoxConnString.Location = new System.Drawing.Point(179, 33);
      this.textBoxConnString.Multiline = true;
      this.textBoxConnString.Name = "textBoxConnString";
      this.textBoxConnString.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
      this.textBoxConnString.Size = new System.Drawing.Size(402, 76);
      this.textBoxConnString.TabIndex = 0;
      // 
      // groupBoxUpit
      // 
      this.groupBoxUpit.Controls.Add(this.textBoxUpit);
      this.groupBoxUpit.Controls.Add(this.label1);
      this.groupBoxUpit.Controls.Add(this.label2);
      this.groupBoxUpit.Controls.Add(this.listViewRezultat);
      this.groupBoxUpit.Location = new System.Drawing.Point(12, 184);
      this.groupBoxUpit.Name = "groupBoxUpit";
      this.groupBoxUpit.Size = new System.Drawing.Size(599, 299);
      this.groupBoxUpit.TabIndex = 6;
      this.groupBoxUpit.TabStop = false;
      // 
      // Upitnik
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.ClientSize = new System.Drawing.Size(629, 494);
      this.Controls.Add(this.groupBoxUpit);
      this.Controls.Add(this.groupBoxKonekcija);
      this.Name = "Upitnik";
      this.Text = "Query Manager";
      this.Load += new System.EventHandler(this.QueryManager_Load);
      this.groupBoxKonekcija.ResumeLayout(false);
      this.groupBoxKonekcija.PerformLayout();
      this.groupBoxUpit.ResumeLayout(false);
      this.groupBoxUpit.PerformLayout();
      this.ResumeLayout(false);

    }

    #endregion

    private System.Windows.Forms.TextBox textBoxUpit;
    private System.Windows.Forms.ListView listViewRezultat;
    private System.Windows.Forms.Button buttonExecute;
    private System.Windows.Forms.Label label1;
    private System.Windows.Forms.Label label2;
    private System.Windows.Forms.GroupBox groupBoxKonekcija;
    private System.Windows.Forms.Label label3;
    private System.Windows.Forms.TextBox textBoxConnString;
    private System.Windows.Forms.RadioButton radioButtonMSJET;
    private System.Windows.Forms.RadioButton radioButtonOLEDBSQL;
    private System.Windows.Forms.RadioButton radioButtonSQLCON;
    private System.Windows.Forms.GroupBox groupBoxUpit;
    private System.Windows.Forms.Button buttonClose;
    private System.Windows.Forms.Button buttonOpen;
    private System.Windows.Forms.Button buttonScalar;
    private System.Windows.Forms.Button buttonNonQuery;
  }
}


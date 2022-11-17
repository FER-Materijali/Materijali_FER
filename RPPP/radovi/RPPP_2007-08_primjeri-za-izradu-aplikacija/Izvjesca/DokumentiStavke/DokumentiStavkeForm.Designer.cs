namespace DokumentiStavke
{
  partial class DokumentiStavkeForm
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
      this.buttonIzvjestaj = new System.Windows.Forms.Button();
      this.reportViewer = new CrystalDecisions.Windows.Forms.CrystalReportViewer();
      this.comboBoxPartner = new System.Windows.Forms.ComboBox();
      this.listViewDokumenti = new System.Windows.Forms.ListView();
      this.columnHeader1 = new System.Windows.Forms.ColumnHeader();
      this.columnHeader2 = new System.Windows.Forms.ColumnHeader();
      this.columnHeader3 = new System.Windows.Forms.ColumnHeader();
      this.columnHeader4 = new System.Windows.Forms.ColumnHeader();
      this.buttonDokumenti = new System.Windows.Forms.Button();
      this.SuspendLayout();
      // 
      // buttonIzvjestaj
      // 
      this.buttonIzvjestaj.Anchor = System.Windows.Forms.AnchorStyles.Top;
      this.buttonIzvjestaj.Location = new System.Drawing.Point(467, 20);
      this.buttonIzvjestaj.Name = "buttonIzvjestaj";
      this.buttonIzvjestaj.Size = new System.Drawing.Size(144, 23);
      this.buttonIzvjestaj.TabIndex = 3;
      this.buttonIzvjestaj.Text = "Generiraj izvještaj";
      this.buttonIzvjestaj.UseVisualStyleBackColor = true;
      this.buttonIzvjestaj.Click += new System.EventHandler(this.buttonIzvjestaj_Click);
      // 
      // reportViewer
      // 
      this.reportViewer.ActiveViewIndex = -1;
      this.reportViewer.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                  | System.Windows.Forms.AnchorStyles.Left)
                  | System.Windows.Forms.AnchorStyles.Right)));
      this.reportViewer.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
      this.reportViewer.DisplayGroupTree = false;
      this.reportViewer.Location = new System.Drawing.Point(23, 260);
      this.reportViewer.Name = "reportViewer";
      this.reportViewer.SelectionFormula = "";
      this.reportViewer.Size = new System.Drawing.Size(588, 402);
      this.reportViewer.TabIndex = 4;
      this.reportViewer.ViewTimeSelectionFormula = "";
      // 
      // comboBoxPartner
      // 
      this.comboBoxPartner.Anchor = System.Windows.Forms.AnchorStyles.Top;
      this.comboBoxPartner.FormattingEnabled = true;
      this.comboBoxPartner.Location = new System.Drawing.Point(24, 22);
      this.comboBoxPartner.Name = "comboBoxPartner";
      this.comboBoxPartner.Size = new System.Drawing.Size(275, 21);
      this.comboBoxPartner.TabIndex = 5;
      // 
      // listViewDokumenti
      // 
      this.listViewDokumenti.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                  | System.Windows.Forms.AnchorStyles.Right)));
      this.listViewDokumenti.CheckBoxes = true;
      this.listViewDokumenti.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader1,
            this.columnHeader2,
            this.columnHeader3,
            this.columnHeader4});
      this.listViewDokumenti.Location = new System.Drawing.Point(24, 49);
      this.listViewDokumenti.MultiSelect = false;
      this.listViewDokumenti.Name = "listViewDokumenti";
      this.listViewDokumenti.Size = new System.Drawing.Size(587, 194);
      this.listViewDokumenti.TabIndex = 7;
      this.listViewDokumenti.UseCompatibleStateImageBehavior = false;
      this.listViewDokumenti.View = System.Windows.Forms.View.Details;
      // 
      // columnHeader1
      // 
      this.columnHeader1.Text = "Id dokumenta";
      this.columnHeader1.Width = 112;
      // 
      // columnHeader2
      // 
      this.columnHeader2.Text = "Broj dokumenta";
      this.columnHeader2.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
      this.columnHeader2.Width = 113;
      // 
      // columnHeader3
      // 
      this.columnHeader3.Text = "Datum";
      this.columnHeader3.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
      this.columnHeader3.Width = 129;
      // 
      // columnHeader4
      // 
      this.columnHeader4.Text = "Iznos";
      this.columnHeader4.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
      this.columnHeader4.Width = 119;
      // 
      // buttonDokumenti
      // 
      this.buttonDokumenti.Anchor = System.Windows.Forms.AnchorStyles.Top;
      this.buttonDokumenti.Location = new System.Drawing.Point(305, 20);
      this.buttonDokumenti.Name = "buttonDokumenti";
      this.buttonDokumenti.Size = new System.Drawing.Size(156, 23);
      this.buttonDokumenti.TabIndex = 8;
      this.buttonDokumenti.Text = "Prikaži dokumente";
      this.buttonDokumenti.UseVisualStyleBackColor = true;
      this.buttonDokumenti.Click += new System.EventHandler(this.buttonDokumenti_Click);
      // 
      // DokumentiStavkeForm
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.ClientSize = new System.Drawing.Size(635, 674);
      this.Controls.Add(this.buttonDokumenti);
      this.Controls.Add(this.listViewDokumenti);
      this.Controls.Add(this.comboBoxPartner);
      this.Controls.Add(this.reportViewer);
      this.Controls.Add(this.buttonIzvjestaj);
      this.Name = "DokumentiStavkeForm";
      this.Text = "Dokumenti i stavke";
      this.ResumeLayout(false);

    }

    #endregion

    private System.Windows.Forms.Button buttonIzvjestaj;
    private CrystalDecisions.Windows.Forms.CrystalReportViewer reportViewer;
    private System.Windows.Forms.ComboBox comboBoxPartner;
    private System.Windows.Forms.ListView listViewDokumenti;
    private System.Windows.Forms.ColumnHeader columnHeader1;
    private System.Windows.Forms.ColumnHeader columnHeader2;
    private System.Windows.Forms.ColumnHeader columnHeader3;
    private System.Windows.Forms.ColumnHeader columnHeader4;
    private System.Windows.Forms.Button buttonDokumenti;
  }
}


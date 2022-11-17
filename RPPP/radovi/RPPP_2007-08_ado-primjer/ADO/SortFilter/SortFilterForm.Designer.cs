namespace SortFilter
{
  partial class SortFilterForm
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
      System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(SortFilterForm));
      this.oleDbConnection1 = new System.Data.OleDb.OleDbConnection();
      this.oleDbSelectCommand1 = new System.Data.OleDb.OleDbCommand();
      this.oleDbDataAdapterMjesta = new System.Data.OleDb.OleDbDataAdapter();
      this.textBoxFilter = new System.Windows.Forms.TextBox();
      this.buttonFilter = new System.Windows.Forms.Button();
      this.groupBoxFilter = new System.Windows.Forms.GroupBox();
      this.buttonSelect = new System.Windows.Forms.Button();
      this.buttonFind = new System.Windows.Forms.Button();
      this.buttonAddFilter = new System.Windows.Forms.Button();
      this.textBoxUvjet = new System.Windows.Forms.TextBox();
      this.comboBoxColumns = new System.Windows.Forms.ComboBox();
      this.groupBoxSort = new System.Windows.Forms.GroupBox();
      this.textBoxSort = new System.Windows.Forms.TextBox();
      this.panel2 = new System.Windows.Forms.Panel();
      this.radioButtonUzlazno = new System.Windows.Forms.RadioButton();
      this.radioButtonSilazno = new System.Windows.Forms.RadioButton();
      this.panel1 = new System.Windows.Forms.Panel();
      this.radioButtonPostBrMjesta = new System.Windows.Forms.RadioButton();
      this.radioButtonNazMjesta = new System.Windows.Forms.RadioButton();
      this.radioButtonOznDrzave = new System.Windows.Forms.RadioButton();
      this.radioButtonNazDrzave = new System.Windows.Forms.RadioButton();
      this.buttonSort = new System.Windows.Forms.Button();
      this.drzavaBindingSource = new System.Windows.Forms.BindingSource(this.components);
      this.dataView = new System.Data.DataView();
      this.dataSetMjesta = new SortFilter.DataSetMjesta();
      this.dataGridView = new System.Windows.Forms.DataGridView();
      this.idMjestaDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
      this.nazMjestaDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
      this.postBrMjestaDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
      this.postNazMjestaDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
      this.nazDrzaveDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
      this.oznDrzaveDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
      this.iSO3DrzaveDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
      this.sifDrzaveDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
      this.groupBoxFilter.SuspendLayout();
      this.groupBoxSort.SuspendLayout();
      this.panel2.SuspendLayout();
      this.panel1.SuspendLayout();
      ((System.ComponentModel.ISupportInitialize)(this.drzavaBindingSource)).BeginInit();
      ((System.ComponentModel.ISupportInitialize)(this.dataView)).BeginInit();
      ((System.ComponentModel.ISupportInitialize)(this.dataSetMjesta)).BeginInit();
      ((System.ComponentModel.ISupportInitialize)(this.dataGridView)).BeginInit();
      this.SuspendLayout();
      // 
      // oleDbConnection1
      // 
      this.oleDbConnection1.ConnectionString = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=c:\\Projects\\Firma.mdb";
      // 
      // oleDbSelectCommand1
      // 
      this.oleDbSelectCommand1.CommandText = resources.GetString("oleDbSelectCommand1.CommandText");
      this.oleDbSelectCommand1.Connection = this.oleDbConnection1;
      // 
      // oleDbDataAdapterMjesta
      // 
      this.oleDbDataAdapterMjesta.SelectCommand = this.oleDbSelectCommand1;
      this.oleDbDataAdapterMjesta.TableMappings.AddRange(new System.Data.Common.DataTableMapping[] {
            new System.Data.Common.DataTableMapping("Table", "MjestoDrzava", new System.Data.Common.DataColumnMapping[] {
                        new System.Data.Common.DataColumnMapping("IdMjesta", "IdMjesta"),
                        new System.Data.Common.DataColumnMapping("NazMjesta", "NazMjesta"),
                        new System.Data.Common.DataColumnMapping("PostBrMjesta", "PostBrMjesta"),
                        new System.Data.Common.DataColumnMapping("PostNazMjesta", "PostNazMjesta"),
                        new System.Data.Common.DataColumnMapping("NazDrzave", "NazDrzave"),
                        new System.Data.Common.DataColumnMapping("OznDrzave", "OznDrzave"),
                        new System.Data.Common.DataColumnMapping("ISO3Drzave", "ISO3Drzave"),
                        new System.Data.Common.DataColumnMapping("SifDrzave", "SifDrzave")})});
      // 
      // textBoxFilter
      // 
      this.textBoxFilter.Location = new System.Drawing.Point(6, 114);
      this.textBoxFilter.Multiline = true;
      this.textBoxFilter.Name = "textBoxFilter";
      this.textBoxFilter.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
      this.textBoxFilter.Size = new System.Drawing.Size(266, 65);
      this.textBoxFilter.TabIndex = 1;
      // 
      // buttonFilter
      // 
      this.buttonFilter.Location = new System.Drawing.Point(197, 75);
      this.buttonFilter.Name = "buttonFilter";
      this.buttonFilter.Size = new System.Drawing.Size(75, 23);
      this.buttonFilter.TabIndex = 2;
      this.buttonFilter.Text = "Filter";
      this.buttonFilter.UseVisualStyleBackColor = true;
      this.buttonFilter.Click += new System.EventHandler(this.buttonFilter_Click);
      // 
      // groupBoxFilter
      // 
      this.groupBoxFilter.Anchor = System.Windows.Forms.AnchorStyles.Top;
      this.groupBoxFilter.Controls.Add(this.buttonSelect);
      this.groupBoxFilter.Controls.Add(this.buttonFind);
      this.groupBoxFilter.Controls.Add(this.buttonAddFilter);
      this.groupBoxFilter.Controls.Add(this.textBoxUvjet);
      this.groupBoxFilter.Controls.Add(this.comboBoxColumns);
      this.groupBoxFilter.Controls.Add(this.textBoxFilter);
      this.groupBoxFilter.Controls.Add(this.buttonFilter);
      this.groupBoxFilter.Location = new System.Drawing.Point(25, 20);
      this.groupBoxFilter.Name = "groupBoxFilter";
      this.groupBoxFilter.Size = new System.Drawing.Size(278, 185);
      this.groupBoxFilter.TabIndex = 7;
      this.groupBoxFilter.TabStop = false;
      this.groupBoxFilter.Text = "Filter";
      // 
      // buttonSelect
      // 
      this.buttonSelect.Location = new System.Drawing.Point(100, 75);
      this.buttonSelect.Name = "buttonSelect";
      this.buttonSelect.Size = new System.Drawing.Size(75, 23);
      this.buttonSelect.TabIndex = 11;
      this.buttonSelect.Text = "Select";
      this.buttonSelect.UseVisualStyleBackColor = true;
      this.buttonSelect.Click += new System.EventHandler(this.buttonSelect_Click);
      // 
      // buttonFind
      // 
      this.buttonFind.Location = new System.Drawing.Point(6, 75);
      this.buttonFind.Name = "buttonFind";
      this.buttonFind.Size = new System.Drawing.Size(75, 23);
      this.buttonFind.TabIndex = 10;
      this.buttonFind.Text = "Find";
      this.buttonFind.UseVisualStyleBackColor = true;
      this.buttonFind.Click += new System.EventHandler(this.buttonFind_Click);
      // 
      // buttonAddFilter
      // 
      this.buttonAddFilter.Location = new System.Drawing.Point(240, 26);
      this.buttonAddFilter.Name = "buttonAddFilter";
      this.buttonAddFilter.Size = new System.Drawing.Size(32, 23);
      this.buttonAddFilter.TabIndex = 9;
      this.buttonAddFilter.Text = "*";
      this.buttonAddFilter.UseVisualStyleBackColor = true;
      this.buttonAddFilter.Click += new System.EventHandler(this.buttonAddFilter_Click);
      // 
      // textBoxUvjet
      // 
      this.textBoxUvjet.Location = new System.Drawing.Point(133, 29);
      this.textBoxUvjet.Name = "textBoxUvjet";
      this.textBoxUvjet.Size = new System.Drawing.Size(100, 20);
      this.textBoxUvjet.TabIndex = 8;
      // 
      // comboBoxColumns
      // 
      this.comboBoxColumns.FormattingEnabled = true;
      this.comboBoxColumns.Location = new System.Drawing.Point(6, 29);
      this.comboBoxColumns.Name = "comboBoxColumns";
      this.comboBoxColumns.Size = new System.Drawing.Size(121, 21);
      this.comboBoxColumns.TabIndex = 7;
      // 
      // groupBoxSort
      // 
      this.groupBoxSort.Anchor = System.Windows.Forms.AnchorStyles.Top;
      this.groupBoxSort.Controls.Add(this.textBoxSort);
      this.groupBoxSort.Controls.Add(this.panel2);
      this.groupBoxSort.Controls.Add(this.panel1);
      this.groupBoxSort.Controls.Add(this.buttonSort);
      this.groupBoxSort.Location = new System.Drawing.Point(309, 20);
      this.groupBoxSort.Name = "groupBoxSort";
      this.groupBoxSort.Size = new System.Drawing.Size(287, 185);
      this.groupBoxSort.TabIndex = 8;
      this.groupBoxSort.TabStop = false;
      this.groupBoxSort.Text = "Sort";
      // 
      // textBoxSort
      // 
      this.textBoxSort.Location = new System.Drawing.Point(6, 114);
      this.textBoxSort.Multiline = true;
      this.textBoxSort.Name = "textBoxSort";
      this.textBoxSort.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
      this.textBoxSort.Size = new System.Drawing.Size(275, 65);
      this.textBoxSort.TabIndex = 10;
      // 
      // panel2
      // 
      this.panel2.Controls.Add(this.radioButtonUzlazno);
      this.panel2.Controls.Add(this.radioButtonSilazno);
      this.panel2.Location = new System.Drawing.Point(206, 16);
      this.panel2.Name = "panel2";
      this.panel2.Size = new System.Drawing.Size(75, 58);
      this.panel2.TabIndex = 10;
      // 
      // radioButtonUzlazno
      // 
      this.radioButtonUzlazno.AutoSize = true;
      this.radioButtonUzlazno.Checked = true;
      this.radioButtonUzlazno.Location = new System.Drawing.Point(7, 13);
      this.radioButtonUzlazno.Name = "radioButtonUzlazno";
      this.radioButtonUzlazno.Size = new System.Drawing.Size(63, 17);
      this.radioButtonUzlazno.TabIndex = 7;
      this.radioButtonUzlazno.TabStop = true;
      this.radioButtonUzlazno.Text = "Uzlazno";
      this.radioButtonUzlazno.UseVisualStyleBackColor = true;
      // 
      // radioButtonSilazno
      // 
      this.radioButtonSilazno.AutoSize = true;
      this.radioButtonSilazno.Location = new System.Drawing.Point(7, 33);
      this.radioButtonSilazno.Name = "radioButtonSilazno";
      this.radioButtonSilazno.Size = new System.Drawing.Size(59, 17);
      this.radioButtonSilazno.TabIndex = 8;
      this.radioButtonSilazno.Text = "Silazno";
      this.radioButtonSilazno.UseVisualStyleBackColor = true;
      // 
      // panel1
      // 
      this.panel1.Controls.Add(this.radioButtonPostBrMjesta);
      this.panel1.Controls.Add(this.radioButtonNazMjesta);
      this.panel1.Controls.Add(this.radioButtonOznDrzave);
      this.panel1.Controls.Add(this.radioButtonNazDrzave);
      this.panel1.Location = new System.Drawing.Point(6, 16);
      this.panel1.Name = "panel1";
      this.panel1.Size = new System.Drawing.Size(194, 58);
      this.panel1.TabIndex = 13;
      // 
      // radioButtonPostBrMjesta
      // 
      this.radioButtonPostBrMjesta.AutoSize = true;
      this.radioButtonPostBrMjesta.Location = new System.Drawing.Point(14, 33);
      this.radioButtonPostBrMjesta.Name = "radioButtonPostBrMjesta";
      this.radioButtonPostBrMjesta.Size = new System.Drawing.Size(87, 17);
      this.radioButtonPostBrMjesta.TabIndex = 12;
      this.radioButtonPostBrMjesta.Text = "PostBrMjesta";
      this.radioButtonPostBrMjesta.UseVisualStyleBackColor = true;
      this.radioButtonPostBrMjesta.CheckedChanged += new System.EventHandler(this.radioSort_CheckedChanged);
      // 
      // radioButtonNazMjesta
      // 
      this.radioButtonNazMjesta.AutoSize = true;
      this.radioButtonNazMjesta.Checked = true;
      this.radioButtonNazMjesta.Location = new System.Drawing.Point(14, 13);
      this.radioButtonNazMjesta.Name = "radioButtonNazMjesta";
      this.radioButtonNazMjesta.Size = new System.Drawing.Size(75, 17);
      this.radioButtonNazMjesta.TabIndex = 9;
      this.radioButtonNazMjesta.TabStop = true;
      this.radioButtonNazMjesta.Text = "NazMjesta";
      this.radioButtonNazMjesta.UseVisualStyleBackColor = true;
      this.radioButtonNazMjesta.CheckedChanged += new System.EventHandler(this.radioSort_CheckedChanged);
      // 
      // radioButtonOznDrzave
      // 
      this.radioButtonOznDrzave.AutoSize = true;
      this.radioButtonOznDrzave.Location = new System.Drawing.Point(104, 33);
      this.radioButtonOznDrzave.Name = "radioButtonOznDrzave";
      this.radioButtonOznDrzave.Size = new System.Drawing.Size(78, 17);
      this.radioButtonOznDrzave.TabIndex = 11;
      this.radioButtonOznDrzave.Text = "OznDrzave";
      this.radioButtonOznDrzave.UseVisualStyleBackColor = true;
      this.radioButtonOznDrzave.CheckedChanged += new System.EventHandler(this.radioSort_CheckedChanged);
      // 
      // radioButtonNazDrzave
      // 
      this.radioButtonNazDrzave.AutoSize = true;
      this.radioButtonNazDrzave.Location = new System.Drawing.Point(104, 13);
      this.radioButtonNazDrzave.Name = "radioButtonNazDrzave";
      this.radioButtonNazDrzave.Size = new System.Drawing.Size(78, 17);
      this.radioButtonNazDrzave.TabIndex = 10;
      this.radioButtonNazDrzave.Text = "NazDrzave";
      this.radioButtonNazDrzave.UseVisualStyleBackColor = true;
      this.radioButtonNazDrzave.CheckedChanged += new System.EventHandler(this.radioSort_CheckedChanged);
      // 
      // buttonSort
      // 
      this.buttonSort.Location = new System.Drawing.Point(206, 80);
      this.buttonSort.Name = "buttonSort";
      this.buttonSort.Size = new System.Drawing.Size(75, 23);
      this.buttonSort.TabIndex = 2;
      this.buttonSort.Text = "Sort";
      this.buttonSort.UseVisualStyleBackColor = true;
      this.buttonSort.Click += new System.EventHandler(this.buttonSort_Click);
      // 
      // drzavaBindingSource
      // 
      this.drzavaBindingSource.DataSource = this.dataView;
      // 
      // dataView
      // 
      this.dataView.Table = this.dataSetMjesta.MjestoDrzava;
      // 
      // dataSetMjesta
      // 
      this.dataSetMjesta.DataSetName = "DataSetMjesta";
      this.dataSetMjesta.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
      // 
      // dataGridView
      // 
      this.dataGridView.AllowUserToAddRows = false;
      this.dataGridView.AllowUserToDeleteRows = false;
      this.dataGridView.AutoGenerateColumns = false;
      this.dataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
      this.dataGridView.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.idMjestaDataGridViewTextBoxColumn,
            this.nazMjestaDataGridViewTextBoxColumn,
            this.postBrMjestaDataGridViewTextBoxColumn,
            this.postNazMjestaDataGridViewTextBoxColumn,
            this.nazDrzaveDataGridViewTextBoxColumn,
            this.oznDrzaveDataGridViewTextBoxColumn,
            this.iSO3DrzaveDataGridViewTextBoxColumn,
            this.sifDrzaveDataGridViewTextBoxColumn});
      this.dataGridView.DataSource = this.dataView;
      this.dataGridView.Location = new System.Drawing.Point(25, 220);
      this.dataGridView.Name = "dataGridView";
      this.dataGridView.ReadOnly = true;
      this.dataGridView.Size = new System.Drawing.Size(571, 150);
      this.dataGridView.TabIndex = 9;
      // 
      // idMjestaDataGridViewTextBoxColumn
      // 
      this.idMjestaDataGridViewTextBoxColumn.DataPropertyName = "IdMjesta";
      this.idMjestaDataGridViewTextBoxColumn.HeaderText = "IdMjesta";
      this.idMjestaDataGridViewTextBoxColumn.Name = "idMjestaDataGridViewTextBoxColumn";
      this.idMjestaDataGridViewTextBoxColumn.ReadOnly = true;
      // 
      // nazMjestaDataGridViewTextBoxColumn
      // 
      this.nazMjestaDataGridViewTextBoxColumn.DataPropertyName = "NazMjesta";
      this.nazMjestaDataGridViewTextBoxColumn.HeaderText = "NazMjesta";
      this.nazMjestaDataGridViewTextBoxColumn.Name = "nazMjestaDataGridViewTextBoxColumn";
      this.nazMjestaDataGridViewTextBoxColumn.ReadOnly = true;
      // 
      // postBrMjestaDataGridViewTextBoxColumn
      // 
      this.postBrMjestaDataGridViewTextBoxColumn.DataPropertyName = "PostBrMjesta";
      this.postBrMjestaDataGridViewTextBoxColumn.HeaderText = "PostBrMjesta";
      this.postBrMjestaDataGridViewTextBoxColumn.Name = "postBrMjestaDataGridViewTextBoxColumn";
      this.postBrMjestaDataGridViewTextBoxColumn.ReadOnly = true;
      // 
      // postNazMjestaDataGridViewTextBoxColumn
      // 
      this.postNazMjestaDataGridViewTextBoxColumn.DataPropertyName = "PostNazMjesta";
      this.postNazMjestaDataGridViewTextBoxColumn.HeaderText = "PostNazMjesta";
      this.postNazMjestaDataGridViewTextBoxColumn.Name = "postNazMjestaDataGridViewTextBoxColumn";
      this.postNazMjestaDataGridViewTextBoxColumn.ReadOnly = true;
      // 
      // nazDrzaveDataGridViewTextBoxColumn
      // 
      this.nazDrzaveDataGridViewTextBoxColumn.DataPropertyName = "NazDrzave";
      this.nazDrzaveDataGridViewTextBoxColumn.HeaderText = "NazDrzave";
      this.nazDrzaveDataGridViewTextBoxColumn.Name = "nazDrzaveDataGridViewTextBoxColumn";
      this.nazDrzaveDataGridViewTextBoxColumn.ReadOnly = true;
      // 
      // oznDrzaveDataGridViewTextBoxColumn
      // 
      this.oznDrzaveDataGridViewTextBoxColumn.DataPropertyName = "OznDrzave";
      this.oznDrzaveDataGridViewTextBoxColumn.HeaderText = "OznDrzave";
      this.oznDrzaveDataGridViewTextBoxColumn.Name = "oznDrzaveDataGridViewTextBoxColumn";
      this.oznDrzaveDataGridViewTextBoxColumn.ReadOnly = true;
      // 
      // iSO3DrzaveDataGridViewTextBoxColumn
      // 
      this.iSO3DrzaveDataGridViewTextBoxColumn.DataPropertyName = "ISO3Drzave";
      this.iSO3DrzaveDataGridViewTextBoxColumn.HeaderText = "ISO3Drzave";
      this.iSO3DrzaveDataGridViewTextBoxColumn.Name = "iSO3DrzaveDataGridViewTextBoxColumn";
      this.iSO3DrzaveDataGridViewTextBoxColumn.ReadOnly = true;
      // 
      // sifDrzaveDataGridViewTextBoxColumn
      // 
      this.sifDrzaveDataGridViewTextBoxColumn.DataPropertyName = "SifDrzave";
      this.sifDrzaveDataGridViewTextBoxColumn.HeaderText = "SifDrzave";
      this.sifDrzaveDataGridViewTextBoxColumn.Name = "sifDrzaveDataGridViewTextBoxColumn";
      this.sifDrzaveDataGridViewTextBoxColumn.ReadOnly = true;
      // 
      // SortFilterForm
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.ClientSize = new System.Drawing.Size(613, 395);
      this.Controls.Add(this.dataGridView);
      this.Controls.Add(this.groupBoxSort);
      this.Controls.Add(this.groupBoxFilter);
      this.Name = "SortFilterForm";
      this.Text = "Sort & Filter";
      this.Load += new System.EventHandler(this.SortFilterForm_Load);
      this.groupBoxFilter.ResumeLayout(false);
      this.groupBoxFilter.PerformLayout();
      this.groupBoxSort.ResumeLayout(false);
      this.groupBoxSort.PerformLayout();
      this.panel2.ResumeLayout(false);
      this.panel2.PerformLayout();
      this.panel1.ResumeLayout(false);
      this.panel1.PerformLayout();
      ((System.ComponentModel.ISupportInitialize)(this.drzavaBindingSource)).EndInit();
      ((System.ComponentModel.ISupportInitialize)(this.dataView)).EndInit();
      ((System.ComponentModel.ISupportInitialize)(this.dataSetMjesta)).EndInit();
      ((System.ComponentModel.ISupportInitialize)(this.dataGridView)).EndInit();
      this.ResumeLayout(false);

    }

    #endregion

    private System.Data.OleDb.OleDbConnection oleDbConnection1;
    private System.Data.OleDb.OleDbCommand oleDbSelectCommand1;
    private System.Data.OleDb.OleDbDataAdapter oleDbDataAdapterMjesta;
    private System.Windows.Forms.TextBox textBoxFilter;
    private System.Windows.Forms.Button buttonFilter;
    private System.Windows.Forms.GroupBox groupBoxFilter;
    private System.Windows.Forms.GroupBox groupBoxSort;
    private System.Windows.Forms.RadioButton radioButtonSilazno;
    private System.Windows.Forms.RadioButton radioButtonUzlazno;
    private System.Windows.Forms.Button buttonSort;
    private System.Windows.Forms.RadioButton radioButtonOznDrzave;
    private System.Windows.Forms.RadioButton radioButtonNazDrzave;
    private System.Windows.Forms.RadioButton radioButtonNazMjesta;
    private System.Windows.Forms.RadioButton radioButtonPostBrMjesta;
    private System.Windows.Forms.Panel panel1;
    private System.Windows.Forms.Panel panel2;
    private DataSetMjesta dataSetMjesta;
    private System.Windows.Forms.BindingSource drzavaBindingSource;
    private System.Windows.Forms.ComboBox comboBoxColumns;
    private System.Windows.Forms.TextBox textBoxSort;
    private System.Windows.Forms.Button buttonAddFilter;
    private System.Windows.Forms.TextBox textBoxUvjet;
    private System.Windows.Forms.Button buttonFind;
    private System.Windows.Forms.DataGridView dataGridView;
    private System.Data.DataView dataView;
    private System.Windows.Forms.DataGridViewTextBoxColumn idMjestaDataGridViewTextBoxColumn;
    private System.Windows.Forms.DataGridViewTextBoxColumn nazMjestaDataGridViewTextBoxColumn;
    private System.Windows.Forms.DataGridViewTextBoxColumn postBrMjestaDataGridViewTextBoxColumn;
    private System.Windows.Forms.DataGridViewTextBoxColumn postNazMjestaDataGridViewTextBoxColumn;
    private System.Windows.Forms.DataGridViewTextBoxColumn nazDrzaveDataGridViewTextBoxColumn;
    private System.Windows.Forms.DataGridViewTextBoxColumn oznDrzaveDataGridViewTextBoxColumn;
    private System.Windows.Forms.DataGridViewTextBoxColumn iSO3DrzaveDataGridViewTextBoxColumn;
    private System.Windows.Forms.DataGridViewTextBoxColumn sifDrzaveDataGridViewTextBoxColumn;
    private System.Windows.Forms.Button buttonSelect;
  }
}


namespace DebeliKlijent
{
  partial class FormDebeli
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
      System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormDebeli));
      this.sqlSelectCommand1 = new System.Data.SqlClient.SqlCommand();
      this.sqlConnection1 = new System.Data.SqlClient.SqlConnection();
      this.sqlDataAdapterPromet = new System.Data.SqlClient.SqlDataAdapter();
      this.dataSetDebeli = new DebeliKlijent.DataSetDebeli();
      this.prometPartneraBindingSource = new System.Windows.Forms.BindingSource(this.components);
      this.splitContainer1 = new System.Windows.Forms.SplitContainer();
      this.dataGridViewPromet = new System.Windows.Forms.DataGridView();
      this.idPartneraDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
      this.nazivDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
      this.brojDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
      this.prometDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
      this.dataGridViewDokument = new System.Windows.Forms.DataGridView();
      ((System.ComponentModel.ISupportInitialize)(this.dataSetDebeli)).BeginInit();
      ((System.ComponentModel.ISupportInitialize)(this.prometPartneraBindingSource)).BeginInit();
      this.splitContainer1.Panel1.SuspendLayout();
      this.splitContainer1.Panel2.SuspendLayout();
      this.splitContainer1.SuspendLayout();
      ((System.ComponentModel.ISupportInitialize)(this.dataGridViewPromet)).BeginInit();
      ((System.ComponentModel.ISupportInitialize)(this.dataGridViewDokument)).BeginInit();
      this.SuspendLayout();
      // 
      // sqlSelectCommand1
      // 
      this.sqlSelectCommand1.CommandText = resources.GetString("sqlSelectCommand1.CommandText");
      this.sqlSelectCommand1.Connection = this.sqlConnection1;
      // 
      // sqlConnection1
      // 
      this.sqlConnection1.ConnectionString = "Data Source=KLODOVIK\\SQL05;Initial Catalog=Firma;Integrated Security=True";
      this.sqlConnection1.FireInfoMessageEventOnUserErrors = false;
      // 
      // sqlDataAdapterPromet
      // 
      this.sqlDataAdapterPromet.SelectCommand = this.sqlSelectCommand1;
      this.sqlDataAdapterPromet.TableMappings.AddRange(new System.Data.Common.DataTableMapping[] {
            new System.Data.Common.DataTableMapping("Table", "Dokument", new System.Data.Common.DataColumnMapping[] {
                        new System.Data.Common.DataColumnMapping("IdPartnera", "IdPartnera"),
                        new System.Data.Common.DataColumnMapping("Naziv", "Naziv"),
                        new System.Data.Common.DataColumnMapping("Broj", "Broj"),
                        new System.Data.Common.DataColumnMapping("Promet", "Promet")})});
      // 
      // dataSetDebeli
      // 
      this.dataSetDebeli.DataSetName = "DataSetDebeli";
      this.dataSetDebeli.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
      // 
      // prometPartneraBindingSource
      // 
      this.prometPartneraBindingSource.DataMember = "PrometPartnera";
      this.prometPartneraBindingSource.DataSource = this.dataSetDebeli;
      // 
      // splitContainer1
      // 
      this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
      this.splitContainer1.Location = new System.Drawing.Point(0, 0);
      this.splitContainer1.Name = "splitContainer1";
      this.splitContainer1.Orientation = System.Windows.Forms.Orientation.Horizontal;
      // 
      // splitContainer1.Panel1
      // 
      this.splitContainer1.Panel1.Controls.Add(this.dataGridViewPromet);
      // 
      // splitContainer1.Panel2
      // 
      this.splitContainer1.Panel2.Controls.Add(this.dataGridViewDokument);
      this.splitContainer1.Size = new System.Drawing.Size(588, 394);
      this.splitContainer1.SplitterDistance = 197;
      this.splitContainer1.TabIndex = 1;
      // 
      // dataGridViewPromet
      // 
      this.dataGridViewPromet.AllowUserToAddRows = false;
      this.dataGridViewPromet.AllowUserToDeleteRows = false;
      this.dataGridViewPromet.AutoGenerateColumns = false;
      this.dataGridViewPromet.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
      this.dataGridViewPromet.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.idPartneraDataGridViewTextBoxColumn,
            this.nazivDataGridViewTextBoxColumn,
            this.brojDataGridViewTextBoxColumn,
            this.prometDataGridViewTextBoxColumn});
      this.dataGridViewPromet.DataSource = this.prometPartneraBindingSource;
      this.dataGridViewPromet.Dock = System.Windows.Forms.DockStyle.Fill;
      this.dataGridViewPromet.Location = new System.Drawing.Point(0, 0);
      this.dataGridViewPromet.Name = "dataGridViewPromet";
      this.dataGridViewPromet.ReadOnly = true;
      this.dataGridViewPromet.Size = new System.Drawing.Size(588, 197);
      this.dataGridViewPromet.TabIndex = 1;
      this.dataGridViewPromet.CurrentCellChanged += new System.EventHandler(this.dataGridViewPromet_CurrentCellChanged);
      // 
      // idPartneraDataGridViewTextBoxColumn
      // 
      this.idPartneraDataGridViewTextBoxColumn.DataPropertyName = "IdPartnera";
      this.idPartneraDataGridViewTextBoxColumn.HeaderText = "IdPartnera";
      this.idPartneraDataGridViewTextBoxColumn.Name = "idPartneraDataGridViewTextBoxColumn";
      this.idPartneraDataGridViewTextBoxColumn.ReadOnly = true;
      // 
      // nazivDataGridViewTextBoxColumn
      // 
      this.nazivDataGridViewTextBoxColumn.DataPropertyName = "Naziv";
      this.nazivDataGridViewTextBoxColumn.HeaderText = "Naziv";
      this.nazivDataGridViewTextBoxColumn.Name = "nazivDataGridViewTextBoxColumn";
      this.nazivDataGridViewTextBoxColumn.ReadOnly = true;
      // 
      // brojDataGridViewTextBoxColumn
      // 
      this.brojDataGridViewTextBoxColumn.DataPropertyName = "Broj";
      this.brojDataGridViewTextBoxColumn.HeaderText = "Broj";
      this.brojDataGridViewTextBoxColumn.Name = "brojDataGridViewTextBoxColumn";
      this.brojDataGridViewTextBoxColumn.ReadOnly = true;
      // 
      // prometDataGridViewTextBoxColumn
      // 
      this.prometDataGridViewTextBoxColumn.DataPropertyName = "Promet";
      this.prometDataGridViewTextBoxColumn.HeaderText = "Promet";
      this.prometDataGridViewTextBoxColumn.Name = "prometDataGridViewTextBoxColumn";
      this.prometDataGridViewTextBoxColumn.ReadOnly = true;
      // 
      // dataGridViewDokument
      // 
      this.dataGridViewDokument.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
      this.dataGridViewDokument.Dock = System.Windows.Forms.DockStyle.Fill;
      this.dataGridViewDokument.Location = new System.Drawing.Point(0, 0);
      this.dataGridViewDokument.Name = "dataGridViewDokument";
      this.dataGridViewDokument.Size = new System.Drawing.Size(588, 193);
      this.dataGridViewDokument.TabIndex = 0;
      // 
      // FormDebeli
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.ClientSize = new System.Drawing.Size(588, 394);
      this.Controls.Add(this.splitContainer1);
      this.Name = "FormDebeli";
      this.Text = "Debeli klijent";
      this.Load += new System.EventHandler(this.FormDebeli_Load);
      ((System.ComponentModel.ISupportInitialize)(this.dataSetDebeli)).EndInit();
      ((System.ComponentModel.ISupportInitialize)(this.prometPartneraBindingSource)).EndInit();
      this.splitContainer1.Panel1.ResumeLayout(false);
      this.splitContainer1.Panel2.ResumeLayout(false);
      this.splitContainer1.ResumeLayout(false);
      ((System.ComponentModel.ISupportInitialize)(this.dataGridViewPromet)).EndInit();
      ((System.ComponentModel.ISupportInitialize)(this.dataGridViewDokument)).EndInit();
      this.ResumeLayout(false);

    }

    #endregion

    private System.Data.SqlClient.SqlCommand sqlSelectCommand1;
    private System.Data.SqlClient.SqlConnection sqlConnection1;
    private System.Data.SqlClient.SqlDataAdapter sqlDataAdapterPromet;
    private DataSetDebeli dataSetDebeli;
    private System.Windows.Forms.BindingSource prometPartneraBindingSource;
    private System.Windows.Forms.SplitContainer splitContainer1;
    private System.Windows.Forms.DataGridView dataGridViewPromet;
    private System.Windows.Forms.DataGridViewTextBoxColumn idPartneraDataGridViewTextBoxColumn;
    private System.Windows.Forms.DataGridViewTextBoxColumn nazivDataGridViewTextBoxColumn;
    private System.Windows.Forms.DataGridViewTextBoxColumn brojDataGridViewTextBoxColumn;
    private System.Windows.Forms.DataGridViewTextBoxColumn prometDataGridViewTextBoxColumn;
    private System.Windows.Forms.DataGridView dataGridViewDokument;
  }
}


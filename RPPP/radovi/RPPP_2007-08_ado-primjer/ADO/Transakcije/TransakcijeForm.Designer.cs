namespace Transakcije
{
  partial class TransakcijeForm
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
      System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(TransakcijeForm));
      this.buttonBegin = new System.Windows.Forms.Button();
      this.oleDbConnection = new System.Data.OleDb.OleDbConnection();
      this.buttonRollback = new System.Windows.Forms.Button();
      this.buttonCommit = new System.Windows.Forms.Button();
      this.oleDbSelectCommand1 = new System.Data.OleDb.OleDbCommand();
      this.oleDbInsertCommand1 = new System.Data.OleDb.OleDbCommand();
      this.oleDbUpdateCommand1 = new System.Data.OleDb.OleDbCommand();
      this.oleDbDeleteCommand1 = new System.Data.OleDb.OleDbCommand();
      this.daPartner = new System.Data.OleDb.OleDbDataAdapter();
      this.oleDbSelectCommand2 = new System.Data.OleDb.OleDbCommand();
      this.oleDbInsertCommand2 = new System.Data.OleDb.OleDbCommand();
      this.oleDbUpdateCommand2 = new System.Data.OleDb.OleDbCommand();
      this.oleDbDeleteCommand2 = new System.Data.OleDb.OleDbCommand();
      this.daTvrtka = new System.Data.OleDb.OleDbDataAdapter();
      this.firmaDataSet = new Transakcije.FirmaDataSet();
      this.textSQL = new System.Windows.Forms.TextBox();
      this.buttonExecute = new System.Windows.Forms.Button();
      ((System.ComponentModel.ISupportInitialize)(this.firmaDataSet)).BeginInit();
      this.SuspendLayout();
      // 
      // buttonBegin
      // 
      this.buttonBegin.Location = new System.Drawing.Point(394, 12);
      this.buttonBegin.Name = "buttonBegin";
      this.buttonBegin.Size = new System.Drawing.Size(75, 23);
      this.buttonBegin.TabIndex = 1;
      this.buttonBegin.Text = "Begin";
      this.buttonBegin.UseVisualStyleBackColor = true;
      this.buttonBegin.Click += new System.EventHandler(this.buttonBegin_Click);
      // 
      // oleDbConnection
      // 
      this.oleDbConnection.ConnectionString = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=C:\\Projects\\Firma.mdb";
      // 
      // buttonRollback
      // 
      this.buttonRollback.Location = new System.Drawing.Point(394, 126);
      this.buttonRollback.Name = "buttonRollback";
      this.buttonRollback.Size = new System.Drawing.Size(75, 23);
      this.buttonRollback.TabIndex = 2;
      this.buttonRollback.Text = "Rollback";
      this.buttonRollback.UseVisualStyleBackColor = true;
      this.buttonRollback.Click += new System.EventHandler(this.buttonRollback_Click);
      // 
      // buttonCommit
      // 
      this.buttonCommit.Location = new System.Drawing.Point(394, 88);
      this.buttonCommit.Name = "buttonCommit";
      this.buttonCommit.Size = new System.Drawing.Size(75, 23);
      this.buttonCommit.TabIndex = 4;
      this.buttonCommit.Text = "Commit";
      this.buttonCommit.UseVisualStyleBackColor = true;
      this.buttonCommit.Click += new System.EventHandler(this.buttonCommit_Click);
      // 
      // oleDbSelectCommand1
      // 
      this.oleDbSelectCommand1.CommandText = "SELECT     *\r\nFROM         Partner";
      this.oleDbSelectCommand1.Connection = this.oleDbConnection;
      // 
      // oleDbInsertCommand1
      // 
      this.oleDbInsertCommand1.CommandText = "INSERT INTO `Partner` (`TipPartnera`, `IdMjestaPartnera`, `AdrPartnera`, `IdMjest" +
          "aIsporuke`, `AdrIsporuke`) VALUES (?, ?, ?, ?, ?)";
      this.oleDbInsertCommand1.Connection = this.oleDbConnection;
      this.oleDbInsertCommand1.Parameters.AddRange(new System.Data.OleDb.OleDbParameter[] {
            new System.Data.OleDb.OleDbParameter("TipPartnera", System.Data.OleDb.OleDbType.VarWChar, 0, "TipPartnera"),
            new System.Data.OleDb.OleDbParameter("IdMjestaPartnera", System.Data.OleDb.OleDbType.Integer, 0, "IdMjestaPartnera"),
            new System.Data.OleDb.OleDbParameter("AdrPartnera", System.Data.OleDb.OleDbType.VarWChar, 0, "AdrPartnera"),
            new System.Data.OleDb.OleDbParameter("IdMjestaIsporuke", System.Data.OleDb.OleDbType.Integer, 0, "IdMjestaIsporuke"),
            new System.Data.OleDb.OleDbParameter("AdrIsporuke", System.Data.OleDb.OleDbType.VarWChar, 0, "AdrIsporuke")});
      // 
      // oleDbUpdateCommand1
      // 
      this.oleDbUpdateCommand1.CommandText = resources.GetString("oleDbUpdateCommand1.CommandText");
      this.oleDbUpdateCommand1.Connection = this.oleDbConnection;
      this.oleDbUpdateCommand1.Parameters.AddRange(new System.Data.OleDb.OleDbParameter[] {
            new System.Data.OleDb.OleDbParameter("TipPartnera", System.Data.OleDb.OleDbType.VarWChar, 0, "TipPartnera"),
            new System.Data.OleDb.OleDbParameter("IdMjestaPartnera", System.Data.OleDb.OleDbType.Integer, 0, "IdMjestaPartnera"),
            new System.Data.OleDb.OleDbParameter("AdrPartnera", System.Data.OleDb.OleDbType.VarWChar, 0, "AdrPartnera"),
            new System.Data.OleDb.OleDbParameter("IdMjestaIsporuke", System.Data.OleDb.OleDbType.Integer, 0, "IdMjestaIsporuke"),
            new System.Data.OleDb.OleDbParameter("AdrIsporuke", System.Data.OleDb.OleDbType.VarWChar, 0, "AdrIsporuke"),
            new System.Data.OleDb.OleDbParameter("Original_IdPartnera", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "IdPartnera", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("IsNull_TipPartnera", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, ((byte)(0)), ((byte)(0)), "TipPartnera", System.Data.DataRowVersion.Original, true, null),
            new System.Data.OleDb.OleDbParameter("Original_TipPartnera", System.Data.OleDb.OleDbType.VarWChar, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "TipPartnera", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("IsNull_IdMjestaPartnera", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, ((byte)(0)), ((byte)(0)), "IdMjestaPartnera", System.Data.DataRowVersion.Original, true, null),
            new System.Data.OleDb.OleDbParameter("Original_IdMjestaPartnera", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "IdMjestaPartnera", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("IsNull_AdrPartnera", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, ((byte)(0)), ((byte)(0)), "AdrPartnera", System.Data.DataRowVersion.Original, true, null),
            new System.Data.OleDb.OleDbParameter("Original_AdrPartnera", System.Data.OleDb.OleDbType.VarWChar, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "AdrPartnera", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("IsNull_IdMjestaIsporuke", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, ((byte)(0)), ((byte)(0)), "IdMjestaIsporuke", System.Data.DataRowVersion.Original, true, null),
            new System.Data.OleDb.OleDbParameter("Original_IdMjestaIsporuke", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "IdMjestaIsporuke", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("IsNull_AdrIsporuke", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, ((byte)(0)), ((byte)(0)), "AdrIsporuke", System.Data.DataRowVersion.Original, true, null),
            new System.Data.OleDb.OleDbParameter("Original_AdrIsporuke", System.Data.OleDb.OleDbType.VarWChar, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "AdrIsporuke", System.Data.DataRowVersion.Original, null)});
      // 
      // oleDbDeleteCommand1
      // 
      this.oleDbDeleteCommand1.CommandText = resources.GetString("oleDbDeleteCommand1.CommandText");
      this.oleDbDeleteCommand1.Connection = this.oleDbConnection;
      this.oleDbDeleteCommand1.Parameters.AddRange(new System.Data.OleDb.OleDbParameter[] {
            new System.Data.OleDb.OleDbParameter("Original_IdPartnera", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "IdPartnera", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("IsNull_TipPartnera", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, ((byte)(0)), ((byte)(0)), "TipPartnera", System.Data.DataRowVersion.Original, true, null),
            new System.Data.OleDb.OleDbParameter("Original_TipPartnera", System.Data.OleDb.OleDbType.VarWChar, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "TipPartnera", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("IsNull_IdMjestaPartnera", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, ((byte)(0)), ((byte)(0)), "IdMjestaPartnera", System.Data.DataRowVersion.Original, true, null),
            new System.Data.OleDb.OleDbParameter("Original_IdMjestaPartnera", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "IdMjestaPartnera", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("IsNull_AdrPartnera", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, ((byte)(0)), ((byte)(0)), "AdrPartnera", System.Data.DataRowVersion.Original, true, null),
            new System.Data.OleDb.OleDbParameter("Original_AdrPartnera", System.Data.OleDb.OleDbType.VarWChar, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "AdrPartnera", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("IsNull_IdMjestaIsporuke", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, ((byte)(0)), ((byte)(0)), "IdMjestaIsporuke", System.Data.DataRowVersion.Original, true, null),
            new System.Data.OleDb.OleDbParameter("Original_IdMjestaIsporuke", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "IdMjestaIsporuke", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("IsNull_AdrIsporuke", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, ((byte)(0)), ((byte)(0)), "AdrIsporuke", System.Data.DataRowVersion.Original, true, null),
            new System.Data.OleDb.OleDbParameter("Original_AdrIsporuke", System.Data.OleDb.OleDbType.VarWChar, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "AdrIsporuke", System.Data.DataRowVersion.Original, null)});
      // 
      // daPartner
      // 
      this.daPartner.DeleteCommand = this.oleDbDeleteCommand1;
      this.daPartner.InsertCommand = this.oleDbInsertCommand1;
      this.daPartner.SelectCommand = this.oleDbSelectCommand1;
      this.daPartner.TableMappings.AddRange(new System.Data.Common.DataTableMapping[] {
            new System.Data.Common.DataTableMapping("Table", "Partner", new System.Data.Common.DataColumnMapping[] {
                        new System.Data.Common.DataColumnMapping("IdPartnera", "IdPartnera"),
                        new System.Data.Common.DataColumnMapping("TipPartnera", "TipPartnera"),
                        new System.Data.Common.DataColumnMapping("IdMjestaPartnera", "IdMjestaPartnera"),
                        new System.Data.Common.DataColumnMapping("AdrPartnera", "AdrPartnera"),
                        new System.Data.Common.DataColumnMapping("IdMjestaIsporuke", "IdMjestaIsporuke"),
                        new System.Data.Common.DataColumnMapping("AdrIsporuke", "AdrIsporuke")})});
      this.daPartner.UpdateCommand = this.oleDbUpdateCommand1;
      // 
      // oleDbSelectCommand2
      // 
      this.oleDbSelectCommand2.CommandText = "SELECT     IdTvrtke, MatBrTvrtke, NazivTvrtke\r\nFROM         Tvrtka";
      this.oleDbSelectCommand2.Connection = this.oleDbConnection;
      // 
      // oleDbInsertCommand2
      // 
      this.oleDbInsertCommand2.CommandText = "INSERT INTO `Tvrtka` (`IdTvrtke`, `MatBrTvrtke`, `NazivTvrtke`) VALUES (?, ?, ?)";
      this.oleDbInsertCommand2.Connection = this.oleDbConnection;
      this.oleDbInsertCommand2.Parameters.AddRange(new System.Data.OleDb.OleDbParameter[] {
            new System.Data.OleDb.OleDbParameter("IdTvrtke", System.Data.OleDb.OleDbType.Integer, 0, "IdTvrtke"),
            new System.Data.OleDb.OleDbParameter("MatBrTvrtke", System.Data.OleDb.OleDbType.VarWChar, 0, "MatBrTvrtke"),
            new System.Data.OleDb.OleDbParameter("NazivTvrtke", System.Data.OleDb.OleDbType.VarWChar, 0, "NazivTvrtke")});
      // 
      // oleDbUpdateCommand2
      // 
      this.oleDbUpdateCommand2.CommandText = resources.GetString("oleDbUpdateCommand2.CommandText");
      this.oleDbUpdateCommand2.Connection = this.oleDbConnection;
      this.oleDbUpdateCommand2.Parameters.AddRange(new System.Data.OleDb.OleDbParameter[] {
            new System.Data.OleDb.OleDbParameter("IdTvrtke", System.Data.OleDb.OleDbType.Integer, 0, "IdTvrtke"),
            new System.Data.OleDb.OleDbParameter("MatBrTvrtke", System.Data.OleDb.OleDbType.VarWChar, 0, "MatBrTvrtke"),
            new System.Data.OleDb.OleDbParameter("NazivTvrtke", System.Data.OleDb.OleDbType.VarWChar, 0, "NazivTvrtke"),
            new System.Data.OleDb.OleDbParameter("Original_IdTvrtke", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "IdTvrtke", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("IsNull_MatBrTvrtke", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, ((byte)(0)), ((byte)(0)), "MatBrTvrtke", System.Data.DataRowVersion.Original, true, null),
            new System.Data.OleDb.OleDbParameter("Original_MatBrTvrtke", System.Data.OleDb.OleDbType.VarWChar, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "MatBrTvrtke", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("IsNull_NazivTvrtke", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, ((byte)(0)), ((byte)(0)), "NazivTvrtke", System.Data.DataRowVersion.Original, true, null),
            new System.Data.OleDb.OleDbParameter("Original_NazivTvrtke", System.Data.OleDb.OleDbType.VarWChar, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "NazivTvrtke", System.Data.DataRowVersion.Original, null)});
      // 
      // oleDbDeleteCommand2
      // 
      this.oleDbDeleteCommand2.CommandText = "DELETE FROM `Tvrtka` WHERE ((`IdTvrtke` = ?) AND ((? = 1 AND `MatBrTvrtke` IS NUL" +
          "L) OR (`MatBrTvrtke` = ?)) AND ((? = 1 AND `NazivTvrtke` IS NULL) OR (`NazivTvrt" +
          "ke` = ?)))";
      this.oleDbDeleteCommand2.Connection = this.oleDbConnection;
      this.oleDbDeleteCommand2.Parameters.AddRange(new System.Data.OleDb.OleDbParameter[] {
            new System.Data.OleDb.OleDbParameter("Original_IdTvrtke", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "IdTvrtke", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("IsNull_MatBrTvrtke", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, ((byte)(0)), ((byte)(0)), "MatBrTvrtke", System.Data.DataRowVersion.Original, true, null),
            new System.Data.OleDb.OleDbParameter("Original_MatBrTvrtke", System.Data.OleDb.OleDbType.VarWChar, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "MatBrTvrtke", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("IsNull_NazivTvrtke", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, ((byte)(0)), ((byte)(0)), "NazivTvrtke", System.Data.DataRowVersion.Original, true, null),
            new System.Data.OleDb.OleDbParameter("Original_NazivTvrtke", System.Data.OleDb.OleDbType.VarWChar, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "NazivTvrtke", System.Data.DataRowVersion.Original, null)});
      // 
      // daTvrtka
      // 
      this.daTvrtka.DeleteCommand = this.oleDbDeleteCommand2;
      this.daTvrtka.InsertCommand = this.oleDbInsertCommand2;
      this.daTvrtka.SelectCommand = this.oleDbSelectCommand2;
      this.daTvrtka.TableMappings.AddRange(new System.Data.Common.DataTableMapping[] {
            new System.Data.Common.DataTableMapping("Table", "Tvrtka", new System.Data.Common.DataColumnMapping[] {
                        new System.Data.Common.DataColumnMapping("IdTvrtke", "IdTvrtke"),
                        new System.Data.Common.DataColumnMapping("MatBrTvrtke", "MatBrTvrtke"),
                        new System.Data.Common.DataColumnMapping("NazivTvrtke", "NazivTvrtke")})});
      this.daTvrtka.UpdateCommand = this.oleDbUpdateCommand2;
      // 
      // firmaDataSet
      // 
      this.firmaDataSet.DataSetName = "FirmaDataSet";
      this.firmaDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
      // 
      // textSQL
      // 
      this.textSQL.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
      this.textSQL.Location = new System.Drawing.Point(12, 12);
      this.textSQL.Multiline = true;
      this.textSQL.Name = "textSQL";
      this.textSQL.ScrollBars = System.Windows.Forms.ScrollBars.Both;
      this.textSQL.Size = new System.Drawing.Size(362, 137);
      this.textSQL.TabIndex = 11;
      this.textSQL.Text = "UPDATE Artikl SET CijArtikla=666 \r\nWHERE SifArtikla=\r\n(SELECT Min(SifArtikla) FRO" +
          "M Artikl)\r\n";
      // 
      // buttonExecute
      // 
      this.buttonExecute.Location = new System.Drawing.Point(394, 50);
      this.buttonExecute.Name = "buttonExecute";
      this.buttonExecute.Size = new System.Drawing.Size(75, 23);
      this.buttonExecute.TabIndex = 12;
      this.buttonExecute.Text = "Execute";
      this.buttonExecute.UseVisualStyleBackColor = true;
      this.buttonExecute.Click += new System.EventHandler(this.buttonExecute_Click);
      // 
      // TransakcijeForm
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.ClientSize = new System.Drawing.Size(481, 170);
      this.Controls.Add(this.buttonExecute);
      this.Controls.Add(this.textSQL);
      this.Controls.Add(this.buttonCommit);
      this.Controls.Add(this.buttonRollback);
      this.Controls.Add(this.buttonBegin);
      this.Name = "TransakcijeForm";
      this.Text = "Transakcije";
      this.Load += new System.EventHandler(this.TransakcijeForm_Load);
      ((System.ComponentModel.ISupportInitialize)(this.firmaDataSet)).EndInit();
      this.ResumeLayout(false);
      this.PerformLayout();

    }

    #endregion

    private System.Windows.Forms.Button buttonBegin;
    private System.Data.OleDb.OleDbConnection oleDbConnection;
    private System.Windows.Forms.Button buttonRollback;
    private FirmaDataSet firmaDataSet;
    private System.Windows.Forms.Button buttonCommit;
    private System.Data.OleDb.OleDbCommand oleDbSelectCommand1;
    private System.Data.OleDb.OleDbCommand oleDbInsertCommand1;
    private System.Data.OleDb.OleDbCommand oleDbUpdateCommand1;
    private System.Data.OleDb.OleDbCommand oleDbDeleteCommand1;
    private System.Data.OleDb.OleDbDataAdapter daPartner;
    private System.Data.OleDb.OleDbCommand oleDbSelectCommand2;
    private System.Data.OleDb.OleDbCommand oleDbInsertCommand2;
    private System.Data.OleDb.OleDbCommand oleDbUpdateCommand2;
    private System.Data.OleDb.OleDbCommand oleDbDeleteCommand2;
    private System.Data.OleDb.OleDbDataAdapter daTvrtka;
    private System.Windows.Forms.TextBox textSQL;
    private System.Windows.Forms.Button buttonExecute;

  }
}


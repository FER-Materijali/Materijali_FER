namespace TankiKlijent
{
  partial class FormTanki
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
      this.sqlConnection1 = new System.Data.SqlClient.SqlConnection();
      this.dataGridViewPromet = new System.Windows.Forms.DataGridView();
      this.splitContainer1 = new System.Windows.Forms.SplitContainer();
      this.dataGridViewDokument = new System.Windows.Forms.DataGridView();
      ((System.ComponentModel.ISupportInitialize)(this.dataGridViewPromet)).BeginInit();
      this.splitContainer1.Panel1.SuspendLayout();
      this.splitContainer1.Panel2.SuspendLayout();
      this.splitContainer1.SuspendLayout();
      ((System.ComponentModel.ISupportInitialize)(this.dataGridViewDokument)).BeginInit();
      this.SuspendLayout();
      // 
      // sqlConnection1
      // 
      this.sqlConnection1.ConnectionString = "Data Source=KLODOVIK\\SQL05;Initial Catalog=Firma;Integrated Security=True";
      this.sqlConnection1.FireInfoMessageEventOnUserErrors = false;
      // 
      // dataGridViewPromet
      // 
      this.dataGridViewPromet.AllowUserToAddRows = false;
      this.dataGridViewPromet.AllowUserToDeleteRows = false;
      this.dataGridViewPromet.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
      this.dataGridViewPromet.Dock = System.Windows.Forms.DockStyle.Fill;
      this.dataGridViewPromet.Location = new System.Drawing.Point(0, 0);
      this.dataGridViewPromet.Name = "dataGridViewPromet";
      this.dataGridViewPromet.ReadOnly = true;
      this.dataGridViewPromet.Size = new System.Drawing.Size(575, 201);
      this.dataGridViewPromet.TabIndex = 1;
      this.dataGridViewPromet.CurrentCellChanged += new System.EventHandler(this.dataGridViewPromet_CurrentCellChanged);
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
      this.splitContainer1.Size = new System.Drawing.Size(575, 403);
      this.splitContainer1.SplitterDistance = 201;
      this.splitContainer1.TabIndex = 2;
      // 
      // dataGridViewDokument
      // 
      this.dataGridViewDokument.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
      this.dataGridViewDokument.Dock = System.Windows.Forms.DockStyle.Fill;
      this.dataGridViewDokument.Location = new System.Drawing.Point(0, 0);
      this.dataGridViewDokument.Name = "dataGridViewDokument";
      this.dataGridViewDokument.Size = new System.Drawing.Size(575, 198);
      this.dataGridViewDokument.TabIndex = 0;
      // 
      // FormTanki
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.ClientSize = new System.Drawing.Size(575, 403);
      this.Controls.Add(this.splitContainer1);
      this.Name = "FormTanki";
      this.Text = "Tanki klijent";
      this.Load += new System.EventHandler(this.FormTanki_Load);
      ((System.ComponentModel.ISupportInitialize)(this.dataGridViewPromet)).EndInit();
      this.splitContainer1.Panel1.ResumeLayout(false);
      this.splitContainer1.Panel2.ResumeLayout(false);
      this.splitContainer1.ResumeLayout(false);
      ((System.ComponentModel.ISupportInitialize)(this.dataGridViewDokument)).EndInit();
      this.ResumeLayout(false);

    }

    #endregion

    private System.Data.SqlClient.SqlConnection sqlConnection1;
    private System.Windows.Forms.DataGridView dataGridViewPromet;
    private System.Windows.Forms.SplitContainer splitContainer1;
    private System.Windows.Forms.DataGridView dataGridViewDokument;
  }
}


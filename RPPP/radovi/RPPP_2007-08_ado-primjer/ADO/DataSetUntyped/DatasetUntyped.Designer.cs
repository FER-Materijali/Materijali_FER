namespace MasterDetailUntyped
{
    partial class DatasetUntyped
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
          this.dataGridViewStavke = new System.Windows.Forms.DataGridView();
          this.labelStavke = new System.Windows.Forms.Label();
          this.dataGridViewGlava = new System.Windows.Forms.DataGridView();
          this.label1 = new System.Windows.Forms.Label();
          ((System.ComponentModel.ISupportInitialize)(this.dataGridViewStavke)).BeginInit();
          ((System.ComponentModel.ISupportInitialize)(this.dataGridViewGlava)).BeginInit();
          this.SuspendLayout();
          // 
          // dataGridViewStavke
          // 
          this.dataGridViewStavke.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                      | System.Windows.Forms.AnchorStyles.Right)));
          this.dataGridViewStavke.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
          this.dataGridViewStavke.Location = new System.Drawing.Point(12, 205);
          this.dataGridViewStavke.Name = "dataGridViewStavke";
          this.dataGridViewStavke.Size = new System.Drawing.Size(552, 142);
          this.dataGridViewStavke.TabIndex = 35;
          // 
          // labelStavke
          // 
          this.labelStavke.AutoSize = true;
          this.labelStavke.Location = new System.Drawing.Point(9, 189);
          this.labelStavke.Name = "labelStavke";
          this.labelStavke.Size = new System.Drawing.Size(44, 13);
          this.labelStavke.TabIndex = 48;
          this.labelStavke.Text = "Stavke:";
          // 
          // dataGridViewGlava
          // 
          this.dataGridViewGlava.AllowUserToAddRows = false;
          this.dataGridViewGlava.AllowUserToDeleteRows = false;
          this.dataGridViewGlava.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                      | System.Windows.Forms.AnchorStyles.Right)));
          this.dataGridViewGlava.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
          this.dataGridViewGlava.Location = new System.Drawing.Point(12, 25);
          this.dataGridViewGlava.Name = "dataGridViewGlava";
          this.dataGridViewGlava.ReadOnly = true;
          this.dataGridViewGlava.Size = new System.Drawing.Size(552, 150);
          this.dataGridViewGlava.TabIndex = 49;
          // 
          // label1
          // 
          this.label1.AutoSize = true;
          this.label1.Location = new System.Drawing.Point(9, 9);
          this.label1.Name = "label1";
          this.label1.Size = new System.Drawing.Size(61, 13);
          this.label1.TabIndex = 50;
          this.label1.Text = "Dokumenti:";
          // 
          // DatasetUntyped
          // 
          this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
          this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
          this.ClientSize = new System.Drawing.Size(576, 363);
          this.Controls.Add(this.label1);
          this.Controls.Add(this.dataGridViewGlava);
          this.Controls.Add(this.labelStavke);
          this.Controls.Add(this.dataGridViewStavke);
          this.Name = "DatasetUntyped";
          this.Text = "Untyped skupovi podataka";
          this.Load += new System.EventHandler(this.DokumentStavka_Load);
          ((System.ComponentModel.ISupportInitialize)(this.dataGridViewStavke)).EndInit();
          ((System.ComponentModel.ISupportInitialize)(this.dataGridViewGlava)).EndInit();
          this.ResumeLayout(false);
          this.PerformLayout();

        }

        #endregion

      private System.Windows.Forms.DataGridView dataGridViewStavke;
      private System.Windows.Forms.Label labelStavke;
      private System.Windows.Forms.DataGridView dataGridViewGlava;
      private System.Windows.Forms.Label label1;
    }
}


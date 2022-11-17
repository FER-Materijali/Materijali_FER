namespace ListCollection
{
    partial class Forma
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
            this.editbox = new System.Windows.Forms.TextBox();
            this.Analiziraj_gumb = new System.Windows.Forms.Button();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.datotekaToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.KROSdataGrid = new System.Windows.Forms.DataGridView();
            this.Pokazivac = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Naziv = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.IdentDataGrid = new System.Windows.Forms.DataGridView();
            this.dataGridViewTextBoxColumn1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn2 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.KonstDataGrid = new System.Windows.Forms.DataGridView();
            this.dataGridViewTextBoxColumn3 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn4 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Tip = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.UZdataGrid = new System.Windows.Forms.DataGridView();
            this.UZ = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn5 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Redak = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.OutputBox = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.menuStrip1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.KROSdataGrid)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.IdentDataGrid)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.KonstDataGrid)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.UZdataGrid)).BeginInit();
            this.SuspendLayout();
            // 
            // editbox
            // 
            this.editbox.AcceptsReturn = true;
            this.editbox.AcceptsTab = true;
            this.editbox.AllowDrop = true;
            this.editbox.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.editbox.Location = new System.Drawing.Point(12, 46);
            this.editbox.Multiline = true;
            this.editbox.Name = "editbox";
            this.editbox.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.editbox.Size = new System.Drawing.Size(517, 417);
            this.editbox.TabIndex = 0;
            // 
            // Analiziraj_gumb
            // 
            this.Analiziraj_gumb.Location = new System.Drawing.Point(160, 469);
            this.Analiziraj_gumb.Name = "Analiziraj_gumb";
            this.Analiziraj_gumb.Size = new System.Drawing.Size(200, 30);
            this.Analiziraj_gumb.TabIndex = 4;
            this.Analiziraj_gumb.Text = "Analiziraj!";
            this.Analiziraj_gumb.UseVisualStyleBackColor = true;
            this.Analiziraj_gumb.Click += new System.EventHandler(this.Analiziraj_gumb_Click);
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.datotekaToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(857, 24);
            this.menuStrip1.TabIndex = 5;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // datotekaToolStripMenuItem
            // 
            this.datotekaToolStripMenuItem.Name = "datotekaToolStripMenuItem";
            this.datotekaToolStripMenuItem.Size = new System.Drawing.Size(102, 20);
            this.datotekaToolStripMenuItem.Text = "Otvori datoteku";
            this.datotekaToolStripMenuItem.ToolTipText = "Otvaranje datoteke sa izvornim kodom";
            this.datotekaToolStripMenuItem.Click += new System.EventHandler(this.datotekaToolStripMenuItem_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(639, 30);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(137, 13);
            this.label1.TabIndex = 7;
            this.label1.Text = "Tablica uniformnih znakova";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(667, 299);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(75, 13);
            this.label2.TabIndex = 7;
            this.label2.Text = "Tablica KROS";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(653, 439);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(105, 13);
            this.label3.TabIndex = 7;
            this.label3.Text = "Tablica identifikatora";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(667, 581);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(88, 13);
            this.label4.TabIndex = 7;
            this.label4.Text = "Tablica konstanti";
            // 
            // KROSdataGrid
            // 
            this.KROSdataGrid.AllowUserToAddRows = false;
            this.KROSdataGrid.AllowUserToDeleteRows = false;
            this.KROSdataGrid.AllowUserToResizeColumns = false;
            this.KROSdataGrid.AllowUserToResizeRows = false;
            this.KROSdataGrid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.KROSdataGrid.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Pokazivac,
            this.Naziv});
            this.KROSdataGrid.EditMode = System.Windows.Forms.DataGridViewEditMode.EditProgrammatically;
            this.KROSdataGrid.Location = new System.Drawing.Point(565, 315);
            this.KROSdataGrid.Name = "KROSdataGrid";
            this.KROSdataGrid.ReadOnly = true;
            this.KROSdataGrid.RowHeadersVisible = false;
            this.KROSdataGrid.RowHeadersWidthSizeMode = System.Windows.Forms.DataGridViewRowHeadersWidthSizeMode.DisableResizing;
            this.KROSdataGrid.Size = new System.Drawing.Size(275, 105);
            this.KROSdataGrid.TabIndex = 8;
            // 
            // Pokazivac
            // 
            this.Pokazivac.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.None;
            this.Pokazivac.HeaderText = "Pokazivač";
            this.Pokazivac.Name = "Pokazivac";
            this.Pokazivac.ReadOnly = true;
            this.Pokazivac.Width = 60;
            // 
            // Naziv
            // 
            this.Naziv.HeaderText = "Naziv";
            this.Naziv.Name = "Naziv";
            this.Naziv.ReadOnly = true;
            this.Naziv.Width = 195;
            // 
            // IdentDataGrid
            // 
            this.IdentDataGrid.AllowUserToAddRows = false;
            this.IdentDataGrid.AllowUserToDeleteRows = false;
            this.IdentDataGrid.AllowUserToResizeColumns = false;
            this.IdentDataGrid.AllowUserToResizeRows = false;
            this.IdentDataGrid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.IdentDataGrid.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dataGridViewTextBoxColumn1,
            this.dataGridViewTextBoxColumn2});
            this.IdentDataGrid.EditMode = System.Windows.Forms.DataGridViewEditMode.EditProgrammatically;
            this.IdentDataGrid.Location = new System.Drawing.Point(565, 455);
            this.IdentDataGrid.Name = "IdentDataGrid";
            this.IdentDataGrid.ReadOnly = true;
            this.IdentDataGrid.RowHeadersVisible = false;
            this.IdentDataGrid.RowHeadersWidthSizeMode = System.Windows.Forms.DataGridViewRowHeadersWidthSizeMode.DisableResizing;
            this.IdentDataGrid.Size = new System.Drawing.Size(275, 105);
            this.IdentDataGrid.TabIndex = 8;
            // 
            // dataGridViewTextBoxColumn1
            // 
            this.dataGridViewTextBoxColumn1.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.None;
            this.dataGridViewTextBoxColumn1.HeaderText = "Pokazivač";
            this.dataGridViewTextBoxColumn1.Name = "dataGridViewTextBoxColumn1";
            this.dataGridViewTextBoxColumn1.ReadOnly = true;
            this.dataGridViewTextBoxColumn1.Width = 60;
            // 
            // dataGridViewTextBoxColumn2
            // 
            this.dataGridViewTextBoxColumn2.HeaderText = "Naziv";
            this.dataGridViewTextBoxColumn2.Name = "dataGridViewTextBoxColumn2";
            this.dataGridViewTextBoxColumn2.ReadOnly = true;
            this.dataGridViewTextBoxColumn2.Width = 195;
            // 
            // KonstDataGrid
            // 
            this.KonstDataGrid.AllowUserToAddRows = false;
            this.KonstDataGrid.AllowUserToDeleteRows = false;
            this.KonstDataGrid.AllowUserToResizeColumns = false;
            this.KonstDataGrid.AllowUserToResizeRows = false;
            this.KonstDataGrid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.KonstDataGrid.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dataGridViewTextBoxColumn3,
            this.dataGridViewTextBoxColumn4,
            this.Tip});
            this.KonstDataGrid.EditMode = System.Windows.Forms.DataGridViewEditMode.EditProgrammatically;
            this.KonstDataGrid.Location = new System.Drawing.Point(565, 597);
            this.KonstDataGrid.Name = "KonstDataGrid";
            this.KonstDataGrid.ReadOnly = true;
            this.KonstDataGrid.RowHeadersVisible = false;
            this.KonstDataGrid.RowHeadersWidthSizeMode = System.Windows.Forms.DataGridViewRowHeadersWidthSizeMode.DisableResizing;
            this.KonstDataGrid.Size = new System.Drawing.Size(275, 105);
            this.KonstDataGrid.TabIndex = 8;
            // 
            // dataGridViewTextBoxColumn3
            // 
            this.dataGridViewTextBoxColumn3.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.None;
            this.dataGridViewTextBoxColumn3.HeaderText = "Pokazivač";
            this.dataGridViewTextBoxColumn3.Name = "dataGridViewTextBoxColumn3";
            this.dataGridViewTextBoxColumn3.ReadOnly = true;
            this.dataGridViewTextBoxColumn3.Width = 60;
            // 
            // dataGridViewTextBoxColumn4
            // 
            this.dataGridViewTextBoxColumn4.HeaderText = "Vrijednost";
            this.dataGridViewTextBoxColumn4.Name = "dataGridViewTextBoxColumn4";
            this.dataGridViewTextBoxColumn4.ReadOnly = true;
            this.dataGridViewTextBoxColumn4.Width = 115;
            // 
            // Tip
            // 
            this.Tip.HeaderText = "Tip";
            this.Tip.Name = "Tip";
            this.Tip.ReadOnly = true;
            this.Tip.Width = 80;
            // 
            // UZdataGrid
            // 
            this.UZdataGrid.AllowUserToAddRows = false;
            this.UZdataGrid.AllowUserToDeleteRows = false;
            this.UZdataGrid.AllowUserToResizeColumns = false;
            this.UZdataGrid.AllowUserToResizeRows = false;
            this.UZdataGrid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.UZdataGrid.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.UZ,
            this.dataGridViewTextBoxColumn5,
            this.Redak});
            this.UZdataGrid.EditMode = System.Windows.Forms.DataGridViewEditMode.EditProgrammatically;
            this.UZdataGrid.Location = new System.Drawing.Point(565, 46);
            this.UZdataGrid.Name = "UZdataGrid";
            this.UZdataGrid.ReadOnly = true;
            this.UZdataGrid.RowHeadersVisible = false;
            this.UZdataGrid.RowHeadersWidthSizeMode = System.Windows.Forms.DataGridViewRowHeadersWidthSizeMode.DisableResizing;
            this.UZdataGrid.Size = new System.Drawing.Size(275, 231);
            this.UZdataGrid.TabIndex = 8;
            // 
            // UZ
            // 
            this.UZ.HeaderText = "Uniformni Znak";
            this.UZ.Name = "UZ";
            this.UZ.ReadOnly = true;
            // 
            // dataGridViewTextBoxColumn5
            // 
            this.dataGridViewTextBoxColumn5.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.None;
            this.dataGridViewTextBoxColumn5.HeaderText = "Pokazivač";
            this.dataGridViewTextBoxColumn5.Name = "dataGridViewTextBoxColumn5";
            this.dataGridViewTextBoxColumn5.ReadOnly = true;
            this.dataGridViewTextBoxColumn5.Width = 60;
            // 
            // Redak
            // 
            this.Redak.HeaderText = "Redak";
            this.Redak.Name = "Redak";
            this.Redak.ReadOnly = true;
            this.Redak.Width = 90;
            // 
            // OutputBox
            // 
            this.OutputBox.AcceptsReturn = true;
            this.OutputBox.AcceptsTab = true;
            this.OutputBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.OutputBox.Location = new System.Drawing.Point(12, 555);
            this.OutputBox.Multiline = true;
            this.OutputBox.Name = "OutputBox";
            this.OutputBox.ReadOnly = true;
            this.OutputBox.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.OutputBox.Size = new System.Drawing.Size(517, 147);
            this.OutputBox.TabIndex = 9;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(245, 539);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(28, 13);
            this.label5.TabIndex = 10;
            this.label5.Text = "Izlaz";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(227, 30);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(77, 13);
            this.label6.TabIndex = 11;
            this.label6.Text = "Ulazni program";
            // 
            // Forma
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(857, 714);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.OutputBox);
            this.Controls.Add(this.KonstDataGrid);
            this.Controls.Add(this.IdentDataGrid);
            this.Controls.Add(this.UZdataGrid);
            this.Controls.Add(this.KROSdataGrid);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.Analiziraj_gumb);
            this.Controls.Add(this.editbox);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Forma";
            this.Text = "Sintaksni analizator";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.KROSdataGrid)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.IdentDataGrid)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.KonstDataGrid)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.UZdataGrid)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button Analiziraj_gumb;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem datotekaToolStripMenuItem;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        public System.Windows.Forms.DataGridView KROSdataGrid;
        private System.Windows.Forms.DataGridViewTextBoxColumn Pokazivac;
        private System.Windows.Forms.DataGridViewTextBoxColumn Naziv;
        public System.Windows.Forms.DataGridView IdentDataGrid;
        public System.Windows.Forms.DataGridView KonstDataGrid;
        public System.Windows.Forms.DataGridView UZdataGrid;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn3;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn4;
        private System.Windows.Forms.DataGridViewTextBoxColumn Tip;
        private System.Windows.Forms.DataGridViewTextBoxColumn UZ;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn5;
        private System.Windows.Forms.DataGridViewTextBoxColumn Redak;
        public System.Windows.Forms.TextBox editbox;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn1;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn2;
        public System.Windows.Forms.TextBox OutputBox;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        
    }
}


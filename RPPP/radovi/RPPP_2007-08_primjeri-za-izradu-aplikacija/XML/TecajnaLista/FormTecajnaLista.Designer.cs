namespace TecajnaLista
{
    partial class FormTecajnaLista
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
          this.buttonDodaj = new System.Windows.Forms.Button();
          this.groupBox1 = new System.Windows.Forms.GroupBox();
          this.buttonUcitaj = new System.Windows.Forms.Button();
          this.buttonBrowse = new System.Windows.Forms.Button();
          this.textBoxDatoteka = new System.Windows.Forms.TextBox();
          this.openFileDialogTecajnaLista = new System.Windows.Forms.OpenFileDialog();
          this.buttonWrite = new System.Windows.Forms.Button();
          this.tabControl1 = new System.Windows.Forms.TabControl();
          this.tabPage1 = new System.Windows.Forms.TabPage();
          this.listView1 = new System.Windows.Forms.ListView();
          this.columnNaziv = new System.Windows.Forms.ColumnHeader();
          this.columnJedinica = new System.Windows.Forms.ColumnHeader();
          this.columnKupovniEf = new System.Windows.Forms.ColumnHeader();
          this.columnKupovniDe = new System.Windows.Forms.ColumnHeader();
          this.columnSrednji = new System.Windows.Forms.ColumnHeader();
          this.columnProdajniDe = new System.Windows.Forms.ColumnHeader();
          this.columnProdajniEf = new System.Windows.Forms.ColumnHeader();
          this.tabPage2 = new System.Windows.Forms.TabPage();
          this.textBoxXMLSchema = new System.Windows.Forms.TextBox();
          this.tabPage3 = new System.Windows.Forms.TabPage();
          this.textBoxXML = new System.Windows.Forms.TextBox();
          this.tabPage4 = new System.Windows.Forms.TabPage();
          this.dataGridView1 = new System.Windows.Forms.DataGridView();
          this.groupBox1.SuspendLayout();
          this.tabControl1.SuspendLayout();
          this.tabPage1.SuspendLayout();
          this.tabPage2.SuspendLayout();
          this.tabPage3.SuspendLayout();
          this.tabPage4.SuspendLayout();
          ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
          this.SuspendLayout();
          // 
          // buttonDodaj
          // 
          this.buttonDodaj.Enabled = false;
          this.buttonDodaj.Location = new System.Drawing.Point(607, 30);
          this.buttonDodaj.Name = "buttonDodaj";
          this.buttonDodaj.Size = new System.Drawing.Size(133, 23);
          this.buttonDodaj.TabIndex = 3;
          this.buttonDodaj.Text = "Dodaj valutu...";
          this.buttonDodaj.UseVisualStyleBackColor = true;
          this.buttonDodaj.Click += new System.EventHandler(this.buttonDodaj_Click);
          // 
          // groupBox1
          // 
          this.groupBox1.Controls.Add(this.buttonUcitaj);
          this.groupBox1.Controls.Add(this.buttonBrowse);
          this.groupBox1.Controls.Add(this.textBoxDatoteka);
          this.groupBox1.Location = new System.Drawing.Point(2, 12);
          this.groupBox1.Name = "groupBox1";
          this.groupBox1.Size = new System.Drawing.Size(586, 53);
          this.groupBox1.TabIndex = 4;
          this.groupBox1.TabStop = false;
          // 
          // buttonUcitaj
          // 
          this.buttonUcitaj.Location = new System.Drawing.Point(482, 19);
          this.buttonUcitaj.Name = "buttonUcitaj";
          this.buttonUcitaj.Size = new System.Drawing.Size(75, 23);
          this.buttonUcitaj.TabIndex = 2;
          this.buttonUcitaj.Text = "Uèitaj";
          this.buttonUcitaj.UseVisualStyleBackColor = true;
          this.buttonUcitaj.Click += new System.EventHandler(this.buttonUcitaj_Click);
          // 
          // buttonBrowse
          // 
          this.buttonBrowse.Location = new System.Drawing.Point(401, 19);
          this.buttonBrowse.Name = "buttonBrowse";
          this.buttonBrowse.Size = new System.Drawing.Size(75, 23);
          this.buttonBrowse.TabIndex = 1;
          this.buttonBrowse.Text = "Browse...";
          this.buttonBrowse.UseVisualStyleBackColor = true;
          this.buttonBrowse.Click += new System.EventHandler(this.buttonBrowse_Click);
          // 
          // textBoxDatoteka
          // 
          this.textBoxDatoteka.Location = new System.Drawing.Point(19, 21);
          this.textBoxDatoteka.Name = "textBoxDatoteka";
          this.textBoxDatoteka.Size = new System.Drawing.Size(356, 20);
          this.textBoxDatoteka.TabIndex = 0;
          this.textBoxDatoteka.Text = "../../TecajnaLista.xml";
          // 
          // openFileDialogTecajnaLista
          // 
          this.openFileDialogTecajnaLista.FileName = "TecajnaLista.xml";
          // 
          // buttonWrite
          // 
          this.buttonWrite.Enabled = false;
          this.buttonWrite.Location = new System.Drawing.Point(753, 30);
          this.buttonWrite.Name = "buttonWrite";
          this.buttonWrite.Size = new System.Drawing.Size(75, 23);
          this.buttonWrite.TabIndex = 5;
          this.buttonWrite.Text = "Spremi";
          this.buttonWrite.UseVisualStyleBackColor = true;
          this.buttonWrite.Click += new System.EventHandler(this.buttonSpremi_Click);
          // 
          // tabControl1
          // 
          this.tabControl1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                      | System.Windows.Forms.AnchorStyles.Left)
                      | System.Windows.Forms.AnchorStyles.Right)));
          this.tabControl1.Controls.Add(this.tabPage1);
          this.tabControl1.Controls.Add(this.tabPage2);
          this.tabControl1.Controls.Add(this.tabPage3);
          this.tabControl1.Controls.Add(this.tabPage4);
          this.tabControl1.Location = new System.Drawing.Point(2, 79);
          this.tabControl1.Name = "tabControl1";
          this.tabControl1.SelectedIndex = 0;
          this.tabControl1.Size = new System.Drawing.Size(851, 426);
          this.tabControl1.TabIndex = 6;
          // 
          // tabPage1
          // 
          this.tabPage1.Controls.Add(this.listView1);
          this.tabPage1.Location = new System.Drawing.Point(4, 22);
          this.tabPage1.Name = "tabPage1";
          this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
          this.tabPage1.Size = new System.Drawing.Size(843, 400);
          this.tabPage1.TabIndex = 0;
          this.tabPage1.Text = "Lista";
          this.tabPage1.UseVisualStyleBackColor = true;
          // 
          // listView1
          // 
          this.listView1.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnNaziv,
            this.columnJedinica,
            this.columnKupovniEf,
            this.columnKupovniDe,
            this.columnSrednji,
            this.columnProdajniDe,
            this.columnProdajniEf});
          this.listView1.Dock = System.Windows.Forms.DockStyle.Fill;
          this.listView1.Location = new System.Drawing.Point(3, 3);
          this.listView1.Name = "listView1";
          this.listView1.Size = new System.Drawing.Size(837, 394);
          this.listView1.TabIndex = 2;
          this.listView1.UseCompatibleStateImageBehavior = false;
          this.listView1.View = System.Windows.Forms.View.Details;
          // 
          // columnNaziv
          // 
          this.columnNaziv.Text = "Naziv valute";
          this.columnNaziv.Width = 100;
          // 
          // columnJedinica
          // 
          this.columnJedinica.Text = "Jedinica";
          this.columnJedinica.Width = 100;
          // 
          // columnKupovniEf
          // 
          this.columnKupovniEf.DisplayIndex = 5;
          this.columnKupovniEf.Text = "Kupovni za efektivu";
          this.columnKupovniEf.Width = 120;
          // 
          // columnKupovniDe
          // 
          this.columnKupovniDe.DisplayIndex = 2;
          this.columnKupovniDe.Text = "Kupovni za devize";
          this.columnKupovniDe.Width = 120;
          // 
          // columnSrednji
          // 
          this.columnSrednji.DisplayIndex = 3;
          this.columnSrednji.Text = "Srednji";
          this.columnSrednji.Width = 120;
          // 
          // columnProdajniDe
          // 
          this.columnProdajniDe.DisplayIndex = 4;
          this.columnProdajniDe.Text = "Prodajni za devize";
          this.columnProdajniDe.Width = 120;
          // 
          // columnProdajniEf
          // 
          this.columnProdajniEf.Text = "Prodajni za efektivu";
          this.columnProdajniEf.Width = 120;
          // 
          // tabPage2
          // 
          this.tabPage2.Controls.Add(this.textBoxXMLSchema);
          this.tabPage2.Location = new System.Drawing.Point(4, 22);
          this.tabPage2.Name = "tabPage2";
          this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
          this.tabPage2.Size = new System.Drawing.Size(817, 227);
          this.tabPage2.TabIndex = 1;
          this.tabPage2.Text = "Schema";
          this.tabPage2.UseVisualStyleBackColor = true;
          // 
          // textBoxXMLSchema
          // 
          this.textBoxXMLSchema.Dock = System.Windows.Forms.DockStyle.Fill;
          this.textBoxXMLSchema.Location = new System.Drawing.Point(3, 3);
          this.textBoxXMLSchema.Multiline = true;
          this.textBoxXMLSchema.Name = "textBoxXMLSchema";
          this.textBoxXMLSchema.ScrollBars = System.Windows.Forms.ScrollBars.Both;
          this.textBoxXMLSchema.Size = new System.Drawing.Size(811, 221);
          this.textBoxXMLSchema.TabIndex = 0;
          // 
          // tabPage3
          // 
          this.tabPage3.Controls.Add(this.textBoxXML);
          this.tabPage3.Location = new System.Drawing.Point(4, 22);
          this.tabPage3.Name = "tabPage3";
          this.tabPage3.Padding = new System.Windows.Forms.Padding(3);
          this.tabPage3.Size = new System.Drawing.Size(817, 227);
          this.tabPage3.TabIndex = 2;
          this.tabPage3.Text = "XML";
          this.tabPage3.UseVisualStyleBackColor = true;
          // 
          // textBoxXML
          // 
          this.textBoxXML.Dock = System.Windows.Forms.DockStyle.Fill;
          this.textBoxXML.Location = new System.Drawing.Point(3, 3);
          this.textBoxXML.Multiline = true;
          this.textBoxXML.Name = "textBoxXML";
          this.textBoxXML.ScrollBars = System.Windows.Forms.ScrollBars.Both;
          this.textBoxXML.Size = new System.Drawing.Size(811, 221);
          this.textBoxXML.TabIndex = 1;
          // 
          // tabPage4
          // 
          this.tabPage4.Controls.Add(this.dataGridView1);
          this.tabPage4.Location = new System.Drawing.Point(4, 22);
          this.tabPage4.Name = "tabPage4";
          this.tabPage4.Padding = new System.Windows.Forms.Padding(3);
          this.tabPage4.Size = new System.Drawing.Size(817, 227);
          this.tabPage4.TabIndex = 3;
          this.tabPage4.Text = "Grid";
          this.tabPage4.UseVisualStyleBackColor = true;
          // 
          // dataGridView1
          // 
          this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
          this.dataGridView1.Dock = System.Windows.Forms.DockStyle.Fill;
          this.dataGridView1.Location = new System.Drawing.Point(3, 3);
          this.dataGridView1.Name = "dataGridView1";
          this.dataGridView1.Size = new System.Drawing.Size(811, 221);
          this.dataGridView1.TabIndex = 2;
          // 
          // FormTecajnaLista
          // 
          this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
          this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
          this.ClientSize = new System.Drawing.Size(858, 514);
          this.Controls.Add(this.tabControl1);
          this.Controls.Add(this.buttonWrite);
          this.Controls.Add(this.groupBox1);
          this.Controls.Add(this.buttonDodaj);
          this.Name = "FormTecajnaLista";
          this.Text = "Teèajna lista";
          this.groupBox1.ResumeLayout(false);
          this.groupBox1.PerformLayout();
          this.tabControl1.ResumeLayout(false);
          this.tabPage1.ResumeLayout(false);
          this.tabPage2.ResumeLayout(false);
          this.tabPage2.PerformLayout();
          this.tabPage3.ResumeLayout(false);
          this.tabPage3.PerformLayout();
          this.tabPage4.ResumeLayout(false);
          ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
          this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button buttonDodaj;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button buttonUcitaj;
        private System.Windows.Forms.Button buttonBrowse;
        private System.Windows.Forms.TextBox textBoxDatoteka;
        private System.Windows.Forms.OpenFileDialog openFileDialogTecajnaLista;
        private System.Windows.Forms.Button buttonWrite;
      private System.Windows.Forms.TabControl tabControl1;
      private System.Windows.Forms.TabPage tabPage1;
      private System.Windows.Forms.ListView listView1;
      private System.Windows.Forms.ColumnHeader columnNaziv;
      private System.Windows.Forms.ColumnHeader columnJedinica;
      private System.Windows.Forms.ColumnHeader columnKupovniEf;
      private System.Windows.Forms.ColumnHeader columnKupovniDe;
      private System.Windows.Forms.ColumnHeader columnSrednji;
      private System.Windows.Forms.ColumnHeader columnProdajniDe;
      private System.Windows.Forms.ColumnHeader columnProdajniEf;
      private System.Windows.Forms.TabPage tabPage2;
      private System.Windows.Forms.TextBox textBoxXMLSchema;
      private System.Windows.Forms.TabPage tabPage3;
      private System.Windows.Forms.TabPage tabPage4;
      private System.Windows.Forms.TextBox textBoxXML;
      private System.Windows.Forms.DataGridView dataGridView1;
    }
}


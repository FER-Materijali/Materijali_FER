namespace SSP
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.label1 = new System.Windows.Forms.Label();
            this.richTextBoxProdukcijeGramatike = new System.Windows.Forms.RichTextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.buttonTablicaIspred = new System.Windows.Forms.Button();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.maniToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.učitajGramatikuToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.izlazToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.richTextBoxPNZ = new System.Windows.Forms.RichTextBox();
            this.label3 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(41, 45);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(112, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Produkcije gramatike :";
            // 
            // richTextBoxProdukcijeGramatike
            // 
            this.richTextBoxProdukcijeGramatike.Location = new System.Drawing.Point(29, 69);
            this.richTextBoxProdukcijeGramatike.Name = "richTextBoxProdukcijeGramatike";
            this.richTextBoxProdukcijeGramatike.Size = new System.Drawing.Size(196, 299);
            this.richTextBoxProdukcijeGramatike.TabIndex = 1;
            this.richTextBoxProdukcijeGramatike.Text = "";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(308, 45);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(80, 13);
            this.label2.TabIndex = 2;
            this.label2.Text = "Tablica Ispred :";
            // 
            // dataGridView1
            // 
            this.dataGridView1.AllowUserToAddRows = false;
            this.dataGridView1.AllowUserToDeleteRows = false;
            this.dataGridView1.AllowUserToResizeColumns = false;
            this.dataGridView1.AllowUserToResizeRows = false;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(291, 69);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.ReadOnly = true;
            this.dataGridView1.RowHeadersWidth = 50;
            this.dataGridView1.Size = new System.Drawing.Size(310, 150);
            this.dataGridView1.TabIndex = 3;
            // 
            // buttonTablicaIspred
            // 
            this.buttonTablicaIspred.Location = new System.Drawing.Point(469, 389);
            this.buttonTablicaIspred.Name = "buttonTablicaIspred";
            this.buttonTablicaIspred.Size = new System.Drawing.Size(66, 23);
            this.buttonTablicaIspred.TabIndex = 2;
            this.buttonTablicaIspred.Text = "Generiraj";
            this.buttonTablicaIspred.UseVisualStyleBackColor = true;
            this.buttonTablicaIspred.Click += new System.EventHandler(this.buttonTablicaIspred_Click_1);
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.maniToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(613, 24);
            this.menuStrip1.TabIndex = 4;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // maniToolStripMenuItem
            // 
            this.maniToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.učitajGramatikuToolStripMenuItem,
            this.izlazToolStripMenuItem});
            this.maniToolStripMenuItem.Name = "maniToolStripMenuItem";
            this.maniToolStripMenuItem.Size = new System.Drawing.Size(46, 20);
            this.maniToolStripMenuItem.Text = "Mani";
            // 
            // učitajGramatikuToolStripMenuItem
            // 
            this.učitajGramatikuToolStripMenuItem.Name = "učitajGramatikuToolStripMenuItem";
            this.učitajGramatikuToolStripMenuItem.Size = new System.Drawing.Size(161, 22);
            this.učitajGramatikuToolStripMenuItem.Text = "Učitaj gramatiku";
            this.učitajGramatikuToolStripMenuItem.Click += new System.EventHandler(this.učitajGramatikuToolStripMenuItem_Click);
            // 
            // izlazToolStripMenuItem
            // 
            this.izlazToolStripMenuItem.Name = "izlazToolStripMenuItem";
            this.izlazToolStripMenuItem.Size = new System.Drawing.Size(161, 22);
            this.izlazToolStripMenuItem.Text = "Izlaz";
            this.izlazToolStripMenuItem.Click += new System.EventHandler(this.izlazToolStripMenuItem_Click);
            // 
            // richTextBoxPNZ
            // 
            this.richTextBoxPNZ.BackColor = System.Drawing.SystemColors.Window;
            this.richTextBoxPNZ.Location = new System.Drawing.Point(291, 272);
            this.richTextBoxPNZ.Name = "richTextBoxPNZ";
            this.richTextBoxPNZ.ReadOnly = true;
            this.richTextBoxPNZ.Size = new System.Drawing.Size(310, 96);
            this.richTextBoxPNZ.TabIndex = 5;
            this.richTextBoxPNZ.Text = "";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(308, 247);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(229, 13);
            this.label3.TabIndex = 6;
            this.label3.Text = "Skupovi SLIJEDI praznih nezavršnih znakova :";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(613, 424);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.richTextBoxPNZ);
            this.Controls.Add(this.richTextBoxProdukcijeGramatike);
            this.Controls.Add(this.buttonTablicaIspred);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.menuStrip1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "SSP";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.RichTextBox richTextBoxProdukcijeGramatike;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.Button buttonTablicaIspred;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem maniToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem izlazToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem učitajGramatikuToolStripMenuItem;
        private System.Windows.Forms.RichTextBox richTextBoxPNZ;
        private System.Windows.Forms.Label label3;
    }
}


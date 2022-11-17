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
            this.components = new System.ComponentModel.Container();
            this.button1 = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.openFD = new System.Windows.Forms.OpenFileDialog();
            this.toolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.produkcijeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.zAPOCINJESkupoveToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.pomoćToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.općenitoToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.notifyIcon1 = new System.Windows.Forms.NotifyIcon(this.components);
            this.label1 = new System.Windows.Forms.Label();
            this.radioButton2 = new System.Windows.Forms.RadioButton();
            this.radioButton1 = new System.Windows.Forms.RadioButton();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.openToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.produkcijeToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.zAPOCINJESkupToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.pomoćToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.općenitoToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.label3 = new System.Windows.Forms.Label();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.button1.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.button1.Location = new System.Drawing.Point(70, 76);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(116, 31);
            this.button1.TabIndex = 1;
            this.button1.Text = "Generiraj!";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // textBox1
            // 
            this.textBox1.BackColor = System.Drawing.SystemColors.Desktop;
            this.textBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox1.ForeColor = System.Drawing.SystemColors.ScrollBar;
            this.textBox1.Location = new System.Drawing.Point(56, 208);
            this.textBox1.Name = "textBox1";
            this.textBox1.ReadOnly = true;
            this.textBox1.Size = new System.Drawing.Size(149, 22);
            this.textBox1.TabIndex = 2;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(226, 24);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(210, 24);
            this.label2.TabIndex = 3;
            this.label2.Text = "Tablica LALR parsera";
            this.label2.Visible = false;
            // 
            // openFD
            // 
            this.openFD.FileName = "openFileDialog1";
            // 
            // toolStripMenuItem1
            // 
            this.toolStripMenuItem1.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.produkcijeToolStripMenuItem,
            this.zAPOCINJESkupoveToolStripMenuItem});
            this.toolStripMenuItem1.ForeColor = System.Drawing.SystemColors.ControlLight;
            this.toolStripMenuItem1.Name = "toolStripMenuItem1";
            this.toolStripMenuItem1.Size = new System.Drawing.Size(53, 20);
            this.toolStripMenuItem1.Text = "Otvori";
            // 
            // produkcijeToolStripMenuItem
            // 
            this.produkcijeToolStripMenuItem.Name = "produkcijeToolStripMenuItem";
            this.produkcijeToolStripMenuItem.Size = new System.Drawing.Size(190, 22);
            this.produkcijeToolStripMenuItem.Text = "Produkcije";
            // 
            // zAPOCINJESkupoveToolStripMenuItem
            // 
            this.zAPOCINJESkupoveToolStripMenuItem.Name = "zAPOCINJESkupoveToolStripMenuItem";
            this.zAPOCINJESkupoveToolStripMenuItem.Size = new System.Drawing.Size(190, 22);
            this.zAPOCINJESkupoveToolStripMenuItem.Text = "\"ZAPOčINJE\" skupove";
            // 
            // pomoćToolStripMenuItem
            // 
            this.pomoćToolStripMenuItem.ForeColor = System.Drawing.SystemColors.Control;
            this.pomoćToolStripMenuItem.Name = "pomoćToolStripMenuItem";
            this.pomoćToolStripMenuItem.Size = new System.Drawing.Size(57, 20);
            this.pomoćToolStripMenuItem.Text = "Pomoć";
            // 
            // općenitoToolStripMenuItem
            // 
            this.općenitoToolStripMenuItem.ForeColor = System.Drawing.SystemColors.Control;
            this.općenitoToolStripMenuItem.Name = "općenitoToolStripMenuItem";
            this.općenitoToolStripMenuItem.Size = new System.Drawing.Size(70, 20);
            this.općenitoToolStripMenuItem.Text = "Općenito";
            // 
            // notifyIcon1
            // 
            this.notifyIcon1.Text = "notifyIcon1";
            this.notifyIcon1.Visible = true;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(19, 122);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(45, 13);
            this.label1.TabIndex = 8;
            this.label1.Text = "Tablica:";
            // 
            // radioButton2
            // 
            this.radioButton2.AutoSize = true;
            this.radioButton2.Location = new System.Drawing.Point(70, 145);
            this.radioButton2.Name = "radioButton2";
            this.radioButton2.Size = new System.Drawing.Size(116, 17);
            this.radioButton2.TabIndex = 7;
            this.radioButton2.Text = "kanonskog parsera";
            this.radioButton2.UseVisualStyleBackColor = true;
            this.radioButton2.CheckedChanged += new System.EventHandler(this.radioButton2_CheckedChanged);
            // 
            // radioButton1
            // 
            this.radioButton1.AutoSize = true;
            this.radioButton1.Location = new System.Drawing.Point(70, 122);
            this.radioButton1.Name = "radioButton1";
            this.radioButton1.Size = new System.Drawing.Size(90, 17);
            this.radioButton1.TabIndex = 6;
            this.radioButton1.Text = "LALR parsera";
            this.radioButton1.UseVisualStyleBackColor = true;
            this.radioButton1.CheckedChanged += new System.EventHandler(this.radioButton1_CheckedChanged);
            // 
            // menuStrip1
            // 
            this.menuStrip1.BackColor = System.Drawing.SystemColors.Highlight;
            this.menuStrip1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.menuStrip1.GripStyle = System.Windows.Forms.ToolStripGripStyle.Visible;
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.openToolStripMenuItem,
            this.pomoćToolStripMenuItem1,
            this.općenitoToolStripMenuItem1});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.RenderMode = System.Windows.Forms.ToolStripRenderMode.Professional;
            this.menuStrip1.Size = new System.Drawing.Size(250, 24);
            this.menuStrip1.TabIndex = 5;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // openToolStripMenuItem
            // 
            this.openToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.produkcijeToolStripMenuItem1,
            this.zAPOCINJESkupToolStripMenuItem});
            this.openToolStripMenuItem.ForeColor = System.Drawing.SystemColors.Control;
            this.openToolStripMenuItem.Name = "openToolStripMenuItem";
            this.openToolStripMenuItem.Size = new System.Drawing.Size(53, 20);
            this.openToolStripMenuItem.Text = "Otvori";
            // 
            // produkcijeToolStripMenuItem1
            // 
            this.produkcijeToolStripMenuItem1.Name = "produkcijeToolStripMenuItem1";
            this.produkcijeToolStripMenuItem1.Size = new System.Drawing.Size(183, 22);
            this.produkcijeToolStripMenuItem1.Text = "Produkcije";
            this.produkcijeToolStripMenuItem1.Click += new System.EventHandler(this.produkcijeToolStripMenuItem1_Click);
            // 
            // zAPOCINJESkupToolStripMenuItem
            // 
            this.zAPOCINJESkupToolStripMenuItem.Name = "zAPOCINJESkupToolStripMenuItem";
            this.zAPOCINJESkupToolStripMenuItem.Size = new System.Drawing.Size(183, 22);
            this.zAPOCINJESkupToolStripMenuItem.Text = "\'ZAPOCINJE\' skup";
            this.zAPOCINJESkupToolStripMenuItem.Click += new System.EventHandler(this.zAPOCINJESkupToolStripMenuItem_Click);
            // 
            // pomoćToolStripMenuItem1
            // 
            this.pomoćToolStripMenuItem1.ForeColor = System.Drawing.SystemColors.Control;
            this.pomoćToolStripMenuItem1.Name = "pomoćToolStripMenuItem1";
            this.pomoćToolStripMenuItem1.Size = new System.Drawing.Size(57, 20);
            this.pomoćToolStripMenuItem1.Text = "Pomoć";
            this.pomoćToolStripMenuItem1.Click += new System.EventHandler(this.pomoćToolStripMenuItem1_Click_1);
            // 
            // općenitoToolStripMenuItem1
            // 
            this.općenitoToolStripMenuItem1.ForeColor = System.Drawing.SystemColors.Control;
            this.općenitoToolStripMenuItem1.Name = "općenitoToolStripMenuItem1";
            this.općenitoToolStripMenuItem1.Size = new System.Drawing.Size(70, 20);
            this.općenitoToolStripMenuItem1.Text = "Općenito";
            this.općenitoToolStripMenuItem1.Click += new System.EventHandler(this.općenitoToolStripMenuItem1_Click_1);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label3.Location = new System.Drawing.Point(226, 24);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(261, 24);
            this.label3.TabIndex = 9;
            this.label3.Text = "Tablica kanonskog parsera";
            this.label3.Visible = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Highlight;
            this.ClientSize = new System.Drawing.Size(250, 305);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.radioButton2);
            this.Controls.Add(this.radioButton1);
            this.Controls.Add(this.menuStrip1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.button1);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.ForeColor = System.Drawing.SystemColors.Control;
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "Generator tablice LALR parsera";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.OpenFileDialog openFD;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem produkcijeToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem zAPOCINJESkupoveToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem pomoćToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem općenitoToolStripMenuItem;
        private System.Windows.Forms.NotifyIcon notifyIcon1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.RadioButton radioButton2;
        private System.Windows.Forms.RadioButton radioButton1;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem openToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem produkcijeToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem zAPOCINJESkupToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem pomoćToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem općenitoToolStripMenuItem1;
        private System.Windows.Forms.Label label3;
    }
}


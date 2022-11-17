namespace WindowsFormsApplication2
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
            this.textBoxUlazniNiz = new System.Windows.Forms.TextBox();
            this.buttonParsiraj = new System.Windows.Forms.Button();
            this.labelUlazniNiz = new System.Windows.Forms.Label();
            this.labelIspis = new System.Windows.Forms.Label();
            this.labelGreskaNiz = new System.Windows.Forms.Label();
            this.textBoxStanjeNaStogu = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.textBoxAkcija = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // textBoxUlazniNiz
            // 
            this.textBoxUlazniNiz.BackColor = System.Drawing.Color.WhiteSmoke;
            this.textBoxUlazniNiz.ForeColor = System.Drawing.SystemColors.MenuText;
            this.textBoxUlazniNiz.Location = new System.Drawing.Point(15, 49);
            this.textBoxUlazniNiz.Name = "textBoxUlazniNiz";
            this.textBoxUlazniNiz.Size = new System.Drawing.Size(75, 20);
            this.textBoxUlazniNiz.TabIndex = 0;
            // 
            // buttonParsiraj
            // 
            this.buttonParsiraj.Location = new System.Drawing.Point(12, 191);
            this.buttonParsiraj.Name = "buttonParsiraj";
            this.buttonParsiraj.Size = new System.Drawing.Size(75, 52);
            this.buttonParsiraj.TabIndex = 3;
            this.buttonParsiraj.Text = "Parsiraj!";
            this.buttonParsiraj.UseVisualStyleBackColor = true;
            this.buttonParsiraj.Click += new System.EventHandler(this.buttonParsiraj_Click_1);
            // 
            // labelUlazniNiz
            // 
            this.labelUlazniNiz.AutoSize = true;
            this.labelUlazniNiz.Location = new System.Drawing.Point(12, 33);
            this.labelUlazniNiz.Name = "labelUlazniNiz";
            this.labelUlazniNiz.Size = new System.Drawing.Size(55, 13);
            this.labelUlazniNiz.TabIndex = 5;
            this.labelUlazniNiz.Text = "Ulazni niz:";
            // 
            // labelIspis
            // 
            this.labelIspis.AutoSize = true;
            this.labelIspis.Location = new System.Drawing.Point(93, 33);
            this.labelIspis.Name = "labelIspis";
            this.labelIspis.Size = new System.Drawing.Size(39, 13);
            this.labelIspis.TabIndex = 7;
            this.labelIspis.Text = "Akcija:";
            // 
            // labelGreskaNiz
            // 
            this.labelGreskaNiz.AutoSize = true;
            this.labelGreskaNiz.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.labelGreskaNiz.ForeColor = System.Drawing.Color.DarkRed;
            this.labelGreskaNiz.Location = new System.Drawing.Point(147, 9);
            this.labelGreskaNiz.Name = "labelGreskaNiz";
            this.labelGreskaNiz.Size = new System.Drawing.Size(0, 20);
            this.labelGreskaNiz.TabIndex = 9;
            // 
            // textBoxStanjeNaStogu
            // 
            this.textBoxStanjeNaStogu.Location = new System.Drawing.Point(313, 49);
            this.textBoxStanjeNaStogu.Multiline = true;
            this.textBoxStanjeNaStogu.Name = "textBoxStanjeNaStogu";
            this.textBoxStanjeNaStogu.ReadOnly = true;
            this.textBoxStanjeNaStogu.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.textBoxStanjeNaStogu.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.textBoxStanjeNaStogu.Size = new System.Drawing.Size(204, 194);
            this.textBoxStanjeNaStogu.TabIndex = 10;
            this.textBoxStanjeNaStogu.WordWrap = false;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(310, 33);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(84, 13);
            this.label1.TabIndex = 11;
            this.label1.Text = "Stanje na stogu:";
            // 
            // textBoxAkcija
            // 
            this.textBoxAkcija.Location = new System.Drawing.Point(96, 49);
            this.textBoxAkcija.Multiline = true;
            this.textBoxAkcija.Name = "textBoxAkcija";
            this.textBoxAkcija.ReadOnly = true;
            this.textBoxAkcija.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.textBoxAkcija.Size = new System.Drawing.Size(219, 194);
            this.textBoxAkcija.TabIndex = 8;
            this.textBoxAkcija.WordWrap = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.BackColor = System.Drawing.Color.LightGray;
            this.ClientSize = new System.Drawing.Size(519, 272);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBoxStanjeNaStogu);
            this.Controls.Add(this.labelGreskaNiz);
            this.Controls.Add(this.textBoxAkcija);
            this.Controls.Add(this.labelIspis);
            this.Controls.Add(this.labelUlazniNiz);
            this.Controls.Add(this.buttonParsiraj);
            this.Controls.Add(this.textBoxUlazniNiz);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.HelpButton = true;
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.Text = "Simulator LR(1) parsera";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBoxUlazniNiz;
        private System.Windows.Forms.Button buttonParsiraj;
        private System.Windows.Forms.Label labelUlazniNiz;
        private System.Windows.Forms.Label labelIspis;
        public System.Windows.Forms.TextBox textBoxAkcija;
        private System.Windows.Forms.Label labelGreskaNiz;
        public System.Windows.Forms.TextBox textBoxStanjeNaStogu;
        private System.Windows.Forms.Label label1;
    }
}


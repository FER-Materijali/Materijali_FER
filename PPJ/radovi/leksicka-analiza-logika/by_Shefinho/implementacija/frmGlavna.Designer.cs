namespace SSP_PPJ_62
{
    partial class frmGlavna
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
            this.tbUnos = new System.Windows.Forms.TextBox();
            this.tbIzlaz = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.btnKreni = new System.Windows.Forms.Button();
            this.lbKursor = new System.Windows.Forms.Label();
            this.btnInfo = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.checkBox3 = new System.Windows.Forms.CheckBox();
            this.checkBox2 = new System.Windows.Forms.CheckBox();
            this.checkBox1 = new System.Windows.Forms.CheckBox();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // tbUnos
            // 
            this.tbUnos.AcceptsReturn = true;
            this.tbUnos.AcceptsTab = true;
            this.tbUnos.Font = new System.Drawing.Font("Courier New", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.tbUnos.Location = new System.Drawing.Point(42, 62);
            this.tbUnos.Multiline = true;
            this.tbUnos.Name = "tbUnos";
            this.tbUnos.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.tbUnos.Size = new System.Drawing.Size(377, 314);
            this.tbUnos.TabIndex = 0;
            this.tbUnos.WordWrap = false;
            // 
            // tbIzlaz
            // 
            this.tbIzlaz.Font = new System.Drawing.Font("Courier New", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.tbIzlaz.Location = new System.Drawing.Point(482, 62);
            this.tbIzlaz.Multiline = true;
            this.tbIzlaz.Name = "tbIzlaz";
            this.tbIzlaz.ReadOnly = true;
            this.tbIzlaz.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.tbIzlaz.Size = new System.Drawing.Size(377, 314);
            this.tbIzlaz.TabIndex = 1;
            this.tbIzlaz.WordWrap = false;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label1.Location = new System.Drawing.Point(39, 36);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(48, 18);
            this.label1.TabIndex = 2;
            this.label1.Text = "Unos:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label2.Location = new System.Drawing.Point(479, 36);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(41, 18);
            this.label2.TabIndex = 3;
            this.label2.Text = "Izlaz:";
            // 
            // btnKreni
            // 
            this.btnKreni.Location = new System.Drawing.Point(42, 521);
            this.btnKreni.Name = "btnKreni";
            this.btnKreni.Size = new System.Drawing.Size(75, 23);
            this.btnKreni.TabIndex = 4;
            this.btnKreni.Text = "Kreni";
            this.btnKreni.UseVisualStyleBackColor = true;
            this.btnKreni.Click += new System.EventHandler(this.btnKreni_Click);
            // 
            // lbKursor
            // 
            this.lbKursor.AutoSize = true;
            this.lbKursor.Font = new System.Drawing.Font("Arial", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.lbKursor.Location = new System.Drawing.Point(39, 388);
            this.lbKursor.Name = "lbKursor";
            this.lbKursor.Size = new System.Drawing.Size(98, 15);
            this.lbKursor.TabIndex = 5;
            this.lbKursor.Text = "Položaj kursora: ";
            // 
            // btnInfo
            // 
            this.btnInfo.Location = new System.Drawing.Point(123, 521);
            this.btnInfo.Name = "btnInfo";
            this.btnInfo.Size = new System.Drawing.Size(93, 23);
            this.btnInfo.TabIndex = 8;
            this.btnInfo.Text = "O programu...";
            this.btnInfo.UseVisualStyleBackColor = true;
            this.btnInfo.Click += new System.EventHandler(this.btnInfo_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.checkBox3);
            this.groupBox1.Controls.Add(this.checkBox2);
            this.groupBox1.Controls.Add(this.checkBox1);
            this.groupBox1.Location = new System.Drawing.Point(42, 417);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(248, 89);
            this.groupBox1.TabIndex = 9;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Opcije:";
            // 
            // checkBox3
            // 
            this.checkBox3.AutoSize = true;
            this.checkBox3.Location = new System.Drawing.Point(16, 65);
            this.checkBox3.Name = "checkBox3";
            this.checkBox3.Size = new System.Drawing.Size(210, 17);
            this.checkBox3.TabIndex = 2;
            this.checkBox3.Text = "Ispiši niz pomaknutih semantičkih akcija";
            this.checkBox3.UseVisualStyleBackColor = true;
            // 
            // checkBox2
            // 
            this.checkBox2.AutoSize = true;
            this.checkBox2.Location = new System.Drawing.Point(16, 43);
            this.checkBox2.Name = "checkBox2";
            this.checkBox2.Size = new System.Drawing.Size(152, 17);
            this.checkBox2.TabIndex = 1;
            this.checkBox2.Text = "Ispiši niz semantičkih akcija";
            this.checkBox2.UseVisualStyleBackColor = true;
            // 
            // checkBox1
            // 
            this.checkBox1.AutoSize = true;
            this.checkBox1.Location = new System.Drawing.Point(16, 20);
            this.checkBox1.Name = "checkBox1";
            this.checkBox1.Size = new System.Drawing.Size(175, 17);
            this.checkBox1.TabIndex = 0;
            this.checkBox1.Text = "Ispiši atributno sintaksno stablo";
            this.checkBox1.UseVisualStyleBackColor = true;
            // 
            // frmGlavna
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(907, 556);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.btnInfo);
            this.Controls.Add(this.lbKursor);
            this.Controls.Add(this.btnKreni);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.tbIzlaz);
            this.Controls.Add(this.tbUnos);
            this.Name = "frmGlavna";
            this.Text = "PPJ SSP - zadatak 62";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        

        #endregion

        private System.Windows.Forms.TextBox tbUnos;
        private System.Windows.Forms.TextBox tbIzlaz;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button btnKreni;
        private System.Windows.Forms.Label lbKursor;
        private System.Windows.Forms.Button btnInfo;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.CheckBox checkBox3;
        private System.Windows.Forms.CheckBox checkBox2;
        private System.Windows.Forms.CheckBox checkBox1;
    }
}


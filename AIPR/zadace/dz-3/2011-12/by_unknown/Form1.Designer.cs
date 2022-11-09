namespace GenetskiApr
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
            this.button1 = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.rb1 = new System.Windows.Forms.RadioButton();
            this.rb2 = new System.Windows.Forms.RadioButton();
            this.rb3 = new System.Windows.Forms.RadioButton();
            this.rb4 = new System.Windows.Forms.RadioButton();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.tbP = new System.Windows.Forms.TextBox();
            this.tbPopulacija = new System.Windows.Forms.TextBox();
            this.tbMutacija = new System.Windows.Forms.TextBox();
            this.tbMax = new System.Windows.Forms.TextBox();
            this.tbMin = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.tbPreciznost = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.tbN = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.tbVrijednosti = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(12, 19);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(124, 54);
            this.button1.TabIndex = 0;
            this.button1.Text = "Pokreni";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // textBox1
            // 
            this.textBox1.BackColor = System.Drawing.Color.LavenderBlush;
            this.textBox1.Location = new System.Drawing.Point(12, 122);
            this.textBox1.Multiline = true;
            this.textBox1.Name = "textBox1";
            this.textBox1.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.textBox1.Size = new System.Drawing.Size(1096, 461);
            this.textBox1.TabIndex = 1;
            // 
            // rb1
            // 
            this.rb1.AutoSize = true;
            this.rb1.Checked = true;
            this.rb1.Location = new System.Drawing.Point(563, 22);
            this.rb1.Name = "rb1";
            this.rb1.Size = new System.Drawing.Size(205, 17);
            this.rb1.TabIndex = 2;
            this.rb1.TabStop = true;
            this.rb1.Text = "(x1-p1)^2 + (x2-p2)^2 + ... + (x5-p5)^2 ";
            this.rb1.UseVisualStyleBackColor = true;
            // 
            // rb2
            // 
            this.rb2.AutoSize = true;
            this.rb2.Location = new System.Drawing.Point(563, 85);
            this.rb2.Name = "rb2";
            this.rb2.Size = new System.Drawing.Size(153, 17);
            this.rb2.TabIndex = 3;
            this.rb2.Text = "|(x-y)*(x+y)| + (x^2+y^2)^0.5";
            this.rb2.UseVisualStyleBackColor = true;
            // 
            // rb3
            // 
            this.rb3.AutoSize = true;
            this.rb3.Location = new System.Drawing.Point(863, 22);
            this.rb3.Name = "rb3";
            this.rb3.Size = new System.Drawing.Size(74, 17);
            this.rb3.TabIndex = 4;
            this.rb3.Text = "Funkcija 6";
            this.rb3.UseVisualStyleBackColor = true;
            // 
            // rb4
            // 
            this.rb4.AutoSize = true;
            this.rb4.Location = new System.Drawing.Point(863, 45);
            this.rb4.Name = "rb4";
            this.rb4.Size = new System.Drawing.Size(74, 17);
            this.rb4.TabIndex = 5;
            this.rb4.Text = "Funkcija 7";
            this.rb4.UseVisualStyleBackColor = true;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(161, 22);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(98, 13);
            this.label1.TabIndex = 6;
            this.label1.Text = "Veličina populacije:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(406, 19);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(107, 13);
            this.label2.TabIndex = 7;
            this.label2.Text = "Vjerojatnost mutacije:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(561, 56);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(21, 13);
            this.label3.TabIndex = 8;
            this.label3.Text = "px:";
            // 
            // tbP
            // 
            this.tbP.Location = new System.Drawing.Point(588, 53);
            this.tbP.Name = "tbP";
            this.tbP.Size = new System.Drawing.Size(180, 20);
            this.tbP.TabIndex = 9;
            this.tbP.Text = "1 2 3 4 5";
            // 
            // tbPopulacija
            // 
            this.tbPopulacija.Location = new System.Drawing.Point(275, 19);
            this.tbPopulacija.Name = "tbPopulacija";
            this.tbPopulacija.Size = new System.Drawing.Size(100, 20);
            this.tbPopulacija.TabIndex = 10;
            this.tbPopulacija.Text = "50";
            // 
            // tbMutacija
            // 
            this.tbMutacija.Location = new System.Drawing.Point(409, 35);
            this.tbMutacija.Name = "tbMutacija";
            this.tbMutacija.Size = new System.Drawing.Size(100, 20);
            this.tbMutacija.TabIndex = 11;
            this.tbMutacija.Text = "0,1";
            // 
            // tbMax
            // 
            this.tbMax.Location = new System.Drawing.Point(275, 82);
            this.tbMax.Name = "tbMax";
            this.tbMax.Size = new System.Drawing.Size(100, 20);
            this.tbMax.TabIndex = 15;
            this.tbMax.Text = "100";
            // 
            // tbMin
            // 
            this.tbMin.Location = new System.Drawing.Point(275, 49);
            this.tbMin.Name = "tbMin";
            this.tbMin.Size = new System.Drawing.Size(100, 20);
            this.tbMin.TabIndex = 14;
            this.tbMin.Text = "-100";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(161, 85);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(30, 13);
            this.label4.TabIndex = 13;
            this.label4.Text = "Max:";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(161, 52);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(27, 13);
            this.label5.TabIndex = 12;
            this.label5.Text = "Min:";
            // 
            // tbPreciznost
            // 
            this.tbPreciznost.Location = new System.Drawing.Point(409, 78);
            this.tbPreciznost.Name = "tbPreciznost";
            this.tbPreciznost.Size = new System.Drawing.Size(100, 20);
            this.tbPreciznost.TabIndex = 17;
            this.tbPreciznost.Text = "3";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(406, 62);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(114, 13);
            this.label6.TabIndex = 16;
            this.label6.Text = "Znamenke preciznosti:";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(12, 87);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(21, 13);
            this.label7.TabIndex = 18;
            this.label7.Text = "N: ";
            // 
            // tbN
            // 
            this.tbN.Location = new System.Drawing.Point(40, 85);
            this.tbN.Name = "tbN";
            this.tbN.Size = new System.Drawing.Size(81, 20);
            this.tbN.TabIndex = 19;
            this.tbN.Text = "100000";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(860, 71);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(66, 13);
            this.label8.TabIndex = 20;
            this.label8.Text = "Broj varijabli:";
            // 
            // tbVrijednosti
            // 
            this.tbVrijednosti.Location = new System.Drawing.Point(880, 90);
            this.tbVrijednosti.Name = "tbVrijednosti";
            this.tbVrijednosti.Size = new System.Drawing.Size(45, 20);
            this.tbVrijednosti.TabIndex = 21;
            this.tbVrijednosti.Text = "2";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(1121, 585);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(10, 13);
            this.label9.TabIndex = 22;
            this.label9.Text = ".";
            this.label9.Click += new System.EventHandler(this.label9_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Pink;
            this.ClientSize = new System.Drawing.Size(1130, 596);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.tbVrijednosti);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.tbN);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.tbPreciznost);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.tbMax);
            this.Controls.Add(this.tbMin);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.tbMutacija);
            this.Controls.Add(this.tbPopulacija);
            this.Controls.Add(this.tbP);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.rb4);
            this.Controls.Add(this.rb3);
            this.Controls.Add(this.rb2);
            this.Controls.Add(this.rb1);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.button1);
            this.Name = "Form1";
            this.Text = "Program je spor i ne daje baš najbolje rezultate...";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.RadioButton rb1;
        private System.Windows.Forms.RadioButton rb2;
        private System.Windows.Forms.RadioButton rb3;
        private System.Windows.Forms.RadioButton rb4;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox tbP;
        private System.Windows.Forms.TextBox tbPopulacija;
        private System.Windows.Forms.TextBox tbMutacija;
        private System.Windows.Forms.TextBox tbMax;
        private System.Windows.Forms.TextBox tbMin;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox tbPreciznost;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox tbN;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.TextBox tbVrijednosti;
        private System.Windows.Forms.Label label9;
    }
}


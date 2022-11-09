namespace APR___lab4
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
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.tbA = new System.Windows.Forms.TextBox();
            this.tbB = new System.Windows.Forms.TextBox();
            this.tbX = new System.Windows.Forms.TextBox();
            this.tbT = new System.Windows.Forms.TextBox();
            this.tbI = new System.Windows.Forms.TextBox();
            this.tbIspis = new System.Windows.Forms.TextBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.rbTrapezni = new System.Windows.Forms.RadioButton();
            this.rbRungeKutta = new System.Windows.Forms.RadioButton();
            this.tbEkran = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.label7 = new System.Windows.Forms.Label();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(40, 46);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(55, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Matrica A:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(40, 82);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(55, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Matrica B:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(40, 116);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(36, 13);
            this.label3.TabIndex = 2;
            this.label3.Text = "x(t=0):";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(40, 147);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(48, 13);
            this.label4.TabIndex = 3;
            this.label4.Text = "Korak T:";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(40, 178);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(85, 13);
            this.label5.TabIndex = 4;
            this.label5.Text = "Duljina intervala:";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(40, 214);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(75, 13);
            this.label6.TabIndex = 5;
            this.label6.Text = "Korak za ispis:";
            // 
            // tbA
            // 
            this.tbA.Location = new System.Drawing.Point(131, 43);
            this.tbA.Name = "tbA";
            this.tbA.Size = new System.Drawing.Size(100, 20);
            this.tbA.TabIndex = 6;
            this.tbA.Text = "A.txt";
            // 
            // tbB
            // 
            this.tbB.Location = new System.Drawing.Point(131, 79);
            this.tbB.Name = "tbB";
            this.tbB.Size = new System.Drawing.Size(100, 20);
            this.tbB.TabIndex = 7;
            this.tbB.Text = "B.txt";
            // 
            // tbX
            // 
            this.tbX.Location = new System.Drawing.Point(131, 113);
            this.tbX.Name = "tbX";
            this.tbX.Size = new System.Drawing.Size(100, 20);
            this.tbX.TabIndex = 8;
            this.tbX.Text = "X.txt";
            // 
            // tbT
            // 
            this.tbT.Location = new System.Drawing.Point(131, 144);
            this.tbT.Name = "tbT";
            this.tbT.Size = new System.Drawing.Size(100, 20);
            this.tbT.TabIndex = 9;
            this.tbT.Text = "0,1";
            // 
            // tbI
            // 
            this.tbI.Location = new System.Drawing.Point(131, 175);
            this.tbI.Name = "tbI";
            this.tbI.Size = new System.Drawing.Size(100, 20);
            this.tbI.TabIndex = 10;
            this.tbI.Text = "1,0";
            // 
            // tbIspis
            // 
            this.tbIspis.Location = new System.Drawing.Point(131, 211);
            this.tbIspis.Name = "tbIspis";
            this.tbIspis.Size = new System.Drawing.Size(100, 20);
            this.tbIspis.TabIndex = 11;
            this.tbIspis.Text = "2";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.rbTrapezni);
            this.groupBox1.Controls.Add(this.rbRungeKutta);
            this.groupBox1.Location = new System.Drawing.Point(43, 261);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(188, 121);
            this.groupBox1.TabIndex = 12;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Postupak rješavanja:";
            // 
            // rbTrapezni
            // 
            this.rbTrapezni.AutoSize = true;
            this.rbTrapezni.Location = new System.Drawing.Point(24, 71);
            this.rbTrapezni.Name = "rbTrapezni";
            this.rbTrapezni.Size = new System.Drawing.Size(113, 17);
            this.rbTrapezni.TabIndex = 1;
            this.rbTrapezni.Text = "Trapezni postupak";
            this.rbTrapezni.UseVisualStyleBackColor = true;
            // 
            // rbRungeKutta
            // 
            this.rbRungeKutta.AutoSize = true;
            this.rbRungeKutta.Checked = true;
            this.rbRungeKutta.Location = new System.Drawing.Point(24, 37);
            this.rbRungeKutta.Name = "rbRungeKutta";
            this.rbRungeKutta.Size = new System.Drawing.Size(132, 17);
            this.rbRungeKutta.TabIndex = 0;
            this.rbRungeKutta.TabStop = true;
            this.rbRungeKutta.Text = "Runge Kutta postupak";
            this.rbRungeKutta.UseVisualStyleBackColor = true;
            // 
            // tbEkran
            // 
            this.tbEkran.BackColor = System.Drawing.Color.LavenderBlush;
            this.tbEkran.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.tbEkran.Location = new System.Drawing.Point(278, 38);
            this.tbEkran.Multiline = true;
            this.tbEkran.Name = "tbEkran";
            this.tbEkran.ReadOnly = true;
            this.tbEkran.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.tbEkran.Size = new System.Drawing.Size(341, 488);
            this.tbEkran.TabIndex = 0;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(43, 451);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(188, 75);
            this.button1.TabIndex = 13;
            this.button1.Text = "Rješavanje sustava:";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click_1);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(624, 539);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(10, 13);
            this.label7.TabIndex = 14;
            this.label7.Text = ".";
            this.label7.Click += new System.EventHandler(this.label7_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Pink;
            this.ClientSize = new System.Drawing.Size(635, 551);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.tbEkran);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.tbIspis);
            this.Controls.Add(this.tbI);
            this.Controls.Add(this.tbT);
            this.Controls.Add(this.tbX);
            this.Controls.Add(this.tbB);
            this.Controls.Add(this.tbA);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "APR, 4. dz";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox tbA;
        private System.Windows.Forms.TextBox tbB;
        private System.Windows.Forms.TextBox tbX;
        private System.Windows.Forms.TextBox tbT;
        private System.Windows.Forms.TextBox tbI;
        private System.Windows.Forms.TextBox tbIspis;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RadioButton rbTrapezni;
        private System.Windows.Forms.RadioButton rbRungeKutta;
        private System.Windows.Forms.TextBox tbEkran;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label7;

    }
}


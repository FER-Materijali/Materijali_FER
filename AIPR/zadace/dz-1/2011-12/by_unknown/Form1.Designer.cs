namespace APR___lab1
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
            this.txtMatricaA = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.txtVektorX = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.txtVektorB = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.btnUcitajA = new System.Windows.Forms.Button();
            this.btnPohraniUDatoteku = new System.Windows.Forms.Button();
            this.btnUcitajB = new System.Windows.Forms.Button();
            this.txtKonstantaUsporedbe = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.btnPostaviKonstantu = new System.Windows.Forms.Button();
            this.txtRezultati = new System.Windows.Forms.TextBox();
            this.btnLU = new System.Windows.Forms.Button();
            this.btnLUP = new System.Windows.Forms.Button();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // txtMatricaA
            // 
            this.txtMatricaA.BackColor = System.Drawing.Color.Pink;
            this.txtMatricaA.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.txtMatricaA.Location = new System.Drawing.Point(22, 36);
            this.txtMatricaA.Multiline = true;
            this.txtMatricaA.Name = "txtMatricaA";
            this.txtMatricaA.Size = new System.Drawing.Size(400, 175);
            this.txtMatricaA.TabIndex = 1;
            this.txtMatricaA.WordWrap = false;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label1.Location = new System.Drawing.Point(178, 13);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(76, 20);
            this.label1.TabIndex = 2;
            this.label1.Text = "Matrica A";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label2.Location = new System.Drawing.Point(475, 13);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(67, 20);
            this.label2.TabIndex = 3;
            this.label2.Text = "Vektor x";
            // 
            // txtVektorX
            // 
            this.txtVektorX.BackColor = System.Drawing.Color.Pink;
            this.txtVektorX.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.txtVektorX.Location = new System.Drawing.Point(446, 36);
            this.txtVektorX.Multiline = true;
            this.txtVektorX.Name = "txtVektorX";
            this.txtVektorX.Size = new System.Drawing.Size(125, 175);
            this.txtVektorX.TabIndex = 4;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(428, 122);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(12, 13);
            this.label3.TabIndex = 5;
            this.label3.Text = "x";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(577, 122);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(13, 13);
            this.label4.TabIndex = 6;
            this.label4.Text = "=";
            // 
            // txtVektorB
            // 
            this.txtVektorB.BackColor = System.Drawing.Color.Pink;
            this.txtVektorB.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.txtVektorB.Location = new System.Drawing.Point(596, 36);
            this.txtVektorB.Multiline = true;
            this.txtVektorB.Name = "txtVektorB";
            this.txtVektorB.Size = new System.Drawing.Size(125, 175);
            this.txtVektorB.TabIndex = 7;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label5.Location = new System.Drawing.Point(616, 13);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(69, 20);
            this.label5.TabIndex = 8;
            this.label5.Text = "Vektor b";
            // 
            // btnUcitajA
            // 
            this.btnUcitajA.Location = new System.Drawing.Point(163, 217);
            this.btnUcitajA.Name = "btnUcitajA";
            this.btnUcitajA.Size = new System.Drawing.Size(125, 31);
            this.btnUcitajA.TabIndex = 9;
            this.btnUcitajA.Text = "Učitaj iz datoteke";
            this.btnUcitajA.UseVisualStyleBackColor = true;
            this.btnUcitajA.Click += new System.EventHandler(this.btnUcitajA_Click);
            // 
            // btnPohraniUDatoteku
            // 
            this.btnPohraniUDatoteku.Location = new System.Drawing.Point(446, 217);
            this.btnPohraniUDatoteku.Name = "btnPohraniUDatoteku";
            this.btnPohraniUDatoteku.Size = new System.Drawing.Size(125, 31);
            this.btnPohraniUDatoteku.TabIndex = 10;
            this.btnPohraniUDatoteku.Text = "Pohrani u datoteku";
            this.btnPohraniUDatoteku.UseVisualStyleBackColor = true;
            this.btnPohraniUDatoteku.Click += new System.EventHandler(this.btnPohraniUDatoteku_Click);
            // 
            // btnUcitajB
            // 
            this.btnUcitajB.Location = new System.Drawing.Point(596, 217);
            this.btnUcitajB.Name = "btnUcitajB";
            this.btnUcitajB.Size = new System.Drawing.Size(128, 31);
            this.btnUcitajB.TabIndex = 11;
            this.btnUcitajB.Text = "Učitaj iz datoteke";
            this.btnUcitajB.UseVisualStyleBackColor = true;
            this.btnUcitajB.Click += new System.EventHandler(this.btnUcitajB_Click);
            // 
            // txtKonstantaUsporedbe
            // 
            this.txtKonstantaUsporedbe.BackColor = System.Drawing.Color.Pink;
            this.txtKonstantaUsporedbe.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.txtKonstantaUsporedbe.Location = new System.Drawing.Point(53, 295);
            this.txtKonstantaUsporedbe.Name = "txtKonstantaUsporedbe";
            this.txtKonstantaUsporedbe.Size = new System.Drawing.Size(198, 29);
            this.txtKonstantaUsporedbe.TabIndex = 12;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label6.Location = new System.Drawing.Point(50, 278);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(131, 13);
            this.label6.TabIndex = 13;
            this.label6.Text = "Konstanta usporedbe:";
            // 
            // btnPostaviKonstantu
            // 
            this.btnPostaviKonstantu.Location = new System.Drawing.Point(53, 332);
            this.btnPostaviKonstantu.Name = "btnPostaviKonstantu";
            this.btnPostaviKonstantu.Size = new System.Drawing.Size(198, 28);
            this.btnPostaviKonstantu.TabIndex = 14;
            this.btnPostaviKonstantu.Text = "Postavi";
            this.btnPostaviKonstantu.UseVisualStyleBackColor = true;
            this.btnPostaviKonstantu.Click += new System.EventHandler(this.button2_Click);
            // 
            // txtRezultati
            // 
            this.txtRezultati.BackColor = System.Drawing.Color.Pink;
            this.txtRezultati.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.txtRezultati.Location = new System.Drawing.Point(321, 292);
            this.txtRezultati.Multiline = true;
            this.txtRezultati.Name = "txtRezultati";
            this.txtRezultati.ReadOnly = true;
            this.txtRezultati.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.txtRezultati.Size = new System.Drawing.Size(400, 350);
            this.txtRezultati.TabIndex = 15;
            // 
            // btnLU
            // 
            this.btnLU.Location = new System.Drawing.Point(53, 540);
            this.btnLU.Name = "btnLU";
            this.btnLU.Size = new System.Drawing.Size(198, 48);
            this.btnLU.TabIndex = 16;
            this.btnLU.Text = "Rješavanje LU";
            this.btnLU.UseVisualStyleBackColor = true;
            this.btnLU.Click += new System.EventHandler(this.btnLU_Click);
            // 
            // btnLUP
            // 
            this.btnLUP.Location = new System.Drawing.Point(53, 594);
            this.btnLUP.Name = "btnLUP";
            this.btnLUP.Size = new System.Drawing.Size(198, 48);
            this.btnLUP.TabIndex = 17;
            this.btnLUP.Text = "Rješavanje LUP";
            this.btnLUP.UseVisualStyleBackColor = true;
            this.btnLUP.Click += new System.EventHandler(this.btnLUP_Click);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label7.Location = new System.Drawing.Point(318, 271);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(199, 18);
            this.label7.TabIndex = 18;
            this.label7.Text = "Međurezultati i obavijesti:";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(0, 654);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(10, 13);
            this.label8.TabIndex = 19;
            this.label8.Text = ".";
            this.label8.Click += new System.EventHandler(this.label8_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.HotPink;
            this.ClientSize = new System.Drawing.Size(741, 666);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.btnLUP);
            this.Controls.Add(this.btnLU);
            this.Controls.Add(this.txtRezultati);
            this.Controls.Add(this.btnPostaviKonstantu);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.txtKonstantaUsporedbe);
            this.Controls.Add(this.btnUcitajB);
            this.Controls.Add(this.btnPohraniUDatoteku);
            this.Controls.Add(this.btnUcitajA);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.txtVektorB);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.txtVektorX);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.txtMatricaA);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Rješavanje sustava linearnih jednadžbi";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtMatricaA;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox txtVektorX;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox txtVektorB;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Button btnUcitajA;
        private System.Windows.Forms.Button btnPohraniUDatoteku;
        private System.Windows.Forms.Button btnUcitajB;
        private System.Windows.Forms.TextBox txtKonstantaUsporedbe;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Button btnPostaviKonstantu;
        private System.Windows.Forms.TextBox txtRezultati;
        private System.Windows.Forms.Button btnLU;
        private System.Windows.Forms.Button btnLUP;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
    }
}


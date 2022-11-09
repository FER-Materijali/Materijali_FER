namespace APR___lab2
{
    partial class frmB
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
            this.label5 = new System.Windows.Forms.Label();
            this.txtPx = new System.Windows.Forms.TextBox();
            this.txtPrikaz = new System.Windows.Forms.TextBox();
            this.btnPokreni = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.rb2 = new System.Windows.Forms.RadioButton();
            this.rb1 = new System.Windows.Forms.RadioButton();
            this.btnUcitaj = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.txtPreciznost = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.txtKoeficijentRefleksije = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.txtPocetnaTocka = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label5.Location = new System.Drawing.Point(391, 111);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(27, 18);
            this.label5.TabIndex = 33;
            this.label5.Text = "px:";
            // 
            // txtPx
            // 
            this.txtPx.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.txtPx.Location = new System.Drawing.Point(416, 107);
            this.txtPx.Name = "txtPx";
            this.txtPx.Size = new System.Drawing.Size(225, 26);
            this.txtPx.TabIndex = 32;
            this.txtPx.Text = "1 2 3";
            // 
            // txtPrikaz
            // 
            this.txtPrikaz.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.txtPrikaz.Location = new System.Drawing.Point(52, 319);
            this.txtPrikaz.Multiline = true;
            this.txtPrikaz.Name = "txtPrikaz";
            this.txtPrikaz.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.txtPrikaz.Size = new System.Drawing.Size(596, 476);
            this.txtPrikaz.TabIndex = 31;
            // 
            // btnPokreni
            // 
            this.btnPokreni.Enabled = false;
            this.btnPokreni.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.btnPokreni.Location = new System.Drawing.Point(372, 245);
            this.btnPokreni.Name = "btnPokreni";
            this.btnPokreni.Size = new System.Drawing.Size(269, 42);
            this.btnPokreni.TabIndex = 30;
            this.btnPokreni.Text = "Pokreni Box postupak";
            this.btnPokreni.UseVisualStyleBackColor = true;
            this.btnPokreni.Click += new System.EventHandler(this.btnPokreni_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label4.Location = new System.Drawing.Point(368, 28);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(234, 20);
            this.label4.TabIndex = 29;
            this.label4.Text = "Funkcije za traženje minimuma: ";
            // 
            // rb2
            // 
            this.rb2.AutoSize = true;
            this.rb2.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.rb2.Location = new System.Drawing.Point(372, 81);
            this.rb2.Name = "rb2";
            this.rb2.Size = new System.Drawing.Size(276, 22);
            this.rb2.TabIndex = 26;
            this.rb2.Text = "(x1-p1)^2 + (x2-p2)^2 + ... + (x5-p5)^2 ";
            this.rb2.UseVisualStyleBackColor = true;
            // 
            // rb1
            // 
            this.rb1.AutoSize = true;
            this.rb1.Checked = true;
            this.rb1.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.rb1.Location = new System.Drawing.Point(372, 54);
            this.rb1.Name = "rb1";
            this.rb1.Size = new System.Drawing.Size(147, 22);
            this.rb1.TabIndex = 25;
            this.rb1.TabStop = true;
            this.rb1.Text = "(x-4)^2 + 4*(y-2)^2";
            this.rb1.UseVisualStyleBackColor = true;
            // 
            // btnUcitaj
            // 
            this.btnUcitaj.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.btnUcitaj.Location = new System.Drawing.Point(52, 245);
            this.btnUcitaj.Name = "btnUcitaj";
            this.btnUcitaj.Size = new System.Drawing.Size(249, 42);
            this.btnUcitaj.TabIndex = 23;
            this.btnUcitaj.Text = "Učitaj vrijednosti";
            this.btnUcitaj.UseVisualStyleBackColor = true;
            this.btnUcitaj.Click += new System.EventHandler(this.btnUcitaj_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label3.Location = new System.Drawing.Point(48, 157);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(87, 20);
            this.label3.TabIndex = 22;
            this.label3.Text = "Preciznost:";
            // 
            // txtPreciznost
            // 
            this.txtPreciznost.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.txtPreciznost.Location = new System.Drawing.Point(52, 180);
            this.txtPreciznost.Name = "txtPreciznost";
            this.txtPreciznost.Size = new System.Drawing.Size(249, 26);
            this.txtPreciznost.TabIndex = 21;
            this.txtPreciznost.Text = "0,01";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label2.Location = new System.Drawing.Point(48, 96);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(152, 20);
            this.label2.TabIndex = 20;
            this.label2.Text = "Koeficijent refleksije:";
            // 
            // txtKoeficijentRefleksije
            // 
            this.txtKoeficijentRefleksije.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.txtKoeficijentRefleksije.Location = new System.Drawing.Point(52, 119);
            this.txtKoeficijentRefleksije.Name = "txtKoeficijentRefleksije";
            this.txtKoeficijentRefleksije.Size = new System.Drawing.Size(249, 26);
            this.txtKoeficijentRefleksije.TabIndex = 19;
            this.txtKoeficijentRefleksije.Text = "1,3";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label1.Location = new System.Drawing.Point(48, 28);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(115, 20);
            this.label1.TabIndex = 18;
            this.label1.Text = "Početna točka:";
            // 
            // txtPocetnaTocka
            // 
            this.txtPocetnaTocka.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.txtPocetnaTocka.Location = new System.Drawing.Point(52, 51);
            this.txtPocetnaTocka.Name = "txtPocetnaTocka";
            this.txtPocetnaTocka.Size = new System.Drawing.Size(249, 26);
            this.txtPocetnaTocka.TabIndex = 17;
            this.txtPocetnaTocka.Text = "-4 -3";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label6.Location = new System.Drawing.Point(368, 151);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(98, 20);
            this.label6.TabIndex = 34;
            this.label6.Text = "Ograničenja:";
            // 
            // label7
            // 
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label7.Location = new System.Drawing.Point(369, 181);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(269, 52);
            this.label7.TabIndex = 35;
            this.label7.Text = "Implicitna ograničenja:  x1-x2 <= 0,  x1-2 <= 0\r\n\r\nEksplicitna ograničenja: x[i] " +
                "€ [-100, 100]";
            // 
            // frmB
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Pink;
            this.ClientSize = new System.Drawing.Size(699, 782);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.txtPx);
            this.Controls.Add(this.txtPrikaz);
            this.Controls.Add(this.btnPokreni);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.rb2);
            this.Controls.Add(this.rb1);
            this.Controls.Add(this.btnUcitaj);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.txtPreciznost);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.txtKoeficijentRefleksije);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.txtPocetnaTocka);
            this.Name = "frmB";
            this.Text = "frmB";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox txtPx;
        private System.Windows.Forms.TextBox txtPrikaz;
        private System.Windows.Forms.Button btnPokreni;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.RadioButton rb2;
        private System.Windows.Forms.RadioButton rb1;
        private System.Windows.Forms.Button btnUcitaj;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox txtPreciznost;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox txtKoeficijentRefleksije;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox txtPocetnaTocka;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
    }
}
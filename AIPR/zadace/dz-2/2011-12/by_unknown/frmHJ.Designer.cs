namespace APR___lab2
{
    partial class frmHJ
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
            this.txtPocetnaTocka = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.txtVektorPomaka = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.txtVektorPreciznosti = new System.Windows.Forms.TextBox();
            this.btnUcitaj = new System.Windows.Forms.Button();
            this.rb1 = new System.Windows.Forms.RadioButton();
            this.rb2 = new System.Windows.Forms.RadioButton();
            this.rb3 = new System.Windows.Forms.RadioButton();
            this.rb4 = new System.Windows.Forms.RadioButton();
            this.rb5 = new System.Windows.Forms.RadioButton();
            this.label4 = new System.Windows.Forms.Label();
            this.btnPokreni = new System.Windows.Forms.Button();
            this.txtPrikaz = new System.Windows.Forms.TextBox();
            this.txtPx = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // txtPocetnaTocka
            // 
            this.txtPocetnaTocka.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.txtPocetnaTocka.Location = new System.Drawing.Point(30, 45);
            this.txtPocetnaTocka.Name = "txtPocetnaTocka";
            this.txtPocetnaTocka.Size = new System.Drawing.Size(249, 26);
            this.txtPocetnaTocka.TabIndex = 0;
            this.txtPocetnaTocka.Text = "2 2";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label1.Location = new System.Drawing.Point(26, 22);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(237, 20);
            this.label1.TabIndex = 1;
            this.label1.Text = "Početna točka pretraživanja, Xp:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label2.Location = new System.Drawing.Point(26, 75);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(145, 20);
            this.label2.TabIndex = 3;
            this.label2.Text = "Vektor pomaka, dx:";
            // 
            // txtVektorPomaka
            // 
            this.txtVektorPomaka.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.txtVektorPomaka.Location = new System.Drawing.Point(30, 98);
            this.txtVektorPomaka.Name = "txtVektorPomaka";
            this.txtVektorPomaka.Size = new System.Drawing.Size(249, 26);
            this.txtVektorPomaka.TabIndex = 2;
            this.txtVektorPomaka.Text = "1 1";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label3.Location = new System.Drawing.Point(26, 136);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(211, 20);
            this.label3.TabIndex = 5;
            this.label3.Text = "Vektor granične preznosti, e:";
            // 
            // txtVektorPreciznosti
            // 
            this.txtVektorPreciznosti.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.txtVektorPreciznosti.Location = new System.Drawing.Point(30, 159);
            this.txtVektorPreciznosti.Name = "txtVektorPreciznosti";
            this.txtVektorPreciznosti.Size = new System.Drawing.Size(249, 26);
            this.txtVektorPreciznosti.TabIndex = 4;
            this.txtVektorPreciznosti.Text = "0,1 0,1";
            // 
            // btnUcitaj
            // 
            this.btnUcitaj.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.btnUcitaj.Location = new System.Drawing.Point(30, 229);
            this.btnUcitaj.Name = "btnUcitaj";
            this.btnUcitaj.Size = new System.Drawing.Size(249, 42);
            this.btnUcitaj.TabIndex = 6;
            this.btnUcitaj.Text = "Učitaj vrijednosti";
            this.btnUcitaj.UseVisualStyleBackColor = true;
            this.btnUcitaj.Click += new System.EventHandler(this.btnUcitaj_Click);
            // 
            // rb1
            // 
            this.rb1.AutoSize = true;
            this.rb1.Checked = true;
            this.rb1.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.rb1.Location = new System.Drawing.Point(350, 49);
            this.rb1.Name = "rb1";
            this.rb1.Size = new System.Drawing.Size(169, 22);
            this.rb1.TabIndex = 7;
            this.rb1.TabStop = true;
            this.rb1.Text = "10*(x^2-y)^2 + (1-x)^2";
            this.rb1.UseVisualStyleBackColor = true;
            // 
            // rb2
            // 
            this.rb2.AutoSize = true;
            this.rb2.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.rb2.Location = new System.Drawing.Point(350, 77);
            this.rb2.Name = "rb2";
            this.rb2.Size = new System.Drawing.Size(147, 22);
            this.rb2.TabIndex = 8;
            this.rb2.TabStop = true;
            this.rb2.Text = "(x-4)^2 + 4*(y-2)^2";
            this.rb2.UseVisualStyleBackColor = true;
            // 
            // rb3
            // 
            this.rb3.AutoSize = true;
            this.rb3.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.rb3.Location = new System.Drawing.Point(350, 104);
            this.rb3.Name = "rb3";
            this.rb3.Size = new System.Drawing.Size(276, 22);
            this.rb3.TabIndex = 9;
            this.rb3.TabStop = true;
            this.rb3.Text = "(x1-p1)^2 + (x2-p2)^2 + ... + (x5-p5)^2 ";
            this.rb3.UseVisualStyleBackColor = true;
            // 
            // rb4
            // 
            this.rb4.AutoSize = true;
            this.rb4.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.rb4.Location = new System.Drawing.Point(350, 159);
            this.rb4.Name = "rb4";
            this.rb4.Size = new System.Drawing.Size(211, 22);
            this.rb4.TabIndex = 10;
            this.rb4.TabStop = true;
            this.rb4.Text = "|(x-y)*(x+y)| + (x^2+y^2)^0.5";
            this.rb4.UseVisualStyleBackColor = true;
            // 
            // rb5
            // 
            this.rb5.AutoSize = true;
            this.rb5.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.rb5.Location = new System.Drawing.Point(350, 187);
            this.rb5.Name = "rb5";
            this.rb5.Size = new System.Drawing.Size(46, 22);
            this.rb5.TabIndex = 11;
            this.rb5.TabStop = true;
            this.rb5.Text = "----";
            this.rb5.UseVisualStyleBackColor = true;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label4.Location = new System.Drawing.Point(346, 22);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(234, 20);
            this.label4.TabIndex = 12;
            this.label4.Text = "Funkcije za traženje minimuma: ";
            // 
            // btnPokreni
            // 
            this.btnPokreni.Enabled = false;
            this.btnPokreni.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.btnPokreni.Location = new System.Drawing.Point(350, 229);
            this.btnPokreni.Name = "btnPokreni";
            this.btnPokreni.Size = new System.Drawing.Size(269, 42);
            this.btnPokreni.TabIndex = 13;
            this.btnPokreni.Text = "Pokreni Hooke-Jeeves postupak";
            this.btnPokreni.UseVisualStyleBackColor = true;
            this.btnPokreni.Click += new System.EventHandler(this.btnPokreni_Click);
            // 
            // txtPrikaz
            // 
            this.txtPrikaz.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.txtPrikaz.Location = new System.Drawing.Point(30, 313);
            this.txtPrikaz.Multiline = true;
            this.txtPrikaz.Name = "txtPrikaz";
            this.txtPrikaz.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.txtPrikaz.Size = new System.Drawing.Size(596, 336);
            this.txtPrikaz.TabIndex = 14;
            // 
            // txtPx
            // 
            this.txtPx.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.txtPx.Location = new System.Drawing.Point(394, 130);
            this.txtPx.Name = "txtPx";
            this.txtPx.Size = new System.Drawing.Size(225, 26);
            this.txtPx.TabIndex = 15;
            this.txtPx.Text = "1 2 3";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label5.Location = new System.Drawing.Point(369, 134);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(27, 18);
            this.label5.TabIndex = 16;
            this.label5.Text = "px:";
            // 
            // frmHJ
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Pink;
            this.ClientSize = new System.Drawing.Size(643, 677);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.txtPx);
            this.Controls.Add(this.txtPrikaz);
            this.Controls.Add(this.btnPokreni);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.rb5);
            this.Controls.Add(this.rb4);
            this.Controls.Add(this.rb3);
            this.Controls.Add(this.rb2);
            this.Controls.Add(this.rb1);
            this.Controls.Add(this.btnUcitaj);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.txtVektorPreciznosti);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.txtVektorPomaka);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.txtPocetnaTocka);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.MaximizeBox = false;
            this.Name = "frmHJ";
            this.Text = "Hooke-Jeeves postupak";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtPocetnaTocka;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox txtVektorPomaka;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox txtVektorPreciznosti;
        private System.Windows.Forms.Button btnUcitaj;
        private System.Windows.Forms.RadioButton rb1;
        private System.Windows.Forms.RadioButton rb2;
        private System.Windows.Forms.RadioButton rb3;
        private System.Windows.Forms.RadioButton rb4;
        private System.Windows.Forms.RadioButton rb5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button btnPokreni;
        private System.Windows.Forms.TextBox txtPrikaz;
        private System.Windows.Forms.TextBox txtPx;
        private System.Windows.Forms.Label label5;
    }
}


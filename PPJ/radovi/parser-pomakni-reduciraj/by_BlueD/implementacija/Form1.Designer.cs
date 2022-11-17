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
            this.parsirajGram1Button = new System.Windows.Forms.Button();
            this.parsirajGram2Button = new System.Windows.Forms.Button();
            this.parsirajGram3Button = new System.Windows.Forms.Button();
            this.gram1UlazniNizBox = new System.Windows.Forms.TextBox();
            this.gram2UlazniNiz = new System.Windows.Forms.TextBox();
            this.gram3UlazniNizBox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.richTextBox1 = new System.Windows.Forms.RichTextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.gram1OutputReslutLabel = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.richTextBox2 = new System.Windows.Forms.RichTextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.gram2OutputReslutLabel = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.richTextBox3 = new System.Windows.Forms.RichTextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.gram3OutputReslutLabel = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // parsirajGram1Button
            // 
            this.parsirajGram1Button.Location = new System.Drawing.Point(477, 28);
            this.parsirajGram1Button.Name = "parsirajGram1Button";
            this.parsirajGram1Button.Size = new System.Drawing.Size(81, 37);
            this.parsirajGram1Button.TabIndex = 0;
            this.parsirajGram1Button.Text = "PARSIRAJ GRAM 1";
            this.parsirajGram1Button.UseVisualStyleBackColor = true;
            this.parsirajGram1Button.Click += new System.EventHandler(this.parsirajGram1Button_Click);
            // 
            // parsirajGram2Button
            // 
            this.parsirajGram2Button.Location = new System.Drawing.Point(477, 176);
            this.parsirajGram2Button.Name = "parsirajGram2Button";
            this.parsirajGram2Button.Size = new System.Drawing.Size(81, 37);
            this.parsirajGram2Button.TabIndex = 1;
            this.parsirajGram2Button.Text = "PARSIRAJ GRAM 2";
            this.parsirajGram2Button.UseVisualStyleBackColor = true;
            this.parsirajGram2Button.Click += new System.EventHandler(this.parsirajGram2Button_Click);
            // 
            // parsirajGram3Button
            // 
            this.parsirajGram3Button.Location = new System.Drawing.Point(477, 339);
            this.parsirajGram3Button.Name = "parsirajGram3Button";
            this.parsirajGram3Button.Size = new System.Drawing.Size(81, 37);
            this.parsirajGram3Button.TabIndex = 2;
            this.parsirajGram3Button.Text = "PARSIRAJ GRAM 3";
            this.parsirajGram3Button.UseVisualStyleBackColor = true;
            this.parsirajGram3Button.Click += new System.EventHandler(this.parsirajGram3Button_Click);
            // 
            // gram1UlazniNizBox
            // 
            this.gram1UlazniNizBox.Location = new System.Drawing.Point(241, 28);
            this.gram1UlazniNizBox.Name = "gram1UlazniNizBox";
            this.gram1UlazniNizBox.Size = new System.Drawing.Size(208, 20);
            this.gram1UlazniNizBox.TabIndex = 3;
            // 
            // gram2UlazniNiz
            // 
            this.gram2UlazniNiz.Location = new System.Drawing.Point(241, 176);
            this.gram2UlazniNiz.Name = "gram2UlazniNiz";
            this.gram2UlazniNiz.Size = new System.Drawing.Size(208, 20);
            this.gram2UlazniNiz.TabIndex = 4;
            // 
            // gram3UlazniNizBox
            // 
            this.gram3UlazniNizBox.Location = new System.Drawing.Point(241, 336);
            this.gram3UlazniNizBox.Name = "gram3UlazniNizBox";
            this.gram3UlazniNizBox.Size = new System.Drawing.Size(208, 20);
            this.gram3UlazniNizBox.TabIndex = 5;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Arial", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label1.Location = new System.Drawing.Point(12, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(105, 16);
            this.label1.TabIndex = 6;
            this.label1.Text = "GRAMATIKA 1:";
            // 
            // richTextBox1
            // 
            this.richTextBox1.Location = new System.Drawing.Point(12, 28);
            this.richTextBox1.Name = "richTextBox1";
            this.richTextBox1.ReadOnly = true;
            this.richTextBox1.Size = new System.Drawing.Size(143, 88);
            this.richTextBox1.TabIndex = 7;
            this.richTextBox1.Text = "\n<S>   -->   ( <A> <S> )\n<S>   -->   ( b )\n<A>   -->   ( <S> a <A>)\n<A>   -->   (" +
                " a )";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(180, 31);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(55, 13);
            this.label2.TabIndex = 8;
            this.label2.Text = "Ulazni niz:";
            // 
            // gram1OutputReslutLabel
            // 
            this.gram1OutputReslutLabel.Location = new System.Drawing.Point(235, 63);
            this.gram1OutputReslutLabel.Name = "gram1OutputReslutLabel";
            this.gram1OutputReslutLabel.Size = new System.Drawing.Size(236, 53);
            this.gram1OutputReslutLabel.TabIndex = 9;
            // 
            // label5
            // 
            this.label5.BackColor = System.Drawing.SystemColors.Desktop;
            this.label5.Location = new System.Drawing.Point(-2, 140);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(582, 10);
            this.label5.TabIndex = 13;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Arial", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label3.Location = new System.Drawing.Point(12, 161);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(105, 16);
            this.label3.TabIndex = 14;
            this.label3.Text = "GRAMATIKA 2:";
            // 
            // richTextBox2
            // 
            this.richTextBox2.Location = new System.Drawing.Point(12, 180);
            this.richTextBox2.Name = "richTextBox2";
            this.richTextBox2.ReadOnly = true;
            this.richTextBox2.Size = new System.Drawing.Size(143, 96);
            this.richTextBox2.TabIndex = 15;
            this.richTextBox2.Text = "<S>   -->   ( b <A> <S> <B> )\n<S>   -->   ( b <A> )\n<A>   -->   ( d <S> c a )\n<A>" +
                "   -->   ( e )\n<B>   -->   ( c <A> a )\n<B>   -->   ( c )";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(180, 183);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(55, 13);
            this.label4.TabIndex = 16;
            this.label4.Text = "Ulazni niz:";
            // 
            // gram2OutputReslutLabel
            // 
            this.gram2OutputReslutLabel.Location = new System.Drawing.Point(235, 223);
            this.gram2OutputReslutLabel.Name = "gram2OutputReslutLabel";
            this.gram2OutputReslutLabel.Size = new System.Drawing.Size(236, 53);
            this.gram2OutputReslutLabel.TabIndex = 17;
            // 
            // label7
            // 
            this.label7.BackColor = System.Drawing.SystemColors.Desktop;
            this.label7.Location = new System.Drawing.Point(-2, 294);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(582, 10);
            this.label7.TabIndex = 18;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("Arial", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label8.Location = new System.Drawing.Point(12, 317);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(105, 16);
            this.label8.TabIndex = 19;
            this.label8.Text = "GRAMATIKA 3:";
            // 
            // richTextBox3
            // 
            this.richTextBox3.Location = new System.Drawing.Point(12, 336);
            this.richTextBox3.Name = "richTextBox3";
            this.richTextBox3.ReadOnly = true;
            this.richTextBox3.Size = new System.Drawing.Size(143, 96);
            this.richTextBox3.TabIndex = 20;
            this.richTextBox3.Text = "\nS   -->   (L)\nS   -->   x\nL   -->   S\nL   -->   L,S";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(180, 339);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(55, 13);
            this.label9.TabIndex = 21;
            this.label9.Text = "Ulazni niz:";
            // 
            // gram3OutputReslutLabel
            // 
            this.gram3OutputReslutLabel.Location = new System.Drawing.Point(235, 379);
            this.gram3OutputReslutLabel.Name = "gram3OutputReslutLabel";
            this.gram3OutputReslutLabel.Size = new System.Drawing.Size(236, 53);
            this.gram3OutputReslutLabel.TabIndex = 22;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(578, 462);
            this.Controls.Add(this.gram3OutputReslutLabel);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.richTextBox3);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.gram2OutputReslutLabel);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.richTextBox2);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.gram1OutputReslutLabel);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.richTextBox1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.gram3UlazniNizBox);
            this.Controls.Add(this.gram2UlazniNiz);
            this.Controls.Add(this.gram1UlazniNizBox);
            this.Controls.Add(this.parsirajGram3Button);
            this.Controls.Add(this.parsirajGram2Button);
            this.Controls.Add(this.parsirajGram1Button);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button parsirajGram1Button;
        private System.Windows.Forms.Button parsirajGram2Button;
        private System.Windows.Forms.Button parsirajGram3Button;
        private System.Windows.Forms.TextBox gram1UlazniNizBox;
        private System.Windows.Forms.TextBox gram2UlazniNiz;
        private System.Windows.Forms.TextBox gram3UlazniNizBox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.RichTextBox richTextBox1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label gram1OutputReslutLabel;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.RichTextBox richTextBox2;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label gram2OutputReslutLabel;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.RichTextBox richTextBox3;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label gram3OutputReslutLabel;
    }
}


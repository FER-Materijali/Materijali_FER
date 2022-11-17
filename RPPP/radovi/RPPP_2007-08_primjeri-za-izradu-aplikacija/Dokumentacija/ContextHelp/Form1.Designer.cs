namespace ContextHelp
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
            this.helpProvider1 = new System.Windows.Forms.HelpProvider();
            this.numericUpDown1 = new System.Windows.Forms.NumericUpDown();
            this.numericUpDown2 = new System.Windows.Forms.NumericUpDown();
            this.ZbrojiButton = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.ZbrojLabel = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown2)).BeginInit();
            this.SuspendLayout();
            // 
            // helpProvider1
            // 
            this.helpProvider1.HelpNamespace = "help.chm";
            // 
            // numericUpDown1
            // 
            this.helpProvider1.SetHelpKeyword(this.numericUpDown1, "kontrola.htm");
            this.helpProvider1.SetHelpNavigator(this.numericUpDown1, System.Windows.Forms.HelpNavigator.Topic);
            this.numericUpDown1.Location = new System.Drawing.Point(12, 12);
            this.numericUpDown1.Name = "numericUpDown1";
            this.helpProvider1.SetShowHelp(this.numericUpDown1, true);
            this.numericUpDown1.Size = new System.Drawing.Size(35, 20);
            this.numericUpDown1.TabIndex = 0;
            // 
            // numericUpDown2
            // 
            this.helpProvider1.SetHelpKeyword(this.numericUpDown2, "kontrola.htm");
            this.helpProvider1.SetHelpNavigator(this.numericUpDown2, System.Windows.Forms.HelpNavigator.Topic);
            this.numericUpDown2.Location = new System.Drawing.Point(53, 12);
            this.numericUpDown2.Name = "numericUpDown2";
            this.helpProvider1.SetShowHelp(this.numericUpDown2, true);
            this.numericUpDown2.Size = new System.Drawing.Size(39, 20);
            this.numericUpDown2.TabIndex = 1;
            // 
            // ZbrojiButton
            // 
            this.ZbrojiButton.Location = new System.Drawing.Point(12, 38);
            this.ZbrojiButton.Name = "ZbrojiButton";
            this.ZbrojiButton.Size = new System.Drawing.Size(75, 23);
            this.ZbrojiButton.TabIndex = 2;
            this.ZbrojiButton.Text = "Zbroji";
            this.ZbrojiButton.UseVisualStyleBackColor = true;
            this.ZbrojiButton.Click += new System.EventHandler(this.ZbrojiButton_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(98, 12);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(34, 13);
            this.label1.TabIndex = 3;
            this.label1.Text = "Zbroj:";
            // 
            // ZbrojLabel
            // 
            this.ZbrojLabel.AutoSize = true;
            this.ZbrojLabel.Location = new System.Drawing.Point(138, 12);
            this.ZbrojLabel.Name = "ZbrojLabel";
            this.ZbrojLabel.Size = new System.Drawing.Size(0, 13);
            this.ZbrojLabel.TabIndex = 4;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(265, 79);
            this.Controls.Add(this.ZbrojLabel);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.ZbrojiButton);
            this.Controls.Add(this.numericUpDown2);
            this.Controls.Add(this.numericUpDown1);
            this.helpProvider1.SetHelpKeyword(this, "forma.htm");
            this.helpProvider1.SetHelpNavigator(this, System.Windows.Forms.HelpNavigator.Topic);
            this.Name = "Form1";
            this.helpProvider1.SetShowHelp(this, true);
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown2)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.HelpProvider helpProvider1;
        private System.Windows.Forms.NumericUpDown numericUpDown1;
        private System.Windows.Forms.NumericUpDown numericUpDown2;
        private System.Windows.Forms.Button ZbrojiButton;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label ZbrojLabel;
    }
}


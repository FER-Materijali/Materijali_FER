namespace TextSearch
{
    partial class TextSearch
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
            this.algorithmSelectBox = new System.Windows.Forms.GroupBox();
            this.knuthMorissPrattBtn = new System.Windows.Forms.RadioButton();
            this.rabinKarpBtn = new System.Windows.Forms.RadioButton();
            this.patternInput = new System.Windows.Forms.TextBox();
            this.patternBox = new System.Windows.Forms.GroupBox();
            this.searchBtn = new System.Windows.Forms.Button();
            this.textBox = new System.Windows.Forms.GroupBox();
            this.textInput = new System.Windows.Forms.TextBox();
            this.resultBox = new System.Windows.Forms.GroupBox();
            this.resultOut = new System.Windows.Forms.RichTextBox();
            this.algorithmSelectBox.SuspendLayout();
            this.patternBox.SuspendLayout();
            this.textBox.SuspendLayout();
            this.resultBox.SuspendLayout();
            this.SuspendLayout();
            // 
            // algorithmSelectBox
            // 
            this.algorithmSelectBox.Controls.Add(this.knuthMorissPrattBtn);
            this.algorithmSelectBox.Controls.Add(this.rabinKarpBtn);
            this.algorithmSelectBox.Location = new System.Drawing.Point(12, 12);
            this.algorithmSelectBox.Name = "algorithmSelectBox";
            this.algorithmSelectBox.Size = new System.Drawing.Size(212, 45);
            this.algorithmSelectBox.TabIndex = 1;
            this.algorithmSelectBox.TabStop = false;
            this.algorithmSelectBox.Text = "Algorithm";
            // 
            // knuthMorissPrattBtn
            // 
            this.knuthMorissPrattBtn.AutoSize = true;
            this.knuthMorissPrattBtn.Location = new System.Drawing.Point(91, 20);
            this.knuthMorissPrattBtn.Name = "knuthMorissPrattBtn";
            this.knuthMorissPrattBtn.Size = new System.Drawing.Size(109, 17);
            this.knuthMorissPrattBtn.TabIndex = 1;
            this.knuthMorissPrattBtn.Text = "Knuth-Morris-Pratt";
            this.knuthMorissPrattBtn.UseVisualStyleBackColor = true;
            // 
            // rabinKarpBtn
            // 
            this.rabinKarpBtn.AutoSize = true;
            this.rabinKarpBtn.Checked = true;
            this.rabinKarpBtn.Location = new System.Drawing.Point(7, 20);
            this.rabinKarpBtn.Name = "rabinKarpBtn";
            this.rabinKarpBtn.Size = new System.Drawing.Size(78, 17);
            this.rabinKarpBtn.TabIndex = 0;
            this.rabinKarpBtn.TabStop = true;
            this.rabinKarpBtn.Text = "Rabin-Karp";
            this.rabinKarpBtn.UseVisualStyleBackColor = true;
            // 
            // patternInput
            // 
            this.patternInput.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.patternInput.Location = new System.Drawing.Point(6, 19);
            this.patternInput.Name = "patternInput";
            this.patternInput.Size = new System.Drawing.Size(308, 20);
            this.patternInput.TabIndex = 2;
            // 
            // patternBox
            // 
            this.patternBox.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.patternBox.Controls.Add(this.patternInput);
            this.patternBox.Location = new System.Drawing.Point(230, 12);
            this.patternBox.Name = "patternBox";
            this.patternBox.Size = new System.Drawing.Size(320, 45);
            this.patternBox.TabIndex = 3;
            this.patternBox.TabStop = false;
            this.patternBox.Text = "Search pattern";
            // 
            // searchBtn
            // 
            this.searchBtn.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.searchBtn.Location = new System.Drawing.Point(556, 29);
            this.searchBtn.Name = "searchBtn";
            this.searchBtn.Size = new System.Drawing.Size(75, 23);
            this.searchBtn.TabIndex = 4;
            this.searchBtn.Text = "Search";
            this.searchBtn.UseVisualStyleBackColor = true;
            this.searchBtn.Click += new System.EventHandler(this.searchBtn_Click);
            // 
            // textBox
            // 
            this.textBox.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.textBox.Controls.Add(this.textInput);
            this.textBox.Location = new System.Drawing.Point(12, 63);
            this.textBox.Name = "textBox";
            this.textBox.Size = new System.Drawing.Size(619, 167);
            this.textBox.TabIndex = 2;
            this.textBox.TabStop = false;
            this.textBox.Text = "Text";
            // 
            // textInput
            // 
            this.textInput.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.textInput.Location = new System.Drawing.Point(7, 20);
            this.textInput.Multiline = true;
            this.textInput.Name = "textInput";
            this.textInput.Size = new System.Drawing.Size(606, 137);
            this.textInput.TabIndex = 0;
            // 
            // resultBox
            // 
            this.resultBox.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.resultBox.Controls.Add(this.resultOut);
            this.resultBox.Location = new System.Drawing.Point(12, 236);
            this.resultBox.Name = "resultBox";
            this.resultBox.Size = new System.Drawing.Size(619, 167);
            this.resultBox.TabIndex = 3;
            this.resultBox.TabStop = false;
            this.resultBox.Text = "Results";
            // 
            // resultOut
            // 
            this.resultOut.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.resultOut.Location = new System.Drawing.Point(7, 20);
            this.resultOut.Name = "resultOut";
            this.resultOut.ReadOnly = true;
            this.resultOut.Size = new System.Drawing.Size(606, 137);
            this.resultOut.TabIndex = 0;
            this.resultOut.Text = "";
            // 
            // TextSearch
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(643, 413);
            this.Controls.Add(this.resultBox);
            this.Controls.Add(this.textBox);
            this.Controls.Add(this.searchBtn);
            this.Controls.Add(this.patternBox);
            this.Controls.Add(this.algorithmSelectBox);
            this.Name = "TextSearch";
            this.Text = "Text Search - jk47975";
            this.algorithmSelectBox.ResumeLayout(false);
            this.algorithmSelectBox.PerformLayout();
            this.patternBox.ResumeLayout(false);
            this.patternBox.PerformLayout();
            this.textBox.ResumeLayout(false);
            this.textBox.PerformLayout();
            this.resultBox.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.GroupBox algorithmSelectBox;
        private System.Windows.Forms.RadioButton knuthMorissPrattBtn;
        private System.Windows.Forms.RadioButton rabinKarpBtn;
        private System.Windows.Forms.TextBox patternInput;
        private System.Windows.Forms.GroupBox patternBox;
        private System.Windows.Forms.Button searchBtn;
        private System.Windows.Forms.GroupBox textBox;
        private System.Windows.Forms.TextBox textInput;
        private System.Windows.Forms.GroupBox resultBox;
        private System.Windows.Forms.RichTextBox resultOut;
    }
}


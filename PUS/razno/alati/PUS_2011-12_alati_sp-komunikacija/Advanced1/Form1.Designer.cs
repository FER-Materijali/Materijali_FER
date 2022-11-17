namespace Microsoft.ServiceModel.Samples
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
            this.btnStart = new System.Windows.Forms.Button();
            this.btnStop = new System.Windows.Forms.Button();
            this.btnAdd2 = new System.Windows.Forms.Button();
            this.btnSub2 = new System.Windows.Forms.Button();
            this.btnMul2 = new System.Windows.Forms.Button();
            this.btnDiv2 = new System.Windows.Forms.Button();
            this.btnClose2 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnStart
            // 
            this.btnStart.Location = new System.Drawing.Point(33, 37);
            this.btnStart.Name = "btnStart";
            this.btnStart.Size = new System.Drawing.Size(75, 23);
            this.btnStart.TabIndex = 0;
            this.btnStart.Text = "Start Server";
            this.btnStart.UseVisualStyleBackColor = true;
            this.btnStart.Click += new System.EventHandler(this.btnStart_Click);
            // 
            // btnStop
            // 
            this.btnStop.Location = new System.Drawing.Point(33, 66);
            this.btnStop.Name = "btnStop";
            this.btnStop.Size = new System.Drawing.Size(75, 23);
            this.btnStop.TabIndex = 1;
            this.btnStop.Text = "Stop Server";
            this.btnStop.UseVisualStyleBackColor = true;
            this.btnStop.Click += new System.EventHandler(this.btnStop_Click);
            // 
            // btnAdd2
            // 
            this.btnAdd2.Location = new System.Drawing.Point(179, 37);
            this.btnAdd2.Name = "btnAdd2";
            this.btnAdd2.Size = new System.Drawing.Size(75, 23);
            this.btnAdd2.TabIndex = 2;
            this.btnAdd2.Text = "Add";
            this.btnAdd2.UseVisualStyleBackColor = true;
            this.btnAdd2.Click += new System.EventHandler(this.btnAdd2_Click);
            // 
            // btnSub2
            // 
            this.btnSub2.Location = new System.Drawing.Point(179, 66);
            this.btnSub2.Name = "btnSub2";
            this.btnSub2.Size = new System.Drawing.Size(75, 23);
            this.btnSub2.TabIndex = 3;
            this.btnSub2.Text = "Substract";
            this.btnSub2.UseVisualStyleBackColor = true;
            this.btnSub2.Click += new System.EventHandler(this.btnSub2_Click);
            // 
            // btnMul2
            // 
            this.btnMul2.Location = new System.Drawing.Point(179, 95);
            this.btnMul2.Name = "btnMul2";
            this.btnMul2.Size = new System.Drawing.Size(75, 23);
            this.btnMul2.TabIndex = 4;
            this.btnMul2.Text = "Multiply";
            this.btnMul2.UseVisualStyleBackColor = true;
            this.btnMul2.Click += new System.EventHandler(this.btnMul2_Click);
            // 
            // btnDiv2
            // 
            this.btnDiv2.Location = new System.Drawing.Point(179, 125);
            this.btnDiv2.Name = "btnDiv2";
            this.btnDiv2.Size = new System.Drawing.Size(75, 23);
            this.btnDiv2.TabIndex = 5;
            this.btnDiv2.Text = "Divide";
            this.btnDiv2.UseVisualStyleBackColor = true;
            this.btnDiv2.Click += new System.EventHandler(this.btnDiv2_Click);
            // 
            // btnClose2
            // 
            this.btnClose2.Location = new System.Drawing.Point(179, 155);
            this.btnClose2.Name = "btnClose2";
            this.btnClose2.Size = new System.Drawing.Size(75, 23);
            this.btnClose2.TabIndex = 6;
            this.btnClose2.Text = "Close";
            this.btnClose2.UseVisualStyleBackColor = true;
            this.btnClose2.Click += new System.EventHandler(this.btnClose2_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 262);
            this.Controls.Add(this.btnClose2);
            this.Controls.Add(this.btnDiv2);
            this.Controls.Add(this.btnMul2);
            this.Controls.Add(this.btnSub2);
            this.Controls.Add(this.btnAdd2);
            this.Controls.Add(this.btnStop);
            this.Controls.Add(this.btnStart);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.Button btnStop;
        private System.Windows.Forms.Button btnAdd2;
        private System.Windows.Forms.Button btnSub2;
        private System.Windows.Forms.Button btnMul2;
        private System.Windows.Forms.Button btnDiv2;
        private System.Windows.Forms.Button btnClose2;
    }
}


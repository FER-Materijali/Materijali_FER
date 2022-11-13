namespace AVLtree
{
    partial class Sucelje
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
            this.components = new System.ComponentModel.Container();
            this.openFileBtn = new System.Windows.Forms.Button();
            this.nodeBox = new System.Windows.Forms.TextBox();
            this.addBtn = new System.Windows.Forms.Button();
            this.errorProvider1 = new System.Windows.Forms.ErrorProvider(this.components);
            this.drawPanel = new System.Windows.Forms.Panel();
            this.delBox = new System.Windows.Forms.TextBox();
            this.deleteBtn = new System.Windows.Forms.Button();
            this.clearBtn = new System.Windows.Forms.Button();
            this.findBox = new System.Windows.Forms.TextBox();
            this.findBtn = new System.Windows.Forms.Button();
            this.timeLabel = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.errorProvider1)).BeginInit();
            this.SuspendLayout();
            // 
            // openFileBtn
            // 
            this.openFileBtn.Location = new System.Drawing.Point(2, 3);
            this.openFileBtn.Name = "openFileBtn";
            this.openFileBtn.Size = new System.Drawing.Size(88, 23);
            this.openFileBtn.TabIndex = 0;
            this.openFileBtn.Text = "Otvori datoteku";
            this.openFileBtn.UseVisualStyleBackColor = true;
            this.openFileBtn.Click += new System.EventHandler(this.openFileBtn_Click);
            // 
            // nodeBox
            // 
            this.nodeBox.Location = new System.Drawing.Point(2, 49);
            this.nodeBox.MaxLength = 3;
            this.nodeBox.Name = "nodeBox";
            this.nodeBox.Size = new System.Drawing.Size(26, 20);
            this.nodeBox.TabIndex = 1;
            this.nodeBox.Validating += new System.ComponentModel.CancelEventHandler(this.nodeBox_Validating);
            // 
            // addBtn
            // 
            this.addBtn.Location = new System.Drawing.Point(34, 46);
            this.addBtn.Name = "addBtn";
            this.addBtn.Size = new System.Drawing.Size(56, 23);
            this.addBtn.TabIndex = 2;
            this.addBtn.Text = "Dodaj";
            this.addBtn.UseVisualStyleBackColor = true;
            this.addBtn.Click += new System.EventHandler(this.addBtn_Click);
            this.addBtn.Validating += new System.ComponentModel.CancelEventHandler(this.nodeBox_Validating);
            // 
            // errorProvider1
            // 
            this.errorProvider1.ContainerControl = this;
            // 
            // drawPanel
            // 
            this.drawPanel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.drawPanel.AutoScroll = true;
            this.drawPanel.BackColor = System.Drawing.Color.DimGray;
            this.drawPanel.CausesValidation = false;
            this.drawPanel.Location = new System.Drawing.Point(104, 0);
            this.drawPanel.Name = "drawPanel";
            this.drawPanel.Size = new System.Drawing.Size(1000, 700);
            this.drawPanel.TabIndex = 3;
            this.drawPanel.Paint += new System.Windows.Forms.PaintEventHandler(this.drawPanel_Paint);
            // 
            // delBox
            // 
            this.delBox.Location = new System.Drawing.Point(2, 146);
            this.delBox.Name = "delBox";
            this.delBox.Size = new System.Drawing.Size(26, 20);
            this.delBox.TabIndex = 4;
            this.delBox.Validating += new System.ComponentModel.CancelEventHandler(this.textBox1_Validating);
            // 
            // deleteBtn
            // 
            this.deleteBtn.Location = new System.Drawing.Point(34, 146);
            this.deleteBtn.Name = "deleteBtn";
            this.deleteBtn.Size = new System.Drawing.Size(56, 23);
            this.deleteBtn.TabIndex = 5;
            this.deleteBtn.Text = "Ukloni";
            this.deleteBtn.UseVisualStyleBackColor = true;
            this.deleteBtn.Click += new System.EventHandler(this.deleteBtn_Click);
            this.deleteBtn.Validating += new System.ComponentModel.CancelEventHandler(this.textBox1_Validating);
            // 
            // clearBtn
            // 
            this.clearBtn.Location = new System.Drawing.Point(2, 331);
            this.clearBtn.Name = "clearBtn";
            this.clearBtn.Size = new System.Drawing.Size(75, 23);
            this.clearBtn.TabIndex = 0;
            this.clearBtn.Text = "Clear";
            this.clearBtn.UseVisualStyleBackColor = true;
            this.clearBtn.Click += new System.EventHandler(this.clearBtn_Click);
            // 
            // findBox
            // 
            this.findBox.Location = new System.Drawing.Point(2, 244);
            this.findBox.Name = "findBox";
            this.findBox.Size = new System.Drawing.Size(26, 20);
            this.findBox.TabIndex = 6;
            this.findBox.Validating += new System.ComponentModel.CancelEventHandler(this.findBox_Validating);
            // 
            // findBtn
            // 
            this.findBtn.Location = new System.Drawing.Point(34, 240);
            this.findBtn.Name = "findBtn";
            this.findBtn.Size = new System.Drawing.Size(56, 23);
            this.findBtn.TabIndex = 7;
            this.findBtn.Text = "Pronađi";
            this.findBtn.UseVisualStyleBackColor = true;
            this.findBtn.Click += new System.EventHandler(this.findBtn_Click);
            // 
            // timeLabel
            // 
            this.timeLabel.AutoSize = true;
            this.timeLabel.Location = new System.Drawing.Point(15, 515);
            this.timeLabel.Name = "timeLabel";
            this.timeLabel.Size = new System.Drawing.Size(13, 13);
            this.timeLabel.TabIndex = 8;
            this.timeLabel.Text = "0";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(-1, 493);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(107, 13);
            this.label1.TabIndex = 9;
            this.label1.Text = "Operacija izvedena u";
            // 
            // Sucelje
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1104, 700);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.timeLabel);
            this.Controls.Add(this.findBtn);
            this.Controls.Add(this.findBox);
            this.Controls.Add(this.clearBtn);
            this.Controls.Add(this.deleteBtn);
            this.Controls.Add(this.delBox);
            this.Controls.Add(this.drawPanel);
            this.Controls.Add(this.addBtn);
            this.Controls.Add(this.nodeBox);
            this.Controls.Add(this.openFileBtn);
            this.Name = "Sucelje";
            this.Text = "AVL stablo";
            ((System.ComponentModel.ISupportInitialize)(this.errorProvider1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button openFileBtn;
        private System.Windows.Forms.TextBox nodeBox;
        private System.Windows.Forms.Button addBtn;
        private System.Windows.Forms.ErrorProvider errorProvider1;
        private System.Windows.Forms.Panel drawPanel;
        private System.Windows.Forms.Button deleteBtn;
        private System.Windows.Forms.TextBox delBox;
        private System.Windows.Forms.Button clearBtn;
        private System.Windows.Forms.Button findBtn;
        private System.Windows.Forms.TextBox findBox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label timeLabel;
    }
}


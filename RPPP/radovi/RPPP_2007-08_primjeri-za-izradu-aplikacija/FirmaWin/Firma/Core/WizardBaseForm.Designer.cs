namespace Firma
{
    partial class WizardBaseForm
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
          this.panel1 = new System.Windows.Forms.Panel();
          this.buttonCancel = new System.Windows.Forms.Button();
          this.buttonPrevious = new System.Windows.Forms.Button();
          this.buttonNext = new System.Windows.Forms.Button();
          this.panel1.SuspendLayout();
          this.SuspendLayout();
          // 
          // panel1
          // 
          this.panel1.Controls.Add(this.buttonCancel);
          this.panel1.Controls.Add(this.buttonPrevious);
          this.panel1.Controls.Add(this.buttonNext);
          this.panel1.Dock = System.Windows.Forms.DockStyle.Bottom;
          this.panel1.Location = new System.Drawing.Point(0, 336);
          this.panel1.Name = "panel1";
          this.panel1.Size = new System.Drawing.Size(693, 47);
          this.panel1.TabIndex = 0;
          // 
          // buttonCancel
          // 
          this.buttonCancel.Anchor = System.Windows.Forms.AnchorStyles.None;
          this.buttonCancel.Location = new System.Drawing.Point(335, 12);
          this.buttonCancel.Name = "buttonCancel";
          this.buttonCancel.Size = new System.Drawing.Size(102, 23);
          this.buttonCancel.TabIndex = 2;
          this.buttonCancel.Text = "Odustani";
          this.buttonCancel.UseVisualStyleBackColor = true;
          // 
          // buttonPrevious
          // 
          this.buttonPrevious.Anchor = System.Windows.Forms.AnchorStyles.None;
          this.buttonPrevious.Location = new System.Drawing.Point(471, 12);
          this.buttonPrevious.Name = "buttonPrevious";
          this.buttonPrevious.Size = new System.Drawing.Size(102, 23);
          this.buttonPrevious.TabIndex = 1;
          this.buttonPrevious.Text = "Prethodni korak";
          this.buttonPrevious.UseVisualStyleBackColor = true;
          // 
          // buttonNext
          // 
          this.buttonNext.Anchor = System.Windows.Forms.AnchorStyles.None;
          this.buttonNext.Location = new System.Drawing.Point(579, 12);
          this.buttonNext.Name = "buttonNext";
          this.buttonNext.Size = new System.Drawing.Size(102, 23);
          this.buttonNext.TabIndex = 0;
          this.buttonNext.Text = "Sljedeæi korak";
          this.buttonNext.UseVisualStyleBackColor = true;
          // 
          // WizardBaseForm
          // 
          this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
          this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
          this.ClientSize = new System.Drawing.Size(693, 383);
          this.ControlBox = false;
          this.Controls.Add(this.panel1);
          this.Name = "WizardBaseForm";
          this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
          this.Text = "WizardBaseForm";
          this.Load += new System.EventHandler(this.WizardBaseForm_Load);
          this.Activated += new System.EventHandler(this.WizardBaseForm_Activated);
          this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.WizardBaseForm_FormClosing);
          this.panel1.ResumeLayout(false);
          this.ResumeLayout(false);

        }

        #endregion

        protected System.Windows.Forms.Panel panel1;
        protected System.Windows.Forms.Button buttonCancel;
        protected System.Windows.Forms.Button buttonPrevious;
        protected System.Windows.Forms.Button buttonNext;

    }
}
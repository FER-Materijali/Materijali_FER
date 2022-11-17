namespace Firma
{
    partial class BaseForm
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
          this.helpProvider = new System.Windows.Forms.HelpProvider();
          this.SuspendLayout();
          // 
          // helpProvider
          // 
          this.helpProvider.HelpNamespace = "Doc\\Firma.chm";
          // 
          // BaseForm
          // 
          this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
          this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
          this.ClientSize = new System.Drawing.Size(284, 264);
          this.HelpButton = true;
          this.KeyPreview = true;
          this.Name = "BaseForm";
          this.Text = "BaseForm";
          this.Deactivate += new System.EventHandler(this.BaseForm_Deactivate);
          this.Activated += new System.EventHandler(this.BaseForm_Activated);
          this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.BaseForm_FormClosed);
          this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.BaseForm_KeyDown);
          this.TextChanged += new System.EventHandler(this.BaseForm_TextChanged);
          this.ResumeLayout(false);

        }

        #endregion

      protected System.Windows.Forms.HelpProvider helpProvider;


      }
}
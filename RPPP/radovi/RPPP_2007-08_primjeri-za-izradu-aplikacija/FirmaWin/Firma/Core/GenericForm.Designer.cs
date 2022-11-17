namespace Firma
{
    partial class GenericForm
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
            this.bindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.errorProvider = new System.Windows.Forms.ErrorProvider(this.components);
            this.formToolbar1 = new Firma.FormToolbar(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.bindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.errorProvider)).BeginInit();
            this.SuspendLayout();
            // 
            // bindingSource
            // 
            this.bindingSource.CurrentChanged += new System.EventHandler(this.bindingSource_CurrentChanged);
            // 
            // errorProvider
            // 
            this.errorProvider.ContainerControl = this;
            this.errorProvider.DataSource = this.bindingSource;
            // 
            // formToolbar1
            // 
            this.formToolbar1.Enabled = false;
            this.formToolbar1.Form = this; // da toolbar sazna na kojoj je formi
            this.formToolbar1.GripStyle = System.Windows.Forms.ToolStripGripStyle.Hidden;
            this.formToolbar1.Location = new System.Drawing.Point(0, 0);
            this.formToolbar1.Name = "formToolbar1";
            this.formToolbar1.Size = new System.Drawing.Size(425, 25);
            this.formToolbar1.TabIndex = 1;
            // 
            // GenericForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoScroll = true;
            this.ClientSize = new System.Drawing.Size(425, 357);
            this.Controls.Add(this.formToolbar1);
            this.MainBindingsource = this.bindingSource;
            this.Name = "GenericForm";
            this.Text = "GenericForm";
            this.PropertyChanged += new System.ComponentModel.PropertyChangedEventHandler(this.GenericForm_PropertyChanged);
            ((System.ComponentModel.ISupportInitialize)(this.bindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.errorProvider)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.BindingSource bindingSource;
        private System.Windows.Forms.ErrorProvider errorProvider;
        private FormToolbar formToolbar1;
    }
}
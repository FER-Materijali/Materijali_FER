namespace Firma
{
    partial class ArtiklForm
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
          System.Windows.Forms.Label sifArtiklaLabel;
          System.Windows.Forms.Label nazArtiklaLabel;
          System.Windows.Forms.Label jedMjereLabel;
          System.Windows.Forms.Label cijArtiklaLabel;
          System.Windows.Forms.Label zastUslugaLabel;
          this.artiklBindingSource = new System.Windows.Forms.BindingSource(this.components);
          this.artiklPanel = new System.Windows.Forms.Panel();
          this.slikaArtiklaPictureBox = new System.Windows.Forms.PictureBox();
          this.contextMenuStrip = new System.Windows.Forms.ContextMenuStrip(this.components);
          this.uèitajSlikuToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
          this.obrišiSlikuToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
          this.zastUslugaCheckBox = new System.Windows.Forms.CheckBox();
          this.cijArtiklaTextBox = new System.Windows.Forms.TextBox();
          this.jedMjereTextBox = new System.Windows.Forms.TextBox();
          this.nazArtiklaTextBox = new System.Windows.Forms.TextBox();
          this.sifArtiklaTextBox = new System.Windows.Forms.TextBox();
          this.artiklErrorProvider = new System.Windows.Forms.ErrorProvider(this.components);
          this.openFileDialog = new System.Windows.Forms.OpenFileDialog();
          this.formToolbar1 = new Firma.FormToolbar(this.components);
          this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
          this.btnSetSlikaArtikla = new System.Windows.Forms.ToolStripButton();
          this.btnClearSlikaArtikla = new System.Windows.Forms.ToolStripButton();
          sifArtiklaLabel = new System.Windows.Forms.Label();
          nazArtiklaLabel = new System.Windows.Forms.Label();
          jedMjereLabel = new System.Windows.Forms.Label();
          cijArtiklaLabel = new System.Windows.Forms.Label();
          zastUslugaLabel = new System.Windows.Forms.Label();
          ((System.ComponentModel.ISupportInitialize)(this.artiklBindingSource)).BeginInit();
          this.artiklPanel.SuspendLayout();
          ((System.ComponentModel.ISupportInitialize)(this.slikaArtiklaPictureBox)).BeginInit();
          this.contextMenuStrip.SuspendLayout();
          ((System.ComponentModel.ISupportInitialize)(this.artiklErrorProvider)).BeginInit();
          this.formToolbar1.SuspendLayout();
          this.SuspendLayout();
          // 
          // sifArtiklaLabel
          // 
          sifArtiklaLabel.AutoSize = true;
          sifArtiklaLabel.Location = new System.Drawing.Point(12, 22);
          sifArtiklaLabel.Name = "sifArtiklaLabel";
          sifArtiklaLabel.Size = new System.Drawing.Size(28, 13);
          sifArtiklaLabel.TabIndex = 0;
          sifArtiklaLabel.Text = "Šifra";
          // 
          // nazArtiklaLabel
          // 
          nazArtiklaLabel.AutoSize = true;
          nazArtiklaLabel.Location = new System.Drawing.Point(12, 48);
          nazArtiklaLabel.Name = "nazArtiklaLabel";
          nazArtiklaLabel.Size = new System.Drawing.Size(34, 13);
          nazArtiklaLabel.TabIndex = 2;
          nazArtiklaLabel.Text = "Naziv";
          // 
          // jedMjereLabel
          // 
          jedMjereLabel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
          jedMjereLabel.AutoSize = true;
          jedMjereLabel.Location = new System.Drawing.Point(12, 105);
          jedMjereLabel.Name = "jedMjereLabel";
          jedMjereLabel.Size = new System.Drawing.Size(55, 13);
          jedMjereLabel.TabIndex = 4;
          jedMjereLabel.Text = "Jed. mjere";
          // 
          // cijArtiklaLabel
          // 
          cijArtiklaLabel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
          cijArtiklaLabel.AutoSize = true;
          cijArtiklaLabel.Location = new System.Drawing.Point(12, 131);
          cijArtiklaLabel.Name = "cijArtiklaLabel";
          cijArtiklaLabel.Size = new System.Drawing.Size(36, 13);
          cijArtiklaLabel.TabIndex = 6;
          cijArtiklaLabel.Text = "Cijena";
          // 
          // zastUslugaLabel
          // 
          zastUslugaLabel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
          zastUslugaLabel.AutoSize = true;
          zastUslugaLabel.Location = new System.Drawing.Point(12, 159);
          zastUslugaLabel.Name = "zastUslugaLabel";
          zastUslugaLabel.Size = new System.Drawing.Size(40, 13);
          zastUslugaLabel.TabIndex = 8;
          zastUslugaLabel.Text = "Usluga";
          // 
          // artiklBindingSource
          // 
          this.artiklBindingSource.DataSource = typeof(Firma.Artikl);
          this.artiklBindingSource.CurrentChanged += new System.EventHandler(this.artiklBindingSource_CurrentChanged);
          this.artiklBindingSource.CurrentItemChanged += new System.EventHandler(this.artiklBindingSource_CurrentItemChanged);
          // 
          // artiklPanel
          // 
          this.artiklPanel.Controls.Add(this.slikaArtiklaPictureBox);
          this.artiklPanel.Controls.Add(zastUslugaLabel);
          this.artiklPanel.Controls.Add(this.zastUslugaCheckBox);
          this.artiklPanel.Controls.Add(cijArtiklaLabel);
          this.artiklPanel.Controls.Add(this.cijArtiklaTextBox);
          this.artiklPanel.Controls.Add(jedMjereLabel);
          this.artiklPanel.Controls.Add(this.jedMjereTextBox);
          this.artiklPanel.Controls.Add(nazArtiklaLabel);
          this.artiklPanel.Controls.Add(this.nazArtiklaTextBox);
          this.artiklPanel.Controls.Add(sifArtiklaLabel);
          this.artiklPanel.Controls.Add(this.sifArtiklaTextBox);
          this.artiklPanel.Dock = System.Windows.Forms.DockStyle.Fill;
          this.artiklPanel.Enabled = false;
          this.artiklPanel.Location = new System.Drawing.Point(0, 25);
          this.artiklPanel.Name = "artiklPanel";
          this.artiklPanel.Size = new System.Drawing.Size(505, 192);
          this.artiklPanel.TabIndex = 1;
          // 
          // slikaArtiklaPictureBox
          // 
          this.slikaArtiklaPictureBox.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                      | System.Windows.Forms.AnchorStyles.Left)
                      | System.Windows.Forms.AnchorStyles.Right)));
          this.slikaArtiklaPictureBox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
          this.slikaArtiklaPictureBox.ContextMenuStrip = this.contextMenuStrip;
          this.slikaArtiklaPictureBox.DataBindings.Add(new System.Windows.Forms.Binding("Image", this.artiklBindingSource, "SlikaArtikla", true));
          this.slikaArtiklaPictureBox.Location = new System.Drawing.Point(275, 19);
          this.slikaArtiklaPictureBox.Name = "slikaArtiklaPictureBox";
          this.slikaArtiklaPictureBox.Size = new System.Drawing.Size(218, 159);
          this.slikaArtiklaPictureBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
          this.slikaArtiklaPictureBox.TabIndex = 11;
          this.slikaArtiklaPictureBox.TabStop = false;
          // 
          // contextMenuStrip
          // 
          this.contextMenuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.uèitajSlikuToolStripMenuItem,
            this.obrišiSlikuToolStripMenuItem});
          this.contextMenuStrip.Name = "contextMenuStrip";
          this.contextMenuStrip.Size = new System.Drawing.Size(133, 48);
          // 
          // uèitajSlikuToolStripMenuItem
          // 
          this.uèitajSlikuToolStripMenuItem.Name = "uèitajSlikuToolStripMenuItem";
          this.uèitajSlikuToolStripMenuItem.Size = new System.Drawing.Size(132, 22);
          this.uèitajSlikuToolStripMenuItem.Text = "Uèitaj sliku";
          this.uèitajSlikuToolStripMenuItem.Click += new System.EventHandler(this.btnSetSlikaArtikla_Click);
          // 
          // obrišiSlikuToolStripMenuItem
          // 
          this.obrišiSlikuToolStripMenuItem.Name = "obrišiSlikuToolStripMenuItem";
          this.obrišiSlikuToolStripMenuItem.Size = new System.Drawing.Size(132, 22);
          this.obrišiSlikuToolStripMenuItem.Text = "Obriši sliku";
          this.obrišiSlikuToolStripMenuItem.Click += new System.EventHandler(this.btnClearSlikaArtikla_Click);
          // 
          // zastUslugaCheckBox
          // 
          this.zastUslugaCheckBox.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
          this.zastUslugaCheckBox.DataBindings.Add(new System.Windows.Forms.Binding("CheckState", this.artiklBindingSource, "ZastUsluga", true));
          this.zastUslugaCheckBox.Location = new System.Drawing.Point(73, 154);
          this.zastUslugaCheckBox.Name = "zastUslugaCheckBox";
          this.zastUslugaCheckBox.Size = new System.Drawing.Size(104, 24);
          this.zastUslugaCheckBox.TabIndex = 9;
          // 
          // cijArtiklaTextBox
          // 
          this.cijArtiklaTextBox.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
          this.cijArtiklaTextBox.Location = new System.Drawing.Point(73, 128);
          this.cijArtiklaTextBox.Name = "cijArtiklaTextBox";
          this.cijArtiklaTextBox.Size = new System.Drawing.Size(100, 20);
          this.cijArtiklaTextBox.TabIndex = 7;
          this.cijArtiklaTextBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
          this.cijArtiklaTextBox.Leave += new System.EventHandler(this.ArtiklControlLeave);
          this.cijArtiklaTextBox.Enter += new System.EventHandler(this.ArtiklControlEnter);
          // 
          // jedMjereTextBox
          // 
          this.jedMjereTextBox.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
          this.jedMjereTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.artiklBindingSource, "JedMjere", true));
          this.jedMjereTextBox.Location = new System.Drawing.Point(73, 102);
          this.jedMjereTextBox.Name = "jedMjereTextBox";
          this.jedMjereTextBox.Size = new System.Drawing.Size(100, 20);
          this.jedMjereTextBox.TabIndex = 5;
          this.jedMjereTextBox.Leave += new System.EventHandler(this.ArtiklControlLeave);
          this.jedMjereTextBox.Enter += new System.EventHandler(this.ArtiklControlEnter);
          // 
          // nazArtiklaTextBox
          // 
          this.nazArtiklaTextBox.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                      | System.Windows.Forms.AnchorStyles.Left)));
          this.nazArtiklaTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.artiklBindingSource, "NazArtikla", true));
          this.helpProvider.SetHelpKeyword(this.nazArtiklaTextBox, "");
          this.helpProvider.SetHelpNavigator(this.nazArtiklaTextBox, System.Windows.Forms.HelpNavigator.Topic);
          this.nazArtiklaTextBox.Location = new System.Drawing.Point(73, 45);
          this.nazArtiklaTextBox.Multiline = true;
          this.nazArtiklaTextBox.Name = "nazArtiklaTextBox";
          this.helpProvider.SetShowHelp(this.nazArtiklaTextBox, true);
          this.nazArtiklaTextBox.Size = new System.Drawing.Size(196, 51);
          this.nazArtiklaTextBox.TabIndex = 3;
          this.nazArtiklaTextBox.Leave += new System.EventHandler(this.ArtiklControlLeave);
          this.nazArtiklaTextBox.Enter += new System.EventHandler(this.ArtiklControlEnter);
          // 
          // sifArtiklaTextBox
          // 
          this.sifArtiklaTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.artiklBindingSource, "SifArtikla", true));
          this.helpProvider.SetHelpKeyword(this.sifArtiklaTextBox, "Firma.htm#Maticni_podaci-Artikl-Sifra");
          this.helpProvider.SetHelpNavigator(this.sifArtiklaTextBox, System.Windows.Forms.HelpNavigator.Topic);
          this.sifArtiklaTextBox.Location = new System.Drawing.Point(73, 19);
          this.sifArtiklaTextBox.Name = "sifArtiklaTextBox";
          this.helpProvider.SetShowHelp(this.sifArtiklaTextBox, true);
          this.sifArtiklaTextBox.Size = new System.Drawing.Size(100, 20);
          this.sifArtiklaTextBox.TabIndex = 1;
          this.sifArtiklaTextBox.Leave += new System.EventHandler(this.ArtiklControlLeave);
          this.sifArtiklaTextBox.Enter += new System.EventHandler(this.ArtiklControlEnter);
          // 
          // artiklErrorProvider
          // 
          this.artiklErrorProvider.ContainerControl = this;
          this.artiklErrorProvider.DataSource = this.artiklBindingSource;
          // 
          // openFileDialog
          // 
          this.openFileDialog.Filter = "Slike (*.BMP;*.JPG;*.GIF)|*.BMP;*.JPG;*.GIF|Sve datoteke (*.*)|*.*\"";
          this.openFileDialog.InitialDirectory = ".";
          this.openFileDialog.Title = "Uèitaj sliku artikla";
          // 
          // formToolbar1
          // 
          this.formToolbar1.Enabled = false;
          this.formToolbar1.Form = this;
          this.formToolbar1.GripStyle = System.Windows.Forms.ToolStripGripStyle.Hidden;
          this.formToolbar1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripSeparator2,
            this.btnSetSlikaArtikla,
            this.btnClearSlikaArtikla});
          this.formToolbar1.Location = new System.Drawing.Point(0, 0);
          this.formToolbar1.Name = "formToolbar1";
          this.formToolbar1.Size = new System.Drawing.Size(505, 25);
          this.formToolbar1.TabIndex = 2;
          this.formToolbar1.Text = "formToolbar1";
          // 
          // toolStripSeparator2
          // 
          this.toolStripSeparator2.Name = "toolStripSeparator2";
          this.toolStripSeparator2.Size = new System.Drawing.Size(6, 25);
          // 
          // btnSetSlikaArtikla
          // 
          this.btnSetSlikaArtikla.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
          this.btnSetSlikaArtikla.ImageTransparentColor = System.Drawing.Color.Magenta;
          this.btnSetSlikaArtikla.Name = "btnSetSlikaArtikla";
          this.btnSetSlikaArtikla.Size = new System.Drawing.Size(68, 22);
          this.btnSetSlikaArtikla.Text = "Uèitaj sliku";
          this.btnSetSlikaArtikla.Click += new System.EventHandler(this.btnSetSlikaArtikla_Click);
          // 
          // btnClearSlikaArtikla
          // 
          this.btnClearSlikaArtikla.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
          this.btnClearSlikaArtikla.ImageTransparentColor = System.Drawing.Color.Magenta;
          this.btnClearSlikaArtikla.Name = "btnClearSlikaArtikla";
          this.btnClearSlikaArtikla.Size = new System.Drawing.Size(69, 22);
          this.btnClearSlikaArtikla.Text = "Obriši sliku";
          this.btnClearSlikaArtikla.Click += new System.EventHandler(this.btnClearSlikaArtikla_Click);
          // 
          // ArtiklForm
          // 
          this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
          this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
          this.ClientSize = new System.Drawing.Size(505, 217);
          this.Controls.Add(this.artiklPanel);
          this.Controls.Add(this.formToolbar1);
          this.FocusOnEdit = this.nazArtiklaTextBox;
          this.FocusOnNew = this.sifArtiklaTextBox;
          this.helpProvider.SetHelpKeyword(this, "Firma.htm#Maticni podaci-Artikl");
          this.helpProvider.SetHelpNavigator(this, System.Windows.Forms.HelpNavigator.Topic);
          this.KeyPreview = false;
          this.MainBindingsource = this.artiklBindingSource;
          this.Name = "ArtiklForm";
          this.helpProvider.SetShowHelp(this, true);
          this.Text = "Artikl";
          this.PropertyChanged += new System.ComponentModel.PropertyChangedEventHandler(this.ArtiklForm_PropertyChanged);
          ((System.ComponentModel.ISupportInitialize)(this.artiklBindingSource)).EndInit();
          this.artiklPanel.ResumeLayout(false);
          this.artiklPanel.PerformLayout();
          ((System.ComponentModel.ISupportInitialize)(this.slikaArtiklaPictureBox)).EndInit();
          this.contextMenuStrip.ResumeLayout(false);
          ((System.ComponentModel.ISupportInitialize)(this.artiklErrorProvider)).EndInit();
          this.formToolbar1.ResumeLayout(false);
          this.formToolbar1.PerformLayout();
          this.ResumeLayout(false);
          this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.BindingSource artiklBindingSource;
        private System.Windows.Forms.Panel artiklPanel;
        private System.Windows.Forms.PictureBox slikaArtiklaPictureBox;
        private System.Windows.Forms.CheckBox zastUslugaCheckBox;
        private System.Windows.Forms.TextBox cijArtiklaTextBox;
        private System.Windows.Forms.TextBox jedMjereTextBox;
        private System.Windows.Forms.TextBox nazArtiklaTextBox;
        private System.Windows.Forms.TextBox sifArtiklaTextBox;
        private System.Windows.Forms.ErrorProvider artiklErrorProvider;
        private System.Windows.Forms.OpenFileDialog openFileDialog;
        private FormToolbar formToolbar1;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ToolStripButton btnSetSlikaArtikla;
        private System.Windows.Forms.ToolStripButton btnClearSlikaArtikla;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip;
        private System.Windows.Forms.ToolStripMenuItem uèitajSlikuToolStripMenuItem;
      private System.Windows.Forms.ToolStripMenuItem obrišiSlikuToolStripMenuItem;
    }
}
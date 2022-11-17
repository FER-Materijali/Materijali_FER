namespace Firma
{
    partial class MainForm
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
          this.statusBar = new System.Windows.Forms.StatusStrip();
          this.sblModuleName = new System.Windows.Forms.ToolStripStatusLabel();
          this.sblFunction = new System.Windows.Forms.ToolStripStatusLabel();
          this.sblStatus = new System.Windows.Forms.ToolStripStatusLabel();
          this.sblUser = new System.Windows.Forms.ToolStripStatusLabel();
          this.menuStrip1 = new System.Windows.Forms.MenuStrip();
          this.testToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
          this.dokumentWizardToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
          this.separatorToolStripMenuItem = new System.Windows.Forms.ToolStripSeparator();
          this.izlazToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
          this.maticniPodaciToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
          this.partnerToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
          this.artiklToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
          this.dokumentToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
          this.tabliceToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
          this.artiklToolStripTablice = new System.Windows.Forms.ToolStripMenuItem();
          this.drzavaToolStripTablice = new System.Windows.Forms.ToolStripMenuItem();
          this.mjestoToolStripTablice = new System.Windows.Forms.ToolStripMenuItem();
          this.prozoriToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
          this.kaskadnoPoravnanjeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
          this.horizontalnoPoravnanjeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
          this.vertikalnoPoravnanjeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
          this.HelpStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
          this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
          this.helpProvider1 = new System.Windows.Forms.HelpProvider();
          this.statusBar.SuspendLayout();
          this.menuStrip1.SuspendLayout();
          this.SuspendLayout();
          // 
          // statusBar
          // 
          this.statusBar.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.sblModuleName,
            this.sblFunction,
            this.sblStatus,
            this.sblUser});
          this.statusBar.Location = new System.Drawing.Point(0, 596);
          this.statusBar.Name = "statusBar";
          this.statusBar.Size = new System.Drawing.Size(814, 22);
          this.statusBar.TabIndex = 0;
          // 
          // sblModuleName
          // 
          this.sblModuleName.AutoSize = false;
          this.sblModuleName.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold);
          this.sblModuleName.Name = "sblModuleName";
          this.sblModuleName.Size = new System.Drawing.Size(195, 17);
          this.sblModuleName.Spring = true;
          this.sblModuleName.Text = "[sblModuleName]";
          this.sblModuleName.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
          // 
          // sblFunction
          // 
          this.sblFunction.AutoSize = false;
          this.sblFunction.Name = "sblFunction";
          this.sblFunction.Size = new System.Drawing.Size(209, 17);
          this.sblFunction.Text = "[sblFunction]";
          this.sblFunction.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
          // 
          // sblStatus
          // 
          this.sblStatus.Name = "sblStatus";
          this.sblStatus.Padding = new System.Windows.Forms.Padding(5, 0, 5, 0);
          this.sblStatus.Size = new System.Drawing.Size(195, 17);
          this.sblStatus.Spring = true;
          this.sblStatus.Text = "[sblStatus]";
          this.sblStatus.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
          // 
          // sblUser
          // 
          this.sblUser.AutoSize = false;
          this.sblUser.Image = global::Firma.Properties.Resources.user_256;
          this.sblUser.Name = "sblUser";
          this.sblUser.Size = new System.Drawing.Size(200, 17);
          this.sblUser.Text = "[sblUser]";
          this.sblUser.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
          // 
          // menuStrip1
          // 
          this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.testToolStripMenuItem,
            this.maticniPodaciToolStripMenuItem,
            this.tabliceToolStripMenuItem,
            this.prozoriToolStripMenuItem,
            this.HelpStripMenuItem});
          this.menuStrip1.Location = new System.Drawing.Point(0, 0);
          this.menuStrip1.MdiWindowListItem = this.prozoriToolStripMenuItem;
          this.menuStrip1.Name = "menuStrip1";
          this.menuStrip1.Size = new System.Drawing.Size(814, 24);
          this.menuStrip1.TabIndex = 3;
          this.menuStrip1.Text = "menuStrip1";
          // 
          // testToolStripMenuItem
          // 
          this.testToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.dokumentWizardToolStripMenuItem,
            this.separatorToolStripMenuItem,
            this.izlazToolStripMenuItem});
          this.testToolStripMenuItem.Name = "testToolStripMenuItem";
          this.testToolStripMenuItem.Size = new System.Drawing.Size(49, 20);
          this.testToolStripMenuItem.Text = "&Firma";
          // 
          // dokumentWizardToolStripMenuItem
          // 
          this.dokumentWizardToolStripMenuItem.Name = "dokumentWizardToolStripMenuItem";
          this.dokumentWizardToolStripMenuItem.Size = new System.Drawing.Size(198, 22);
          this.dokumentWizardToolStripMenuItem.Text = "Zaprimanje dokumenta";
          this.dokumentWizardToolStripMenuItem.Click += new System.EventHandler(this.dokumentWizardToolStripMenuItem_Click);
          // 
          // separatorToolStripMenuItem
          // 
          this.separatorToolStripMenuItem.Name = "separatorToolStripMenuItem";
          this.separatorToolStripMenuItem.Size = new System.Drawing.Size(195, 6);
          // 
          // izlazToolStripMenuItem
          // 
          this.izlazToolStripMenuItem.Image = global::Firma.Properties.Resources.door_in;
          this.izlazToolStripMenuItem.Name = "izlazToolStripMenuItem";
          this.izlazToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Alt | System.Windows.Forms.Keys.X)));
          this.izlazToolStripMenuItem.Size = new System.Drawing.Size(198, 22);
          this.izlazToolStripMenuItem.Text = "Izlaz";
          this.izlazToolStripMenuItem.Click += new System.EventHandler(this.izlazToolStripMenuItem_Click);
          // 
          // maticniPodaciToolStripMenuItem
          // 
          this.maticniPodaciToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.partnerToolStripMenuItem,
            this.artiklToolStripMenuItem,
            this.dokumentToolStripMenuItem});
          this.maticniPodaciToolStripMenuItem.Name = "maticniPodaciToolStripMenuItem";
          this.maticniPodaciToolStripMenuItem.Size = new System.Drawing.Size(98, 20);
          this.maticniPodaciToolStripMenuItem.Text = "&Matièni podaci";
          // 
          // partnerToolStripMenuItem
          // 
          this.partnerToolStripMenuItem.Name = "partnerToolStripMenuItem";
          this.partnerToolStripMenuItem.Size = new System.Drawing.Size(130, 22);
          this.partnerToolStripMenuItem.Text = "Partner";
          this.partnerToolStripMenuItem.Click += new System.EventHandler(this.partnerToolStripMenuItem_Click);
          // 
          // artiklToolStripMenuItem
          // 
          this.artiklToolStripMenuItem.Name = "artiklToolStripMenuItem";
          this.artiklToolStripMenuItem.Size = new System.Drawing.Size(130, 22);
          this.artiklToolStripMenuItem.Text = "Artikl";
          this.artiklToolStripMenuItem.Click += new System.EventHandler(this.artiklToolStripMenuItem_Click);
          // 
          // dokumentToolStripMenuItem
          // 
          this.dokumentToolStripMenuItem.Name = "dokumentToolStripMenuItem";
          this.dokumentToolStripMenuItem.Size = new System.Drawing.Size(130, 22);
          this.dokumentToolStripMenuItem.Text = "Dokument";
          this.dokumentToolStripMenuItem.Click += new System.EventHandler(this.dokumentToolStripMenuItem_Click);
          // 
          // tabliceToolStripMenuItem
          // 
          this.tabliceToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.artiklToolStripTablice,
            this.drzavaToolStripTablice,
            this.mjestoToolStripTablice});
          this.tabliceToolStripMenuItem.Name = "tabliceToolStripMenuItem";
          this.tabliceToolStripMenuItem.Size = new System.Drawing.Size(113, 20);
          this.tabliceToolStripMenuItem.Text = "&Tablice (šifrarnici)";
          // 
          // artiklToolStripTablice
          // 
          this.artiklToolStripTablice.Name = "artiklToolStripTablice";
          this.artiklToolStripTablice.Size = new System.Drawing.Size(110, 22);
          this.artiklToolStripTablice.Text = "Artikl ";
          this.artiklToolStripTablice.Click += new System.EventHandler(this.artiklToolStripTablice_Click);
          // 
          // drzavaToolStripTablice
          // 
          this.drzavaToolStripTablice.Name = "drzavaToolStripTablice";
          this.drzavaToolStripTablice.Size = new System.Drawing.Size(110, 22);
          this.drzavaToolStripTablice.Text = "Država";
          this.drzavaToolStripTablice.Click += new System.EventHandler(this.drzavaToolStripTablice_Click);
          // 
          // mjestoToolStripTablice
          // 
          this.mjestoToolStripTablice.Name = "mjestoToolStripTablice";
          this.mjestoToolStripTablice.Size = new System.Drawing.Size(110, 22);
          this.mjestoToolStripTablice.Text = "Mjesto";
          this.mjestoToolStripTablice.Click += new System.EventHandler(this.mjestoToolStripTablice_Click);
          // 
          // prozoriToolStripMenuItem
          // 
          this.prozoriToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.kaskadnoPoravnanjeToolStripMenuItem,
            this.horizontalnoPoravnanjeToolStripMenuItem,
            this.vertikalnoPoravnanjeToolStripMenuItem});
          this.prozoriToolStripMenuItem.Name = "prozoriToolStripMenuItem";
          this.prozoriToolStripMenuItem.Size = new System.Drawing.Size(56, 20);
          this.prozoriToolStripMenuItem.Text = "&Prozori";
          // 
          // kaskadnoPoravnanjeToolStripMenuItem
          // 
          this.kaskadnoPoravnanjeToolStripMenuItem.Image = global::Firma.Properties.Resources.application_cascade;
          this.kaskadnoPoravnanjeToolStripMenuItem.Name = "kaskadnoPoravnanjeToolStripMenuItem";
          this.kaskadnoPoravnanjeToolStripMenuItem.Size = new System.Drawing.Size(205, 22);
          this.kaskadnoPoravnanjeToolStripMenuItem.Text = "Kaskadni raspored";
          this.kaskadnoPoravnanjeToolStripMenuItem.Click += new System.EventHandler(this.kaskadnoPoravnanjeToolStripMenuItem_Click);
          // 
          // horizontalnoPoravnanjeToolStripMenuItem
          // 
          this.horizontalnoPoravnanjeToolStripMenuItem.Image = global::Firma.Properties.Resources.application_tile_horizontal;
          this.horizontalnoPoravnanjeToolStripMenuItem.Name = "horizontalnoPoravnanjeToolStripMenuItem";
          this.horizontalnoPoravnanjeToolStripMenuItem.Size = new System.Drawing.Size(205, 22);
          this.horizontalnoPoravnanjeToolStripMenuItem.Text = "Horizontalno poravnanje";
          this.horizontalnoPoravnanjeToolStripMenuItem.Click += new System.EventHandler(this.horizontalnoPoravnanjeToolStripMenuItem_Click);
          // 
          // vertikalnoPoravnanjeToolStripMenuItem
          // 
          this.vertikalnoPoravnanjeToolStripMenuItem.Image = global::Firma.Properties.Resources.application_tile_vertical;
          this.vertikalnoPoravnanjeToolStripMenuItem.Name = "vertikalnoPoravnanjeToolStripMenuItem";
          this.vertikalnoPoravnanjeToolStripMenuItem.Size = new System.Drawing.Size(205, 22);
          this.vertikalnoPoravnanjeToolStripMenuItem.Text = "Vertikalno poravnanje";
          this.vertikalnoPoravnanjeToolStripMenuItem.Click += new System.EventHandler(this.vertikalnoPoravnanjeToolStripMenuItem_Click);
          // 
          // HelpStripMenuItem
          // 
          this.HelpStripMenuItem.Name = "HelpStripMenuItem";
          this.HelpStripMenuItem.Size = new System.Drawing.Size(57, 20);
          this.HelpStripMenuItem.Text = "Pomoæ";
          this.HelpStripMenuItem.Click += new System.EventHandler(this.HelpStripMenuItem_Click);
          // 
          // contextMenuStrip1
          // 
          this.contextMenuStrip1.Name = "contextMenuStrip1";
          this.contextMenuStrip1.Size = new System.Drawing.Size(61, 4);
          // 
          // helpProvider1
          // 
          this.helpProvider1.HelpNamespace = "Doc\\Firma.chm";
          // 
          // MainForm
          // 
          this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
          this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
          this.ClientSize = new System.Drawing.Size(814, 618);
          this.Controls.Add(this.statusBar);
          this.Controls.Add(this.menuStrip1);
          this.IsMdiContainer = true;
          this.KeyPreview = true;
          this.MainMenuStrip = this.menuStrip1;
          this.Name = "MainForm";
          this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
          this.Text = "Firma App";
          this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
          this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.MainForm_KeyDown);
          this.statusBar.ResumeLayout(false);
          this.statusBar.PerformLayout();
          this.menuStrip1.ResumeLayout(false);
          this.menuStrip1.PerformLayout();
          this.ResumeLayout(false);
          this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.StatusStrip statusBar;
        private System.Windows.Forms.ToolStripStatusLabel sblModuleName;
        private System.Windows.Forms.ToolStripStatusLabel sblFunction;
        private System.Windows.Forms.ToolStripStatusLabel sblStatus;
        private System.Windows.Forms.ToolStripStatusLabel sblUser;
        private System.Windows.Forms.MenuStrip menuStrip1;
      private System.Windows.Forms.ToolStripMenuItem testToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator separatorToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem izlazToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem prozoriToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem kaskadnoPoravnanjeToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem horizontalnoPoravnanjeToolStripMenuItem;
      private System.Windows.Forms.ToolStripMenuItem vertikalnoPoravnanjeToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem dokumentWizardToolStripMenuItem;
      private System.Windows.Forms.ToolStripMenuItem maticniPodaciToolStripMenuItem;
      private System.Windows.Forms.ToolStripMenuItem partnerToolStripMenuItem;
      private System.Windows.Forms.ToolStripMenuItem artiklToolStripMenuItem;
      private System.Windows.Forms.ToolStripMenuItem tabliceToolStripMenuItem;
      private System.Windows.Forms.ToolStripMenuItem artiklToolStripTablice;
      private System.Windows.Forms.ToolStripMenuItem dokumentToolStripMenuItem;
      private System.Windows.Forms.ToolStripMenuItem drzavaToolStripTablice;
      private System.Windows.Forms.ToolStripMenuItem mjestoToolStripTablice;
      private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
      private System.Windows.Forms.ToolStripMenuItem HelpStripMenuItem;
      private System.Windows.Forms.HelpProvider helpProvider1;
    }
}


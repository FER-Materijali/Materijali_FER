namespace Tokenizer
{
  partial class FormTokenizer
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
      this.textBoxDelimiter = new System.Windows.Forms.TextBox();
      this.labelDelimiter = new System.Windows.Forms.Label();
      this.textBoxDatoteka = new System.Windows.Forms.TextBox();
      this.buttonBrowse = new System.Windows.Forms.Button();
      this.buttonPrikazi = new System.Windows.Forms.Button();
      this.openFileDialog = new System.Windows.Forms.OpenFileDialog();
      this.listViewPodaci = new System.Windows.Forms.ListView();
      this.panelUcitavanje = new System.Windows.Forms.Panel();
      this.errorProvider = new System.Windows.Forms.ErrorProvider(this.components);
      this.saveFileDialog = new System.Windows.Forms.SaveFileDialog();
      this.panelSpremanje = new System.Windows.Forms.Panel();
      this.textBoxDatotekaSpremi = new System.Windows.Forms.TextBox();
      this.textBoxDelimiterSpremi = new System.Windows.Forms.TextBox();
      this.buttonSpremi = new System.Windows.Forms.Button();
      this.labelDelimiterSpremi = new System.Windows.Forms.Label();
      this.buttonBrowseNew = new System.Windows.Forms.Button();
      this.label1 = new System.Windows.Forms.Label();
      this.label2 = new System.Windows.Forms.Label();
      this.panelUcitavanje.SuspendLayout();
      ((System.ComponentModel.ISupportInitialize)(this.errorProvider)).BeginInit();
      this.panelSpremanje.SuspendLayout();
      this.SuspendLayout();
      // 
      // textBoxDelimiter
      // 
      this.textBoxDelimiter.Location = new System.Drawing.Point(400, 16);
      this.textBoxDelimiter.MaxLength = 1;
      this.textBoxDelimiter.Name = "textBoxDelimiter";
      this.textBoxDelimiter.Size = new System.Drawing.Size(27, 20);
      this.textBoxDelimiter.TabIndex = 0;
      // 
      // labelDelimiter
      // 
      this.labelDelimiter.AutoSize = true;
      this.labelDelimiter.Location = new System.Drawing.Point(347, 19);
      this.labelDelimiter.Name = "labelDelimiter";
      this.labelDelimiter.Size = new System.Drawing.Size(50, 13);
      this.labelDelimiter.TabIndex = 1;
      this.labelDelimiter.Text = "Delimiter:";
      // 
      // textBoxDatoteka
      // 
      this.textBoxDatoteka.Location = new System.Drawing.Point(29, 16);
      this.textBoxDatoteka.Name = "textBoxDatoteka";
      this.textBoxDatoteka.Size = new System.Drawing.Size(214, 20);
      this.textBoxDatoteka.TabIndex = 2;
      // 
      // buttonBrowse
      // 
      this.buttonBrowse.Location = new System.Drawing.Point(249, 14);
      this.buttonBrowse.Name = "buttonBrowse";
      this.buttonBrowse.Size = new System.Drawing.Size(75, 23);
      this.buttonBrowse.TabIndex = 3;
      this.buttonBrowse.Text = "Browse...";
      this.buttonBrowse.UseVisualStyleBackColor = true;
      this.buttonBrowse.Click += new System.EventHandler(this.buttonBrowse_Click);
      // 
      // buttonPrikazi
      // 
      this.buttonPrikazi.Location = new System.Drawing.Point(455, 14);
      this.buttonPrikazi.Name = "buttonPrikazi";
      this.buttonPrikazi.Size = new System.Drawing.Size(75, 23);
      this.buttonPrikazi.TabIndex = 4;
      this.buttonPrikazi.Text = "Prikaži";
      this.buttonPrikazi.UseVisualStyleBackColor = true;
      this.buttonPrikazi.Click += new System.EventHandler(this.buttonPrikazi_Click);
      // 
      // openFileDialog
      // 
      this.openFileDialog.FileName = "dat.txt";
      this.openFileDialog.Filter = "(*.txt) | *.txt";
      this.openFileDialog.Title = "Odaberite datoteku";
      // 
      // listViewPodaci
      // 
      this.listViewPodaci.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                  | System.Windows.Forms.AnchorStyles.Left)
                  | System.Windows.Forms.AnchorStyles.Right)));
      this.listViewPodaci.Location = new System.Drawing.Point(17, 118);
      this.listViewPodaci.Name = "listViewPodaci";
      this.listViewPodaci.Size = new System.Drawing.Size(627, 228);
      this.listViewPodaci.TabIndex = 5;
      this.listViewPodaci.UseCompatibleStateImageBehavior = false;
      this.listViewPodaci.View = System.Windows.Forms.View.Details;
      // 
      // panelUcitavanje
      // 
      this.panelUcitavanje.Anchor = System.Windows.Forms.AnchorStyles.Top;
      this.panelUcitavanje.Controls.Add(this.textBoxDatoteka);
      this.panelUcitavanje.Controls.Add(this.textBoxDelimiter);
      this.panelUcitavanje.Controls.Add(this.buttonPrikazi);
      this.panelUcitavanje.Controls.Add(this.labelDelimiter);
      this.panelUcitavanje.Controls.Add(this.buttonBrowse);
      this.panelUcitavanje.Location = new System.Drawing.Point(115, 12);
      this.panelUcitavanje.Name = "panelUcitavanje";
      this.panelUcitavanje.Size = new System.Drawing.Size(548, 52);
      this.panelUcitavanje.TabIndex = 6;
      // 
      // errorProvider
      // 
      this.errorProvider.ContainerControl = this;
      // 
      // panelSpremanje
      // 
      this.panelSpremanje.Anchor = System.Windows.Forms.AnchorStyles.Top;
      this.panelSpremanje.Controls.Add(this.textBoxDatotekaSpremi);
      this.panelSpremanje.Controls.Add(this.textBoxDelimiterSpremi);
      this.panelSpremanje.Controls.Add(this.buttonSpremi);
      this.panelSpremanje.Controls.Add(this.labelDelimiterSpremi);
      this.panelSpremanje.Controls.Add(this.buttonBrowseNew);
      this.panelSpremanje.Location = new System.Drawing.Point(115, 55);
      this.panelSpremanje.Name = "panelSpremanje";
      this.panelSpremanje.Size = new System.Drawing.Size(548, 52);
      this.panelSpremanje.TabIndex = 7;
      // 
      // textBoxDatotekaSpremi
      // 
      this.textBoxDatotekaSpremi.Location = new System.Drawing.Point(29, 16);
      this.textBoxDatotekaSpremi.Name = "textBoxDatotekaSpremi";
      this.textBoxDatotekaSpremi.Size = new System.Drawing.Size(214, 20);
      this.textBoxDatotekaSpremi.TabIndex = 2;
      // 
      // textBoxDelimiterSpremi
      // 
      this.textBoxDelimiterSpremi.Location = new System.Drawing.Point(400, 16);
      this.textBoxDelimiterSpremi.MaxLength = 1;
      this.textBoxDelimiterSpremi.Name = "textBoxDelimiterSpremi";
      this.textBoxDelimiterSpremi.Size = new System.Drawing.Size(27, 20);
      this.textBoxDelimiterSpremi.TabIndex = 0;
      // 
      // buttonSpremi
      // 
      this.buttonSpremi.Location = new System.Drawing.Point(455, 14);
      this.buttonSpremi.Name = "buttonSpremi";
      this.buttonSpremi.Size = new System.Drawing.Size(75, 23);
      this.buttonSpremi.TabIndex = 4;
      this.buttonSpremi.Text = "Spremi";
      this.buttonSpremi.UseVisualStyleBackColor = true;
      this.buttonSpremi.Click += new System.EventHandler(this.buttonSpremi_Click);
      // 
      // labelDelimiterSpremi
      // 
      this.labelDelimiterSpremi.AutoSize = true;
      this.labelDelimiterSpremi.Location = new System.Drawing.Point(347, 19);
      this.labelDelimiterSpremi.Name = "labelDelimiterSpremi";
      this.labelDelimiterSpremi.Size = new System.Drawing.Size(50, 13);
      this.labelDelimiterSpremi.TabIndex = 1;
      this.labelDelimiterSpremi.Text = "Delimiter:";
      // 
      // buttonBrowseNew
      // 
      this.buttonBrowseNew.Location = new System.Drawing.Point(249, 14);
      this.buttonBrowseNew.Name = "buttonBrowseNew";
      this.buttonBrowseNew.Size = new System.Drawing.Size(75, 23);
      this.buttonBrowseNew.TabIndex = 3;
      this.buttonBrowseNew.Text = "Browse...";
      this.buttonBrowseNew.UseVisualStyleBackColor = true;
      this.buttonBrowseNew.Click += new System.EventHandler(this.buttonBrowseNew_Click);
      // 
      // label1
      // 
      this.label1.AutoSize = true;
      this.label1.Location = new System.Drawing.Point(12, 31);
      this.label1.Name = "label1";
      this.label1.Size = new System.Drawing.Size(97, 13);
      this.label1.TabIndex = 8;
      this.label1.Text = "Izvorišna datoteka:";
      // 
      // label2
      // 
      this.label2.AutoSize = true;
      this.label2.Location = new System.Drawing.Point(14, 74);
      this.label2.Name = "label2";
      this.label2.Size = new System.Drawing.Size(103, 13);
      this.label2.TabIndex = 9;
      this.label2.Text = "Odredišna datoteka:";
      // 
      // FormTokenizer
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.ClientSize = new System.Drawing.Size(661, 358);
      this.Controls.Add(this.label2);
      this.Controls.Add(this.label1);
      this.Controls.Add(this.panelSpremanje);
      this.Controls.Add(this.panelUcitavanje);
      this.Controls.Add(this.listViewPodaci);
      this.Name = "FormTokenizer";
      this.Text = "Tokenizer";
      this.panelUcitavanje.ResumeLayout(false);
      this.panelUcitavanje.PerformLayout();
      ((System.ComponentModel.ISupportInitialize)(this.errorProvider)).EndInit();
      this.panelSpremanje.ResumeLayout(false);
      this.panelSpremanje.PerformLayout();
      this.ResumeLayout(false);
      this.PerformLayout();

    }

    #endregion

    private System.Windows.Forms.TextBox textBoxDelimiter;
    private System.Windows.Forms.Label labelDelimiter;
    private System.Windows.Forms.TextBox textBoxDatoteka;
    private System.Windows.Forms.Button buttonBrowse;
    private System.Windows.Forms.Button buttonPrikazi;
    private System.Windows.Forms.OpenFileDialog openFileDialog;
    private System.Windows.Forms.ListView listViewPodaci;
    private System.Windows.Forms.Panel panelUcitavanje;
    private System.Windows.Forms.ErrorProvider errorProvider;
    private System.Windows.Forms.Panel panelSpremanje;
    private System.Windows.Forms.TextBox textBoxDatotekaSpremi;
    private System.Windows.Forms.TextBox textBoxDelimiterSpremi;
    private System.Windows.Forms.Button buttonSpremi;
    private System.Windows.Forms.Label labelDelimiterSpremi;
    private System.Windows.Forms.Button buttonBrowseNew;
    private System.Windows.Forms.SaveFileDialog saveFileDialog;
    private System.Windows.Forms.Label label2;
    private System.Windows.Forms.Label label1;
  }
}


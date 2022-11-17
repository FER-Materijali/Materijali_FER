namespace Dokumenti
{
    partial class DokumentiForm
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
          this.dateTimePickerOd = new System.Windows.Forms.DateTimePicker();
          this.dateTimePickerDo = new System.Windows.Forms.DateTimePicker();
          this.groupBoxIzvjestaj = new System.Windows.Forms.GroupBox();
          this.checkBoxSviPartneri = new System.Windows.Forms.CheckBox();
          this.labelPartner = new System.Windows.Forms.Label();
          this.labelDatum = new System.Windows.Forms.Label();
          this.comboBoxPartneri = new System.Windows.Forms.ComboBox();
          this.checkBoxSviDatumi = new System.Windows.Forms.CheckBox();
          this.buttonAdrese = new System.Windows.Forms.Button();
          this.buttonDokumenti = new System.Windows.Forms.Button();
          this.labelDo = new System.Windows.Forms.Label();
          this.labelOd = new System.Windows.Forms.Label();
          this.reportViewer = new CrystalDecisions.Windows.Forms.CrystalReportViewer();
          this.groupBoxIzvjestaj.SuspendLayout();
          this.SuspendLayout();
          // 
          // dateTimePickerOd
          // 
          this.dateTimePickerOd.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
          this.dateTimePickerOd.Location = new System.Drawing.Point(103, 24);
          this.dateTimePickerOd.Name = "dateTimePickerOd";
          this.dateTimePickerOd.Size = new System.Drawing.Size(116, 20);
          this.dateTimePickerOd.TabIndex = 0;
          // 
          // dateTimePickerDo
          // 
          this.dateTimePickerDo.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
          this.dateTimePickerDo.Location = new System.Drawing.Point(253, 24);
          this.dateTimePickerDo.Name = "dateTimePickerDo";
          this.dateTimePickerDo.Size = new System.Drawing.Size(112, 20);
          this.dateTimePickerDo.TabIndex = 1;
          // 
          // groupBoxIzvjestaj
          // 
          this.groupBoxIzvjestaj.Anchor = System.Windows.Forms.AnchorStyles.Top;
          this.groupBoxIzvjestaj.Controls.Add(this.checkBoxSviPartneri);
          this.groupBoxIzvjestaj.Controls.Add(this.labelPartner);
          this.groupBoxIzvjestaj.Controls.Add(this.labelDatum);
          this.groupBoxIzvjestaj.Controls.Add(this.comboBoxPartneri);
          this.groupBoxIzvjestaj.Controls.Add(this.checkBoxSviDatumi);
          this.groupBoxIzvjestaj.Controls.Add(this.buttonAdrese);
          this.groupBoxIzvjestaj.Controls.Add(this.buttonDokumenti);
          this.groupBoxIzvjestaj.Controls.Add(this.labelDo);
          this.groupBoxIzvjestaj.Controls.Add(this.dateTimePickerDo);
          this.groupBoxIzvjestaj.Controls.Add(this.labelOd);
          this.groupBoxIzvjestaj.Controls.Add(this.dateTimePickerOd);
          this.groupBoxIzvjestaj.Location = new System.Drawing.Point(12, 12);
          this.groupBoxIzvjestaj.Name = "groupBoxIzvjestaj";
          this.groupBoxIzvjestaj.Size = new System.Drawing.Size(610, 89);
          this.groupBoxIzvjestaj.TabIndex = 2;
          this.groupBoxIzvjestaj.TabStop = false;
          this.groupBoxIzvjestaj.Text = "Odaberite izvješæe";
          // 
          // checkBoxSviPartneri
          // 
          this.checkBoxSviPartneri.AutoSize = true;
          this.checkBoxSviPartneri.Location = new System.Drawing.Point(380, 52);
          this.checkBoxSviPartneri.Name = "checkBoxSviPartneri";
          this.checkBoxSviPartneri.Size = new System.Drawing.Size(79, 17);
          this.checkBoxSviPartneri.TabIndex = 8;
          this.checkBoxSviPartneri.Text = "Svi partneri";
          this.checkBoxSviPartneri.UseVisualStyleBackColor = true;
          this.checkBoxSviPartneri.CheckedChanged += new System.EventHandler(this.checkBoxSviPartneri_CheckedChanged);
          // 
          // labelPartner
          // 
          this.labelPartner.AutoSize = true;
          this.labelPartner.Location = new System.Drawing.Point(13, 53);
          this.labelPartner.Name = "labelPartner";
          this.labelPartner.Size = new System.Drawing.Size(41, 13);
          this.labelPartner.TabIndex = 7;
          this.labelPartner.Text = "Partner";
          // 
          // labelDatum
          // 
          this.labelDatum.AutoSize = true;
          this.labelDatum.Location = new System.Drawing.Point(13, 28);
          this.labelDatum.Name = "labelDatum";
          this.labelDatum.Size = new System.Drawing.Size(38, 13);
          this.labelDatum.TabIndex = 6;
          this.labelDatum.Text = "Datum";
          // 
          // comboBoxPartneri
          // 
          this.comboBoxPartneri.FormattingEnabled = true;
          this.comboBoxPartneri.Location = new System.Drawing.Point(103, 50);
          this.comboBoxPartneri.Name = "comboBoxPartneri";
          this.comboBoxPartneri.Size = new System.Drawing.Size(262, 21);
          this.comboBoxPartneri.TabIndex = 5;
          // 
          // checkBoxSviDatumi
          // 
          this.checkBoxSviDatumi.AutoSize = true;
          this.checkBoxSviDatumi.Location = new System.Drawing.Point(380, 27);
          this.checkBoxSviDatumi.Name = "checkBoxSviDatumi";
          this.checkBoxSviDatumi.Size = new System.Drawing.Size(75, 17);
          this.checkBoxSviDatumi.TabIndex = 4;
          this.checkBoxSviDatumi.Text = "Svi datumi";
          this.checkBoxSviDatumi.UseVisualStyleBackColor = true;
          this.checkBoxSviDatumi.CheckedChanged += new System.EventHandler(this.checkBoxSviDatumi_CheckedChanged);
          // 
          // buttonAdrese
          // 
          this.buttonAdrese.Location = new System.Drawing.Point(461, 47);
          this.buttonAdrese.Name = "buttonAdrese";
          this.buttonAdrese.Size = new System.Drawing.Size(134, 34);
          this.buttonAdrese.TabIndex = 3;
          this.buttonAdrese.Text = "Naljepnice - adrese isporuke";
          this.buttonAdrese.UseVisualStyleBackColor = true;
          this.buttonAdrese.Click += new System.EventHandler(this.buttonAdrese_Click);
          // 
          // buttonDokumenti
          // 
          this.buttonDokumenti.Location = new System.Drawing.Point(461, 9);
          this.buttonDokumenti.Name = "buttonDokumenti";
          this.buttonDokumenti.Size = new System.Drawing.Size(134, 32);
          this.buttonDokumenti.TabIndex = 2;
          this.buttonDokumenti.Text = "Popis dokumenata";
          this.buttonDokumenti.UseVisualStyleBackColor = true;
          this.buttonDokumenti.Click += new System.EventHandler(this.buttonDokumenti_Click);
          // 
          // labelDo
          // 
          this.labelDo.AutoSize = true;
          this.labelDo.Location = new System.Drawing.Point(225, 28);
          this.labelDo.Name = "labelDo";
          this.labelDo.Size = new System.Drawing.Size(22, 13);
          this.labelDo.TabIndex = 1;
          this.labelDo.Text = "do:";
          // 
          // labelOd
          // 
          this.labelOd.AutoSize = true;
          this.labelOd.Location = new System.Drawing.Point(64, 28);
          this.labelOd.Name = "labelOd";
          this.labelOd.Size = new System.Drawing.Size(22, 13);
          this.labelOd.TabIndex = 0;
          this.labelOd.Text = "od:";
          // 
          // reportViewer
          // 
          this.reportViewer.ActiveViewIndex = -1;
          this.reportViewer.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                      | System.Windows.Forms.AnchorStyles.Left)
                      | System.Windows.Forms.AnchorStyles.Right)));
          this.reportViewer.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
          this.reportViewer.Location = new System.Drawing.Point(12, 107);
          this.reportViewer.Name = "reportViewer";
          this.reportViewer.SelectionFormula = "";
          this.reportViewer.Size = new System.Drawing.Size(610, 513);
          this.reportViewer.TabIndex = 3;
          this.reportViewer.ViewTimeSelectionFormula = "";
          // 
          // DokumentiForm
          // 
          this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
          this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
          this.ClientSize = new System.Drawing.Size(636, 632);
          this.Controls.Add(this.reportViewer);
          this.Controls.Add(this.groupBoxIzvjestaj);
          this.Name = "DokumentiForm";
          this.Text = "Izvješæe dokumenata po datumu";
          this.groupBoxIzvjestaj.ResumeLayout(false);
          this.groupBoxIzvjestaj.PerformLayout();
          this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DateTimePicker dateTimePickerOd;
        private System.Windows.Forms.DateTimePicker dateTimePickerDo;
        private System.Windows.Forms.GroupBox groupBoxIzvjestaj;
        private System.Windows.Forms.Label labelDo;
        private System.Windows.Forms.Label labelOd;
        private System.Windows.Forms.Button buttonDokumenti;
      private CrystalDecisions.Windows.Forms.CrystalReportViewer reportViewer;
      private System.Windows.Forms.Button buttonAdrese;
      private System.Windows.Forms.CheckBox checkBoxSviDatumi;
        private System.Windows.Forms.ComboBox comboBoxPartneri;
        private System.Windows.Forms.Label labelPartner;
        private System.Windows.Forms.Label labelDatum;
      private System.Windows.Forms.CheckBox checkBoxSviPartneri;
    }
}


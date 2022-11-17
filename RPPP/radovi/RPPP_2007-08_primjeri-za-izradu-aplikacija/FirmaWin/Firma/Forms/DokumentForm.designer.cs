namespace Firma
{
    partial class DokumentForm
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
          System.Windows.Forms.Label brDokumentaLabel;
          System.Windows.Forms.Label datDokumentaLabel;
          System.Windows.Forms.Label idPartneraLabel;
          System.Windows.Forms.Label idPrethDokumentaLabel;
          System.Windows.Forms.Label iznosDokumentaLabel;
          System.Windows.Forms.Label postoPorezLabel;
          System.Windows.Forms.Label vrDokumentaLabel;
          System.Windows.Forms.Label label1;
          System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle1 = new System.Windows.Forms.DataGridViewCellStyle();
          System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle2 = new System.Windows.Forms.DataGridViewCellStyle();
          System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle3 = new System.Windows.Forms.DataGridViewCellStyle();
          System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle4 = new System.Windows.Forms.DataGridViewCellStyle();
          System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle5 = new System.Windows.Forms.DataGridViewCellStyle();
          this.dokumentBindingSource = new System.Windows.Forms.BindingSource(this.components);
          this.stavkaBindingSource = new System.Windows.Forms.BindingSource(this.components);
          this.dokumentPanel = new System.Windows.Forms.Panel();
          this.textBox1 = new System.Windows.Forms.TextBox();
          this.vrDokumentaTextBox = new System.Windows.Forms.TextBox();
          this.postoPorezTextBox = new System.Windows.Forms.TextBox();
          this.iznosDokumentaTextBox = new System.Windows.Forms.TextBox();
          this.idPrethDokumentaComboBox = new System.Windows.Forms.ComboBox();
          this.prethDokumentBindingSource = new System.Windows.Forms.BindingSource(this.components);
          this.idPartneraComboBox = new System.Windows.Forms.ComboBox();
          this.partnerInfoBindingSource = new System.Windows.Forms.BindingSource(this.components);
          this.datDokumentaDateTimePicker = new System.Windows.Forms.DateTimePicker();
          this.brDokumentaTextBox = new System.Windows.Forms.TextBox();
          this.stavkaPanel = new System.Windows.Forms.Panel();
          this.stavkaDataGridView = new System.Windows.Forms.DataGridView();
          this.dataGridViewTextBoxColumn6 = new System.Windows.Forms.DataGridViewComboBoxColumn();
          this.artiklBindingSource = new System.Windows.Forms.BindingSource(this.components);
          this.dataGridViewTextBoxColumn7 = new System.Windows.Forms.DataGridViewTextBoxColumn();
          this.dataGridViewTextBoxColumn3 = new System.Windows.Forms.DataGridViewTextBoxColumn();
          this.dataGridViewTextBoxColumn4 = new System.Windows.Forms.DataGridViewTextBoxColumn();
          this.dataGridViewTextBoxColumn5 = new System.Windows.Forms.DataGridViewTextBoxColumn();
          this.dataGridViewTextBoxColumn1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
          this.stavkaErrorProvider = new System.Windows.Forms.ErrorProvider(this.components);
          this.dokumentErrorProvider = new System.Windows.Forms.ErrorProvider(this.components);
          this.formToolbar1 = new Firma.FormToolbar(this.components);
          brDokumentaLabel = new System.Windows.Forms.Label();
          datDokumentaLabel = new System.Windows.Forms.Label();
          idPartneraLabel = new System.Windows.Forms.Label();
          idPrethDokumentaLabel = new System.Windows.Forms.Label();
          iznosDokumentaLabel = new System.Windows.Forms.Label();
          postoPorezLabel = new System.Windows.Forms.Label();
          vrDokumentaLabel = new System.Windows.Forms.Label();
          label1 = new System.Windows.Forms.Label();
          ((System.ComponentModel.ISupportInitialize)(this.dokumentBindingSource)).BeginInit();
          ((System.ComponentModel.ISupportInitialize)(this.stavkaBindingSource)).BeginInit();
          this.dokumentPanel.SuspendLayout();
          ((System.ComponentModel.ISupportInitialize)(this.prethDokumentBindingSource)).BeginInit();
          ((System.ComponentModel.ISupportInitialize)(this.partnerInfoBindingSource)).BeginInit();
          this.stavkaPanel.SuspendLayout();
          ((System.ComponentModel.ISupportInitialize)(this.stavkaDataGridView)).BeginInit();
          ((System.ComponentModel.ISupportInitialize)(this.artiklBindingSource)).BeginInit();
          ((System.ComponentModel.ISupportInitialize)(this.stavkaErrorProvider)).BeginInit();
          ((System.ComponentModel.ISupportInitialize)(this.dokumentErrorProvider)).BeginInit();
          this.SuspendLayout();
          // 
          // brDokumentaLabel
          // 
          brDokumentaLabel.AutoSize = true;
          brDokumentaLabel.Location = new System.Drawing.Point(312, 20);
          brDokumentaLabel.Name = "brDokumentaLabel";
          brDokumentaLabel.Size = new System.Drawing.Size(25, 13);
          brDokumentaLabel.TabIndex = 0;
          brDokumentaLabel.Text = "Broj";
          // 
          // datDokumentaLabel
          // 
          datDokumentaLabel.AutoSize = true;
          datDokumentaLabel.Location = new System.Drawing.Point(488, 20);
          datDokumentaLabel.Name = "datDokumentaLabel";
          datDokumentaLabel.Size = new System.Drawing.Size(38, 13);
          datDokumentaLabel.TabIndex = 2;
          datDokumentaLabel.Text = "Datum";
          // 
          // idPartneraLabel
          // 
          idPartneraLabel.AutoSize = true;
          idPartneraLabel.Location = new System.Drawing.Point(12, 46);
          idPartneraLabel.Name = "idPartneraLabel";
          idPartneraLabel.Size = new System.Drawing.Size(41, 13);
          idPartneraLabel.TabIndex = 4;
          idPartneraLabel.Text = "Partner";
          // 
          // idPrethDokumentaLabel
          // 
          idPrethDokumentaLabel.AutoSize = true;
          idPrethDokumentaLabel.Location = new System.Drawing.Point(12, 73);
          idPrethDokumentaLabel.Name = "idPrethDokumentaLabel";
          idPrethDokumentaLabel.Size = new System.Drawing.Size(76, 13);
          idPrethDokumentaLabel.TabIndex = 6;
          idPrethDokumentaLabel.Text = "Prethodni dok.";
          // 
          // iznosDokumentaLabel
          // 
          iznosDokumentaLabel.AutoSize = true;
          iznosDokumentaLabel.Location = new System.Drawing.Point(488, 72);
          iznosDokumentaLabel.Name = "iznosDokumentaLabel";
          iznosDokumentaLabel.Size = new System.Drawing.Size(32, 13);
          iznosDokumentaLabel.TabIndex = 8;
          iznosDokumentaLabel.Text = "Iznos";
          // 
          // postoPorezLabel
          // 
          postoPorezLabel.AutoSize = true;
          postoPorezLabel.Location = new System.Drawing.Point(488, 46);
          postoPorezLabel.Name = "postoPorezLabel";
          postoPorezLabel.Size = new System.Drawing.Size(34, 13);
          postoPorezLabel.TabIndex = 10;
          postoPorezLabel.Text = "Porez";
          // 
          // vrDokumentaLabel
          // 
          vrDokumentaLabel.AutoSize = true;
          vrDokumentaLabel.Location = new System.Drawing.Point(178, 20);
          vrDokumentaLabel.Name = "vrDokumentaLabel";
          vrDokumentaLabel.Size = new System.Drawing.Size(31, 13);
          vrDokumentaLabel.TabIndex = 12;
          vrDokumentaLabel.Text = "Vrsta";
          // 
          // label1
          // 
          label1.AutoSize = true;
          label1.Location = new System.Drawing.Point(12, 20);
          label1.Name = "label1";
          label1.Size = new System.Drawing.Size(72, 13);
          label1.TabIndex = 14;
          label1.Text = "Id dokumenta";
          // 
          // dokumentBindingSource
          // 
          this.dokumentBindingSource.DataSource = typeof(Firma.Dokument);
          this.dokumentBindingSource.CurrentChanged += new System.EventHandler(this.dokumentBindingSource_CurrentChanged);
          this.dokumentBindingSource.CurrentItemChanged += new System.EventHandler(this.dokumentBindingSource_CurrentItemChanged);
          // 
          // stavkaBindingSource
          // 
          this.stavkaBindingSource.DataSource = typeof(Firma.Stavka);
          this.stavkaBindingSource.CurrentChanged += new System.EventHandler(this.stavkaBindingSource_CurrentChanged);
          // 
          // dokumentPanel
          // 
          this.dokumentPanel.Controls.Add(label1);
          this.dokumentPanel.Controls.Add(this.textBox1);
          this.dokumentPanel.Controls.Add(vrDokumentaLabel);
          this.dokumentPanel.Controls.Add(this.vrDokumentaTextBox);
          this.dokumentPanel.Controls.Add(postoPorezLabel);
          this.dokumentPanel.Controls.Add(this.postoPorezTextBox);
          this.dokumentPanel.Controls.Add(iznosDokumentaLabel);
          this.dokumentPanel.Controls.Add(this.iznosDokumentaTextBox);
          this.dokumentPanel.Controls.Add(idPrethDokumentaLabel);
          this.dokumentPanel.Controls.Add(this.idPrethDokumentaComboBox);
          this.dokumentPanel.Controls.Add(idPartneraLabel);
          this.dokumentPanel.Controls.Add(this.idPartneraComboBox);
          this.dokumentPanel.Controls.Add(datDokumentaLabel);
          this.dokumentPanel.Controls.Add(this.datDokumentaDateTimePicker);
          this.dokumentPanel.Controls.Add(brDokumentaLabel);
          this.dokumentPanel.Controls.Add(this.brDokumentaTextBox);
          this.dokumentPanel.Dock = System.Windows.Forms.DockStyle.Top;
          this.dokumentPanel.Enabled = false;
          this.dokumentPanel.Location = new System.Drawing.Point(0, 25);
          this.dokumentPanel.Name = "dokumentPanel";
          this.dokumentPanel.Size = new System.Drawing.Size(738, 111);
          this.dokumentPanel.TabIndex = 2;
          // 
          // textBox1
          // 
          this.textBox1.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.dokumentBindingSource, "IdDokumenta", true));
          this.textBox1.Location = new System.Drawing.Point(90, 17);
          this.textBox1.Name = "textBox1";
          this.textBox1.ReadOnly = true;
          this.textBox1.Size = new System.Drawing.Size(64, 20);
          this.textBox1.TabIndex = 0;
          // 
          // vrDokumentaTextBox
          // 
          this.vrDokumentaTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.dokumentBindingSource, "VrDokumenta", true));
          this.vrDokumentaTextBox.Location = new System.Drawing.Point(215, 17);
          this.vrDokumentaTextBox.Name = "vrDokumentaTextBox";
          this.vrDokumentaTextBox.Size = new System.Drawing.Size(50, 20);
          this.vrDokumentaTextBox.TabIndex = 1;
          this.vrDokumentaTextBox.Leave += new System.EventHandler(this.DokumentControlLeave);
          this.vrDokumentaTextBox.Enter += new System.EventHandler(this.DokumentControlEnter);
          // 
          // postoPorezTextBox
          // 
          this.postoPorezTextBox.Location = new System.Drawing.Point(532, 43);
          this.postoPorezTextBox.Name = "postoPorezTextBox";
          this.postoPorezTextBox.Size = new System.Drawing.Size(100, 20);
          this.postoPorezTextBox.TabIndex = 6;
          this.postoPorezTextBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
          this.postoPorezTextBox.Leave += new System.EventHandler(this.DokumentControlLeave);
          this.postoPorezTextBox.Enter += new System.EventHandler(this.DokumentControlEnter);
          // 
          // iznosDokumentaTextBox
          // 
          this.iznosDokumentaTextBox.Location = new System.Drawing.Point(532, 69);
          this.iznosDokumentaTextBox.Name = "iznosDokumentaTextBox";
          this.iznosDokumentaTextBox.ReadOnly = true;
          this.iznosDokumentaTextBox.Size = new System.Drawing.Size(100, 20);
          this.iznosDokumentaTextBox.TabIndex = 7;
          this.iznosDokumentaTextBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
          this.iznosDokumentaTextBox.Leave += new System.EventHandler(this.DokumentControlLeave);
          this.iznosDokumentaTextBox.Enter += new System.EventHandler(this.DokumentControlEnter);
          // 
          // idPrethDokumentaComboBox
          // 
          this.idPrethDokumentaComboBox.AutoCompleteMode = System.Windows.Forms.AutoCompleteMode.SuggestAppend;
          this.idPrethDokumentaComboBox.AutoCompleteSource = System.Windows.Forms.AutoCompleteSource.ListItems;
          this.idPrethDokumentaComboBox.DataBindings.Add(new System.Windows.Forms.Binding("SelectedValue", this.dokumentBindingSource, "IdPrethDokumenta", true));
          this.idPrethDokumentaComboBox.DataSource = this.prethDokumentBindingSource;
          this.idPrethDokumentaComboBox.DisplayMember = "LookupText";
          this.idPrethDokumentaComboBox.FormattingEnabled = true;
          this.idPrethDokumentaComboBox.Location = new System.Drawing.Point(90, 70);
          this.idPrethDokumentaComboBox.Name = "idPrethDokumentaComboBox";
          this.idPrethDokumentaComboBox.Size = new System.Drawing.Size(337, 21);
          this.idPrethDokumentaComboBox.TabIndex = 4;
          this.idPrethDokumentaComboBox.ValueMember = "IdDokumenta";
          this.idPrethDokumentaComboBox.Leave += new System.EventHandler(this.DokumentControlLeave);
          this.idPrethDokumentaComboBox.Enter += new System.EventHandler(this.DokumentControlEnter);
          // 
          // prethDokumentBindingSource
          // 
          this.prethDokumentBindingSource.DataSource = typeof(Firma.Dokument);
          // 
          // idPartneraComboBox
          // 
          this.idPartneraComboBox.DataBindings.Add(new System.Windows.Forms.Binding("SelectedValue", this.dokumentBindingSource, "IdPartnera", true));
          this.idPartneraComboBox.DataSource = this.partnerInfoBindingSource;
          this.idPartneraComboBox.DisplayMember = "Naziv";
          this.idPartneraComboBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
          this.idPartneraComboBox.FormattingEnabled = true;
          this.idPartneraComboBox.Location = new System.Drawing.Point(90, 43);
          this.idPartneraComboBox.Name = "idPartneraComboBox";
          this.idPartneraComboBox.Size = new System.Drawing.Size(337, 21);
          this.idPartneraComboBox.TabIndex = 3;
          this.idPartneraComboBox.ValueMember = "IdPartnera";
          this.idPartneraComboBox.Leave += new System.EventHandler(this.DokumentControlLeave);
          this.idPartneraComboBox.Enter += new System.EventHandler(this.DokumentControlEnter);
          // 
          // partnerInfoBindingSource
          // 
          this.partnerInfoBindingSource.DataSource = typeof(Firma.Partner);
          // 
          // datDokumentaDateTimePicker
          // 
          this.datDokumentaDateTimePicker.DataBindings.Add(new System.Windows.Forms.Binding("Value", this.dokumentBindingSource, "DatDokumenta", true));
          this.datDokumentaDateTimePicker.Format = System.Windows.Forms.DateTimePickerFormat.Short;
          this.datDokumentaDateTimePicker.Location = new System.Drawing.Point(532, 17);
          this.datDokumentaDateTimePicker.Name = "datDokumentaDateTimePicker";
          this.datDokumentaDateTimePicker.Size = new System.Drawing.Size(100, 20);
          this.datDokumentaDateTimePicker.TabIndex = 5;
          this.datDokumentaDateTimePicker.Leave += new System.EventHandler(this.DokumentControlLeave);
          this.datDokumentaDateTimePicker.Enter += new System.EventHandler(this.DokumentControlEnter);
          // 
          // brDokumentaTextBox
          // 
          this.brDokumentaTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.dokumentBindingSource, "BrDokumenta", true));
          this.brDokumentaTextBox.Location = new System.Drawing.Point(343, 17);
          this.brDokumentaTextBox.Name = "brDokumentaTextBox";
          this.brDokumentaTextBox.Size = new System.Drawing.Size(84, 20);
          this.brDokumentaTextBox.TabIndex = 2;
          this.brDokumentaTextBox.Leave += new System.EventHandler(this.DokumentControlLeave);
          this.brDokumentaTextBox.Enter += new System.EventHandler(this.DokumentControlEnter);
          // 
          // stavkaPanel
          // 
          this.stavkaPanel.Controls.Add(this.stavkaDataGridView);
          this.stavkaPanel.Dock = System.Windows.Forms.DockStyle.Fill;
          this.stavkaPanel.Location = new System.Drawing.Point(0, 136);
          this.stavkaPanel.Name = "stavkaPanel";
          this.stavkaPanel.Size = new System.Drawing.Size(738, 243);
          this.stavkaPanel.TabIndex = 4;
          // 
          // stavkaDataGridView
          // 
          this.stavkaDataGridView.AutoGenerateColumns = false;
          this.stavkaDataGridView.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dataGridViewTextBoxColumn6,
            this.dataGridViewTextBoxColumn7,
            this.dataGridViewTextBoxColumn3,
            this.dataGridViewTextBoxColumn4,
            this.dataGridViewTextBoxColumn5,
            this.dataGridViewTextBoxColumn1});
          this.stavkaDataGridView.DataSource = this.stavkaBindingSource;
          this.stavkaDataGridView.Dock = System.Windows.Forms.DockStyle.Fill;
          this.stavkaDataGridView.Location = new System.Drawing.Point(0, 0);
          this.stavkaDataGridView.Name = "stavkaDataGridView";
          this.stavkaDataGridView.Size = new System.Drawing.Size(738, 243);
          this.stavkaDataGridView.TabIndex = 0;
          this.stavkaDataGridView.CellValueChanged += new System.Windows.Forms.DataGridViewCellEventHandler(this.stavkaDataGridView_CellValueChanged);
          // 
          // dataGridViewTextBoxColumn6
          // 
          this.dataGridViewTextBoxColumn6.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
          this.dataGridViewTextBoxColumn6.DataPropertyName = "SifArtikla";
          this.dataGridViewTextBoxColumn6.DataSource = this.artiklBindingSource;
          this.dataGridViewTextBoxColumn6.DisplayMember = "NazArtikla";
          this.dataGridViewTextBoxColumn6.HeaderText = "Naziv artikla";
          this.dataGridViewTextBoxColumn6.Name = "dataGridViewTextBoxColumn6";
          this.dataGridViewTextBoxColumn6.Resizable = System.Windows.Forms.DataGridViewTriState.True;
          this.dataGridViewTextBoxColumn6.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.Automatic;
          this.dataGridViewTextBoxColumn6.ValueMember = "SifArtikla";
          // 
          // artiklBindingSource
          // 
          this.artiklBindingSource.DataSource = typeof(Firma.Artikl);
          // 
          // dataGridViewTextBoxColumn7
          // 
          this.dataGridViewTextBoxColumn7.DataPropertyName = "JedMjereArtikla";
          dataGridViewCellStyle1.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
          this.dataGridViewTextBoxColumn7.DefaultCellStyle = dataGridViewCellStyle1;
          this.dataGridViewTextBoxColumn7.HeaderText = "Mjera";
          this.dataGridViewTextBoxColumn7.Name = "dataGridViewTextBoxColumn7";
          this.dataGridViewTextBoxColumn7.ReadOnly = true;
          this.dataGridViewTextBoxColumn7.Width = 60;
          // 
          // dataGridViewTextBoxColumn3
          // 
          this.dataGridViewTextBoxColumn3.DataPropertyName = "KolArtikla";
          dataGridViewCellStyle2.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleRight;
          dataGridViewCellStyle2.Format = "N2";
          dataGridViewCellStyle2.NullValue = null;
          this.dataGridViewTextBoxColumn3.DefaultCellStyle = dataGridViewCellStyle2;
          this.dataGridViewTextBoxColumn3.HeaderText = "Kolièina";
          this.dataGridViewTextBoxColumn3.Name = "dataGridViewTextBoxColumn3";
          this.dataGridViewTextBoxColumn3.Width = 75;
          // 
          // dataGridViewTextBoxColumn4
          // 
          this.dataGridViewTextBoxColumn4.DataPropertyName = "JedCijArtikla";
          dataGridViewCellStyle3.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleRight;
          dataGridViewCellStyle3.Format = "C2";
          dataGridViewCellStyle3.NullValue = null;
          this.dataGridViewTextBoxColumn4.DefaultCellStyle = dataGridViewCellStyle3;
          this.dataGridViewTextBoxColumn4.HeaderText = "Jedinièna cijena";
          this.dataGridViewTextBoxColumn4.Name = "dataGridViewTextBoxColumn4";
          // 
          // dataGridViewTextBoxColumn5
          // 
          this.dataGridViewTextBoxColumn5.DataPropertyName = "PostoRabat";
          dataGridViewCellStyle4.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleRight;
          dataGridViewCellStyle4.Format = "p";
          dataGridViewCellStyle4.NullValue = null;
          this.dataGridViewTextBoxColumn5.DefaultCellStyle = dataGridViewCellStyle4;
          this.dataGridViewTextBoxColumn5.HeaderText = "Rabat";
          this.dataGridViewTextBoxColumn5.Name = "dataGridViewTextBoxColumn5";
          this.dataGridViewTextBoxColumn5.Width = 75;
          // 
          // dataGridViewTextBoxColumn1
          // 
          this.dataGridViewTextBoxColumn1.DataPropertyName = "Iznos";
          dataGridViewCellStyle5.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleRight;
          dataGridViewCellStyle5.Format = "C2";
          dataGridViewCellStyle5.NullValue = null;
          this.dataGridViewTextBoxColumn1.DefaultCellStyle = dataGridViewCellStyle5;
          this.dataGridViewTextBoxColumn1.HeaderText = "Ukupna cijena";
          this.dataGridViewTextBoxColumn1.Name = "dataGridViewTextBoxColumn1";
          this.dataGridViewTextBoxColumn1.ReadOnly = true;
          // 
          // stavkaErrorProvider
          // 
          this.stavkaErrorProvider.ContainerControl = this;
          this.stavkaErrorProvider.DataSource = this.stavkaBindingSource;
          // 
          // dokumentErrorProvider
          // 
          this.dokumentErrorProvider.ContainerControl = this;
          this.dokumentErrorProvider.DataSource = this.dokumentBindingSource;
          // 
          // formToolbar1
          // 
          this.formToolbar1.Enabled = false;
          this.formToolbar1.Form = this;
          this.formToolbar1.GripStyle = System.Windows.Forms.ToolStripGripStyle.Hidden;
          this.formToolbar1.Location = new System.Drawing.Point(0, 0);
          this.formToolbar1.Name = "formToolbar1";
          this.formToolbar1.Size = new System.Drawing.Size(738, 25);
          this.formToolbar1.TabIndex = 5;
          this.formToolbar1.Text = "formToolbar1";
          // 
          // DokumentForm
          // 
          this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
          this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
          this.ClientSize = new System.Drawing.Size(738, 379);
          this.Controls.Add(this.stavkaPanel);
          this.Controls.Add(this.dokumentPanel);
          this.Controls.Add(this.formToolbar1);
          this.FocusOnNew = this.vrDokumentaTextBox;
          this.helpProvider.SetHelpKeyword(this, "Firma.htm#Maticni_podaci-Dokument");
          this.helpProvider.SetHelpNavigator(this, System.Windows.Forms.HelpNavigator.Topic);
          this.MainBindingsource = this.dokumentBindingSource;
          this.Name = "DokumentForm";
          this.helpProvider.SetShowHelp(this, true);
          this.Text = "Dokument";
          this.PropertyChanged += new System.ComponentModel.PropertyChangedEventHandler(this.DokumentForm_PropertyChanged);
          ((System.ComponentModel.ISupportInitialize)(this.dokumentBindingSource)).EndInit();
          ((System.ComponentModel.ISupportInitialize)(this.stavkaBindingSource)).EndInit();
          this.dokumentPanel.ResumeLayout(false);
          this.dokumentPanel.PerformLayout();
          ((System.ComponentModel.ISupportInitialize)(this.prethDokumentBindingSource)).EndInit();
          ((System.ComponentModel.ISupportInitialize)(this.partnerInfoBindingSource)).EndInit();
          this.stavkaPanel.ResumeLayout(false);
          ((System.ComponentModel.ISupportInitialize)(this.stavkaDataGridView)).EndInit();
          ((System.ComponentModel.ISupportInitialize)(this.artiklBindingSource)).EndInit();
          ((System.ComponentModel.ISupportInitialize)(this.stavkaErrorProvider)).EndInit();
          ((System.ComponentModel.ISupportInitialize)(this.dokumentErrorProvider)).EndInit();
          this.ResumeLayout(false);
          this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.BindingSource dokumentBindingSource;
      private System.Windows.Forms.BindingSource stavkaBindingSource;
      private System.Windows.Forms.Panel dokumentPanel;
        private System.Windows.Forms.Panel stavkaPanel;
        private System.Windows.Forms.TextBox vrDokumentaTextBox;
        private System.Windows.Forms.TextBox postoPorezTextBox;
        private System.Windows.Forms.TextBox iznosDokumentaTextBox;
        private System.Windows.Forms.ComboBox idPrethDokumentaComboBox;
        private System.Windows.Forms.ComboBox idPartneraComboBox;
        private System.Windows.Forms.DateTimePicker datDokumentaDateTimePicker;
        private System.Windows.Forms.TextBox brDokumentaTextBox;
        private System.Windows.Forms.DataGridView stavkaDataGridView;
        private System.Windows.Forms.BindingSource partnerInfoBindingSource;
        private System.Windows.Forms.BindingSource artiklBindingSource;
        private System.Windows.Forms.ErrorProvider stavkaErrorProvider;
      private System.Windows.Forms.ErrorProvider dokumentErrorProvider;
        private System.Windows.Forms.BindingSource prethDokumentBindingSource;
      private FormToolbar formToolbar1;
      private System.Windows.Forms.DataGridViewComboBoxColumn dataGridViewTextBoxColumn6;
      private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn7;
      private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn3;
      private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn4;
      private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn5;
      private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn1;
      private System.Windows.Forms.TextBox textBox1;
    }
}
namespace UnosArtikala
{
    partial class Artikl
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
          System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Artikl));
          this.listBoxArtikli = new System.Windows.Forms.ListBox();
          this.artiklBindingSource = new System.Windows.Forms.BindingSource(this.components);
          this.dataSetArtikli = new UnosArtikala.DataSetArtikli();
          this.panelArtikl = new System.Windows.Forms.Panel();
          this.textBoxNazArtikla = new System.Windows.Forms.TextBox();
          this.textBoxCijArtikla = new System.Windows.Forms.TextBox();
          this.textBoxJedMjere = new System.Windows.Forms.TextBox();
          this.textBoxSifArtikla = new System.Windows.Forms.TextBox();
          this.checkBoxUsluga = new System.Windows.Forms.CheckBox();
          this.pictureBoxArtikl = new System.Windows.Forms.PictureBox();
          this.labelJedMjere = new System.Windows.Forms.Label();
          this.labelCijArtikla = new System.Windows.Forms.Label();
          this.labelNazArtikla = new System.Windows.Forms.Label();
          this.labelSifArtikla = new System.Windows.Forms.Label();
          this.buttonAdd = new System.Windows.Forms.Button();
          this.buttonUpdate = new System.Windows.Forms.Button();
          this.buttonDelete = new System.Windows.Forms.Button();
          this.labelPosition = new System.Windows.Forms.Label();
          this.buttonFirst = new System.Windows.Forms.Button();
          this.buttonPrev = new System.Windows.Forms.Button();
          this.buttonNext = new System.Windows.Forms.Button();
          this.buttonLast = new System.Windows.Forms.Button();
          this.oleDbConnection1 = new System.Data.OleDb.OleDbConnection();
          this.oleDbSelectCommand1 = new System.Data.OleDb.OleDbCommand();
          this.oleDbInsertCommand1 = new System.Data.OleDb.OleDbCommand();
          this.oleDbUpdateCommand1 = new System.Data.OleDb.OleDbCommand();
          this.oleDbDeleteCommand1 = new System.Data.OleDb.OleDbCommand();
          this.oleDbDataAdapter1 = new System.Data.OleDb.OleDbDataAdapter();
          this.panel2 = new System.Windows.Forms.Panel();
          this.buttonSave = new System.Windows.Forms.Button();
          this.buttonCommand = new System.Windows.Forms.Button();
          this.buttonEdit = new System.Windows.Forms.Button();
          this.buttonFill = new System.Windows.Forms.Button();
          this.labelRowState = new System.Windows.Forms.Label();
          this.buttonCancel = new System.Windows.Forms.Button();
          this.errorProviderArtikl = new System.Windows.Forms.ErrorProvider(this.components);
          this.toolTip = new System.Windows.Forms.ToolTip(this.components);
          ((System.ComponentModel.ISupportInitialize)(this.artiklBindingSource)).BeginInit();
          ((System.ComponentModel.ISupportInitialize)(this.dataSetArtikli)).BeginInit();
          this.panelArtikl.SuspendLayout();
          ((System.ComponentModel.ISupportInitialize)(this.pictureBoxArtikl)).BeginInit();
          this.panel2.SuspendLayout();
          ((System.ComponentModel.ISupportInitialize)(this.errorProviderArtikl)).BeginInit();
          this.SuspendLayout();
          // 
          // listBoxArtikli
          // 
          this.listBoxArtikli.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                      | System.Windows.Forms.AnchorStyles.Left)
                      | System.Windows.Forms.AnchorStyles.Right)));
          this.listBoxArtikli.DataSource = this.artiklBindingSource;
          this.listBoxArtikli.DisplayMember = "NazArtikla";
          this.listBoxArtikli.FormattingEnabled = true;
          this.listBoxArtikli.Location = new System.Drawing.Point(0, 0);
          this.listBoxArtikli.Name = "listBoxArtikli";
          this.listBoxArtikli.Size = new System.Drawing.Size(563, 160);
          this.listBoxArtikli.TabIndex = 0;
          this.listBoxArtikli.SelectedIndexChanged += new System.EventHandler(this.listBoxArtikli_SelectedIndexChanged);
          // 
          // artiklBindingSource
          // 
          this.artiklBindingSource.DataMember = "Artikl";
          this.artiklBindingSource.DataSource = this.dataSetArtikli;
          // 
          // dataSetArtikli
          // 
          this.dataSetArtikli.DataSetName = "DataSetArtikli";
          this.dataSetArtikli.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
          // 
          // panelArtikl
          // 
          this.panelArtikl.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
          this.panelArtikl.Controls.Add(this.textBoxNazArtikla);
          this.panelArtikl.Controls.Add(this.textBoxCijArtikla);
          this.panelArtikl.Controls.Add(this.textBoxJedMjere);
          this.panelArtikl.Controls.Add(this.textBoxSifArtikla);
          this.panelArtikl.Controls.Add(this.checkBoxUsluga);
          this.panelArtikl.Controls.Add(this.pictureBoxArtikl);
          this.panelArtikl.Controls.Add(this.labelJedMjere);
          this.panelArtikl.Controls.Add(this.labelCijArtikla);
          this.panelArtikl.Controls.Add(this.labelNazArtikla);
          this.panelArtikl.Controls.Add(this.labelSifArtikla);
          this.panelArtikl.Location = new System.Drawing.Point(0, 160);
          this.panelArtikl.Name = "panelArtikl";
          this.panelArtikl.Size = new System.Drawing.Size(563, 278);
          this.panelArtikl.TabIndex = 1;
          // 
          // textBoxNazArtikla
          // 
          this.textBoxNazArtikla.Location = new System.Drawing.Point(69, 51);
          this.textBoxNazArtikla.Multiline = true;
          this.textBoxNazArtikla.Name = "textBoxNazArtikla";
          this.textBoxNazArtikla.ScrollBars = System.Windows.Forms.ScrollBars.Horizontal;
          this.textBoxNazArtikla.Size = new System.Drawing.Size(261, 40);
          this.textBoxNazArtikla.TabIndex = 2;
          // 
          // textBoxCijArtikla
          // 
          this.textBoxCijArtikla.Location = new System.Drawing.Point(69, 100);
          this.textBoxCijArtikla.Name = "textBoxCijArtikla";
          this.textBoxCijArtikla.Size = new System.Drawing.Size(119, 20);
          this.textBoxCijArtikla.TabIndex = 3;
          // 
          // textBoxJedMjere
          // 
          this.textBoxJedMjere.Location = new System.Drawing.Point(69, 129);
          this.textBoxJedMjere.Name = "textBoxJedMjere";
          this.textBoxJedMjere.Size = new System.Drawing.Size(119, 20);
          this.textBoxJedMjere.TabIndex = 4;
          // 
          // textBoxSifArtikla
          // 
          this.textBoxSifArtikla.Location = new System.Drawing.Point(69, 22);
          this.textBoxSifArtikla.Name = "textBoxSifArtikla";
          this.textBoxSifArtikla.Size = new System.Drawing.Size(119, 20);
          this.textBoxSifArtikla.TabIndex = 1;
          // 
          // checkBoxUsluga
          // 
          this.checkBoxUsluga.AutoSize = true;
          this.checkBoxUsluga.CheckAlign = System.Drawing.ContentAlignment.MiddleRight;
          this.checkBoxUsluga.Location = new System.Drawing.Point(23, 158);
          this.checkBoxUsluga.Name = "checkBoxUsluga";
          this.checkBoxUsluga.Size = new System.Drawing.Size(59, 17);
          this.checkBoxUsluga.TabIndex = 5;
          this.checkBoxUsluga.Text = "Usluga";
          this.checkBoxUsluga.UseVisualStyleBackColor = true;
          // 
          // pictureBoxArtikl
          // 
          this.pictureBoxArtikl.BackColor = System.Drawing.SystemColors.ControlLight;
          this.pictureBoxArtikl.Location = new System.Drawing.Point(348, 6);
          this.pictureBoxArtikl.Name = "pictureBoxArtikl";
          this.pictureBoxArtikl.Size = new System.Drawing.Size(182, 186);
          this.pictureBoxArtikl.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
          this.pictureBoxArtikl.TabIndex = 4;
          this.pictureBoxArtikl.TabStop = false;
          this.toolTip.SetToolTip(this.pictureBoxArtikl, "Klikni za dodati sliku.");
          this.pictureBoxArtikl.Click += new System.EventHandler(this.pictureBoxArtikl_Click);
          // 
          // labelJedMjere
          // 
          this.labelJedMjere.AutoSize = true;
          this.labelJedMjere.Location = new System.Drawing.Point(23, 129);
          this.labelJedMjere.Name = "labelJedMjere";
          this.labelJedMjere.Size = new System.Drawing.Size(36, 13);
          this.labelJedMjere.TabIndex = 3;
          this.labelJedMjere.Text = "Mjera:";
          // 
          // labelCijArtikla
          // 
          this.labelCijArtikla.AutoSize = true;
          this.labelCijArtikla.Location = new System.Drawing.Point(23, 100);
          this.labelCijArtikla.Name = "labelCijArtikla";
          this.labelCijArtikla.Size = new System.Drawing.Size(39, 13);
          this.labelCijArtikla.TabIndex = 2;
          this.labelCijArtikla.Text = "Cijena:";
          // 
          // labelNazArtikla
          // 
          this.labelNazArtikla.AutoSize = true;
          this.labelNazArtikla.Location = new System.Drawing.Point(23, 51);
          this.labelNazArtikla.Name = "labelNazArtikla";
          this.labelNazArtikla.Size = new System.Drawing.Size(37, 13);
          this.labelNazArtikla.TabIndex = 1;
          this.labelNazArtikla.Text = "Naziv:";
          // 
          // labelSifArtikla
          // 
          this.labelSifArtikla.AutoSize = true;
          this.labelSifArtikla.Location = new System.Drawing.Point(23, 25);
          this.labelSifArtikla.Name = "labelSifArtikla";
          this.labelSifArtikla.Size = new System.Drawing.Size(31, 13);
          this.labelSifArtikla.TabIndex = 0;
          this.labelSifArtikla.Text = "Šifra:";
          // 
          // buttonAdd
          // 
          this.buttonAdd.Location = new System.Drawing.Point(20, 34);
          this.buttonAdd.Name = "buttonAdd";
          this.buttonAdd.Size = new System.Drawing.Size(75, 23);
          this.buttonAdd.TabIndex = 12;
          this.buttonAdd.Text = "Add";
          this.toolTip.SetToolTip(this.buttonAdd, "Dodavanje zapisa.");
          this.buttonAdd.UseVisualStyleBackColor = true;
          this.buttonAdd.Click += new System.EventHandler(this.buttonAdd_Click);
          // 
          // buttonUpdate
          // 
          this.buttonUpdate.Location = new System.Drawing.Point(460, 2);
          this.buttonUpdate.Name = "buttonUpdate";
          this.buttonUpdate.Size = new System.Drawing.Size(75, 23);
          this.buttonUpdate.TabIndex = 11;
          this.buttonUpdate.Text = "Update";
          this.toolTip.SetToolTip(this.buttonUpdate, "Pohrana promjena u bazu.");
          this.buttonUpdate.UseVisualStyleBackColor = true;
          this.buttonUpdate.Click += new System.EventHandler(this.buttonUpdate_Click);
          // 
          // buttonDelete
          // 
          this.buttonDelete.Location = new System.Drawing.Point(178, 34);
          this.buttonDelete.Name = "buttonDelete";
          this.buttonDelete.Size = new System.Drawing.Size(75, 23);
          this.buttonDelete.TabIndex = 14;
          this.buttonDelete.Text = "Delete";
          this.toolTip.SetToolTip(this.buttonDelete, "Brisanje zapisa.");
          this.buttonDelete.UseVisualStyleBackColor = true;
          this.buttonDelete.Click += new System.EventHandler(this.buttonDelete_Click);
          // 
          // labelPosition
          // 
          this.labelPosition.AccessibleDescription = "Displays Record Postion in DataSet";
          this.labelPosition.AccessibleName = "Position Indicator";
          this.labelPosition.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F);
          this.labelPosition.ImeMode = System.Windows.Forms.ImeMode.NoControl;
          this.labelPosition.Location = new System.Drawing.Point(124, 2);
          this.labelPosition.Name = "labelPosition";
          this.labelPosition.Size = new System.Drawing.Size(87, 24);
          this.labelPosition.TabIndex = 29;
          this.labelPosition.Text = "0 od 0";
          this.labelPosition.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
          // 
          // buttonFirst
          // 
          this.buttonFirst.AccessibleName = "Move First";
          this.buttonFirst.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold);
          this.buttonFirst.ImeMode = System.Windows.Forms.ImeMode.NoControl;
          this.buttonFirst.Location = new System.Drawing.Point(22, 0);
          this.buttonFirst.Name = "buttonFirst";
          this.buttonFirst.Size = new System.Drawing.Size(48, 24);
          this.buttonFirst.TabIndex = 6;
          this.buttonFirst.Text = "|<";
          this.toolTip.SetToolTip(this.buttonFirst, "Prvi zapis.");
          this.buttonFirst.Click += new System.EventHandler(this.buttonFirst_Click);
          // 
          // buttonPrev
          // 
          this.buttonPrev.AccessibleName = "Move Previous";
          this.buttonPrev.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold);
          this.buttonPrev.ImeMode = System.Windows.Forms.ImeMode.NoControl;
          this.buttonPrev.Location = new System.Drawing.Point(70, 0);
          this.buttonPrev.Name = "buttonPrev";
          this.buttonPrev.Size = new System.Drawing.Size(48, 24);
          this.buttonPrev.TabIndex = 7;
          this.buttonPrev.Text = "<";
          this.toolTip.SetToolTip(this.buttonPrev, "Prethodni zapis.");
          this.buttonPrev.Click += new System.EventHandler(this.buttonPrevious_Click);
          // 
          // buttonNext
          // 
          this.buttonNext.AccessibleName = "Move Next";
          this.buttonNext.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold);
          this.buttonNext.ImeMode = System.Windows.Forms.ImeMode.NoControl;
          this.buttonNext.Location = new System.Drawing.Point(272, 1);
          this.buttonNext.Name = "buttonNext";
          this.buttonNext.Size = new System.Drawing.Size(48, 24);
          this.buttonNext.TabIndex = 8;
          this.buttonNext.Text = ">";
          this.toolTip.SetToolTip(this.buttonNext, "Sljedeæi zapis.");
          this.buttonNext.Click += new System.EventHandler(this.buttonNext_Click);
          // 
          // buttonLast
          // 
          this.buttonLast.AccessibleName = "Move Last";
          this.buttonLast.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold);
          this.buttonLast.ImeMode = System.Windows.Forms.ImeMode.NoControl;
          this.buttonLast.Location = new System.Drawing.Point(320, 1);
          this.buttonLast.Name = "buttonLast";
          this.buttonLast.Size = new System.Drawing.Size(48, 24);
          this.buttonLast.TabIndex = 9;
          this.buttonLast.Text = ">|";
          this.toolTip.SetToolTip(this.buttonLast, "Posljednji zapis.");
          this.buttonLast.Click += new System.EventHandler(this.buttonLast_Click);
          // 
          // oleDbConnection1
          // 
          this.oleDbConnection1.ConnectionString = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=\"C:/Projects/Firma.mdb\";Persist Secu" +
              "rity Info=True";
          // 
          // oleDbSelectCommand1
          // 
          this.oleDbSelectCommand1.CommandText = "SELECT SifArtikla, NazArtikla, JedMjere, CijArtikla, ZastUsluga, SlikaArtikla FRO" +
              "M Artikl";
          this.oleDbSelectCommand1.Connection = this.oleDbConnection1;
          // 
          // oleDbInsertCommand1
          // 
          this.oleDbInsertCommand1.CommandText = "INSERT INTO `Artikl` (`SifArtikla`, `NazArtikla`, `JedMjere`, `CijArtikla`, `Zast" +
              "Usluga`, `SlikaArtikla`) VALUES (?, ?, ?, ?, ?, ?)";
          this.oleDbInsertCommand1.Connection = this.oleDbConnection1;
          this.oleDbInsertCommand1.Parameters.AddRange(new System.Data.OleDb.OleDbParameter[] {
            new System.Data.OleDb.OleDbParameter("SifArtikla", System.Data.OleDb.OleDbType.Integer, 0, "SifArtikla"),
            new System.Data.OleDb.OleDbParameter("NazArtikla", System.Data.OleDb.OleDbType.VarWChar, 0, "NazArtikla"),
            new System.Data.OleDb.OleDbParameter("JedMjere", System.Data.OleDb.OleDbType.VarWChar, 0, "JedMjere"),
            new System.Data.OleDb.OleDbParameter("CijArtikla", System.Data.OleDb.OleDbType.Numeric, 0, System.Data.ParameterDirection.Input, false, ((byte)(10)), ((byte)(2)), "CijArtikla", System.Data.DataRowVersion.Current, null),
            new System.Data.OleDb.OleDbParameter("ZastUsluga", System.Data.OleDb.OleDbType.Boolean, 0, "ZastUsluga"),
            new System.Data.OleDb.OleDbParameter("SlikaArtikla", System.Data.OleDb.OleDbType.LongVarBinary, 0, "SlikaArtikla")});
          // 
          // oleDbUpdateCommand1
          // 
          this.oleDbUpdateCommand1.CommandText = resources.GetString("oleDbUpdateCommand1.CommandText");
          this.oleDbUpdateCommand1.Connection = this.oleDbConnection1;
          this.oleDbUpdateCommand1.Parameters.AddRange(new System.Data.OleDb.OleDbParameter[] {
            new System.Data.OleDb.OleDbParameter("SifArtikla", System.Data.OleDb.OleDbType.Integer, 0, "SifArtikla"),
            new System.Data.OleDb.OleDbParameter("NazArtikla", System.Data.OleDb.OleDbType.VarWChar, 0, "NazArtikla"),
            new System.Data.OleDb.OleDbParameter("JedMjere", System.Data.OleDb.OleDbType.VarWChar, 0, "JedMjere"),
            new System.Data.OleDb.OleDbParameter("CijArtikla", System.Data.OleDb.OleDbType.Numeric, 0, System.Data.ParameterDirection.Input, false, ((byte)(10)), ((byte)(2)), "CijArtikla", System.Data.DataRowVersion.Current, null),
            new System.Data.OleDb.OleDbParameter("ZastUsluga", System.Data.OleDb.OleDbType.Boolean, 0, "ZastUsluga"),
            new System.Data.OleDb.OleDbParameter("SlikaArtikla", System.Data.OleDb.OleDbType.LongVarBinary, 0, "SlikaArtikla"),
            new System.Data.OleDb.OleDbParameter("Original_SifArtikla", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "SifArtikla", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("IsNull_NazArtikla", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, ((byte)(0)), ((byte)(0)), "NazArtikla", System.Data.DataRowVersion.Original, true, null),
            new System.Data.OleDb.OleDbParameter("Original_NazArtikla", System.Data.OleDb.OleDbType.VarWChar, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "NazArtikla", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("IsNull_JedMjere", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, ((byte)(0)), ((byte)(0)), "JedMjere", System.Data.DataRowVersion.Original, true, null),
            new System.Data.OleDb.OleDbParameter("Original_JedMjere", System.Data.OleDb.OleDbType.VarWChar, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "JedMjere", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("IsNull_CijArtikla", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, ((byte)(0)), ((byte)(0)), "CijArtikla", System.Data.DataRowVersion.Original, true, null),
            new System.Data.OleDb.OleDbParameter("Original_CijArtikla", System.Data.OleDb.OleDbType.Numeric, 0, System.Data.ParameterDirection.Input, false, ((byte)(10)), ((byte)(2)), "CijArtikla", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("IsNull_ZastUsluga", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, ((byte)(0)), ((byte)(0)), "ZastUsluga", System.Data.DataRowVersion.Original, true, null),
            new System.Data.OleDb.OleDbParameter("Original_ZastUsluga", System.Data.OleDb.OleDbType.Boolean, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "ZastUsluga", System.Data.DataRowVersion.Original, null)});
          // 
          // oleDbDeleteCommand1
          // 
          this.oleDbDeleteCommand1.CommandText = resources.GetString("oleDbDeleteCommand1.CommandText");
          this.oleDbDeleteCommand1.Connection = this.oleDbConnection1;
          this.oleDbDeleteCommand1.Parameters.AddRange(new System.Data.OleDb.OleDbParameter[] {
            new System.Data.OleDb.OleDbParameter("Original_SifArtikla", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "SifArtikla", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("IsNull_NazArtikla", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, ((byte)(0)), ((byte)(0)), "NazArtikla", System.Data.DataRowVersion.Original, true, null),
            new System.Data.OleDb.OleDbParameter("Original_NazArtikla", System.Data.OleDb.OleDbType.VarWChar, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "NazArtikla", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("IsNull_JedMjere", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, ((byte)(0)), ((byte)(0)), "JedMjere", System.Data.DataRowVersion.Original, true, null),
            new System.Data.OleDb.OleDbParameter("Original_JedMjere", System.Data.OleDb.OleDbType.VarWChar, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "JedMjere", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("IsNull_CijArtikla", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, ((byte)(0)), ((byte)(0)), "CijArtikla", System.Data.DataRowVersion.Original, true, null),
            new System.Data.OleDb.OleDbParameter("Original_CijArtikla", System.Data.OleDb.OleDbType.Numeric, 0, System.Data.ParameterDirection.Input, false, ((byte)(10)), ((byte)(2)), "CijArtikla", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("IsNull_ZastUsluga", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, ((byte)(0)), ((byte)(0)), "ZastUsluga", System.Data.DataRowVersion.Original, true, null),
            new System.Data.OleDb.OleDbParameter("Original_ZastUsluga", System.Data.OleDb.OleDbType.Boolean, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "ZastUsluga", System.Data.DataRowVersion.Original, null)});
          // 
          // oleDbDataAdapter1
          // 
          this.oleDbDataAdapter1.DeleteCommand = this.oleDbDeleteCommand1;
          this.oleDbDataAdapter1.InsertCommand = this.oleDbInsertCommand1;
          this.oleDbDataAdapter1.SelectCommand = this.oleDbSelectCommand1;
          this.oleDbDataAdapter1.TableMappings.AddRange(new System.Data.Common.DataTableMapping[] {
            new System.Data.Common.DataTableMapping("Table", "Artikl", new System.Data.Common.DataColumnMapping[] {
                        new System.Data.Common.DataColumnMapping("SifArtikla", "SifArtikla"),
                        new System.Data.Common.DataColumnMapping("NazArtikla", "NazArtikla"),
                        new System.Data.Common.DataColumnMapping("JedMjere", "JedMjere"),
                        new System.Data.Common.DataColumnMapping("CijArtikla", "CijArtikla"),
                        new System.Data.Common.DataColumnMapping("ZastUsluga", "ZastUsluga"),
                        new System.Data.Common.DataColumnMapping("SlikaArtikla", "SlikaArtikla")})});
          this.oleDbDataAdapter1.UpdateCommand = this.oleDbUpdateCommand1;
          // 
          // panel2
          // 
          this.panel2.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
          this.panel2.Controls.Add(this.buttonSave);
          this.panel2.Controls.Add(this.buttonCommand);
          this.panel2.Controls.Add(this.buttonEdit);
          this.panel2.Controls.Add(this.buttonFill);
          this.panel2.Controls.Add(this.labelRowState);
          this.panel2.Controls.Add(this.buttonCancel);
          this.panel2.Controls.Add(this.buttonDelete);
          this.panel2.Controls.Add(this.buttonUpdate);
          this.panel2.Controls.Add(this.buttonNext);
          this.panel2.Controls.Add(this.buttonAdd);
          this.panel2.Controls.Add(this.buttonLast);
          this.panel2.Controls.Add(this.labelPosition);
          this.panel2.Controls.Add(this.buttonPrev);
          this.panel2.Controls.Add(this.buttonFirst);
          this.panel2.Location = new System.Drawing.Point(0, 375);
          this.panel2.Name = "panel2";
          this.panel2.Size = new System.Drawing.Size(563, 63);
          this.panel2.TabIndex = 31;
          // 
          // buttonSave
          // 
          this.buttonSave.Location = new System.Drawing.Point(379, 35);
          this.buttonSave.Name = "buttonSave";
          this.buttonSave.Size = new System.Drawing.Size(75, 23);
          this.buttonSave.TabIndex = 16;
          this.buttonSave.Text = "Save";
          this.toolTip.SetToolTip(this.buttonSave, "Pohrana promjena u skup podataka (dataset).");
          this.buttonSave.UseVisualStyleBackColor = true;
          this.buttonSave.Click += new System.EventHandler(this.buttonSave_Click);
          // 
          // buttonCommand
          // 
          this.buttonCommand.Location = new System.Drawing.Point(257, 34);
          this.buttonCommand.Name = "buttonCommand";
          this.buttonCommand.Size = new System.Drawing.Size(75, 23);
          this.buttonCommand.TabIndex = 15;
          this.buttonCommand.Text = "Command";
          this.toolTip.SetToolTip(this.buttonCommand, "Pohrana promjena direktno u bazu. (Update po šifri artikla) ");
          this.buttonCommand.UseVisualStyleBackColor = true;
          this.buttonCommand.Click += new System.EventHandler(this.buttonCommand_Click);
          // 
          // buttonEdit
          // 
          this.buttonEdit.Location = new System.Drawing.Point(99, 34);
          this.buttonEdit.Name = "buttonEdit";
          this.buttonEdit.Size = new System.Drawing.Size(75, 23);
          this.buttonEdit.TabIndex = 13;
          this.buttonEdit.Text = "Edit";
          this.toolTip.SetToolTip(this.buttonEdit, "Editiranje zapisa.");
          this.buttonEdit.UseVisualStyleBackColor = true;
          this.buttonEdit.Click += new System.EventHandler(this.buttonEdit_Click);
          // 
          // buttonFill
          // 
          this.buttonFill.Location = new System.Drawing.Point(379, 1);
          this.buttonFill.Name = "buttonFill";
          this.buttonFill.Size = new System.Drawing.Size(75, 23);
          this.buttonFill.TabIndex = 10;
          this.buttonFill.Text = "Fill (Refresh)";
          this.toolTip.SetToolTip(this.buttonFill, "Ponovno punjenje skupa podataka.");
          this.buttonFill.UseVisualStyleBackColor = true;
          this.buttonFill.Click += new System.EventHandler(this.buttonFill_Click);
          // 
          // labelRowState
          // 
          this.labelRowState.AccessibleDescription = "Displays Record Postion in DataSet";
          this.labelRowState.AccessibleName = "Position Indicator";
          this.labelRowState.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F);
          this.labelRowState.ImeMode = System.Windows.Forms.ImeMode.NoControl;
          this.labelRowState.Location = new System.Drawing.Point(200, 0);
          this.labelRowState.Name = "labelRowState";
          this.labelRowState.Size = new System.Drawing.Size(71, 24);
          this.labelRowState.TabIndex = 31;
          this.labelRowState.Text = "...";
          this.labelRowState.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
          // 
          // buttonCancel
          // 
          this.buttonCancel.Location = new System.Drawing.Point(460, 35);
          this.buttonCancel.Name = "buttonCancel";
          this.buttonCancel.Size = new System.Drawing.Size(75, 23);
          this.buttonCancel.TabIndex = 17;
          this.buttonCancel.Text = "Cancel";
          this.toolTip.SetToolTip(this.buttonCancel, "Odustajanje od trenutnih promjena.");
          this.buttonCancel.UseVisualStyleBackColor = true;
          this.buttonCancel.Click += new System.EventHandler(this.buttonCancel_Click);
          // 
          // errorProviderArtikl
          // 
          this.errorProviderArtikl.ContainerControl = this;
          this.errorProviderArtikl.DataSource = this.artiklBindingSource;
          // 
          // Artikl
          // 
          this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
          this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
          this.ClientSize = new System.Drawing.Size(563, 438);
          this.Controls.Add(this.panel2);
          this.Controls.Add(this.panelArtikl);
          this.Controls.Add(this.listBoxArtikli);
          this.Name = "Artikl";
          this.Text = "Artikli";
          this.Load += new System.EventHandler(this.Form1_Load);
          ((System.ComponentModel.ISupportInitialize)(this.artiklBindingSource)).EndInit();
          ((System.ComponentModel.ISupportInitialize)(this.dataSetArtikli)).EndInit();
          this.panelArtikl.ResumeLayout(false);
          this.panelArtikl.PerformLayout();
          ((System.ComponentModel.ISupportInitialize)(this.pictureBoxArtikl)).EndInit();
          this.panel2.ResumeLayout(false);
          ((System.ComponentModel.ISupportInitialize)(this.errorProviderArtikl)).EndInit();
          this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ListBox listBoxArtikli;
        private System.Windows.Forms.Panel panelArtikl;
        private System.Windows.Forms.Button buttonAdd;
        private System.Windows.Forms.Button buttonUpdate;
        private System.Windows.Forms.Button buttonDelete;
        private System.Windows.Forms.PictureBox pictureBoxArtikl;
        private System.Windows.Forms.Label labelJedMjere;
        private System.Windows.Forms.Label labelCijArtikla;
        private System.Windows.Forms.Label labelNazArtikla;
        private System.Windows.Forms.Label labelSifArtikla;
        private System.Windows.Forms.TextBox textBoxNazArtikla;
        private System.Windows.Forms.TextBox textBoxCijArtikla;
        private System.Windows.Forms.TextBox textBoxJedMjere;
        private System.Windows.Forms.TextBox textBoxSifArtikla;
        private System.Windows.Forms.CheckBox checkBoxUsluga;
        private System.Windows.Forms.Label labelPosition;
        private System.Windows.Forms.Button buttonFirst;
        private System.Windows.Forms.Button buttonPrev;
        private System.Windows.Forms.Button buttonNext;
        private System.Windows.Forms.Button buttonLast;
        private System.Data.OleDb.OleDbConnection oleDbConnection1;
        private System.Data.OleDb.OleDbCommand oleDbSelectCommand1;
        private System.Data.OleDb.OleDbCommand oleDbInsertCommand1;
        private System.Data.OleDb.OleDbCommand oleDbUpdateCommand1;
        private System.Data.OleDb.OleDbCommand oleDbDeleteCommand1;
        private System.Data.OleDb.OleDbDataAdapter oleDbDataAdapter1;
      private DataSetArtikli dataSetArtikli;
      private System.Windows.Forms.Panel panel2;
      private System.Windows.Forms.ErrorProvider errorProviderArtikl;
      private System.Windows.Forms.Button buttonCancel;
      private System.Windows.Forms.Label labelRowState;
      private System.Windows.Forms.Button buttonFill;
      private System.Windows.Forms.BindingSource artiklBindingSource;
      private System.Windows.Forms.Button buttonEdit;
      private System.Windows.Forms.Button buttonCommand;
      private System.Windows.Forms.Button buttonSave;
      private System.Windows.Forms.ToolTip toolTip;
    }
}


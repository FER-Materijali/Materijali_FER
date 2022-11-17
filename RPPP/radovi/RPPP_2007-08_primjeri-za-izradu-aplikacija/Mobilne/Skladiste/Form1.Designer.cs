namespace Skladiste
{
  partial class Form1
  {
    /// <summary>
    /// Required designer variable.
    /// </summary>
    private System.ComponentModel.IContainer components = null;
    private System.Windows.Forms.MainMenu mainMenu1;

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
      this.mainMenu1 = new System.Windows.Forms.MainMenu();
      this.menuItemPrikazi = new System.Windows.Forms.MenuItem();
      this.menuItemNaruci = new System.Windows.Forms.MenuItem();
      this.dataGrid1 = new System.Windows.Forms.DataGrid();
      this.textBoxKolicina = new System.Windows.Forms.TextBox();
      this.labelKolicina = new System.Windows.Forms.Label();
      this.panel1 = new System.Windows.Forms.Panel();
      this.labelNazivArtikla = new System.Windows.Forms.Label();
      this.dateTimePickerOd = new System.Windows.Forms.DateTimePicker();
      this.dateTimePickerDo = new System.Windows.Forms.DateTimePicker();
      this.label1 = new System.Windows.Forms.Label();
      this.label2 = new System.Windows.Forms.Label();
      this.panel1.SuspendLayout();
      this.SuspendLayout();
      // 
      // mainMenu1
      // 
      this.mainMenu1.MenuItems.Add(this.menuItemPrikazi);
      this.mainMenu1.MenuItems.Add(this.menuItemNaruci);
      // 
      // menuItemPrikazi
      // 
      this.menuItemPrikazi.Text = "Prikaži";
      this.menuItemPrikazi.Click += new System.EventHandler(this.menuItemPrikazi_Click);
      // 
      // menuItemNaruci
      // 
      this.menuItemNaruci.Enabled = false;
      this.menuItemNaruci.Text = "Naruèi";
      this.menuItemNaruci.Click += new System.EventHandler(this.menuItemNaruci_Click);
      // 
      // dataGrid1
      // 
      this.dataGrid1.BackgroundColor = System.Drawing.Color.FromArgb(((int)(((byte)(128)))), ((int)(((byte)(128)))), ((int)(((byte)(128)))));
      this.dataGrid1.Location = new System.Drawing.Point(0, 35);
      this.dataGrid1.Name = "dataGrid1";
      this.dataGrid1.Size = new System.Drawing.Size(240, 162);
      this.dataGrid1.TabIndex = 0;
      this.dataGrid1.CurrentCellChanged += new System.EventHandler(this.dataGrid1_CurrentCellChanged);
      // 
      // textBoxKolicina
      // 
      this.textBoxKolicina.Location = new System.Drawing.Point(131, 36);
      this.textBoxKolicina.Name = "textBoxKolicina";
      this.textBoxKolicina.Size = new System.Drawing.Size(100, 21);
      this.textBoxKolicina.TabIndex = 4;
      this.textBoxKolicina.Text = "0";
      this.textBoxKolicina.LostFocus += new System.EventHandler(this.textBoxKolicina_LostFocus);
      // 
      // labelKolicina
      // 
      this.labelKolicina.Location = new System.Drawing.Point(3, 36);
      this.labelKolicina.Name = "labelKolicina";
      this.labelKolicina.Size = new System.Drawing.Size(122, 20);
      this.labelKolicina.Text = "Kolièina za naruèiti:";
      // 
      // panel1
      // 
      this.panel1.Controls.Add(this.labelNazivArtikla);
      this.panel1.Controls.Add(this.labelKolicina);
      this.panel1.Controls.Add(this.textBoxKolicina);
      this.panel1.Enabled = false;
      this.panel1.Location = new System.Drawing.Point(0, 203);
      this.panel1.Name = "panel1";
      this.panel1.Size = new System.Drawing.Size(237, 62);
      // 
      // labelNazivArtikla
      // 
      this.labelNazivArtikla.Font = new System.Drawing.Font("Tahoma", 8F, System.Drawing.FontStyle.Regular);
      this.labelNazivArtikla.Location = new System.Drawing.Point(3, 0);
      this.labelNazivArtikla.Name = "labelNazivArtikla";
      this.labelNazivArtikla.Size = new System.Drawing.Size(231, 36);
      // 
      // dateTimePickerOd
      // 
      this.dateTimePickerOd.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
      this.dateTimePickerOd.Location = new System.Drawing.Point(30, 7);
      this.dateTimePickerOd.Name = "dateTimePickerOd";
      this.dateTimePickerOd.Size = new System.Drawing.Size(79, 22);
      this.dateTimePickerOd.TabIndex = 1;
      // 
      // dateTimePickerDo
      // 
      this.dateTimePickerDo.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
      this.dateTimePickerDo.Location = new System.Drawing.Point(150, 7);
      this.dateTimePickerDo.Name = "dateTimePickerDo";
      this.dateTimePickerDo.Size = new System.Drawing.Size(79, 22);
      this.dateTimePickerDo.TabIndex = 2;
      // 
      // label1
      // 
      this.label1.Location = new System.Drawing.Point(0, 9);
      this.label1.Name = "label1";
      this.label1.Size = new System.Drawing.Size(30, 20);
      this.label1.Text = "Od:";
      // 
      // label2
      // 
      this.label2.Location = new System.Drawing.Point(115, 9);
      this.label2.Name = "label2";
      this.label2.Size = new System.Drawing.Size(29, 20);
      this.label2.Text = "Do:";
      // 
      // Form1
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(96F, 96F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Dpi;
      this.AutoScroll = true;
      this.ClientSize = new System.Drawing.Size(240, 268);
      this.Controls.Add(this.label2);
      this.Controls.Add(this.label1);
      this.Controls.Add(this.dateTimePickerDo);
      this.Controls.Add(this.dateTimePickerOd);
      this.Controls.Add(this.panel1);
      this.Controls.Add(this.dataGrid1);
      this.Menu = this.mainMenu1;
      this.Name = "Form1";
      this.Text = "Skladište";
      this.panel1.ResumeLayout(false);
      this.ResumeLayout(false);

    }

    #endregion

    private System.Windows.Forms.DataGrid dataGrid1;
    private System.Windows.Forms.MenuItem menuItemNaruci;
    private System.Windows.Forms.TextBox textBoxKolicina;
    private System.Windows.Forms.Label labelKolicina;
    private System.Windows.Forms.Panel panel1;
    private System.Windows.Forms.Label labelNazivArtikla;
    private System.Windows.Forms.DateTimePicker dateTimePickerOd;
    private System.Windows.Forms.DateTimePicker dateTimePickerDo;
    private System.Windows.Forms.Label label1;
    private System.Windows.Forms.Label label2;
    private System.Windows.Forms.MenuItem menuItemPrikazi;
  }
}


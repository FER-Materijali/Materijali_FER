namespace AppointmentList
{
  partial class EvidencijaPoslova
  {
    /// <summary>
    /// Required designer variable.
    /// </summary>
    private System.ComponentModel.IContainer components = null;

    private System.Windows.Forms.Label DatumLabel;
    private System.Windows.Forms.Label DanLabel;
    private System.Windows.Forms.Label nazivLabel;
    private System.Windows.Forms.Label TimeLabel;
    private System.Windows.Forms.Label posaoValueDisplayLabel;
    private System.Windows.Forms.Label nazivToScheduleLabel;
    private System.Windows.Forms.Label posaoSetLabel;
    private System.Windows.Forms.Label ScheduledLabel;
    private System.Windows.Forms.Label posaoDisplayLabel;
    private System.Windows.Forms.ComboBox posaoComboBox;
    private System.Windows.Forms.ComboBox vrijemeComboBox;
    private System.Windows.Forms.MainMenu mainMenu1;
    private System.Windows.Forms.ListBox rasporedListBox;
    private System.Windows.Forms.TextBox nazivRasporedTextBox;
    private System.Windows.Forms.TextBox nazivTextBox;
    private System.Windows.Forms.Button SaveToSqlCEButton;
    private System.Windows.Forms.Button SaveToXMLButton;

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
      this.DatumLabel = new System.Windows.Forms.Label();
      this.DanLabel = new System.Windows.Forms.Label();
      this.rasporedListBox = new System.Windows.Forms.ListBox();
      this.SaveToSqlCEButton = new System.Windows.Forms.Button();
      this.SaveToXMLButton = new System.Windows.Forms.Button();
      this.nazivLabel = new System.Windows.Forms.Label();
      this.nazivTextBox = new System.Windows.Forms.TextBox();
      this.posaoSetLabel = new System.Windows.Forms.Label();
      this.posaoComboBox = new System.Windows.Forms.ComboBox();
      this.TimeLabel = new System.Windows.Forms.Label();
      this.ScheduledLabel = new System.Windows.Forms.Label();
      this.vrijemeComboBox = new System.Windows.Forms.ComboBox();
      this.posaoValueDisplayLabel = new System.Windows.Forms.Label();
      this.posaoDisplayLabel = new System.Windows.Forms.Label();
      this.nazivToScheduleLabel = new System.Windows.Forms.Label();
      this.nazivRasporedTextBox = new System.Windows.Forms.TextBox();
      this.SuspendLayout();
      // 
      // DatumLabel
      // 
      this.DatumLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold);
      this.DatumLabel.Location = new System.Drawing.Point(0, 0);
      this.DatumLabel.Name = "DatumLabel";
      this.DatumLabel.Size = new System.Drawing.Size(120, 16);
      this.DatumLabel.Text = "Datum";
      // 
      // DanLabel
      // 
      this.DanLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold);
      this.DanLabel.Location = new System.Drawing.Point(136, 0);
      this.DanLabel.Name = "DanLabel";
      this.DanLabel.Size = new System.Drawing.Size(104, 16);
      this.DanLabel.Text = "Dan";
      this.DanLabel.TextAlign = System.Drawing.ContentAlignment.TopRight;
      // 
      // rasporedListBox
      // 
      this.rasporedListBox.Location = new System.Drawing.Point(8, 136);
      this.rasporedListBox.Name = "rasporedListBox";
      this.rasporedListBox.Size = new System.Drawing.Size(72, 114);
      this.rasporedListBox.TabIndex = 10;
      // 
      // SaveToSqlCEButton
      // 
      this.SaveToSqlCEButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 7F, System.Drawing.FontStyle.Bold);
      this.SaveToSqlCEButton.Location = new System.Drawing.Point(48, 80);
      this.SaveToSqlCEButton.Name = "SaveToSqlCEButton";
      this.SaveToSqlCEButton.Size = new System.Drawing.Size(80, 24);
      this.SaveToSqlCEButton.TabIndex = 7;
      this.SaveToSqlCEButton.Text = "Spremi u sqlCE";
      this.SaveToSqlCEButton.Click += new System.EventHandler(this.SaveToSqlCEButton_Click);
      // 
      // SaveToXMLButton
      // 
      this.SaveToXMLButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 7F, System.Drawing.FontStyle.Bold);
      this.SaveToXMLButton.Location = new System.Drawing.Point(136, 80);
      this.SaveToXMLButton.Name = "SaveToXMLButton";
      this.SaveToXMLButton.Size = new System.Drawing.Size(96, 24);
      this.SaveToXMLButton.TabIndex = 6;
      this.SaveToXMLButton.Text = "Spremi u XML";
      this.SaveToXMLButton.Click += new System.EventHandler(this.SaveToXMLButton_Click);
      // 
      // nazivLabel
      // 
      this.nazivLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold);
      this.nazivLabel.Location = new System.Drawing.Point(8, 24);
      this.nazivLabel.Name = "nazivLabel";
      this.nazivLabel.Size = new System.Drawing.Size(40, 16);
      this.nazivLabel.Text = "Naziv:";
      // 
      // nazivTextBox
      // 
      this.nazivTextBox.Location = new System.Drawing.Point(48, 24);
      this.nazivTextBox.Name = "nazivTextBox";
      this.nazivTextBox.Size = new System.Drawing.Size(184, 21);
      this.nazivTextBox.TabIndex = 4;
      // 
      // posaoSetLabel
      // 
      this.posaoSetLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold);
      this.posaoSetLabel.Location = new System.Drawing.Point(8, 48);
      this.posaoSetLabel.Name = "posaoSetLabel";
      this.posaoSetLabel.Size = new System.Drawing.Size(48, 22);
      this.posaoSetLabel.Text = "Posao:";
      // 
      // posaoComboBox
      // 
      this.posaoComboBox.Items.Add("Predavanje");
      this.posaoComboBox.Items.Add("Sastanak");
      this.posaoComboBox.Items.Add("Ispit");
      this.posaoComboBox.Items.Add("Ruèak");
      this.posaoComboBox.Location = new System.Drawing.Point(48, 48);
      this.posaoComboBox.Name = "posaoComboBox";
      this.posaoComboBox.Size = new System.Drawing.Size(72, 22);
      this.posaoComboBox.TabIndex = 2;
      // 
      // TimeLabel
      // 
      this.TimeLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold);
      this.TimeLabel.Location = new System.Drawing.Point(126, 48);
      this.TimeLabel.Name = "TimeLabel";
      this.TimeLabel.Size = new System.Drawing.Size(51, 16);
      this.TimeLabel.Text = "Vrijeme:";
      // 
      // ScheduledLabel
      // 
      this.ScheduledLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold);
      this.ScheduledLabel.Location = new System.Drawing.Point(8, 120);
      this.ScheduledLabel.Name = "ScheduledLabel";
      this.ScheduledLabel.Size = new System.Drawing.Size(64, 16);
      this.ScheduledLabel.Text = "Raspored:";
      // 
      // vrijemeComboBox
      // 
      this.vrijemeComboBox.Location = new System.Drawing.Point(172, 48);
      this.vrijemeComboBox.Name = "vrijemeComboBox";
      this.vrijemeComboBox.Size = new System.Drawing.Size(60, 22);
      this.vrijemeComboBox.TabIndex = 0;
      // 
      // posaoValueDisplayLabel
      // 
      this.posaoValueDisplayLabel.Location = new System.Drawing.Point(96, 184);
      this.posaoValueDisplayLabel.Name = "posaoValueDisplayLabel";
      this.posaoValueDisplayLabel.Size = new System.Drawing.Size(106, 16);
      this.posaoValueDisplayLabel.Text = "Tip";
      // 
      // posaoDisplayLabel
      // 
      this.posaoDisplayLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold);
      this.posaoDisplayLabel.Location = new System.Drawing.Point(96, 168);
      this.posaoDisplayLabel.Name = "posaoDisplayLabel";
      this.posaoDisplayLabel.Size = new System.Drawing.Size(52, 16);
      this.posaoDisplayLabel.Text = "Posao:";
      // 
      // nazivToScheduleLabel
      // 
      this.nazivToScheduleLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold);
      this.nazivToScheduleLabel.Location = new System.Drawing.Point(96, 120);
      this.nazivToScheduleLabel.Name = "nazivToScheduleLabel";
      this.nazivToScheduleLabel.Size = new System.Drawing.Size(40, 16);
      this.nazivToScheduleLabel.Text = "Naziv:";
      // 
      // nazivRasporedTextBox
      // 
      this.nazivRasporedTextBox.Location = new System.Drawing.Point(96, 136);
      this.nazivRasporedTextBox.Name = "nazivRasporedTextBox";
      this.nazivRasporedTextBox.ReadOnly = true;
      this.nazivRasporedTextBox.Size = new System.Drawing.Size(136, 21);
      this.nazivRasporedTextBox.TabIndex = 12;
      // 
      // EvidencijaPoslova
      // 
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Inherit;
      this.BackColor = System.Drawing.Color.Lavender;
      this.ClientSize = new System.Drawing.Size(240, 268);
      this.Controls.Add(this.vrijemeComboBox);
      this.Controls.Add(this.TimeLabel);
      this.Controls.Add(this.posaoComboBox);
      this.Controls.Add(this.posaoSetLabel);
      this.Controls.Add(this.nazivTextBox);
      this.Controls.Add(this.nazivLabel);
      this.Controls.Add(this.SaveToXMLButton);
      this.Controls.Add(this.SaveToSqlCEButton);
      this.Controls.Add(this.DanLabel);
      this.Controls.Add(this.DatumLabel);
      this.Controls.Add(this.rasporedListBox);
      this.Controls.Add(this.ScheduledLabel);
      this.Controls.Add(this.nazivRasporedTextBox);
      this.Controls.Add(this.nazivToScheduleLabel);
      this.Controls.Add(this.posaoDisplayLabel);
      this.Controls.Add(this.posaoValueDisplayLabel);
      this.Menu = this.mainMenu1;
      this.Name = "EvidencijaPoslova";
      this.Text = "Evidencija poslova";
      this.Load += new System.EventHandler(this.AppointmentList_Load);
      this.ResumeLayout(false);

    }

    #endregion
  }
}


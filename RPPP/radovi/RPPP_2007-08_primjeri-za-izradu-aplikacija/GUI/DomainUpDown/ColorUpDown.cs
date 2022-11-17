using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;

namespace ColorUpDown
{
  /// <summary>
  /// Summary description for Form1.
  /// </summary>
  public class MainForm : System.Windows.Forms.Form
  {
    private System.Windows.Forms.DomainUpDown knownColorUpDown;
    private System.Windows.Forms.NumericUpDown opacityUpDown;
    private System.Windows.Forms.Label label1;
    private System.Windows.Forms.Label label2;
    /// <summary>
    /// Required designer variable.
    /// </summary>
    private System.ComponentModel.Container components = null;

    public MainForm()
    {
      //
      // Required for Windows Form Designer support
      //
      InitializeComponent();
      string [] colorNames = Enum.GetNames(typeof(KnownColor));
      knownColorUpDown.Items.AddRange(colorNames);
      knownColorUpDown.SelectedIndex = 0;

      //
      // TODO: Add any constructor code after InitializeComponent call
      //
    }

    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    protected override void Dispose( bool disposing )
    {
      if( disposing )
      {
        if (components != null) 
        {
          components.Dispose();
        }
      }
      base.Dispose( disposing );
    }

    #region Windows Form Designer generated code
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    private void InitializeComponent()
    {
      this.knownColorUpDown = new System.Windows.Forms.DomainUpDown();
      this.opacityUpDown = new System.Windows.Forms.NumericUpDown();
      this.label1 = new System.Windows.Forms.Label();
      this.label2 = new System.Windows.Forms.Label();
      ((System.ComponentModel.ISupportInitialize)(this.opacityUpDown)).BeginInit();
      this.SuspendLayout();
      // 
      // knownColorUpDown
      // 
      this.knownColorUpDown.Items.Add("Zelena");
      this.knownColorUpDown.Items.Add("Plava");
      this.knownColorUpDown.Items.Add("Crvena");
      this.knownColorUpDown.Location = new System.Drawing.Point(112, 56);
      this.knownColorUpDown.Name = "knownColorUpDown";
      this.knownColorUpDown.Size = new System.Drawing.Size(152, 20);
      this.knownColorUpDown.TabIndex = 0;
      this.knownColorUpDown.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
      this.knownColorUpDown.UpDownAlign = System.Windows.Forms.LeftRightAlignment.Left;
      this.knownColorUpDown.SelectedItemChanged += new System.EventHandler(this.knownColorUpDown_SelectedItemChanged);
      // 
      // opacityUpDown
      // 
      this.opacityUpDown.DecimalPlaces = 2;
      this.opacityUpDown.Increment = new System.Decimal(new int[] {
                                                                    10,
                                                                    0,
                                                                    0,
                                                                    131072});
      this.opacityUpDown.Location = new System.Drawing.Point(112, 96);
      this.opacityUpDown.Maximum = new System.Decimal(new int[] {
                                                                  1,
                                                                  0,
                                                                  0,
                                                                  0});
      this.opacityUpDown.Name = "opacityUpDown";
      this.opacityUpDown.Size = new System.Drawing.Size(152, 20);
      this.opacityUpDown.TabIndex = 1;
      this.opacityUpDown.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
      this.opacityUpDown.ThousandsSeparator = true;
      this.opacityUpDown.Value = new System.Decimal(new int[] {
                                                                1,
                                                                0,
                                                                0,
                                                                0});
      this.opacityUpDown.ValueChanged += new System.EventHandler(this.opacityUpDown_ValueChanged);
      // 
      // label1
      // 
      this.label1.Location = new System.Drawing.Point(48, 56);
      this.label1.Name = "label1";
      this.label1.Size = new System.Drawing.Size(56, 16);
      this.label1.TabIndex = 2;
      this.label1.Text = "Color";
      this.label1.Click += new System.EventHandler(this.label1_Click);
      // 
      // label2
      // 
      this.label2.Location = new System.Drawing.Point(48, 96);
      this.label2.Name = "label2";
      this.label2.Size = new System.Drawing.Size(56, 16);
      this.label2.TabIndex = 3;
      this.label2.Text = "Opacity";
      // 
      // MainForm
      // 
      this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
      this.ClientSize = new System.Drawing.Size(376, 150);
      this.Controls.Add(this.label2);
      this.Controls.Add(this.label1);
      this.Controls.Add(this.opacityUpDown);
      this.Controls.Add(this.knownColorUpDown);
      this.Name = "MainForm";
      this.Text = "ColorUpDown Example";
      ((System.ComponentModel.ISupportInitialize)(this.opacityUpDown)).EndInit();
      this.ResumeLayout(false);

    }
    #endregion

    /// <summary>
    /// The main entry point for the application.
    /// </summary>
    [STAThread]
    static void Main() 
    {
      Application.Run(new MainForm());
    }

    private void knownColorUpDown_SelectedItemChanged(object sender, System.EventArgs e)
    {
      string currentColorName = (string)knownColorUpDown.SelectedItem;
      try
      {
        this.BackColor = Color.FromName(currentColorName);
      }
      catch(ArgumentException exception)
      {
        //MessageBox.Show(exception.Message);
      }
    }

    private void opacityUpDown_ValueChanged(object sender, System.EventArgs e) 
    {
      this.Opacity = (double) opacityUpDown.Value;
    }

    private void label1_Click(object sender, System.EventArgs e) 
    {
      
    }
  }
}

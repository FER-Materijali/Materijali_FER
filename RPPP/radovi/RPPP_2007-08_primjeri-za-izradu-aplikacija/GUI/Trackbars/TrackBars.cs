using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;
using System.Diagnostics;

namespace Bars
{
  /// <summary>
  /// Summary description for Form1.
  /// </summary>
  public class Form1 : System.Windows.Forms.Form
  {
    private System.Windows.Forms.TrackBar trackR;
    private System.Windows.Forms.TrackBar trackG;
    private System.Windows.Forms.TrackBar trackB;
    private System.Windows.Forms.Label label1;
    /// <summary>
    /// Required designer variable.
    /// </summary>
    private System.ComponentModel.Container components = null;

    public Form1()
    {
      //
      // Required for Windows Form Designer support
      //
      InitializeComponent();

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
      this.trackR = new System.Windows.Forms.TrackBar();
      this.trackG = new System.Windows.Forms.TrackBar();
      this.trackB = new System.Windows.Forms.TrackBar();
      this.label1 = new System.Windows.Forms.Label();
      ((System.ComponentModel.ISupportInitialize)(this.trackR)).BeginInit();
      ((System.ComponentModel.ISupportInitialize)(this.trackG)).BeginInit();
      ((System.ComponentModel.ISupportInitialize)(this.trackB)).BeginInit();
      this.SuspendLayout();
      // 
      // trackR
      // 
      this.trackR.BackColor = System.Drawing.Color.Red;
      this.trackR.Dock = System.Windows.Forms.DockStyle.Top;
      this.trackR.Location = new System.Drawing.Point(0, 0);
      this.trackR.Maximum = 255;
      this.trackR.Name = "trackR";
      this.trackR.Size = new System.Drawing.Size(292, 50);
      this.trackR.TabIndex = 0;
      this.trackR.TickFrequency = 20;
      this.trackR.TickStyle = System.Windows.Forms.TickStyle.TopLeft;
      this.trackR.ValueChanged += new System.EventHandler(this.TrackBarOnValueChanged);
      this.trackR.Scroll += new System.EventHandler(this.trackR_Scroll);
      // 
      // trackG
      // 
      this.trackG.BackColor = System.Drawing.Color.Green;
      this.trackG.Dock = System.Windows.Forms.DockStyle.Top;
      this.trackG.Location = new System.Drawing.Point(0, 50);
      this.trackG.Maximum = 255;
      this.trackG.Name = "trackG";
      this.trackG.Size = new System.Drawing.Size(292, 50);
      this.trackG.TabIndex = 1;
      this.trackG.TickFrequency = 10;
      this.trackG.ValueChanged += new System.EventHandler(this.TrackBarOnValueChanged);
      // 
      // trackB
      // 
      this.trackB.BackColor = System.Drawing.Color.Blue;
      this.trackB.Dock = System.Windows.Forms.DockStyle.Top;
      this.trackB.Location = new System.Drawing.Point(0, 100);
      this.trackB.Maximum = 255;
      this.trackB.Name = "trackB";
      this.trackB.Size = new System.Drawing.Size(292, 50);
      this.trackB.TabIndex = 2;
      this.trackB.TickFrequency = 5;
      this.trackB.TickStyle = System.Windows.Forms.TickStyle.Both;
      this.trackB.ValueChanged += new System.EventHandler(this.TrackBarOnValueChanged);
      this.trackB.Scroll += new System.EventHandler(this.trackB_Scroll);
      // 
      // label1
      // 
      this.label1.Dock = System.Windows.Forms.DockStyle.Bottom;
      this.label1.Location = new System.Drawing.Point(0, 222);
      this.label1.Name = "label1";
      this.label1.Size = new System.Drawing.Size(292, 40);
      this.label1.TabIndex = 3;
      this.label1.Text = "label1";
      // 
      // Form1
      // 
      this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
      this.ClientSize = new System.Drawing.Size(292, 262);
      this.Controls.Add(this.label1);
      this.Controls.Add(this.trackB);
      this.Controls.Add(this.trackG);
      this.Controls.Add(this.trackR);
      this.Name = "Form1";
      this.Text = "Form1";
      this.Load += new System.EventHandler(this.Form1_Load);
      ((System.ComponentModel.ISupportInitialize)(this.trackR)).EndInit();
      ((System.ComponentModel.ISupportInitialize)(this.trackG)).EndInit();
      ((System.ComponentModel.ISupportInitialize)(this.trackB)).EndInit();
      this.ResumeLayout(false);

    }
    #endregion

    /// <summary>
    /// The main entry point for the application.
    /// </summary>
    [STAThread]
    static void Main() 
    {
      Application.Run(new Form1());
    }

    private void Form1_Load(object sender, System.EventArgs e) 
    {
      Color color = BackColor;
      trackR.Value = color.R; // Generates ValueChanged event.
      trackG.Value = color.G;
      trackB.Value = color.B;
    }

    void TrackBarOnValueChanged(object obj, EventArgs ea) 
    {
      this.BackColor = Color.FromArgb(
        trackR.Value, 
        trackG.Value,
        trackB.Value);
      label1.Text = this.BackColor.ToString();
    }

    private void trackB_Scroll(object sender, System.EventArgs e) 
    {
    
    }

    private void trackR_Scroll(object sender, System.EventArgs e) 
    {
    
    }
  }
}

namespace RacunanjePI
{
  partial class Form1
  {
    /// <summary>
    /// Required designer variable.
    /// </summary>

    private System.Windows.Forms.Panel panel1;
    private System.Windows.Forms.Label label1;
    private System.Windows.Forms.Button buttonCalc;
    private System.Windows.Forms.NumericUpDown digitsUpDown;
    private System.Windows.Forms.TextBox piTextBox;
    private System.Windows.Forms.ProgressBar piProgressBar;
    
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
      this.panel1 = new System.Windows.Forms.Panel();
      this.buttonStop = new System.Windows.Forms.Button();
      this.buttonCalc = new System.Windows.Forms.Button();
      this.digitsUpDown = new System.Windows.Forms.NumericUpDown();
      this.label1 = new System.Windows.Forms.Label();
      this.piTextBox = new System.Windows.Forms.TextBox();
      this.piProgressBar = new System.Windows.Forms.ProgressBar();
      this.panel1.SuspendLayout();
      ((System.ComponentModel.ISupportInitialize)(this.digitsUpDown)).BeginInit();
      this.SuspendLayout();
      // 
      // panel1
      // 
      this.panel1.Controls.Add(this.buttonStop);
      this.panel1.Controls.Add(this.buttonCalc);
      this.panel1.Controls.Add(this.digitsUpDown);
      this.panel1.Controls.Add(this.label1);
      this.panel1.Dock = System.Windows.Forms.DockStyle.Top;
      this.panel1.Location = new System.Drawing.Point(0, 0);
      this.panel1.Name = "panel1";
      this.panel1.Size = new System.Drawing.Size(324, 40);
      this.panel1.TabIndex = 0;
      // 
      // buttonStop
      // 
      this.buttonStop.Location = new System.Drawing.Point(237, 8);
      this.buttonStop.Name = "buttonStop";
      this.buttonStop.Size = new System.Drawing.Size(75, 23);
      this.buttonStop.TabIndex = 3;
      this.buttonStop.Text = "Stop";
      this.buttonStop.Click += new System.EventHandler(this.buttonStop_Click);
      // 
      // buttonCalc
      // 
      this.buttonCalc.Location = new System.Drawing.Point(159, 8);
      this.buttonCalc.Name = "buttonCalc";
      this.buttonCalc.Size = new System.Drawing.Size(75, 23);
      this.buttonCalc.TabIndex = 2;
      this.buttonCalc.Text = "Calc";
      this.buttonCalc.Click += new System.EventHandler(this.buttonCalc_Click);
      // 
      // digitsUpDown
      // 
      this.digitsUpDown.Location = new System.Drawing.Point(82, 11);
      this.digitsUpDown.Maximum = new decimal(new int[] {
            10000,
            0,
            0,
            0});
      this.digitsUpDown.Name = "digitsUpDown";
      this.digitsUpDown.Size = new System.Drawing.Size(56, 20);
      this.digitsUpDown.TabIndex = 1;
      // 
      // label1
      // 
      this.label1.Location = new System.Drawing.Point(10, 13);
      this.label1.Name = "label1";
      this.label1.Size = new System.Drawing.Size(64, 23);
      this.label1.TabIndex = 0;
      this.label1.Text = "Digits of Pi";
      // 
      // piTextBox
      // 
      this.piTextBox.Dock = System.Windows.Forms.DockStyle.Fill;
      this.piTextBox.Location = new System.Drawing.Point(0, 40);
      this.piTextBox.Multiline = true;
      this.piTextBox.Name = "piTextBox";
      this.piTextBox.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
      this.piTextBox.Size = new System.Drawing.Size(324, 177);
      this.piTextBox.TabIndex = 1;
      this.piTextBox.Text = "3";
      // 
      // piProgressBar
      // 
      this.piProgressBar.Dock = System.Windows.Forms.DockStyle.Bottom;
      this.piProgressBar.Location = new System.Drawing.Point(0, 217);
      this.piProgressBar.Maximum = 1;
      this.piProgressBar.Name = "piProgressBar";
      this.piProgressBar.Size = new System.Drawing.Size(324, 23);
      this.piProgressBar.TabIndex = 2;
      // 
      // Form1
      // 
      this.AcceptButton = this.buttonCalc;
      this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
      this.ClientSize = new System.Drawing.Size(324, 240);
      this.Controls.Add(this.piTextBox);
      this.Controls.Add(this.panel1);
      this.Controls.Add(this.piProgressBar);
      this.Name = "Form1";
      this.Text = "Digits of Pi";
      this.panel1.ResumeLayout(false);
      ((System.ComponentModel.ISupportInitialize)(this.digitsUpDown)).EndInit();
      this.ResumeLayout(false);
      this.PerformLayout();

    }
    #endregion

    private System.Windows.Forms.Button buttonStop;
  }
}


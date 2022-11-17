namespace Zastave
{
  partial class Form1
  {

    // GroupBox with PictureBox inside to display a flag
    private System.Windows.Forms.GroupBox fraFlagGroupBox;
    private System.Windows.Forms.PictureBox picFlag;

    // Label and ComboBox to choose a country name
    private System.Windows.Forms.Label lblChoose;
    private System.Windows.Forms.ComboBox cboOptions;

    // Label to display result
    private System.Windows.Forms.Label lblFeedback;

    // Buttons to submit an answer and move to the next flag
    private System.Windows.Forms.Button btnSubmit;
    private System.Windows.Forms.Button btnNext;


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
      this.lblChoose = new System.Windows.Forms.Label();
      this.lblFeedback = new System.Windows.Forms.Label();
      this.btnSubmit = new System.Windows.Forms.Button();
      this.btnNext = new System.Windows.Forms.Button();
      this.fraFlagGroupBox = new System.Windows.Forms.GroupBox();
      this.picFlag = new System.Windows.Forms.PictureBox();
      this.cboOptions = new System.Windows.Forms.ComboBox();
      this.fraFlagGroupBox.SuspendLayout();
      this.SuspendLayout();
      // 
      // lblChoose
      // 
      this.lblChoose.Location = new System.Drawing.Point(136, 8);
      this.lblChoose.Name = "lblChoose";
      this.lblChoose.Size = new System.Drawing.Size(88, 21);
      this.lblChoose.TabIndex = 0;
      this.lblChoose.Text = "Select country:";
      this.lblChoose.TextAlign = System.Drawing.ContentAlignment.TopCenter;
      // 
      // lblFeedback
      // 
      this.lblFeedback.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
      this.lblFeedback.Font = new System.Drawing.Font("Tahoma", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((System.Byte)(0)));
      this.lblFeedback.Location = new System.Drawing.Point(136, 64);
      this.lblFeedback.Name = "lblFeedback";
      this.lblFeedback.Size = new System.Drawing.Size(120, 32);
      this.lblFeedback.TabIndex = 1;
      this.lblFeedback.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
      // 
      // btnSubmit
      // 
      this.btnSubmit.Location = new System.Drawing.Point(272, 8);
      this.btnSubmit.Name = "btnSubmit";
      this.btnSubmit.Size = new System.Drawing.Size(88, 32);
      this.btnSubmit.TabIndex = 2;
      this.btnSubmit.Text = "Submit";
      this.btnSubmit.Click += new System.EventHandler(this.btnSubmit_Click);
      // 
      // btnNext
      // 
      this.btnNext.Enabled = false;
      this.btnNext.Location = new System.Drawing.Point(272, 48);
      this.btnNext.Name = "btnNext";
      this.btnNext.Size = new System.Drawing.Size(88, 32);
      this.btnNext.TabIndex = 3;
      this.btnNext.Text = "Next Flag";
      this.btnNext.Click += new System.EventHandler(this.btnNext_Click);
      // 
      // fraFlagGroupBox
      // 
      this.fraFlagGroupBox.Controls.Add(this.picFlag);
      this.fraFlagGroupBox.Location = new System.Drawing.Point(8, 8);
      this.fraFlagGroupBox.Name = "fraFlagGroupBox";
      this.fraFlagGroupBox.Size = new System.Drawing.Size(112, 88);
      this.fraFlagGroupBox.TabIndex = 4;
      this.fraFlagGroupBox.TabStop = false;
      this.fraFlagGroupBox.Text = "Flag";
      // 
      // picFlag
      // 
      this.picFlag.Location = new System.Drawing.Point(16, 24);
      this.picFlag.Name = "picFlag";
      this.picFlag.Size = new System.Drawing.Size(80, 56);
      this.picFlag.TabIndex = 0;
      this.picFlag.TabStop = false;
      // 
      // cboOptions
      // 
      this.cboOptions.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
      this.cboOptions.Location = new System.Drawing.Point(136, 32);
      this.cboOptions.MaxDropDownItems = 4;
      this.cboOptions.Name = "cboOptions";
      this.cboOptions.TabIndex = 5;
      // 
      // FrmFlagQuiz
      // 
      this.AutoScaleBaseSize = new System.Drawing.Size(5, 14);
      this.ClientSize = new System.Drawing.Size(376, 109);
      this.Controls.Add(this.cboOptions);
      this.Controls.Add(this.fraFlagGroupBox);
      this.Controls.Add(this.btnNext);
      this.Controls.Add(this.btnSubmit);
      this.Controls.Add(this.lblFeedback);
      this.Controls.Add(this.lblChoose);
      this.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((System.Byte)(0)));
      this.Name = "FrmFlagQuiz";
      this.Text = "Flag Quiz";
      this.Load += new System.EventHandler(this.FrmFlagQuiz_Load);
      this.fraFlagGroupBox.ResumeLayout(false);
      this.ResumeLayout(false);

    }
    #endregion
  }
}


namespace Vjesala
{
  partial class Form1
  {
    /// <summary>
    /// Required designer variable.
    /// </summary>
    /// 

    private System.Windows.Forms.ImageList imageList1;
    private System.Windows.Forms.PictureBox pictureBox1;
    private System.Windows.Forms.Button butShow;
    private System.Windows.Forms.Button butAdd;
    private System.Windows.Forms.ImageList imageList2;

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
      System.Resources.ResourceManager resources = new System.Resources.ResourceManager(typeof(Form1));
      this.imageList1 = new System.Windows.Forms.ImageList(this.components);
      this.pictureBox1 = new System.Windows.Forms.PictureBox();
      this.butShow = new System.Windows.Forms.Button();
      this.butAdd = new System.Windows.Forms.Button();
      this.imageList2 = new System.Windows.Forms.ImageList(this.components);
      this.SuspendLayout();
      // 
      // imageList1
      // 
      this.imageList1.ImageSize = new System.Drawing.Size(75, 150);
      this.imageList1.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageList1.ImageStream")));
      this.imageList1.TransparentColor = System.Drawing.Color.Transparent;
      // 
      // pictureBox1
      // 
      this.pictureBox1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
        | System.Windows.Forms.AnchorStyles.Right)));
      this.pictureBox1.Location = new System.Drawing.Point(56, 24);
      this.pictureBox1.Name = "pictureBox1";
      this.pictureBox1.Size = new System.Drawing.Size(72, 64);
      this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize;
      this.pictureBox1.TabIndex = 0;
      this.pictureBox1.TabStop = false;
      // 
      // butShow
      // 
      this.butShow.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)
        | System.Windows.Forms.AnchorStyles.Right)));
      this.butShow.ImageAlign = System.Drawing.ContentAlignment.TopLeft;
      this.butShow.ImageList = this.imageList1;
      this.butShow.Location = new System.Drawing.Point(192, 24);
      this.butShow.Name = "butShow";
      this.butShow.Size = new System.Drawing.Size(72, 40);
      this.butShow.TabIndex = 1;
      this.butShow.Text = "Pokaži";
      this.butShow.Click += new System.EventHandler(this.butShow_Click);
      // 
      // butAdd
      // 
      this.butAdd.Location = new System.Drawing.Point(192, 80);
      this.butAdd.Name = "butAdd";
      this.butAdd.Size = new System.Drawing.Size(72, 40);
      this.butAdd.TabIndex = 2;
      this.butAdd.Text = "Dodaj";
      this.butAdd.Click += new System.EventHandler(this.butAdd_Click);
      // 
      // imageList2
      // 
      this.imageList2.ImageSize = new System.Drawing.Size(16, 16);
      this.imageList2.TransparentColor = System.Drawing.Color.Transparent;
      // 
      // Form1
      // 
      this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
      this.ClientSize = new System.Drawing.Size(292, 262);
      this.Controls.Add(this.butAdd);
      this.Controls.Add(this.butShow);
      this.Controls.Add(this.pictureBox1);
      this.Name = "Form1";
      this.Text = "Form1";
      this.ResumeLayout(false);

    }
    #endregion
  }
}


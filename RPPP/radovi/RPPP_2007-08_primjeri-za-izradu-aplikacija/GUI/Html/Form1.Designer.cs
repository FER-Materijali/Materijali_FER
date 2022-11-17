namespace Html
{
  partial class Form1
  {

    private System.Windows.Forms.ListBox lbDragDropSource;
    private System.Windows.Forms.Splitter splitterCentral;
    private System.Windows.Forms.TextBox txtMain;
    
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
      this.lbDragDropSource = new System.Windows.Forms.ListBox();
      this.splitterCentral = new System.Windows.Forms.Splitter();
      this.txtMain = new System.Windows.Forms.TextBox();
      this.SuspendLayout();
      // 
      // lbDragDropSource
      // 
      this.lbDragDropSource.Dock = System.Windows.Forms.DockStyle.Left;
      this.lbDragDropSource.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((System.Byte)(0)));
      this.lbDragDropSource.IntegralHeight = false;
      this.lbDragDropSource.ItemHeight = 20;
      this.lbDragDropSource.Name = "lbDragDropSource";
      this.lbDragDropSource.Size = new System.Drawing.Size(152, 301);
      this.lbDragDropSource.TabIndex = 0;
      this.lbDragDropSource.MouseDown += new System.Windows.Forms.MouseEventHandler(this.lbDragDropSource_MouseDown);
      this.lbDragDropSource.QueryContinueDrag += new System.Windows.Forms.QueryContinueDragEventHandler(this.lbDragDropSource_QueryContinueDrag);
      this.lbDragDropSource.DragEnter += new System.Windows.Forms.DragEventHandler(this.DragEnter);
      this.lbDragDropSource.DragLeave += new System.EventHandler(this.DragLeave);
      // 
      // splitterCentral
      // 
      this.splitterCentral.Location = new System.Drawing.Point(152, 0);
      this.splitterCentral.Name = "splitterCentral";
      this.splitterCentral.Size = new System.Drawing.Size(3, 301);
      this.splitterCentral.TabIndex = 1;
      this.splitterCentral.TabStop = false;
      // 
      // txtMain
      // 
      this.txtMain.AcceptsReturn = true;
      this.txtMain.AcceptsTab = true;
      this.txtMain.AllowDrop = true;
      this.txtMain.Dock = System.Windows.Forms.DockStyle.Fill;
      this.txtMain.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((System.Byte)(0)));
      this.txtMain.Location = new System.Drawing.Point(155, 0);
      this.txtMain.Multiline = true;
      this.txtMain.Name = "txtMain";
      this.txtMain.Size = new System.Drawing.Size(333, 301);
      this.txtMain.TabIndex = 2;
      this.txtMain.Text = "";
      this.txtMain.DragOver += new System.Windows.Forms.DragEventHandler(this.txtMain_DragOver);
      this.txtMain.DragDrop += new System.Windows.Forms.DragEventHandler(this.txtMain_DragDrop);
      this.txtMain.DragEnter += new System.Windows.Forms.DragEventHandler(this.DragEnter);
      this.txtMain.DragLeave += new System.EventHandler(this.DragLeave);
      // 
      // DragDropForm
      // 
      this.AllowDrop = true;
      this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
      this.ClientSize = new System.Drawing.Size(488, 301);
      this.Controls.AddRange(new System.Windows.Forms.Control[] {
                                                                  this.txtMain,
                                                                  this.splitterCentral,
                                                                  this.lbDragDropSource});
      this.Name = "DragDropForm";
      this.Text = "Drag and Drop Sample";
      this.ResumeLayout(false);

    }
    #endregion
  }
}


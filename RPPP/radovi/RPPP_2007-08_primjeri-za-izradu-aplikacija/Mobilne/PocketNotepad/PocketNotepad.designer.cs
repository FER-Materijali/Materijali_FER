namespace Mobilne
{
  partial class PocketNotepad
  {
    /// <summary>
    /// Required designer variable.
    /// </summary>
    private System.ComponentModel.IContainer components = null;
    private System.Windows.Forms.MainMenu mainMenu;

        private System.Windows.Forms.TextBox textBox;
        private Microsoft.WindowsCE.Forms.InputPanel inputPanel;
        private System.Windows.Forms.MenuItem menuItem1;
        private System.Windows.Forms.MenuItem mnuNew;
        private System.Windows.Forms.MenuItem mnuOpen;
        private System.Windows.Forms.MenuItem mnuSave;
        private System.Windows.Forms.MenuItem mnuSaveAs;
        private System.Windows.Forms.MenuItem menuItem6;
        private System.Windows.Forms.MenuItem mnuExit;
        private System.Windows.Forms.MenuItem menuItem8;
        private System.Windows.Forms.MenuItem mnuCut;
        private System.Windows.Forms.MenuItem mnuCopy;
        private System.Windows.Forms.MenuItem mnuPaste;
        private bool hasChanges = false;
        private System.Windows.Forms.SaveFileDialog saveFileDialog;
        private System.Windows.Forms.OpenFileDialog openFileDialog;
        private string fileName = null;
        private string clipboard = "";
   

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
      this.mainMenu = new System.Windows.Forms.MainMenu();
      this.menuItem1 = new System.Windows.Forms.MenuItem();
      this.mnuNew = new System.Windows.Forms.MenuItem();
      this.mnuOpen = new System.Windows.Forms.MenuItem();
      this.mnuSave = new System.Windows.Forms.MenuItem();
      this.mnuSaveAs = new System.Windows.Forms.MenuItem();
      this.menuItem6 = new System.Windows.Forms.MenuItem();
      this.mnuExit = new System.Windows.Forms.MenuItem();
      this.menuItem8 = new System.Windows.Forms.MenuItem();
      this.mnuCut = new System.Windows.Forms.MenuItem();
      this.mnuCopy = new System.Windows.Forms.MenuItem();
      this.mnuPaste = new System.Windows.Forms.MenuItem();
      this.textBox = new System.Windows.Forms.TextBox();
      this.inputPanel = new Microsoft.WindowsCE.Forms.InputPanel();
      this.saveFileDialog = new System.Windows.Forms.SaveFileDialog();
      this.openFileDialog = new System.Windows.Forms.OpenFileDialog();
      this.SuspendLayout();
      // 
      // mainMenu
      // 
      this.mainMenu.MenuItems.Add(this.menuItem1);
      this.mainMenu.MenuItems.Add(this.menuItem8);
      // 
      // menuItem1
      // 
      this.menuItem1.MenuItems.Add(this.mnuNew);
      this.menuItem1.MenuItems.Add(this.mnuOpen);
      this.menuItem1.MenuItems.Add(this.mnuSave);
      this.menuItem1.MenuItems.Add(this.mnuSaveAs);
      this.menuItem1.MenuItems.Add(this.menuItem6);
      this.menuItem1.MenuItems.Add(this.mnuExit);
      this.menuItem1.Text = "File";
      this.menuItem1.Click += new System.EventHandler(this.menuItem1_Click);
      // 
      // mnuNew
      // 
      this.mnuNew.Text = "New";
      this.mnuNew.Click += new System.EventHandler(this.mnuNew_Click);
      // 
      // mnuOpen
      // 
      this.mnuOpen.Text = "Open";
      this.mnuOpen.Click += new System.EventHandler(this.mnuOpen_Click);
      // 
      // mnuSave
      // 
      this.mnuSave.Text = "Save";
      this.mnuSave.Click += new System.EventHandler(this.mnuSave_Click);
      // 
      // mnuSaveAs
      // 
      this.mnuSaveAs.Text = "Save As";
      this.mnuSaveAs.Click += new System.EventHandler(this.mnuSaveAs_Click);
      // 
      // menuItem6
      // 
      this.menuItem6.Text = "-";
      // 
      // mnuExit
      // 
      this.mnuExit.Text = "Exit";
      this.mnuExit.Click += new System.EventHandler(this.mnuExit_Click);
      // 
      // menuItem8
      // 
      this.menuItem8.MenuItems.Add(this.mnuCut);
      this.menuItem8.MenuItems.Add(this.mnuCopy);
      this.menuItem8.MenuItems.Add(this.mnuPaste);
      this.menuItem8.Text = "Edit";
      // 
      // mnuCut
      // 
      this.mnuCut.Text = "Cut";
      this.mnuCut.Click += new System.EventHandler(this.mnuCut_Click);
      // 
      // mnuCopy
      // 
      this.mnuCopy.Text = "Copy";
      this.mnuCopy.Click += new System.EventHandler(this.mnuCopy_Click);
      // 
      // mnuPaste
      // 
      this.mnuPaste.Text = "Paste";
      this.mnuPaste.Click += new System.EventHandler(this.mnuPaste_Click);
      // 
      // textBox
      // 
      this.textBox.Dock = System.Windows.Forms.DockStyle.Fill;
      this.textBox.Location = new System.Drawing.Point(0, 0);
      this.textBox.Multiline = true;
      this.textBox.Name = "textBox";
      this.textBox.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
      this.textBox.Size = new System.Drawing.Size(240, 268);
      this.textBox.TabIndex = 0;
      this.textBox.TextChanged += new System.EventHandler(this.textBox_TextChanged);
      this.textBox.GotFocus += new System.EventHandler(this.textBox_GotFocus);
      this.textBox.LostFocus += new System.EventHandler(this.textBox_LostFocus);
      // 
      // saveFileDialog
      // 
      this.saveFileDialog.FileName = "doc1";
      this.saveFileDialog.Filter = "Text Files(*.txt)|*.txt|All Files(*.*)|*.*";
      // 
      // openFileDialog
      // 
      this.openFileDialog.Filter = "Text Files(*.txt)|*.txt|All Files(*.*)|*.*";
      // 
      // PocketNotepad
      // 
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Inherit;
      this.ClientSize = new System.Drawing.Size(240, 268);
      this.Controls.Add(this.textBox);
      this.Menu = this.mainMenu;
      this.MinimizeBox = false;
      this.Name = "PocketNotepad";
      this.Text = "Pocket Notepad";
      this.ResumeLayout(false);

    }

    #endregion

  }
}


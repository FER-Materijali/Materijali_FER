using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;
using System.IO;
namespace RichTextBoxPad {
  /// <summary>
  /// Summary description for Form1.
  /// </summary>
  public class MainForm : System.Windows.Forms.Form {
    private System.Windows.Forms.RichTextBox richTextBox;
    private System.Windows.Forms.MainMenu mainMenu1;
    private System.Windows.Forms.MenuItem FileMenuItem;
    private System.Windows.Forms.MenuItem editMenuItem;
    private System.Windows.Forms.MenuItem editFontMenuItem;
    private System.Windows.Forms.MenuItem editColorMenuItem;
    private System.Windows.Forms.MenuItem fileOpenMenuItem;
    private System.Windows.Forms.MenuItem fileSaveMenuItem;
    private System.Windows.Forms.MenuItem fileSaveAsMenuItem;
    private System.Windows.Forms.MenuItem menuItem8;
    private System.Windows.Forms.MenuItem fileExitMenuItem;
    private IContainer components;


    const string _fileFilter = "RTF files (*.rtf)|*.rtf|" +
      "txt files (*.txt)|*.txt|" +
      "All files (*.*)|*.*";
    const string _overwriteWarning = "File already exists, OK to overwrite?";
    const string _appName = "Mini RTF Editor";
    string fileName = "";
    private System.Windows.Forms.MainMenu mainMenu2;
    string pathName = "";

    public MainForm() {
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
    protected override void Dispose( bool disposing ) {
      if( disposing ) {
        if (components != null) {
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
    private void InitializeComponent() {
      this.components = new System.ComponentModel.Container();
      this.richTextBox = new System.Windows.Forms.RichTextBox();
      this.mainMenu1 = new System.Windows.Forms.MainMenu(this.components);
      this.FileMenuItem = new System.Windows.Forms.MenuItem();
      this.fileOpenMenuItem = new System.Windows.Forms.MenuItem();
      this.fileSaveMenuItem = new System.Windows.Forms.MenuItem();
      this.fileSaveAsMenuItem = new System.Windows.Forms.MenuItem();
      this.menuItem8 = new System.Windows.Forms.MenuItem();
      this.fileExitMenuItem = new System.Windows.Forms.MenuItem();
      this.editMenuItem = new System.Windows.Forms.MenuItem();
      this.editFontMenuItem = new System.Windows.Forms.MenuItem();
      this.editColorMenuItem = new System.Windows.Forms.MenuItem();
      this.mainMenu2 = new System.Windows.Forms.MainMenu(this.components);
      this.SuspendLayout();
      // 
      // richTextBox
      // 
      this.richTextBox.Dock = System.Windows.Forms.DockStyle.Fill;
      this.richTextBox.Location = new System.Drawing.Point(0, 0);
      this.richTextBox.Name = "richTextBox";
      this.richTextBox.Size = new System.Drawing.Size(292, 266);
      this.richTextBox.TabIndex = 0;
      this.richTextBox.Text = "";
      this.richTextBox.TextChanged += new System.EventHandler(this.richTextBox_TextChanged);
      // 
      // mainMenu1
      // 
      this.mainMenu1.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.FileMenuItem,
            this.editMenuItem});
      // 
      // FileMenuItem
      // 
      this.FileMenuItem.Index = 0;
      this.FileMenuItem.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.fileOpenMenuItem,
            this.fileSaveMenuItem,
            this.fileSaveAsMenuItem,
            this.menuItem8,
            this.fileExitMenuItem});
      this.FileMenuItem.Text = "&File";
      // 
      // fileOpenMenuItem
      // 
      this.fileOpenMenuItem.Index = 0;
      this.fileOpenMenuItem.Text = "&Open...";
      this.fileOpenMenuItem.Click += new System.EventHandler(this.fileOpenMenuItem_Click);
      // 
      // fileSaveMenuItem
      // 
      this.fileSaveMenuItem.Index = 1;
      this.fileSaveMenuItem.Text = "&Save";
      this.fileSaveMenuItem.Click += new System.EventHandler(this.fileSaveMenuItem_Click);
      // 
      // fileSaveAsMenuItem
      // 
      this.fileSaveAsMenuItem.Index = 2;
      this.fileSaveAsMenuItem.Text = "Save &As...";
      this.fileSaveAsMenuItem.Click += new System.EventHandler(this.fileSaveAsMenuItem_Click);
      // 
      // menuItem8
      // 
      this.menuItem8.Index = 3;
      this.menuItem8.Text = "-";
      // 
      // fileExitMenuItem
      // 
      this.fileExitMenuItem.Index = 4;
      this.fileExitMenuItem.Text = "E&xit";
      this.fileExitMenuItem.Click += new System.EventHandler(this.fileExitMenuItem_Click);
      // 
      // editMenuItem
      // 
      this.editMenuItem.Index = 1;
      this.editMenuItem.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.editFontMenuItem,
            this.editColorMenuItem});
      this.editMenuItem.Text = "&Edit";
      this.editMenuItem.Popup += new System.EventHandler(this.editMenuItem_Popup);
      // 
      // editFontMenuItem
      // 
      this.editFontMenuItem.Index = 0;
      this.editFontMenuItem.Text = "&Font...";
      this.editFontMenuItem.Click += new System.EventHandler(this.editFontMenuItem_Click);
      // 
      // editColorMenuItem
      // 
      this.editColorMenuItem.Index = 1;
      this.editColorMenuItem.Text = "&Color...";
      this.editColorMenuItem.Click += new System.EventHandler(this.editColorMenuItem_Click);
      // 
      // MainForm
      // 
      this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
      this.ClientSize = new System.Drawing.Size(292, 266);
      this.Controls.Add(this.richTextBox);
      this.Menu = this.mainMenu1;
      this.Name = "MainForm";
      this.Text = "(none)";
      this.Load += new System.EventHandler(this.MainForm_Load);
      this.ResumeLayout(false);

    }
		#endregion

    /// <summary>
    /// The main entry point for the application.
    /// </summary>
    [STAThread]
    static void Main() {
      Application.Run(new MainForm());
    }

    private void fileExitMenuItem_Click(object sender, System.EventArgs e) {
      Close();
    }

    private void fileSaveAsMenuItem_Click(object sender, System.EventArgs e) {
      SaveTextToNewPath();
    }

    private void MainForm_Load(object sender, System.EventArgs e) {
      Text = _appName + " - " + "[empty]";
    }

    private void fileOpenMenuItem_Click(object sender, System.EventArgs e) {
      OpenFileDialog dlg = new OpenFileDialog();
      dlg.Filter = _fileFilter;
      //dlg.InitialDirectory = Application.CommonAppDataPath;
      dlg.CheckFileExists = false;
      if(dlg.ShowDialog() == DialogResult.OK) {
        string path = dlg.FileName;
        if(File.Exists(path) != true) {
          StreamWriter writer = File.CreateText(path);
          writer.Close();
        }
        fileName = Path.GetFileName(path);
        pathName = path;
        Text = _appName + " - " +  fileName;
        FileAttributes attribs = File.GetAttributes(path);
        FileInfo info = new FileInfo(path);
        if(info.Extension.ToUpper() == ".RTF")
          richTextBox.LoadFile(path, RichTextBoxStreamType.RichText);
        else
          richTextBox.LoadFile(path, RichTextBoxStreamType.PlainText);
      }
    }

    private void SaveTextToPath(string path) {
      FileInfo info = new FileInfo(path);
      if(info.Extension.ToUpper() == ".RTF")
        richTextBox.SaveFile(path, RichTextBoxStreamType.RichText);
      else
        richTextBox.SaveFile(path, RichTextBoxStreamType.PlainText);
    }

    private void SaveTextToNewPath() {
      SaveFileDialog dlg = new SaveFileDialog();
      dlg.Filter = _fileFilter;
      //dlg.InitialDirectory = Application.CommonAppDataPath;
      if(dlg.ShowDialog() == DialogResult.OK) {
        string path = dlg.FileName;
        if(File.Exists(path) == true) {
          DialogResult result = MessageBox.Show(_overwriteWarning,
            _appName,
            MessageBoxButtons.OKCancel,
            MessageBoxIcon.Question);
          if(result == DialogResult.Cancel)
            return;
        }
        fileName = Path.GetFileName(path);
        pathName = path;
        Text = _appName + " - " +  fileName;
        SaveTextToPath(path);
      }
    }

    private void fileSaveMenuItem_Click(object sender, System.EventArgs e) {
      if(fileName != null && fileName != "")
        SaveTextToPath(pathName);
      else
        SaveTextToNewPath();
    }

    private void editFontMenuItem_Click(object sender, System.EventArgs e) {
      FontDialog dlg = new FontDialog();
      dlg.Font = richTextBox.SelectionFont;
      if(dlg.ShowDialog() == DialogResult.OK) {
        richTextBox.SelectionFont = dlg.Font;

      }
    }

    private void editColorMenuItem_Click(object sender, System.EventArgs e) {
      ColorDialog dlg = new ColorDialog();
      dlg.Color = richTextBox.SelectionColor;
      if(dlg.ShowDialog() == DialogResult.OK) {
        richTextBox.SelectionColor = dlg.Color;
      }
    }

    private void editMenuItem_Popup(object sender, System.EventArgs e) {
      if(richTextBox.SelectionLength > 0) {
        editFontMenuItem.Enabled = true;
        editColorMenuItem.Enabled = true;
      }
      else {
        editFontMenuItem.Enabled = false;
        editColorMenuItem.Enabled = false;
      }
    }

    private void richTextBox_TextChanged(object sender, System.EventArgs e) {
    
    }
  }
}

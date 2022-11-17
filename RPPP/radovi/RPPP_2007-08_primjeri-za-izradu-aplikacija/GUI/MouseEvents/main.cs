using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;

namespace MSPress.CSharpCoreRef.MouseEvents {
  public class MainForm : System.Windows.Forms.Form {
    private System.ComponentModel.Container components = null;
    private System.Windows.Forms.ListBox eventListBox;
    private System.Windows.Forms.Button closeButton;
    private System.Windows.Forms.Label mouseEventArgsLabel;
    private System.Windows.Forms.Label positionLabel;

    public MainForm() {
      InitializeComponent();
      MouseEventHandler wheelHandler = null;
      wheelHandler = new MouseEventHandler(listBox_MouseWheel);
      eventListBox.MouseWheel += wheelHandler;
    }

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
      this.eventListBox = new System.Windows.Forms.ListBox();
      this.closeButton = new System.Windows.Forms.Button();
      this.positionLabel = new System.Windows.Forms.Label();
      this.mouseEventArgsLabel = new System.Windows.Forms.Label();
      this.SuspendLayout();
      // 
      // eventListBox
      // 
      this.eventListBox.Location = new System.Drawing.Point(8, 16);
      this.eventListBox.Name = "eventListBox";
      this.eventListBox.Size = new System.Drawing.Size(296, 108);
      this.eventListBox.TabIndex = 0;
      this.eventListBox.MouseDown += new System.Windows.Forms.MouseEventHandler(this.listBox_MouseDown);
      this.eventListBox.DoubleClick += new System.EventHandler(this.listBox_DoubleClick);
      this.eventListBox.MouseHover += new System.EventHandler(this.listBox_MouseHover);
      this.eventListBox.MouseUp += new System.Windows.Forms.MouseEventHandler(this.listBox_MouseUp);
      this.eventListBox.MouseMove += new System.Windows.Forms.MouseEventHandler(this.listBox_MouseMove);
      this.eventListBox.MouseEnter += new System.EventHandler(this.listBox_MouseEnter);
      this.eventListBox.MouseLeave += new System.EventHandler(this.listBox_MouseLeave);
      this.eventListBox.SelectedIndexChanged += new System.EventHandler(this.eventListBox_SelectedIndexChanged);
      // 
      // closeButton
      // 
      this.closeButton.BackColor = System.Drawing.SystemColors.Control;
      this.closeButton.Location = new System.Drawing.Point(320, 16);
      this.closeButton.Name = "closeButton";
      this.closeButton.TabIndex = 1;
      this.closeButton.Text = "Close";
      this.closeButton.Click += new System.EventHandler(this.closeButton_Click);
      // 
      // positionLabel
      // 
      this.positionLabel.Location = new System.Drawing.Point(8, 136);
      this.positionLabel.Name = "positionLabel";
      this.positionLabel.Size = new System.Drawing.Size(296, 23);
      this.positionLabel.TabIndex = 2;
      this.positionLabel.Text = "positionLabel";
      // 
      // mouseEventArgsLabel
      // 
      this.mouseEventArgsLabel.Location = new System.Drawing.Point(8, 176);
      this.mouseEventArgsLabel.Name = "mouseEventArgsLabel";
      this.mouseEventArgsLabel.Size = new System.Drawing.Size(296, 23);
      this.mouseEventArgsLabel.TabIndex = 3;
      this.mouseEventArgsLabel.Text = "mouseEventArgsLabel";
      // 
      // MainForm
      // 
      this.AcceptButton = this.closeButton;
      this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
      this.AutoScroll = true;
      this.ClientSize = new System.Drawing.Size(416, 214);
      this.Controls.AddRange(new System.Windows.Forms.Control[] {
                                                                  this.mouseEventArgsLabel,
                                                                  this.positionLabel,
                                                                  this.closeButton,
                                                                  this.eventListBox});
      this.MaximizeBox = false;
      this.Name = "MainForm";
      this.Text = "Mouse Events";
      this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.main_MouseDown);
      this.Click += new System.EventHandler(this.main_Click);
      this.Load += new System.EventHandler(this.MainForm_Load);
      this.DoubleClick += new System.EventHandler(this.main_DoubleClick);
      this.MouseUp += new System.Windows.Forms.MouseEventHandler(this.main_MouseUp);
      this.MouseHover += new System.EventHandler(this.main_MouseHover);
      this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.main_MouseMove);
      this.MouseEnter += new System.EventHandler(this.main_MouseEnter);
      this.MouseLeave += new System.EventHandler(this.main_MouseLeave);
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

    private void closeButton_Click(object sender, System.EventArgs e) {
      Close();
    }

    private void main_MouseDown(object sender,
      System.Windows.Forms.MouseEventArgs e) {
      UpdateEventLabels("MouseDown", e.X, e.Y, e);
    }

    private void main_Click(object sender, System.EventArgs e) {
      Point mousePoint = PointToClient(MousePosition);
      UpdateEventLabels("Click",
        mousePoint.X,
        mousePoint.Y,
        null);
    }

    private void main_MouseUp(object sender,
      System.Windows.Forms.MouseEventArgs e) {
      UpdateEventLabels("MouseUp", e.X, e.Y, e);
    }

    private void main_DoubleClick(object sender, System.EventArgs e) {
      Point mousePoint = PointToClient(MousePosition);
      UpdateEventLabels("DoubleClick",
        mousePoint.X,
        mousePoint.Y,
        null);
    }

    private void main_MouseEnter(object sender, System.EventArgs e) {
      Point mousePoint = PointToClient(MousePosition);
      UpdateEventLabels("MouseEnter",
        mousePoint.X,
        mousePoint.Y,
        null);
    }

    private void main_MouseHover(object sender, System.EventArgs e) {
      Point mousePoint = PointToClient(MousePosition);
      UpdateEventLabels("MouseHover",
        mousePoint.X,
        mousePoint.Y,
        null);
    }

    private void main_MouseLeave(object sender, System.EventArgs e) {
      Point mousePoint = PointToClient(MousePosition);
      UpdateEventLabels("MouseLeave",
        mousePoint.X,
        mousePoint.Y,
        null);
    }

    private void main_MouseMove(object sender,
      System.Windows.Forms.MouseEventArgs e) {
      UpdateEventLabels("MouseMove", e.X, e.Y, e);
    }

    private void UpdateEventLabels(string msg,
      int x,int y, MouseEventArgs e) {
      string message = string.Format("{0} X:{1}, Y:{2}",
        msg, x, y);
      positionLabel.Text = message;
      string eventMsg = DateTime.Now.ToShortTimeString();
      eventMsg += " " + message;
      eventListBox.Items.Insert(0, eventMsg);
      eventListBox.TopIndex = 0;

      string mouseInfo;
      if(e != null) {
        mouseInfo = string.Format("Clicks: {0}, Delta: {1}, " + 
          "Buttons: {2}",
          e.Clicks, e.Delta, e.Button.ToString());
      }
      else {
        mouseInfo = "";
      }
      mouseEventArgsLabel.Text = mouseInfo;
    }

    private void listBox_MouseMove(object sender,
      System.Windows.Forms.MouseEventArgs e) {
      UpdateEventLabels("(ListBox)MouseMove", e.X, e.Y, e);
    }

    private void listBox_MouseEnter(object sender, System.EventArgs e) {
      Point mousePoint = PointToClient(MousePosition);
      UpdateEventLabels("(ListBox)MouseEnter",
        mousePoint.X,
        mousePoint.Y,
        null);
    }

    private void listBox_MouseHover(object sender, System.EventArgs e) {
      Point mousePoint = PointToClient(MousePosition);
      UpdateEventLabels("(ListBox)MouseHover",
        mousePoint.X,
        mousePoint.Y,
        null);
    }

    private void listBox_MouseLeave(object sender, System.EventArgs e) {
      Point mousePoint = PointToClient(MousePosition);
      UpdateEventLabels("(ListBox)MouseLeave",
        mousePoint.X,
        mousePoint.Y,
        null);
    }

    private void listBox_MouseUp(object sender,
      System.Windows.Forms.MouseEventArgs e) {
      UpdateEventLabels("(ListBox)MouseUp", e.X, e.Y, e);
    }

    private void listBox_MouseDown(object sender,
      System.Windows.Forms.MouseEventArgs e) {
      UpdateEventLabels("(ListBox)MouseDown", e.X, e.Y, e);
    }

    private void listBox_MouseWheel(object sender,
      System.Windows.Forms.MouseEventArgs e) {
      UpdateEventLabels("(ListBox)MouseWheel", e.X, e.Y, e);
    }

    private void listBox_DoubleClick(object sender, System.EventArgs e) {
      Point mousePoint = PointToClient(MousePosition);
      UpdateEventLabels("(ListBox)DoubleClick",
        mousePoint.X,
        mousePoint.Y,
        null);
    }

    private void eventListBox_SelectedIndexChanged(object sender, System.EventArgs e) {
      
    }

    private void MainForm_Load(object sender, System.EventArgs e) {
    }
  }
}

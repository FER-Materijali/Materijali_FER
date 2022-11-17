//------------------------------------------------------------------------------
/// <copyright from='1997' to='2001' company='Microsoft Corporation'>
///    Copyright (c) Microsoft Corporation. All Rights Reserved.
///
///    This source code is intended only as a supplement to Microsoft
///    Development Tools and/or on-line documentation.  See these other
///    materials for detailed information regarding Microsoft code samples.
///
/// </copyright>
//------------------------------------------------------------------------------
using System;
using System.Collections;
using System.ComponentModel;
using System.Drawing;
using System.Windows.Forms;
using System.Diagnostics;

    // <doc>
    // <desc>
    //     This sample demonstrates the way that Windows does scrolling. The
    //     "value" of the scrollbar must be between minimum and
    //     (maximum - largeChange + 1).
    //     Windows does this because the size of the scrollbar's thumb is equal to
    //     the "largeChange" or "page" value. The value property of the
    //     scrollbar is the  position of the top of the thumb. Therefore, when the
    //     value points to the top of  the last page, the thumb is at the end of the
    //     scrollbar and we can scroll no further, even though the value is less than
    //     the maximum.
    // </desc>
    // </doc>
    //
public class ScrollBarCtl : System.Windows.Forms.Form {
  // Variables for adjusting the position of the pictureBox when scrolling
  private bool  dragging = false; // indikator povlaèenja slike
  private int   oldX, oldY; // stari, tj. poèetni položaj
  private float vScrollMultiplier; // vertikalni pomak slike za korak VScrollBar
  private float vAbsPos;
  private float hScrollMultiplier;
  private System.Windows.Forms.Label labMinValMax; // horizontalni pomak slike za korak HScrollBar
  private float hAbsPos;

  public ScrollBarCtl() : base() {
    //
    // Required for Windows Forms Designer support.
    //
    InitializeComponent();

    comboBox1.SelectedIndex = 0;
    comboBox2.SelectedIndex = 0;

    VScrollBar1.LargeChange = Convert.ToInt16(comboBox1.SelectedItem.ToString());
    HScrollBar1.LargeChange = Convert.ToInt16(comboBox1.SelectedItem.ToString());
    VScrollBar1.SmallChange = Convert.ToInt16(comboBox2.SelectedItem.ToString());
    HScrollBar1.SmallChange = Convert.ToInt16(comboBox2.SelectedItem.ToString());

    SetVerticalScrollMultiplier();
    SetHorizontalScrollMultiplier();

    label11.Text = HScrollBar1.Value.ToString();
    label12.Text = VScrollBar1.Value.ToString();

    /*
    * Change the cursor give the user feedback for dragging the
    * picture around the picturebox
    */
    pictureBox1.Cursor = Cursors.SizeAll;

  }

  // <summary>
  //     ScrollBarCtl overrides dispose so it can clean up the
  //     component list.
  // </summary>
  protected override void Dispose(bool disposing) {
    if (disposing) {
      if (components != null) {
        components.Dispose();
      }
    }
    base.Dispose(disposing);
  }

  /*
  * The vScrollMultiplier takes into account the height of the pictureBox
  * when scrolling.
  * It is essentially "pixels per tick", where a tick is the smallest
  * increment of the scrollbar.
  */
  private void SetVerticalScrollMultiplier() {
    // vertikalni hod, npr. 152-96 = 56
    float hsb = (float)(VScrollBar1.Height - pictureBox1.Height);
    // broj pomaka VScrollBar, npr. 100 - (-100) = 200
    float ticks = (float)(VScrollBar1.Maximum - VScrollBar1.Minimum);
    // vertikalni hod slike za Scrollbar pomak, npr. 56/200 = 0.28
    vScrollMultiplier = hsb / ticks;
  }

  /*
  * The hScrollMultiplier takes into account the width of the
  * pictureBox when scrolling.
  * It is essentially "pixels per tick", where a tick is the smallest
  * increment of the scrollbar.
  */
  private void SetHorizontalScrollMultiplier() {
    float hsb = (float)(HScrollBar1.Width - pictureBox1.Width) ;
    float ticks = (float)(HScrollBar1.Maximum - HScrollBar1.Minimum) ;

    hScrollMultiplier = hsb / ticks ;
  }

  /*
  * Vertical scrollbar handler - scrollbar action handled by Windows Forms Scrollbar.
  * Here we update the label displaying our value and the
  * set the  pictureBox y coordinate.
  */
  private void VScrollBar1_Scroll(object sender, ScrollEventArgs e) {
    label12.Text = VScrollBar1.Value.ToString();
    vAbsPos = (float)(VScrollBar1.Value - VScrollBar1.Minimum);
    labMinValMax.Text = VScrollBar1.Minimum + "/" + VScrollBar1.Value + "/" + VScrollBar1.Maximum;
    pictureBox1.Top = VScrollBar1.Bottom
      - (int)(vScrollMultiplier * vAbsPos)
      - pictureBox1.Height;
  }

  /*
  * Horizontal scrollbar handler - scrollbar action handled by Windows Forms
  * Scrollbar. Here we update the label displaying our value and the set
  * the pictureBox y coordinate.
  */
  private void HScrollBar1_Scroll(object sender, ScrollEventArgs e) {
    label11.Text = HScrollBar1.Value.ToString() ;
    hAbsPos = (float)(HScrollBar1.Value - HScrollBar1.Minimum);
    labMinValMax.Text = HScrollBar1.Minimum + "/" + HScrollBar1.Value + "/" + HScrollBar1.Maximum;

    pictureBox1.Left = HScrollBar1.Right
      - (int)(hScrollMultiplier * hAbsPos)
      - pictureBox1.Width;
  }

  /*
  * Changing the "LargeChange" (the number of ticks per page) property of
  * the ScrollBarCtl.
  */
  private void comboBox1_SelectedIndexChanged(object sender, EventArgs e) {
    VScrollBar1.LargeChange = Convert.ToInt16(comboBox1.SelectedItem.ToString());
    HScrollBar1.LargeChange = Convert.ToInt16(comboBox1.SelectedItem.ToString());
    label11.Text = HScrollBar1.Value.ToString() ;
    label12.Text = VScrollBar1.Value.ToString() ;
  }

  /*
  * Changing the "SmallChange" (the number of ticks per line) property of
  * the ScrollBarCtl.
  */
  private void comboBox2_SelectedIndexChanged(object sender, EventArgs e) {
    VScrollBar1.SmallChange = Convert.ToInt16(comboBox2.SelectedItem.ToString());
    HScrollBar1.SmallChange = Convert.ToInt16(comboBox2.SelectedItem.ToString());
    label11.Text = HScrollBar1.Value.ToString() ;
    label12.Text = VScrollBar1.Value.ToString() ;
  }


  // Mouse event handler to initiate dragging the pictureBox around
  private void pictureBox1_MouseDown(object sender, MouseEventArgs e) {
    dragging = true; // Start dragging

    /*
    * (e.x, e.y) represent the coordinates of the cursor relative to the
    * pictureBox's location. We need to save these on mouseDown in order
    * to calculate the distance dragged.
    */
    oldX = e.X;
    oldY = e.Y;
    Debug.WriteLine ("MouseDown - Old pos:" + oldX.ToString() + "," + oldY.ToString());
  }

  // Mouse event handler to effect dragging the pictureBox around.
  private void pictureBox1_MouseMove(object sender, MouseEventArgs e) {
    if (dragging) {
      int minY = VScrollBar1.Minimum;
      int maxY = VScrollBar1.Maximum;
      int minX = HScrollBar1.Minimum;
      int maxX = HScrollBar1.Maximum;

      /*
      * The new y position of the scrollbar is
      * (old_y_Position - y_distance_that_the_cursor_has_moved).
      * We want to simulate "real" scrolling so we move the
      * ScrollBarCtl in the opposite direction of the pictureBox.
      * We need the multiplier to convert pixels to scrollbar ticks.
      */
      Debug.WriteLine ("MouseMove - New pos:" + e.X.ToString() + "," + e.Y.ToString());
      int value = (int)(VScrollBar1.Value
        - (e.Y - oldY)/vScrollMultiplier);
      if (value < minY) {
        VScrollBar1.Value = minY;
      }
      else if (value > maxY - VScrollBar1.LargeChange + 1) {
        VScrollBar1.Value = maxY - VScrollBar1.LargeChange + 1;
      }
      else {
        VScrollBar1.Value = value;
      }

      // Similarly for the x position...
      value = (int)(HScrollBar1.Value
        - (e.X - oldX)/hScrollMultiplier);
      if (value < minX) {
        HScrollBar1.Value = minX;
      }
      else if (value > maxX - HScrollBar1.LargeChange + 1) {
        HScrollBar1.Value = maxX - HScrollBar1.LargeChange + 1;
      }
      else {
        HScrollBar1.Value = value;
      }

      label11.Text = HScrollBar1.Value.ToString() ;
      label12.Text = VScrollBar1.Value.ToString() ;

      /*
      * The pictureBox moves with the mouse. Thus the new y coordinate is
      * (old_y_Position + y_distance_that_the_cursor_has_moved), and similarly
      * for the x coordinate.
      */
      value = pictureBox1.Top + (e.Y - oldY);
      if (value < VScrollBar1.Top) {
        value = VScrollBar1.Top;
      }
      else if (value > VScrollBar1.Bottom - pictureBox1.Height) {
        value = VScrollBar1.Bottom - pictureBox1.Height;
      }
      pictureBox1.Top = value;

      value = pictureBox1.Left + (e.X - oldX);
      if (value < HScrollBar1.Left) {
        value = HScrollBar1.Left;
      }
      else if (value > HScrollBar1.Right - pictureBox1.Width) {
        value = HScrollBar1.Right - pictureBox1.Width;
      }
      pictureBox1.Left = value;
    }
  }

  /*
  * Mouse event handler to signal the end of the pictureBox dragging
  * sequence.
  */
  private void pictureBox1_MouseUp(object sender, MouseEventArgs e) {
    dragging = false;
  }


  // NOTE: The following code is required by the Windows Forms Designer
  // It can be modified using the Windows Forms Designer.
  // Do not modify it using the code editor.
  private System.ComponentModel.Container components;
  protected internal System.Windows.Forms.VScrollBar VScrollBar1;
  protected internal System.Windows.Forms.HScrollBar HScrollBar1;
  protected internal System.Windows.Forms.GroupBox groupBox1;
  protected internal System.Windows.Forms.Label label1;
  protected internal System.Windows.Forms.Label label2;
  protected internal System.Windows.Forms.ComboBox comboBox2;
  protected internal System.Windows.Forms.PictureBox pictureBox1;
  protected internal System.Windows.Forms.Label label3;
  protected internal System.Windows.Forms.Label label4;
  protected internal System.Windows.Forms.Label label5;
  protected internal System.Windows.Forms.Label label7;
  protected internal System.Windows.Forms.Label label6;
  protected internal System.Windows.Forms.Label label12;
  protected internal System.Windows.Forms.Label label11;
  protected internal System.Windows.Forms.Label label8;
  protected internal System.Windows.Forms.Label label9;
  protected internal System.Windows.Forms.Label label10;
  protected internal System.Windows.Forms.ComboBox comboBox1;

  private void InitializeComponent() {
    System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(ScrollBarCtl));
    this.label11 = new System.Windows.Forms.Label();
    this.label10 = new System.Windows.Forms.Label();
    this.VScrollBar1 = new System.Windows.Forms.VScrollBar();
    this.label12 = new System.Windows.Forms.Label();
    this.comboBox1 = new System.Windows.Forms.ComboBox();
    this.HScrollBar1 = new System.Windows.Forms.HScrollBar();
    this.groupBox1 = new System.Windows.Forms.GroupBox();
    this.labMinValMax = new System.Windows.Forms.Label();
    this.label7 = new System.Windows.Forms.Label();
    this.label6 = new System.Windows.Forms.Label();
    this.comboBox2 = new System.Windows.Forms.ComboBox();
    this.pictureBox1 = new System.Windows.Forms.PictureBox();
    this.label4 = new System.Windows.Forms.Label();
    this.label5 = new System.Windows.Forms.Label();
    this.label8 = new System.Windows.Forms.Label();
    this.label9 = new System.Windows.Forms.Label();
    this.label2 = new System.Windows.Forms.Label();
    this.label3 = new System.Windows.Forms.Label();
    this.label1 = new System.Windows.Forms.Label();
    this.groupBox1.SuspendLayout();
    ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
    this.SuspendLayout();
    // 
    // label11
    // 
    this.label11.Location = new System.Drawing.Point(144, 112);
    this.label11.Name = "label11";
    this.label11.Size = new System.Drawing.Size(72, 16);
    this.label11.TabIndex = 4;
    this.label11.Text = "Label11";
    // 
    // label10
    // 
    this.label10.Location = new System.Drawing.Point(216, 168);
    this.label10.Name = "label10";
    this.label10.Size = new System.Drawing.Size(24, 16);
    this.label10.TabIndex = 13;
    this.label10.Text = "100";
    // 
    // VScrollBar1
    // 
    this.VScrollBar1.Location = new System.Drawing.Point(200, 24);
    this.VScrollBar1.Minimum = -100;
    this.VScrollBar1.Name = "VScrollBar1";
    this.VScrollBar1.Size = new System.Drawing.Size(16, 152);
    this.VScrollBar1.TabIndex = 2;
    this.VScrollBar1.Scroll += new System.Windows.Forms.ScrollEventHandler(this.VScrollBar1_Scroll);
    // 
    // label12
    // 
    this.label12.Location = new System.Drawing.Point(144, 136);
    this.label12.Name = "label12";
    this.label12.Size = new System.Drawing.Size(72, 16);
    this.label12.TabIndex = 7;
    this.label12.Text = "label12";
    // 
    // comboBox1
    // 
    this.comboBox1.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
    this.comboBox1.Items.AddRange(new object[] {
            "20",
            "10",
            "5"});
    this.comboBox1.Location = new System.Drawing.Point(136, 24);
    this.comboBox1.Name = "comboBox1";
    this.comboBox1.Size = new System.Drawing.Size(96, 21);
    this.comboBox1.TabIndex = 0;
    this.comboBox1.SelectedIndexChanged += new System.EventHandler(this.comboBox1_SelectedIndexChanged);
    // 
    // HScrollBar1
    // 
    this.HScrollBar1.Location = new System.Drawing.Point(16, 176);
    this.HScrollBar1.Minimum = -100;
    this.HScrollBar1.Name = "HScrollBar1";
    this.HScrollBar1.Size = new System.Drawing.Size(184, 16);
    this.HScrollBar1.TabIndex = 3;
    this.HScrollBar1.Scroll += new System.Windows.Forms.ScrollEventHandler(this.HScrollBar1_Scroll);
    // 
    // groupBox1
    // 
    this.groupBox1.Controls.Add(this.labMinValMax);
    this.groupBox1.Controls.Add(this.label7);
    this.groupBox1.Controls.Add(this.label6);
    this.groupBox1.Controls.Add(this.comboBox2);
    this.groupBox1.Controls.Add(this.comboBox1);
    this.groupBox1.Controls.Add(this.label11);
    this.groupBox1.Controls.Add(this.label12);
    this.groupBox1.Location = new System.Drawing.Point(264, 16);
    this.groupBox1.Name = "groupBox1";
    this.groupBox1.Size = new System.Drawing.Size(248, 264);
    this.groupBox1.TabIndex = 5;
    this.groupBox1.TabStop = false;
    this.groupBox1.Text = "HScrollBar and VScrollBar";
    this.groupBox1.Enter += new System.EventHandler(this.groupBox1_Enter);
    // 
    // labMinValMax
    // 
    this.labMinValMax.Location = new System.Drawing.Point(24, 176);
    this.labMinValMax.Name = "labMinValMax";
    this.labMinValMax.Size = new System.Drawing.Size(192, 16);
    this.labMinValMax.TabIndex = 8;
    this.labMinValMax.Text = "labMinValMax";
    // 
    // label7
    // 
    this.label7.Location = new System.Drawing.Point(16, 136);
    this.label7.Name = "label7";
    this.label7.Size = new System.Drawing.Size(92, 16);
    this.label7.TabIndex = 2;
    this.label7.Text = "VScrollBar.value";
    // 
    // label6
    // 
    this.label6.Location = new System.Drawing.Point(16, 112);
    this.label6.Name = "label6";
    this.label6.Size = new System.Drawing.Size(92, 16);
    this.label6.TabIndex = 3;
    this.label6.Text = "HScrollBar.value";
    // 
    // comboBox2
    // 
    this.comboBox2.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
    this.comboBox2.Items.AddRange(new object[] {
            "5",
            "2",
            "1"});
    this.comboBox2.Location = new System.Drawing.Point(136, 48);
    this.comboBox2.Name = "comboBox2";
    this.comboBox2.Size = new System.Drawing.Size(96, 21);
    this.comboBox2.TabIndex = 1;
    this.comboBox2.SelectedIndexChanged += new System.EventHandler(this.comboBox2_SelectedIndexChanged);
    // 
    // pictureBox1
    // 
    this.pictureBox1.Cursor = System.Windows.Forms.Cursors.Default;
    this.pictureBox1.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox1.Image")));
    this.pictureBox1.Location = new System.Drawing.Point(64, 56);
    this.pictureBox1.Name = "pictureBox1";
    this.pictureBox1.Size = new System.Drawing.Size(96, 96);
    this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
    this.pictureBox1.TabIndex = 6;
    this.pictureBox1.TabStop = false;
    this.pictureBox1.Text = "pictureBox1";
    this.pictureBox1.MouseMove += new System.Windows.Forms.MouseEventHandler(this.pictureBox1_MouseMove);
    this.pictureBox1.MouseDown += new System.Windows.Forms.MouseEventHandler(this.pictureBox1_MouseDown);
    this.pictureBox1.MouseUp += new System.Windows.Forms.MouseEventHandler(this.pictureBox1_MouseUp);
    // 
    // label4
    // 
    this.label4.Location = new System.Drawing.Point(184, 192);
    this.label4.Name = "label4";
    this.label4.Size = new System.Drawing.Size(24, 16);
    this.label4.TabIndex = 9;
    this.label4.Text = "100";
    // 
    // label5
    // 
    this.label5.Location = new System.Drawing.Point(112, 200);
    this.label5.Name = "label5";
    this.label5.Size = new System.Drawing.Size(32, 16);
    this.label5.TabIndex = 10;
    this.label5.Text = "0";
    // 
    // label8
    // 
    this.label8.Location = new System.Drawing.Point(224, 24);
    this.label8.Name = "label8";
    this.label8.Size = new System.Drawing.Size(32, 16);
    this.label8.TabIndex = 11;
    this.label8.Text = "-100";
    // 
    // label9
    // 
    this.label9.Location = new System.Drawing.Point(224, 96);
    this.label9.Name = "label9";
    this.label9.Size = new System.Drawing.Size(16, 16);
    this.label9.TabIndex = 12;
    this.label9.Text = "0";
    // 
    // label2
    // 
    this.label2.Location = new System.Drawing.Point(280, 64);
    this.label2.Name = "label2";
    this.label2.Size = new System.Drawing.Size(92, 16);
    this.label2.TabIndex = 1;
    this.label2.Text = "SmallChange";
    // 
    // label3
    // 
    this.label3.Location = new System.Drawing.Point(8, 200);
    this.label3.Name = "label3";
    this.label3.Size = new System.Drawing.Size(32, 16);
    this.label3.TabIndex = 8;
    this.label3.Text = "-100";
    // 
    // label1
    // 
    this.label1.Location = new System.Drawing.Point(280, 40);
    this.label1.Name = "label1";
    this.label1.Size = new System.Drawing.Size(92, 72);
    this.label1.TabIndex = 0;
    this.label1.Text = "LargeChange";
    // 
    // ScrollBarCtl
    // 
    this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
    this.ClientSize = new System.Drawing.Size(518, 296);
    this.Controls.Add(this.label10);
    this.Controls.Add(this.label9);
    this.Controls.Add(this.label8);
    this.Controls.Add(this.label5);
    this.Controls.Add(this.label4);
    this.Controls.Add(this.label3);
    this.Controls.Add(this.label2);
    this.Controls.Add(this.label1);
    this.Controls.Add(this.groupBox1);
    this.Controls.Add(this.HScrollBar1);
    this.Controls.Add(this.VScrollBar1);
    this.Controls.Add(this.pictureBox1);
    this.Name = "ScrollBarCtl";
    this.Text = "VScrollBar";
    this.groupBox1.ResumeLayout(false);
    ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
    this.ResumeLayout(false);

  }

  // The main entry point for the application.
  [STAThread]
  public static void Main(string[] args) {
    Application.Run(new ScrollBarCtl());
  }

  private void groupBox1_Enter(object sender, System.EventArgs e) {
  
  }
}


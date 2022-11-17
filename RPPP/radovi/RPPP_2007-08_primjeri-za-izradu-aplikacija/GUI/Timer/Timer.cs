using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;

namespace Clock
{
	/// <summary>
	/// Summary description for Form1.
	/// </summary>
	public class Form1 : System.Windows.Forms.Form
	{
		private System.Windows.Forms.Label labelTime;
		private System.Windows.Forms.Timer timeWatch;
		private System.Windows.Forms.Label labelDate;
    private System.Windows.Forms.Timer stopWatch;
		private System.ComponentModel.IContainer components;
    private System.Windows.Forms.Button resumeButton;
    private System.Windows.Forms.Button pauseButton;
    private System.Windows.Forms.Label labelWatch;

    private int ticks; // number of ticks worked

		#region Form1 Constructor
		public Form1()
		{
			//
			// Required for Windows Form Designer support
			//
			InitializeComponent();

			//
			// TODO: Add any constructor code after InitializeComponent call
			//
			// The following line sets the text for the label box.
			// To display no text, simply use two quote marks.
			labelTime.Text = "";
			// The following two statements set the text size and
			// cause the time to appear centered in the label box
			labelTime.Font = new System.Drawing.Font
				("Microsoft Sans Serif", 24);
			labelTime.TextAlign = ContentAlignment.MiddleCenter;
			labelDate.Font = labelTime.Font;
			labelDate.TextAlign = ContentAlignment.MiddleCenter;
			// This.Text is the text that will appear in the form's
			// title bar.
//			this.Text = "My Clock";
			// The following three lines set the timer to tick
			// every second (1000 milliseconds), start the timer and
			// write the initial time to the label box
			timeWatch.Interval = 1000;
			timeWatch.Start ();
			SetClock ();
		}
		#endregion
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
      this.components = new System.ComponentModel.Container();
      this.timeWatch = new System.Windows.Forms.Timer(this.components);
      this.labelTime = new System.Windows.Forms.Label();
      this.labelDate = new System.Windows.Forms.Label();
      this.stopWatch = new System.Windows.Forms.Timer(this.components);
      this.resumeButton = new System.Windows.Forms.Button();
      this.pauseButton = new System.Windows.Forms.Button();
      this.labelWatch = new System.Windows.Forms.Label();
      this.SuspendLayout();
      // 
      // timeWatch
      // 
      this.timeWatch.Tick += new System.EventHandler(this.timeWatch_Tick);
      // 
      // labelTime
      // 
      this.labelTime.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
      this.labelTime.Dock = System.Windows.Forms.DockStyle.Top;
      this.labelTime.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((System.Byte)(0)));
      this.labelTime.Location = new System.Drawing.Point(0, 45);
      this.labelTime.Name = "labelTime";
      this.labelTime.Size = new System.Drawing.Size(336, 45);
      this.labelTime.TabIndex = 0;
      this.labelTime.Text = "labelTime";
      this.labelTime.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
      // 
      // labelDate
      // 
      this.labelDate.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
      this.labelDate.Dock = System.Windows.Forms.DockStyle.Top;
      this.labelDate.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((System.Byte)(0)));
      this.labelDate.Name = "labelDate";
      this.labelDate.Size = new System.Drawing.Size(336, 45);
      this.labelDate.TabIndex = 1;
      this.labelDate.Text = "labelDate";
      this.labelDate.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
      // 
      // stopWatch
      // 
      this.stopWatch.Interval = 10;
      this.stopWatch.Tick += new System.EventHandler(this.stopWatch_Tick);
      // 
      // resumeButton
      // 
      this.resumeButton.Dock = System.Windows.Forms.DockStyle.Bottom;
      this.resumeButton.Location = new System.Drawing.Point(0, 178);
      this.resumeButton.Name = "resumeButton";
      this.resumeButton.Size = new System.Drawing.Size(336, 40);
      this.resumeButton.TabIndex = 2;
      this.resumeButton.Text = "Resume";
      this.resumeButton.Click += new System.EventHandler(this.resumeButton_Click);
      // 
      // pauseButton
      // 
      this.pauseButton.Dock = System.Windows.Forms.DockStyle.Bottom;
      this.pauseButton.Location = new System.Drawing.Point(0, 138);
      this.pauseButton.Name = "pauseButton";
      this.pauseButton.Size = new System.Drawing.Size(336, 40);
      this.pauseButton.TabIndex = 3;
      this.pauseButton.Text = "Pause";
      this.pauseButton.Click += new System.EventHandler(this.pauseButton_Click);
      // 
      // labelWatch
      // 
      this.labelWatch.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
      this.labelWatch.Dock = System.Windows.Forms.DockStyle.Top;
      this.labelWatch.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((System.Byte)(0)));
      this.labelWatch.Location = new System.Drawing.Point(0, 90);
      this.labelWatch.Name = "labelWatch";
      this.labelWatch.Size = new System.Drawing.Size(336, 45);
      this.labelWatch.TabIndex = 4;
      this.labelWatch.Text = "labelWatch";
      this.labelWatch.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
      // 
      // Form1
      // 
      this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
      this.ClientSize = new System.Drawing.Size(336, 218);
      this.Controls.AddRange(new System.Windows.Forms.Control[] {
                                                                  this.labelWatch,
                                                                  this.labelTime,
                                                                  this.labelDate,
                                                                  this.pauseButton,
                                                                  this.resumeButton});
      this.Name = "Form1";
      this.Text = "Form1";
      this.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.Form1_KeyPress);
      this.Load += new System.EventHandler(this.Form1_Load);
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

		private void timeWatch_Tick(object sender, System.EventArgs e)
		{
			SetClock ();
		}

		protected void SetClock ()
		{
			string str = DateTime.Now.ToString();
			int index = str.IndexOf (" ");
			labelTime.Text = "Time: " + str.Substring (index + 1);
			labelDate.Text = "Date: " + str.Substring (0, index);
		}

    private void Form1_Load(object sender, System.EventArgs e) {
      SetRunningState( true );
    }

    private void stopWatch_Tick(object sender, System.EventArgs e) {
      ticks ++;
      labelWatch.Text = "Watch: " + Ticks2String( ticks ) ;
    }

    private string Ticks2String(int t) {
      int tUnits = 1000/stopWatch.Interval; 
      // npr. 10 desetinki za Interval=100
      int s = t / tUnits; // broj ukupno proteklih sekundi 
      int m = s / 60; // ukupni broj minuta 
      s = s % 60;     // broj sekundi preko punih minuta
      t = t % tUnits; // ostatak desetinki

      return String.Format("{0:D2}:{1:D2}:{2:D2}", m, s, t); 
    }

    private void pauseButton_Click(object sender, System.EventArgs e) {
      SetRunningState ( false );
    }

    private void resumeButton_Click(object sender, System.EventArgs e) {
      SetRunningState ( true );
     }

    private void SetRunningState( bool running ) {
      stopWatch.Enabled = running;

      resumeButton.Enabled = !running;
      pauseButton.Enabled = running;

      this.Focus();
    }

    private void Form1_KeyPress(object sender, System.Windows.Forms.KeyPressEventArgs e) {
      switch ( e.KeyChar ) {
        case 'p': case 'P':
          SetRunningState ( false );
          break;

        case 'R': case 'r':
          SetRunningState ( true );
          break;

        case 'Q': case 'q':
          Application.Exit();
          break;

        default:
          break;
      } // end of switch
    
    }

	}
}

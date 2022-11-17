using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;

namespace ProjektAutomati
{
	/// <summary>
	/// Summary description for Form1.
	/// </summary>
	public class Form1 : System.Windows.Forms.Form
	{
		private System.Windows.Forms.TextBox txtPrvi;
		private System.Windows.Forms.Label lblPrvi;
		private System.Windows.Forms.Label lblDrugi;
		private System.Windows.Forms.TextBox txtDrugi;
		private System.Windows.Forms.Label lblPrvo;
		private System.Windows.Forms.Label lblDrugo;
		private System.Windows.Forms.Button btnPrviKorak;
		private System.Windows.Forms.Button btnDrugiKorak;
		private System.Windows.Forms.Button btnIzlaz;
		private System.Windows.Forms.MainMenu mainMenu1;
		private System.Windows.Forms.MenuItem menuItem1;
		private System.Windows.Forms.MenuItem menuItem2;
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
			this.txtPrvi = new System.Windows.Forms.TextBox();
			this.lblPrvi = new System.Windows.Forms.Label();
			this.lblDrugi = new System.Windows.Forms.Label();
			this.txtDrugi = new System.Windows.Forms.TextBox();
			this.lblPrvo = new System.Windows.Forms.Label();
			this.lblDrugo = new System.Windows.Forms.Label();
			this.btnPrviKorak = new System.Windows.Forms.Button();
			this.btnDrugiKorak = new System.Windows.Forms.Button();
			this.btnIzlaz = new System.Windows.Forms.Button();
			this.mainMenu1 = new System.Windows.Forms.MainMenu();
			this.menuItem1 = new System.Windows.Forms.MenuItem();
			this.menuItem2 = new System.Windows.Forms.MenuItem();
			this.SuspendLayout();
			// 
			// txtPrvi
			// 
			this.txtPrvi.Location = new System.Drawing.Point(96, 24);
			this.txtPrvi.Name = "txtPrvi";
			this.txtPrvi.Size = new System.Drawing.Size(176, 20);
			this.txtPrvi.TabIndex = 0;
			this.txtPrvi.Text = "";
			// 
			// lblPrvi
			// 
			this.lblPrvi.Location = new System.Drawing.Point(16, 24);
			this.lblPrvi.Name = "lblPrvi";
			this.lblPrvi.Size = new System.Drawing.Size(64, 23);
			this.lblPrvi.TabIndex = 1;
			this.lblPrvi.Text = "Prvi broj:";
			// 
			// lblDrugi
			// 
			this.lblDrugi.Location = new System.Drawing.Point(16, 56);
			this.lblDrugi.Name = "lblDrugi";
			this.lblDrugi.Size = new System.Drawing.Size(64, 23);
			this.lblDrugi.TabIndex = 2;
			this.lblDrugi.Text = "Drugi broj:";
			// 
			// txtDrugi
			// 
			this.txtDrugi.Location = new System.Drawing.Point(96, 56);
			this.txtDrugi.Name = "txtDrugi";
			this.txtDrugi.Size = new System.Drawing.Size(176, 20);
			this.txtDrugi.TabIndex = 3;
			this.txtDrugi.Text = "";
			// 
			// lblPrvo
			// 
			this.lblPrvo.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
			this.lblPrvo.Location = new System.Drawing.Point(16, 104);
			this.lblPrvo.Name = "lblPrvo";
			this.lblPrvo.Size = new System.Drawing.Size(152, 56);
			this.lblPrvo.TabIndex = 4;
			this.lblPrvo.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// lblDrugo
			// 
			this.lblDrugo.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
			this.lblDrugo.Location = new System.Drawing.Point(16, 168);
			this.lblDrugo.Name = "lblDrugo";
			this.lblDrugo.Size = new System.Drawing.Size(152, 32);
			this.lblDrugo.TabIndex = 5;
			this.lblDrugo.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// btnPrviKorak
			// 
			this.btnPrviKorak.Location = new System.Drawing.Point(200, 104);
			this.btnPrviKorak.Name = "btnPrviKorak";
			this.btnPrviKorak.Size = new System.Drawing.Size(75, 56);
			this.btnPrviKorak.TabIndex = 7;
			this.btnPrviKorak.Text = "Poèetno stanje trake";
			this.btnPrviKorak.Click += new System.EventHandler(this.btnPrviKorak_Click);
			// 
			// btnDrugiKorak
			// 
			this.btnDrugiKorak.Location = new System.Drawing.Point(200, 168);
			this.btnDrugiKorak.Name = "btnDrugiKorak";
			this.btnDrugiKorak.Size = new System.Drawing.Size(75, 56);
			this.btnDrugiKorak.TabIndex = 8;
			this.btnDrugiKorak.Text = "Konaèno stanje trake";
			this.btnDrugiKorak.Click += new System.EventHandler(this.btnDrugiKorak_Click);
			// 
			// btnIzlaz
			// 
			this.btnIzlaz.Location = new System.Drawing.Point(200, 232);
			this.btnIzlaz.Name = "btnIzlaz";
			this.btnIzlaz.TabIndex = 10;
			this.btnIzlaz.Text = "Izlaz";
			this.btnIzlaz.Click += new System.EventHandler(this.btnIzlaz_Click);
			// 
			// mainMenu1
			// 
			this.mainMenu1.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
																					  this.menuItem1});
			// 
			// menuItem1
			// 
			this.menuItem1.Index = 0;
			this.menuItem1.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
																					  this.menuItem2});
			this.menuItem1.Text = "Help";
			// 
			// menuItem2
			// 
			this.menuItem2.Index = 0;
			this.menuItem2.Text = "About...";
			this.menuItem2.Click += new System.EventHandler(this.menuItem2_Click);
			// 
			// Form1
			// 
			this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
			this.ClientSize = new System.Drawing.Size(296, 270);
			this.Controls.Add(this.btnIzlaz);
			this.Controls.Add(this.btnDrugiKorak);
			this.Controls.Add(this.btnPrviKorak);
			this.Controls.Add(this.lblDrugo);
			this.Controls.Add(this.lblPrvo);
			this.Controls.Add(this.txtDrugi);
			this.Controls.Add(this.lblDrugi);
			this.Controls.Add(this.lblPrvi);
			this.Controls.Add(this.txtPrvi);
			this.Menu = this.mainMenu1;
			this.Name = "Form1";
			this.Text = "Form1";
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

		private void btnIzlaz_Click(object sender, System.EventArgs e)
		{
			this.Close();
		}

		private void btnPrviKorak_Click(object sender, System.EventArgs e)
		{
			lblPrvo.Text = txtPrvi.Text + "+" + txtDrugi.Text;
		}

		private void btnDrugiKorak_Click(object sender, System.EventArgs e)
		{
			lblDrugo.Text = "";
			Turing TS = new Turing(txtPrvi.Text,txtDrugi.Text);
			TS.Radi("q0");
			for(int i = 0; i < TS.Traka.Length; i++)
			{
				if(TS.Traka[i]!= "B")
					lblDrugo.Text += TS.Traka[i];
			}
			
		}

		private void menuItem2_Click(object sender, System.EventArgs e)
		{
			MessageBox.Show("Zahvaljujuæi svom cimeru riješio sam programski dio zadatka u 2h u noæi, dakle da njega nije bilo završio bih puno ranije!!!!!!!!!","About");
		}

	}
}

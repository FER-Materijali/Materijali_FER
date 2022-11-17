using System;
using System.ComponentModel;
using System.Collections;
using System.Diagnostics;

namespace NorthwindCE_2556
{
	/// <summary>
	/// Summary description for orderItemControl.
	/// </summary>
	public class orderItemControl : System.Windows.Forms.Control
	{
		private System.ComponentModel.Container components;

		public System.Windows.Forms.TextBox discountTextBox;
		public System.Windows.Forms.TextBox quantityTextBox;
		public System.Windows.Forms.TextBox priceTextBox;
		public System.Windows.Forms.ComboBox productComboBox;

		public orderItemControl()
		{
			/// <summary>
			/// Required for Windows.Forms Class Composition Designer support
			/// </summary>
			InitializeComponent();

			this.productComboBox = new System.Windows.Forms.ComboBox();
			this.quantityTextBox = new System.Windows.Forms.TextBox();
			this.priceTextBox = new System.Windows.Forms.TextBox();
			this.discountTextBox = new System.Windows.Forms.TextBox();

			//Initialize Product ComboBox
			this.productComboBox.Size = new System.Drawing.Size(130, 20);
			this.productComboBox.Location = new System.Drawing.Point(0, 0);

			//Initialize Quantity TextBox
			this.quantityTextBox.Size = new System.Drawing.Size(30, 20);
			this.quantityTextBox.Location = new System.Drawing.Point(130, 0);

			//Initialize Price TextBox
			this.priceTextBox.Size = new System.Drawing.Size(40, 20);
			this.priceTextBox.Location = new System.Drawing.Point(160, 0);

			//Initialize Discount TextBox
			this.discountTextBox.Size = new System.Drawing.Size(30, 20);
			this.discountTextBox.Location = new System.Drawing.Point(200, 0);
			this.discountTextBox.Text = "0";

			//Add controls to the Controls collection
			this.Controls.Add(this.productComboBox);
			this.Controls.Add(this.quantityTextBox);
			this.Controls.Add(this.priceTextBox);
			this.Controls.Add(this.discountTextBox);

			this.Size = new System.Drawing.Size(238, 20);
		}

		protected override void Dispose( bool disposing ) 
		{
			if ( disposing ) 
			{
				if (! (components == null) ) 
				{
					components.Dispose();
				}
			}
			base.Dispose(disposing);
		}

		#region Component Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
		}
		#endregion

		public string  ProductID  
		{
			get 
			{
				return productComboBox.SelectedValue.ToString();
			}
			set 
			{
				productComboBox.SelectedValue = value;
			}
		}

		public string  OrderQuantity  
		{
			get 
			{
				return quantityTextBox.Text;
			}
			set 
			{
				quantityTextBox.Text = value;
			}
		}

		public string  OrderPrice  
		{
			get 
			{
				return priceTextBox.Text;
			}
			set 
			{
				priceTextBox.Text = value;
			}
		}

		public string  OrderDiscount  
		{
			get 
			{
				return discountTextBox.Text;
			}
			set 
			{
				discountTextBox.Text = value;
			}
		}
	}
}

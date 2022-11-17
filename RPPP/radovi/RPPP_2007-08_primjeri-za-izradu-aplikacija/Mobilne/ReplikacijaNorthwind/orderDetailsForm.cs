using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;
using System.Data.SqlServerCe;

namespace NorthwindCE_2556
{
	/// <summary>
	/// Summary description for orderDetailsForm.
	/// </summary>
	public class orderDetailsForm : System.Windows.Forms.Form
	{
		internal System.Windows.Forms.Button backButton;
	
		private int localOrderID;
		private SqlCeDataAdapter daOrderDetails;
		private System.Windows.Forms.DataGrid orderDetailsDataGrid = null;

		public orderDetailsForm()
		{
			//
			// Required for Windows Form Designer support
			//
			InitializeComponent();
		}

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		protected override void Dispose( bool disposing )
		{
			base.Dispose( disposing );
		}

		#region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.backButton = new System.Windows.Forms.Button();
			// 
			// backButton
			// 
			this.backButton.Font = new System.Drawing.Font("Tahoma", 9F, System.Drawing.FontStyle.Regular);
			this.backButton.Location = new System.Drawing.Point(84, 216);
			this.backButton.Text = "Back";
			this.backButton.Click += new System.EventHandler(this.backButton_Click);
			// 
			// orderDetailsForm
			// 
			this.Controls.Add(this.backButton);
			this.Text = "orderDetailsForm";

		}
		#endregion

		public int OrderID  
		{
			get 
			{
				return localOrderID;
			}
			set 
			{
				localOrderID = value;
			}
		}

		public void PopulateOrderDetails() 
		{
			//PopulateOrderDetails() populates the Orders Details table in the dataset and binds data to the controls.
			//Starts the cursor icon and blocks the UI since this procedure may take some time.
			System.Windows.Forms.Cursor.Current = System.Windows.Forms.Cursors.WaitCursor;
			//Get an instance of the dataset.
			DataSet dsNorthwind = NorthwindData.GetInstance().NorthwindDataSet;
			DataTable dtOrderDetails = null;

			try 
			{
				//Determine if the daOrderDetails SqlCeDataAdapter needs to be initialized. This will execute only the first time the PopulateOrderDetails() procedure is executed.
				if ( daOrderDetails == null ) 
				{
					SqlCeConnection cnNorthwind = NorthwindData.GetInstance().NorthwindConnection;
					daOrderDetails = new SqlCeDataAdapter("SELECT ProductName, OrderID, Quantity, " +
						"\"Order Details\"" +
						".UnitPrice, Discount " +
						"FROM " +
						"\"Order Details\"" +
						" INNER JOIN Products on " +
						"\"Order Details\"" +
						".ProductID = Products.ProductID WHERE OrderID = ?",
						cnNorthwind);
					//Define the parameter for the query.
					daOrderDetails.SelectCommand.Parameters.Add("@OrderID", localOrderID);
				}

				dtOrderDetails = dsNorthwind.Tables["OrderDetails"];
				//Determine if the dtOrderDetails DataTable needs to be populated and the controls need to be bound to data.
				if ( dtOrderDetails == null ) 
				{
					daOrderDetails.Fill(dsNorthwind, "OrderDetails");
					dtOrderDetails = dsNorthwind.Tables["OrderDetails"];
					orderDetailsDataGrid = new System.Windows.Forms.DataGrid();
					this.Controls.Add(orderDetailsDataGrid);
					orderDetailsDataGrid.DataSource = dtOrderDetails;
				} 
				else 
				{
					//if the table exists, clear it and then repopulate it.
					daOrderDetails.SelectCommand.Parameters["@OrderID"].Value = localOrderID.ToString();
					dtOrderDetails.Clear();
					daOrderDetails.Fill(dsNorthwind, "OrderDetails");
				}

			} 
			catch (SqlCeException sqlExp) 
			{
				//Pass the SqlException to the centralized error handling procedure in the NorthwindData class.
				NorthwindData.ShowErrors(sqlExp);
			} 
			catch (Exception exp) 
			{
				//Display general Exception information.
				MessageBox.Show(exp.Message, "Northwind");
			}
			//return UI control back to the user.
			System.Windows.Forms.Cursor.Current = System.Windows.Forms.Cursors.Default;
		}

		private void backButton_Click(object sender, System.EventArgs e)
		{
			this.Hide();
		}
	}
}

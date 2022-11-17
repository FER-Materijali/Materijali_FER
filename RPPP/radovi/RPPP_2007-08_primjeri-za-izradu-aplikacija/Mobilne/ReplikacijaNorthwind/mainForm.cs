using System;
using System.Drawing;
using System.Collections;
using System.Windows.Forms;
using System.Data;
using System.ComponentModel;
using System.IO;
using System.Data.SqlServerCe;
using System.Data.SqlTypes;

namespace NorthwindCE_2556
{
	/// <summary>
	/// Summary description for mainForm.
	/// </summary>
	public class mainForm : System.Windows.Forms.Form
	{
		private System.Windows.Forms.TabControl northwindDataTabControl;
		private System.Windows.Forms.TabPage connectionTabPage;
		private System.Windows.Forms.Button connectButton;
		private System.Windows.Forms.TextBox urlTextBox;
		private System.Windows.Forms.TextBox passwordTextBox;
		private System.Windows.Forms.Label urlLabel;
		private System.Windows.Forms.Label passwordLabel;
		private System.Windows.Forms.TextBox userIDTextBox;
		private System.Windows.Forms.Label userIDLabel;
		private System.Windows.Forms.TextBox publisherTextBox;
		private System.Windows.Forms.Label publisherLabel;
		private System.Windows.Forms.RadioButton windowsRadioButton;
		private System.Windows.Forms.RadioButton sqlAuthRadioButton;
		private System.Windows.Forms.Label authenticationLabel;
		private System.Windows.Forms.TabPage customersTabPage;
		private System.Windows.Forms.TextBox faxTextBox;
		private System.Windows.Forms.TextBox phoneTextBox;
		private System.Windows.Forms.TextBox postalTextBox;
		private System.Windows.Forms.TextBox cityTextBox;
		private System.Windows.Forms.TextBox addressTextBox;
		private System.Windows.Forms.TextBox contactTextBox;
		private System.Windows.Forms.Label faxLabel;
		private System.Windows.Forms.Label phoneLabel;
		private System.Windows.Forms.Label postalLabel;
		private System.Windows.Forms.Label cityLabel;
		private System.Windows.Forms.Label AddressLabel;
		private System.Windows.Forms.Label contactLabel;
		private System.Windows.Forms.Label companyLabel;
		private System.Windows.Forms.ComboBox companyComboBox;
		private System.Windows.Forms.TabPage productsTabPage;
		private System.Windows.Forms.TabPage ordersTabPage;
		private System.Windows.Forms.Label Label1;
		private System.Windows.Forms.TabPage newOrdersTabPage;
		private System.Windows.Forms.Label currentCustomerLabel;
		private System.Windows.Forms.Label discountLabel;
		private System.Windows.Forms.Label priceLabel;
		private System.Windows.Forms.Label quantityLabel;
		private System.Windows.Forms.Label productLabel;
		private System.Windows.Forms.MainMenu mainMenu;
		private System.Windows.Forms.MenuItem fileMenuItem;
		private System.Windows.Forms.MenuItem exitMenuItem;
		private System.Windows.Forms.MenuItem lineMenuItem;
		private System.Windows.Forms.MenuItem saveMenuItem;
		private System.Windows.Forms.MenuItem cancelMenuItem;
		private System.Windows.Forms.MenuItem editMenuItem;
		private System.Windows.Forms.MenuItem newMenuItem;

		//The NorthwindData class contains information and objects to work with local data, including a SqlCEConnection,
		//a dataset, connection strings, and data error handling. Separating the data and data logic as a separate class from the 
		//form is a good design practice.  
		private NorthwindData dataNorthwind = null;
		//publisherDatabase stores that name of the SQL 2000 database we are subscribing to.
		private string  publisherDatabase;
		//publication is the name of the publication we are subscribing to.
		private string  publication;
		//existsSettings is a flag that determines if the synchronization settings entered by the user are saved in the local CE database.
		private bool existsSettings;
		//daCustomers, daProducts, daOrders, daOrderDetails are form level SqlCeDataAdapters that are used by different functions to read and 
		//write to the local Customers, Products, Orders, and Order Details tables in the CE database. The existence of these objects is also used 
		//to determine if the tables is initialized. 
		private SqlCeDataAdapter daCustomers = null;
		private SqlCeDataAdapter daProducts = null;
		private SqlCeDataAdapter daOrders = null;
		//ordersDataGrid is a DataGrid that responds to the Click event. Therefore we need to declare it as a form level variable using 
		//the WithEvents keyword.
		private System.Windows.Forms.DataGrid ordersDataGrid = null;
		//frmOrderDetails is a form that displays the details of an order.
		private orderDetailsForm frmOrderDetails = null;
		//verticalAxis is a form level value that stores the vertical position for the current OrderItemControl. Each time a new OrderItemControl is 
		//added to the form, this value is incremented so the control is located below the prior control.
		private int verticalAxis;
		//newOrderItemInitialized is a flag that determines if an OrderItemControl was added to the form.
		private bool newOrderItemInitialized = false;
		//productValuesArray is an form level ArrayList that is initially populated with data from the local CE Products table using a SqlCeDataReader.
		//productValuesArray is cloned each time an OrderItemControl is added to the form to provide the control with a unique data source to 
		//bind to. 
		private ArrayList productValuesArray = null;
		//publisher_CustomerChanges, publisher_ProductChanges, and publisher_OrderChanges are flags that identify if there where changes replicated to the 
		//local CE database from the SQL 2000 publisher when the last synchronization occurred. These values are used to determine if the tables in the local 
		//dataset need to be refreshed.
		private bool publisher_CustomerChanges = false;
		private bool publisher_ProductChanges = false;
		private bool publisher_OrderChanges = false;
		//components is required by the designer
		private System.ComponentModel.Container components = null;

		public mainForm()
		{
			//TODO: Initialize the names of the SQL 2000 database and the publication.
			//Make sure these values coincide with the database and publication you are subscribing to. 
			//if you completed Exercise 1, set publisherDatabase = "Northwind" and   publication = "NorthwindPub".
			//if you did NOT complete Exercise 1, set publisherDatabase = "Nwind_SQLCE" and publication = "SQLCEReplDemoNet".
			publication = "NorthwindPublication";
			publisherDatabase = "Northwind";
			//Get a northwind data object.       
			dataNorthwind = NorthwindData.GetInstance();
			if ( dataNorthwind == null ) 
			{
				MessageBox.Show("Unable to get northwind data object", "Northwind");
				return;
			}
			// Starts the cursor icon and blocks the UI since this function may take some time.
			System.Windows.Forms.Cursor.Current = System.Windows.Forms.Cursors.WaitCursor;
			// Required for Windows Form Designer support
			InitializeComponent();
			//InitReplSync() attempts to read subscription details from the local SQL CE database if they exist
			//and sets default values if the database does not exist
			InitReplSync();
			//This returns the cursor to Default and free the UI.
			System.Windows.Forms.Cursor.Current = System.Windows.Forms.Cursors.Default;
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
      this.northwindDataTabControl = new System.Windows.Forms.TabControl();
      this.connectionTabPage = new System.Windows.Forms.TabPage();
      this.connectButton = new System.Windows.Forms.Button();
      this.urlTextBox = new System.Windows.Forms.TextBox();
      this.passwordTextBox = new System.Windows.Forms.TextBox();
      this.urlLabel = new System.Windows.Forms.Label();
      this.passwordLabel = new System.Windows.Forms.Label();
      this.userIDTextBox = new System.Windows.Forms.TextBox();
      this.userIDLabel = new System.Windows.Forms.Label();
      this.publisherTextBox = new System.Windows.Forms.TextBox();
      this.publisherLabel = new System.Windows.Forms.Label();
      this.windowsRadioButton = new System.Windows.Forms.RadioButton();
      this.sqlAuthRadioButton = new System.Windows.Forms.RadioButton();
      this.authenticationLabel = new System.Windows.Forms.Label();
      this.customersTabPage = new System.Windows.Forms.TabPage();
      this.faxTextBox = new System.Windows.Forms.TextBox();
      this.phoneTextBox = new System.Windows.Forms.TextBox();
      this.postalTextBox = new System.Windows.Forms.TextBox();
      this.cityTextBox = new System.Windows.Forms.TextBox();
      this.addressTextBox = new System.Windows.Forms.TextBox();
      this.contactTextBox = new System.Windows.Forms.TextBox();
      this.faxLabel = new System.Windows.Forms.Label();
      this.phoneLabel = new System.Windows.Forms.Label();
      this.postalLabel = new System.Windows.Forms.Label();
      this.cityLabel = new System.Windows.Forms.Label();
      this.AddressLabel = new System.Windows.Forms.Label();
      this.contactLabel = new System.Windows.Forms.Label();
      this.companyLabel = new System.Windows.Forms.Label();
      this.companyComboBox = new System.Windows.Forms.ComboBox();
      this.productsTabPage = new System.Windows.Forms.TabPage();
      this.ordersTabPage = new System.Windows.Forms.TabPage();
      this.Label1 = new System.Windows.Forms.Label();
      this.newOrdersTabPage = new System.Windows.Forms.TabPage();
      this.currentCustomerLabel = new System.Windows.Forms.Label();
      this.discountLabel = new System.Windows.Forms.Label();
      this.priceLabel = new System.Windows.Forms.Label();
      this.quantityLabel = new System.Windows.Forms.Label();
      this.productLabel = new System.Windows.Forms.Label();
      this.mainMenu = new System.Windows.Forms.MainMenu();
      this.fileMenuItem = new System.Windows.Forms.MenuItem();
      this.exitMenuItem = new System.Windows.Forms.MenuItem();
      this.lineMenuItem = new System.Windows.Forms.MenuItem();
      this.saveMenuItem = new System.Windows.Forms.MenuItem();
      this.cancelMenuItem = new System.Windows.Forms.MenuItem();
      this.editMenuItem = new System.Windows.Forms.MenuItem();
      this.newMenuItem = new System.Windows.Forms.MenuItem();
      this.northwindDataTabControl.SuspendLayout();
      this.connectionTabPage.SuspendLayout();
      this.customersTabPage.SuspendLayout();
      this.ordersTabPage.SuspendLayout();
      this.newOrdersTabPage.SuspendLayout();
      this.SuspendLayout();
      // 
      // northwindDataTabControl
      // 
      this.northwindDataTabControl.Controls.Add(this.connectionTabPage);
      this.northwindDataTabControl.Controls.Add(this.customersTabPage);
      this.northwindDataTabControl.Controls.Add(this.productsTabPage);
      this.northwindDataTabControl.Controls.Add(this.ordersTabPage);
      this.northwindDataTabControl.Controls.Add(this.newOrdersTabPage);
      this.northwindDataTabControl.Location = new System.Drawing.Point(0, 0);
      this.northwindDataTabControl.Name = "northwindDataTabControl";
      this.northwindDataTabControl.SelectedIndex = 0;
      this.northwindDataTabControl.Size = new System.Drawing.Size(240, 192);
      this.northwindDataTabControl.TabIndex = 0;
      this.northwindDataTabControl.SelectedIndexChanged += new System.EventHandler(this.northwindDataTabControl_SelectedIndexChanged);
      // 
      // connectionTabPage
      // 
      this.connectionTabPage.Controls.Add(this.connectButton);
      this.connectionTabPage.Controls.Add(this.urlTextBox);
      this.connectionTabPage.Controls.Add(this.passwordTextBox);
      this.connectionTabPage.Controls.Add(this.urlLabel);
      this.connectionTabPage.Controls.Add(this.passwordLabel);
      this.connectionTabPage.Controls.Add(this.userIDTextBox);
      this.connectionTabPage.Controls.Add(this.userIDLabel);
      this.connectionTabPage.Controls.Add(this.publisherTextBox);
      this.connectionTabPage.Controls.Add(this.publisherLabel);
      this.connectionTabPage.Controls.Add(this.windowsRadioButton);
      this.connectionTabPage.Controls.Add(this.sqlAuthRadioButton);
      this.connectionTabPage.Controls.Add(this.authenticationLabel);
      this.connectionTabPage.Location = new System.Drawing.Point(0, 0);
      this.connectionTabPage.Name = "connectionTabPage";
      this.connectionTabPage.Size = new System.Drawing.Size(240, 169);
      this.connectionTabPage.Text = "Connection";
      // 
      // connectButton
      // 
      this.connectButton.Location = new System.Drawing.Point(84, 136);
      this.connectButton.Name = "connectButton";
      this.connectButton.Size = new System.Drawing.Size(64, 22);
      this.connectButton.TabIndex = 0;
      this.connectButton.Text = "Connect";
      this.connectButton.Click += new System.EventHandler(this.connectButton_Click);
      // 
      // urlTextBox
      // 
      this.urlTextBox.Location = new System.Drawing.Point(72, 108);
      this.urlTextBox.Name = "urlTextBox";
      this.urlTextBox.Size = new System.Drawing.Size(144, 21);
      this.urlTextBox.TabIndex = 1;
      this.urlTextBox.Text = "http://IVANA-ZPR/SQLME/sqlcesa35.dll";
      // 
      // passwordTextBox
      // 
      this.passwordTextBox.Location = new System.Drawing.Point(72, 80);
      this.passwordTextBox.Name = "passwordTextBox";
      this.passwordTextBox.Size = new System.Drawing.Size(144, 21);
      this.passwordTextBox.TabIndex = 2;
      this.passwordTextBox.Text = "root12345";
      // 
      // urlLabel
      // 
      this.urlLabel.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Bold);
      this.urlLabel.Location = new System.Drawing.Point(6, 112);
      this.urlLabel.Name = "urlLabel";
      this.urlLabel.Size = new System.Drawing.Size(32, 20);
      this.urlLabel.Text = "URL";
      // 
      // passwordLabel
      // 
      this.passwordLabel.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Bold);
      this.passwordLabel.Location = new System.Drawing.Point(6, 84);
      this.passwordLabel.Name = "passwordLabel";
      this.passwordLabel.Size = new System.Drawing.Size(64, 20);
      this.passwordLabel.Text = "Password";
      // 
      // userIDTextBox
      // 
      this.userIDTextBox.Location = new System.Drawing.Point(72, 54);
      this.userIDTextBox.Name = "userIDTextBox";
      this.userIDTextBox.Size = new System.Drawing.Size(144, 21);
      this.userIDTextBox.TabIndex = 5;
      this.userIDTextBox.Text = "sa";
      // 
      // userIDLabel
      // 
      this.userIDLabel.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Bold);
      this.userIDLabel.Location = new System.Drawing.Point(6, 60);
      this.userIDLabel.Name = "userIDLabel";
      this.userIDLabel.Size = new System.Drawing.Size(48, 20);
      this.userIDLabel.Text = "User ID";
      // 
      // publisherTextBox
      // 
      this.publisherTextBox.Location = new System.Drawing.Point(72, 28);
      this.publisherTextBox.Name = "publisherTextBox";
      this.publisherTextBox.Size = new System.Drawing.Size(144, 21);
      this.publisherTextBox.TabIndex = 7;
      this.publisherTextBox.Text = "IVANA-ZPR\\IVANA";
      // 
      // publisherLabel
      // 
      this.publisherLabel.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Bold);
      this.publisherLabel.Location = new System.Drawing.Point(6, 32);
      this.publisherLabel.Name = "publisherLabel";
      this.publisherLabel.Size = new System.Drawing.Size(64, 20);
      this.publisherLabel.Text = "Publisher";
      // 
      // windowsRadioButton
      // 
      this.windowsRadioButton.Location = new System.Drawing.Point(152, 8);
      this.windowsRadioButton.Name = "windowsRadioButton";
      this.windowsRadioButton.Size = new System.Drawing.Size(72, 20);
      this.windowsRadioButton.TabIndex = 9;
      this.windowsRadioButton.Text = "Windows";
      // 
      // sqlAuthRadioButton
      // 
      this.sqlAuthRadioButton.Checked = true;
      this.sqlAuthRadioButton.Location = new System.Drawing.Point(104, 8);
      this.sqlAuthRadioButton.Name = "sqlAuthRadioButton";
      this.sqlAuthRadioButton.Size = new System.Drawing.Size(48, 20);
      this.sqlAuthRadioButton.TabIndex = 10;
      this.sqlAuthRadioButton.Text = "SQL";
      // 
      // authenticationLabel
      // 
      this.authenticationLabel.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Bold);
      this.authenticationLabel.Location = new System.Drawing.Point(6, 10);
      this.authenticationLabel.Name = "authenticationLabel";
      this.authenticationLabel.Size = new System.Drawing.Size(88, 16);
      this.authenticationLabel.Text = "Authentication";
      // 
      // customersTabPage
      // 
      this.customersTabPage.Controls.Add(this.faxTextBox);
      this.customersTabPage.Controls.Add(this.phoneTextBox);
      this.customersTabPage.Controls.Add(this.postalTextBox);
      this.customersTabPage.Controls.Add(this.cityTextBox);
      this.customersTabPage.Controls.Add(this.addressTextBox);
      this.customersTabPage.Controls.Add(this.contactTextBox);
      this.customersTabPage.Controls.Add(this.faxLabel);
      this.customersTabPage.Controls.Add(this.phoneLabel);
      this.customersTabPage.Controls.Add(this.postalLabel);
      this.customersTabPage.Controls.Add(this.cityLabel);
      this.customersTabPage.Controls.Add(this.AddressLabel);
      this.customersTabPage.Controls.Add(this.contactLabel);
      this.customersTabPage.Controls.Add(this.companyLabel);
      this.customersTabPage.Controls.Add(this.companyComboBox);
      this.customersTabPage.Location = new System.Drawing.Point(0, 0);
      this.customersTabPage.Name = "customersTabPage";
      this.customersTabPage.Size = new System.Drawing.Size(232, 166);
      this.customersTabPage.Text = "Customers";
      // 
      // faxTextBox
      // 
      this.faxTextBox.Enabled = false;
      this.faxTextBox.Location = new System.Drawing.Point(40, 138);
      this.faxTextBox.Name = "faxTextBox";
      this.faxTextBox.Size = new System.Drawing.Size(88, 21);
      this.faxTextBox.TabIndex = 0;
      // 
      // phoneTextBox
      // 
      this.phoneTextBox.Enabled = false;
      this.phoneTextBox.Location = new System.Drawing.Point(40, 112);
      this.phoneTextBox.Name = "phoneTextBox";
      this.phoneTextBox.Size = new System.Drawing.Size(88, 21);
      this.phoneTextBox.TabIndex = 1;
      // 
      // postalTextBox
      // 
      this.postalTextBox.Enabled = false;
      this.postalTextBox.Location = new System.Drawing.Point(150, 88);
      this.postalTextBox.Name = "postalTextBox";
      this.postalTextBox.Size = new System.Drawing.Size(74, 21);
      this.postalTextBox.TabIndex = 2;
      // 
      // cityTextBox
      // 
      this.cityTextBox.Enabled = false;
      this.cityTextBox.Location = new System.Drawing.Point(26, 88);
      this.cityTextBox.Name = "cityTextBox";
      this.cityTextBox.Size = new System.Drawing.Size(86, 21);
      this.cityTextBox.TabIndex = 3;
      // 
      // addressTextBox
      // 
      this.addressTextBox.Enabled = false;
      this.addressTextBox.Location = new System.Drawing.Point(56, 54);
      this.addressTextBox.Multiline = true;
      this.addressTextBox.Name = "addressTextBox";
      this.addressTextBox.Size = new System.Drawing.Size(168, 32);
      this.addressTextBox.TabIndex = 4;
      // 
      // contactTextBox
      // 
      this.contactTextBox.Enabled = false;
      this.contactTextBox.Location = new System.Drawing.Point(56, 28);
      this.contactTextBox.Name = "contactTextBox";
      this.contactTextBox.Size = new System.Drawing.Size(168, 21);
      this.contactTextBox.TabIndex = 5;
      // 
      // faxLabel
      // 
      this.faxLabel.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Bold);
      this.faxLabel.Location = new System.Drawing.Point(8, 138);
      this.faxLabel.Name = "faxLabel";
      this.faxLabel.Size = new System.Drawing.Size(24, 20);
      this.faxLabel.Text = "Fax";
      // 
      // phoneLabel
      // 
      this.phoneLabel.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Bold);
      this.phoneLabel.Location = new System.Drawing.Point(2, 112);
      this.phoneLabel.Name = "phoneLabel";
      this.phoneLabel.Size = new System.Drawing.Size(44, 20);
      this.phoneLabel.Text = "Phone";
      // 
      // postalLabel
      // 
      this.postalLabel.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Bold);
      this.postalLabel.Location = new System.Drawing.Point(112, 88);
      this.postalLabel.Name = "postalLabel";
      this.postalLabel.Size = new System.Drawing.Size(48, 20);
      this.postalLabel.Text = "Postal";
      // 
      // cityLabel
      // 
      this.cityLabel.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Bold);
      this.cityLabel.Location = new System.Drawing.Point(2, 88);
      this.cityLabel.Name = "cityLabel";
      this.cityLabel.Size = new System.Drawing.Size(30, 20);
      this.cityLabel.Text = "City";
      // 
      // AddressLabel
      // 
      this.AddressLabel.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Bold);
      this.AddressLabel.Location = new System.Drawing.Point(2, 54);
      this.AddressLabel.Name = "AddressLabel";
      this.AddressLabel.Size = new System.Drawing.Size(54, 20);
      this.AddressLabel.Text = "Address";
      // 
      // contactLabel
      // 
      this.contactLabel.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Bold);
      this.contactLabel.Location = new System.Drawing.Point(2, 28);
      this.contactLabel.Name = "contactLabel";
      this.contactLabel.Size = new System.Drawing.Size(52, 20);
      this.contactLabel.Text = "Contact";
      // 
      // companyLabel
      // 
      this.companyLabel.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Bold);
      this.companyLabel.Location = new System.Drawing.Point(2, 6);
      this.companyLabel.Name = "companyLabel";
      this.companyLabel.Size = new System.Drawing.Size(57, 20);
      this.companyLabel.Text = "Company";
      // 
      // companyComboBox
      // 
      this.companyComboBox.Location = new System.Drawing.Point(59, 4);
      this.companyComboBox.Name = "companyComboBox";
      this.companyComboBox.Size = new System.Drawing.Size(166, 22);
      this.companyComboBox.TabIndex = 13;
      this.companyComboBox.SelectedIndexChanged += new System.EventHandler(this.companyComboBox_SelectedIndexChanged);
      // 
      // productsTabPage
      // 
      this.productsTabPage.Location = new System.Drawing.Point(0, 0);
      this.productsTabPage.Name = "productsTabPage";
      this.productsTabPage.Size = new System.Drawing.Size(232, 166);
      this.productsTabPage.Text = "Products";
      // 
      // ordersTabPage
      // 
      this.ordersTabPage.Controls.Add(this.Label1);
      this.ordersTabPage.Location = new System.Drawing.Point(0, 0);
      this.ordersTabPage.Name = "ordersTabPage";
      this.ordersTabPage.Size = new System.Drawing.Size(232, 166);
      this.ordersTabPage.Text = "Orders";
      // 
      // Label1
      // 
      this.Label1.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Bold);
      this.Label1.Location = new System.Drawing.Point(2, 6);
      this.Label1.Name = "Label1";
      this.Label1.Size = new System.Drawing.Size(57, 13);
      this.Label1.Text = "Company";
      // 
      // newOrdersTabPage
      // 
      this.newOrdersTabPage.Controls.Add(this.currentCustomerLabel);
      this.newOrdersTabPage.Controls.Add(this.discountLabel);
      this.newOrdersTabPage.Controls.Add(this.priceLabel);
      this.newOrdersTabPage.Controls.Add(this.quantityLabel);
      this.newOrdersTabPage.Controls.Add(this.productLabel);
      this.newOrdersTabPage.Location = new System.Drawing.Point(0, 0);
      this.newOrdersTabPage.Name = "newOrdersTabPage";
      this.newOrdersTabPage.Size = new System.Drawing.Size(232, 166);
      this.newOrdersTabPage.Text = "New Orders";
      // 
      // currentCustomerLabel
      // 
      this.currentCustomerLabel.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Regular);
      this.currentCustomerLabel.ForeColor = System.Drawing.Color.Red;
      this.currentCustomerLabel.Location = new System.Drawing.Point(12, 144);
      this.currentCustomerLabel.Name = "currentCustomerLabel";
      this.currentCustomerLabel.Size = new System.Drawing.Size(208, 20);
      this.currentCustomerLabel.Text = "Select customer before creating orders";
      this.currentCustomerLabel.TextAlign = System.Drawing.ContentAlignment.TopCenter;
      // 
      // discountLabel
      // 
      this.discountLabel.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Regular);
      this.discountLabel.Location = new System.Drawing.Point(188, 2);
      this.discountLabel.Name = "discountLabel";
      this.discountLabel.Size = new System.Drawing.Size(48, 16);
      this.discountLabel.Text = "Discount";
      // 
      // priceLabel
      // 
      this.priceLabel.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Regular);
      this.priceLabel.Location = new System.Drawing.Point(164, 2);
      this.priceLabel.Name = "priceLabel";
      this.priceLabel.Size = new System.Drawing.Size(32, 16);
      this.priceLabel.Text = "Price";
      // 
      // quantityLabel
      // 
      this.quantityLabel.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Regular);
      this.quantityLabel.Location = new System.Drawing.Point(120, 2);
      this.quantityLabel.Name = "quantityLabel";
      this.quantityLabel.Size = new System.Drawing.Size(48, 20);
      this.quantityLabel.Text = "Quantity";
      // 
      // productLabel
      // 
      this.productLabel.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Regular);
      this.productLabel.Location = new System.Drawing.Point(32, 2);
      this.productLabel.Name = "productLabel";
      this.productLabel.Size = new System.Drawing.Size(48, 20);
      this.productLabel.Text = "Product";
      // 
      // mainMenu
      // 
      this.mainMenu.MenuItems.Add(this.fileMenuItem);
      // 
      // fileMenuItem
      // 
      this.fileMenuItem.MenuItems.Add(this.exitMenuItem);
      this.fileMenuItem.MenuItems.Add(this.lineMenuItem);
      this.fileMenuItem.MenuItems.Add(this.saveMenuItem);
      this.fileMenuItem.MenuItems.Add(this.cancelMenuItem);
      this.fileMenuItem.MenuItems.Add(this.editMenuItem);
      this.fileMenuItem.MenuItems.Add(this.newMenuItem);
      this.fileMenuItem.Text = "File";
      // 
      // exitMenuItem
      // 
      this.exitMenuItem.Text = "Exit";
      this.exitMenuItem.Click += new System.EventHandler(this.exitMenuItem_Click);
      // 
      // lineMenuItem
      // 
      this.lineMenuItem.Text = "-";
      // 
      // saveMenuItem
      // 
      this.saveMenuItem.Text = "Save";
      this.saveMenuItem.Click += new System.EventHandler(this.saveMenuItem_Click);
      // 
      // cancelMenuItem
      // 
      this.cancelMenuItem.Text = "Cancel";
      this.cancelMenuItem.Click += new System.EventHandler(this.cancelMenuItem_Click);
      // 
      // editMenuItem
      // 
      this.editMenuItem.Enabled = false;
      this.editMenuItem.Text = "Edit";
      this.editMenuItem.Click += new System.EventHandler(this.editMenuItem_Click);
      // 
      // newMenuItem
      // 
      this.newMenuItem.Enabled = false;
      this.newMenuItem.Text = "New";
      this.newMenuItem.Click += new System.EventHandler(this.newMenuItem_Click);
      // 
      // mainForm
      // 
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Inherit;
      this.ClientSize = new System.Drawing.Size(240, 268);
      this.Controls.Add(this.northwindDataTabControl);
      this.Menu = this.mainMenu;
      this.Name = "mainForm";
      this.Text = "Northwind Data";
      this.northwindDataTabControl.ResumeLayout(false);
      this.connectionTabPage.ResumeLayout(false);
      this.customersTabPage.ResumeLayout(false);
      this.ordersTabPage.ResumeLayout(false);
      this.newOrdersTabPage.ResumeLayout(false);
      this.ResumeLayout(false);

		}
		#endregion

		/// <summary>
		/// The main entry point for the application.
		/// </summary>

		static void Main() 
		{
			Application.Run(new mainForm());
		}

		private void InitReplSync() 
		{
			//InitReplSync() attempts to read subscription details from the local SQL CE database if they exist.
			try 
			{
				//This will execute only if the database exists.
				if ( File.Exists(dataNorthwind.LocalDatabaseFile) ) 
				{
					//Open connection to the Northwind database.
					if ( ConnectionState.Closed == dataNorthwind.NorthwindConnection.State ) 
					{
						dataNorthwind.NorthwindConnection.Open();
					}
					//Loads the connection information.
					LoadAppProps();
					//existsSettings is a global initialization flag that determines if the ApplicationProperties table exists in the local CE database. 
					//Set existsSettings to true, the ApplicationProperties table exists.
					existsSettings = true;
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

		} //InitReplSync()

		private void ReplSync() 
		{
      
			//ReplSync() synchronizes the local CE database with SQL Server 2000 through the existing publication.
			//Starts the cursor icon and blocks the UI since this function may take some time.
			System.Windows.Forms.Cursor.Current = System.Windows.Forms.Cursors.WaitCursor;
			//Create a SqlCEReplication object.
			SqlCeReplication  replNorthwind = new SqlCeReplication();
			//Set InternetUrl to the URL of the virtual directory that exposes the SQL CE Server Agent.    
			replNorthwind.InternetUrl = urlTextBox.Text;
			//Set Publisher to the name of the SQL 2000 server.
			replNorthwind.Publisher = publisherTextBox.Text;
			//Set PublisherDatabase to the name of the database.
			replNorthwind.PublisherDatabase = publisherDatabase;
			//Set Publication to the name of the publication we are subscribing to.
			replNorthwind.Publication = publication;
			//Set the authentication type, SQL or Windows authentication.
			if ( sqlAuthRadioButton.Checked ) 
			{
				replNorthwind.PublisherSecurityMode = SecurityType.DBAuthentication;
			} 
			else 
			{
				replNorthwind.PublisherSecurityMode = SecurityType.NTAuthentication;
			}
			//Set the user information.
			replNorthwind.PublisherLogin = userIDTextBox.Text;
			replNorthwind.PublisherPassword = passwordTextBox.Text;
			//Set SubscriberConnectionString to the path of the local CE database to be synchronized.
			replNorthwind.SubscriberConnectionString = dataNorthwind.LocalConnString;
			//We are going to hard code the user as Janet Leverling. Normally we could capture the 
			//user information and dynamically generate the subscriber name
			replNorthwind.Subscriber = "JLeverling CE Device";

			try 
			{
				//if the local CE database does not exists, create it.
				if (! File.Exists(dataNorthwind.LocalDatabaseFile) ) 
				{
					replNorthwind.AddSubscription(AddOption.CreateDatabase);
				}
				//if there is an open connection to the database, the synchronization will fail. Ensure the connection is closed.
				if ( dataNorthwind.NorthwindConnection.State == ConnectionState.Open ) 
				{
					dataNorthwind.NorthwindConnection.Close();
				}
				// Synchronize to the server database to populate the Subscription.
				replNorthwind.Synchronize();
				// Display the synchronization results.
				MessageBox.Show("Synchronization Complete:\nPublisher changes = " + replNorthwind.PublisherChanges.ToString() + "\nPublisher conflicts = " + replNorthwind.PublisherConflicts.ToString() + "\nSubscriber changes = " + replNorthwind.SubscriberChanges.ToString(),
					"Northwind",
					MessageBoxButtons.OK,
					MessageBoxIcon.Asterisk,
					MessageBoxDefaultButton.Button1);
				//Save the synchronization settings entered by the user.
				SaveAppProps();
				//if there were any changes, then set the publisher_CustomerChanges, publisher_ProductChanges, and publisher_OrderChanges flags
				//to true so the dataset will be updated.
				if ( (replNorthwind.PublisherChanges > 0) || (replNorthwind.PublisherConflicts > 0) || (replNorthwind.SubscriberChanges > 0) ) 
				{
					publisher_CustomerChanges = true;
					publisher_ProductChanges = true;
					publisher_OrderChanges = true;
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
			finally 
			{
				// Dispose of the Replication object.
				replNorthwind.Dispose();
			}
			System.Windows.Forms.Cursor.Current = System.Windows.Forms.Cursors.Default;
		} //ReplSync()

		private void LoadAppProps() 
		{
			//LoadAppProps() reads synchronization data out of the local CE ApplicationProperties table and populates controls with the values.
			//drAppProp is a SqlCeDataReader that is used to read values out of the local CE ApplicationProperties table.
			SqlCeDataReader drAppProp = null;
			//Create a SqlCeCommand object associated with the connection to NorthwindDemo database. There are many
			//different constructors and ways to initialize SqlCeCommand objects. You will see different implementations used in this application.
			SqlCeCommand cmd = dataNorthwind.NorthwindConnection.CreateCommand();
			//Define the SELECT command for SqlCeCommand. The NorthwindCE_2556 application uses Anonymous Authentication with IIS to perform synchronization.
			//The Internet user information (InternetLogin and InternetPassword) is not used by the application and is only included for completeness.
			cmd.CommandText = "SELECT InternetURL, InternetLogin, InternetPassword, Publisher, PublisherLogin, PublisherPassword, PublisherSecurityMode FROM ApplicationProperties;";
			try 
			{
				//Execute the command. if it was successful then populate the controls with the values.
				drAppProp = cmd.ExecuteReader();
				if ( drAppProp.Read() ) 
				{
					int index;
					//Get the Internet URL data.
					index = drAppProp.GetOrdinal("InternetURL");
					if (! drAppProp.IsDBNull(index) ) 
					{
						urlTextBox.Text = drAppProp.GetString(index);
					} 
					else 
					{
						urlTextBox.Text = "";
					}
					//Get the publisher data.
					index = drAppProp.GetOrdinal("Publisher");
					if (! drAppProp.IsDBNull(index) ) 
					{
						publisherTextBox.Text = drAppProp.GetString(index);
					} 
					else 
					{
						publisherTextBox.Text = "";
					}
					//Get the publisher login data.
					index = drAppProp.GetOrdinal("PublisherLogin");
					if (! drAppProp.IsDBNull(index) ) 
					{
						userIDTextBox.Text = drAppProp.GetString(index);
					} 
					else 
					{
						userIDTextBox.Text = "";
					}
					//Get the publisher password data.
					index = drAppProp.GetOrdinal("PublisherPassword");
					if (! drAppProp.IsDBNull(index) ) 
					{
						passwordTextBox.Text = drAppProp.GetString(index);
					} 
					else 
					{
						passwordTextBox.Text = "";
					}
					//Get the publisher security mode data.
					index = drAppProp.GetOrdinal("PublisherSecurityMode");
					if (! drAppProp.IsDBNull(index) ) 
					{
						if ((drAppProp.GetByte(index) == 1) ) 
						{
							sqlAuthRadioButton.Checked = true;
						} 
						else 
						{
							sqlAuthRadioButton.Checked = false;
						}
					} 
					else 
					{
						sqlAuthRadioButton.Checked = true;
					}
				}
			} 
			finally 
			{
				drAppProp.Close();
			}

		} //LoadAppProps()


		private void PopulateCustomers() 
		{
			//PopulateCustomers() populates the Customers table in the dataset and binds the data to controls.
			//Starts the cursor icon and blocks the UI since this procedure may take some time.
			System.Windows.Forms.Cursor.Current = System.Windows.Forms.Cursors.WaitCursor;
			//Get an instance of the dataset
			DataSet dsNorthwind = NorthwindData.GetInstance().NorthwindDataSet;
			DataTable dtCustomers;
			try 
			{
				//Determine if the daCustomers SqlCeDataAdapter needs to be initialized. This will execute only the first time the PopulateCustomers() procedure is executed.
				if ( daCustomers == null ) 
				{
					SqlCeConnection cnNorthwind = NorthwindData.GetInstance().NorthwindConnection;
					daCustomers = new SqlCeDataAdapter("SELECT * FROM Customers ORDER BY CompanyName", cnNorthwind);
				}

				dtCustomers = dsNorthwind.Tables["Customers"];
				//Determine if the dtCustomers DataTable needs to be populated and the controls need to be bound to data.
				if ( dtCustomers == null ) 
				{
					daCustomers.Fill(dsNorthwind, "Customers");
					dtCustomers = dsNorthwind.Tables["Customers"];
					//Binds the database values to the controls. 
					companyComboBox.DataSource = dtCustomers;
					companyComboBox.DisplayMember = "CompanyName";
					companyComboBox.ValueMember = "CustomerID";
					contactTextBox.DataBindings.Add("Text", dtCustomers, "ContactName");
					addressTextBox.DataBindings.Add("Text", dtCustomers, "Address");
					cityTextBox.DataBindings.Add("Text", dtCustomers, "City");
					postalTextBox.DataBindings.Add("Text", dtCustomers, "PostalCode");
					phoneTextBox.DataBindings.Add("Text", dtCustomers, "Phone");
					faxTextBox.DataBindings.Add("Text", dtCustomers, "Fax");
				} 
				else 
				{
					//if the dtCustomers DataTable exists, determine if the last synchronization resulted in changes to the local CE database
					//and refresh the dataset to capture any new values. The publisher_CustomerChanges flag is set to true when the ReplSync()
					//procedure is executed and the local CE database is modified.
					if ( publisher_CustomerChanges == true ) 
					{
						dtCustomers.Clear();
						daCustomers.Fill(dsNorthwind, "Customers");
						publisher_CustomerChanges = false;
					}
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

		} //PopulateCustomers()

		private void PopulateProducts() 
		{
			//PopulateProducts() populates the Products table in the dataset and binds the data to the controls.
			//Starts the cursor icon and blocks the UI since this procedure may take some time.
			System.Windows.Forms.Cursor.Current = System.Windows.Forms.Cursors.WaitCursor;
			//Get an instance of the dataset
			DataSet dsNorthwind = NorthwindData.GetInstance().NorthwindDataSet;
			DataTable dtProducts = null;

			try 
			{
				//Determine if the daProducts SqlCeDataAdapter needs to be initialized. This will execute only the first time the PopulateProducts() procedure is executed.
				if ( daProducts == null ) 
				{
					SqlCeConnection cnNorthwind = NorthwindData.GetInstance().NorthwindConnection;
					daProducts = new SqlCeDataAdapter("SELECT ProductName, UnitPrice, UnitsInStock FROM Products ORDER BY ProductName", cnNorthwind);
				}

				dtProducts = dsNorthwind.Tables["Products"];
				//Determine if the dtProducts DataTable needs to be populated and the controls need to be bound to data.
				if ( dtProducts == null ) 
				{
					daProducts.Fill(dsNorthwind, "Products");
					dtProducts = dsNorthwind.Tables["Products"];
					System.Windows.Forms.DataGrid productsDataGrid = new System.Windows.Forms.DataGrid();
					productsDataGrid.Height = 170;
					productsDataGrid.Width = 240;
					productsTabPage.Controls.Add(productsDataGrid);
					productsDataGrid.DataSource = dtProducts;
				} 
				else 
				{
					//if the dtProducts DataTable exists, determine if the last synchronization resulted in changes to the local CE database
					//and refresh the dataset to capture any new values. The publisher_ProductChanges flag is set to true when the ReplSync()
					//procedure is executed and the local CE database is modified.
					if ( publisher_ProductChanges == true ) 
					{
						dtProducts.Clear();
						daProducts.Fill(dsNorthwind, "Products");
						publisher_ProductChanges = false;
					}
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

		} //PopulateProducts()

		private void PopulateOrders() 
		{
			//PopulateOrders() populates the Orders table in the dataset and binds the data to the controls.
			//Starts the cursor icon and blocks the UI since this procedure may take some time.
			System.Windows.Forms.Cursor.Current = System.Windows.Forms.Cursors.WaitCursor;
			//Get an instance of the dataset
			DataSet dsNorthwind = NorthwindData.GetInstance().NorthwindDataSet;
			DataTable dtOrders = null;

			try 
			{
				//Determine if the daCustomers SqlCeDataAdapter is initialized. 
				if ( daCustomers == null ) 
				{
					PopulateCustomers();
				}
				//Determine if the daOrders SqlCeDataAdapter needs to be initialized. This will execute only the first time the PopulateOrders() procedure is executed.
				if ( daOrders == null ) 
				{
					SqlCeConnection cnNorthwind = NorthwindData.GetInstance().NorthwindConnection;
					daOrders = new SqlCeDataAdapter("SELECT CustomerID, EmployeeID, OrderID, OrderDate, RequiredDate, ShippedDate, ShipVia, Freight FROM Orders", cnNorthwind);
				}

				dtOrders = dsNorthwind.Tables["Orders"];
				//Determine if the dtOrders DataTable needs to be populated and the controls need to be bound to data.
				if ( dtOrders == null ) 
				{
					daOrders.Fill(dsNorthwind, "Orders");
					dtOrders = dsNorthwind.Tables["Orders"];
					ordersDataGrid = new System.Windows.Forms.DataGrid();
					ordersDataGrid.Click += new System.EventHandler(ordersDataGrid_Click);
					ordersDataGrid.Location = new System.Drawing.Point(2, 32);
					ordersDataGrid.Height = 132;
					ordersDataGrid.Width = 234;
					ordersDataGrid.DataSource = dtOrders;
					//Use the SelectedValue property of the companyComboBox to set a filter on the table so the DataGrid
					//will only display Orders for the currently selected customer.
					dtOrders.DefaultView.RowFilter = "CustomerID = '" + companyComboBox.SelectedValue + "'";
					ordersTabPage.Controls.Add(ordersDataGrid);
				} 
				else 
				{
					//if the dtOrders DataTable exists, determine if the last synchronization resulted in changes to the local CE database
					//and refresh the dataset to capture any new values. The publisher_OrderChanges flag is set to true when the ReplSync()
					//procedure is executed and the local CE database is modified.
					if ( publisher_OrderChanges == true ) 
					{
						dtOrders.Clear();
						daOrders.Fill(dsNorthwind, "Orders");
						publisher_OrderChanges = false;
					}

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

		} //PopulateOrders()

		private void SaveCustomers() 
		{
			//SaveCustomers() saves the current changes to the local CE Customers table.
			//Starts the cursor icon and blocks the UI since this function may take some time.
			System.Windows.Forms.Cursor.Current = System.Windows.Forms.Cursors.WaitCursor;
			//Get an instance of the dataset
			DataSet dsNorthwind = NorthwindData.GetInstance().NorthwindDataSet;
			//Determine if the UpdateCommand for the SqlCeDataAdapter needs to be initialized. This will execute only the first time the SaveCustomers() procedure is executed.
			if ( daCustomers.UpdateCommand == null ) 
			{
				try 
				{
					//Create a SqlCeCommand object for the UPDATE command of daCustomers. There are many different constructors and 
					//ways to initialize SqlCeCommand objects. You will see different implementations used in this application.
					daCustomers.UpdateCommand = new SqlCeCommand();
					SqlCeConnection cnNorthwind = NorthwindData.GetInstance().NorthwindConnection;
					daCustomers.UpdateCommand.Connection = cnNorthwind;
					string  updateSQL = "UPDATE Customers SET ContactName = ?, Address = ?, City = ?, PostalCode = ?, Phone = ?, Fax = ? WHERE (CustomerID = ?)";
					daCustomers.UpdateCommand.CommandText = updateSQL;

					//There are many different constructors and ways to initialize SqlCeParameter objects. You will see different implementations used in this application. 
					//Here we are explicitly defining information about the SqlCeParameter. 

					//@ContactName paramter
					SqlCeParameter  contactParameter = new SqlCeParameter();
					contactParameter.ParameterName = "@ContactName";
					contactParameter.SqlDbType = SqlDbType.NVarChar;
					contactParameter.Size = 30;
					contactParameter.SourceColumn = "ContactName";

					//@Address parameter
					SqlCeParameter  addressParameter = new SqlCeParameter();
					addressParameter.ParameterName = "@Address";
					addressParameter.SqlDbType = SqlDbType.NVarChar;
					addressParameter.Size = 60;
					addressParameter.SourceColumn = "Address";

					//@City parameter
					SqlCeParameter  cityParameter = new SqlCeParameter();
					cityParameter.ParameterName = "@City";
					cityParameter.SqlDbType = SqlDbType.NVarChar;
					cityParameter.Size = 15;
					cityParameter.SourceColumn = "City";

					//@PostalCode parameter
					SqlCeParameter  postalParameter = new SqlCeParameter();
					postalParameter.ParameterName = "@PostalCode";
					postalParameter.SqlDbType = SqlDbType.NVarChar;
					postalParameter.Size = 10;
					postalParameter.SourceColumn = "PostalCode";

					//@Phone parameter
					SqlCeParameter  phoneParameter = new SqlCeParameter();
					phoneParameter.ParameterName = "@Phone";
					phoneParameter.SqlDbType = SqlDbType.NVarChar;
					phoneParameter.Size = 24;
					phoneParameter.SourceColumn = "Phone";

					//@Fax parameter
					SqlCeParameter  faxParameter = new SqlCeParameter();
					faxParameter.ParameterName = "@Fax";
					faxParameter.SqlDbType = SqlDbType.NVarChar;
					faxParameter.Size = 24;
					faxParameter.SourceColumn = "Fax";

					//@CustomerID parameter
					SqlCeParameter customerIDParameter = new SqlCeParameter();
					customerIDParameter.ParameterName = "@CustomerID";
					customerIDParameter.SqlDbType = SqlDbType.NChar;
					customerIDParameter.Size = 5;
					customerIDParameter.SourceColumn = "CustomerID";

					//Add the parameters and their values to the Parameters collection. The order of the parameters must match the order in the query.
					daCustomers.UpdateCommand.Parameters.Add(contactParameter);
					daCustomers.UpdateCommand.Parameters.Add(addressParameter);
					daCustomers.UpdateCommand.Parameters.Add(cityParameter);
					daCustomers.UpdateCommand.Parameters.Add(postalParameter);
					daCustomers.UpdateCommand.Parameters.Add(phoneParameter);
					daCustomers.UpdateCommand.Parameters.Add(faxParameter);
					daCustomers.UpdateCommand.Parameters.Add(customerIDParameter);

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
			}

			if ( MessageBox.Show("Are you sure you want to save? Pressing No will discard all changes.",
				"Northwind",
				System.Windows.Forms.MessageBoxButtons.YesNo,
				System.Windows.Forms.MessageBoxIcon.Asterisk,
				System.Windows.Forms.MessageBoxDefaultButton.Button1) == System.Windows.Forms.DialogResult.Yes )
			{
				try 
				{
					//You must explicitly end edits by calling the EndCurrentEdit method of the 
					//CurrencyManager object or the dataset will not recognize the modifications and
					//changes will not be persisted
					CurrencyManager cm;
					cm = (CurrencyManager) this.BindingContext[dsNorthwind.Tables["Customers"]];
					cm.EndCurrentEdit();
					daCustomers.Update(dsNorthwind, "Customers");
					dsNorthwind.AcceptChanges();
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
			} 
			else 
			{
				try 
				{
					dsNorthwind.RejectChanges();
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
			}

			contactTextBox.Enabled = false;
			addressTextBox.Enabled = false;
			cityTextBox.Enabled = false;
			postalTextBox.Enabled = false;
			phoneTextBox.Enabled = false;
			faxTextBox.Enabled = false;
			//return UI control back to the user.
			System.Windows.Forms.Cursor.Current = System.Windows.Forms.Cursors.Default;

		} //SaveCustomers()

		private void SaveOrders() 
		{
			//SaveOrders() saves new rows in the local CE Orders and Order Details tables.
			//Starts the cursor icon and blocks the UI since this function may take some time.
			System.Windows.Forms.Cursor.Current = System.Windows.Forms.Cursors.WaitCursor;

			//Get an instance of the dataset.
			DataSet dsNorthwind = NorthwindData.GetInstance().NorthwindDataSet;
			//Get an instance of the SqlCeConnection.
			SqlCeConnection cnNorthwind = NorthwindData.GetInstance().NorthwindConnection;
			//orderIDENTITY holds the OrderID value generated by the database when a new order is inserted into the Orders table.
			SqlDecimal  orderIDENTITY = new SqlDecimal();
			try 
			{
				//Create a SqlCeCommand object to INSERT a new row into the Orders table. There are many different constructors and 
				//ways to initialize SqlCeCommand objects. You will see different implementations used in this application.
				SqlCeCommand  commInsertOrders = new SqlCeCommand("INSERT INTO \"Orders\" (CustomerID, EmployeeID, OrderDate, ShipName) VALUES (?, ?, ?, ?);", cnNorthwind);
				//The Orders table includes customer information such as CustomerID and shipping information. The NorthwindCE_2556 application requires
				//that a customer is currently selected before a new order is created. A CurrencyManager object is used to determine the row in the Customers
				//table the form is bound to.
				CurrencyManager cm = (CurrencyManager) this.BindingContext[dsNorthwind.Tables["Customers"]];
				string  customerID = dsNorthwind.Tables["Customers"].Rows[cm.Position]["CustomerID"].ToString();
				string  shipName = dsNorthwind.Tables["Customers"].Rows[cm.Position]["CompanyName"].ToString();
				//We could capture the user information and dynamically generate employeeID value. 3 is the EmployeeID of Janet Leverling.
				int employeeID = 3;
				System.DateTime dateTime = System.DateTime.Now;

				//Add the values to the Parameters collection 
				commInsertOrders.Parameters.Add("@customerIDParameter", customerID);
				commInsertOrders.Parameters.Add("@employeeIDParameter", employeeID);
				commInsertOrders.Parameters.Add("@orderDate", dateTime);
				commInsertOrders.Parameters.Add("@shipName", shipName);

				//Execute the command and insert a new row into the Orders table.
				commInsertOrders.ExecuteScalar();
				//The Order and Order Details tables are related on OrderID. When a new row is inserted into the Orders table, a value for OrderID 
				//is generated. @@IDENTITY returns the identity value of the most recently inserted row. The identity value will be used for each new
				//row in the Order Details table. 
				SqlCeCommand  commSELECTIDENTITY = new SqlCeCommand("SELECT @@IDENTITY FROM Orders");
				commSELECTIDENTITY.Connection = cnNorthwind;
				orderIDENTITY = (SqlDecimal) commSELECTIDENTITY.ExecuteScalar();

			} 
			catch (SqlCeException sqlExp) 
			{
				//Pass the SqlException to the centralized error handling procedure in the NorthwindData class.
				NorthwindData.ShowErrors(sqlExp);
				return;
			} 
			catch (Exception exp) 
			{
				//Display the general Exception information.
				MessageBox.Show(exp.Message, "Northwind");
				return;
			}

			//Loop through Controls collection of newOrdersTabPage. for each OrderItemControl, read the values out of the control and 
			//save them to the Order Details table in the local CE database.
			foreach ( Control ctrl in newOrdersTabPage.Controls )
			{
				if ( ctrl.GetType().Equals(typeof(orderItemControl)) ) 
				{
					orderItemControl orderCtrl = (orderItemControl) ctrl;
					string  orderID = orderIDENTITY.ToString();
					string  productID = orderCtrl.productComboBox.SelectedValue.ToString();
					string  unitPrice = orderCtrl.priceTextBox.Text;
					string  quantity = orderCtrl.quantityTextBox.Text;
					string  discount = orderCtrl.discountTextBox.Text;
					//Remove the control from newOrdersTabPage.
					newOrdersTabPage.Controls.Remove(orderCtrl);
					//Create a SqlCeCommand object to insert the new row into the Order Details table.
					SqlCeCommand  commUpdateOrderDetails = new SqlCeCommand("INSERT INTO \"Order Details\" (OrderID, ProductID, UnitPrice, Quantity, Discount) VALUES (?, ?, ?, ?, ?);");
					//Add the values to the Parameters collection. 
					commUpdateOrderDetails.Parameters.Add("@orderIDParameter", orderID);
					commUpdateOrderDetails.Parameters.Add("@productIDParameter", productID);
					commUpdateOrderDetails.Parameters.Add("@unitPriceParameter", unitPrice);
					commUpdateOrderDetails.Parameters.Add("@qunatityParameter", quantity);
					commUpdateOrderDetails.Parameters.Add("@discountParameter", discount);
					try 
					{
						commUpdateOrderDetails.Connection = cnNorthwind;
						//Execute the command and insert a new row into the Orders table.
						commUpdateOrderDetails.ExecuteNonQuery();
					} 
					catch (SqlCeException sqlExp) 
					{
						//Pass the SqlException to the centralized error handling procedure in the NorthwindData class.
						NorthwindData.ShowErrors(sqlExp);
					} 
					catch (Exception exp) 
					{
						//Display the general Exception information.
						MessageBox.Show(exp.Message, "Northwind");
					}
				}

			} //
			verticalAxis = 0;
			newOrderItemInitialized = false;
			System.Windows.Forms.Cursor.Current = System.Windows.Forms.Cursors.Default;
		} //SaveOrders()

		private void SaveAppProps() 
		{
			//SaveAppProps() saves the synchronization information in the local CE ApplicationProperties table.
			try 
			{
				SqlCeCommand cmd = dataNorthwind.NorthwindConnection.CreateCommand();
				//Create the ApplicationProperties table if it does not already exist.    
				if ( existsSettings == false ) 
				{
					//if the database does not exist, create a new one.
					if (! File.Exists(dataNorthwind.LocalDatabaseFile) ) 
					{
						SqlCeEngine  newSqlDB = new SqlCeEngine(dataNorthwind.LocalConnString);
						newSqlDB.CreateDatabase();
					}
					if ( dataNorthwind.NorthwindConnection.State == ConnectionState.Closed ) 
						dataNorthwind.NorthwindConnection.Open();
					//The NorthwindCE_2556 application uses Anonymous Authentication on IIS to perform synchronization.
					//The Internet user information (InternetLogin and InternetPassword) is not used by the application and is only included for completeness.
					cmd.CommandText = "CREATE TABLE ApplicationProperties (InternetURL NTEXT, " +
						"InternetLogin NVARCHAR(255), " +
						"InternetPassword NVARCHAR(255), " +
						"Publisher NVARCHAR(255), " + 
						"PublisherLogin NVARCHAR(255), " + 
						"PublisherPassword NVARCHAR(255), " + 
						"PublisherSecurityMode TINYINT, " + 
						"Subscriber NVARCHAR(255));";
					//Execute the query and do not return any rows.
					cmd.ExecuteNonQuery();
					existsSettings = true;
				}
				//Delete any existing records from the ApplicationProperties table.
				if ( dataNorthwind.NorthwindConnection.State == ConnectionState.Closed ) 
					dataNorthwind.NorthwindConnection.Open();
				cmd.CommandText = "DELETE FROM ApplicationProperties";
				//Execute the query and do not return any rows.
				cmd.ExecuteNonQuery();
				//Save the synchronization information. We are using a parameterized query to insert the data.
				cmd.CommandText = "INSERT INTO ApplicationProperties " + 
					"(InternetURL, Publisher, PublisherLogin, PublisherPassword, PublisherSecurityMode) " + 
					"VALUES (?, ?, ?, ?, ?);";
				//Add parameters and their values to the Parameters collection of the SqlCeCommand. The order of the parameters must match 
				//the order in the query.
				cmd.Parameters.Add("@p1", urlTextBox.Text);
				cmd.Parameters.Add("@p2", publisherTextBox.Text);
				cmd.Parameters.Add("@p3", userIDTextBox.Text);
				cmd.Parameters.Add("@p4", passwordTextBox.Text);
				if ( sqlAuthRadioButton.Checked ) 
				{
					cmd.Parameters.Add("@p5", 1);
				} 
				else 
				{
					cmd.Parameters.Add("@p5", 0);
				}
				//Execute the query and do not return any rows.
				cmd.ExecuteNonQuery();
			} 
			catch (SqlCeException sqlExp) 
			{
				//Pass the SqlException to the centralized error handling procedure in the NorthwindData class.
				NorthwindData.ShowErrors(sqlExp);
			} 
			catch (Exception exp) 
			{
				//Display the general Exception information.
				MessageBox.Show(exp.Message, "Northwind");
			}

		} //SaveAppProps()

		private void AddOrderItemControl() 
		{
			//AddOrderItemControl() adds a new OrderItemControl to the new Order tab of the form.
			//Starts the cursor icon and blocks the UI since this function may take some time.
			System.Windows.Forms.Cursor.Current = System.Windows.Forms.Cursors.WaitCursor;

			//Determine if the form level array productValuesArray needs to be populated.
			if ( productValuesArray == null ) 
			{
				PopulateProductsArray();
			}

			//Create an OrderItemControl and a unique array for it to bind to.
			orderItemControl  orderControl = new orderItemControl();
			ArrayList  orderControlArray = new ArrayList();

			//Instead of building a new array, clone the existing form level array.
			orderControlArray = (ArrayList) productValuesArray.Clone();

			//Increment verticalAxis which controls the vertical position of the new OrderItemControl.
			verticalAxis = verticalAxis + 22;
			orderControl.Location = new System.Drawing.Point(2, verticalAxis);
			//Bind the constituent controls on the OrderItemControl to the array.
			orderControl.productComboBox.DataSource = orderControlArray;
			orderControl.productComboBox.DisplayMember = "Name";
			orderControl.productComboBox.ValueMember = "ID";
			orderControl.priceTextBox.DataBindings.Add("Text", orderControlArray, "UnitPrice");
			newOrdersTabPage.Controls.Add(orderControl);

			//return UI control back to the user.
			System.Windows.Forms.Cursor.Current = System.Windows.Forms.Cursors.Default;
		} //AddOrderItemControl()

		private void PopulateProductsArray() 
		{
			//PopulateProductsArray() populates a form level ArrayList with data from the Products table using a SqlCeDataReader. 
			productValuesArray = new ArrayList();
			SqlCeConnection cnNorthwind = NorthwindData.GetInstance().NorthwindConnection;
			SqlCeCommand  productsCommand = new SqlCeCommand("SELECT ProductID, ProductName, UnitPrice FROM Products ORDER BY ProductName");
			productsCommand.Connection = NorthwindData.GetInstance().NorthwindConnection;
			SqlCeDataReader productsDataReader = productsCommand.ExecuteReader();

			while ( productsDataReader.Read() )
			{
				//The ArrayList is populated with ProductInfo objects. The ProductInfo class is populated with the ProductID, ProductName and ProductPrice
				//values when initialized. ProductInfo exposes the values as properties.
				productValuesArray.Add(new ProductDataObject(productsDataReader.GetInt32(0), productsDataReader.GetString(1), productsDataReader.GetSqlMoney(2).ToString()));
			}
			productsDataReader.Close();
		}

		private void northwindDataTabControl_SelectedIndexChanged(object sender, System.EventArgs e)
		{
			// Determine which tab is clicked so the controls can be initialized and the tables of the dataset can be populated.
			switch (northwindDataTabControl.SelectedIndex)
			{
				case 0: // Connection tab
					newMenuItem.Enabled = false;
					editMenuItem.Enabled = false;
					saveMenuItem.Enabled = true;
					cancelMenuItem.Enabled = false;
					break;
				case 1: // Customer tab
					//The companyComboBox is bound to the Customers table in the dataset. This control is used on the Customers tab
					//and the Orders tab. Instead of creating a control for each tab, the same control is shared and moved 
					//when the tab is activated.
					if (! customersTabPage.Controls.Contains(companyComboBox) )
					{
						customersTabPage.Controls.Add(companyComboBox);
						companyComboBox.Location = new System.Drawing.Point(59, 4);
					}
					//PopulateCustomers() populates the dataset with information from the local CE Customers table and binds the controls.
					PopulateCustomers();
					newMenuItem.Enabled = false;
					editMenuItem.Enabled = true;
					saveMenuItem.Enabled = true;
					cancelMenuItem.Enabled = true;
					break;
				case 2: // Product tab
					//PopulateProducts() populates the dataset with information from the local CE Products table and binds the controls.
					PopulateProducts();
					newMenuItem.Enabled = false;
					editMenuItem.Enabled = false;
					saveMenuItem.Enabled = false;
					cancelMenuItem.Enabled = false;
					break;
				case 3: // Order tab
					//The companyComboBox is bound to the Customers table in the dataset. This control is used on the Customers tab
					//and the Orders tab. Instead of creating a control for each tab, the same control is shared and moved 
					//when the tab is activated.
					if (! ordersTabPage.Controls.Contains(companyComboBox) )
					{
						//The companyComboBox is initialized on the Customers tab. When it is moved the SelectedIndexChanged event fires. We
						//need to suppress the event before moving the control and then activate it afterwards
						companyComboBox.SelectedIndexChanged -= new System.EventHandler(companyComboBox_SelectedIndexChanged);
						ordersTabPage.Controls.Add(companyComboBox);
						companyComboBox.Location = new System.Drawing.Point(64, 4);
						companyComboBox.SelectedIndexChanged += new System.EventHandler(companyComboBox_SelectedIndexChanged);
					}
					//PopulateOrders() populates the dataset with information from the local CE Orders table and binds the controls.
					PopulateOrders();
					newMenuItem.Enabled = false;
					editMenuItem.Enabled = false;
					saveMenuItem.Enabled = false;
					cancelMenuItem.Enabled = false;
					break;
				case 4: // Order details tab
					//Determine if the Customers table in the dataset in initialized and configure the controls accordingly.
					DataSet dsNorthwind = NorthwindData.GetInstance().NorthwindDataSet;
					if ( dsNorthwind.Tables["Customers"] == null )
					{
						newMenuItem.Enabled = false;
						editMenuItem.Enabled = false;
						saveMenuItem.Enabled = false;
						cancelMenuItem.Enabled = false;
						currentCustomerLabel.Text = "Select customer before creating orders";
					}
					else
					{
						newMenuItem.Enabled = true;
						editMenuItem.Enabled = false;
						saveMenuItem.Enabled = true;
						cancelMenuItem.Enabled = true;
						CurrencyManager cm = (CurrencyManager) this.BindingContext[dsNorthwind.Tables["Customers"]];
						currentCustomerLabel.Text = "new Order for: " + dsNorthwind.Tables["Customers"].Rows[cm.Position]["CompanyName"];
						currentCustomerLabel.ForeColor = System.Drawing.Color.Black;
						//Determine if an OrderItemControl exists on the form. if ( it does not, add it to the form and set the newOrderItemInitialized flag to false.
						if ( newOrderItemInitialized == false )
						{
							AddOrderItemControl();
							newOrderItemInitialized = true;
						}
					}
					break;
			}
		}

		private void connectButton_Click(object sender, System.EventArgs e)
		{
			if ( MessageBox.Show("You are about to synchronize your data. Continue?",
				"Northwind",
				MessageBoxButtons.OKCancel,
				MessageBoxIcon.Asterisk,
				MessageBoxDefaultButton.Button1) == DialogResult.OK ) 
			{
				ReplSync();
			}
		}

		private void ordersDataGrid_Click(object sender, EventArgs e)
		{
			//Initialize a new form to display the order details for the selected parent order item.
			if ( frmOrderDetails == null ) 
			{
				frmOrderDetails = new orderDetailsForm();
			}
			//Determine the currently selected row number in the DataGrid.
			int row = ordersDataGrid.CurrentRowIndex;
			//Read the value out of the third column the DataGrid of the current row and set the OrderID property of the orderDetailsForm.
			frmOrderDetails.OrderID = (int) ordersDataGrid[row, 2];
			//The PopulateOrderDetails() procedure binds the controls.
			frmOrderDetails.PopulateOrderDetails();
			frmOrderDetails.Show();
		}

		private void exitMenuItem_Click(object sender, System.EventArgs e)
		{
			//Exit the application.
			Application.Exit();
		}

		private void editMenuItem_Click(object sender, System.EventArgs e)
		{
			//Enable the TextBoxes so they can be edited.
			contactTextBox.Enabled = true;
			addressTextBox.Enabled = true;
			cityTextBox.Enabled = true;
			postalTextBox.Enabled = true;
			phoneTextBox.Enabled = true;
			faxTextBox.Enabled = true;
		}

		private void saveMenuItem_Click(object sender, System.EventArgs e)
		{
			switch (northwindDataTabControl.SelectedIndex)
			{
				case 0: //Connection tab
					SaveAppProps();
					break;
				case 1: //Customers tab
					SaveCustomers();
					break;
				case 4: //new Orders tab
					SaveOrders();
					break;
			}
		}

		private void newMenuItem_Click(object sender, System.EventArgs e)
		{
			AddOrderItemControl();
		}

		private void cancelMenuItem_Click(object sender, System.EventArgs e)
		{
			switch (northwindDataTabControl.SelectedIndex) 
			{ 
				case 1: //Customers tab
					contactTextBox.Enabled = false;
					addressTextBox.Enabled = false;
					cityTextBox.Enabled = false;
					postalTextBox.Enabled = false;
					phoneTextBox.Enabled = false;
					faxTextBox.Enabled = false;
					DataSet dsNorthwind = NorthwindData.GetInstance().NorthwindDataSet;
					dsNorthwind.RejectChanges();
					break;
				case 4: // new Orders tab

					foreach ( Control ctrl in newOrdersTabPage.Controls )
					{
						if ( ctrl.GetType().Equals(typeof(orderItemControl)) ) 
						{
							orderItemControl orderCtrl = (orderItemControl) ctrl;
							newOrdersTabPage.Controls.Remove(orderCtrl);
						}
					}
					newOrderItemInitialized = false;
					verticalAxis = 0;
					break;
			}
		}

		private void companyComboBox_SelectedIndexChanged(object sender, System.EventArgs e)
		{
			DataSet dsNorthwind = NorthwindData.GetInstance().NorthwindDataSet;
			if (dsNorthwind.Tables["Orders"] != null ) 
			{
				//Set a new filter on the Orders table when to match the currently selected customer.
				dsNorthwind.Tables["Orders"].DefaultView.RowFilter = "CustomerID = '" + companyComboBox.SelectedValue + "'";
			}

		}
	}
}

using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;
using System.Data.OleDb;

namespace ATM
{
  /// <summary>
  /// Summary description for FrmATM.
  /// </summary>
  public class FrmATM : System.Windows.Forms.Form
  {
    // Panel with Label and TextBox inside to display
    // instructions and messages to the user
    private System.Windows.Forms.Panel pnlDisplay;
    private System.Windows.Forms.Label lblDisplay;
    private System.Windows.Forms.TextBox txtInput;

    // GroupBox containing Buttons
    private System.Windows.Forms.GroupBox fraButtons;

    // Buttons for entering PIN and withdrawal amount
    private System.Windows.Forms.Button btnZero;
    private System.Windows.Forms.Button btnOne;
    private System.Windows.Forms.Button btnTwo;
    private System.Windows.Forms.Button btnThree;
    private System.Windows.Forms.Button btnFour;
    private System.Windows.Forms.Button btnFive;
    private System.Windows.Forms.Button btnSix;
    private System.Windows.Forms.Button btnSeven;
    private System.Windows.Forms.Button btnEight;
    private System.Windows.Forms.Button btnNine;

    // Buttons to take an action
    private System.Windows.Forms.Button btnOK;
    private System.Windows.Forms.Button btnBalance;
    private System.Windows.Forms.Button btnWithdraw;
    private System.Windows.Forms.Button btnDone;

    // GroupBox with Label and ComboBox inside for choosing
    // an account number
    private System.Windows.Forms.GroupBox fraAccountNumber;
    private System.Windows.Forms.Label lblAccountNumber;
    private System.Windows.Forms.ComboBox cboAccountNumbers;

    // OleDbConnection for the account information database
    private System.Data.OleDb.OleDbConnection objOleDbConnection;

    // OleDbCommand to select account number from database
    private System.Data.OleDb.OleDbCommand objSelectAccount;

    // OleDbCommand to select account data from database based
    // on account number
    private System.Data.OleDb.OleDbCommand objSelectAccountData;

    // OleDbCommand to update a balance based 
    // on the account number
    private System.Data.OleDb.OleDbCommand objUpdateBalance;

    /// <summary>
    /// Required designer variable.
    /// </summary>
    private System.ComponentModel.Container components = null;

    // variable to store user-entered PIN number
    private string m_strUserPIN;

    // variables to store account balance and user's first name
    private decimal m_decBalance;
    private string m_strFirstName;
    private string m_strPIN;

    // variable to indicate action being performed
    private string m_strAction = "Account";

    public FrmATM()
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
    protected override void Dispose(bool disposing)
    {
      if (disposing)
      {
        if (components != null)
        {
          components.Dispose();
        }
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
      this.pnlDisplay = new System.Windows.Forms.Panel();
      this.txtInput = new System.Windows.Forms.TextBox();
      this.lblDisplay = new System.Windows.Forms.Label();
      this.fraButtons = new System.Windows.Forms.GroupBox();
      this.btnDone = new System.Windows.Forms.Button();
      this.btnWithdraw = new System.Windows.Forms.Button();
      this.btnBalance = new System.Windows.Forms.Button();
      this.btnOK = new System.Windows.Forms.Button();
      this.btnZero = new System.Windows.Forms.Button();
      this.btnNine = new System.Windows.Forms.Button();
      this.btnEight = new System.Windows.Forms.Button();
      this.btnSeven = new System.Windows.Forms.Button();
      this.btnSix = new System.Windows.Forms.Button();
      this.btnFive = new System.Windows.Forms.Button();
      this.btnFour = new System.Windows.Forms.Button();
      this.btnThree = new System.Windows.Forms.Button();
      this.btnTwo = new System.Windows.Forms.Button();
      this.btnOne = new System.Windows.Forms.Button();
      this.fraAccountNumber = new System.Windows.Forms.GroupBox();
      this.cboAccountNumbers = new System.Windows.Forms.ComboBox();
      this.lblAccountNumber = new System.Windows.Forms.Label();
      this.objOleDbConnection = new System.Data.OleDb.OleDbConnection();
      this.objSelectAccount = new System.Data.OleDb.OleDbCommand();
      this.objSelectAccountData = new System.Data.OleDb.OleDbCommand();
      this.objUpdateBalance = new System.Data.OleDb.OleDbCommand();
      this.pnlDisplay.SuspendLayout();
      this.fraButtons.SuspendLayout();
      this.fraAccountNumber.SuspendLayout();
      this.SuspendLayout();
      // 
      // pnlDisplay
      // 
      this.pnlDisplay.Controls.Add(this.txtInput);
      this.pnlDisplay.Controls.Add(this.lblDisplay);
      this.pnlDisplay.Location = new System.Drawing.Point(16, 8);
      this.pnlDisplay.Name = "pnlDisplay";
      this.pnlDisplay.Size = new System.Drawing.Size(328, 152);
      this.pnlDisplay.TabIndex = 0;
      // 
      // txtInput
      // 
      this.txtInput.Location = new System.Drawing.Point(100, 120);
      this.txtInput.Name = "txtInput";
      this.txtInput.ReadOnly = true;
      this.txtInput.Size = new System.Drawing.Size(128, 21);
      this.txtInput.TabIndex = 1;
      this.txtInput.Text = "";
      this.txtInput.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
      this.txtInput.TextChanged += new System.EventHandler(this.txtInput_TextChanged);
      // 
      // lblDisplay
      // 
      this.lblDisplay.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
      this.lblDisplay.Font = new System.Drawing.Font("Tahoma", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((System.Byte)(0)));
      this.lblDisplay.Location = new System.Drawing.Point(20, 16);
      this.lblDisplay.Name = "lblDisplay";
      this.lblDisplay.Size = new System.Drawing.Size(288, 88);
      this.lblDisplay.TabIndex = 0;
      this.lblDisplay.Text = "Please select your account number:";
      this.lblDisplay.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
      // 
      // fraButtons
      // 
      this.fraButtons.Controls.Add(this.btnDone);
      this.fraButtons.Controls.Add(this.btnWithdraw);
      this.fraButtons.Controls.Add(this.btnBalance);
      this.fraButtons.Controls.Add(this.btnOK);
      this.fraButtons.Controls.Add(this.btnZero);
      this.fraButtons.Controls.Add(this.btnNine);
      this.fraButtons.Controls.Add(this.btnEight);
      this.fraButtons.Controls.Add(this.btnSeven);
      this.fraButtons.Controls.Add(this.btnSix);
      this.fraButtons.Controls.Add(this.btnFive);
      this.fraButtons.Controls.Add(this.btnFour);
      this.fraButtons.Controls.Add(this.btnThree);
      this.fraButtons.Controls.Add(this.btnTwo);
      this.fraButtons.Controls.Add(this.btnOne);
      this.fraButtons.Location = new System.Drawing.Point(44, 160);
      this.fraButtons.Name = "fraButtons";
      this.fraButtons.Size = new System.Drawing.Size(276, 150);
      this.fraButtons.TabIndex = 1;
      this.fraButtons.TabStop = false;
      // 
      // btnDone
      // 
      this.btnDone.Enabled = false;
      this.btnDone.Location = new System.Drawing.Point(160, 120);
      this.btnDone.Name = "btnDone";
      this.btnDone.TabIndex = 13;
      this.btnDone.Text = "&Done";
      this.btnDone.Click += new System.EventHandler(this.btnDone_Click);
      // 
      // btnWithdraw
      // 
      this.btnWithdraw.Enabled = false;
      this.btnWithdraw.Location = new System.Drawing.Point(160, 88);
      this.btnWithdraw.Name = "btnWithdraw";
      this.btnWithdraw.TabIndex = 12;
      this.btnWithdraw.Text = "&Withdraw";
      this.btnWithdraw.Click += new System.EventHandler(this.btnWithdraw_Click);
      // 
      // btnBalance
      // 
      this.btnBalance.Enabled = false;
      this.btnBalance.Location = new System.Drawing.Point(160, 56);
      this.btnBalance.Name = "btnBalance";
      this.btnBalance.TabIndex = 11;
      this.btnBalance.Text = "&Balance";
      this.btnBalance.Click += new System.EventHandler(this.btnBalance_Click);
      // 
      // btnOK
      // 
      this.btnOK.Enabled = false;
      this.btnOK.Location = new System.Drawing.Point(160, 24);
      this.btnOK.Name = "btnOK";
      this.btnOK.TabIndex = 10;
      this.btnOK.Text = "&OK";
      this.btnOK.Click += new System.EventHandler(this.btnOK_Click);
      // 
      // btnZero
      // 
      this.btnZero.Location = new System.Drawing.Point(80, 104);
      this.btnZero.Name = "btnZero";
      this.btnZero.Size = new System.Drawing.Size(24, 24);
      this.btnZero.TabIndex = 9;
      this.btnZero.Text = "0";
      this.btnZero.Click += new System.EventHandler(this.btnZero_Click);
      // 
      // btnNine
      // 
      this.btnNine.Location = new System.Drawing.Point(104, 80);
      this.btnNine.Name = "btnNine";
      this.btnNine.Size = new System.Drawing.Size(24, 24);
      this.btnNine.TabIndex = 8;
      this.btnNine.Text = "9";
      this.btnNine.Click += new System.EventHandler(this.btnNine_Click);
      // 
      // btnEight
      // 
      this.btnEight.Location = new System.Drawing.Point(80, 80);
      this.btnEight.Name = "btnEight";
      this.btnEight.Size = new System.Drawing.Size(24, 24);
      this.btnEight.TabIndex = 7;
      this.btnEight.Text = "8";
      this.btnEight.Click += new System.EventHandler(this.btnEight_Click);
      // 
      // btnSeven
      // 
      this.btnSeven.Location = new System.Drawing.Point(56, 80);
      this.btnSeven.Name = "btnSeven";
      this.btnSeven.Size = new System.Drawing.Size(24, 24);
      this.btnSeven.TabIndex = 6;
      this.btnSeven.Text = "7";
      this.btnSeven.Click += new System.EventHandler(this.btnSeven_Click);
      // 
      // btnSix
      // 
      this.btnSix.Location = new System.Drawing.Point(104, 56);
      this.btnSix.Name = "btnSix";
      this.btnSix.Size = new System.Drawing.Size(24, 24);
      this.btnSix.TabIndex = 5;
      this.btnSix.Text = "6";
      this.btnSix.Click += new System.EventHandler(this.btnSix_Click);
      // 
      // btnFive
      // 
      this.btnFive.Location = new System.Drawing.Point(80, 56);
      this.btnFive.Name = "btnFive";
      this.btnFive.Size = new System.Drawing.Size(24, 24);
      this.btnFive.TabIndex = 4;
      this.btnFive.Text = "5";
      this.btnFive.Click += new System.EventHandler(this.btnFive_Click);
      // 
      // btnFour
      // 
      this.btnFour.Location = new System.Drawing.Point(56, 56);
      this.btnFour.Name = "btnFour";
      this.btnFour.Size = new System.Drawing.Size(24, 24);
      this.btnFour.TabIndex = 3;
      this.btnFour.Text = "4";
      this.btnFour.Click += new System.EventHandler(this.btnFour_Click);
      // 
      // btnThree
      // 
      this.btnThree.Location = new System.Drawing.Point(104, 32);
      this.btnThree.Name = "btnThree";
      this.btnThree.Size = new System.Drawing.Size(24, 24);
      this.btnThree.TabIndex = 2;
      this.btnThree.Text = "3";
      this.btnThree.Click += new System.EventHandler(this.btnThree_Click);
      // 
      // btnTwo
      // 
      this.btnTwo.Location = new System.Drawing.Point(80, 32);
      this.btnTwo.Name = "btnTwo";
      this.btnTwo.Size = new System.Drawing.Size(24, 24);
      this.btnTwo.TabIndex = 1;
      this.btnTwo.Text = "2";
      this.btnTwo.Click += new System.EventHandler(this.btnTwo_Click);
      // 
      // btnOne
      // 
      this.btnOne.Location = new System.Drawing.Point(56, 32);
      this.btnOne.Name = "btnOne";
      this.btnOne.Size = new System.Drawing.Size(24, 24);
      this.btnOne.TabIndex = 0;
      this.btnOne.Text = "1";
      this.btnOne.Click += new System.EventHandler(this.btnOne_Click);
      // 
      // fraAccountNumber
      // 
      this.fraAccountNumber.Controls.Add(this.cboAccountNumbers);
      this.fraAccountNumber.Controls.Add(this.lblAccountNumber);
      this.fraAccountNumber.Location = new System.Drawing.Point(44, 320);
      this.fraAccountNumber.Name = "fraAccountNumber";
      this.fraAccountNumber.Size = new System.Drawing.Size(276, 48);
      this.fraAccountNumber.TabIndex = 2;
      this.fraAccountNumber.TabStop = false;
      // 
      // cboAccountNumbers
      // 
      this.cboAccountNumbers.Location = new System.Drawing.Point(126, 16);
      this.cboAccountNumbers.Name = "cboAccountNumbers";
      this.cboAccountNumbers.TabIndex = 1;
      this.cboAccountNumbers.SelectedIndexChanged += new System.EventHandler(this.cboAccountNumbers_SelectedIndexChanged);
      // 
      // lblAccountNumber
      // 
      this.lblAccountNumber.Location = new System.Drawing.Point(30, 22);
      this.lblAccountNumber.Name = "lblAccountNumber";
      this.lblAccountNumber.Size = new System.Drawing.Size(96, 15);
      this.lblAccountNumber.TabIndex = 0;
      this.lblAccountNumber.Text = "Account Number:";
      // 
      // objOleDbConnection
      // 
      this.objOleDbConnection.ConnectionString = @"Jet OLEDB:Global Partial Bulk Ops=2;Jet OLEDB:Registry Path=;Jet OLEDB:Database Locking Mode=1;Data Source=""" + System.IO.Directory.GetCurrentDirectory() + @"\..\..\db_ATM.mdb"";Mode=Share Deny None;Jet OLEDB:Engine Type=5;Provider=""Microsoft.Jet.OLEDB.4.0"";Jet OLEDB:System database=;Jet OLEDB:SFP=False;persist security info=False;Extended Properties=;Jet OLEDB:Compact Without Replica Repair=False;Jet OLEDB:Encrypt Database=False;Jet OLEDB:Create System Database=False;Jet OLEDB:Don't Copy Locale on Compact=False;User ID=Admin;Jet OLEDB:Global Bulk Transactions=1";
      // 
      // objSelectAccount
      // 
      this.objSelectAccount.CommandText = "SELECT AccountNumber FROM AccountInformation";
      this.objSelectAccount.Connection = this.objOleDbConnection;
      // 
      // objSelectAccountData
      // 
      this.objSelectAccountData.CommandText = "SELECT PIN, BalanceAmount, FirstName FROM AccountInformation WHERE (AccountNumber" +
         " = ?)";
      this.objSelectAccountData.Connection = this.objOleDbConnection;
      this.objSelectAccountData.Parameters.Add(new System.Data.OleDb.OleDbParameter("AccountNumber", System.Data.OleDb.OleDbType.Integer, 0, "AccountNumber"));
      // 
      // objUpdateBalance
      // 
      this.objUpdateBalance.CommandText = "UPDATE AccountInformation SET BalanceAmount = ? WHERE (AccountNumber = ?)";
      this.objUpdateBalance.Connection = this.objOleDbConnection;
      this.objUpdateBalance.Parameters.Add(new System.Data.OleDb.OleDbParameter("BalanceAmount", System.Data.OleDb.OleDbType.Double, 0, "BalanceAmount"));
      this.objUpdateBalance.Parameters.Add(new System.Data.OleDb.OleDbParameter("Original_AccountNumber", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, false, ((System.Byte)(0)), ((System.Byte)(0)), "AccountNumber", System.Data.DataRowVersion.Original, null));
      // 
      // FrmATM
      // 
      this.AutoScaleBaseSize = new System.Drawing.Size(5, 14);
      this.ClientSize = new System.Drawing.Size(360, 381);
      this.Controls.Add(this.fraAccountNumber);
      this.Controls.Add(this.fraButtons);
      this.Controls.Add(this.pnlDisplay);
      this.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((System.Byte)(0)));
      this.Name = "FrmATM";
      this.Text = "ATM";
      this.Load += new System.EventHandler(this.FrmATM_Load);
      this.pnlDisplay.ResumeLayout(false);
      this.fraButtons.ResumeLayout(false);
      this.fraAccountNumber.ResumeLayout(false);
      this.ResumeLayout(false);

    }
    #endregion

    /// <summary>
    /// The main entry point for the application.
    /// </summary>
    [STAThread]
    static void Main()
    {
      Application.Run(new FrmATM());
    }

    // invoke when 0 Button is clicked
    private void btnZero_Click(
       object sender, System.EventArgs e)
    {
      InputNumber("0"); // invoke method with argument 0

    } // end method btnZero_Click

    // invoke when 1 Button is clicked
    private void btnOne_Click(
       object sender, System.EventArgs e)
    {
      InputNumber("1"); // invoke method with argument 1

    } // end method btnOne_Click

    // invoke when 2 Button is clicked
    private void btnTwo_Click(
       object sender, System.EventArgs e)
    {
      InputNumber("2"); // invoke method with argument 2

    } // end method btnTwo_Click

    // invoke when 3 Button is clicked
    private void btnThree_Click(
       object sender, System.EventArgs e)
    {
      InputNumber("3"); // invoke method with argument 3

    } // end method btnThree_Click

    // invoke when 4 Button is clicked
    private void btnFour_Click(
       object sender, System.EventArgs e)
    {
      InputNumber("4"); // invoke method with argument 4

    } // end method btnFour_Click

    // invoke when 5 Button is clicked
    private void btnFive_Click(
       object sender, System.EventArgs e)
    {
      InputNumber("5"); // invoke method with argument 5

    } // end method btnFive_Click

    // invoke when 6 Button is clicked
    private void btnSix_Click(
       object sender, System.EventArgs e)
    {
      InputNumber("6"); // invoke method with argument 6

    } // end method btnSix_Click

    // invoke when 7 Button is clicked
    private void btnSeven_Click(
       object sender, System.EventArgs e)
    {
      InputNumber("7"); // invoke method with argument 7

    } // end method btnSeven_Click

    // invoke when 8 Button is clicked
    private void btnEight_Click(
       object sender, System.EventArgs e)
    {
      InputNumber("8"); // invoke method with argument 8

    } // end method btnEight_Click

    // invoke when 9 Button is clicked
    private void btnNine_Click(
       object sender, System.EventArgs e)
    {
      InputNumber("9"); // invoke method with argument 9

    } // end method btnNine_Click

    // determines what text will display in TextBox
    private void InputNumber(string strNumber)
    {
      // if user is entering PIN number display * to 
      // conceal PIN entry; store entered PIN in variable
      if (m_strAction == "PIN")
      {
        txtInput.Text += "*";
        m_strUserPIN += strNumber;
      }
      else // otherwise display number
      {
        txtInput.Text += strNumber;
      }

    } // end method InputNumber

    // invoke when OK Button is clicked
    private void btnOK_Click(
       object sender, System.EventArgs e)
    {
      // determine what action to perform
      switch (m_strAction)
      {
        // if user provided PIN number
        case "PIN":

          RetrieveAccountInformation(); // invoke method

          // determine if PIN number is within valid range
          if (m_strUserPIN == m_strPIN)
          {
            // enable Buttons and disable ComboBox
            btnBalance.Enabled = true;
            btnWithdraw.Enabled = true;
            cboAccountNumbers.Enabled = false;

            // display status to user
            lblDisplay.Text = "Welcome " + m_strFirstName +
               ", select a transaction.";

            // change action to indicate that no user-action 
            // is expected
            m_strAction = "NoAction";
          }
          else
          {
            // indicate that incorrect PIN was provided
            lblDisplay.Text =
               "Sorry, PIN number is incorrect."
               + "Please re-enter the PIN number.";

            // clear user's previous PIN entry
            m_strUserPIN = "";
          }

          txtInput.Clear(); // clear TextBox
          break;

        // if user provided withdrawal amount
        case "Withdrawal":

          // invoke Withdrawal method with decimal argument
          Withdrawal(Convert.ToDecimal(txtInput.Text));
          txtInput.Clear();
          m_strAction = "NoAction";
          break;

      } // end switch

    } // end method btnOK_Click

    // invoked when Withdraw Button is clicked
    private void btnWithdraw_Click(
       object sender, System.EventArgs e)
    {
      // display message to user
      lblDisplay.Text =
         "Enter the amount you would like to withdraw.";

      // change action to indicate user will
      // provide withdrawal amount
      m_strAction = "Withdrawal";

    } // end method btnWithdraw_Click

    // determine new balance amount
    private void Withdrawal(decimal decWithdrawAmount)
    {
      // determine if amount can be withdrawn
      if (decWithdrawAmount <= m_decBalance)
      {
        // determine new balance amount after withdrawal
        m_decBalance -= decWithdrawAmount;

        UpdateBalance(); // invoke method to update database

        // display balance information to user
        lblDisplay.Text = "Your current balance is " +
           String.Format("{0:C}", m_decBalance);
      }
      else
      {
        // indicate amount cannot be withdrawn
        lblDisplay.Text = "The withdrawal amount is too large."
           + " Select Withdraw and enter a different amount.";
      }

    } // end method WithDrawal

    // invoked when Balance Button is clicked
    private void btnBalance_Click(
       object sender, System.EventArgs e)
    {
      // display user's balance 
      lblDisplay.Text = "Your current balance is " +
         String.Format("{0:C}", m_decBalance);

    } // end method btnBalance_Click

    // invoked when Done Button is clicked
    private void btnDone_Click(
       object sender, System.EventArgs e)
    {
      lblDisplay.Text = "Please select your account number.";

      // change action to indicate that user will 
      // provide account number
      m_strAction = "Account";
      m_strUserPIN = "";

      txtInput.Clear(); // clear TextBox
      btnOK.Enabled = false; // disable OK Button
      btnBalance.Enabled = false; // disable Balance Button
      btnWithdraw.Enabled = false; // disable Withdraw Button
      btnDone.Enabled = false; // disable Done Button
      cboAccountNumbers.Enabled = true; // enable ComboBox
      cboAccountNumbers.Text = ""; // clear selected account

    } // end method btnDone_Click

    // invoke when user inputs information in TextBox
    private void txtInput_TextChanged(
       object sender, System.EventArgs e)
    {
      btnOK.Enabled = true; // enable OK Button

    } // end method txtInput_TextChanged

    // invoke when selection is made in ComboBox
    private void cboAccountNumbers_SelectedIndexChanged(
       object sender, System.EventArgs e)
    {
      // change action to indicate that user will 
      // provide account number
      m_strAction = "PIN";

      // prompt user to enter PIN number
      lblDisplay.Text = "Please enter your PIN number.";
      btnDone.Enabled = true; // enable Done Button;
      txtInput.Clear(); // clear TextBox

    } // end method cboAccountNumbers_SelectedIndexChanged

    // load application Form
    private void FrmATM_Load(object sender, System.EventArgs e)
    {
      objOleDbConnection.Open(); // open database connection

      // create database reader to read information from database
      OleDbDataReader objReader =
         objSelectAccount.ExecuteReader();

      // fill ComboBox with account numbers
      while (objReader.Read())
      {
        cboAccountNumbers.Items.Add(
           objReader["AccountNumber"]);
      }

      objOleDbConnection.Close(); // close database connection

    } // end method FrmATM_Load

    // invoke when user provides account number
    private void RetrieveAccountInformation()
    {
      // specify account number of row from which data
      // will be retrieved
      objSelectAccountData.Parameters["AccountNumber"].Value =
         cboAccountNumbers.SelectedItem;

      objOleDbConnection.Open(); // open database connection

      // create database reader to read information from database
      OleDbDataReader objReader =
         objSelectAccountData.ExecuteReader();

      objReader.Read(); // open data reader connection

      // retrieve PIN number, balance amount and first name 
      // information from database
      m_strPIN = Convert.ToString(
         objReader["PIN"]);
      m_decBalance = Convert.ToDecimal(
         objReader["BalanceAmount"]);
      m_strFirstName = Convert.ToString(
         objReader["FirstName"]);

      objReader.Close(); // close data reader connection
      objOleDbConnection.Close(); // close database connection

    } // end method RetrieveAccountInformation

    // update BalanceAmount in database
    private void UpdateBalance()
    {
      // specify new BalanceAmount to update in database
      objUpdateBalance.Parameters["BalanceAmount"].Value =
         m_decBalance;

      // specify row whose BalanceAmount will update
      objUpdateBalance.Parameters[
         "Original_AccountNumber"].Value =
         cboAccountNumbers.SelectedItem;

      objOleDbConnection.Open(); // open database connection

      // execute update statement
      objUpdateBalance.ExecuteNonQuery();

      objOleDbConnection.Close(); // close database connection

    } // end method UpdateBalance

  } // end class FrmATM
}

/**************************************************************************
 * (C) Copyright 1992-2004 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/

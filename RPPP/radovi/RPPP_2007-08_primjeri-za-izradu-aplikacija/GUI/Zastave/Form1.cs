using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Zastave
{
  public partial class Form1 : Form
  {

    // string array stores country names
    string[] strOptions = {
         "Russia", "China", "United States", "Italy",
         "Australia", "South Africa", "Brazil", "Spain" };

    // boolean array tracks displayed flags
    bool[] blnUsed;

    // number of flags shown
    int intCount = 1;
    string strCountry; // current flag's country


    public Form1()
    {
      InitializeComponent();
    }

          // handles Flag Quiz Form's Load event
      private void FrmFlagQuiz_Load(
         object sender, System.EventArgs e )
      {
         // initialize the boolean array
         blnUsed = new bool[ strOptions.GetUpperBound( 0 ) ];

         Array.Sort( strOptions ); // alphabetize country names

         // display country names in ComboBox
         cboOptions.DataSource = strOptions;

         DisplayFlag(); // display first flag in PictureBox

      } // end method FrmFlagQuiz_Load

      // return full path name of image file as a string
      string BuildPathName()
      {
         // begin with country name
         string strOutput = strCountry;

         // locate space character if there is one
         int intSpace = strOutput.IndexOf( " " );
         
         // remove space from country name if there is one
         if ( intSpace > 0 )
         {
            strOutput = strOutput.Remove( intSpace, 1 );
         }

         strOutput = strOutput.ToLower(); // make chars lowercase
         strOutput += ".png"; // add file extension

         // add path name
         strOutput = strOutput.Insert( 0,
            "../../images/" );

         return strOutput;  // return full path name

      } // end method BuildPathName

      // return an unused random number
      int GetUniqueRandomNumber()
      {
         Random objRandom = new Random();
         int intRandom;

         // generate random numbers until unused flag is found
         do
         {
            intRandom = objRandom.Next( 0, blnUsed.Length );
         } while ( blnUsed[ intRandom ] == true );

         // indicate that flag has been used
         blnUsed[ intRandom ] = true;

         return intRandom; // return index for new flag

      } // end method GetUniqueRandomNumber

      // display random flag in PictureBox
      void DisplayFlag()
      {
         // unique index ensures that a flag is used
         // no more than once
         int intRandom = GetUniqueRandomNumber();

         // retrieve country name from array strOptions
         strCountry = strOptions[ intRandom ];

         // get image's full path name
         string strPath = BuildPathName();
         picFlag.Image = Image.FromFile( strPath ); // display image

      } // end method DisplayFlag

      // handles Submit Button's Click event
      private void btnSubmit_Click(
         object sender, System.EventArgs e )
      {
         // retrieve answer from ComboBox
         string strResponse = 
            Convert.ToString( cboOptions.SelectedValue );

         // verify answer
         if ( strResponse == strCountry )
         {
            lblFeedback.Text = "Correct!";
         }
         else
         {
            lblFeedback.Text = "Sorry, incorrect.";
         }

         // inform user if quiz is over
         if ( intCount >= 5 ) // quiz is over
         {
            lblFeedback.Text += "   Done!";
            btnNext.Enabled = false;
            btnSubmit.Enabled = false;
            cboOptions.Enabled = false;
         }
         else // quiz is not over
         {
            btnSubmit.Enabled = false;
            btnNext.Enabled = true;
         }

      } // end method btnSubmit_Click

      // handles Next Button's Click event
      private void btnNext_Click( 
         object sender, System.EventArgs e )
      {
         DisplayFlag(); // display next flag
         lblFeedback.Text = ""; // clear output

         // change selected country to first in ComboBox
         cboOptions.SelectedIndex = 0;

         intCount++; // update number of flags shown

         btnSubmit.Enabled = true;
         btnNext.Enabled = false;

      } // end method btnNext_Click

   } // end class 
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


  
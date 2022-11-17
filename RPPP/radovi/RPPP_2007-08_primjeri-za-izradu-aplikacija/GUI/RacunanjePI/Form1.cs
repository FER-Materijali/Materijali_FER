//#define THREADING

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

using System.Threading;
using System.Diagnostics;


namespace RacunanjePI
{
  public partial class Form1 : Form
  {

    int digitsToCalc = 0;
    Thread piThread;

    public Form1()
    {
      InitializeComponent();
    }


    void CalcPiThreadStart()
    {
      CalcPi(digitsToCalc);
    }

    delegate void ShowProgressDelegate(string pi, int totalDigits, int digitsSoFar);

    void ShowProgress(string pi, int totalDigits, int digitsSoFar)
    {
#if THREADING
      if (this.InvokeRequired)
      {
        ShowProgressDelegate showProgress = new ShowProgressDelegate(ShowProgress);
        this.BeginInvoke(showProgress, new object[] { pi, totalDigits, digitsSoFar });
      }
      else
      {
        piTextBox.Text = pi;
        piProgressBar.Maximum = totalDigits;
        piProgressBar.Value = digitsSoFar;
      }
#else      
      piTextBox.Text = pi;
      piProgressBar.Maximum = totalDigits;
      piProgressBar.Value = digitsSoFar;
#endif

    } // ShowProgress


    void CalcPi(int digits)
    {
      StringBuilder pi = new StringBuilder("3", digits + 2);

      ShowProgress(pi.ToString(), digits, 0);

      if (digits > 0)
      {
        pi.Append(".");

        for (int i = 0; i < digits; i += 9)
        {
          int nineDigits = NineDigitsOfPi.StartingAt(i + 1);
          int digitCount = Math.Min(digits - i, 9);
          string ds = string.Format("{0:D9}", nineDigits);
          pi.Append(ds.Substring(0, digitCount));

          ShowProgress(pi.ToString(), digits, i + digitCount);
        }
      }
    }

    void buttonCalc_Click(object sender, EventArgs e)
    {

      digitsToCalc = (int)digitsUpDown.Value;
#if THREADING
      piThread = new Thread(new ThreadStart(CalcPiThreadStart));
      piThread.Start();
#else
      CalcPi(digitsToCalc);
#endif

    }

    private void buttonStop_Click(object sender, EventArgs e)
    {
#if THREADING
      piThread.Abort();
#else
      ; // ovdje je "nemoguæe doæi"
#endif
    }
  }
}
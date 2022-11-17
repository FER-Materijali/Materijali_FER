using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Windows.Forms;

namespace ServiceModelSamples
{
    public class CalcService : ICalc
    {
        // Step 2: Implement functionality for the service operations.
        public double Add2(double n1, double n2)
        {
            double result = n1 + n2;
            MessageBox.Show("Received Add2()");
            return result;
        }

        public double Subtract2(double n1, double n2)
        {
            double result = n1 - n2;
            MessageBox.Show("Received Substract2()");
            return result;
        }

        public double Multiply2(double n1, double n2)
        {
            double result = n1 * n2;
            MessageBox.Show("Received Multiply2()");
            return result;
        }

        public double Divide2(double n1, double n2)
        {
            double result = n1 / n2;
            MessageBox.Show("Received Divide2()");
            return result;
        }
    }
}

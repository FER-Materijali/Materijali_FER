using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Windows.Forms;

namespace Microsoft.ServiceModel.Samples
{
    public class CalculatorService:ICalculator
    {
        public double Add(double n1, double n2)
        {
            double result = n1 + n2;
            MessageBox.Show("Received Add()");
            return result;
        }

        public double Subtract(double n1, double n2)
        {
            double result = n1 - n2;
            MessageBox.Show("Received Substract()");
            return result;
        }

        public double Multiply(double n1, double n2)
        {
            double result = n1 * n2;
            MessageBox.Show("Received Multiply()");
            return result;
        }

        public double Divide(double n1, double n2)
        {
            double result = n1 / n2;
            MessageBox.Show("Received Divide()");
            return result;
        }
    }
}

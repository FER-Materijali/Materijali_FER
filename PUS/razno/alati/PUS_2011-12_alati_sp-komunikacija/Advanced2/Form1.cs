using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.ServiceModel;
using System.ServiceModel.Description;

namespace ServiceModelSamples
{
    public partial class Form1 : Form
    {

        //Step 1: Create an endpoint address and an instance of the WCF Client.
        EndpointAddress epAddress = new EndpointAddress("http://localhost:8000/ServiceModelSamples/Service/CalculatorService");
        CalculatorClient client = new CalculatorClient();

        // Step 2 of the hosting procedure: Create ServiceHost
        ServiceHost selfHost2 = new ServiceHost(typeof(CalcService), new Uri("http://localhost:8000/ServiceModelSamples/Service2"));

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            // Step 2: Call the service operations.
            // Call the Add service operation.
            double value1 = 100.00D;
            double value2 = 15.99D;
            double result = client.Add(value1, value2);
            MessageBox.Show("Add({" + value1.ToString() + "},{" + value2.ToString() + "}) = {" + result.ToString() + "}");
        }

        private void btnSubstract_Click(object sender, EventArgs e)
        {
            // Call the Subtract service operation.
            double value1 = 145.00D;
            double value2 = 76.54D;
            double result = client.Subtract(value1, value2);
            MessageBox.Show("Substract({" + value1.ToString() + "},{" + value2.ToString() + "}) = {" + result.ToString() + "}");
        }

        private void btnMul_Click(object sender, EventArgs e)
        {
            // Call the Multiply service operation.
            double value1 = 9.00D;
            double value2 = 81.25D;
            double result = client.Multiply(value1, value2);
            MessageBox.Show("Multiply({" + value1.ToString() + "},{" + value2.ToString() + "}) = {" + result.ToString() + "}");
        }

        private void btnDiv_Click(object sender, EventArgs e)
        {
            // Call the Divide service operation.
            double value1 = 22.00D;
            double value2 = 7.00D;
            double result = client.Divide(value1, value2);
            MessageBox.Show("Divide({" + value1.ToString() + "},{" + value2.ToString() + "}) = {" + result.ToString() + "}");
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            //Step 3: Closing the client gracefully closes the connection and cleans up resources.
            client.Close();
        }

        private void btnStart2_Click(object sender, EventArgs e)
        {
            try
            {


                // Step 3 of the hosting procedure: Add a service endpoint.
                selfHost2.AddServiceEndpoint(
                    typeof(ICalc),
                    new WSHttpBinding(),
                    "CalcService");


                // Step 4 of the hosting procedure: Enable metadata exchange.
                ServiceMetadataBehavior smb = new ServiceMetadataBehavior();
                smb.HttpGetEnabled = true;
                selfHost2.Description.Behaviors.Add(smb);

                // Step 5 of the hosting procedure: Start (and then stop) the service.
                selfHost2.Open();
                MessageBox.Show("Service2 is ready");

            }
            catch (CommunicationException ce)
            {
                MessageBox.Show("Kenjoza" + ce);
                selfHost2.Abort();
            }
        }

        private void btnStop2_Click(object sender, EventArgs e)
        {
            // Close the ServiceHostBase to shutdown the service.
            selfHost2.Close();
        }
    }
}

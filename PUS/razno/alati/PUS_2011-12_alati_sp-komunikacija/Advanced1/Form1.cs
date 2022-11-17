using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.ServiceModel.Description;
using System.ServiceModel;

namespace Microsoft.ServiceModel.Samples
{
    public partial class Form1 : Form
    {

        // Step 1 of the address configuration procedure: Create a URI to serve as the base address.
       // Uri baseAddress = new Uri("http://localhost:8000/ServiceModelSamples/Service");

        //Step 1: Create an endpoint address and an instance of the WCF Client.
        EndpointAddress epAddress = new EndpointAddress("http://localhost:8000/ServiceModelSamples/Service/CalcService");
        CalcClient client = new CalcClient();


        // Step 2 of the hosting procedure: Create ServiceHost
        ServiceHost selfHost = new ServiceHost(typeof(CalculatorService), new Uri("http://localhost:8000/ServiceModelSamples/Service"));

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
        }

        private void btnStart_Click(object sender, EventArgs e)
        {

            try
            {


                // Step 3 of the hosting procedure: Add a service endpoint.
                selfHost.AddServiceEndpoint(typeof(ICalculator),new WSHttpBinding(),"CalculatorService");


                // Step 4 of the hosting procedure: Enable metadata exchange.
                ServiceMetadataBehavior smb = new ServiceMetadataBehavior();
                smb.HttpGetEnabled = true;
                selfHost.Description.Behaviors.Add(smb);

                // Step 5 of the hosting procedure: Start (and then stop) the service.
                selfHost.Open();
                MessageBox.Show("Service is ready");

                // Close the ServiceHostBase to shutdown the service.
                /*ovo zajeb ? */
               // selfHost.Close();

            }
            catch (CommunicationException ce)
            {
                MessageBox.Show("Kenjoza" + ce);
                selfHost.Abort();
            }
        }

        private void btnStop_Click(object sender, EventArgs e)
        {
            // Close the ServiceHostBase to shutdown the service.
            /*ovo zajeb ? */
            selfHost.Close();
        }

        private void btnAdd2_Click(object sender, EventArgs e)
        {
            // Step 2: Call the service operations.
            // Call the Add service operation.
            double value1 = 100.00D;
            double value2 = 15.99D;
            double result = client.Add2(value1, value2);
            MessageBox.Show("Add2({" + value1.ToString() + "},{" + value2.ToString() + "}) = {" + result.ToString() + "}");
        }

        private void btnSub2_Click(object sender, EventArgs e)
        {
            // Call the Subtract service operation.
            double value1 = 145.00D;
            double value2 = 76.54D;
            double result = client.Subtract2(value1, value2);
            MessageBox.Show("Substract2({" + value1.ToString() + "},{" + value2.ToString() + "}) = {" + result.ToString() + "}");
        }

        private void btnMul2_Click(object sender, EventArgs e)
        {
            // Call the Multiply service operation.
            double value1 = 9.00D;
            double value2 = 81.25D;
            double result = client.Multiply2(value1, value2);
            MessageBox.Show("Multiply2({" + value1.ToString() + "},{" + value2.ToString() + "}) = {" + result.ToString() + "}");
        }

        private void btnDiv2_Click(object sender, EventArgs e)
        {
            // Call the Divide service operation.
            double value1 = 22.00D;
            double value2 = 7.00D;
            double result = client.Divide2(value1, value2);
            MessageBox.Show("Divide2({" + value1.ToString() + "},{" + value2.ToString() + "}) = {" + result.ToString() + "}");
        }

        private void btnClose2_Click(object sender, EventArgs e)
        {
            //Step 3: Closing the client gracefully closes the connection and cleans up resources.
            client.Close();
        }
    }
}

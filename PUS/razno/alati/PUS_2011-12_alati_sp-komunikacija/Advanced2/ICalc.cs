using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.ServiceModel;
using System.ServiceModel.Description;

namespace ServiceModelSamples
{
    [ServiceContract(Namespace = "http://Microsoft.ServiceModel.Samples")]
    public interface ICalc
    {
        [OperationContract]
        double Add2(double n1, double n2);
        [OperationContract]
        double Subtract2(double n1, double n2);
        [OperationContract]
        double Multiply2(double n1, double n2);
        [OperationContract]
        double Divide2(double n1, double n2);
    }
}

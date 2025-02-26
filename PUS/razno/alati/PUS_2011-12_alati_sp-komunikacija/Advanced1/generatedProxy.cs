﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.261
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------



[System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
[System.ServiceModel.ServiceContractAttribute(Namespace="http://Microsoft.ServiceModel.Samples", ConfigurationName="ICalc")]
public interface ICalc
{
    
    [System.ServiceModel.OperationContractAttribute(Action="http://Microsoft.ServiceModel.Samples/ICalc/Add2", ReplyAction="http://Microsoft.ServiceModel.Samples/ICalc/Add2Response")]
    double Add2(double n1, double n2);
    
    [System.ServiceModel.OperationContractAttribute(Action="http://Microsoft.ServiceModel.Samples/ICalc/Subtract2", ReplyAction="http://Microsoft.ServiceModel.Samples/ICalc/Subtract2Response")]
    double Subtract2(double n1, double n2);
    
    [System.ServiceModel.OperationContractAttribute(Action="http://Microsoft.ServiceModel.Samples/ICalc/Multiply2", ReplyAction="http://Microsoft.ServiceModel.Samples/ICalc/Multiply2Response")]
    double Multiply2(double n1, double n2);
    
    [System.ServiceModel.OperationContractAttribute(Action="http://Microsoft.ServiceModel.Samples/ICalc/Divide2", ReplyAction="http://Microsoft.ServiceModel.Samples/ICalc/Divide2Response")]
    double Divide2(double n1, double n2);
}

[System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
public interface ICalcChannel : ICalc, System.ServiceModel.IClientChannel
{
}

[System.Diagnostics.DebuggerStepThroughAttribute()]
[System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
public partial class CalcClient : System.ServiceModel.ClientBase<ICalc>, ICalc
{
    
    public CalcClient()
    {
    }
    
    public CalcClient(string endpointConfigurationName) : 
            base(endpointConfigurationName)
    {
    }
    
    public CalcClient(string endpointConfigurationName, string remoteAddress) : 
            base(endpointConfigurationName, remoteAddress)
    {
    }
    
    public CalcClient(string endpointConfigurationName, System.ServiceModel.EndpointAddress remoteAddress) : 
            base(endpointConfigurationName, remoteAddress)
    {
    }
    
    public CalcClient(System.ServiceModel.Channels.Binding binding, System.ServiceModel.EndpointAddress remoteAddress) : 
            base(binding, remoteAddress)
    {
    }
    
    public double Add2(double n1, double n2)
    {
        return base.Channel.Add2(n1, n2);
    }
    
    public double Subtract2(double n1, double n2)
    {
        return base.Channel.Subtract2(n1, n2);
    }
    
    public double Multiply2(double n1, double n2)
    {
        return base.Channel.Multiply2(n1, n2);
    }
    
    public double Divide2(double n1, double n2)
    {
        return base.Channel.Divide2(n1, n2);
    }
}

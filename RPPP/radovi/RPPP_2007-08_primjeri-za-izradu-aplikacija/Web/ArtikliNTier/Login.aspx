<%@ Page Language="C#" MasterPageFile="~/Artikli.master" AutoEventWireup="true" CodeFile="Login.aspx.cs" Inherits="Login" Title="RPPP - Internet trgovina - Prijava korisnia" %>
<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
    <asp:Login ID="Login1" runat="server" 
        FailureText="Prijava neuspješna." 
        LoginButtonText="Prijava" 
        PasswordLabelText="Zaporka:" 
        CssClass="menu_top" 
        DisplayRememberMe="False" 
        PasswordRequiredErrorMessage="" 
        RememberMeText="" 
        TitleText="Prijava korisnika" 
        UserNameLabelText="Korisnièko ime:" 
        UserNameRequiredErrorMessage="" BackColor="#F7F7DE" BorderColor="#CCCC99" BorderStyle="Solid" BorderWidth="1px" Font-Names="Verdana" Font-Size="10pt">
        
        <TextBoxStyle CssClass="upis_box" Width="150px" />
        <LoginButtonStyle CssClass="button" />
        <LabelStyle CssClass="menu_top" />
<TitleTextStyle BackColor="#6B696B" Font-Bold="True" ForeColor="#FFFFFF" />
    </asp:Login>
</asp:Content>


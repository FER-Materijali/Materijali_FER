<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>RPPP - Master-Detail</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
&nbsp;<asp:DropDownList ID="DropDownList1" runat="server" AutoPostBack="True" DataSourceID="SqlDataSource1"
DataTextField="NazDrzave" DataValueField="OznDrzave">
</asp:DropDownList><asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:FirmaConnectionString %>"
SelectCommand="SELECT [OznDrzave], [NazDrzave] FROM [Drzava] ORDER BY [NazDrzave]">
</asp:SqlDataSource>
<asp:GridView ID="GridView1" runat="server" AllowPaging="True" AllowSorting="True"
AutoGenerateColumns="False" BackColor="LightGoldenrodYellow" BorderColor="Tan" BorderWidth="1px"
CellPadding="2" DataSourceID="SqlDataSource2" ForeColor="Black" GridLines="None">
<PagerSettings Mode="NumericFirstLast" />
<FooterStyle BackColor="Tan" />
<Columns>
<asp:BoundField DataField="PostBrMjesta" HeaderText="Poštanski broj" SortExpression="PostBrMjesta" />
<asp:BoundField DataField="NazMjesta" HeaderText="Naziv mjesta" SortExpression="NazMjesta" />
<asp:BoundField DataField="PostNazMjesta" HeaderText="Poštanska oznaka mjesta" SortExpression="PostNazMjesta" />
</Columns>
<SelectedRowStyle BackColor="DarkSlateBlue" ForeColor="GhostWhite" />
<PagerStyle BackColor="PaleGoldenrod" ForeColor="DarkSlateBlue" HorizontalAlign="Center" />
<HeaderStyle BackColor="Tan" Font-Bold="True" />
<AlternatingRowStyle BackColor="PaleGoldenrod" />
</asp:GridView>
<asp:SqlDataSource ID="SqlDataSource2" runat="server" ConnectionString="<%$ ConnectionStrings:FirmaConnectionString %>"
SelectCommand="SELECT [NazMjesta], [PostBrMjesta], [PostNazMjesta] FROM [Mjesto] WHERE ([OznDrzave] = @OznDrzave)">
<SelectParameters>
<asp:ControlParameter ControlID="DropDownList1" Name="OznDrzave" PropertyName="SelectedValue"
Type="String" />
</SelectParameters>
</asp:SqlDataSource>
    
    </div>
    </form>
</body>
</html>

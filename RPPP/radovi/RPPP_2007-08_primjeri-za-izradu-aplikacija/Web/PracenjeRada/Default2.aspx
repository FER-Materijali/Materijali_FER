<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default2.aspx.cs" Inherits="Default2" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
      Ime u sessionu: <asp:Label ID="lblIme" runat="server" /> <br />
      Datum zadnje promjene: <asp:Label ID="lblDatum" runat="server" /> <br />
      <asp:HyperLink ID="HyperLink1" runat="server" NavigateUrl="~/Default.aspx">Povratak na poèetnu stranicu</asp:HyperLink>
    </div>
    </form>
</body>
</html>

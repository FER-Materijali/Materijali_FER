<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" Trace="true" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
      Unesite ime: <asp:TextBox ID="tbIme" runat="server"/>
      <br />
      <asp:Button ID="btnSpremi" runat="server" Text="Spremi ime" OnClick="btnSpremi_Click" />
      <asp:Button ID="btnKreni" runat="server" Text="Kreni" OnClick="btnKreni_Click" />
      </div>
    </form>
</body>
</html>

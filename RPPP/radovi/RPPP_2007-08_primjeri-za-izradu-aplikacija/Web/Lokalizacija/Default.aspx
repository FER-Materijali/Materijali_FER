<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" Culture="auto" UICulture="auto"  meta:resourcekey="PageResource1" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>Primjer lokalizacije</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
      <p>
      <asp:Localize ID="UvodniOpis" runat="server" meta:resourcekey="UvodniOpisResource1"/>
      </p>
      <p>
        <asp:Label ID="lblPozdrav" runat="server" /> , 
        <asp:Label ID="lblDatum" runat="server" />
      </p>
      &nbsp;<asp:Label ID="lblOdabir" runat="server" Text="Odaberite jedno od ponuđenih piva" meta:resourcekey="lblOdabirResource1"></asp:Label>
      <p>
      <asp:DropDownList ID="ddlOdabir" runat="server" AutoPostBack="True" meta:resourcekey="ddlOdabirResource1" OnSelectedIndexChanged="ddlOdabir_SelectedIndexChanged">
        <asp:ListItem meta:resourcekey="ListItemResource1" Text="Svijetlo pivo"></asp:ListItem>
        <asp:ListItem meta:resourcekey="ListItemResource2" Text="Tamno pivo"></asp:ListItem>
        <asp:ListItem meta:resourcekey="ListItemResource3" Text="Pšenično pivo"></asp:ListItem>
        <asp:ListItem meta:resourcekey="ListItemResource4" Text="Bezalkoholno pivo"></asp:ListItem>
      </asp:DropDownList>      
      </p>
      <asp:Label ID="lblOdabranaStavka" runat="server" meta:resourcekey="lblOdabranaStavkaResource1"/>
      <br /><br />
      <asp:Button ID="btnHR" runat="server" Text="Hrvatski" meta:resourcekey="btnHRResource1" OnClick="btnHR_Click" />
      <asp:Button ID="btnEN" runat="server" Text="Engleski" meta:resourcekey="btnENResource1" OnClick="btnEN_Click" />      
    </div>
    </form>
</body>
</html>

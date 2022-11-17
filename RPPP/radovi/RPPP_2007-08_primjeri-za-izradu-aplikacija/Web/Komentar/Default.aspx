<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default"  %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>Komentar</title>
</head>
<body>
  <form id="form1" runat="server">
    <div>
      Popunite obavezne podatke, napišite vlastiti komentar i pošaljite ga autorima ove stranice:<br />
      Ja sam:  
      <asp:RadioButtonList ID="rblStatus" runat="server" AutoPostBack="True" OnSelectedIndexChanged="rblStatus_SelectedIndexChanged">
        <asp:ListItem Value="S">Student</asp:ListItem>
        <asp:ListItem Value="P">Promatrač</asp:ListItem>
      </asp:RadioButtonList>
      <br />
      <asp:Label ID="lblGodinaStudija" runat="server" Text="Trenutna godina studija" Visible="False"></asp:Label>
      <asp:TextBox ID="tbGodinaStudija" runat="server" Visible="False"></asp:TextBox>
      <asp:RequiredFieldValidator ID="GodinaValidator1" runat="server" ControlToValidate="tbGodinaStudija"
        ErrorMessage="Godina studija mora biti unesena" Enabled="false"/>
      <asp:RegularExpressionValidator ID="RegularExpressionValidator1" runat="server" ControlToValidate="tbGodinaStudija"
        ErrorMessage="Godina studija mora biti između 1 i 5" ValidationExpression="[1-5]"/><br />
      Poznajem sljedeće programske jezike:<br />
      <asp:ListBox ID="lbxJezici" runat="server" Rows="7" SelectionMode="Multiple">
        <asp:ListItem>Basic</asp:ListItem>
        <asp:ListItem>C</asp:ListItem>
        <asp:ListItem>C++</asp:ListItem>
        <asp:ListItem>C#</asp:ListItem>
        <asp:ListItem>Pascal</asp:ListItem>
        <asp:ListItem>Perl</asp:ListItem>
        <asp:ListItem>PHP</asp:ListItem>
      </asp:ListBox>
      <br />
      Moj komentar: <br /> <asp:TextBox ID="tbKomentar" runat="server" MaxLength="500" Rows="5" TextMode="MultiLine" Width="300px"></asp:TextBox> 
      <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" ControlToValidate="tbKomentar"
        ErrorMessage="Komentar mora biti popunjen"/>
      <asp:Button ID="btnPosalji" runat="server" Text="Pošalji" OnClick="btnPosalji_Click" />&nbsp;
    </div>
 </form>
</body>
</html>

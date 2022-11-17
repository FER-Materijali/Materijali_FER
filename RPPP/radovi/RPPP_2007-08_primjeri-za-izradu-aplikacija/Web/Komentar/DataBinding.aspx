<%@ Page Language="C#" AutoEventWireup="true" CodeFile="DataBinding.aspx.cs" Inherits="DataBinding" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head id="Head1" runat="server">
    <title>Komentar - prošireni</title>
</head>
<body>
  <form id="form1" runat="server">
    <div>
      <asp:Label ID="lblTrenutniDatum" runat="server" Text="<%# MyProperty %>"/>
      <br />
      Popunite obavezne podatke, napišite vlastiti komentar i pošaljite ga autorima ove stranice:<br />
      Ja sam:  
      <asp:RadioButtonList ID="rblStatus" runat="server" AutoPostBack="True" OnSelectedIndexChanged="rblStatus_SelectedIndexChanged">
        <asp:ListItem Value="S">Student</asp:ListItem>
        <asp:ListItem Value="P">Promatraè</asp:ListItem>
      </asp:RadioButtonList>
      <br />
      <asp:Label ID="lblGodinaStudija" runat="server" Text="Trenutna godina studija" Visible="False"></asp:Label>
      <asp:TextBox ID="tbGodinaStudija" runat="server" Visible="False"></asp:TextBox>
      <asp:RequiredFieldValidator ID="GodinaValidator1" runat="server" ControlToValidate="tbGodinaStudija"
        ErrorMessage="Godina studija mora biti unesena" Enabled="false"/>
      <asp:RegularExpressionValidator ID="RegularExpressionValidator1" runat="server" ControlToValidate="tbGodinaStudija"
        ErrorMessage="Godina studija mora biti izmeðu 1 i 5" ValidationExpression="[1-5]"></asp:RegularExpressionValidator><br />
      Poznajem sljedeæe programske jezike:<br />
      <asp:ListBox ID="lbxJezici" runat="server" Rows="7" SelectionMode="Multiple">       
      </asp:ListBox>
      <br />
      Moj komentar: <br /> <asp:TextBox ID="tbKomentar" runat="server" MaxLength="500" Rows="5" TextMode="MultiLine" Width="300px"></asp:TextBox> 
      <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" ControlToValidate="tbKomentar"
        ErrorMessage="Komentar mora biti popunjen"></asp:RequiredFieldValidator><br />
      <asp:Button ID="btnPosalji" runat="server" Text="Pošalji" OnClick="btnPosalji_Click" />&nbsp;
    </div>
 </form>
</body>
</html>

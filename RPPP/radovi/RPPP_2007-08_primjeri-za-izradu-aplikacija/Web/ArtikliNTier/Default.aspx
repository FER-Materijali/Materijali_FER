<%@ Page Language="C#" MasterPageFile="~/Artikli.master" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" Title="RPPP - Web shop" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
    <table id="Table1" border="0" cellpadding="2" cellspacing="2" runat="server">
    <tr valign="top">
        <td style="width:70%">
            <asp:Label runat="server" ID="lblAritkli" Text="Artikli u ponudi" /><br />
            <asp:GridView ID="GridViewArtikli" runat="server" AutoGenerateColumns="False" BackColor="LightGoldenrodYellow"
                BorderColor="Tan" BorderWidth="1px" CellPadding="2" DataKeyNames="SifArtikla"
                DataSourceID="ObjectDataSourceArtikli" ForeColor="Black" GridLines="None" OnRowCommand="GridView1_RowCommand" AllowPaging="True" OnRowDataBound="GridViewArtikli_RowDataBound" AllowSorting="False">
                <FooterStyle BackColor="Tan" />
                <Columns>
					<asp:BoundField DataField="SifArtikla" HeaderText="SifArtikla" SortExpression="SifArtikla" />
					<asp:BoundField DataField="NazArtikla" HeaderText="NazArtikla" SortExpression="NazArtikla" />
					<asp:BoundField DataField="JedMjere" HeaderText="JedMjere" SortExpression="JedMjere" />
					<asp:BoundField DataField="CijArtikla" HeaderText="CijArtikla" DataFormatString="{0:N2}" SortExpression="CijArtikla" ItemStyle-HorizontalAlign="Right" />
					 <asp:ButtonField ButtonType="Button" CommandName="Stavi" Text="Stavi u košaricu" />
                </Columns>
                <SelectedRowStyle BackColor="DarkSlateBlue" ForeColor="GhostWhite" />
                <PagerStyle BackColor="PaleGoldenrod" ForeColor="DarkSlateBlue" HorizontalAlign="Center" />
                <HeaderStyle BackColor="Tan" Font-Bold="True" />
                <AlternatingRowStyle BackColor="PaleGoldenrod" />
            </asp:GridView>
            <asp:ObjectDataSource ID="ObjectDataSourceArtikli" runat="server" SelectMethod="FetchAll"
                TypeName="Firma.ArtiklBllProvider"></asp:ObjectDataSource>
        </td>
    </tr>
    <tr>        
        <td>
            Košarica <br />
           <asp:GridView ID="GridViewKosarica" runat="server" AllowPaging="True" AutoGenerateColumns="False" ShowFooter="True"
                CellPadding="4" DataSourceID="ObjectDataSourceKosarica" ForeColor="#333333" GridLines="None" DataKeyNames="SifArtikla">
                <FooterStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
                <Columns>
                    <asp:BoundField DataField="SifArtikla" HeaderText="Šifra artikla" SortExpression="SifArtikla" ReadOnly="True" />
                    <asp:BoundField DataField="JedMjereArtikla" HeaderText="Jedinična mjera" SortExpression="JedMjere" ReadOnly="True" />
                    <asp:BoundField DataField="NazArtikla" HeaderText="Naziv" SortExpression="NazArtikla" ReadOnly="True" />
                    <asp:BoundField DataField="JedCijArtikla" HeaderText="Jedinična cijena" SortExpression="CijArtikla" DataFormatString="{0:N2}" ReadOnly="True" ItemStyle-HorizontalAlign="Right" />
                    <asp:BoundField DataField="KolArtikla" HeaderText="Količina" />
                    <asp:TemplateField HeaderText="Iznos" ItemStyle-HorizontalAlign="Right">                        
                        <ItemTemplate>
                            <asp:Label ID="Label1" runat="server" Text='<%# Eval("Iznos", "{0:N2}") %>'></asp:Label>
                        </ItemTemplate>
                        <FooterTemplate>
                            <asp:Label ID="lblTotal" runat="server" Text='<%# KosaricaController.Ukupno().ToString("N2") %>' />
                        </FooterTemplate>
                    </asp:TemplateField>                    
                    <asp:CommandField ButtonType="Button" CancelText="Odustani" EditText="Promijeni količinu"
                        ShowEditButton="True" UpdateText="Spremi" />
                    <asp:CommandField ShowDeleteButton="True" DeleteText="Izbaci iz košarice" ButtonType="Button" />
                </Columns>
                <RowStyle BackColor="#F7F6F3" ForeColor="#333333" />
                <EditRowStyle BackColor="#999999" />
                <SelectedRowStyle BackColor="#E2DED6" Font-Bold="True" ForeColor="#333333" />
                <PagerStyle BackColor="#284775" ForeColor="White" HorizontalAlign="Center" />
                <HeaderStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
                <AlternatingRowStyle BackColor="White" ForeColor="#284775" />                
                <EmptyDataTemplate>
                    Vaša košarica je prazna
                </EmptyDataTemplate>                
            </asp:GridView>
            <asp:ObjectDataSource ID="ObjectDataSourceKosarica" runat="server" SelectMethod="DohvatiArtikle"
                TypeName="KosaricaController" UpdateMethod="AzurirajKolicinu" DeleteMethod="IzbrisiArtikl">                
                <UpdateParameters>
                    <asp:Parameter Name="KolArtikla" Type="Int32" />
                    <asp:Parameter Name="SifArtikla" Type="Int32" />
                </UpdateParameters>
                <DeleteParameters>
                    <asp:Parameter Name="SifArtikla" Type="Int32" />
                </DeleteParameters>
            </asp:ObjectDataSource> 
        </td>
    </tr>
    <tr>
        <td>
            &nbsp;<asp:HyperLink ID="hlPlacanje" runat="server" NavigateUrl="Placanje.aspx">Plaćanje</asp:HyperLink></td>
    </tr>
    </table>        
</asp:Content>
<%@ Page Language="C#" MasterPageFile="~/Artikli.master" AutoEventWireup="true" CodeFile="Placanje.aspx.cs" Inherits="Placanje" Title="RPPP - WebApps - Plaæanje narudžbe" %>
<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
    <asp:HyperLink ID="HyperLink1" runat="server" NavigateUrl="~/Default.aspx">Povratak na odabir artikala</asp:HyperLink>
    <asp:Wizard ID="Wizard1" runat="server" BackColor="#F7F6F3" BorderColor="#CCCCCC" BorderStyle="Solid" BorderWidth="1px" Font-Names="Verdana" Font-Size="0.8em" CancelButtonText="Odustani" FinishCompleteButtonText="Potvrdi kupnju" FinishPreviousButtonText="Prethodni korak" StartNextButtonText="Dalje" StepNextButtonText="Dalje" StepPreviousButtonText="Prethodni korak" ActiveStepIndex="0" OnFinishButtonClick="Wizard1_FinishButtonClick" OnNextButtonClick="Wizard1_NextButtonClick">
        <wizardsteps>             
            <asp:WizardStep ID="WizardStep2" title="Podaci o dostavi" runat="server" StepType="Start">
                <asp:Repeater ID="KosaricaRepeater" runat="server" DataSourceID="ArtikliObjectDataSource">
                    <HeaderTemplate>
                        <table border="1" cellpadding="2" cellspacing="2" width="100%">
                    </HeaderTemplate>
                    <ItemTemplate>
                        <tr>
                            <td>
                                <%# Eval("NazArtikla") %>
                            </td>
                            <td>
                                <%# Eval("KolArtikla")%>
                            </td>
                            <td align="right">
                                <%# Eval("JedCijArtikla") %>
                            </td>
                            <td align="right">
                                <%# Eval("Iznos", "{0:N2}") %>
                            </td>
                        </tr>                        
                    </ItemTemplate>                    
                    <FooterTemplate>
                        <tr>
                            <td colspan="3" align="right">
                                Ukupno:
                            </td>
                            <td align="right">
                                <%# KosaricaController.Ukupno().ToString("N2") %>
                            </td>
                        </tr>
                        </table>                        
                    </FooterTemplate>
                </asp:Repeater>
                <asp:ObjectDataSource ID="ArtikliObjectDataSource" runat="server" SelectMethod="DohvatiArtikle"
                    TypeName="KosaricaController"></asp:ObjectDataSource>
                    <hr />
                <table>
                    <tr>                        
                        <td>
                            <asp:Label ID="lblMBR" runat="server" Text="Matièni broj:"></asp:Label>
                        </td>
                        <td>
                            <asp:TextBox ID="tbMBR" runat="server" MaxLength="30"></asp:TextBox>
                        </td>
                    </tr>
                    <tr>
                        <td>
                            Ukoliko ste veæ kupovali možete dohvatiti postojeæe podatke za navedeni matièni broj
                        </td>
                        <td>
                            <asp:Button id="btnDohvatiPodatke" runat="server" Text="Dohvati podatke" OnClick="btnDohvatiPodatke_Click" />                            
                        </td>
                    </tr>
                    <tr>                        
                        <td>
                            <asp:Label ID="lblImePrezime" runat="server" Text="Prezime ili naziv tvrtke:"></asp:Label>
                        </td>
                        <td>
                            <asp:TextBox ID="tbImePrezime" runat="server" MaxLength="50"></asp:TextBox>
                        </td>
                    </tr>
                    <tr>                        
                        <td>
                            Adresa raèuna
                        </td>
                        <td>
                            <asp:TextBox ID="tbAdresaRacuna" runat="server" MaxLength="50"></asp:TextBox>
                        </td>
                    </tr>
                    <tr>                        
                        <td>
                            Adresa isporuke
                        </td>
                        <td>
                            <asp:TextBox ID="tbAdresaIsporuke" runat="server" MaxLength="50"></asp:TextBox>
                        </td>
                    </tr>
                    <tr>                        
                        <td>
                            <asp:Label ID="lblEmail" runat="server" Text="E-mail"></asp:Label>
                        </td>
                        <td>
                            <asp:TextBox ID="tbEmail" runat="server"></asp:TextBox>
                            &nbsp;
                        </td>
                    </tr>
                    <tr>                        
                        <td>
                            Naèin dostave
                        </td>
                        <td>
                            <asp:DropDownList ID="ddlVrstaDostave" runat="server">
                                <asp:ListItem Value="P">Poštom</asp:ListItem>
                                <asp:ListItem Value="KD">Kurirska dostava</asp:ListItem>
                            </asp:DropDownList>
                        </td>
                    </tr>
                    <tr>                        
                        <td colspan="2">
                            <asp:Label ID="lblPodaciNepotpuni" runat="server" Text="Podaci su nepotpuni." ForeColor="Red" Visible="False"></asp:Label>
                        </td>
                    </tr>                            
                </table>                
            </asp:WizardStep> 
            <asp:WizardStep ID="WizardStep3" title="Izraèun ukupne cijene" runat="server">
                <asp:Repeater ID="KosaricaRepeater2" runat="server" DataSourceID="ArtikliObjectDataSource">
                    <HeaderTemplate>
                        <table border="1" cellpadding="2" cellspacing="2" width="600px">
                    </HeaderTemplate>
                    <ItemTemplate>
                        <tr>
                            <td>
                                <%# Eval("NazArtikla") %>
                            </td>
                            <td>
                                <%# Eval("KolArtikla")%>
                            </td>
                            <td align="right">
                                <%# Eval("JedCijArtikla")%>
                            </td>
                            <td align="right">
                                <%# Eval("Iznos", "{0:N2}") %>
                            </td>
                        </tr>                        
                    </ItemTemplate>                    
                    <FooterTemplate>
                        <tr>
                            <td colspan="3" align="right">
                                Ukupno:
                            </td>
                            <td align="right">
                                <%# KosaricaController.Ukupno().ToString("N2") %>
                            </td>
                        </tr>
                        </table>                        
                    </FooterTemplate>
                </asp:Repeater>                
                <table border="1" cellpadding="2" cellspacing="2" width="600px">
                    <tr>
                        <td>Poštarina:</td>
                        <td align="right"><asp:Label ID="lblPostarina" runat="server"></asp:Label> </td>
                    </tr>
                    <tr>
                        <td>Ukupna cijena:</td>
                        <td align="right"><asp:Label ID="lblUkupnaCijena" runat="server" Font-Bold="True"></asp:Label> </td>
                    </tr>
                </table>
            </asp:WizardStep> 
            <asp:WizardStep ID="WizardStep4" title="Unos podataka o plaæanju" runat="server" StepType="Finish">
                <table border="1" cellpadding="2" cellspacing="2" width="100%">
                    <tr>
                        <td>
                            <asp:Label ID="lblVlasnikKartice" runat="server" Text="Vlasnik kartice"/>
                        </td>
                        <td>
                            <asp:TextBox ID="tbVlasnik" runat="server" Width="300px"></asp:TextBox>        
                        </td>
                    </tr>                
                    <tr>
                        <td>
                            <asp:Label ID="lblVrstaKartice" runat="server" Text="Vrsta kartice i datum važenja"/>
                        </td>
                        <td>
                            <asp:DropDownList ID="ddlVrstaKartice" runat="server">
                                <asp:ListItem Value="MC">MasterCard</asp:ListItem>
                                <asp:ListItem Value="AMEX">American Express</asp:ListItem>
                                <asp:ListItem>Diners</asp:ListItem>
                                <asp:ListItem>Visa</asp:ListItem>
                            </asp:DropDownList>
                            <asp:DropDownList ID="ddlMjesec" runat="server">
                                <asp:ListItem>1</asp:ListItem>
                                <asp:ListItem>2</asp:ListItem>
                                <asp:ListItem>3</asp:ListItem>
                                <asp:ListItem>4</asp:ListItem>
                                <asp:ListItem>5</asp:ListItem>
                                <asp:ListItem>6</asp:ListItem>
                                <asp:ListItem>7</asp:ListItem>
                                <asp:ListItem>8</asp:ListItem>
                                <asp:ListItem>9</asp:ListItem>
                                <asp:ListItem>10</asp:ListItem>
                                <asp:ListItem>11</asp:ListItem>
                                <asp:ListItem>12</asp:ListItem>
                            </asp:DropDownList>
                            <asp:DropDownList ID="ddlGodina" runat="server">
                                <asp:ListItem>2008</asp:ListItem>
                                <asp:ListItem>2009</asp:ListItem>
                                <asp:ListItem>2010</asp:ListItem>
                                <asp:ListItem>2011</asp:ListItem>
                                <asp:ListItem>2012</asp:ListItem>
                                <asp:ListItem>2013</asp:ListItem>
                                <asp:ListItem>2014</asp:ListItem>
                            </asp:DropDownList>      
                        </td>
                    </tr>
                    <tr>
                        <td>
                            <asp:Label ID="lblBrojKartice" runat="server" Text="Broj kartice"/>
                        </td>
                        <td>
                            <asp:TextBox ID="tbBrojKartice" runat="server" Width="300px"></asp:TextBox>        
                        </td>
                    </tr> 
                    <tr>
                        <td colspan="2">
                            <asp:Label ID="lblGreska" runat="server" ForeColor="Red" Visible="False"></asp:Label>
                        </td>
                    </tr>
                </table>                
            </asp:WizardStep> 
            <asp:WizardStep ID="WizardStep5" title="Potvrda" runat="server" StepType="Complete">                
                Vaša narudžba je uspješno obraðena. E-mail s potvrdom narudžbe je poslan na vašu e-mail adresu.                
                <asp:Panel ID="RacunPanel" runat="server"> 
                    <table border="1" cellpadding="2" cellspacing="2">
                        <tr>
                            <td colspan="2">
                                <asp:Label ID="lblDatum" runat="server"/>
                            </td>
                            <td>Broj raèuna</td>
                            <td><asp:Label ID="lblBrojRacuna" runat="server" /></td>
                        </tr>
                        <tr>
                            <td>Kupac</td>
                            <td><asp:Label ID="lblKupac" runat="server" /></td>
                            <td>Matièni broj</td>
                            <td><asp:Label ID="lblMaticniBroj" runat="server" /></td>
                        </tr>
                        <tr>                            
                            <td>Adresa raèuna</td>
                            <td colspan="3"><asp:Label ID="lblAdresaRacuna" runat="server" /></td>
                        </tr>
                        <tr>                            
                            <td>Adresa isporuke</td>
                            <td colspan="3"><asp:Label ID="lblAdresaIsporuke" runat="server" /></td>
                        </tr>                    
                        <tr>                            
                            <td>Naèin dostave</td>
                            <td><asp:Label ID="lblNacinDostave" runat="server" /></td>
                        </tr>
                    </table>                           
                    <asp:Repeater ID="RacunRepeater" runat="server" DataSourceID="ArtikliObjectDataSource">
                        <HeaderTemplate>
                            <table border="1" cellpadding="2" cellspacing="2" width="600px">
                        </HeaderTemplate>
                        <ItemTemplate>
                            <tr>
                                <td>
                                    <%# Eval("NazArtikla") %>
                                </td>
                                <td>
                                    <%# Eval("KolArtikla")%>
                                </td>
                                <td align="right">
                                    <%# Eval("JedCijArtikla")%>
                                </td>
                                <td align="right">
                                    <%# Eval("Iznos", "{0:N2}") %>
                                </td>
                            </tr>                        
                        </ItemTemplate>                    
                        <FooterTemplate>
                            <tr>
                                <td colspan="3" align="right">
                                    Ukupno:
                                </td>
                                <td align="right">
                                    <%# KosaricaController.Ukupno().ToString("N2") %>
                                </td>
                            </tr>
                            </table>                        
                        </FooterTemplate>
                    </asp:Repeater>
                    <table border="1" cellpadding="2" cellspacing="2" width="600px">
                        <tr>
                            <td>Poštarina:</td>
                            <td align="right"><asp:Label ID="lblPostarina2" runat="server"></asp:Label> </td>
                        </tr>
                        <tr>
                            <td>Ukupna cijena:</td>
                            <td align="right"><asp:Label ID="lblUkupnaCijena2" runat="server" Font-Bold="True"></asp:Label> </td>
                        </tr>
                        <tr>
                            <td>Kreditna kartica i broj autorizacije:</td>
                            <td align="right"><asp:Label ID="lblBrojAutorizacije" runat="server"></asp:Label> </td>
                        </tr>                        
                    </table>
                </asp:Panel>                                 
            </asp:WizardStep>             
        </wizardsteps>
        <StepStyle BorderWidth="0px" ForeColor="#5D7B9D" />
        <SideBarStyle BackColor="#7C6F57" BorderWidth="0px" Font-Size="0.9em" VerticalAlign="Top" />
        <NavigationButtonStyle BackColor="#FFFBFF" BorderColor="#CCCCCC" BorderStyle="Solid"
            BorderWidth="1px" Font-Names="Verdana" Font-Size="0.8em" ForeColor="#284775" />
        <SideBarButtonStyle BorderWidth="0px" Font-Names="Verdana" ForeColor="White" />
        <HeaderStyle BackColor="#5D7B9D" BorderStyle="Solid" Font-Bold="True" Font-Size="0.9em"
            ForeColor="White" HorizontalAlign="Left" />
        <NavigationStyle VerticalAlign="Top" />
    </asp:Wizard>
    <asp:Label ID="lblEmailGreska" runat="server" ForeColor="red" />
</asp:Content>


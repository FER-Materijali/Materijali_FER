<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
	<xsl:output method="xml" indent="yes"
				doctype-system="http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd"
				doctype-public="-//W3C//DTD XHTML 1.0 Strict//EN" />
  
	<xsl:template match="/">
		<html xmlns="http://www.w3.org/1999/xhtml">
			<head>
				<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
				<link rel="stylesheet" type="text/css" href="dizajn.css" />
				<title>Telefonski imenik</title>
				
				<link rel="shortcut icon" href="images/phone_icon_tab.png" />
				<script type="text/javascript" src="js/jquery-1.7.1.min.js"></script>
				<script type="text/javascript" src="js/jquery-ui-1.8.18.custom.min.js"></script>
			</head>
      
			<body>
			
				<div id="wrapper">
					<div id="main">
						<div id="header">
							<h1>
								<a href="index.html" id="title">
									<img src="images/phone_icon.png" alt="phone" />
									Telefonski Imenik
								</a>
							</h1>
						</div>

						<div id="menu">
							<ul>
								<li><a href="index.html">Početna</a></li>
								<li><a href="obrazac.html">Pretraga</a></li>
								<li class="active"><a href="podaci.xml">Pregled</a></li>
								<li><a href="http://www.rasip.fer.hr/">Rasip</a></li>
								<li><a href="http://www.fer.hr/" target="_blank">Fer</a></li>
								<li><a href="mailto:matej.miklecic@fer.hr">Kontakt</a></li>
							</ul>
						</div>
						
						<div id="content">
						
							<h2>
								Pregled Telefonskog Imenika
							</h2>
							
							<br />
							<br />
							
							<div id="pretraga">
							
								<table class="fancy" summary="Pretraga telefonskog imenika">
									<thead>
										<tr>
											<th>Ime &amp; Prezime</th>
											<th>Broj Telefona</th>
											<th>Adresa</th>
											<th>Email</th>
										</tr>
									</thead>
									
									<tbody>
										<xsl:for-each select="/telefonski_imenik/osoba">
											<!-- <xsl:sort select="prezime" /> -->
											<tr>
												<td>
													<xsl:value-of select="ime" />
													<xsl:text> </xsl:text>
													<xsl:value-of select="prezime" />
												</td>
												<td>
													<xsl:for-each select="telefon">
														(<xsl:value-of select="broj/@pozivni_broj" />)
														<xsl:text> </xsl:text>
														<xsl:value-of select="broj" />
														<br />
													</xsl:for-each>
												</td>
												<td>
													<xsl:if test="string(adresa/ulica)">
														<xsl:value-of select="adresa/ulica" />
														<xsl:text> </xsl:text>
														<xsl:value-of select="adresa/kucni_broj" />,
														<xsl:value-of select="adresa/mjesto/@postanski_broj" />
														<xsl:text> </xsl:text>
														<xsl:value-of select="adresa/mjesto" />
													</xsl:if>
												</td>
												<td>
													<xsl:for-each select="mail_adresa">
														<xsl:value-of select="." />
														<br />
													</xsl:for-each>
												</td>
											</tr>
										</xsl:for-each>
									</tbody>
									
									<tfoot>
										<tr>
											<td> </td>
											<td> </td>
											<td> </td>
											<td> </td>
										</tr>
									</tfoot>
								</table>
							</div>
						</div>
					</div>
				</div>
				
				<div id="footer">
					<a href="http://creativecommons.org/licenses/by-nc-nd/3.0/hr/legalcode" target="_blank">
						© 2012 Matej Miklečić
					</a>
				</div>
					
			</body>
		</html>
	</xsl:template>
</xsl:stylesheet>
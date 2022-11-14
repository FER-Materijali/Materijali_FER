<?xml  version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"> 
<xsl:output method="xml" indent="yes" doctype-system="http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd" doctype-public="-//W3C//DTD XHTML 1.0 Strict//EN" />
	
	
	<xsl:template match="/">
		
		<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="hr">

		<head>

			<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">	</meta>
			<meta name="description" content="Popis poslovnica marke Citroën"> </meta>
			<meta name="keywords" content="Citroën, poslovnice, HTML, CSS, vježba, OR, FER"> </meta>
			<meta name="author" content="0036467500"> </meta>
			<link rel="stylesheet" type="text/css" href="dizajn.css"> </link>
			<title>Popis poslovnica</title>
		</head>
	
		<body>
	
			<div id="header">
				<a id="hlink" href="index.html">
				<img src="slika1.jpg" alt="Slika1.jpg" width="75" height="75" /></a><h1 id="hnaslov">Popis poslovnica marke Citroën</h1>
				
			</div>
			<div id="container">
			
			<div id="navigation">
			
			<ul id="lista">
				<li><a class="link" href="index.html">Home</a></li>
				<li><a class="link" href="podaci.xml">XML Podaci</a></li>
				<li><a class="link" href="obrazac.html">Pretraživanje</a></li>
				<li><a class="link" href="http://www.fer.unizg.hr/predmet/or">FER Otvoreno Računarstvo</a></li>
				<li><a class="link" href="http://www.fer.hr/" target="_blank">FER Početna stranica</a></li>
				<li><a class="link" href="mailto:">Pošalji e-mail</a></li>
			</ul>
	
			</div>
			
			<div id="body">
				<table id="xml">
					<tr>
						<th>Ime poslovnice</th>
						<th>Modeli</th>
						<th>Radno vrijeme</th>
						<th>Adresa</th>
						<th>Usluga</th>
					</tr>
					<xsl:for-each select="/poslovnice/poslovnica">
						<tr>
							<td>
									<xsl:variable name="id">
											<xsl:value-of select="fid" /> 
									</xsl:variable>
								
									<a href="https://facebook.com/{$id}"><xsl:value-of select="ime"/></a>
								
							</td>
							<td>
								<xsl:for-each select="modeli">
									<xsl:value-of select="vrsta" /> - <xsl:value-of select="starost" /> <br />
								</xsl:for-each>
							</td>
							<td>
								Početak: <xsl:value-of select="rvrijeme/radnop" /><br />
								Kraj: <xsl:value-of select="rvrijeme/radnok" /><br />
							</td>
							<td>
								Ulica: <xsl:value-of select="ulica" /> <xsl:text>&#160;</xsl:text> <xsl:value-of select="br" />, <xsl:value-of select="grad" />
								
							</td>
							<td>
								Dostupne usluge: 
								<xsl:for-each select="modeli/popis">
									<xsl:value-of select="usluga" />
									<xsl:if test="position() != last()">
										<xsl:text>, </xsl:text>
									</xsl:if>
									<xsl:if test="not(usluga)">
										<xsl:text>--</xsl:text>
									</xsl:if>
									
								</xsl:for-each>
							</td>
						</tr>
					</xsl:for-each>
				</table>
			</div>
			</div>
		<div id="footer">
			Autor: sipe 2015
		</div>
			
		   
	
      </body>
    </html>
  </xsl:template>
	
</xsl:stylesheet> 
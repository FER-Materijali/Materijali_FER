<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:output method="xml" indent="yes" doctype-system="http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd" doctype-public="- //W3C//DTD XHTML 1.0 Strict//EN" />
<xsl:template match="/">
<html xmlns="http://www.w3.org/1999/xhtml">



	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
		<title>Podatci</title>
		<link rel="stylesheet" type="text/css" href="dizajn.css"/>
	</head>	
	
	<body>
		<div class="zaglavlje">
			<div class="logo"><a href="index.html"><img src="znak1.jpg" alt="logo" /></a></div>
			<div class="naslov"><h1 class="naslov">Košarkaški klubovi Eurolige</h1></div>		
		</div>		
			
	<div class="izbor" >
	<ul  id="izbornik" style="list-style-type:none">
	<li class="izbor"><a class="link" href="index.html">Naslovna</a></li> 		
	<li class="izbor"><a class="link" href="obrazac.html">Pretraživanje klubova</a></li>
	<li class="izbor"><a class="link" href="podaci.xml">Podatci</a></li> 
	<li class="izbor"><a class="link"  href="http://www.fer.hr">fer.hr</a></li> 				
	<li class="izbor"><a class="link" href="http://www.fer.unizg.hr/predmet/or" 
		onclick="window.open(this.href, '_blank');return false;" >OR</a></li> 
	<li class="izbor"><a class="link" href="mailto:fer.hr">email me</a></li>
	</ul>
	</div>	
			
			
			
			
		<div class="prvi" > 
		<table>
		<tr>	<th>Ime kluba</th>
				<th>Drzava</th>
				<th>Grad</th>
				<th>Predsjednik</th>
				<th>Kapacitet</th>
				<th>Navijaci</th>
				<th>Trofeji</th>
				<th>Redovit član</th>
				<th>Kontakt tel</th>		
		</tr>
		
		<xsl:for-each select="/klubovi/klub">
		<tr>
							<td><xsl:value-of select="ime" /></td>
									
							<td><xsl:value-of select="@drzava"/></td>
					
							<td><xsl:value-of select="grad" /></td>
							
							<td>
								<xsl:value-of select="predsjednik/imepred" />
								<br/>
								<xsl:value-of select="predsjednik/prezimepred" />
							</td>
							
							<td><xsl:value-of select="kapacitet" /></td>
							
							<td><xsl:value-of select="navijaci" /></td>
							
							<td><xsl:value-of select="trofeji" /></td>
							
							<td><xsl:value-of select="@redovit"/></td>
							
							<td>
								<xsl:for-each select="kontakt/tel">
								<xsl:value-of select="text()"/>
								<br/>
								</xsl:for-each>
							</td>	
								
		</tr>
				</xsl:for-each>
				</table>
		</div>

		<div class="footer" ><p class="foot">autor: karonja</p></div>
      </body>
	  
    </html>
  </xsl:template>
</xsl:stylesheet> 
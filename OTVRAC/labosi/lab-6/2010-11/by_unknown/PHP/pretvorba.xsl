<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output method="xml" indent="yes" doctype-system="http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd" doctype-public="- //W3C//DTD XHTML 1.0 Strict//EN" />
  
  <xsl:template match="/">
    <html xmlns="http://www.w3.org/1999/xhtml">
      <head>
        <meta http-equiv="Content-Type" content="text/html;charset=utf-8" />
        <script src="js/jquery.min.js"></script>
        <link rel="stylesheet" type="text/css" href="dizajn.css" />
        <script type="text/javascript" src="js/jquery.dimensions.min.js"></script>
        <script type="text/javascript" src="js/jquery.tooltip.min.js"></script>
        <script>
        $(document).ready(function(){
          $("tr").tooltip();
        });
        </script>
        <title>Knjižnica</title>
      </head>
      
      <body>
        <div id="header">
          <a href="index.html">
            <img src="images/logo.png" alt="" class="image" border="0" />
          </a>
          <a href="index.html" id="header_text">
            Nacionalna i sveučilišna knjižnica
          </a>
        </div>

        <div id="menu">
          <ul>
            <li><a href="index.html" title="tu treba raditi">Početna stranica</a></li>
            <li><a href="podaci.xml" title="tu treba raditi">Katalog knjiga</a></li>
            <li><a href="obrazac.html" title="tu treba raditi">Pretraga</a></li>
            <li><a href="http://www.rasip.fer.hr/" title="tu treba raditi">RASIP</a></li>
            <li><a href="http://www.fer.hr/" target="_blank" title="tu treba raditi">FER</a></li>
            <li>
              <a>
                <xsl:attribute name="href">mailto:Viktor.Fonic@FER.hr</xsl:attribute>
                Kontakt (e-mail)
              </a>
            </li>
          </ul>
        </div>
        
        <div id="content">
          <h1>Katalog knjiga</h1>
          <table class="table_stripes" width="1000px">
            <tr title="asd">
              <th>Naslov</th>
              <th>Autor</th>
              <th class="center">Izdanje</th>
              <th class="center">Ostali podaci</th>
              <th>Recenzije</th>
            </tr>
            <xsl:for-each select="/knjiznica/knjiga">
              <tr>
                <td>
                  <xsl:value-of select="naslov" /><xsl:if test="string(podnaslov)">:<br />
                    <xsl:value-of select="podnaslov" />
                  </xsl:if>
                </td>
                <td>
                  <xsl:value-of select="autor" />
                </td>
                <td class="center">
                  Izdavač: <xsl:value-of select="izdavac" /><br />
                  Datum izdanja:
                  <xsl:value-of select="datum_izdanja/dan" />.<xsl:value-of select="datum_izdanja/mjesec" />.<xsl:value-of select="datum_izdanja/godina" />.<br />
                  Jezik: <xsl:value-of select="@jezik" /><br />
                  Izdanje: <xsl:value-of select="@izdanje" /><br />
                </td>
                <td class="center">
                  Broj stranica: <xsl:value-of select="@broj_stranica" /><br />
                  Uvez: <xsl:value-of select="@uvez" /><br />
                  Kategorija: <xsl:value-of select="kategorija" /><br />
                  Cijena: <xsl:value-of select="cijena" />
                </td>
                <td>
                  <xsl:for-each select="recenzija">
                    <xsl:value-of select="sadrzaj" /><br />
                  </xsl:for-each>
                </td>
              </tr>
            </xsl:for-each>
          </table>
        </div>
        
        <div id="footer">
          © Nacionalna i sveučilišna knjižnica u Zagrebu 2005. Sva prava pridržana. | Ul. Hrvatske bratske zajednice 4 p.p. 550, 10000 Zagreb.HRVATSKA | Tel. ++ 385 1 616-4111 | webmaster: Viktor Fonić | Mob. ++ 385 98 181 24 33
        </div>
      </body>
    </html>
  </xsl:template>
</xsl:stylesheet>
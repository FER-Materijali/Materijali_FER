<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:output method="xml" indent="yes" doctype-system="http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd" doctype-public="-//W3C//DTD XHTML 1.0 Strict//EN"/>
    <xsl:template match="/">
        <html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="hr">
        <head>
            <meta charset="utf-8" />
		    <meta name="description" content="Laboratorijske vježbe iz OR"/>
		    <meta name="keywords" content="MotoGP,CSS Vježba,HTML vježba"/>
		    <meta name="author" content="Jure Knezović"/>
		    <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
		    <link rel="stylesheet" type="text/css" href="dizajn.css" />
		    <link rel="icon" type="image/png" href="images/web-logo.png"/>
		    <title>Utrke</title>
        </head>
          <body>
		    <div class="row">
			    <div class="col-12">
				    <header>
					    <h1>
						    <a href="index.html"><img  id="logo" src="images/logo.svg" alt="MotoGp"/></a>
						    MotoGP Prvenstvo
					    </h1>
				    </header>
			    </div>
		    </div>
		    <div class="row">
			    <div class="col-3">
				    <nav>
					    <a href="index.html">Početna</a>
                        <a href="podaci.xml" class="active">Utrke v1</a>
                        <a href="podaci1.xml">Utrke v2</a> 
					    <a href="obrazac.html">Pretraga v1</a>
                        <a href="obrazac1.html">Pretraga v2</a>
					    <a href="http://www.fer.unizg.hr/predmet/or" target="_top">Otvoreno računarstvo</a>
					    <a href="http://www.fer.unizg.hr/" target="_blank">FER</a>
					    <a href="mailto:jure.knezovic@fer.hr">Kontaktirajte autora</a>
				    </nav>
			    </div>
			    <div class="col-9">
                    <section>
                        <h2 class="naslov naslovObrazac"> Utrke svjetskog prvenstva 2015/16</h2>
                        <table id="podatak">
						    <thead>
							    <tr>
								    <th>Velika Nagrada</th>
								    <th>Staza</th>
								    <th>Grad</th>
                                    <th>Datum utrke</th>
                                    <th>Pobjednik</th>
                                    <th>Facebook</th>
							    </tr>
						    </thead>
						    <tbody>
                                <xsl:for-each select="prvenstvo/utrka">
                                    <tr>
                                        <td><xsl:value-of select="imeutrke"/></td>
                                        <td><xsl:value-of select="staza/imestaze"/></td>
                                        <td><xsl:value-of select="staza/grad"/>&#44;<xsl:value-of select="staza/drzava"/></td>
                                        <td><xsl:value-of select="datumutrke"/></td>
                                        <td><xsl:value-of select="detaljiutrke/pobjednik/imepobjednika"/>&#160;<xsl:value-of select="detaljiutrke/pobjednik/prezimepobjednika"/></td>
                                        <td><a>
                                                <xsl:attribute name="href">
                                                    http://www.facebook.com/<xsl:value-of select="facebookid"/>
                                                </xsl:attribute>
                                                <xsl:attribute name="target">
                                                    _top
                                                </xsl:attribute>
                                                <img id="fblogo" src="./images/fejsach.svg" alt="facebook"/>
                                            </a>
                                        </td>
                                    </tr>
                                </xsl:for-each>
                            </tbody>
                        </table>
                    </section>  
			    </div>
		    </div>
		    <div class="row">
			    <div class="col-12">
				    <footer>
					    <p>&#169;Jure Knezović - Otvoreno računarstvo 2015/16</p>
                    </footer>
                </div>
            </div>
          </body>
        </html>
    </xsl:template>
</xsl:stylesheet>
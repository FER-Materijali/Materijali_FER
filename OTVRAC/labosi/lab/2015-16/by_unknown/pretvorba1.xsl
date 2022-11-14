<?xml version="1.0" encoding="utf-8" ?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                xmlns:dns="http://www.w3schools.com">
    <xsl:output method="xml" indent="yes" doctype-system="http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd"
                doctype-public="-//W3C//DTD XHTML 1.0 Strict//EN"/>
    <xsl:template match="/">
        <html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="hr">
            <head>
                <meta charset="utf-8"/>
                <meta name="description" content="Laboratorijske vježbe iz OR"/>
                <meta name="keywords" content="MotoGP,CSS Vježba,HTML vježba"/>
                <meta name="author" content="Jure Knezović"/>
                <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
                <link rel="stylesheet" type="text/css" href="dizajn.css"/>
                <link rel="icon" type="image/png" href="images/web-logo.png"/>
                <title>Utrke</title>
            </head>
            <body>
                <div class="row">
                    <div class="col-12">
                        <header>
                            <h1>
                                <a href="index.html">
                                    <img id="logo" src="images/logo.svg" alt="MotoGp"/>
                                </a>
                                MotoGP Prvenstvo
                            </h1>
                        </header>
                    </div>
                </div>
                <div class="row">
                    <div class="col-3">
                        <nav>
                            <a href="index.html">Početna</a>
                            <a href="podaci.xml">Utrke v1</a>
                            <a href="podaci1.xml" class="active">Utrke v2</a>
                            <a href="obrazac.html">Pretraga v1</a>
                            <a href="obrazac1.html">Pretraga v2</a>
                            <a href="http://www.fer.unizg.hr/predmet/or" target="_top">Otvoreno računarstvo</a>
                            <a href="http://www.fer.unizg.hr/" target="_blank">FER</a>
                            <a href="mailto:jure.knezovic@fer.hr">Kontaktirajte autora</a>
                        </nav>
                    </div>
                    <div class="col-9">
                        <section>
                            <h2 class="naslov naslovObrazac">Utrke svjetskog prvenstva 2015/16</h2>
                            <table id="podatci">
                                <tbody>
                                    <xsl:for-each select="dns:prvenstvo/dns:utrka">
                                        <tr>
                                            <th colspan="3">
                                                <xsl:value-of select="dns:imeutrke"/> ,
                                                <xsl:value-of select="dns:staza/dns:imestaze"/>
                                            </th>
                                        </tr>
                                        <tr>
                                            <td class="podatcinaslov">
                                                Grad
                                            </td>
                                            <td class="podatcisredina">
                                                <xsl:value-of select="dns:staza/dns:grad"/>
                                            </td>
                                            <td class="pozadina">
                                                <xsl:choose>
                                                    <xsl:when test="dns:detaljiutrke">
                                                        <xsl:attribute name="rowspan">
                                                            <xsl:value-of
                                                                    select="8+count(dns:detaljiutrke/dns:vrijeme)"/>
                                                        </xsl:attribute>
                                                    </xsl:when>
                                                    <xsl:otherwise>
                                                        <xsl:attribute name="rowspan">
                                                            <xsl:value-of select="5"/>
                                                        </xsl:attribute>
                                                    </xsl:otherwise>
                                                </xsl:choose>
                                                <a>
                                                    <xsl:attribute name="href">
                                                        http://www.facebook.com/<xsl:value-of select="dns:facebookid"/>
                                                    </xsl:attribute>
                                                    <xsl:attribute name="target">
                                                        _top
                                                    </xsl:attribute>
                                                    <img class="slika">
                                                        <xsl:attribute name="src">
                                                            <xsl:value-of select="dns:staza/dns:slikastaze"/>
                                                        </xsl:attribute>
                                                    </img>
                                                </a>
                                            </td>

                                        </tr>
                                        <tr>
                                            <td class="podatcinaslov">
                                                Država
                                            </td>
                                            <td class="podatcisredina">
                                                <xsl:value-of select="dns:staza/dns:drzava"/>
                                            </td>
                                        </tr>
                                        <tr>
                                            <td class="podatcinaslov">
                                                Dužina kruga
                                            </td>
                                            <td class="podatcisredina">
                                                <xsl:value-of select="dns:staza/dns:detaljistaze/dns:duzinakruga"/> m
                                            </td>
                                        </tr>
                                        <tr>
                                            <td class="podatcinaslov">
                                                Broj zavoja
                                            </td>
                                            <td class="podatcisredina">
                                                <xsl:value-of select="dns:staza/dns:detaljistaze/@brojzavoja"/>
                                            </td>
                                        </tr>
                                        <tr>
                                            <td class="podatcinaslov">
                                                Datum utrke
                                            </td>
                                            <td class="podatcisredina">
                                                <xsl:value-of select="dns:datumutrke"/>
                                            </td>
                                        </tr>
                                        <xsl:if test="dns:detaljiutrke">
                                            <tr>
                                                <td class="podatcinaslov">
                                                    Pobjednik
                                                </td>
                                                <td class="podatcisredina">
                                                    <xsl:value-of
                                                            select="dns:detaljiutrke/dns:pobjednik/dns:imepobjednika"/>&#160;<xsl:value-of
                                                        select="dns:detaljiutrke/dns:pobjednik/dns:prezimepobjednika"/>
                                                </td>
                                            </tr>
                                            <tr>
                                                <td class="podatcinaslov">
                                                    Motor pobjednika
                                                </td>
                                                <td class="podatcisredina">
                                                    <xsl:value-of select="dns:detaljiutrke/dns:pobjednik/@motorpobjednika"/>
                                                </td>
                                            </tr>
                                            <tr>
                                                <td class="podatcinaslov">
                                                    Utrku završilo
                                                </td>
                                                <td class="podatcisredina">
                                                    <xsl:value-of select="21-count(dns:detaljiutrke/dns:odustajanje)"/>&#160;vozača
                                                </td>
                                            </tr>
                                            <xsl:for-each select="dns:detaljiutrke/dns:vrijeme">
                                                <tr>
                                                    <xsl:if test="position()=1">
                                                        <td class="podatcinaslov">
                                                            <xsl:attribute name="rowspan">
                                                                <xsl:value-of select="count(../dns:vrijeme)"/>
                                                            </xsl:attribute>
                                                            Vrijeme
                                                        </td>
                                                    </xsl:if>
                                                    <td class="podatcisredina">
                                                        <xsl:value-of select="dns:temperatura"/>&#176;&#160;<xsl:value-of
                                                            select="dns:naoblaka"/>
                                                    </td>
                                                </tr>
                                            </xsl:for-each>
                                        </xsl:if>
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
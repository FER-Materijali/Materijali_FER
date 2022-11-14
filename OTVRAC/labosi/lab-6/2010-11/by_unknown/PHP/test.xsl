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
          $("a").tooltip();
        });
        </script>
        
      </head>
      <body>
        
        <a href="http://jquery.com" title="Write less, do more">jQuery.com</a>
        <br />
        <a href="http://learningjquery.com" title="Learn more, write less">learningjQuery.com</a>
      </body>
    </html>
  </xsl:template>
</xsl:stylesheet>
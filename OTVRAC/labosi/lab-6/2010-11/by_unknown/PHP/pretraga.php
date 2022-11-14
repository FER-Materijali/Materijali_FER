<?php

  date_default_timezone_set("America/Los_Angeles");
  include ('funkcije.php');
  
  error_reporting (E_ALL);

  $a = file_get_contents("http://localhost:8080/OR5.lab/servlet");
  $dom = new DOMDocument();
  $dom->loadXML($a);

  $xp = new DOMXPath($dom);

  $query = generateQuery();
  $rezultat = $xp->query($query);
  
  function ispisiOstalo($element)
  {
    ?>
    Broj stranica:
    <?php
      echo $element->getAttribute('broj_stranica');
    ?>
    <br />
    Uvez:
    <?php
      echo $element->getAttribute('uvez');
    ?>
    <br />
    <?php
      echo getElementValue($element,'kategorija')->nodeValue;
    ?>
    <br />
    Cijena:
    <?php
      echo getElementValue($element,'cijena')->nodeValue;
  }
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html>
  <head>
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8" />
    <script src="js/jquery.min.js"></script>
    <link rel="stylesheet" type="text/css" href="dizajn.css" />
    <!--
    <script type="text/javascript" src="js/jquery.dimensions.min.js"></script>
    <script type="text/javascript" src="js/jquery.tooltip.min.js"></script>
    -->
    <script type="text/javascript" src="js/jquery.tools.min.js"></script>
    <script>
    $(document).ready(function(){
      $("tr[title]").tooltip();
    });
    
    function loadDetails($id)
    {
      var xhr;
      if (window.XMLHttpRequest)     // Standard object
      {
        xhr = new XMLHttpRequest();     // Firefox, Safari, ...
      }
      else if (window.ActiveXObject)   // Internet Explorer 
      {
        xhr = new ActiveXObject("Microsoft.XMLHTTP");
      }
      
      
      var url = "http://localhost/OR/6.%20labos/detalji.php?id=" + $id;
      xhr.open("GET", url, true);
      xhr.send(null);
      document.getElementById("more").innerHTML = '<img src="spinner.gif" alt="Pričekajte..." />';
      
      xhr.onreadystatechange = function()
      {
        if (xhr.readyState == 4)
        {
          if (xhr.status == 200)
          {
            document.getElementById("more").innerHTML = xhr.responseText;
          }
        }
      };
    }
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
        <li><a href="index.html">Početna stranica</a></li>
        <li><a href="podaci.xml">Katalog knjiga</a></li>
        <li><a href="obrazac.html">Pretraga</a></li>
        <li><a href="http://www.rasip.fer.hr/">RASIP</a></li>
        <li><a href="http://www.fer.hr/" target="_blank">FER</a></li>
        <li><a href="mailto:Viktor.Fonic@FER.hr">Kontakt (e-mail)</a></li>
      </ul>
    </div>
    
    <div id="more">
    </div>

    <div id="content">
      <h1>Rezultati pretrage</h1>
      <table class="table_stripes" width="1000px">
        <tr>
          <th>Naslov</th>
          <th>Autor</th>
          <th class="center">Izdanje</th>
          <th class="center">Akcija</th>
        </tr>
        <?php
          foreach ($rezultat as $element)
          {
        ?>
        <tr title="<?php echo ispisiOstalo($element); ?>">
          <td>
            <?php
              echo getElementValue($element, 'naslov')->nodeValue;
              $podnaslov = getElementValue($element, 'podnaslov');
              if (!empty($podnaslov))
              {
                echo ":<br />";
                echo getElementValue($element, 'podnaslov')->nodeValue;
              }
            ?>
          </td>
          <td>
            <?php
              foreach($element->getElementsByTagName('autor') as $autor)
              {
                echo getElementValue($autor, 'ime')->nodeValue;
                echo " ";
                echo getElementValue($autor, 'prezime')->nodeValue;
                echo "<br />";
              }
            ?>
          </td>
          <td class="center">
            Izdavač:
            <?php
              echo getElementValue($element, 'izdavac')->nodeValue;
            ?>
            <br />
            Datum izdanja:
            <?php
              echo getElementValue($element, 'datum_izdanja')->nodeValue;
            ?>
            <br />
            Jezik:
            <?php
              echo $element->getAttribute('jezik');
            ?>
            <br />
            Izdanje:
            <?php
              echo $element->getAttribute('izdanje');
            ?>
          </td>
          <td>
            <a href="#" onclick="loadDetails('<?php echo $element->getAttribute('id'); ?>'); return false">Više...</a>
          </td>
        </tr>
        <?php
          }
        ?>
      </table>
    </div>

    <div id="footer">
      © Nacionalna i sveučilišna knjižnica u Zagrebu 2005. Sva prava pridržana. | Ul. Hrvatske bratske zajednice 4 p.p. 550, 10000 Zagreb.HRVATSKA | Tel. ++ 385 1 616-4111 | webmaster: Viktor Fonić | Mob. ++ 385 98 181 24 33
    </div>
  </body>
</html>

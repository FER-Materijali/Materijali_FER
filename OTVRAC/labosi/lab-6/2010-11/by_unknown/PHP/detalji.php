<?php
 date_default_timezone_set("America/Los_Angeles");
  include ('funkcije.php');
  
  error_reporting (E_ALL);

  $a = file_get_contents("http://localhost:8080/OR5.lab/servlet");
  $dom = new DOMDocument();
  $dom->loadXML($a);

  $xp = new DOMXPath($dom);

  $query = generateEasyQuery();
  $rezultat = $xp->query($query);
  
  foreach ($rezultat as $element)
  {
    echo '<b>' . getElementValue($element, 'naslov')->nodeValue . '</b>';
    echo '<br />';
    echo getElementValue($element, 'izdavac')->nodeValue . '<br />';
    echo 'Jezik: ' . $element->getAttribute('jezik') . '<br />';
    echo $element->getAttribute('broj_stranica') . 'str.<br />';
    echo $element->getAttribute('uvez') . ' uvez<br />';
    echo getElementValue($element,'kategorija')->nodeValue . '<br />';
    echo getElementValue($element,'cijena')->nodeValue . '<br />';
  }
?>

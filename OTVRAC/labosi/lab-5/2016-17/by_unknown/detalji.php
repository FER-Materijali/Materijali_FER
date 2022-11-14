<?php
header('Access-Control-Allow-Origin: *');
include ("funkcije.php");

$kod = $_GET["id"];



$dom = new DOMDocument();
  
$dom->load('podaci.xml'); 

$xp = new DOMXPath($dom); 

$putanja = '/klubovi/klub[contains(@id, "'. $kod . '")]';


$rez = $xp->query($putanja);



foreach($rez as $elem){

	if(($kod) == ($elem->getAttribute('id'))) {
		
			echo "<b>Dodatni detalji:</b><br/>";
			echo "Ikad osvojio titulu: ";
			echo $elem->getAttribute('osvajac'); 
			echo "<br/>Broj osvojenih trofeja: ";
			echo $elem->getElementsByTagName('trofeji')->item(0)->nodeValue;
			echo "<br/>Navijači: ";
			echo $elem->getElementsByTagName('navijaci')->item(0)->nodeValue;
			echo "<br/>Kapacitet dvorane: ";
			echo $elem->getElementsByTagName('kapacitet')->item(0)->nodeValue;
			echo "<br/>";
		
	}
}
sleep(1);


?>
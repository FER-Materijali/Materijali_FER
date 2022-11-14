<?php

include ("funkcije.php");

$kod = $_GET["kod"];



$dom = new DOMDocument();
  
$dom->load('podaci.xml'); 

$xp = new DOMXPath($dom); 

$putanja = '/poslovnice/poslovnica[contains(@kod, "'. $kod . '")]';
echo $putanja;

$rez = $xp->query($putanja);



foreach($rez as $akcija){
	#echo $kod;
	#echo $akcija->getAttribute('kod');
	if(($kod) == ($akcija->getAttribute('kod'))) {
		
		echo 'Naručivanje e-mailom ' . getElementValue($akcija, 'email')->nodeValue . "<br/>"; 
		echo 'Probna vožnja ' . getElementValue($akcija, 'probna')->nodeValue . "<br />";
	
		
		
	}
}
sleep(1);
?>
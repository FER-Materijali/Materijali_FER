<?php

	include ('funkcije.php');

	error_reporting (E_ALL);

	$dom = new DOMDocument();
	
	# 6. lab
	#$a = file_get_contents("http://localhost:8081/Servlet/servlet");
	#$dom->loadXML($a);
	$dom->load('podaci.xml');

	$xp = new DOMXPath($dom);

	$upit = generirajUpit();
	$rezultat = $xp->query($upit);

	foreach ($rezultat as $osoba)
	{
		echo '<b><span style="color:#fece2f;">' . getFirstElementByTagName($osoba, 'ime')->nodeValue . " " . getFirstElementByTagName($osoba, 'prezime')->nodeValue . '</span></b>';
		echo '<br />';
		echo '<b>OIB: </b>' . $osoba->getAttribute('oib') . '<br />';
		echo '<b>Kategorija: </b>' . $osoba->getAttribute('kategorija') . '<br />';
		echo '<b>Datum ro&#x0111;enja: </b>' . getFirstElementByTagName($osoba, 'datum_rodjenja')->nodeValue . '<br />';
		
		$adresa = getFirstElementByTagName($osoba, 'adresa');
		if (!empty($adresa))
		{
			echo '<b>Adresa: </b>';
			echo getFirstElementByTagName($adresa, 'ulica')->nodeValue . ' ';
			echo getFirstElementByTagName($adresa, 'kucni_broj')->nodeValue . ',<br/>&nbsp;&nbsp;&nbsp;';
			echo getFirstElementByTagName($adresa, 'mjesto')->getAttribute('postanski_broj') . ' ';
			echo getFirstElementByTagName($adresa, 'mjesto')->nodeValue;
			echo '<br />';
		}
		
		echo '<b>Telefon: </b><br/>';
		foreach ($osoba->getElementsByTagName('telefon') as $telefon)
		{
			echo '&nbsp;&nbsp;&nbsp;(' . getFirstElementByTagName($telefon, 'broj')->getAttribute('pozivni_broj') . ') ';
			echo getFirstElementByTagName($telefon, 'broj')->nodeValue;
			echo '<br>';
		}
		
		echo '<b>Email: </b><br/>';
		foreach ($osoba->getElementsByTagName('mail_adresa') as $email)
		{
			echo '&nbsp;&nbsp;&nbsp;' . $email->nodeValue . '<br />';
		}
	}
	
	sleep(1);
?>

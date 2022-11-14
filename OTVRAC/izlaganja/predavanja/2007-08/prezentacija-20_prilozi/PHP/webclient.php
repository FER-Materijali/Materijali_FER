<?php

	//provjera broja argumenata skripte
	if( $argc != 4 ) {
		echo "usage: php webclient.php <server> <port> <page>\n";
		exit(1);
	}
	
	//stvaranje veze s posluziteljem, spojna veza, cekanje na vezu do 5 s.
	$conn = @stream_socket_client("tcp://$argv[1]:$argv[2]", $errno, $errstr, 5);
	
	//ispitivanje da li je veza uspjesno stvorena
	if(! $conn ) {
		echo "($errno) $errstr\n";
		exit(1);
	}
	
	//zahtjev za dokumentom (vrlo pojednostavljeno)
	fwrite($conn, "GET /$argv[3] HTTP/1.0\r\n");
	
	//zavrsetak zaglavlja (prazan redak)
	fwrite($conn, "\r\n");
	
	//dva retka razmaka prije ispisivanja odgovora posluzitelja
	//radi citljivosti (nema utjecaj na fukcionalnost)
	echo "\n\n";
	
	//citanje odgovora posluzitelja redak po redak
	//do kraja (isto kao i kod citana tekst datoteke)
	while(! feof($conn) )
		echo fgets($conn);
		
	//zatvaranje veze s posluziteljem
	fclose($conn);
?>
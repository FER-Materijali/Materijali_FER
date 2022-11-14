<?php

	//provjera broja argumenata skripte
	if( $argc != 2 ) {
		echo "usage: php webserver.php <port>\n";
		echo "port broj izmedju 1024 i 65535\n";
		exit(1);
	}
	
	//otvaranje uticnice na vratima $argv[1]
	$socket = @stream_socket_server("tcp://0.0.0.0:$argv[1]", $errno, $errstr);
	
	//ispitivanje da li je uticnica uspjesno stvorena
	if(! $socket ) {
		echo "($errno) $errstr\n";
		exit(1);
	}

	echo "Posluzitelj spreman za rad, uticnica $argv[1]\n";

	//glavna petlja prihvacanja zahtjeva klijenata
	while($conn = stream_socket_accept($socket)) {
		
		//prvi redak zaglavlja sadrzi URL dohvacanog dokumenta
		$cmd = fgets($conn);
		echo "\n-----------------------------------------\n$cmd";
		
		//citanje ostatka zaglavlja poslanog od web preglednika
		//vise redaka podataka, zavrsava s praznim retkom (uokvirenje!)
		do {
			echo ($line = fgets($conn));
		} while ( strcmp($line, "\r\n") );
		
		//drugo polje unutar retka naredbe je lokalni put do dokumenta (GET path HTTP/1.x)
		//put mora biti dekodiran (dekodiranje %20 i ostalih %-kodiranih znakova ...)
		$path = strtok($cmd, " ");
		$path = urldecode(strtok(" "));
		
		//mice se pocetni / znak iz puta, put relativan na 
		//direktorij u kojem je posluzitelj pokrenut!
		$path = substr($path, 1, strlen($path)-1);
		
		//dohvacanje citavog sadrzaja datoteke
		$content = file_get_contents($path);
		
		//ako datoteka ne postoji, vrati gresku
		if( !$content ) {
			$errPage = "<html><head><title>Error</title></head><body>The requested page" .
			 " does not exist.</body></html>";
			@fwrite($conn, "HTTP/1.0 404 File not found\n");
			@fwrite($conn, "Content-Type: text/html\n");
			@fwrite($conn, "Content-Length:" . strlen($errPage) . "\n\n");	//brojanje okteta!
			@fwrite($conn, $errPage . "\n\n");
		}
		
		//datoteka postoji, proslijedi sadrzaj klijentu
		else {
		
			@fwrite($conn, "HTTP/1.0 200 OK\n");	
			@fwrite($conn, "Content-Length:" . strlen($content) . "\n\n");	//brojanje okteta!
			@fwrite($conn, $content);
		}
		
		//zatvaranje veze
		fclose($conn);
	}
	
	//zatvaramo uticnicu
	fclose($socket);
?>
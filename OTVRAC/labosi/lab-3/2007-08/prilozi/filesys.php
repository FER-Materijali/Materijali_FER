<?php


	//primjer ulazne datoteke: events.txt
	
	//moraju biti zadana dva parametra
	if( $argc != 3 ) {
		echo "usage: php filesys.php input-file output-file\n";
		exit(1);
	}

	//strukture podataka
	$log = array('Log summary' => $argv[1]);
	$log['INFO'] = $log['WARNING'] = $log['ERROR'] = 0;
	
	//otvaranje ulazne datoteke u nacinu citanja
	$inFile = @fopen($argv[1], 'r');
	if(! $inFile ) {
		echo "input file '$argv[1]' does not exist\n";
		exit(1);
	}
	
	//za svaki redak
	while(! feof($inFile) ) {
	
		//procitaj redak iz datoteke
		$inLine = fgets($inFile);
		
		//makni prazne znakove ispred i iza teksta
		$inLine = trim($inLine);
		
		//izdvoji tip dogadjaja
		$evt_type = substr($inLine, 0, strpos($inLine, ':'));
		
		//povecaj brojac tipa dogadjaja
		$log[$evt_type]++;
	}
	
	//otvaranje izlazne datoteke
	$outFile = @fopen($argv[2], 'w');
	if(! $outFile ) {
		echo "could not open file '$argv[2]' for writing\n";
		exit(1);
	}
	
	//pisanje sumarnog izvjesca u izlaznu datoteku
	foreach($log as $key => $val)
		fwrite($outFile, $key . ": " . $val . "\n");
	
	//zatvaranje datoteka
	fclose($inFile);
	fclose($outFile);
?>
<?php

	if( $argc != 2 ) {
		echo "usage: php stream_client.php <URL>\n";
		exit(1);
	}
	
	$stream = fopen($argv[1], 'r');
	
	if(! $stream ) {
		echo "Error accessing $argv[1]\n";
		exit(1);
	}

	$content = stream_get_contents($stream);
	echo "\n$content\n";
?>
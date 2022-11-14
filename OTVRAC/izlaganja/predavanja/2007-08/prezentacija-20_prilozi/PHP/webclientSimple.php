<?php

	if( $argc != 4 ) {
		echo "usage: php webclient.php <server> <port> <path>\n";
		exit(1);
	}
	
	$socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
	
	socket_connect($socket, $argv[1], $argv[2]);
	
	socket_write($socket, "GET /$argv[3] HTTP/1.0\r\n\r\n");
	
	$data = socket_read($socket, 100000);
	
	socket_close($socket);

	echo "len = " . strlen($data);
	echo "\n----------------------------------\n";
	echo $data . "\n";
?>
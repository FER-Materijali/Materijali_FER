<?php

	if( $argc != 2 ) {
		echo "usage: php tserver.php <port>\n";
		echo "port between 1024 and 65535\n";
		exit(1);
	}
	
	$socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
	
	socket_bind($socket, '127.0.0.1', $argv[1]);
	
	socket_listen($socket, 2);
	
	echo "Ready to accept connections at port $argv[1]\n";
	
	//main loop
	while(TRUE) {
	
		$cSocket = socket_accept($socket);
		
		$peerName = "";
		socket_getpeername($cSocket, $peerName);
		echo "Accepted connection from $peerName... ";
		sleep(2);	//"processing delay" :)
		
		socket_write($cSocket, date('n/j/Y g:i a') . "\n");
		
		socket_close($cSocket);
		
		echo "done\n";
	}
	
	socket_close($socket);
?>
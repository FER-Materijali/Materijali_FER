<?php

	if( $argc != 4 ) {
		echo "usage: php tclient.php <server> <port>  block     or\n";
		echo "usage: php tclient.php <server> <port>  nonblock\n";
		exit(1);
	}
	
	$socket = @socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
	if( $socket == FALSE ) reportError();
	
	$status = @socket_connect($socket, $argv[1], $argv[2]);
	if( $status == FALSE ) reportError();
	
	if( strcasecmp($argv[3], "nonblock") == 0 )
		socket_set_nonblock($socket);
	elseif(  strcasecmp($argv[3], "block") == 0 )
		socket_set_block($socket);
	else {
		echo "communication mode not recognized (block or nonblock valid): $argv[3]\n";
		exit(1);
	}
	
	socket_write($socket, "TIME\n");
	$timeout = 10;
	
	do {
		usleep(500000);		// 0.5 second sleep
	 	$data = socket_read($socket, 1500);
		echo "-";
		if( --$timeout == 0 ) {
			echo "response timeout!\n";
			reportError();
		}
	} while( $data == FALSE );
	echo "\n" . $data . "\n";
		
	socket_close($socket);
	
	function reportError() {
	
		echo "(" . socket_last_error() . ") " . socket_strerror(socket_last_error()). "\n";
		exit(1);
	}
?>
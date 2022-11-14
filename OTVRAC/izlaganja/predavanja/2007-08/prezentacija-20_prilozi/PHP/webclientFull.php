<?php

	if( $argc != 4 ) {
		echo "usage: php webclient.php <server> <port> <path>\n";
		exit(1);
	}
	
	$socket = @socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
	if( $socket == FALSE ) reportError();
	
	$status = socket_connect($socket, $argv[1], $argv[2]);
	if( $status == FALSE ) reportError();
	
	$req = "GET /$argv[3] HTTP/1.0\r\n\r\n";
	$req_sent = 0;
	do {
		$status = socket_write($socket, substr($req, $req_sent));
		if( $status == FALSE ) reportError();
		$req_sent += $status;
	} while ($req_sent != strlen($req));
	
	$data = "";
	while( ($rbuff = socket_read($socket, 1500)) != FALSE )
		$data .= $rbuff;

	socket_close($socket);
	
	echo "len = " . strlen($data) . "\n";
	echo $data . "\n";
	
	function reportError() {
	
		echo "(" . socket_last_error() . ") " . socket_strerror(socket_last_error()). "\n";
		exit(1);
	}
?>
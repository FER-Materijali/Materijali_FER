<?php

	//provjera broja argumenata skripte
	if( $argc != 2 ) {
		echo "usage: php udp_server.php <port>\n";
		echo "port between 1024 and 65535\n";
		exit(1);
	}

	$socket = @socket_create(AF_INET, SOCK_DGRAM, SOL_UDP);
	if( $socket == FALSE ) reportError();
	if( socket_bind($socket, '127.0.0.1', $argv[1]) == FALSE ) reportError();
	echo "Ready to accept connections at port $argv[1]\n";

	do {
		$c_addr = "";
		$c_port = 0;
		
		$len = @socket_recvfrom($socket, $msg, 1500, 0, $c_addr, $c_port);
		if($len == -1) reportError();
		else if($len == 0) continue;
		
		echo "Query received from " . $c_addr . " at port " . $c_port . ": $msg\n";
		
		if( strcasecmp($msg, "time") == 0 ) $rsp = date("D M j H:i:s Y\r\n");
		else $rsp = date("not understood");
			
		if( socket_sendto($socket, $rsp, strlen($rsp), 0, $c_addr, $c_port ) == -1 )
			reportError();
		
	} while( TRUE );

	socket_close($socket);

	function reportError() {
	
		echo "(" . socket_last_error() . ") " . socket_strerror(socket_last_error()). "\n";
		exit(1);
	}
?>
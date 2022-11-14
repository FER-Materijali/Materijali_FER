<?php

	if( $argc != 3 ) {
		echo "usage: php udp_client.php <host> <port>\n";
		exit(1);
	}
	
	$socket = @socket_create(AF_INET, SOCK_DGRAM, SOL_UDP);
	if( $socket == FALSE ) reportError();
	
	$req = "time";
	if( socket_sendto($socket, $req, strlen($req), 0, $argv[1], $argv[2]) == -1 )
		reportError();
	
	$s_addr = "";
	$s_port = 0;

	$len = @socket_recvfrom($socket, $message, 1500, 0, $s_addr, $s_port);
	if($len > 1)
		echo "($s_addr, $s_port): $message\n";
	else 
		reportError();
	
	socket_close($socket);
	
	function reportError() {
	
		echo "(" . socket_last_error() . ") " . socket_strerror(socket_last_error()). "\n";
		exit(1);
	}
?>
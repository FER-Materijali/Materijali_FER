<?php

	if( $argc != 2 ) {
		echo "usage: php tnserver.php <port>\n";
		echo "port between 1024 and 65535\n";
		exit(1);
	}
	
	$socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
	if( $socket == FALSE ) reportError();
	if( socket_bind($socket, '127.0.0.1', $argv[1]) == FALSE ) reportError();
	if( socket_listen($socket, 2) == FALSE )  reportError();
	
	echo "Ready to accept connections at port $argv[1]\n";
	
	//main client loop
	while($cSocket = socket_accept($socket)) {
	
		$peerName = "";
		socket_getpeername($cSocket, $peerName);
		echo "Accepted connection from $peerName.\n";
		
		
		//client conversation loop
		while(TRUE) {
		
			$cmd = "";
			do {
				$cmf = @socket_read($cSocket, 1500);
				if($cmf == FALSE) break;
				$cmd .= $cmf;
			} while( $cmf[strlen($cmf)-1] != "\n");
	
			$cmd = stripCtrl($cmd);
			
			if( strcasecmp($cmd, 'TIME') == 0 ) {
				$status = socket_write($cSocket, date('n/j/Y g:i a') . "\n");
				if($status == FALSE) {
					socket_close($cSocket);
					echo "Connection with $peerName has been lost.\n";
					break;
				}
			}
			elseif( strcasecmp($cmd, 'CLOSE') == 0 ) {
			
				socket_write($cSocket, "server: closing connection\n");
				socket_close($cSocket);
				echo "Connection with $peerName closed.\n";
				break;
			}
			else {
				$status = @socket_write($cSocket, "not understood: $cmd\n");
				if($status == FALSE) {
					@socket_close($cSocket);
					echo "Connection with $peerName has been lost.\n";
					break;
				}
			}
		}
	}

	socket_close($socket);


	function stripCtrl($string) {
	
		$chars = str_split($string);
		$end = 0;
		while( ($end < strlen($string)) && (ord($chars[$end]) >= 0x30) ) $end++;
		
		return substr($string, 0, $end);
	}
	
	function reportError() {
	
		echo "(" . socket_last_error() . ") " . socket_strerror(socket_last_error()). "\n";
		exit(1);
	}
?>
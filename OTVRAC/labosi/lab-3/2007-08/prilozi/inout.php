<?php

$line = fgets(STDIN);	// citanje sa stdin

$out =  $line . "\n";

fwrite(STDOUT, "stdout: " . $out);	// isto kao i echo ...

fwrite(STDERR, "stderr: " . $out);	// stderr

?>

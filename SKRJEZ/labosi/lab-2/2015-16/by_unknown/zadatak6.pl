while(defined($line = <>)) {
	$line =~ tr/a-zA-Z/e-za-dE-ZA-D/;
	print uc $line;
}

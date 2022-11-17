#!/usr/bin/perl -w

foreach $file (@ARGV) {
	open RLOG, "<", "$file";

	
	while (defined ($redak = <RLOG>)) {
		@redak = split / /, "$redak";
		@vrijeme = split /:/, "$redak[3]";
		$sat = $vrijeme[1];
		$brPrist[$sat] += 1;
	}
	
	$date = $redak[3];
	$date =~ s|^.*\[(.{2}/.{3}/.{4}).*$|$1|;
	printf ("\n Date: %s\n sat : broj pristupa\n-------------------------------\n", $date);

	
	$index = 0;
	foreach (@brPrist) {
		printf ("  %02d : %s", $index++ , $_ . "\n");
	}
}
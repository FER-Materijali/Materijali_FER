@hour_table = (0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,);    	

while (defined($line = <>)) {
	if( defined $filename && $filename ne $ARGV) {
		&print_log;
	}
	if ( ! defined $filename || $filename ne $ARGV && $ARGV ne "-") {
		$filename = $ARGV;
		@parts = split(/\./, $filename);
		($day, $month, $year) = split(/-/, $parts[1]);
		print "\n Datum: $year-$month-$day\n";
	}
	if ( $filename eq $ARGV || $ARGV eq "-") {
		@parts = split(/:/, $line);
		$hour = $parts[1];
		++$hour_table[$hour];
	}
}
&print_log;

sub print_log {
	print " sat : broj pristupa\n";
	print "------------------------\n";
	for ( (0..23) ) {
		printf "  %02d : %d\n", $_, $hour_table[$_];
		$hour_table[$_] = 0;
	}
}

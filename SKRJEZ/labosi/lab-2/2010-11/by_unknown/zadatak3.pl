#!/usr/bin/perl

$currDate = 'none';
$currHour = 'none';

while(defined($line = <>)) {
	
	chomp($line);
	
	if($line =~ /\[([0-9]{2}\/[A-Za-z]{3}\/[0-9]{4}):([0-9]{2})/) {
	
		if($1 ne $currDate) {
			
			print "$currHour : $counter\n\n";
			
			$currDate = $1;
			$currHour = $2;
			$counter = 1;
			
			print "Date: $1\n";
			print "Sat: broj pristupa\n";
			print "------------------\n";
			
		}
		
		elsif($2 ne $currHour) {
			
			print "$currHour : $counter\n";
			
			$currHour = $2;
			$counter = 1;
		}
		else {
			
			$counter += 1;
		}
			
	}
}

print "$currHour : $counter\n";
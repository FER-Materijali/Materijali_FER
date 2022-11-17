#!/usr/bin/perl

while (defined ( $line = <> )) {
	
	chomp($line);
	
	#if($line =~ /([0-9]+);([A-Za-z]+);([A-Za-z]+);
	
	@data = split /;/,$line;
	
	$data[3] =~ /([0-9]{4}-[0-9]{2}-[0-9]{2}) ([0-9]{2}):/;
	$startDate = $1;
	$start = $2;
	
	$data[4] =~ /([0-9]{4}-[0-9]{2}-[0-9]{2}) ([0-9]{2}):/;
	$endDate = $1;
	$end = $2;
	
	#print "$startDate $endDate \n";
	
	if($startDate ne $endDate or $end > $start) {
		
		$data[3] =~ s/\ .+$//;
		print "$data[0]; $data[1] $data[2] - PROBLEM: $data[3] --> $data[4]\n";
		
	}
	
}
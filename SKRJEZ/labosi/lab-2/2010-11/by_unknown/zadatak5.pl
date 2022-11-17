#!/usr/bin/perl

if(@ARGV != 1) {
	
	print "Morate predati ime datoteke";
	die;
}


my $fopen = open STUDENTI, "<", $ARGV[0];

if(!$fopen) {
	
	print "Datoteka ne postoji!";
	die;
}
$first = 0;
%studRang;
%studInfo;

while( defined ($line = <STUDENTI>)) {
	
	chomp($line);
	
	if(!$first) {
		
		@udjeli = split /;/,$line;
		$first = 1;
	}
	
	else {
	
		@studData = split /;/,$line;
		$bodovi = 0;
		
		for($i=0;$i<@udjeli;$i++) {
			
			if($studData[$i+3] ne '-') {
				
				$bodovi += $studData[$i+3] * $udjeli[$i];
			
			}
			
		}
		
		$studRang{$studData[0]} = $bodovi;
		$studInfo{$studData[0]} = $studData[1].", ".$studData[2];
		
	#end else	
	}
	
}
print "Lista po rangu:\n--------------------- \n";
$i = 0;
foreach $key (sort { $studRang{$b} <=> $studRang{$a} } keys %studRang) {
    $i+=1;
	printf "%d. %-32s (%s) : %.2f \n",$i,$studInfo{$key},$key,$studRang{$key};
}


#!/usr/bin/perl -w

while (defined ($redak = <>)) {
	chomp ($redak);
	@redak = split /;/, $redak;
	@timestampPoc = split / /, $redak[3];
	@timestampPred = split / /, $redak[4];
	$timestampPoc = $redak[3];
	$timestampPoc =~ s/([0-9]{4})-([0-9]{2})-([0-9]{2}) ([0-9]{2}):([0-9]{2}).*$/$1$2$3$4$5/;
	$timestampPred = $redak[4];
	$timestampPred =~ s/([0-9]{4})-([0-9]{2})-([0-9]{2}) ([0-9]{2}):([0-9]{2}).*$/$1$2$3$4$5/;
	
	#print "$timestampPoc; $timestampPred\n";
	
	if ($timestampPred > $timestampPoc + 100) {
		print "$redak[0] $redak[1] $redak[2] - PROBLEM: $timestampPoc[0] $timestampPoc[1] --> $timestampPred[0] $timestampPred[1]\n";
	}
}
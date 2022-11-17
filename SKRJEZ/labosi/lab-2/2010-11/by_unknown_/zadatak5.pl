#!/usr/bin/perl -w

chomp ($udjeli = <>);
@udjeli = split /;/, $udjeli;

$index = 0;
while (defined ($redak = <>)) {
	@redak = split /;/, $redak;
	$jmbag = shift @redak;
	$prez = shift @redak;
	$ime = shift @redak;
	
	$sumRedak = 0;
	$indexInt = 0;
	foreach (@redak) {
		if ($_ eq '-') {
			$_ = 0;
		}
		$sumRedak += $udjeli[$indexInt] * $_;
		$indexInt++;
	}
	
	$rangLista[$index] = sprintf("%06.2f;%s;%s;%s", $sumRedak, $jmbag, $prez, $ime);
	$index++;
}

@rlSorted = reverse sort (@rangLista);
#@rlSorted = reverse @rlSorted;

$index = 1;
foreach (@rlSorted) {
	@redak = split /;/, $_;
	
	printf ("%3d. %-35s:% 6.2f\n", $index, "$redak[2], $redak[3] ($redak[1])", $redak[0]);
	$index++;
}
	

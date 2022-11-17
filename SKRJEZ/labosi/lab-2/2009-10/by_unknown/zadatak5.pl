if(@ARGV != 1){	
	die "Ocekivan je jedan parametar - ulazna datoteka.";
}
if( ! open STUD, $ARGV[0] ){
	die "Datoteka ".$ARGV[0]." nije pronadjena.";
}

chomp($_ = <STUD>);
@koef = split;

while(<STUD>){
	chomp($_);
	@redak = split;
	if( @redak != 3+@koef){
		die "Retci sa koeficijentima i studentima nisu odgovarajucih duljina!\nRedak: @redak\nKoeficijenti: @koef\n";
	}	
	$imePrezime = $redak[1]." ".$redak[2];	
	$indeks = @koef;
	while( $indeks > 0 ){
		$indeks -= 1;
		$studenti{$imePrezime} += $koef[$indeks]*$redak[3+$indeks];
	}	
}
while( ($kljuc, $vrijednost) = each %studenti ){
	push @konacno, "$vrijednost\t$kljuc";
}
foreach $red ( reverse sort @konacno ){
	$i+=1;
	printf "%4d. | %s\n", $i, $red;
}

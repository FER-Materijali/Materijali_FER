while(defined($line = <>)) {
	($jmbag, $prezime, $ime, $termin, $zakljucano) = split(/;/, $line);
	@termin_parts = split(/ /, $termin);
	@zakljucano_parts = split(/ /, $zakljucano);
	if(! &provjeri_interval($termin_parts[0], $termin_parts[1], $zakljucano_parts[0], $zakljucano_parts[1]) ) {
		print "$jmbag $prezime $ime - PROBLEM $termin_parts[0] $termin_parts[1] --> $zakljucano";
	}
}

sub provjeri_interval {
	my($termin_datum, $termin_pocetak, $zakljucano_datum, $zakljucano_vrijeme) = @_;
	if($termin_datum ne $zakljucano_datum) {
		return 0;
	}
	my($termin_timestamp) = &timestamp($termin_pocetak);
	my($zakljucano_timestamp) = &timestamp($zakljucano_vrijeme);

	($zakljucano_timestamp - $termin_timestamp) < 3600;
}

sub timestamp {
	my($hours, $minutes, $seconds) = split(/:/, $_[0]);

	$hours * 3600 + $minutes * 60 + $seconds;
}

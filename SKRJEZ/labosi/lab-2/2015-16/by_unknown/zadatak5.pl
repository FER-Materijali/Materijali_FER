open FILE, $ARGV[$#ARGV];

chomp($line = <FILE>);
@factors = split(/;/, $line);

@students = ();
while(defined($line = <FILE>)) {
	chomp($line);
	$line =~ s/-/0/;
	($jmbag, $prezime, $ime, $komponente) = split(/;/, $line, 4);

	unshift @students, &calculate . ";$prezime;$ime;$jmbag";
}
@sorted = sort { $b <=> $a } @students;

print "Lista po rangu:\n";
print "---------------------\n";
for( (0..$#sorted) ) {
	($score, $prezime, $ime, $jmbag) = split(/;/, $sorted[$_]);
	printf "%3d. %-50s : %-.2f\n", $_ + 1, "$prezime, $ime ($jmbag)" , $score;
}

sub calculate {
	my $score = 0;
	my @parts = split(/;/, $komponente);
	for ( (0 .. $#factors) ) {
		$score += $parts[$_] * $factors[$_];
	}
	$score;
}


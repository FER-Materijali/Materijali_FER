#!/usr/bin/perl

open my $traka, "<traka.txt" or die "Ne mogu otvoriti datoteku traka.txt!";
my @trakaArr = <$traka>;
close $traka;
@polje = split(//, $trakaArr[0]);
unshift(@polje,'#');

open my $definicija, "<definicija.txt" or die "Ne mogu otvoriti datoteku definicija.txt!";
my @definicijaArr = <$definicija>;
close $definicija;

# skup stanja
$definicijaArr[0] =~ s/^.*\((.*)\)/$1/;
@skupStanja = split /,/, $definicijaArr[0];
chomp ($skupStanja[-1]);

# abeceda trake
$definicijaArr[1] =~ s/^.*\((.*)\)/$1/;@abecedaTrake 
= split /,/, $definicijaArr[1];
chomp ($abecedaTrake[-1]);

# pocetno stanje
$definicijaArr[2] =~ s/^.*\((.*)\)/$1/;
chomp ($pocetnoStanje = $definicijaArr[2]);

# prihvatljiva stanja
$definicijaArr[3] =~ s/^.*\((.*)\)/$1/;
@prihvatljivaStanja = split /,/, $definicijaArr[3];
chomp ($prihvatljivaStanja[-1]);

my $trenPolozaj = 1; # polje[1]
my $stanje = $pocetnoStanje;

print "Traka na pocetku:" . " " x 2; print "@polje\n";
print "Pocetno stanje:" . " " x 4; print "$stanje\n";
print "Znak na traci:" . " " x 5; print "$polje[1]\n\n";

while (1) {
	
	my $traka = $polje[$trenPolozaj];
	if ($traka eq '') { $traka = "E"; $trakaTmp = "E"; }
	else { $trakaTmp = $traka };
	my @tmpArr = grep(/^\($stanje,$trakaTmp\)=/,@definicijaArr);
	chomp(my $prijelaz = $tmpArr[0]);
	if (length($prijelaz) < 10) {
		print "Ne postoji prijelaz\n\n";
		print "Niz nije prihvatljiv\n";
		exit;
	}
	$_ = $prijelaz;	s/\(.*\)=\((.*)\)/$1/;
	my @tmpArr = split /,/, $_;
	($novoStanje, $novaTraka, $pomak) = ($tmpArr[0], $tmpArr[1], $tmpArr[2]);
	
	$stanje = $novoStanje; # promjena stanja
	$polje[$trenPolozaj] = $novaTraka; # zamjena na traci
	if ($pomak eq "R") { $trenPolozaj++; } # pomak lijevo/desno
	elsif ($pomak eq "L") { $trenPolozaj--; }
	else { die "Greska kod pomaka trake\n"; }
	
	print "Prijelaz:" . " " x 10; print "$prijelaz\n";
	print "Novo stanje:" . " " x 7; print "$novoStanje\n";
	print "Promjena na traci: "; print "$traka => $novaTraka\n";
	print "Pomak:" . " " x 13; print "$pomak\n";
	print "Traka:" . " " x 13; print "@polje\n\n";
	
	# provjera
	if (! grep {$_ eq $stanje} @skupStanja) { 
		die "Nalazimo se u stanju koje nije u skupu stanja automata!\n";
	}
	if (! grep {$_ eq $traka} @abecedaTrake) {
		die "Na traci je znak koji nije u abecedi automata!\n";
	}
	if (grep {$_ eq $novoStanje} @prihvatljivaStanja) { 
		$br = 0;
		foreach (0..$#polje) {
			$br++;
			if ($polje[$_] eq "=") { last; }
		}
		$rj = $#polje - $br + 1;
		print "Niz je prihvatljiv!\n";
		exit;
	}
}

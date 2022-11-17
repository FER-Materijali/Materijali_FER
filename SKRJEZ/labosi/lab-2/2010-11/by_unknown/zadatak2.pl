#!/usr/bin/perl

print "Unesite Brojeve; Odvojite ih Razmakom ili zarezom\n";

chomp($brojevi = <STDIN>);

@listaBrojeva = split/[^0-9\.]+/,$brojevi;

if(@listaBrojeva < 1) {
	
	print "Unijeli ste prazan niz\n";

}

else {

	$suma = 0;
	foreach $broj(@listaBrojeva) {
		
		$suma += $broj;
		
	}
	
	print $suma/(@listaBrojeva);
	
}

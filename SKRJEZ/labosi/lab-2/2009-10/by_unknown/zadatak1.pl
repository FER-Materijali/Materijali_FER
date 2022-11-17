#!/usr/bin/perl

print "Unesite znakovni niz koji zelite ponavljati:\n";
$redak = <STDIN>;
print "Unesite broj ponavljanja:\n";
$brojPonavljanja = <STDIN>;
while($brojPonavljanja > 0){
	$brojPonavljanja -= 1;
	print $redak;
}


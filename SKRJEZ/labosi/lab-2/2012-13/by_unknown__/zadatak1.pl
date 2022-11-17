#!perl

print "Unesite niz znakova:\n";
chomp($NizZn = <STDIN>);

print "Unesite broj ponavljanja:\n";
chomp($BrPon = <STDIN>);
while($BrPon =~ /\D/) {
	print "Ponovno unesite broj ponavljanja:\n";
	chomp($BrPon = <STDIN>);
}

while($BrPon) {
	print "$NizZn\n";
	$BrPon -= 1;
}
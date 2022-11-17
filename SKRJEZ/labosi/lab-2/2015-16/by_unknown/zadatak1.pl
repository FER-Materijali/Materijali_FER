print "Unesite niz znakova\n";
chomp($niz = <STDIN>);
print "unesite broj ponavljanja\n";
chomp($n = <STDIN>);

$niz = "$niz\n" x $n;
print "$niz";


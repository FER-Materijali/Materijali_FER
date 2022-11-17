#!/usr/bin/perl -w

print "Ucitajte niz znakova:\n";
chomp ($niz = <STDIN>);
print "Unesite broj ponavljanja:\n";
chomp ($broj = <STDIN>);

print $niz x $broj . "\n";

exit 0;
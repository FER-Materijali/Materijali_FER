#!/usr/bin/perl -w

print "Upišite niz znakova:\n";
chomp($niz = <STDIN>);
print "Upišite broj ponavljanja:\n";
chomp($n=<STDIN>);
for my $i (1..$n){
 print "$niz\n";
}


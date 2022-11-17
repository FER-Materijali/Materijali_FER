#!/usr/bin/perl -w

print "Upišite brojeve:\n";
chomp(@brojevi=<STDIN>);
$n=@brojevi;
foreach my $broj (@brojevi){
 $zbroj += $broj;
}
$arsr=$zbroj/$n;
printf "Aritmetička sredina je: %.2f\n",$arsr;


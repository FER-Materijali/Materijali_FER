#!/usr/bin/perl -w

$pocetak=0;
while(<>){
 $linija = $_;
 ($datum) = $ARGV =~ m/([\d]{4}-[\d]{2}-[\d]{2})/;
 ($sat) = $linija =~ m/[\d]{4}:([\d]{2}):[\d]{2}:[\d]{2}/;
 if($pocetak==0){
  $pocetak=1;
  print "\nDatum: $datum\n";
  print "sat : broj ponavljanja\n";
  print "----------------------------\n";
  $pristupi{$sat}++;
 }else{
  $pristupi{$sat}++;
 }
 if(eof){
  foreach $vrijeme (sort keys %pristupi){
   printf "%3d : %d\n",$vrijeme,$pristupi{$vrijeme};
  }
  $pocetak=0;
  %pristupi=();
 }
}


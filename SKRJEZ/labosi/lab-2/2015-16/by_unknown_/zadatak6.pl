#!/usr/bin/perl -w

@alphabet = "a".."z";
$sif=$ARGV[0];
$sif_poz = &pozicija($sif)+1;
shift @ARGV;
while (defined($linija=<>)){
 chomp $linija;
 $linija = lc $linija;
 $sif = lc $sif;
 #print "Original: $linija\n";
 @rijeci = split " ",$linija;
 foreach $rijec (@rijeci){
  @slova = split "",$rijec;
  foreach $slovo (@slova){
    $poz=&pozicija($slovo);
    $novo= ($poz+$sif_poz)%26;
    $slovo = $alphabet[$novo];
  }
  $rijec = join "",@slova;
 }
 $linija = join " ",@rijeci;
 $linija = uc $linija;
 print "$linija\n";
}

sub pozicija{
 foreach $index (0..25){
  if ($alphabet[$index] eq $_[0]){
   return $index;
  }
 }
}

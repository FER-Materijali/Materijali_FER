#!/usr/bin/perl -w

$prvi_red=0;
while(defined($line = <>)){
 chomp $line;
 if($prvi_red == 0){
  @koef= split ";",$line;
  $prvi_red=1;
 }else{
  $line =~ /(^[\d]{10}[;][^\d]+)/;
  $kljuc=$1;
  @ocjene = split ";",$line;
  shift @ocjene;
  shift @ocjene;
  shift @ocjene;
  $suma=0;
  foreach $index (0..$#ocjene){
   if($ocjene[$index] ne "-"){
   $suma += $koef[$index]*$ocjene[$index];
   }
  }
  $studenti{$kljuc}=$suma;
 }
 &ispis(%studenti);
}
sub ispis{
 @sorted = sort {$studenti{$b} <=> $studenti{$a}} keys %studenti;
 print "Lista po rangu:\n";
 print "---------------------------------\n";
 $n=1;
 foreach $k (@sorted){
  @parts= split ";",$k;
  $s = "$parts[1], $parts[2] ($parts[0])";
  printf "%3d. %-35s : %.2f\n",$n,$s,$studenti{$k};
 $n++;
 }
} 

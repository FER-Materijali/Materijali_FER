#!/usr/bin/perl -w

while(<>){
 chomp;
 @parts = split "\t",$_;
 $termini{$parts[3]." ".$parts[4]}=$_;
}
$i=1;
foreach $key (sort fun keys %termini){
 @parts = split "\t",$termini{$key};
 printf "%2d %s %s %s %s\n",$i,$parts[3],$parts[4],$parts[6],$parts[2];
 $i++;
}
sub fun{
 @a1=split " ",$a;
 @b1=split " ",$b;
 return $a1[0]  cmp $b1[0] || $a1[2] cmp $b1[2];
}

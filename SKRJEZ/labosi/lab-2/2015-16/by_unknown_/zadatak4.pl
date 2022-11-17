#!/usr/bin/perl -w

$first_line_skip=0;
while(<>){
 chomp;
 if($first_line_skip==0){
  $first_line_skip=1;
 }elsif(! m/([\d]{4}-[\d]{2}-[\d]{2}).*\1/g){ #datum
  &ispis($_);
 }else{ #vrijeme
  m/([\d]+):[\d]{2}.*([\d]{2}):[\d]{2}:[\d]{2}/;
  if ($2 >= $1 + 1){
   &ispis($_);
  } 
 }
}

sub ispis(){
 @fields=split ";",$_[0];
 print "$fields[0] $fields[1] $fields[2]";
 print " - PROBLEM: ";
 ($part) = $fields[3] =~ m/(^[\d:-]+[ ][\d:]+)/;
 print "$part";
 print " --> ";
 print "$fields[4]\n";
}

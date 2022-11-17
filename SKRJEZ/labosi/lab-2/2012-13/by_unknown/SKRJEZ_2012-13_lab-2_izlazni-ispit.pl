#!perl

if(@ARGV != 1){
	die "\nKao argument treba navesti ime jedne datoteke!\n";
}

while($red = <>){
	@pom = split / /, $red;
	$adresa = $pom[0];
	$br{$adresa}++;
}

@pom = keys %br;
@pom = sort @pom;

foreach $k (@pom){
	print "$k : $br{$k}\n";
}
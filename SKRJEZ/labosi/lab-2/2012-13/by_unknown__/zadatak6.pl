#!perl

$len = pop(@ARGV);

while($red = <>){
	$red = "\L$red\E";
	@pom = ($red =~ m/\b(\w{$len})/g);
	foreach $k (@pom){
		$br{$k}++;
	}
}

@pom = keys %br;
@pom = sort @pom;

foreach $k (@pom){
	print "$k : $br{$k}\n";
}
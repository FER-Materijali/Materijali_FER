while ( <> ){
	@elemRetka = split /\ /;
	$ipAdrese{$elemRetka[0]} +=1;
}
while ( ($key, $value) = each %ipAdrese ) {
	print "$key\t->\t$value\n";
}
chomp(@numbers = <STDIN>);
$sum = 0;
for ( @numbers ) {
	$sum += $_;
}

print "Aritmeticka sredina: " . $sum / ($#numbers + 1);

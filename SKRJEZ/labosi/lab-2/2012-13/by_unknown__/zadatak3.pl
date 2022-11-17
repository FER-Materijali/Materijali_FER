#! perl

$z=0;
while(<>){
	@pom = split /\[/, $_;
	@pom1 = split /:/, $pom[1];
	$datum = $pom1[0];
	$sat = $pom1[1];
	
	if($z == 0 || $z != $datum){
		if($z != 0){
			print "  $s : $pon[$k]\n";
		}
		print "\n Date: $datum\n";
		print " sat : broj pristupa\n";
		print "------------------------------\n";
		$z = $datum;
		$k = 0;
		foreach $i (0..24){
			$pon[$i] = 0;
			$i++;
		}
	}
	
	if($z == $datum){
		if($k == $sat){
			$pon[$k]++;
			$s = $sat;
		}
		else{
			$k++;
			$pon[$k]++;
			print "  $s : $pon[$k-1]\n";
		}
	}
}
print "  $s : $pon[$k]\n";
#!perl

if(@ARGV != 1){
	die "Kao argument treba navesti ime jedne datoteke!\n";
}

print "Lista po rangu:\n";
print "----------------------------\n";

$z="DA";
$j=0;
while($red = <>){
	if($z eq 'DA'){
		@fakt = split /;/, $red;
		$n = @fakt;
		$z="NE";
	}
	else{
		@stud = split /;/, $red;
		$i=0;
		$rez=0;
		while($i < $n){
			$k=(3+$i);
			if($stud[$k] ne '-'){
				$z=($fakt[$i]*$stud[$k]);
				$rez = ($rez + $z);
			}
			else{
				$rez+=0;
			}
			$i++;
		}
		$list[$j] = "$rez $stud[0] $stud[1] $stud[2]";
		$j++;
	}
}

@pom = reverse sort(@list);
$i=0;
$k=1;
while($i < $j){
	@p = split / /, $pom[$i];
	$list = "$p[2], $p[3] ($p[1])";
	printf "%3d. %-35s : %5.2f\n", $k, $list, $p[0];
	$i++;
	$k++;
}
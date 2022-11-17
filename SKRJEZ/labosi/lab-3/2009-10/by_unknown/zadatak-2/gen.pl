open IN, ">ulaz.txt";

$i=0;
while($i<20){
	$numel = (rand(10)+1)*10;
	$j = 0;
	while($j<=$numel){
		print IN rand()*20;		
		if($j<$numel){
			print IN " ";
		}
		$j++;
	}
	print IN "\n";
	$i++;
}
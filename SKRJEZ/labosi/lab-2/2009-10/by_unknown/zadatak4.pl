$regIzraz = shift @ARGV;
if($regIzraz eq "-v"){
	$negacija=0;
	$regIzraz = shift @ARGV;	
}else{
	$negacija=1;
}
while(<>){
	chomp($_);
	if( m/.*($regIzraz).*/g ){
		if($negacija){
			print $_,"\n";
		}		
	}else{
		if(!$negacija){
			print $_,"\n";
		}
	}
}

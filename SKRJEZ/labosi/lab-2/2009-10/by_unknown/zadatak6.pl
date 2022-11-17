if(@ARGV < 1){	
	die "Ocekivan je barem jedan parametar - pocetak sifre.";
}

$_ = shift @ARGV;
if( $_ eq "-d" ){
	$desifriranje = 1;
	$_ = shift@ARGV;
}else{
	$desifriranje = 0;
}

$pomak =  ord( uc $_ ) - ord('A') +1 ;
if($desifriranje){
	$pomak = 26 - $pomak;
}

while(<>){
	split //, $_;
	foreach $znak (@_){
		$o = ord( uc $znak);
		if( $o>64 && $o < 91 ){			
			$o = (( ord( uc $znak) + $pomak ) % 65) % 26 + 65;
			print chr $o;						
		}else{
			print $znak;			
		}
	}
}
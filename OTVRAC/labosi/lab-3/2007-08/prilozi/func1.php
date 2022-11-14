<?php

$val = 5;
$glob = 2;
$ret = add($val);		//poziv funkcije prije njene definicije, u ovom slucaju dopusteno

function add($var) {

	$temp = $var+1;		//u $temp ide vrijednost $var uvecana za 1
	$var = -1;			//vrijednost $var je -1, $val je varijabla lokalna funkciji!
	$glob = 4;			//$glob je varijabla lokalna funkciji, nije $glob definirana prije definicije funkcije!
	return $temp;
}

echo "$glob  $val  $ret\n";	//vrijednosti $glob i $val su ocuvane

?>


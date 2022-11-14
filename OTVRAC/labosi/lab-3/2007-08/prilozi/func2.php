<?php

function add(&$var, $inc=1) {	//prenosenje vrijednosti po referenci, moguc utjecaj na vrijednost varijable argumenta
								//podrazumijevana vrijednost je 1
						
	$temp = $var+$inc;			//u $temp ide vrijednost $var uvecana za drugi argument
	$var = 0;					//vrijednost $var je 0, $val je referenca na varijablu argument
	return $temp;
}

$val = 5;						//vrijednost $val na 5
$ret = add($val);				//poziv funkcije samo s jednim parametrom

echo "$ret  $val\n";			//vrijednost $glob je ocuvana, $val nije!

//echo add(5, 2);				//ovo je greska, zbog call-by-reference prvi argument mora biti varijabla!

$val=5;							//vrijednost $val opet na 5
echo add($val,2) . "  " . $val;	//poziv funkcije s dva argumenta

?>


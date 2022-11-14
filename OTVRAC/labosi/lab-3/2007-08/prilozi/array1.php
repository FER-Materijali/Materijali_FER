<?php
$arr1 = array( 	0 => "nula",
		1 => 'jedan',
		2 => 'dva');
$arr2 = array( 	'nula' => 0,
		'dva' => 'nije po redu',
		1 => 'ali vrijedan');
$arr3 = array( 'pocetni' => '-----',
		'prvi' => $arr1,
		'drugi' => $arr2);

$arr4 = array( 5, 12, 5, 'b', 'a');

if( is_array($arr1) ) echo "\$arr1 je polje!\n";

print_r($arr3);
echo "\n--------------------\n";
echo $arr1[0] . " " . $arr2['dva'] . 
   " " . $arr3['prvi'][2];
echo "\n--------------------\n";
print_r($arr4);
?>
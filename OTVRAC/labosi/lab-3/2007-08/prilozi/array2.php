<?php
$arr1 = array( 2 => 5, 12, 5, 'e1' => 'b', 'e2' => 'a');

print_r($arr1);
echo "\n--------------------\n";
$arr1[] = 7;
$arr1['e3'] = 'c';
$arr1[3] = 11;
unset($arr1['e1']);

print_r($arr1);
?>
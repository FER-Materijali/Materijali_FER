<?php
$arr2 = array(0, 1, 2, 'c');
$arr1 = array(5, 12, $arr2, 'el1', 5, 'el2');

foreach($arr1 as $key => $value) {
   if( is_array($value) == TRUE ) echo "$key => Polje\n";
   else echo "$key => $value\n";
}
echo "--------------------\n";
foreach($arr1 as $value)
   echo "$value\n";
?>

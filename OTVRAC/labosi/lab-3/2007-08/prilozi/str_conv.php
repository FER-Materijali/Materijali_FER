<?php
$str1 = '10 litara';  $str2 = 'deset litara';  $str3 = '10.0';
$int1 = 10;  $bool1 = true;  $bool2 = false;  $float1 = 10.3;

$val = 0 + $str1;   echo $val . ": " . gettype($val) . "\n";
$val = 0 + $str2;   echo $val . ": " . gettype($val) . "\n";
$val = 0 + $str3;   echo $val . ": " . gettype($val) . "\n";
echo "----------------------------\n";
$str = strval($int1);   echo $str . ": " . gettype($str) . "\n";
$str = strval($bool1);   echo $str . ": " . gettype($str) . "\n";
$str = strval($bool2);   echo $str . ": " . gettype($str) . "\n";
$str = strval($float1);   echo $str . ": " . gettype($str) . "\n";
?>

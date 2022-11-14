<?php
$str1 = 'Hello, ';
$str2 = "World!";

$res1 = $str1 + $str2;
$res2 = $str1 . $str2;

$res3 = $str2;
$res3[strlen($res3)-1] = '?';

echo '$res1 | $res2 | $res3\n';
echo "$res1 | $res2 | $res3\n";
?>

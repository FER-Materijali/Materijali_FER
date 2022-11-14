<?php
$var1 = TRUE;	//boolean
$var2 = 24;		//integer
$var3 = "or";	//string
$var4 = 3.14;	//float

$res1 = $var1 + $var2;
$res2 = $var2 + $var3;
$res3 = ($var2 == $res2);
$res4 = is_bool($var1);

echo "\$res1=$res1, \$res2=$res2, \$var1=$var1,",
 " \$res3=$res3, \$var3=$var3, \$res4=$res4 \n";

echo gettype($res1), ", ", gettype($res2), ", ", gettype($var1), 
 ", ", gettype($res3), ", ", gettype($var3), ", ", gettype($res4);
?>
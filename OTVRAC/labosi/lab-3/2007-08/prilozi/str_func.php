<?php
$str = "  Hello, world! What a nice day.";
$delimiters = " ,!.";
$matching = "day";
$day = 11; $month=21; $year = 1864;

printf("Today is %d-%d-%d.\n", $year, $month, $day);

echo ">" . trim($str) . "<\n";
echo substr($str, 0, strpos($str, ',')) . "\n";

$token = strtok($str, $delimiters);
while($token !== FALSE) {
   echo "|$token";
   if( strcmp($matching, $token) == 0 ) echo "*";
   $token = strtok($delimiters);
}
echo "|\n";
?>

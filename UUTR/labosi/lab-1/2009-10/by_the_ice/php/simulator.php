<?php
  $def=file("definition.txt");
  for($i=0;$i<count($def);$i++) { //load the definition
    $tmp=explode(" ",str_replace("\n","",$def[$i]));
    $automat[$tmp[0]][$tmp[1]]=$tmp[2];
    $state[$tmp[2]]=$tmp[3];
  }
  $cur_state="START"; $state[$cur_state]=1;
  $val=explode(" ",file_get_contents("simulation.txt"));
  for($i=0;$i<count($val);$i++)
    if($automat[$cur_state][$val[$i]]!="") {
      echo "$val[$i] $cur_state => ".$automat[$cur_state][$val[$i]]."\n"; 
      $cur_state=$automat[$cur_state][$val[$i]];
    } else
      die("\nNiz nije prihvacen!");
  if($state[$cur_state])
    die("\nNiz prihvacen!");
  echo "\nNiz nije prihvacen!";
?>
<?php
  $def=file("definition.txt");
  for($i=0;$i<count($def) && $tmp=explode(" ",str_replace("\n","",$def[$i]));$i++)
    $automat[$tmp[0]][$tmp[1]]=$tmp[2];
  $cur_state="START";
  $val=explode(" ",file_get_contents("simulation.txt"));
  for($i=0;$i<count($val);$i++)
    $cur_state=$automat[$cur_state][$val[$i]] or die("\nNiz nije prihvacen!");
  (!stripos($cur_state,"_")) ? die("\nNiz prihvacen!") : die("\nNiz nije prihvacen!");
?>
<?php
  $state=array();
  $site[0]["name"]="START";
  $input=file("input.txt"); //ulaz iz kojeg se generira definicija
  for($i=0;$i<count($input);$i++) { //ucitaj sve stranice
    $tmp=explode("|",$input[$i]);
    if(count($tmp)==3) {
      $tmp2=explode(":",$tmp[0]);
      $site_id=$tmp2[0];
      $site[$site_id]["name"]=$tmp2[1];
      $site[$site_id]["link"]=explode(",",$tmp[1]);
      $site[$site_id]["res"]=str_replace(",","_",str_replace("\r\n","",$tmp[2]));
      if($site[$site_id]["res"]) $site[$site_id]["res"]="_".$site[$site_id]["res"];
    }
  }
  $site[0]["link"]=range(1,count($site)-1); //START linka na sve druge
  for($i=0;$i<count($site);$i++) //generiraj slijedece stanje (sa resursima) za svaki link
    for($j=0;$j<count($site[$i]["link"]);$j++) {
      $next=$site[$i]["link"][$j];
      $next_state=$site[$next]["name"].$site[$next]["res"];
      $automat[$site[$i]["name"]][$site[$next]["name"]]=$next_state;
      array_push(&$state,$next_state);
    }
  for($i=0;$i<count($state);$i++) // loop kroz sva stanja moguce resurse
    if(is_array($automat[$state[$i]])==false) { //ako stanje nije definirano
      $res=explode("_",$state[$i]); //definiraj stanje za sve moguce ulaze
      for($j=1;$j<count($res);$j++) {
        $next_state=str_replace("_".$res[$j],"",$state[$i]);
        $automat[$state[$i]][$res[$j]]=$next_state;
        array_push(&$state,$next_state);
      }
    }
  $fp=fopen("definition.txt","w");
  while($automat_name=key($automat)) {
    while($res=key($automat[$automat_name])) {
      $state_good=1;
      $next_state=$automat[$automat_name][$res];
      if(strpos($next_state,"_")) $state_good=0; //stanje sadrzi jos resursa - nije prihvatljivo
      fwrite($fp,"$automat_name $res $next_state $state_good\n");
      echo "$automat_name $res $next_state $state_good\n";
      next($automat[$automat_name]);
    }
    next($automat);
  }
  fclose($fp);
?>
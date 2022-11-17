<?php
  $state=array();
  $input=file("input.txt");
  for($i=0;$i<count($input) && $tmp=explode("|",str_replace(" ","",$input[$i]));$i++) {
    $tmp2=explode(":",$tmp[0]);
    $site[$tmp2[0]]=array("name"=>$tmp2[1],"link"=>explode(",",$tmp[1]),"res"=>($tmp[2]!="\r\n") ? "_".str_replace(",","_",str_replace("\r\n","",$tmp[2])) : "" );
  }
  $site[0]=array("name"=>"START","link"=>range(1,count($site)));
  for($i=0;$i<count($site);$i++)
    for($j=0;$j<count($site[$i]["link"]) && $next=$site[$i]["link"][$j];$j++)
      array_push(&$state,$automat[$site[$i]["name"]][$site[$next]["name"]]=$site[$next]["name"].$site[$next]["res"]);
  for($i=0;$i<count($state);$i++)
    if(is_array($automat[$state[$i]])==false && $res=explode("_",$state[$i]))
      for($j=1;$j<count($res);$j++)
        array_push(&$state,$automat[$state[$i]][$res[$j]]=str_replace("_".$res[$j],"",$state[$i]));
  $fp=fopen("definition.txt","w");
  while($automat_name=key($automat)) {
    while($res=key($automat[$automat_name])) {
      fwrite($fp,"$automat_name $res ".$automat[$automat_name][$res]."\n");
      next($automat[$automat_name]);
    }
    next($automat);
  }
  fclose($fp);
?>
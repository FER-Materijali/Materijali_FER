<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>UTR - LAB1</title>
</head>

<body>
<?
	
	
	
	$a_1_txt_src=$a_1_txt='http://127.0.0.1/faks/utr/lab1/a1.txt';	
	$status_a_1_txt=0;
	
	
	
	$a_2_txt_src=$a_2_txt='http://127.0.0.1/faks/utr/lab1/a2.txt';	
	$status_a_2_txt=0;
	
	if (isset($_REQUEST["a_1_txt"])) {
		$a_1_txt_get=$_REQUEST["a_1_txt"];	
		
		if ($a_1_txt_get=@file_get_contents($a_1_txt_get)) {
			$status_a_1_txt=1;
			$a_1_txt_src=$_REQUEST["a_1_txt"];
		} else {
			$status_a_1_txt=2;	
		}
		
	}	
	
	if (isset($_REQUEST["a_2_txt"])) {
		$a_2_txt_get=$_REQUEST["a_2_txt"];	
		
		if ($a_2_txt_get=@file_get_contents($a_2_txt_get)) {
			$status_a_2_txt=1;
			$a_2_txt_src=$_REQUEST["a_2_txt"];
		} else {
			$status_a_2_txt=2;	
		}
		
	}
	
	
	if ( ($status_a_1_txt==0) or ($status_a_1_txt==2) ) {
		$a_1_txt_get=file_get_contents($a_1_txt);
	}
	
	if ( ($status_a_2_txt==0) or ($status_a_2_txt==2) ) {
		$a_2_txt_get=file_get_contents($a_2_txt);
	}
		
		
	$a_1_pars=explode("\r\n",$a_1_txt_get);
	$a_2_pars=explode("\r\n",$a_2_txt_get);
	
	$a_1=array();
	$a_2=array();
	
	//echo $status_a_1_txt.' '.$status_a_2_txt.' '.$a_1_txt_get.' '.$a_2_txt_get;
	
		for ($i=0;$i<sizeof($a_1_pars);$i++) {
		
			if ($i<=3) {
				
				if ( ($i==0) or ($i==1) or ($i==2) ) {
					$a_1[$i]=explode (",",$a_1_pars[$i]);	
				}
				
				if ($i==3) {
					$a_1[$i]=$a_1_pars[$i];	
				}
				
			} else {
				
				if ($i>=4) {
					
					if ($i==4) {
						$a_1[$i]=array();	
					}
				
					$b=explode ("->",$a_1_pars[$i]);	
					
					$c=explode (",",$b[1]);
					
					$b=explode (",",$b[0]);
					
					
					if (!isset($a_1[4][$b[0]])) {
						$a_1[4][$b[0]]=array();
					}
					
					
					
					$a_1[4][$b[0]][$b[1]]=$c;
					
					
					
				}
					
			}
			
			
		}
		
		for ($i=0;$i<sizeof($a_2_pars);$i++) {
		
			$a_2[$i]=array();
			
			for ($j=0;$j<strlen($a_2_pars[$i]);$j++) {
				
				$a_2[$i][$j]=$a_2_pars[$i][$j];
					
			}
			
		}
		
		
		
	function okruzenje ($stanje,$znak='$') {
		
		global $a_1;
		
		if (isset($a_1[4][$stanje][$znak])) {
			return $a_1[4][$stanje][$znak];
		} else {
			return array();	
		}
	
	}
	
	function epsilon_okruzenje ($arr=array()) {
	
		//zadano početno stanje	prima kroz parametar $arr
		$okr=$arr;
		$i=0;
		
		while ($i<sizeof($okr)) {
			
			$temp=okruzenje($okr[$i]);
			
			for ($j=0;$j<sizeof($temp);$j++) {
			
				if (!in_array($temp[$j],$okr)) {
					$okr[]=$temp[$j];	
				}
				
			}
			
			$i++;
				
		}
		
		return $okr;	
		
	}
	
	
	function obrada_znaka ($ulaz_stanja=array(),$znak) {
	
		$izlaz_stanja=array();
		
		for ($i=0;$i<sizeof($ulaz_stanja);$i++) {
			
			
			$temp=okruzenje($ulaz_stanja[$i],$znak);
			
			for ($j=0;$j<sizeof($temp);$j++) {
			
				if (!in_array($temp[$j],$izlaz_stanja)) {
					$izlaz_stanja[]=$temp[$j];	
				}
				
			}
			
		}
		
		return $izlaz_stanja;
		
	}
	
	
	function print_format ($arr_1,$arr_2,$znak='$') {
		
		if ($znak==='$') {
		
			echo 'OKRUZENJE(';
			
				echo implode(',',$arr_1);
			
			echo ') ----> ';
			
				echo implode(',',$arr_2);
			
		} else {
			
			echo implode(',',$arr_1);
			
			echo ' --'.$znak.'--> ';
			
			echo implode(',',$arr_2);
			
		}
		
		echo '<br />';
		
	}
	
	
	function provjeri_prihvatljivost ($stanja) {
		
		$status=0;
		
		global $a_1;
		
		for ($i=0;$i<sizeof($stanja);$i++) {
		
			if (in_array($stanja[$i],$a_1[2])) {
				$status=1;	
			}
			
		}
		
		return $status;
		
	}
	
	
	
	
	
	
	
	
	
		
		
		
		
	
	
?>
<h1>Uvod u teoriju računarstva / 2011 / LAB1 / &epsilon; - NKA</h1>

<hr />

<form action="" method="post" >
	URL do datoteke &quot;Definicije konačnog automata&quot;: <input type="text" name="a_1_txt" value="<? echo $a_1_txt_src; ?>" style="width:500px;"  />
    <br /><br />
    URL do datoteke &quot;Sa ulaznim nizovima&quot;: <input type="text" name="a_2_txt" value="<? echo $a_1_txt_src; ?>" style="width:500px;" />
    <br /><br />
    <input type="submit" value="IZVRŠITI"  />
</form>

<hr />

<?
	if ( ($status_a_1_txt==0) or ($status_a_1_txt==2) or ($status_a_2_txt==0) or ($status_a_2_txt==2) ) {
?> 
    <span style="color:red;" >
        Notifications: <br />
        <?
			if ($status_a_1_txt==0) {
				echo 'Trenutno nije izabrana datoteka Definicije konačnog automata i zato je zadana datoteka: &quot;'.$a_1_txt.'&quot;<br />';
			}
			
			if ($status_a_2_txt==0) {
				echo 'Trenutno nije izabrana datoteka Ulaznog niza i zato je zadana datoteka: &quot;'.$a_2_txt.'&quot;<br />';
			}
			
			if ($status_a_1_txt==2) {
				echo 'Naveli ste pogrešan URL do datoteke Definicije konačnog automata i zato je zadana datoteka: &quot;'.$a_1_txt.'&quot;<br />';
			}
			
			if ($status_a_2_txt==2) {
				echo 'Naveli ste pogrešan URL do Ulaznog niza i zato je zadana datoteka: &quot;'.$a_2_txt.'&quot;<br />';
			}
		?>
    </span>
    
    <hr />
<?
	}
?>



IZLAZ PROGRAMA:

<div style="font-family:'Courier New', Courier, monospace;" >

    <?
//Status ULAZNOG niza
	$ulaz_status=1;
	
	//početna vrijednost iz 3. reda 1. datoteke
		$pocetno=array($a_1[3]);
	
	//obrada nizova znakova koji dolaze iz 2. datoteke
	for ($i=0;$i<sizeof($a_2);$i++) {
		
		echo '&quot;'.implode('',$a_2[$i]).'&quot;<br />';
		
		$okr=epsilon_okruzenje($pocetno);
		print_format ($pocetno,$okr);
	
		for ($j=0;$j<sizeof($a_2[$i]);$j++) {
			
			if (!in_array($a_2[$i][$j],$a_1[1])) {
			
				echo '<span style="color:red;" >NIZ JE NEISPRAVAN, JER ZNAK '.$a_2[$i][$j].' NIJE U ABECEDI</span>';
				
				$NOT_OK=1;
				
				break;
				
				
				
			}
			
			$okr_2=obrada_znaka($okr,$a_2[$i][$j]);	
			
			print_format ($okr,$okr_2,$a_2[$i][$j]);
			
			$okr=$okr_2;
			
			$okr=epsilon_okruzenje($okr);
			print_format ($okr_2,$okr);
			
			
		}
		
		if (!isset($NOT_OK)) {
			$prihvatljivo=provjeri_prihvatljivost($okr);
			
			if ($prihvatljivo==1) {
				echo '<span style="color:green;" >NIZ JE PRIHVATLJIV</span>';	
			} else {
				echo '<span style="color:red;" >NIZ NIJE PRIHVATLJIV</span>';	
			}
		} else {
			unset ($NOT_OK);	
		}
		
		
		echo '<hr />';
		
	}
    ?>
</div>

</body>
</html>
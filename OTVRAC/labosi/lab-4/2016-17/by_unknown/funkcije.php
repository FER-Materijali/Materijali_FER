<?php
//print_r($_REQUEST);
	function upper($string) {
		return	"translate(" . $string . ",  'abcdefghijklljmnnjopqrstuvwxyzšđčćž', 'ABCDEFGHIJKLLJMNNJOPQRSTUVWXYZŠĐČĆŽ')";
	}
	
	

		function upit() {
			$query = array();
			
		if (!empty($_REQUEST['ime']))
			$query[] = 'contains(' . upper('ime') . ', "' . mb_strtoupper($_REQUEST['ime'], "UTF-8") . '")';
			
		if (!empty($_REQUEST['grad']))
			$query[] = 'contains(' . upper('grad') . ', "' . mb_strtoupper($_REQUEST['grad'], "UTF-8") . '")';

		if (!empty($_REQUEST['imepred']))
			$query[] = 'contains(' . upper('predsjednik/imepred') . ', "' . mb_strtoupper($_REQUEST['imepred'], "UTF-8") . '")';
		
		if (!empty($_REQUEST['prezimepred']))
			$query[] = 'contains(' . upper('predsjednik/prezimepred') . ', "' . mb_strtoupper($_REQUEST['prezimepred'], "UTF-8") . '")';

		if (!empty($_REQUEST['drzava'])) {
			$drzavaQuery = array();
			foreach ($_REQUEST['drzava'] as $elem) {
				$drzavaQuery[] = "@drzava='" . $elem . "'";
			}
		}
			if (!empty($drzavaQuery))
				$query[] =  "(" . implode( " or ", $drzavaQuery) . ")";
	
		if (!empty($_REQUEST['velicina']))
			$query[] = 'contains(kapacitet/@velicina, "' . $_REQUEST['velicina'] . '")';
		
		if (!empty($_REQUEST['navijac']))
			$query[] = 'contains(@navijac, "' . $_REQUEST['navijac'] . '")';
		if (!empty($_REQUEST['osvajac']))
			$query[] = 'contains(@osvajac, "' . $_REQUEST['osvajac'] . '")';
		if (!empty($_REQUEST['osnivac']))
			$query[] = 'contains(@osnivac, "' . $_REQUEST['osnivac'] . '")';
		if (!empty($_REQUEST['redovit']))
			$query[] = 'contains(@redovit, "' . $_REQUEST['redovit'] . '")';
		
		
		if (!empty($_REQUEST['navijaci']))
			$query[] = 'contains(' . upper('navijaci') . ', "' . mb_strtoupper($_REQUEST['navijaci'], "UTF-8") . '")';

		if (!empty($_REQUEST['trofeji']))
			$query[] = 'contains(' . upper('trofeji') . ', "' . mb_strtoupper($_REQUEST['trofeji'], "UTF-8") . '")';

		
		$xpathQuery = implode(" and ", $query);
		
			
			
		


		
		if(!empty($xpathQuery))
			return "/klubovi/klub[" . $xpathQuery . "]";

		else
			return "/klubovi/klub";
	}	
	function fb_slika($argument) {
		$link = "https://graph.facebook.com/"  . $argument . "?fields=picture,website&access_token=258535104503215|7825f7090b47560fec6caa9e49437140";
			
			$fts = file_get_contents($link);
			$encod = utf8_encode($fts);
			$dekodirano = json_decode($encod, true);
		/* 	upravljanje pogreškama, sad nece raditi jer ova funkcija vraća argument slike u url u pretraga.php
			if (isset ($dekodirano["error"])){
			echo "Dogodila se greška.";
			return "code " . $dekodirano["error"]["code"];
			break;}
			else */
			return $dekodirano["picture"]["data"]["url"];
	} 
	
	
		function fb_adresa($argument) {
			$link = "https://graph.facebook.com/" . $argument . "?fields=location,website&access_token=258535104503215|7825f7090b47560fec6caa9e49437140";
			$fts = file_get_contents($link);
			$encod = utf8_encode($fts);
			$dekodirano = json_decode($encod, true);
			if (isset ($dekodirano["location"]["city"]))
			{return $dekodirano["location"]["city"];}		
		
	}
	
		function fb_web($argument) {
			$link = "https://graph.facebook.com/" . $argument . "?fields=location,website&access_token=258535104503215|7825f7090b47560fec6caa9e49437140";
			$fts = file_get_contents($link);
			$encod = utf8_encode($fts);
			$dekodirano = json_decode($encod, true);
			if (isset ($dekodirano["website"]))
			{return $dekodirano["website"];}		
		
	}
		
	function geo_koord($ulaz) {
		$upit = "https://nominatim.openstreetmap.org/search?q=";
		$linkaj = rawurlencode($ulaz);
		$cijeliupit = $upit.$linkaj."&format=xml";
		return $cijeliupit;
	}
<?php 
	error_reporting(0);

	#dohvati item
	function getElementValue($node, $elementName) {
		return $node->getElementsByTagName($elementName)->item(0);
	}
	#hack za slova
	function sveveliko($slova) {
		return	"translate(" . $slova . ", 'abcdefghijklmnopqrstuvwxyz', 'ABCDEFGHIJKLMNOPQRSTUVWXYZ')";
	}
	
	function generiraj() {
		$polje = array();
		
		if(!empty($_REQUEST['kod'])){
			$polje[] = 'contains(@kod, "' . $_REQUEST['kod'] . '")';
		}
		
	$regijapolje = array();
    if (!empty($_REQUEST['regija'])) {
      foreach ($_REQUEST['regija'] as $regija1) {
		echo $regija1;
        $regijapolje[] = 'contains(@regija, "' . $regija1 . '")';
      }
	  if (!empty($regijapolje)){
		$polje[] = "(" . implode(" or ", $regijapolje) . ")";
	  }
	 
    }
	
	$modelipolje = array();
    if (!empty($_REQUEST['vrsta'])) {		
     foreach ($_REQUEST['vrsta'] as $vrsta1) {
        $modelipolje[] = "vrsta='" . $vrsta1 . "'";
      }
	  
	}
	  if (!empty($modelipolje)){
		$polje[] = "modeli[" . implode(" or ", $modelipolje) . "]";
	  }
	

	if (!empty($_REQUEST['usluga'])) {
        $usluge = array();


      foreach ($_REQUEST['usluga'] as $usluga) {
			$usluge[] = sveveliko('usluga') . '="' . strtoupper($usluga) . '"';
      }
		if (!empty($usluge)) {
			$polje[] = 'modeli/popis['. implode(' or ', $usluge)  . ']';
		}
    }
	
	
	$godinapolje = array();
		
	if (!empty($_REQUEST['godina'])) {
			$godinapolje[] = 'contains(godina, "' . $_REQUEST['godina'] . '")';
	}
	if (!empty($godinapolje)) {
		$polje[] = 'modeli[' . implode(' or ', $godinapolje). ']';
	}
		
		if(!empty($_REQUEST['placanje'])){
			$polje[] = 'contains(@placanje, "' . $_REQUEST['placanje'] . '")';
		}
	
	
	
		if(!empty($_REQUEST['placanje'])){
			$polje[] = 'contains(@placanje, "' . $_REQUEST['placanje'] . '")';
		}
		
		if (!empty($_REQUEST['ime'])){
			$polje[] = 'contains(' . sveveliko('ime') . ', "' . strtoupper($_REQUEST['ime']) . '")';
		}
		
		if (!empty($_REQUEST['probna'])){
			$polje[] = 'contains(' . sveveliko('probna') . ', "' . strtoupper($_REQUEST['probna']) . '")';
		}
		if (!empty($_REQUEST['email'])){
			$polje[] = 'contains(' . sveveliko('email') . ', "' . strtoupper($_REQUEST['email']) . '")';
		}
		if (!empty($_REQUEST['termin'])){
			$polje[] = 'contains(' . sveveliko('termin') . ', "' . strtoupper($_REQUEST['termin']) . '")';
		}
		
		$radnovrijeme = array();
		
		if (!empty($_REQUEST['testradno'])) {
			$radnovrijeme[] = 'radnop <= ' . $_REQUEST['testradno'];
		}
		if (!empty($_REQUEST['testradno'])) {
			$radnovrijeme[] = 'radnok >= ' . $_REQUEST['testradno'];
		}
		if (!empty($radnovrijeme)) {
			$polje[] = 'rvrijeme[' . implode(' and ', $radnovrijeme). ']';
		}
		
		if (!empty($_REQUEST['dezurni'])){
			$polje[] = 'contains(' . sveveliko('dezurni') . ', "' . strtoupper($_REQUEST['dezurni']) . '")';
		}
		
		if (!empty($_REQUEST['grad'])){
			echo mb_strtoupper($_REQUEST['grad'], "UTF-8");
			$polje[] = 'contains(' . sveveliko('grad') . ', "' . mb_strtoupper($_REQUEST['grad'], "UTF-8") . '")';
		}
		
		if (!empty($_REQUEST['pbr'])) {
			$polje[] = 'contains(pbr, "' . $_REQUEST['pbr'] . '")';
		}
		
		if (!empty($_REQUEST['ulica'])){
			$polje[] = 'contains(' . sveveliko('ulica') . ', "' . strtoupper($_REQUEST['ulica']) . '")';
		}
		
		if (!empty($_REQUEST['br'])) {
			$polje[] = 'contains(br, "' . $_REQUEST['br'] . '")';
		}
		
		$stringupita = implode(' and ', $polje);
		
		if (empty($stringupita)) {
			return '/poslovnice/poslovnica';
		}
		else {
			return '/poslovnice/poslovnica[' . $stringupita .']';
		}
	}
	
	function get_picture($argument) {
		$link = "http://graph.facebook.com/" . "" . $argument . "/photos";
		if (file_get_contents($link) == FALSE) {
			$opts = array('http' =>
			array(
			'ignore_errors' => '1'
			)
			);
			$context = stream_context_create($opts);
			$stream = fopen($link, 'r', false, $context);
			$greska=stream_get_contents($stream);
			$greskadekodirano = json_decode($greska);
			#return "Code: " . $greskadekodirano->error->code . " " . "Sub-code: " . $greskadekodirano->error->error_subcode;
			return "greska.png";
		}
		$fts = file_get_contents($link);
		$dekodiranje = json_decode($fts);
		#if (isset ($dekodiranje->error[0])){
		#	echo "GRESKA";
		#	return "code " . $dekodiranje->error[0]->code . " " . "subcode" . $dekodiranje->error[0]->error_subcode;
		#	break;
		#}
		usleep(500000);
		return $dekodiranje->data[0]->picture;
	}
	
	function get_adress($argument) {
		$link = "http://graph.facebook.com/" . "" . $argument;
		if (file_get_contents($link) == FALSE) {
			$opts = array('http' =>
			array(
			'ignore_errors' => '1'
			)
			);
			$context = stream_context_create($opts);
			$stream = fopen($link, 'r', false, $context);
			$greska=stream_get_contents($stream);
			$greskadekodirano = json_decode($greska);
			echo "Dogodila se greška" . "<br>";
			return "Code: " . $greskadekodirano->error->code . " " . "Sub-code: " . $greskadekodirano->error->error_subcode;
		}
		$fts = file_get_contents($link);
		$dekodiranje = json_decode($fts);
		usleep(500000);
		return $dekodiranje->location->street . ", "  . $dekodiranje->location->city . " " . $dekodiranje->location->country ;
	}
	
	function get_adress2($argument) {
		$link = "http://graph.facebook.com/" . "" . $argument;
		if (file_get_contents($link) == FALSE) {
			$opts = array('http' =>
			array(
			'ignore_errors' => '1'
			)
			);
			$context = stream_context_create($opts);
			$stream = fopen($link, 'r', false, $context);
			$greska=stream_get_contents($stream);
			$greskadekodirano = json_decode($greska);
			echo "Dogodila se greška" . "<br>";
			return "Code: " . $greskadekodirano->error->code . " " . "Sub-code: " . $greskadekodirano->error->error_subcode;
		}
		$fts = file_get_contents($link);
		$dekodiranje = json_decode($fts);
		usleep(500000);
		return $dekodiranje->location->city . " " . $dekodiranje->location->country ;
	}
	
	function get_link($argument) {
		$link = "http://graph.facebook.com/" . "" . $argument;
		if (file_get_contents($link) == FALSE) {
			$opts = array('http' =>
			array(
			'ignore_errors' => '1'
			)
			);
			$context = stream_context_create($opts);
			$stream = fopen($link, 'r', false, $context);
			$greska=stream_get_contents($stream);
			$greskadekodirano = json_decode($greska);
			#return "Code: " . $greskadekodirano->error->code . " " . "Sub-code: " . $greskadekodirano->error->error_subcode;
			return "http://www.google.hr";
		}
		$fts = file_get_contents($link);
		$dekodiranje = json_decode($fts);
		usleep(500000);
		if (isset ($dekodiranje->website)){
			$str = $dekodiranje->website;
			$str = preg_replace('#^https?://#', '', $str);
			return "http://" . $str;
		}
		else {
			return $dekodiranje->link;
		}
	}
	
	function generiraj_osm($ulaz) {
		$upit = "http://open.mapquestapi.com/nominatim/v1/search?q=";
		$bezrazmak = rawurlencode($ulaz);
		$cijeliupit = $upit.$bezrazmak."&format=xml";
		usleep(500000);
		return $cijeliupit;
	}
	
			
?>
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		
		
		
		
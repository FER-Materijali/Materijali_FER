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
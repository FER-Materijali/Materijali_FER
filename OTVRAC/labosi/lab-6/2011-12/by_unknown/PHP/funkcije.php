<?php

	function getFirstElementByTagName($node, $elementName)
	{
		return $node->getElementsByTagName($elementName)->item(0);
	}
	
	function generirajUpit()
	{
		$listaUpit = array();
		
		if (!empty($_REQUEST['oib']))
		{
			$listaUpit[] = 'contains(@oib, "' . $_REQUEST['oib'] . '")';
		}
		if (!empty($_REQUEST['ime']))
		{
			$listaUpit[] = 'contains(' . toUpper('ime') . ', "' . strToUpper($_REQUEST['ime']) . '")';
		}
		if (!empty($_REQUEST['prezime']))
		{
			$listaUpit[] = 'contains(' . toUpper('prezime') . ', "' . strToUpper($_REQUEST['prezime']) . '")';
		}
		if (!empty($_REQUEST['kategorija']))
		{
			$kategorijaUpit = array();
			
			foreach ($_REQUEST['kategorija'] as $kategorija)
			{
				$kategorijaUpit[] = '@kategorija="' . $kategorija . '"';
			}
			
			if (!empty($kategorijaUpit))
			{
				$listaUpit[] = '(' . implode(' or ', $kategorijaUpit) . ')';
			}
		}
		
		$telefonUpit = array();
		if (!empty($_REQUEST['tiptelefon']))
		{
			$telefonUpit[] = '@tip="' . $_REQUEST['tiptelefon'] . '"';
		}
		if (!empty($_REQUEST['broj']))
		{
			$telefonUpit[] = 'contains(broj, "' . $_REQUEST['broj'] . '")';
		}
		if (!empty($_REQUEST['pozivni']))
		{
			$pozivniUpit = array();
			
			foreach ($_REQUEST['pozivni'] as $pozivni)
			{
				$pozivniUpit[] = '@pozivni_broj="' . $pozivni . '"';
			}
			
			if (!empty($pozivniUpit))
			{
				$telefonUpit[] = 'broj[' . implode(' or ', $pozivniUpit) . ']';
			}
		}
		if (!empty($telefonUpit))
		{
			$listaUpit[] = 'telefon[' . implode(' and ', $telefonUpit) . ']';
		}
		
		$adresaUpit = array();
		if (!empty($_REQUEST['ulica']))
		{
			$adresaUpit[] = 'contains(' . toUpper('ulica') . ', "' . strToUpper($_REQUEST['ulica']) . '")';
		}
		if (!empty($_REQUEST['kucni_broj']))
		{
			$adresaUpit[] = 'contains(kucni_broj, "' . $_REQUEST['kucni_broj'] . '")';
		}
		if (!empty($_REQUEST['mjesto']))
		{
			$adresaUpit[] = 'contains(' . toUpper('mjesto') . ', "' . strToUpper($_REQUEST['mjesto']) . '")';
		}
		if (!empty($_REQUEST['postanski_broj']))
		{
			$adresaUpit[] = 'mjesto[contains(@postanski_broj, "' . $_REQUEST['postanski_broj'] . '")]';
		}
		if (!empty($_REQUEST['drzava']))
		{
			$adresaUpit[] = 'contains(' . toUpper('drzava') . ', "' . strToUpper($_REQUEST['drzava']) . '")';
		}
		if (!empty($adresaUpit))
		{
			$listaUpit[] = 'adresa[' . implode(' and ', $adresaUpit) . ']';
		}
		
		$zanimanjeUpit = array();
		if (!empty($_REQUEST['vrsta_djelatnosti']))
		{
			if ($_REQUEST['vrsta_djelatnosti'] != 'none')
			{
				$zanimanjeUpit[] = '@vrsta_djelatnosti="' . $_REQUEST['vrsta_djelatnosti'] . '"';
			}
		}
		if (!empty($_REQUEST['kljucne_rijeci']))
		{
			$zanimanjeUpit[] = 'contains(' . toUpper('kljucne_rijeci') . ', "' . strToUpper($_REQUEST['kljucne_rijeci']) . '")';
		}
		if (!empty($_REQUEST['naziv_tvrtke']))
		{
			$zanimanjeUpit[] = 'contains(' . toUpper('naziv_tvrtke') . ', "' . strToUpper($_REQUEST['naziv_tvrtke']) . '")';
		}
		if (!empty($zanimanjeUpit))
		{
			$listaUpit[] = 'zanimanje[' . implode(' and ', $zanimanjeUpit) . ']';
		}
		
		if (!empty($_REQUEST['mail_adresa']))
		{
			$listaUpit[] = 'contains(mail_adresa, "' . $_REQUEST['mail_adresa'] . '")';
		}
		if (!empty($_REQUEST['datum_rodjenja']))
		{
			$listaUpit[] = 'datum_rodjenja="' . $_REQUEST['datum_rodjenja'] . '"';
		}

		$strUpit = implode(' and ', $listaUpit);
		
		if (empty($strUpit))
		{
			return '/telefonski_imenik/osoba';
		}
		else
		{
			return '/telefonski_imenik/osoba[' . $strUpit . ']';
		}
	}
	
	function toUpper($string)
	{
		return	"translate(" . $string . ", 'abcdefghijklmnopqrstuvwxyz', 'ABCDEFGHIJKLMNOPQRSTUVWXYZ')";
	}
	
?>
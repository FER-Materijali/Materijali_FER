<?php

	include ('funkcije.php');
  
	error_reporting (E_ALL);

	$dom = new DOMDocument();
	
	#6. lab
	#$a = file_get_contents("http://localhost:8081/Servlet/servlet");
	#$dom->loadXML($a);
	$dom->load('podaci.xml');

	$xp = new DOMXPath($dom);

	$upit = generirajUpit();
	$rezultat = $xp->query($upit);
	
	function printTooltipText($osoba)
	{
		?>
		<b>Kategorija: </b> <?= $osoba->getAttribute('kategorija') ?>
		<br />
		<b>OIB: </b> <?= $osoba->getAttribute('oib') ?>
		<br />
		<b>Email: </b> <?= getFirstElementByTagName($osoba, 'mail_adresa')->nodeValue ?>
		<?php
	}
?>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
		<link rel="stylesheet" type="text/css" href="dizajn.css" />
		<title>Telefonski imenik</title>
		
		<link type="text/css" href="css/flick/jquery-ui-1.8.18.custom.css" rel="Stylesheet">
		<link rel="shortcut icon" href="images/phone_icon_tab.png" />
		<script type="text/javascript" src="js/jquery-1.7.1.min.js"></script>
		<script type="text/javascript" src="js/jquery-ui-1.8.18.custom.min.js"></script>
		<script type="text/javascript" src="js/jquery.ui.position.min.js"></script>
		<script type="text/javascript" src="js/jquery.ui.tooltip.min.js"></script>
		<script type="text/javascript" src="js/detalji.js"></script>
	</head>

	<body>
		
		<div id="wrapper">
			<div id="main">
				<div id="header">
					<h1>
						<a href="index.html" id="title">
							<img src="images/phone_icon.png" alt="phone" />
							Telefonski Imenik
						</a>
					</h1>
				</div>

				<div id="menu">
					<ul>
						<li><a href="index.html">Početna</a></li>
						<li class="active"><a href="obrazac.html">Pretraga</a></li>
						<li><a href="podaci.xml">Pregled</a></li>
						<li><a href="http://www.rasip.fer.hr/">Rasip</a></li>
						<li><a href="http://www.fer.hr/" target="_blank">Fer</a></li>
						<li><a href="mailto:matej.miklecic@fer.hr">Kontakt</a></li>
					</ul>
				</div>
				
				<div id="detailInfo"> </div>
				
				<div id="content">
				
					<h2>
						Rezultati Pretrage
					</h2>
					
					<br>
					<br>
				
					<div id="pretraga">
			
						<table class="fancy" summary="Pretraga telefonskog imenika">
							<thead>
								<tr>
									<th style="width:23%;">Ime <span style="font-size: 14px !important;">&</span> Prezime</th>
									<th style="width:23%;">Broj Telefona</th>
									<th>Adresa</th>
									<th style="width:14%;">Akcija</th>
								</tr>
							</thead>
							
							<tbody>
							
								<?php
								foreach ($rezultat as $osoba)
								{
								?>
							
								<tr title="<?php echo printTooltipText($osoba); ?>" onclick="showMoreInfo('<?php echo $osoba->getAttribute('oib'); ?>'); return false;">
									<td>
										<?php echo getFirstElementByTagName($osoba, 'ime')->nodeValue; ?>
										<?php echo getFirstElementByTagName($osoba, 'prezime')->nodeValue; ?>
									</td>
									<td>
										<?php
										foreach ($osoba->getElementsByTagName('telefon') as $telefon)
										{
											echo '(' . getFirstElementByTagName($telefon, 'broj')->getAttribute('pozivni_broj') . ') ';
											echo getFirstElementByTagName($telefon, 'broj')->nodeValue;
											echo '<br>';
										}
										?>
									</td>
									<td>
										<?php
										$adresa = getFirstElementByTagName($osoba, 'adresa');
										if (!empty($adresa))
										{
											echo getFirstElementByTagName($adresa, 'ulica')->nodeValue . ' ';
											echo getFirstElementByTagName($adresa, 'kucni_broj')->nodeValue . ', ';
											echo getFirstElementByTagName($adresa, 'mjesto')->getAttribute('postanski_broj') . ' ';
											echo getFirstElementByTagName($adresa, 'mjesto')->nodeValue;
										}
										?>
									</td>
									<td align="center">
										<a href="#" onclick="showMoreInfo('<?php echo $osoba->getAttribute('oib'); ?>'); return false;">
											<div class="ui-icon ui-icon-info"> </div>
										</a>
									</td>
								</tr>
								
								<?php } ?>
								
							</tbody>
							
							<tfoot>
								<tr>
									<td></td>
									<td></td>
									<td></td>
									<td></td>
								</tr>
							</tfoot>
						</table>
					</div>
				</div>
			</div>
		</div>
		
		<div id="footer">
			<a href="http://creativecommons.org/licenses/by-nc-nd/3.0/hr/legalcode" target="_blank">
				© 2012 Matej Miklečić
			</a>
		</div>

	</body>
</html>
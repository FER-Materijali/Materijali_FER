<?php
	error_reporting (E_ALL);
	include_once ('funkcije.php');
	
	$dom = new DOMDocument();
  	$dom->load('podaci.xml');

  	$xp = new DOMXPath($dom);

  	$upit = upit();
	//print_r($upit);
  	$queryResult = $xp->query($upit);
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<html>

<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
		<title>Pretraživanje klubova</title>
		
		<link rel="stylesheet" type="text/css" href="dizajn.css">
		<!--<script type="text/javascript" src="detalji.js"></script>
		<link rel="stylesheet" href="http://cdnjs.cloudflare.com/ajax/libs/leaflet/0.7.3/leaflet.css" />
		<script src="http://cdnjs.cloudflare.com/ajax/libs/leaflet/0.7.3/leaflet.js"></script>-->
	</head>
	<body>
		<div class="zaglavlje">
			<div class="logo">
				<a href="index.html"><img src="znak1.jpg" alt="logo"  ></a>
			</div>
			<div class="naslov">
				<h1 class="naslov">Službena stranica Eurolige</h1>
			</div>		
		</div>
	<div>	
	<div class="izbor" >
	<ul  id="izbornik" style="list-style-type:none">
	<li class="izbor"><a class="link" href="index.html">Naslovna</a></li> 		
	<li class="izbor"><a class="link" href="obrazac.html">Pretraživanje klubova</a></li> 	
	<li class="izbor"><a class="link" href="podaci.xml">Podatci</a></li> 
	<li class="izbor"><a class="link"  href="http://www.fer.hr">fer.hr</a></li> 				
	<li class="izbor"><a class="link" href="http://www.fer.unizg.hr/predmet/or" 
		onclick="window.open(this.href, '_blank');return false;" >OR</a></li> 
	<li class="izbor"><a class="link" href="mailter.hr">email me</a></li>
	</ul>

	<div id="detalji"> </div>
	</div>
	
	</div>
	<div class="prvi"  > 
		<h3> Pretraživanje klubova ABA lige!</h3>
		
		<table>
		<tr>	
				<th>Ime kluba</th>
				<th>Država</th>
				<th>Grad</th>
				<th>Predsjednik</th>
				<th>Kapacitet dvorane</th>
				<th>Navijaci</th>
				<th>Kontakt tel</th>
		</tr>
		<?php
				foreach ($queryResult as $elem) {
		?>	
		<tr onmouseover="promijeniBoju(this)" onmouseout="this.style.backgroundColor=''">

		<td> <?php echo $elem->getElementsByTagName('ime')->item(0)->nodeValue; ?> </td>
		<td> <?php echo $elem->getAttribute('drzava'); ?> </td>
		<td> <?php echo $elem->getElementsByTagName('grad')->item(0)->nodeValue; ?> </td>
		<td> <?php echo $elem->getElementsByTagName('imepred')->item(0)->nodeValue; ?> 
			 <?php echo $elem->getElementsByTagName('prezimepred')->item(0)->nodeValue; ?></td>
		<td> <?php echo $elem->getElementsByTagName('kapacitet')->item(0)->nodeValue; ?> </td>	 
		<td> <?php echo $elem->getElementsByTagName('navijaci')->item(0)->nodeValue; ?> </td>
 	
 <td> <?php 
$link = $elem->getElementsByTagName('tel');
 for ($i = 0; $i <$link->length; $i++) {
 echo $elem->getElementsByTagName('tel')->item($i)->nodeValue;
 echo '<br/>';} ?> </td>
		</tr>
        		<?php
				}
			?>	
		</table>
		</div>
		<div class="footer">
		<p class="foot">autor: Karonja</p>
		</div>
	</body>
</html>

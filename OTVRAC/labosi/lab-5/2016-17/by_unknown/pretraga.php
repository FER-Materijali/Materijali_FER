<?php
header('Access-Control-Allow-Origin: *');
	//error_reporting (E_ALL);
	include_once ('funkcije.php');
	$dom = new DOMDocument();
  	$dom->load('podaci.xml');
  	$xp = new DOMXPath($dom);
    //var_dump($xp);
  	$upit = upit();
	//print_r($upit);
  	$queryResult = $xp->query($upit);
	
	$uri = 'http://api.football-data.org/v1/soccerseasons/424/leagueTable';
    $reqPrefs['http']['method'] = 'GET';
    $reqPrefs['http']['header'] = 'X-Auth-Token: f441a185b1044264b8701172cb1113bc';
    $stream_context = stream_context_create($reqPrefs);
    $response = file_get_contents($uri, false, $stream_context);
    $fixtures = json_decode($response, true);
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<html>

<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
		<title>Pretraživanje klubova</title>
		
		<link rel="stylesheet" type="text/css" href="dizajn.css">
		 <link rel="stylesheet" href="https://unpkg.com/leaflet@1.0.3/dist/leaflet.css" />
    <script src="https://unpkg.com/leaflet@1.0.3/dist/leaflet.js"></script>
		
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
	<li class="izbor"><a class="link" href="mailto:r.hr">email me</a></li>
	</ul>
	
	<div id="api"> 	<?php
		echo "Ako ste više nogometni fan:</br>";
	echo "Grupa D:</br>";
		foreach($fixtures['standings']['D'] as $item) {
    echo  $item['team']  . " " . 	$item['points'] . " iz  " .$item['goals'] . " golova." . '<br />';
} 
?>
	<br/>
</div>
	<div id="detalji"> </div>
	<br/>
	<br/>	
	<br/>
	<br/>
	</div>
	
	</div>
	
<div class="prvi"  > 
		<h3> Pretraživanje klubova ABA lige!</h3>
		
		<table>
		<tr>	
				<th>Slika</th>
				<th>Ime kluba</th>
				<th>Država</th>
				<th>Grad</th>
				<th>Predsjednik</th>
				
				<th>Kontakt tel</th>
				<th>Geo lokacija</th>
				<th>Akcija</th>
		</tr>
		<?php
				foreach ($queryResult as $elem) {
					
				$lokacija = fb_adresa($elem->getElementsByTagName('fid')->item(0)->nodeValue);
				#Ako ne postoji lokacija na Facebooku, onda dohvaća lokaciju iz XML i to koristi za generiranje koordinata na osm-u
				if (empty($lokacija))
				$lokacija = $elem->getElementsByTagName('grad')->item(0)->nodeValue;
			
				$geo_koord = geo_koord ($lokacija);
				$dobij_xml = file_get_contents($geo_koord);
				$xml = simplexml_load_string($dobij_xml);	
				$geo_duljina = $xml->place[0]['lon'];
				$geo_širina = $xml->place[0]['lat'];
				$ime = $elem->getElementsByTagName('ime')->item(0)->nodeValue;
				$website = fb_web($elem->getElementsByTagName('fid')->item(0)->nodeValue);
		?>	
		<tr onmouseover="promijeniBoju(this)" onmouseout="this.style.backgroundColor=''">
		
		
		<td><img src="<?php echo fb_slika($elem->getElementsByTagName('fid')->item(0)->nodeValue);?>" /></td>
		<td> <?php echo $elem->getElementsByTagName('ime')->item(0)->nodeValue; ?> </td>
		<td> <?php echo $elem->getAttribute('drzava'); ?> </td>
		<td> <?php echo fb_adresa($elem->getElementsByTagName('fid')->item(0)->nodeValue) ?> </td>
		<td> <?php echo $elem->getElementsByTagName('imepred')->item(0)->nodeValue; ?> 
			 <?php echo $elem->getElementsByTagName('prezimepred')->item(0)->nodeValue; ?></td>
 	
 <td> <?php 
 
$link = $elem->getElementsByTagName('tel');
 for ($i = 0; $i <$link->length; $i++) {
 echo $elem->getElementsByTagName('tel')->item($i)->nodeValue;
 echo '<br/>';} ?> </td>

		<td>Duljina: <?php echo $geo_duljina ?><br/>Širina: <?php echo $geo_širina  ?> </td>
		<td>
		<?php $url = "http://127.0.0.1:801/detalji.php?id="."".$elem->getAttribute("id")."&show=simple";  

				?>
					<a href="#" onclick="prikaziDetalje('<?php echo $url  ?>'); mapMe('<?php echo $geo_širina ?>', '<?php echo $geo_duljina ?>', '<?php echo $ime ?>', '<?php echo $website ?>');">Detalji</a>
	
							<br />
						</td>	
		</tr>
        		<?php 
				}
			?>	
		</table>

 <div id="mapid"></div>
 <style>#mapid { height: 320px;}
</style>
		<script> var mymap = L.map('mapid').setView([51.505, -0.09], 13);
		L.tileLayer('http://{s}.tile.thunderforest.com/cycle/{z}/{x}/{y}.png', {
	attribution: '&copy; <a href="http://www.opencyclemap.org">OpenCycleMap</a>, &copy; <a href="http://www.openstreetmap.org/copyright">OpenStreetMap</a>'
	}).addTo(mymap);
	</script>
	<script src="detalji.js"></script>
		</div>
		<div class="footer">
		<p class="foot">autor: Karonja</p>
		</div>
	</body>
</html>
<?php
  
  
  include ('funkcije.php'); 
  
  $dom = new DOMDocument();
  
  $dom->load('podaci.xml'); 

  $xp = new DOMXPath($dom); 

  $upit = generiraj(); 
  echo $upit;
  $rez = $xp->query($upit);
?>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
 
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="hr">
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=urf-8">	
		<meta name="description" content="Popis poslovnica marke Citroën">
		<meta name="keywords" content="Citroën, poslovnice, HTML, CSS, vježba, OR, FER">
		<meta name="author" content="0036467500">
	    <link rel="stylesheet" type="text/css" href="dizajn.css">
		<title>Popis poslovnica</title>
		<script type="text/javascript" src="detalji.js"></script>
		<link rel="stylesheet" href="http://cdnjs.cloudflare.com/ajax/libs/leaflet/0.7.3/leaflet.css" />
		<script src="http://cdnjs.cloudflare.com/ajax/libs/leaflet/0.7.3/leaflet.js"></script>
		 
	</head>
	
		<body>
	
		<div id="header">
			<a id="hlink"href="index.html">
			<img src="slika1.jpg" alt="Logo Citroëna" width="80" height="80"></a><h1 id="hnaslov">Popis poslovnica marke Citroën</h1>
		</div>
		
		<div id="container">
			<div id="navigation">
			<ul id="lista">
				<li><a class="link" href="index.html">Home</a></li>
				<li><a class="link" href="podaci.xml">XML Podaci</a></li>
				<li><a class="link" href="obrazac.html">Pretraživanje</a></li>
				<li><a class="link" href="http://www.fer.unizg.hr/predmet/or">FER Otvoreno Računarstvo</a></li>
				<li><a class="link" href="http://www.fer.hr/" target="_blank">FER Početna stranica</a></li>
				<li><a class="link" href="mailto:">Pošalji e-mail</a>
				
			</ul>
			</div>
			
			<div id="body">
				<h2> Rezultati </h2>
				<table class="rezultati">
					<thead>
					<tr>
						<th>Ime poslovnice + link</th>
						<th>Radno vrijeme</th>
						<th>Popis modela</th>
						<th>OSM poslovnica</th>				
						<th>Slika FB</th>
						<th>AKCIJA</th>
					</tr>
					</thead>
				<tbody>
				<?php
					foreach ($rez as $ele){
				?>
					<tr onmouseover="PromijeniBoju(this)" onmouseout="VratiBoju(this)">
						<td>
								<a href="<?php
											echo get_link(getElementValue($ele, 'fid')->nodeValue); 
											$adresa2 = (get_link(getElementValue($ele, 'fid')->nodeValue));
											?>"> 
											<?php 
												echo getElementValue($ele, 'ime')->nodeValue; 
												$imeposlovnice = getElementValue($ele, 'ime')->nodeValue; 
												?>
								</a>
						</td>
						<td>
							<?php
								foreach($ele->getElementsByTagName('rvrijeme') as $radnovrijeme){
									echo getElementValue($radnovrijeme, 'radnop')->nodeValue;
									echo "-";
									echo getElementValue($radnovrijeme, 'radnok')->nodeValue;
									echo "<br />";
								}
							?>
						</td>
						<td>
							<?php
							#$modeli = getElementValue($ele, 'modeli');
							foreach($ele->getElementsByTagName('modeli') as $modeli) {
								echo getElementValue($modeli, 'vrsta')->nodeValue;
								echo " - ";
								echo getElementValue($modeli, 'godina')->nodeValue;
								echo "<br />";
								foreach($modeli->getElementsByTagName('usluga') as $popisusluga) {										
									echo $popisusluga->nodeValue;
									echo "<br />";
								
							}
							}							
																
							?>
						</td>
						<td>
							<?php
								$adresa = get_adress(getElementValue($ele, 'fid')->nodeValue);
								$lokacija = generiraj_osm($adresa);
								$sadrzaj = file_get_contents($lokacija);
								#echo $lokacija;
								#echo $sadrzaj;
								$xml = simplexml_load_string($sadrzaj);
								if (!isset($xml->place[0])) {
									#$rastavljeno = explode (" ", $adresa);
									#echo $rastavljeno[5];
									$grad = get_adress2(getElementValue($ele, 'fid')->nodeValue);
									$lokacija2 = generiraj_osm($grad);
									$zaxml = file_get_contents($lokacija2);
									$xml = simplexml_load_string($zaxml);
								}
								echo "LAT: " . $xml->place[0]['lat'].", LOT: ".$xml->place[0]['lon'];
							?>
						</td>
						<td>
							<img src="<?php echo get_picture(getElementValue($ele, 'fid')->nodeValue);?>" />
						</td>
						<td>
							<?php 
							$url = "detalji.php?kod="."".$ele->getAttribute("kod");  	
							$kod = $ele->getAttribute("kod");
							
						?>
							<img src="strelica.png" width="30" height="30" onclick="loadXMLDoc('<?php echo $kod; ?>', '<?php echo $url; ?>'); Karta('<?php echo $xml->place[0]['lat']; ?>', '<?php echo $xml->place[0]['lon']; ?>', '<?php echo $adresa2; ?>','<?php echo $imeposlovnice; ?>')" />
							<br />
						
						</td>
					</tr>
					<?php } ?>
				</tbody>
				</table>
				</div>
			</div>
			
			<h2 style="position: absolute; color: red;  top: 570px; left: 62px;">Dodatni detalji</h2>
			
			<div id="detalji" >	
				
			</div>
			<div id="map"></div>
			
			<div id="footer">
			
				Autor: sipe 2015
			
			</div>
	
		</body>
</html>	
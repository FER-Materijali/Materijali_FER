
function PromijeniBoju(mojred) { 
	mojred.style.backgroundColor = "#E5F9F8"; 
}

function VratiBoju(mojred) { 
	mojred.style.backgroundColor = "#8D8D8D"; 
}


var zahtjev // globalna varijabla
var map // mapa globalna

function odradi() {
	if(zahtjev.readyState == 4) {
		if(zahtjev.status == 200){ // sve ok
		document.getElementById('detalji').innerHTML = zahtjev.responseText;
		
	}
	else { // nije ok
		alert("Nije 200 OK, greška:\n" + zahtjev.statusText);
		}
	}		
	
}

function loadXMLDoc(kod, url) {
	
	document.getElementById('detalji').innerHTML = '<img src="ucitavam.gif" alt="Pričekajte!" />';
	
	if (window.XMLHttpRequest) { // FF, Safari, Opera, IE7+ 
		zahtjev = new XMLHttpRequest(); // stvaranje novog objekta 
	} 
	else if (window.ActiveXObject) { // IE 6+ 
		zahtjev = new ActiveXObject("Microsoft.XMLHTTP"); //ActiveX 
	} 
	if (zahtjev) { // uspješno stvoren objekt 
		zahtjev.onreadystatechange = odradi; 
		zahtjev.open("GET", url, true); // metoda, URL, asinkroni način 
		zahtjev.send(null); //slanje (null za GET, podaci za POST) 
		
	}
}

function Karta(lat, lon,adr, ime) {
	
	document.getElementById('map').innerHTML = '<img src="ucitavam.gif" alt="Pričekajte!" />';
	
	
	document.getElementById('map').innerHTML = "<div id='map2'></div>";
	
	var map = L.map('map2').setView([lat, lon], 13);
	L.tileLayer('http://{s}.tile.thunderforest.com/cycle/{z}/{x}/{y}.png', {
	attribution: '&copy; <a href="http://www.opencyclemap.org">OpenCycleMap</a>, &copy; <a href="http://www.openstreetmap.org/copyright">OpenStreetMap</a>'
	}).addTo(map);
	
	var marker = L.marker([lat, lon]).addTo(map)
    marker.bindPopup('Ime poslovnice: '+ime + '<br/>Širina: '+lat+'<br/>Dužina: '+lon+'<br/>WEB: '+adr).openPopup();
}


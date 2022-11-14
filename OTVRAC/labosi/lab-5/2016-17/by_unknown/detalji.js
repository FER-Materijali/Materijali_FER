function promijeniBoju(mojred) { 
	mojred.style.backgroundColor = "#4CAF50"; 
}


var zahtjev; // globalna varijabla
//var map = L.map('map'); 
var marker;
function prikaziDetalje(url) {
	
	var req;
		if (window.XMLHttpRequest) {
			zahtjev = new XMLHttpRequest();

		} else if (window.ActiveXObject) {
			zahtjev = new ActiveXObject("Microsoft.XMLHTTP");
		}
	
	zahtjev.open("GET", url, true);
	zahtjev.send(null);
	
	 document.getElementById("detalji").innerHTML = '<img src="loading.gif" alt="" />';
	
	zahtjev.onreadystatechange = function() {
		if(zahtjev.readyState == 4) {
			if(zahtjev.status == 200) {
				document.getElementById("detalji").innerHTML = zahtjev.responseText;
				
		} else {
			//alert("Nije primljen 200 OK, nego:\n" + zahtjev.statusText);
			
		}
	}

};
 }

function mapMe(lat, lon, ime, web) {
	

	document.getElementById("mapid").style.visibility = 'visible';
	mymap.setView([lat, lon], 5);
	try {
		//moramo u try catchu jer prvi put nema markera i izbaci error
		mymap.removeLayer(marker);
	} catch(err) {
		//no marker removed
	}
	marker = L.marker([lat, lon]).addTo(mymap);
    marker.bindPopup('Klub: '+ime + '<br/>Geo. širina: '+lat+'<br/>Geo. dužina: '+lon+'<br/>Službena stranica: '+web).openPopup();

	
}

 
 
 

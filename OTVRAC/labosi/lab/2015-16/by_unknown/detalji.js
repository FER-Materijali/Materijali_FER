var XMLrequest;
var url;
var map;

function changeRowColor(rowPointer) {
    rowPointer.style.backgroundColor = '#6cb0f9';
    rowPointer.style.color = '#FFFFFF';
}

function returnRowColor(rowPointer, brReda) {
    if (brReda % 2 === 0) {
        rowPointer.style.backgroundColor = 'rgba(6, 74, 149, 0.4)';
        rowPointer.style.color = '#FFFFFF';
    } else {
        rowPointer.style.backgroundColor = '#FFFFFF';
        rowPointer.style.color = 'rgba(6, 74, 149, 0.7)';
    }
}

function showDetails(raceID, lat, lon, name, officialSite,address) {
    showDetailsAboutRace(raceID,lat,lon);
    showMap(lat, lon, name, officialSite,address);
}

function showDetailsAboutRace(raceID,lat,lon) {
    document.getElementById('details').classList.add("addDetails");
    document.getElementById('details').innerHTML = '<h3 class="naslov naslovObrazac">Dodatni detalji</h3>' +
        '<img id="detailsLoader"src="images/loader.svg" alt="Molimo pričekajte!" />';

    if (window.XMLHttpRequest) { // FF, Safari, Opera, IE7+
        XMLrequest = new XMLHttpRequest(); // stvaranje novog objekta
    } else if (window.ActiveXObject) { // IE 6+
        XMLrequest = new ActiveXObject("Microsoft.XMLHTTP"); //ActiveX
    }
    if (XMLrequest) { // uspješno stvoren objekt
        url = "detalji.php?idutrke=" + raceID+"&lat="+lat+"&lon="+lon;
        XMLrequest.onreadystatechange = processQuery;
        XMLrequest.open("GET", url, true); // metoda, URL, asinkroni na?in
        XMLrequest.send(null); //slanje (null za GET, podaci za POST)
    }
}

function processQuery() {
    if (XMLrequest.readyState == 4) {
        if (XMLrequest.status == 200) { // sve ok
            document.getElementById('details').innerHTML = XMLrequest.responseText;
        }
        else { // nije ok
            alert("Nije 200 OK, greška:\n" + XMLrequest.statusText);
        }
    }
}

function showMap(lat, lon, name, officialSite,address) {
    document.getElementById('mapid').style.display = "block";
    document.getElementById('mapid').style.innerHTML = '<img id="detailsLoader"src="images/page-loader.gif" alt="Molimo pričekajte!" />';
    document.getElementById('mapid').innerHTML = '<div id="insideMapa"></div>';

    map = L.map('insideMapa').setView([lat, lon], 15);

    L.tileLayer('https://api.mapbox.com/styles/v1/mapbox/satellite-streets-v9/tiles/{z}/{x}/{y}?access_token=pk.eyJ1IjoianVyZTk5IiwiYSI6ImNpb3Myeng5ZDAwMWF3OWx3bDUwcjN3MzQifQ.IOAMHRsPZHdOs9YxYskekQ', {
        maxZoom: 16,
        attribution: 'Map data &copy; <a href="http://openstreetmap.org">OpenStreetMap</a> contributors, ' +
        '<a href="http://creativecommons.org/licenses/by-sa/2.0/">CC-BY-SA</a>, ' +
        'Imagery © <a href="http://www.mapbox.com">Mapbox</a>'
    }).addTo(map);

    var marker = L.marker([lat, lon]).addTo(map);
    marker.bindPopup("<h1><b>" + name + "</b></h1><b>Širina : </b>" + lat + "<br><b>Dužina : </b>" + lon + "<br><b>Adresa : </b>" + address +'<br><a target="_blank" href="' + officialSite + '">' + officialSite + '</a>').openPopup();
}







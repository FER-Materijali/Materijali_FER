<?php
include('funkcije.php');
$raceID = $_GET["idutrke"];
$lattitude = $_GET["lat"];
$longitude = $_GET["lon"];
$dom = new DOMDocument();
$dom->load('podaci.xml');
$xpath = new DOMXPath($dom);
$query = '/prvenstvo/utrka[@idutrka=' . $raceID . ']';
$rezultat = $xpath->query($query);

$datum=date("Y-m-d");
echo('<h3 class="naslov naslovObrazac">Dodatni detalji o stazi</h3>');

foreach ($rezultat as $elementRezultata) {
    echo('<p>');
    echo('<b>Ime staze :</b> ' . catchValue($elementRezultata, "imestaze"));
    echo('<br/>');
    echo('<b>Grad :</b> ' . catchValue($elementRezultata, "grad"));
    echo('<br/>');
    echo('<b>Država :</b> ' . catchValue($elementRezultata, "drzava"));
    echo('<br/>');
    echo('<b>Broj zavoja :</b> ' . $elementRezultata->getElementsByTagName('detaljistaze')->item(0)->getAttribute('brojzavoja'));
    echo('<br/>');
    echo('<b>Dužina kruga :</b> ' . catchValue($elementRezultata, "duzinakruga") . ' m');
    echo('<br/>');
    echo('</p>');
    $today = date("Y-m-d");
    $datum = catchValue($elementRezultata, "datumutrke");
    echo('<h3 class="naslov">Dodatni detalji o utrci</h3>');
    echo('<p>');
    echo('<b>Datum održavanja :</b> ' . date("d.m.Y", strtotime($datum)));
    if ($today > $datum) {//utrka održana
        echo('<br/>');
        $today = date("Y-m-d");
        $pobjednik = catchValue($elementRezultata, "imepobjednika") . " " . catchValue($elementRezultata, "prezimepobjednika");
        echo('<b>Pobjednik utrke :</b> ' . $pobjednik);
        echo('<br/>');
        echo('<b>Motor pobjednika :</b> ' . $elementRezultata->getElementsByTagName('pobjednik')->item(0)->getAttribute('motorpobjednika'));
        echo('<br/>');
        $odustali=$elementRezultata->getElementsByTagName('odustajanje')->length;
        $ended = 22 - $odustali;
        echo('<b>Utrku završilo :</b> ' . $ended . ' vozača');
        echo('<br/>');
        $vrijeme = catchValue($elementRezultata, "vrijeme");
        echo('<b>Vrijeme :</b> ' . $vrijeme . '&#176;&#160;C');
    } else {
        echo('<br/>');
        echo('<br/>');
        echo("Utrka još nije održana, posjetite nas kasnije za više detalja!");
    }
    echo('</p>');
}

if (is_numeric($lattitude)) {
    $lattitude = number_format($lattitude, 3);
    $longitude = number_format($longitude, 3);
    $today = date("Y-m-d");
    if ($today > $datum) {
        echo('<h3 class="naslov">Vremenska prognoza na dan utrke</h3>');
       $weatherJSON = file_get_contents("http://api.worldweatheronline.com/premium/v1/past-weather.ashx?key=8c10f6c7e83f44948fd71333162905&q=" . $lattitude . "," . $longitude . "&format=json&date=".$datum."&tp=1");
        $decodedJSON[] = json_decode($weatherJSON, true);
        echo('<p>');
        echo('<span class="enlarge">12:00h - 13:00h </span>');
        echo('<br/>');
        echo('<b>Temperatura:</b> ' . $decodedJSON[0]["data"]["weather"][0]["hourly"][12]["tempC"] . '&#176;&#160;C');
        echo('<br/>');
        echo('<b>Real Feel&#174;:</b> ' . $decodedJSON[0]["data"]["weather"][0]["hourly"][12]["FeelsLikeC"] . '&#176;&#160;C');
        echo('<br/>');
        $urlWeather = $decodedJSON[0]["data"]["weather"][0]["hourly"][12]["weatherIconUrl"][0]["value"];
        echo('<img src="' . $urlWeather . '" alt="weather" class="weatherIcon" />');
        echo('<b>Naoblaka:</b> ' . $decodedJSON[0]["data"]["weather"][0]["hourly"][12]["weatherDesc"][0]["value"]);
        echo('<br/>');
        echo('<b>Tlak zraka:</b> ' . $decodedJSON[0]["data"]["weather"][0]["hourly"][12]["pressure"] . ' hPa');
        echo('<br/>');
        echo('<b>Vjetar:</b> ' . $decodedJSON[0]["data"]["weather"][0]["hourly"][12]["winddir16Point"] . "  " . $decodedJSON[0]["data"]["weather"][0]["hourly"][5]["windspeedKmph"] . ' km/h');
        echo('<br/>');
        echo('<b>Relativna vlažnost:</b> ' . $decodedJSON[0]["data"]["weather"][0]["hourly"][12]["humidity"] . ' %');
        echo('<br/>');

        echo('<span class="enlarge">13:00h - 14:00h </span>');
        echo('<br/>');
        echo('<b>Temperatura:</b> ' . $decodedJSON[0]["data"]["weather"][0]["hourly"][13]["tempC"] . '&#176;&#160;C');
        echo('<br/>');
        echo('<b>Real Feel&#174;:</b> ' . $decodedJSON[0]["data"]["weather"][0]["hourly"][13]["FeelsLikeC"] . '&#176;&#160;C');
        echo('<br/>');
        $urlWeather = $decodedJSON[0]["data"]["weather"][0]["hourly"][13]["weatherIconUrl"][0]["value"];
        echo('<img src="' . $urlWeather . '" alt="weather" class="weatherIcon" />');
        echo('<b>Naoblaka:</b> ' . $decodedJSON[0]["data"]["weather"][0]["hourly"][13]["weatherDesc"][0]["value"]);
        echo('<br/>');
        echo('<b>Tlak zraka:</b> ' . $decodedJSON[0]["data"]["weather"][0]["hourly"][13]["pressure"] . ' hPa');
        echo('<br/>');
        echo('<b>Vjetar:</b> ' . $decodedJSON[0]["data"]["weather"][0]["hourly"][13]["winddir16Point"] . "  " . $decodedJSON[0]["data"]["weather"][0]["hourly"][5]["windspeedKmph"] . ' km/h');
        echo('<br/>');
        echo('<b>Relativna vlažnost:</b> ' . $decodedJSON[0]["data"]["weather"][0]["hourly"][13]["humidity"] . ' %');
        echo('<br/>');

        echo('<span class="enlarge">14:00h - 15:00h </span>');
        echo('<br/>');
        echo('<b>Temperatura:</b> ' . $decodedJSON[0]["data"]["weather"][0]["hourly"][14]["tempC"] . '&#176;&#160;C');
        echo('<br/>');
        echo('<b>Real Feel&#174;:</b> ' . $decodedJSON[0]["data"]["weather"][0]["hourly"][14]["FeelsLikeC"] . '&#176;&#160;C');
        echo('<br/>');
        $urlWeather = $decodedJSON[0]["data"]["weather"][0]["hourly"][14]["weatherIconUrl"][0]["value"];
        echo('<img src="' . $urlWeather . '" alt="weather" class="weatherIcon" />');
        echo('<b>Naoblaka:</b> ' . $decodedJSON[0]["data"]["weather"][0]["hourly"][14]["weatherDesc"][0]["value"]);
        echo('<br/>');
        echo('<b>Tlak zraka:</b> ' . $decodedJSON[0]["data"]["weather"][0]["hourly"][14]["pressure"] . ' hPa');
        echo('<br/>');
        echo('<b>Vjetar:</b> ' . $decodedJSON[0]["data"]["weather"][0]["hourly"][14]["winddir16Point"] . "  " . $decodedJSON[0]["data"]["weather"][0]["hourly"][5]["windspeedKmph"] . ' km/h');
        echo('<br/>');
        echo('<b>Relativna vlažnost:</b> ' . $decodedJSON[0]["data"]["weather"][0]["hourly"][14]["humidity"] . ' %');
        echo('<br/>');
        echo('</p>');

    } else {
        echo('<h3 class="naslov">Trodnevna vremenska prognoza</h3>');
        $weatherJSON = file_get_contents("https://api.worldweatheronline.com/premium/v1/weather.ashx?key=8c10f6c7e83f44948fd71333162905&q=" . $lattitude . "," . $longitude . "&format=JSON&num_of_days=3&tp=24");
        $decodedJSON[] = json_decode($weatherJSON, true);
        echo('<p>');
        echo('<span class="enlarge">Prognoza za danas:</span>');
        echo('<br/>');
        echo('<b>Temperatura min:</b> ' . $decodedJSON[0]["data"]["weather"][0]["mintempC"] . '&#176;&#160;C');
        echo('<br/>');
        echo('<b>Temperatura max:</b> ' . $decodedJSON[0]["data"]["weather"][0]["maxtempC"] . '&#176;&#160;C');
        echo('<br/>');
        echo('<b>Real Feel&#174;:</b> ' . $decodedJSON[0]["data"]["weather"][0]["hourly"][0]["FeelsLikeC"] . '&#176;&#160;C');
        echo('<br/>');
        $urlWeather = $decodedJSON[0]["data"]["weather"][0]["hourly"][0]["weatherIconUrl"][0]["value"];
        echo('<img src="' . $urlWeather . '" alt="weather" class="weatherIcon" />');
        echo('<b>Naoblaka:</b> ' . $decodedJSON[0]["data"]["weather"][0]["hourly"][0]["weatherDesc"][0]["value"]);
        echo('<br/>');
        echo('<b>Tlak zraka:</b> ' . $decodedJSON[0]["data"]["weather"][0]["hourly"][0]["pressure"] . ' hPa');
        echo('<br/>');
        echo('<b>Vjetar:</b> ' . $decodedJSON[0]["data"]["weather"][0]["hourly"][0]["winddir16Point"] . "  " . $decodedJSON[0]["data"]["weather"][0]["hourly"][0]["windspeedKmph"] . ' km/h');
        echo('<br/>');
        echo('<b>Relativna vlažnost:</b> ' . $decodedJSON[0]["data"]["weather"][0]["hourly"][0]["humidity"] . ' %');
        echo('<br/>');
        echo('<b>Mogućnost oborina:</b> ' . $decodedJSON[0]["data"]["weather"][0]["hourly"][0]["chanceofrain"] . ' %');
        echo('<br/>');


        echo('<span class="enlarge">Prognoza za sutra:</span>');
        echo('<br/>');
        echo('<b>Temperatura min:</b> ' . $decodedJSON[0]["data"]["weather"][1]["mintempC"] . '&#176;&#160;C');
        echo('<br/>');
        echo('<b>Temperatura max:</b> ' . $decodedJSON[0]["data"]["weather"][1]["maxtempC"] . '&#176;&#160;C');
        echo('<br/>');
        echo('<b>Real Feel&#174;:</b> ' . $decodedJSON[0]["data"]["weather"][1]["hourly"][0]["FeelsLikeC"] . '&#176;&#160;C');
        echo('<br/>');
        $urlWeather = $decodedJSON[0]["data"]["weather"][1]["hourly"][0]["weatherIconUrl"][0]["value"];
        echo('<img src="' . $urlWeather . '" alt="weather" class="weatherIcon" />');
        echo('<b>Naoblaka:</b> ' . $decodedJSON[0]["data"]["weather"][1]["hourly"][0]["weatherDesc"][0]["value"]);
        echo('<br/>');
        echo('<b>Tlak zraka:</b> ' . $decodedJSON[0]["data"]["weather"][1]["hourly"][0]["pressure"] . ' hPa');
        echo('<br/>');
        echo('<b>Vjetar:</b> ' . $decodedJSON[0]["data"]["weather"][1]["hourly"][0]["winddir16Point"] . "  " . $decodedJSON[0]["data"]["weather"][0]["hourly"][0]["windspeedKmph"] . ' km/h');
        echo('<br/>');
        echo('<b>Relativna vlažnost:</b> ' . $decodedJSON[0]["data"]["weather"][1]["hourly"][0]["humidity"] . ' %');
        echo('<br/>');
        echo('<b>Mogućnost oborina:</b> ' . $decodedJSON[0]["data"]["weather"][1]["hourly"][0]["chanceofrain"] . ' %');
        echo('<br/>');


        echo('<span class="enlarge">Prognoza za preksutra:</span>');
        echo('<br/>');
        echo('<b>Temperatura min:</b> ' . $decodedJSON[0]["data"]["weather"][2]["mintempC"] . '&#176;&#160;C');
        echo('<br/>');
        echo('<b>Temperatura max:</b> ' . $decodedJSON[0]["data"]["weather"][2]["maxtempC"] . '&#176;&#160;C');
        echo('<br/>');
        echo('<b>Real Feel&#174;:</b> ' . $decodedJSON[0]["data"]["weather"][2]["hourly"][0]["FeelsLikeC"] . '&#176;&#160;C');
        echo('<br/>');
        $urlWeather = $decodedJSON[0]["data"]["weather"][2]["hourly"][0]["weatherIconUrl"][0]["value"];
        echo('<img src="' . $urlWeather . '" alt="weather" class="weatherIcon" />');
        echo('<b>Naoblaka:</b> ' . $decodedJSON[0]["data"]["weather"][2]["hourly"][0]["weatherDesc"][0]["value"]);
        echo('<br/>');
        echo('<b>Tlak zraka:</b> ' . $decodedJSON[0]["data"]["weather"][2]["hourly"][0]["pressure"] . ' hPa');
        echo('<br/>');
        echo('<b>Vjetar:</b> ' . $decodedJSON[0]["data"]["weather"][2]["hourly"][0]["winddir16Point"] . "  " . $decodedJSON[0]["data"]["weather"][0]["hourly"][0]["windspeedKmph"] . ' km/h');
        echo('<br/>');
        echo('<b>Relativna vlažnost:</b> ' . $decodedJSON[0]["data"]["weather"][2]["hourly"][0]["humidity"] . ' %');
        echo('<br/>');
        echo('<b>Mogućnost oborina:</b> ' . $decodedJSON[0]["data"]["weather"][2]["hourly"][0]["chanceofrain"] . ' %');
        echo('<br/>');
        echo('</p>');
    }

}


?>
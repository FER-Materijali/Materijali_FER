<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8"/>
    <meta name="description" content="Laboratorijske vježbe iz OR"/>
    <meta name="keywords" content="MotoGP,CSS Vježba,HTML vježba">
    <meta name="author" content="Jure Knezović"/>
    <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
    <link rel="stylesheet" type="text/css" href="dizajn.css"/>
    <link rel="icon" type="image/png" href="images/web-logo.png"/>
    <script type="text/javascript" src="detalji.js"></script>
    <link rel="stylesheet" href="http://cdn.leafletjs.com/leaflet/v0.7.7/leaflet.css"/>
    <script src="http://cdn.leafletjs.com/leaflet/v0.7.7/leaflet.js"></script>
    <title>MotoGP - Pretraga</title>
    <script src="//ajax.googleapis.com/ajax/libs/jquery/1.9.1/jquery.min.js"></script>
    <script type="text/javascript">
        $(document).ready(function () {
            $('a').click(function () {
                $('#loader').show();
                window.scrollBy(0, 1);
                window.scrollBy(0, -1);
            });

        });
    </script>
</head>
<body>
<div id="loader">
</div>
<div class="row">
    <div class="col-12">
        <header>
            <h1>
                <a href="index.html"><img id="logo" src="images/logo.svg" alt="MotoGp"/></a>
                MotoGP Prvenstvo
            </h1>
        </header>
    </div>
</div>
<div class="row">
    <div class="col-3">
        <nav>
            <a href="index.html">Početna</a>
            <a href="podaci.xml">Utrke v1</a>
            <a href="podaci1.xml">Utrke v2</a>
            <a href="obrazac.html">Pretraga v1</a>
            <a href="obrazac1.html" class="active">Pretraga v2</a>
            <a href="http://www.fer.unizg.hr/predmet/or" target="_top">Otvoreno računarstvo</a>
            <a href="http://www.fer.unizg.hr/" target="_blank">FER</a>
            <a href="mailto:jure.knezovic@fer.hr">Kontaktirajte autora</a>
        </nav>
        <div id="details">

        </div>
        <div id="mapid">

        </div>
    </div>
    <div class="col-9 min-height">
        <section>
            <h2 class="naslov naslovObrazac">Rezultati pretraživanja</h2>
            <?php
            error_reporting(E_ALL);
            include('funkcije.php');
            $dom = new DOMDocument();
            $dom->load('podaci1.xml');
            $xpath = new DOMXPath($dom);
            $xpath->registerNamespace("w",
                "http://www.w3schools.com");
            $query = createQuery1();
            $rezultat = $xpath->query($query);
            $i = 0;
            foreach ($rezultat as $nebitno) {
                $i++;
            }
            if ($i == 0) {
                echo('<table id="podatak">');
                echo('<tbody><td class="bold"><br/>Nažalost nismo pronašli zapise koji odgovaraju navedenom upitu!<br/><br/><img src="images/sad_smiley.svg" alt="sad_smiley.svg"/><br/><br/></td></tbody>');
                echo('</table>');
            } else {
                echo('<table id="podatci">');
                echo('<tbody>');
                foreach ($rezultat as $ElementRezultata) {
                    $faceID = catchValue($ElementRezultata, "facebookid");
                    $trackName = catchValue($ElementRezultata, "imestaze");
                    $location = getLocation($faceID);
                    $raceID = $ElementRezultata->getAttribute('idutrka');
                    $coordinates = getCoordinates($trackName, $location);
                    $eventPicture = getEventPicture($faceID);
                    $city = catchValue($ElementRezultata, "grad");
                    $country = catchValue($ElementRezultata, "drzava");
                    if (!empty($location)) {
                        $explodedLocation = explode(" , ", $location);
                        if (count($explodedLocation) == 3) {
                            $street = $explodedLocation[0];
                            $city = $explodedLocation[1];
                            $country = $explodedLocation[2];
                        } else {
                            $city = $explodedLocation[0];
                            $country = $explodedLocation[1];
                        }
                    }else{
                        $location=$city." , ".$country;
                    }

                    echo('<thead><tr colspan="3"><th colspan="3">' . catchValue($ElementRezultata, "imeutrke") . " , " . $trackName . "&nbsp;&nbsp;");
                    echo('<a href="http://www.facebook.com/' . $faceID . '">');
                    echo('<img id="fbslika" src="images/face.svg" alt="fblogo.jpg" />');
                    echo('</a>');
                    echo("&nbsp;&nbsp;");
                    $officialSite = getOfficialSite($faceID);
                    if (!isset($officialSite)) {
                        $officialSite = "http://www.motogp.com";
                    }
                    echo('<a href="' . $officialSite . '">');
                    echo('<img id="motoSlika" src="images/logo_motogpcom.svg" alt="motologo.jpg" />');
                    echo('</a>');
                    echo('<img src="images/detailsWhite.svg" alt="detalji" class="mouseHover detaljPretraga" ');
                    $trueCoordinates = getTrueCoordinates($trackName);
                    echo("onclick='showDetails(" . $raceID . "," . $trueCoordinates[0] . "," . $trueCoordinates[1] . ",\"" . $trackName . "\",\"" . $officialSite . "\",\"" . $location . "\")'/>");
                    echo('</th></tr></thead>');
                    $rowAdd = 0;
                    if (isset($street)) {
                        echo('<tr><td class="podatcinaslov">Ulica</td>');
                        echo('<td class="podatcisredina" >' . $street . '</td>');
                        $rowAdd = 1;
                    } else {
                        echo('<tr><td class="podatcinaslov">Grad</td>');
                        echo('<td class="podatcisredina" >' . $city . '</td>');
                    }
                    if ($ElementRezultata->getElementsByTagName('detaljiutrke')->length != 0) {
                        $rowspan = 11 + $rowAdd;
                        echo('<td class="pozadina" rowspan="' . $rowspan . '">');
                    } else {
                        $rowspan = 6 + $rowAdd;
                        echo('<td class="pozadina" rowspan="' . $rowspan . '">');
                    }
                    $dodatak = ' class="pretragaSlika"';
                    if (!isset($eventPicture)) {
                        $eventPicture = catchValue($ElementRezultata, "slikastaze");
                        $dodatak = ' class="slika"';
                    }
                    echo('<div id="mapOrPicture">');
                    echo('<img ' . $dodatak . 'src="' . $eventPicture . '" alt="' . $trackName . '.jpg"/>');
                    echo('</div>');
                    echo('</td>');
                    echo('</tr>');
                    if (isset($street)) {
                        echo('<tr><td class="podatcinaslov">Grad</td>');
                        echo('<td class="podatcisredina" >' . $city . '</td></tr>');
                    }

                    echo('<tr><td class="podatcinaslov">Država</td>');
                    echo('<td class="podatcisredina" >' . $country . '</td></tr>');

                    echo('<tr><td class="podatcinaslov">Geografske koordinate</td>');
                    echo('<td class="podatcisredina" >');
                    if (is_numeric($coordinates[0])) {
                        echo('Širina: ' . number_format($coordinates[0], 5));
                        echo('<br/>');
                        echo('Dužina: ' . number_format($coordinates[1], 5));
                    } else {
                        echo('Dužina: ' . $coordinates[0] . '<br/> Širina: ' . $coordinates[1]);
                    }
                    echo('</td></tr>');

                    echo('<tr><td class="podatcinaslov">Dužina kruga</td>');
                    echo('<td class="podatcisredina" >' . catchValue($ElementRezultata, "duzinakruga") . ' m</td></tr>');

                    echo('<tr><td class="podatcinaslov">Broj zavoja</td>');
                    echo('<td class="podatcisredina" >' . $ElementRezultata->getElementsByTagName('detaljistaze')->item(0)->getAttribute('brojzavoja') . ' </td></tr>');

                    $datum = catchValue($ElementRezultata, "datumutrke");
                    $datum = date("d.m.Y", strtotime($datum));
                    echo('<tr><td class="podatcinaslov">Datum održavanja</td>');
                    echo('<td class="podatcisredina" >' . $datum . '</td></tr>');
                    if ($ElementRezultata->getElementsByTagName('detaljiutrke')->length != 0) {
                        echo('<tr><td class="podatcinaslov">Pobjednik</td>');
                        $Pobjednik = catchValue($ElementRezultata, "imepobjednika") . " " . catchValue($ElementRezultata, "prezimepobjednika");
                        echo('<td class="podatcisredina" >' . $Pobjednik . '</td></tr>');

                        echo('<tr><td class="podatcinaslov">Motor pobjednika</td>');
                        echo('<td class="podatcisredina" >' . $ElementRezultata->getElementsByTagName('pobjednik')->item(0)->getAttribute('motorpobjednika') . '</td></tr>');

                        echo('<tr><td class="podatcinaslov">Utrku završilo</td>');
                        $ended = 22 - $ElementRezultata->getElementsByTagName('odustajanje')->length;
                        echo('<td class="podatcisredina" >' . $ended . ' vozača</td></tr>');

                        echo('<tr><td class="podatcinaslov">Odustali</td>');
                        echo('<td class="podatcisredina">');
                        foreach ($ElementRezultata->getElementsByTagName('odustajanje') as $odustao) {
                            echo(catchValue($odustao, "imednf") . " " . catchValue($odustao, "prezimednf"));
                            echo('<br/>');
                        }
                        echo('</td></tr>');

                        echo('<tr><td class="podatcinaslov">Vrijeme</td>');
                        echo('<td class="podatcisredina">');
                        foreach ($ElementRezultata->getElementsByTagName('vrijeme') as $vrijeme) {
                            echo('<p class="time">');
                            echo(catchValue($vrijeme, "temperatura") . '&#176;&#160;');
                            $slika = catchValue($vrijeme, "naoblaka");
                            if ($slika == 'Sunčano') {
                                $slika = 'suncano';
                            }
                            if ($slika == 'Kišovito') {
                                $slika = 'kisovito';
                            }
                            if ($slika == 'Oblačno') {
                                $slika = 'Oblacno';
                            }
                            if ($slika == 'Poluoblačno') {
                                $slika = 'Poluoblacno';
                            }

                            echo('</p>');
                            echo('<img align="bottom" class="scale" src="./images/weather/' . $slika . '.svg" alt="' . $slika . '.jpg"/>');
                            echo('</br>');

                        }
                        echo('</td>');
                    }
                    unset($street);
                }
                echo('</tbody>');
                echo('</table>');
            }
            ?>

        </section>
    </div>
</div>
<div class="row">
    <div class="col-12">
        <footer>
            <p>&copy;Jure Knezović - Otvoreno računarstvo 2015/16</p>
        </footer>
    </div>
</div>
</body>
</html>
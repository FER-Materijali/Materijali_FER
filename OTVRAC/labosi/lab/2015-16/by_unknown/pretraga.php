<html lang="hr">
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
            <a href="obrazac.html" class="active">Pretraga v1</a>
            <a href="obrazac1.html">Pretraga v2</a>
            <a href="http://www.fer.unizg.hr/predmet/or" target="_top">Otvoreno računarstvo</a>
            <a href="http://www.fer.unizg.hr/" target="_blank">FER</a>
            <a href="mailto:jure.knezovic@fer.hr">Kontaktirajte autora</a>
        </nav>
        <div id="details">

        </div>
    </div>
    <div class="col-9 min-height">
        <section>
            <h2 class="naslov naslovObrazac">Rezultati pretraživanja</h2>
            <table id="podatak">
                <?php
                error_reporting(E_ALL);
                include('funkcije.php');
                $dom = new DOMDocument();
                $dom->load('podaci.xml');
                $xpath = new DOMXPath($dom);
                $query = createQuery();
                $rezultat = $xpath->query($query);
                $i = 0;
                foreach ($rezultat as $nebitno) {
                    $i++;
                }
                if ($i == 0) {
                    echo('<tbody><td class="bold"><br/>Nažalost nismo pronašli zapise koji odgovaraju navedenom upitu!<br/><br/><img src="images/sad_smiley.svg" alt="sad_smiley.svg"/><br/><br/></td></tbody>');
                } else {
                    $i = 0;
                    echo('<thead><tr><th>Velika Nagrada</th><th>Staza</th><th>Lokacija</th><th>Facebook</th><th>Detalji</th></tr></thead><tbody>');
                    foreach ($rezultat as $ElementRezultata) {
                        $i++;
                        $facebookid = catchValue($ElementRezultata, "facebookid");
                        $trackName = catchValue($ElementRezultata, "imestaze");
                        echo('<tr onmouseover="changeRowColor(this)" onmouseout="returnRowColor(this,' . $i . ')"><td width="18%">');
                        echo(catchValue($ElementRezultata, "imeutrke"));
                        echo('</td><td>');
                        echo($trackName);
                        echo('</td><td width="38%">');
                        $location = getLocation($facebookid);
                        if (empty($location)) {
                            $location = catchValue($ElementRezultata, "grad") . " , " . catchValue($ElementRezultata, "drzava");

                        }
                        echo $location;
                        $prikazi_koordinate = false;
                        /*Ovaj dio je iskljucen,sluzi za ispis kooridnata,staviti true ako treba ispis;
                         * */
                        if ($prikazi_koordinate) {
                            echo('<br/>');
                            $coordinates = getCoordinates($trackName, $location);
                            if (is_numeric($coordinates[0])) {
                                echo('Širina: ' . number_format($coordinates[0], 5) . ' Dužina: ' . number_format($coordinates[1], 5));
                            } else {
                                echo('Širina: ' . $coordinates[0] . ' Dužina: ' . $coordinates[1]);
                            }
                        }
                        echo('</td><td>');
                        $link = 'http://www.facebook.com/' . $facebookid;
                        echo('<a href="' . $link . '" target="_top">');
                        $img_src = getEventPicture(catchValue($ElementRezultata, "facebookid"));
                        $dodatak = 'class="racePicture"';
                        if (!isset($img_src)) {
                            $img_src = './images/fejsach.svg';
                            $dodatak = 'id="fblogo"';
                        }
                        echo('<img ' . $dodatak . ' src="' . $img_src . '" alt="facebook"/>');
                        echo('</a>');
                        echo('</td><td>');
                        $raceID = $ElementRezultata->getAttribute('idutrka');
                        $officialSite = getOfficialSite($facebookid);
                        if (empty($officialSite)) {
                            $officialSite = "http://www.motogp.com";
                        }
                        echo('<img src="images/details.svg" alt="detalji" class="mouseHover detaljiSlika" ');
                        $trueCoordinates = getTrueCoordinates($trackName);
                        echo("onclick='showDetails(" . $raceID . "," . number_format($trueCoordinates[0],5) . "," . number_format($trueCoordinates[1],5) . ",\"" . $trackName . "\",\"" . $officialSite . "\",\"" . $location . "\")'/>");
                        echo('</td></tr>');
                    }
                    echo('</tbody>');
                }
                ?>
            </table>
            <div id="mapid"></div>
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
<?php
function createQuery()
{
    $splitQuery = array();
    if (!empty($_POST['RaceName'])) {
        $splitQuery[] = 'contains(' . toUpperString('imeutrke') . ', "' . mb_strtoupper($_POST['RaceName'], "UTF-8") . '")';
    }
    if (!empty($_POST['RaceWinnerName'])) {
        $splitQuery[] = 'detaljiutrke/pobjednik[contains(' . toUpperString('imepobjednika') . ', "' . mb_strtoupper($_POST['RaceWinnerName'], "UTF-8") . '")]';
    }
    if (!empty($_POST['RaceWinnerLastname'])) {
        $splitQuery[] = 'detaljiutrke/pobjednik[contains(' . toUpperString('prezimepobjednika') . ', "' . mb_strtoupper($_POST['RaceWinnerLastname'], "UTF-8") . '")]';
    }
    if (!empty($_POST['Quantity'])) {
        $quantity = 22 - $_POST['Quantity'];
        $splitQuery[] = 'detaljiutrke[count(odustajanje)=' . $quantity . ']';
    }
    if (!empty($_POST['TrackName'])) {
        $splitQuery[] = 'staza[contains(' . toUpperString('imestaze') . ', "' . mb_strtoupper($_POST['TrackName'], "UTF-8") . '")]';
    }
    if (!empty($_POST['TrackCity'])) {
        $splitQuery[] = 'staza[contains(' . toUpperString('grad') . ', "' . mb_strtoupper($_POST['TrackCity'], "UTF-8") . '")]';
    }
    if (!empty($_POST['TrackCountry'])) {
        $splitQuery[] = 'staza[contains(' . toUpperString('drzava') . ', "' . mb_strtoupper($_POST['TrackCountry'], "UTF-8") . '")]';
    }
    if (!empty($_POST['CornerNum'])) {
        $splitQuery[] = 'staza/detaljistaze[contains(@brojzavoja,' . $_POST['CornerNum'] . ')]';
    }
    if (!empty($_POST['Weather'])) {
        $splitQuery[] = 'detaljiutrke/vrijeme[contains(naoblaka,"' . $_POST['Weather'] . '")]';
    }
    if (!empty($_POST['Temperature'])) {
        $splitQuery[] = 'detaljiutrke/vrijeme[temperatura=' . $_POST['Temperature'] . ']';
    }
    if (!empty($_POST['RaceDate'])) {
        $splitQuery[] = 'contains(datumutrke,"' . $_POST['RaceDate'] . '")';
    }


    if (!empty($_POST['RaceWinnerBike'])) {
        $splitQueryBike = array();
        foreach ($_POST['RaceWinnerBike'] as $motor) {
            $splitQueryBike[] = 'contains(@motorpobjednika,"' . $motor . '")';
        }
        $splitQuery[] = 'detaljiutrke/pobjednik[' . implode(' or ', $splitQueryBike) . ']';
    }


    $returnQuery = implode(' and ', $splitQuery);
    if (!empty($returnQuery)) {
        return '/prvenstvo/utrka[' . $returnQuery . ']';
    } else {
        return '/prvenstvo/utrka';
    }
}

function createQuery1()
{
    $splitQuery = array();
    if (!empty($_POST['RaceName'])) {
        $splitQuery[] = 'contains(' . toUpperString('w:imeutrke') . ', "' . mb_strtoupper($_POST['RaceName'], "UTF-8") . '")';
    }
    if (!empty($_POST['RaceWinnerName'])) {
        $splitQuery[] = 'w:detaljiutrke/w:pobjednik[contains(' . toUpperString('w:imepobjednika') . ', "' . mb_strtoupper($_POST['RaceWinnerName'], "UTF-8") . '")]';
    }
    if (!empty($_POST['RaceWinnerLastname'])) {
        $splitQuery[] = 'w:detaljiutrke/w:pobjednik[contains(' . toUpperString('w:prezimepobjednika') . ', "' . mb_strtoupper($_POST['RaceWinnerLastname'], "UTF-8") . '")]';
    }
    if (!empty($_POST['Quantity'])) {
        $quantity = 22 - $_POST['Quantity'];
        $splitQuery[] = 'w:detaljiutrke[count(w:odustajanje)=' . $quantity . ']';
    }
    if (!empty($_POST['TrackName'])) {
        $splitQuery[] = 'w:staza[contains(' . toUpperString('w:imestaze') . ', "' . mb_strtoupper($_POST['TrackName'], "UTF-8") . '")]';
    }
    if (!empty($_POST['TrackCity'])) {
        $splitQuery[] = 'w:staza[contains(' . toUpperString('w:grad') . ', "' . mb_strtoupper($_POST['TrackCity'], "UTF-8") . '")]';
    }
    if (!empty($_POST['TrackCountry'])) {
        $splitQuery[] = 'w:staza[contains(' . toUpperString('w:drzava') . ', "' . mb_strtoupper($_POST['TrackCountry'], "UTF-8") . '")]';
    }
    if (!empty($_POST['Weather'])) {
        $splitQuery[] = 'w:detaljiutrke/w:vrijeme[contains(w:naoblaka,"' . $_POST['Weather'] . '")]';
    }
    if (!empty($_POST['Temperature'])) {
        $splitQuery[] = 'w:detaljiutrke/w:vrijeme[w:temperatura=' . $_POST['Temperature'] . ']';
    }
    if (!empty($_POST['Bike'])) {
        $splitQueryBike = array();
        foreach ($_POST['Bike'] as $motor) {
            $splitQueryBike[] = 'contains(@motorpobjednika,"' . $motor . '")';
        }
        $splitQuery[] = 'w:detaljiutrke/w:pobjednik[' . implode(' or ', $splitQueryBike) . ']';
    }


    if (!empty($_POST['CornerNum'])) {
        $splitQueryCorner = array();
        foreach ($_POST['CornerNum'] as $brojZavoja) {
            $splitQueryCorner[] = '@brojzavoja=' . $brojZavoja . '';
        }
        $splitQuery[] = 'w:staza/w:detaljistaze[' . implode(' or ', $splitQueryCorner) . ']';
    }

    $returnQuery = implode(' and ', $splitQuery);
    if (!empty($returnQuery)) {
        return '/w:prvenstvo/w:utrka[' . $returnQuery . ']';
    } else {
        return '/w:prvenstvo/w:utrka';
    }

}

function toUpperString($string)
{
    return "translate(" . $string . ", 'abcdefghijklmnopqrstuvwxyzšđčćž', 'ABCDEFGHIJKLMNOPQRSTUVWXYZŠĐČĆŽ')";
}

function catchValue($node, $elementName)
{
    return $node->getElementsByTagName($elementName)->item(0)->nodeValue;
}

function getEventPicture($fbid)
{
    $fbJSON = file_get_contents("https://graph.facebook.com/v2.6/" . $fbid . "?fields=cover&amp;&access_token=1768882033345666|5465c1f6181700169eafddb0751c64aa");
    $decodedJSON[] = json_decode($fbJSON, true);
    $picture = $decodedJSON[0]['cover']['source'];
    return $picture;
}

function getOfficialSite($fbid)
{
    $fbJSON = file_get_contents("https://graph.facebook.com/v2.6/" . $fbid . "?fields=description&amp;&access_token=1768882033345666|5465c1f6181700169eafddb0751c64aa");
    $decodedJSON[] = json_decode($fbJSON, true);
    $description = $decodedJSON[0]['description'];
    $matches = array();
    preg_match_all('#\bhttps?://[^\s()<>]+(?:\([\w\d]+\)|([^[:punct:]\s]|/))#', $description, $matches);
    return $matches[0][0];
}

function getLocation($fbid)
{
    $fbJSON = file_get_contents("https://graph.facebook.com/v2.6/" . $fbid . "?fields=place&amp;&access_token=1768882033345666|5465c1f6181700169eafddb0751c64aa");
    $decodedJSON[] = json_decode($fbJSON, true);
    $adresa = array();
    if (isset($decodedJSON[0]['place']['location']['street'])) {
        $ulica = explode(",", $decodedJSON[0]['place']['location']['street'], 2)[0];
        $adresa[] = $ulica;
    }
    if (isset($decodedJSON[0]['place']['location']['city'])) {
        $adresa[] = $decodedJSON[0]['place']['location']['city'];
    }
    if (isset($decodedJSON[0]['place']['location']['country'])) {
        $adresa[] = $decodedJSON[0]['place']['location']['country'];
    }
    $adresaReturn = implode(" , ", $adresa);
    return $adresaReturn;
}

function getDescription($fbid)
{
    $fbJSON = file_get_contents("https://graph.facebook.com/v2.6/" . $fbid . "?fields=description&amp;&access_token=1768882033345666|5465c1f6181700169eafddb0751c64aa");
    $decodedJSON[] = json_decode($fbJSON, true);
    if(isset($decodedJSON[0]['description'])){
        $description = $decodedJSON[0]['description'];
    }else{
        $description="Opis nije pronađen!";
    }
    return $description;
}

function getCoordinates($trackName, $fblocation)
{
    $returnArray = array();
    $query = "http://nominatim.openstreetmap.org/search.php?q=" . rawurlencode($fblocation) . "&format=xml";
    $rawData = file_get_contents($query);
    $searchResults = simplexml_load_string($rawData);
    if (!isset($searchResults->place[0])) {
        $query = "http://nominatim.openstreetmap.org/search.php?q=" . rawurlencode($trackName) . "&format=xml";
        $rawData = file_get_contents($query);
        $searchResults = simplexml_load_string($rawData);
        if (!isset($searchResults->place[0])) {
            $returnArray[0] = "??? ";
            $returnArray[1] = "??? ";
        } else {
            $returnArray[0] = (string)$searchResults->place[0]->attributes()->lat;
            $returnArray[1] = (string)$searchResults->place[0]->attributes()->lon;
        }
    } else {
        $returnArray[0] = (string)$searchResults->place[0]->attributes()->lat;
        $returnArray[1] = (string)$searchResults->place[0]->attributes()->lon;

    }
    return $returnArray;
}

function getTrueCoordinates($trackName)
{
    $query = "http://nominatim.openstreetmap.org/search.php?q=" . rawurlencode($trackName) . "&format=xml";
    $rawData = file_get_contents($query);
    $searchResults = simplexml_load_string($rawData);
    if (!isset($searchResults->place[0])) {
        $returnArray[0] = "??? ";
        $returnArray[1] = "??? ";
    } else {
        $returnArray[0] = (string)$searchResults->place[0]->attributes()->lat;
        $returnArray[1] = (string)$searchResults->place[0]->attributes()->lon;
    }
    return $returnArray;
}


?>
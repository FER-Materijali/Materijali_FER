<?php
 ini_set('display_errors', 1);
 ini_set('display_startup_errors', 1);
 error_reporting(E_ALL);
 $connection = new MongoClient( "mongodb://192.168.56.12");
 $db = $connection->nmbp;
 $collection = $db->vijesti;
 $cursor=$collection->find();
 /*foreach ($cursor as $document) {
    echo $document["naslov"] . "\n";
 }*/
?>




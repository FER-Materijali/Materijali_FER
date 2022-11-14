<?php

function printArray(&$array, $depth=0) {	//definicija funkcije, parametar dubine stabla inicijalno 0 (podrazumijevan)

	foreach($array as $key => $value) {		//za svaki kljuc i vrijednost polja
		
		for($t=0 ; $t<$depth ; $t++)		//pomak teksta na desno, u ovisnosti o dubini stabla
	   		echo "\t";
	   	echo "[$key] => [$value]\n";		//ispis kljuca i vrijednosti elementa polja
	   		
	   	if( is_array($value) == TRUE ) 		//ako je vrijednost tipa array
	   		printArray($value, $depth+1);	//ispisi sadrzaj polja na novoj dubini stabla
	}
}

$arr2 = array(0, 1, 2, 'c');
$arr1 = array(5, 12, $arr2, 'el1', 5, 'el2');

printArray($arr1);							//ispis sadrzaja polja $arr1
?>
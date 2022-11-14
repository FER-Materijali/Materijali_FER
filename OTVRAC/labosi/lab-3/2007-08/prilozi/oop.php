<?php

//definicija razreda Razred
class Razred
{
	//deklaracija javnog atributa atr
	public $atr = 12;

	//definicija javne metode inc
	public function inc($amount) {
		$this->atr +=$amount;
	}
}

$obj1 = new Razred();						//stvaranje objekta $obj1 tipa Razred
$obj2 = new Razred();						//stvaranje objekta $obj2 tipa Razred

echo '$obj1: ' . $obj1->atr . "\n";			//ispisivanje vrijednosti atributa atr objekta $obj1
echo '$obj2: ' . $obj2->atr . "\n";			//ispisivanje vrijednosti atributa atr objekta $obj2

$obj1->inc(4);								//pozivanje metode inc objekta $obj1
$obj2->inc(7);								//pozivanje metode inc objekta $obj2

echo "------------\n";
echo '$obj1: ' . $obj1->atr . "\n";			//ispisivanje vrijednosti atributa atr objekta $obj1
echo '$obj2: ' . $obj2->atr . "\n";			//ispisivanje vrijednosti atributa atr objekta $obj2

?>
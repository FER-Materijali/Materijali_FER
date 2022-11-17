#!perl

print "Unesite niz brojeva\n";
@lista = <STDIN>;

$j=0;
$suma=0;
while($lista[$j] != EOF){
	$suma+=$lista[$j];
	$j++;
}

print "Suma svih brojeva je $suma.\n";
print "Lista sadrzi $j brojeva.\n";
print "Aritmeticka sredina liste je: ", $suma/$j, " .\n";
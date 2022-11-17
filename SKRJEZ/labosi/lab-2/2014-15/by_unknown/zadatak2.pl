print ("Ucitaj niz brojeva\n");
@niz = <STDIN>;
foreach $niz (@niz) {
        $brel += 1;
        $suma += $niz;
}
$sred = $suma/$brel;
print "Aritmeticka sredina zadanih brojeva je $sred\n";
#!/usr/bin/perl

print "Unesite brojeve ciju aritmeticku sredinu zelite saznati (odvojiti razmakom):\n";

chomp( $ulaz = <STDIN> );
@polje = split /\ /, $ulaz;

if(@polje == 0){
	print "Nije unesen niti jedan broj!\n";
}else{
	foreach $element (@polje){
		$suma += $element;
	}
	printf "Aritmeticka sredina je: ". $suma/(@polje) ."\n";
}

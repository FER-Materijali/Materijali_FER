print("Ucitajte niz znakova\n");
chomp($znakovi = <STDIN>);
print("Ucitajte broj ponavljanja\n");
chomp($brojevi = <STDIN>);
 
for my $i (1..$brojevi) {
        print "$znakovi\n";
}
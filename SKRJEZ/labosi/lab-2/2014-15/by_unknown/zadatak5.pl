while (<>) {
        chomp;
        foreach $linija ($_){
                #print "$linija, $i\n";
                if ($i == 1) {
                        @faktori = split /;/, $linija;
                        #print "@faktori\n";
                }
                if ($i >= 4) {
                        @studenti = split /;/, $linija;
                        #print "@studenti\n";
                        $p = 3;
                        #print "@faktori\n";
                        foreach $fak (@faktori) {
                                #print "$fak\n";
                                $studenti[$p] *= $fak;
                                $bodovi += $studenti[$p];
                                $p += 1;
 
                        }
 
 
                #print "@studenti BODOVI: $bodovi\n";
                $kljuc = join(' ', "$studenti[1],", "$studenti[2]", "($studenti[0])");
                $polje{$kljuc}= $bodovi;
                $bodovi = 0;
        }
                $i += 1;
}
}
$br=1;
print "Lista po rangu:" . "\n";
print "---------------------" . "\n";
foreach $jmbg ( sort { $polje{$b} <=> $polje{$a} } keys %polje) {
        print "   $br. $jmbg : " . $polje{$jmbg} . "\n";
        $br += 1;
}
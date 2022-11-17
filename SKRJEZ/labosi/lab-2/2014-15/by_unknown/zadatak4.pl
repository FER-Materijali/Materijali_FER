while (<>){
        chomp;
        @odvojeno = split /;/;
        #print "$odvojeno[3]";
        $termin = $odvojeno[3];
        $zakljucano = $odvojeno[4];
        #print "$termin\n $zakljucano\n";
        @pocetak = split / /, $termin;
        $pocetak1 = $pocetak[1];
        @zakljucao = split / /, $zakljucano;
        $zakljucao1 = $zakljucao[1];
        #print "$pocetak1 \n$zakljucao1\n";
        $test = ($zakljucao1 - $pocetak1);
        #print "$test\n";
        if ($test){
        #print "GRESKA\n";
        print "$odvojeno[0] $odvojeno[1] $odvojeno[2] - PROBLEM: $pocetak[0] $pocetak[1] --> $odvojeno[4]" . "\n";
        }
 
}
$test = 0;
while (<>) {
 
        @datoteka = split /\./, $ARGV;
        $datum = $datoteka[1];
 
        $redak = $_;
        @split1 = split /\[/, $redak;
        @split2 = split /:/, $split1[1];
        $sati = $split2[1];
 
        if ($test == 0) {
                print "\n Datum" . $datum . "\n";
                print " Sat : Broj pristupa" . "\n";
                print " ---------------------" . "\n";
                $test = 1;
        }
 
        if ($test == 1) {
                $ispis[$sati] += 1;
        }
 
 
        if (eof) {
        $test=0;
        #kraj ispis
        foreach $p (0..23){
                print "    $p : $ispis[$p]" . "\n";
                $ispis[$p] = 0;
        }
 
        }
        }
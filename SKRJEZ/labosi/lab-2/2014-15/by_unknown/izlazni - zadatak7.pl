while (<>) {
        $redak = $_;
        @polje = split ' ', $redak;
        #print "$polje[9]\n";
        #print "$polje[0]\n";
        @polje2{$polje[0]} += $polje[9];

}

foreach $ispis (sort {$polje2{$b} <=> $polje2{$a}} keys %polje2) {
        print "$ispis : $polje2{$ispis}" . "\n";
}

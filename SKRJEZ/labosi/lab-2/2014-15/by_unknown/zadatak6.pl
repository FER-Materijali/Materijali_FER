
$broj = pop(@ARGV);

while (<>) {
        chomp;
        tr/A-Z/a-z/;
        $red = $_; #zbog transliteracija
        @popis = ($red =~ m/\b(\w{$broj})/g);

        foreach $rijec (@popis) {
                $polje{$rijec} += 1;
        }
}

@sort = (sort keys %polje);
#ispis
foreach $ispis (@sort) {
        print "$ispis : $polje{$ispis}" . "\n";
}

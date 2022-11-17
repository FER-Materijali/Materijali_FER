#!/usr/bin/perl -w

@lista = (<STDIN>);

foreach (@lista) {
	$sum += $_;
}

print "\navg=" . $sum/@lista . "\n";

exit 0;
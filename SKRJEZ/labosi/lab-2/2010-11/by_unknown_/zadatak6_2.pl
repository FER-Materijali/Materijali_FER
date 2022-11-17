#!/usr/bin/perl -w

$rot = $ARGV[0];
open CYPH, "<", "$ARGV[1]";

while (<CYPH>) {
	tr/a-z/A-Z/;
	eval "tr/$rot-ZA-$rot/A-Z/";
	print;
}
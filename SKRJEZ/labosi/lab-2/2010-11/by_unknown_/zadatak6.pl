#!/usr/bin/perl -w

$rot = $ARGV[0];
open CYPH, "<", "$ARGV[1]";

while (<CYPH>) {
	tr/a-z/A-Z/;
	eval "tr/A-Z/$rot-ZA-$rot/";
	print;
}
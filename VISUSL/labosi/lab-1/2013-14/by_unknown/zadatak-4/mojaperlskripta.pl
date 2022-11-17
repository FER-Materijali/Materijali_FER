#!/usr/bin/perl	 

use strict;
use CGI;
my $cgi = new CGI;
print
        $cgi->header() .
        $cgi->start_html( -title => 'Rezultati') .
        $cgi->h1('Rezultati') . "\n";
my @params = $cgi->param();
print '<TABLE border="1" cellspacing="0" cellpadding="5">' . "\n";
foreach my $parameter (@params) {
        print "<tr><th>$parameter</th><td>" . $cgi->param($parameter) . "</td></tr>\n";
}
print "</TABLE>\n";
print $cgi->end_html . "\n";
exit (0);
	  


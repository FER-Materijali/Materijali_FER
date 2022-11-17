#!/bin/bash
#Skriptni jezici
#Zadatak 3 za 1. ciklus laboratorijskih vjezbi 

#za svaku log datoteku iz liste koja zadovoljava wildcard pattern
#sa naredbom sed exractamo iz imena datum u obliku DD-MM-YYYY
for log in $(ls localhost_access_log.[0-9][0-9][0-9][0-9]-02-*) ; do
    echo $log | sed -r 's/.*\.([0-9]+)-([0-9]+)-([0-9]+).*/datum: \3-\2-\1/'
    echo "-----------------------------------------------------"
    
    #svaku datoteku ispisujemo sa cat, cut-amo samo http request, sortiramo 
    #prebrojimo linije te ostavimo originale sa uniq pa sortiramo po broju ponavljanja
    #zadnji sed sluzi samo za formatiranje outputa kao u pripremi
    cat $log | cut -d'"' -f 2 | sort | uniq -c | sort -rn | sed -r 's/\s+([0-9]*)(\s+)(.*)/    \1  :  \3/' 
    echo
done



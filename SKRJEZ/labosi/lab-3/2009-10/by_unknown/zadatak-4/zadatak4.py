import sys
import urllib
import re

url = sys.argv[1]
#url = "http://www.fer.hr/predmet/skrjez"
page = urllib.urlopen( url ).read()

links = re.findall('href="([^/jm?][^"]+)"', page)

hosts = {}
for link in links:
	match = re.match('http://(?P<host>[^/]+).*', link)
	if match:
		if match.group('host') not in hosts:
			hosts[match.group('host')] = 0
		hosts[match.group('host')] += 1
		
mails = re.findall('[a-zA-Z0-9_.]+@[a-z]+.[a-z]+', page)
pics = re.findall('<img src="([^"]+)"', page)

print "Linkovi na druge stranice:\n\t", '\n\t'.join(links)

print "\nHostovi i broj referenci:"
for x in hosts:
	print "\t", x, hosts[x]
print

print "\nE-mail adrese:\n\t", '\n\t'.join(mails)

print "\nBroj linkova na slike: ", len(pics)

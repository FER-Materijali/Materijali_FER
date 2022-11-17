
import sys
import re
import urllib.request
from urllib.request import urlopen

argument = sys.argv[1]
ucitavam = urlopen(argument)
ucitano = ucitavam.read().decode("utf8")

linkovi = re.findall('href="[^"]+"', ucitano)

host = {}

print("Linkovi: ")

for link in linkovi:
	link = (link.replace("href=", ""))[1:-1]
	#print("-->")
	print(link)
	if "http://" in link:
		#hostovi = link.replace("https://", "")
		hostovi = link.replace("http://", "")
		hostovi = link.replace("www.", "")
		hostovi = hostovi.split("/")
		#print(hostovi[2])
		#input("iznad")
		url = hostovi[2]
		if host.get(url,0):
			host[url] += 1
		else:
			host[url] = 1

print("\n  Hostovi:")
#print(host)
for linija in host.keys():
	#print ("-->"),
	print (linija, host[linija])

print("\n  E-mailovi:")

mail = re.findall(".+@.+\..+", ucitano)

for svaki in mail:
	#print("-->")
	print(svaki)

print("\n  Linkovi za slike:")

link = re.findall('<img[\s]+src="[^"]+"[^>]+>', ucitano)
#print("--> Broj:")
print("Broj:")
print(len(link))


import re, sys, urllib;

f = urllib.urlopen(sys.argv[1]);

#ucitavanje stranice
remote = f.read();
#ispis sadrzaja stranice
print remote;

hosts = {};

links = re.findall('href="(.+?)"',remote);

print;
print "Linkovi";

for url in links:
	print url;
	
	m = re.search('^(http|https|ftp|ftps)://([a-zA-Z0-9\.-]+)/',url);
	
	if(m != None): 
		
		h = m.group(2);
		if(h in hosts): hosts[h] += 1;
		else: hosts[h] = 1;
		
	
	
print;
print "Hostovi:";	

for k,v in hosts.iteritems():
	
	print k, v;


print;
print "E-mail adrese";

mails = re.findall('[A-Za-z0-9\._-]+@[a-zA-Z0-9\.-]+',remote);

for mail in mails:
	print mail;

imgNumber = len(re.findall('<img\s+src=".+',remote));

print;
print "Broj slika:",imgNumber;
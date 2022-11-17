import urllib.request
import re
import sys
from urllib.parse import urlparse

sourceURL=sys.argv[1]
# sourceURL="http://www.python.org"
reHref=r'href=[\'"]?(http[s]{0,1}[^\'" >]+)'
reEmail=r'([a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+)'
reHost=r'href=[\'"]?(http[s]{0,1}[^\'" >]+)'
reImage=r'img.*src="([^"]+)"'
stranica =  urllib.request.urlopen(sourceURL).read().decode('utf-8')

#Find all links
print("Links:")
links = re.findall(reHref, stranica)
for link in links:
    print(link)
print(" ")

#Find hosts from links
print("Hosts:")
print("{0:25s}   {1:5s}".format("Hostname","Count"))
print("-"*40)
hostsDict={}
hosts = re.findall(reHost,stranica)
for host in hosts:
    hostname=urlparse(host).hostname
    if hostname.startswith("www."):
        hostname=hostname[5:]
    if hostname in hostsDict:
        hostsDict[hostname] += 1
    else:
        hostsDict[hostname]=1
for (k,v) in hostsDict.items():
    print("{0:25s} : {1:3d}".format(k,v))

#Find emails
print(" ")
print("E-mail adrese:")
emailTest="purple alice@google.com, blah monkey bob@abc.com blah dishwasher"
emails = re.findall(reEmail,stranica)
for email in emails:
    print (email)

#find images
print(" ")
print("Images")
images=re.findall(reImage,stranica)
for image in images:
    print(image)
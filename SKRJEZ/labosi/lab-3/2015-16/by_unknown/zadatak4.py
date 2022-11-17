import urllib.request
import sys
import re

stranica = urllib.request.urlopen(sys.argv[1])
mybytes = stranica.read()
mystr = mybytes.decode("utf8")

hosts = {}
for match in re.findall(r'href="h.*?"', mystr):
    m = re.search(r'"https?://((www.)?(.*?)(/.*)?)"', match)
    url = m.group(1)
    host = m.group(3)

    print(url)
    if host in hosts:
        hosts[host] = hosts[host] + 1
    else:
        hosts[host] = 1

print("\n =========================================================================== \n")

for host in hosts.keys():
    print("%-50s %d" % (host, hosts[host]))

print("\n =========================================================================== \n")

mails = []
for match in re.findall(r"([a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+)", mystr):
    if not match in mails:
        mails.append(match)
    print(match)

print("\n =========================================================================== \n")

print(len(re.findall(r'<img.*?>', mystr)))

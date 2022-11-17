import urllib.request
import re
import sys


def main():
    adresa = sys.argv[1]
    stranica = urllib.request.urlopen(adresa)
    stranica = stranica.read()
    stranica = stranica.decode("utf8")

    linkovi = re.findall('href="[^"]+"', stranica)
    print("Linkovi:")
    for i in range(len(linkovi)):
        linkovi[i] = linkovi[i].replace("href=", "")
        linkovi[i] = linkovi[i][1:-1]
        print("-", linkovi[i])

    hostovi = {}
    for link in linkovi:
        if "http://" in link:
            host = link.replace("http://", "")
            host = host.replace("www.", "")
            for i in range(len(host)):
                if host[i] == "/":
                    host = host[:i]
                    break
            if host in hostovi.keys():
                hostovi[host] += 1
            else:
                hostovi[host] = 1
    print("\nHostovi:")
    for host in hostovi.keys():
        print("-", host, "se ponavlja", hostovi[host], "puta")

    print("\nE-MAIL-ovi:")
    emailovi = re.findall("[\w]+@[\w]+\.[\w]+", stranica)
    for email in emailovi:
        print("-", email)

    slike = re.findall('<img[\s]+src="[^"]+"[^>]+>', stranica)
##    for slika in slike:
##        print("-", slika)
    print("\n--", len(slike), "slika")


if __name__ == "__main__":
    main()

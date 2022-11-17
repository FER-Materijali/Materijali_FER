import sys

ulaz = sys.argv[1]

linije = open(ulaz, "r").readlines()
rijecnik = {}

for linija in linije:
        dijeljeno = linija.split(" ")
        #print (dijeljeno)
        ip = dijeljeno[0]
        bajt = dijeljeno[-1]
        #print (ip, bajt)
        broj = bajt.strip()
        #input("pauza")
        if ip not in rijecnik.keys():
                rijecnik[ip] = 0
        #print(rijecnik)
        if broj is not "-":
                rijecnik[ip] += int(broj)

#print (rijecnik)
sort =  sorted(rijecnik, key=rijecnik.get, reverse=True)
#print (sort)
#input("PAUZA")
for ip in sort:
        print("{0} : {1}".format(ip,rijecnik[ip]))


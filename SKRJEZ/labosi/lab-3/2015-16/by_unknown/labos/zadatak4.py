import sys

if len(sys.argv) != 1:
    print("Pogrešan broj argumenata.")
    print(">>python3 zadatak4.py putanja_do_datoteke")
    sys.exit(1)
    
lines=[]
with open(sys.argv[1],'r') as dat:
    lines=dat.readlines()

print("<OL>")
for line in lines:
    line=line.rstrip()
    if line == '':
        break
    imeprezime=line.split(";")[0]
    ime=imeprezime.split(",")[1]
    prezime=imeprezime.split(",")[0]
    naziv=line.split(";")[1]
    godina=line.split(";")[2]
    print("  <LI>{0} {1}, <I>{2}</I>, {3}</LI>".format(ime,prezime,naziv,godina))
print("</OL>")

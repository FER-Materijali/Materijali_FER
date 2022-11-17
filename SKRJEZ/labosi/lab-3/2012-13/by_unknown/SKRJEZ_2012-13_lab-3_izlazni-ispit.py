import sys

dat = sys.argv[1]
datoteka = open(dat, "r")
datoteka = datoteka.readlines()
for i in datoteka:
    j = i.split(" ")
    akcija = j[5]
    akcija = akcija[1:]
    print(j[0] + " : " + akcija + " : " + j[6] + " : " + j[9])



import re
import os

listdir = os.listdir(".")

lstudent = {}
llabos = {}
lbroj = []

datoteka = open("studenti.txt", "r")
linije = datoteka.readlines()

brojac = 1

for odvajanje in linije:
	imeprez = odvajanje.strip().split(" ")
	lstudent[imeprez[0]] = [imeprez[1],imeprez[2]] # jmbag : ime,prez
	brojac += 1

for red in listdir:
	if re.match('(Lab_[0-9]+_g[0-9]+.txt)', red):
		broj = int(red.split("_")[1])
		lab = open(red, "r")
		lablinije = lab.readlines()
		if broj not in lbroj:
			lbroj.append(broj)
		for student in lablinije:
			JMBAG,bod = student.strip().split(' ')
			if (llabos.get((JMBAG,broj),0) == 0):
				llabos[JMBAG,broj]=bod
			else:
				print("Greska, student jmbag", JMBAG, " je viseputa izasla na labos")

print ("JMBAG \t\t Prezime,Ime\t", end="")
#sorted(lbroj)
#print (lbroj)
sortirano = sorted(lbroj)
for broj in sortirano:
	print("\tL"+str(broj), end="")

print("")

for student in lstudent:
	print(student, "\t", end="")
	print(lstudent[student][0], lstudent[student][1], end="\t\t")
	for lab in sortirano:
		
		print(str(float(llabos.get((student,int(lab)),0))) + "\t", end="")
	print("")


def popuni(koja):
	red = matricapod[koja].split("\n")
	#print (red)
	dimenzija[koja] = red[0]
	elementi = red[1:]
	rijecnik = {}
	for element in elementi:
		if element is not "":
			element1 = element.split(" ")
			prvi = (int)(element1[0])
			drugi = (int)(element1[1])
			#print (prvi,drugi)
			rijecnik[(prvi,drugi)] = (float)(element1[2])
	print ("Matrica", koja+1, "\n", rijecnik, "\n")
	return rijecnik


def pomnozi(prva,druga):
	pomnozena={}
	for red in range(1, dimenzija2[0]+1):
		for stupac in range(1, dimenzija2[1]+1):
			pomnozena[(red,stupac)] = 0
			for stupac0 in range(1, dimenzija0[1]+1):
				pomnozena[(red,stupac)] =  pomnozena[(red,stupac)] + float(prva.get((red,stupac0),0)*druga.get((stupac0, stupac),0))
				#print (pomnozena)
	return pomnozena

datoteka = open("matrice.txt", "r").read()
matricapod = datoteka.split("\n\n")

#print (matricapod)

dimenzija = [0,0]
matrica0 = popuni(0)
matrica1 = popuni(1)

dimenzija0 = [int(x) for x in dimenzija[0].split(" ")]
dimenzija1 = [int(x) for x in dimenzija[1].split(" ")]

dimenzija2 = [dimenzija0[0],dimenzija1[1]]

if (dimenzija0[0] == dimenzija1[1]):
	#print("Iste su")
	pmatrica = pomnozi(matrica0,matrica1)
else: 
	print("Matrice nisu ulancane, greska!")
	exit

novadat = open("umnozak.txt", "w")
novadat.write(str(dimenzija2[0])+" "+str(dimenzija2[1])+"\n")
print (pmatrica)
print("Umnozak i spremanje u datoteku:")
for red in range(1, dimenzija2[0]+1):
	for stupac in range(1, dimenzija2[1]+1):
		print("%f " % (pmatrica[(red,stupac)]), end=" ")
		if pmatrica[(red,stupac)] == 0:
			del pmatrica[(red,stupac)]
		else:
			novadat.write(str(red)+" "+str(stupac)+" "+str(pmatrica[(red,stupac)])+"\n")
	print("")


novadat.close()
#datoteka.close()

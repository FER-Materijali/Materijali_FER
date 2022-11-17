
print("Hyp#Q10#Q20#Q30#Q40#Q50#Q60#Q70#Q80#Q90")

datoteka = open("ulaz.txt", "r")
linije = datoteka.readlines()
#print (linije)

red = {}

brojac = 0

for element in linije:
        red[brojac] = [(float)(x) for x in linije[brojac].strip().split(" ")]
        red[brojac].sort()
        brojac += 1


brojac = 1

for broj in red:
        print("00%u" % brojac, end="")
        for posto in (0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9):
                broj = (int)(posto*len(red[brojac-1]))
                print("#{0}".format(red[brojac-1][broj]), end="")
        print("")
        brojac += 1

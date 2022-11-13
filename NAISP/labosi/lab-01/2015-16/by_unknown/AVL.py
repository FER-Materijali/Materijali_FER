import sys

class Cvor(): #klasa za cvor
        def  __init__(sebe, podatak): # init sebe i podatak
                sebe.podatak = podatak # u cvor stavi podatak
                sebe.lijevo = None # lijevo dijete prazno
                sebe.desno = None # desno dijete prazno
               
 
class AVLStablo(): # klasa avl stablo
	def  __init__(ulaz, *novi): # init sebe i pokazivac na argumente
		ulaz.cvor = None # cvor prazan
		ulaz.visina = -1 # visina -1 tek smo krenuli
		ulaz.FR = 0 # FR 0 - balansirano
		if len(novi) == 1:
			for i in novi[0]: # svaki novi
				ulaz.insert(i) # umetni
 
	def visina(ulaz): # visina
		if ulaz.cvor: # ako postoji cvor
			return ulaz.cvor.visina # vrati visinu
		else:
			return 0 # ili 0
                       
	def list(ulaz): # visina list
		return (ulaz.visina == 0) # visina 0 za list
               
	def insert(ulaz, podatak): #umetni podatak
		stablo = ulaz.cvor # stablo je cvor
		novicvor = Cvor(podatak) # novi cvor je cvor s podatkom i praznom djecom
               
		if stablo == None: # ako nema stabla
			ulaz.cvor = novicvor # novi cvor je korijen
			ulaz.cvor.lijevo = AVLStablo() # novo stablo lijevo
			ulaz.cvor.desno = AVLStablo() # novo stablo desno
                      
		elif podatak < stablo.podatak: # ako je podatak manji
			ulaz.cvor.lijevo.insert(podatak) # lijevo
                       
		elif podatak > stablo.podatak: # ako je podatak veci
			ulaz.cvor.desno.insert(podatak) # desno
		ulaz.balans()


	def balans(ulaz): # balansiraj pod drvo
		ulaz.azurirajvisinu(False) # ne azuriramo ni visinu ni FR
		ulaz.azurirajFR(False)
		while ulaz.FR < -1 or ulaz.FR > 1: # provjera FR
			if ulaz.FR > 1: # desna tezina
				if ulaz.cvor.lijevo.FR < 0: # lijevo dijete -1, potrebna lijeva rotacija
					ulaz.cvor.lijevo.lrotiraj()
					ulaz.azurirajvisinu()
					ulaz.azurirajFR()
				ulaz.drotiraj() # inace desna rotacija
				ulaz.azurirajvisinu()
				ulaz.azurirajFR()
					
			if ulaz.FR < -1: # lijeva tezina
				if ulaz.cvor.desno.FR > 0:
					ulaz.cvor.desno.drotiraj()
					ulaz.azurirajvisinu()
					ulaz.azurirajFR()
				ulaz.lrotiraj()
				ulaz.azurirajvisinu()
				ulaz.azurirajFR()
	
	def drotiraj(ulaz):
			
		cvor = ulaz.cvor
		lijevi = ulaz.cvor.lijevo.cvor
		desni = lijevi.desno.cvor
			
		ulaz.cvor = lijevi
		lijevi.desno.cvor = cvor
		cvor.lijevo.cvor = desni
		
	def lrotiraj(ulaz):
		
		cvor = ulaz.cvor
		desni = ulaz.cvor.desno.cvor
		lijevi = desni.lijevo.cvor
			
		ulaz.cvor = desni
		desni.lijevo.cvor = cvor
		cvor.desno.cvor = lijevi
			
	def azurirajvisinu(ulaz, rekurzija=True):
		if not ulaz.cvor == None:			
			if rekurzija:
				if ulaz.cvor.lijevo != None:
					ulaz.cvor.lijevo.azurirajvisinu()
				if ulaz.cvor.desno != None:
					ulaz.cvor.desno.azurirajvisinu()
				
			ulaz.visina = max(ulaz.cvor.lijevo.visina, ulaz.cvor.desno.visina) + 1
		else:
			ulaz.visina = -1
		
	def azurirajFR(ulaz, rekurzija=True):
		if not ulaz.cvor == None:			
			if rekurzija:
				if ulaz.cvor.lijevo != None:
					ulaz.cvor.lijevo.azurirajFR()
				if ulaz.cvor.desno != None:
					ulaz.cvor.desno.azurirajFR()
				
			ulaz.FR = (ulaz.cvor.lijevo.visina - ulaz.cvor.desno.visina)
			
		else:
			ulaz.FR = 0			
	 			
				
			
	def ispis(ulaz, razina=0, ld=''): # ispis
		ulaz.azurirajvisinu()
		ulaz.azurirajFR()
			
		if(ulaz.cvor != None):
			print '-' * razina * 2, ld, ulaz.cvor.podatak, 'Visina ' + str(ulaz.visina) + ' FR ' + str(ulaz.FR), 'List' if ulaz.list() else ' '
						
			if ulaz.cvor.lijevo != None:
				ulaz.cvor.lijevo.ispis(razina + 1, 'L')
			if ulaz.cvor.lijevo != None:
				ulaz.cvor.desno.ispis(razina + 1, 'D')

					
if __name__ == "__main__":                        
	a = AVLStablo()
	print "Citam datoteku"
	datoteka = open(sys.argv[1], 'r')
	polje = []
	for i in datoteka.readline().split():
		polje.append(i)
	print polje
	for i in polje:
		a.insert(i)
		           
	a.ispis()
	
	while True:
		broj = raw_input("Unesite novi podatak")
		if broj.isdigit():
			print "Unosim podatak " + broj
			a.insert(broj)
			a.ispis()
		else:
			print "Niste unjeli broj!"
items = [
	(1,2,5),
	(1,6,8),
	(1,10,10),
	(2,7,4),
	(2,3,5),
	(3,4,1),
	(3,5,2)] # kategorija 0, cijena 1, zadovoljstvo 2
	
num_cat = 0
cat = 0
number_item = [0,0,0]
 
for i in items:
	if cat != i[0]:
		num_cat+=1
	cat = i[0] 
#print cat
table = [[0 for x in range(16)] for x in range(7)]
keep_table = [[0 for x in range(16)] for x in range(7)]
#print table[0]
#print table[0][0]
#raw_input("pauza")
#print items[0]
#print items[0][0]
row = 0
history_max = 0
history_weight = 0
item_num = 0 # ukupni broj
residue_weight = 0
sum_old_new = 0
item_cat = [0,0,0] # broj u kategoriji prije
history_max_offset = 0 # pomaknut za tezinu
new_value = 0 # zbrojeno trenutna + prosla pomaknuta

for i in range(1,num_cat+1):
	#print i
	#print("koja smo kategorija")
	#raw_input("kategorija")
	for j in items:
		if i == 1:
			if j[0] == i:
				item_num += 1
				#print ("printam item ") +  str(j) 
				#raw_input("pauza")
				number_item[i-1] += 1
				for k in range(16): 
					if j[1] <= k: # provjera tezine i prostora po stupcima
						table[row][k]=j[2]
						keep_table[row][k] = 1
						#print("umetnuo sam u prvu kategoriju")			
				#print table[row]
				row +=1
				#raw_input("pauza, prva kategorija")
		else:
			if j[0] == i:
				item_num += 1
				#print ("printam item, nije 1. kategorija, koji ubacujemo ") +  str(j) 
				#raw_input("nije prva kategorija ")
				number_item[i-1] += 1 # povecam broj itema u kategoriji, da se znamo vratiti kasnije
				for k in range(16):					
					for p in range(0,number_item[i-2]): # prvi krug je 3 elementa					
						if history_max < table[row-(p+1+item_cat[i-1])][k]:
							history_max = table[row-(p+1+item_cat[i-1])][k] # stupac							
							#print("printam history max za stupac") + str(history_max)
							#raw_input("history max za stupac")
							
					if j[1] > k:
						if history_max != 0:
							table[row][k] = history_max
							
					if j[1] <= k:
						for p in range(0,number_item[i-2]):
							if history_max_offset < table[row-(p+1+item_cat[i-1])][k-j[1]]:
								history_max_offset = table[row-(p+1+item_cat[i-1])][k-j[1]] # stupac							
								#print("printam history max pomaknuti za stupac") + str(history_max)
								#raw_input("history max pomaknuti za stupac")
							
						new_value = j[2] + history_max_offset
						if history_max > new_value:
							table[row][k] = history_max						
						else:
							table[row][k] = new_value
							keep_table[row][k] = 1
						#print ("dodao sam novu vrijednost")
						#print table[row]
						#raw_input("redak s novom vrijednosti")
						
						
						
						
						'''if history_max >= j[1]:
							print("history max je veci, spremam njega ")
							table[row][k] = history_max
							residue_weight = k-history_weight
							print table[row]
							print residue_weight
							print k
							raw_input("tablica s history max na poziciji ") 
							if j[1] <= residue_weight:
								sum_old_new = (j[2]+history_max)
								print("ostatak tezine je dovoljan za item, suma je ") + str(sum_old_new)								
							if history_max < sum_old_new:
								table[row][k] = sum_old_new
								print("nova suma je veca, nju stavljamo ") 
								print("tablica sa sumom")
								print table[row]
								raw_input("tablica sa sumom")
						else:
							table[row][k] = j[2]
							print table[row]
							print("ubacio sam vrijednost predmeta, veci od historya, printam")
							raw_input("tablica samo ubacen")'''
							
					history_max = 0
					history_max_offset = 0
					#history_weight = 0
					#sum_old_new = 0
				#print table[row]
				row +=1
				item_cat[i-1] += 1
				#print ("kraj 2 kat 1 red")
				#for a in range(7):
					#print table[a]
					#print keep_table[a]
					#raw_input("pauza kraj")	
	
row -= 1
print("\n")	
print("Printamo ulazne podatke, prvi broj je kategorije, drugi tezina, treci cijena")
for a in items:
	print a

print("\n")	
print("Printamo tablicu \n")
print('\n'.join([''.join(['{:4}'.format(item) for item in red]) for red in table]))
print("\n")	
print("Printamo keep tablicu\n")
print('\n'.join([''.join(['{:4}'.format(item) for item in red]) for red in keep_table]))
print("\n")

	  
#raw_input("Tablica")

#print num_cat
print("Optimalno rjesenje je kombinacija: ")
#print keep_table[row][k]
#raw_input("keep tablica red")


while (1):
	if keep_table[row][k] == 1: # keep = 1, uzmemo taj podatak
		print items[row] # ispisemo ga
		#print k
		k = k - items[row][1] # pomaknemo se stupaca za cijenu podatka
		#print k
		#raw_input("k prije i poslije")
		row = row - number_item[num_cat-1]
		num_cat -= 1		
		
		if (row < 0 or k < 0):
			break
		
	else:
		row = row-1
		if row < 0:
			break
		



	
		
		
		
	
	
		
		
	
	
		
	

				
				

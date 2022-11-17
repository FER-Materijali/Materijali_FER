import string;

Q = lambda i,num : int(round((i/100.0)*num)); 

file = open("ulaz.txt","rb");
counter = 1;

for line in file:
	
	niz = line.split();
	
	for i in range(0,len(niz)):
	
		niz[i] = float(niz[i]);
		
	niz.sort();
	num = len(niz);
	
	print "%03i" % counter,;
	
	for i in range(1,10):
		
		print "#%.2f" % niz[Q(i,num)],;
		
	counter += 1;
	print;
	
file.close();
		
		
	
	

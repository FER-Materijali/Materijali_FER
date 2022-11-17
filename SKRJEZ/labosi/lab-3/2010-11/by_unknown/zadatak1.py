#!/usr/bin/python
import string,sys;

def loadMatrix(fpointer):
	
	
	for line in fpointer:
		line = line.rstrip();
		break;
	
	dimensions = line.split();
	
	mat = inicijaliziraj_matricu(int(dimensions[0]),int(dimensions[1]));
		
	
	for line in fpointer:
		
		line = line.rstrip();
		
		if(len(line) == 0): return mat;
		
		matDef = string.split(line,' ');
		i = int(matDef[0]);
		j = int(matDef[1]);
		
		mat[i][j] = float(matDef[2]);
		
	
	return mat;
	
def inicijaliziraj_matricu(w,h):
	
	mat = {};
	
	for i in range(1,w+1):
		
		mat[i] = {}
		for j in range(1,h+1):
			
			mat[i][j] = 0;
		#
	#
	
	mat['w'] = w;
	mat['h'] = h;
	
	return mat;


	
def zbroji(mat1, mat2):
	
	if(type(mat1) != type(dict()) or type(mat2) != type(dict())):
		print "Argumenti funkcije mat1 i mat2 moraju biti rjecnici";
		return False;
	
	if(mat1['w'] != mat2['h']):
		print "Matrice nisu ulancane";
		return False;
		
	mat3 = inicijaliziraj_matricu(mat1['w'],mat2['h']);
	
	for i in range(1,mat1['w']+1):
		
		for j in range(1,mat2['h']+1):
			
			for k in range(1, mat1['w']+1):
				
				mat3[i][j] += mat1[i][k] * mat2[k][j];
				#print mat3[i][j];
			#
		#
	#
	
	return mat3;

def ispisi(mat,fpointer):
	
	if(type(mat) !=  type(dict())): 
		
		print "Funkciji ispisi potrebno je predati rjecnik";
		return False;
		
	for i in range(1, mat['w']+1):
		
		for j in range(1, mat['h']+1):
			
			if(mat[i][j] != 0): 
				
				fpointer.write('%d %d %f\n' % (i,j,mat[i][j]));
				
			#
		#
	#
	
	return True;
			
	

####################

file = open(sys.argv[1]);
mat1 = loadMatrix(file);
mat2 = loadMatrix(file);

file.close();

file = open(sys.argv[2],'w');

mat3 = zbroji(mat1,mat2);

if(mat3): ispisi(mat3,file);

file.close();
	
	


#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#       vjezba6.py
#       3. ciklus vjezbi - IRG
#       Copyright 2012 Petra <petra@Yeezi>
#       
#       
#       
from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
import math
import random
##*********************************************************************************
##	Pokazivac na glavni prozor i pocetna velicina.
##*********************************************************************************



class Ociste():

	def __init__(self, x, y, z):
		self.x = x
		self.y = y
		self.z = z

global ociste	
ociste = Ociste(3.0, 3.0 ,5.0)
#glediste = Ociste(0, 0, 0)
global flag
flag=3 #oznacava tip iscrtavanja 1-wire, 2-konst, 3-gouraud
global Ia, Ii,ka,kd
Ia=100
Ii=200 # 0-255
ka=0.5
kd=0.5 # 0-1
global izvor
izvor = [-2, 5, 2] #zadavanje polozaja izvora
global t
t=0.0 #faktor za gibanje po krivulji


##*********************************************************************************
##	Osvjezavanje prikaza. 
##*********************************************************************************

def myDisplay():
	#print("Pozvan myDisplay()\n")
	glClearColor( 1.0, 1.0, 1.0, 1.0)	         # boja pozadine - bijela
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
	if flag==1:
		myObject ()
	if flag==2:
		konstantnoSjencanje()
	if flag==3:
		gouraudovoSjencanje()
		
	glutSwapBuffers()      # iscrtavanje iz dvostrukog spemnika (umjesto glFlush)


##*********************************************************************************
##	Promjena velicine prozora.
##	Funkcija gluPerspective i gluLookAt se obavlja 
##		transformacija pogleda i projekcija
##*********************************************************************************

def myReshape (w, h):
	#print("MR: width=%d, height=%d\n",w,h);
	
	global window
	global width
	global height
	
	width=w
	height=h
	glViewport(0, 0, width, height) 
	glMatrixMode(GL_PROJECTION)        # aktivirana matrica projekcije
	glLoadIdentity()
	gluPerspective(45.0, float(width/height), 0.5, 15.0) # kut pogleda, x/y, prednja i straznja ravnina odsjecanja
	gluLookAt(ociste.x, ociste.y, ociste.z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0)	# ociste x,y,z; glediste x,y,z; up vektor x,y,z
	glMatrixMode(GL_MODELVIEW)      # aktivirana matrica modela


def updatePerspective():
	glMatrixMode(GL_PROJECTION)        # aktivirana matrica projekcije
	glLoadIdentity()
	gluPerspective(45.0, float(width/height), 0.5, 15.0) # kut pogleda, x/y, prednja i straznja ravnina odsjecanja
	gluLookAt(ociste.x, ociste.y, ociste.z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0)	# ociste x,y,z; glediste x,y,z; up vektor x,y,z
	glMatrixMode(GL_MODELVIEW)         # aktivirana matrica modela



##*********************************************************************************
##	Crta moj objekt. Ovdje treba naciniti prikaz ucitanog objekta.
##*********************************************************************************

def myObject():

	#glutWireCube (1.0)
	#glutSolidCube (1.0)
	#glutWireTeapot (1.0)
	#glutSolidTeapot (1.0)
	#glBegin (GL_TRIANGLES) # ili glBegin (GL_LINE_LOOP) za zicnu formu
	
	for i in range(0, len(poligoni)):
		
		if jeStraznji2(i):
			glBegin (GL_LINE_LOOP) 
			V1 = vrhovi[int(poligoni[i][0]) - 1]
			V2 = vrhovi[int(poligoni[i][1]) - 1]
			V3 = vrhovi[int(poligoni[i][2]) - 1]

			glColor3ub(255, 0, 0)	
			glVertex3f(V1[0], V1[1], V1[2])
			glColor3ub(0, 0, 0)	
			glVertex3f(V2[0], V2[1], V2[2])
			glColor3ub(100, 0, 0)
			glVertex3f(V3[0], V3[1], V3[2])
			
			glEnd()



def konstantnoSjencanje():
	
	for i in range(0, len(poligoni)):
		I = int(inteziteti[i])
		if jeStraznji2(i):
			glBegin (GL_TRIANGLES) 
			V1 = vrhovi[int(poligoni[i][0]) - 1]
			V2 = vrhovi[int(poligoni[i][1]) - 1]
			V3 = vrhovi[int(poligoni[i][2]) - 1]

			glColor3ub(I, 0, 0)	
			glVertex3f(V1[0], V1[1], V1[2])
			glColor3ub(I, 0, 0)	
			glVertex3f(V2[0], V2[1], V2[2])
			glColor3ub(I, 0, 0)
			glVertex3f(V3[0], V3[1], V3[2])
			
			glEnd()

def gouraudovoSjencanje():
	
	for i in range(0, len(poligoni)):
		
		if jeStraznji2(i):
			glBegin (GL_TRIANGLES) 
			V1 = vrhovi[int(poligoni[i][0]) - 1]
			V2 = vrhovi[int(poligoni[i][1]) - 1]
			V3 = vrhovi[int(poligoni[i][2]) - 1]
			
			i1 = intezitetiVrh[int(poligoni[i][0]) - 1]
			i2 = intezitetiVrh[int(poligoni[i][1]) - 1]
			i3 = intezitetiVrh[int(poligoni[i][2]) - 1]
			
			glColor3ub(i1, 0, 0)	
			glVertex3f(V1[0], V1[1], V1[2])
			glColor3ub(i2, 0, 0)	
			glVertex3f(V2[0], V2[1], V2[2])
			glColor3ub(i3, 0, 0)
			glVertex3f(V3[0], V3[1], V3[2])
			
			glEnd()


def jeStraznji2(i):
	
	vektorPO = [ociste.x-sredistaPoligona[i][0], 
					ociste.y-sredistaPoligona[i][1],
					ociste.z-sredistaPoligona[i][2]]
					
	D=math.sqrt(vektorPO[0]*vektorPO[0]+vektorPO[1]*vektorPO[1]+vektorPO[2]*vektorPO[2])
	brojnik = (vektorPO[0]/D)*ravnine[i][0]+(vektorPO[1]/D)*ravnine[i][1]+(vektorPO[2]/D)*ravnine[i][2]
	
	if brojnik > 0:
		return 1
	else:
		return 0

#drugi nacin za racunanje vidljivosti		
def jeStraznji(poligon):
	
	produkt = ravnine[poligon][0]*ociste.x + ravnine[poligon][1]*ociste.y + ravnine[poligon][2]*ociste.z + ravnine[poligon][3]
	if produkt > 0:
		return 1 #vidljiv
	else:
		return 0 #straznji
##*********************************************************************************
##	Mis.
##*********************************************************************************

def myMouse(button, state, x, y):
	#	Desna tipka - brise canvas. 
	global t
	if (button == GLUT_RIGHT_BUTTON and state == GLUT_DOWN):
		ociste.x=0
		ociste.y=3.0
		ociste.z=5.0
		t=0.0
		
		updatePerspective()
		glutPostRedisplay()



##*********************************************************************************
##	Tastatura tipke - esc - izlazi iz programa.
##*********************************************************************************

def myKeyboard(theKey, mouseX, mouseY):
	global t
	if theKey=="l":
		ociste.x = ociste.x+0.1
	elif theKey=="k":
		ociste.x =ociste.x-0.1
	elif theKey=="r":
		ociste.x=0.0
	elif theKey=="i":
		ociste.y=ociste.y+0.1
	elif theKey=="o":
		ociste.y=ociste.y-0.1
	elif theKey=="u":
		if t<0.99:
			t=t+0.1
			ociste.x=odrediTocke(t,"x");
			ociste.y=odrediTocke(t,"y");
			ociste.z=odrediTocke(t,"z");
			#print ociste.x, ociste.y, ociste.z, "ociste nakon pritiska tipke u"
	elif theKey=="z":
		if t>0.0:
			t=t-0.1
			ociste.x=odrediTocke(t,"x");
			ociste.y=odrediTocke(t,"y");
			ociste.z=odrediTocke(t,"z");
			#print ociste.x, ociste.y, ociste.z, "ociste nakon pritiska tipke z"
	
	elif theKey==27:
		exit(0)
	else:
		pass
	
	redisplay_all()
	#updatePerspective()
	#glutPostRedisplay()


#ucitavanje tijela
def ucitajTijelo():
	finput = open('teddy.obj', 'r')
	ulaz = finput.readlines()
	global vrhovi
	global poligoni
	vrhovi = []
	poligoni = []
	
	for each in ulaz:
		each=each.rstrip()
		if each == "":
			continue #prazna linija
		if each[0]=='v':
			each = each.split() #lista koordinata npr. [0, 0, 0]
			each.pop(0) #makni "v"
			vrhovifloat=[]
			for v in each:
				vrhovifloat.append(float(v))
			#print each
			#print each, "vrhovi"
			vrhovi.append(vrhovifloat) 
		elif each[0]=='f':
			each = each.split() #lista vrhova [1, 3, 2]
			each.pop(0) #makni f
			poligoni.append(each)
		else:
			continue #komentar

def ucitajTockeKontrolnogPoligona():
	ulaz=open("tocke.txt", "r").readlines()
	
	global tockeKontrolnogPoligona
	tockeKontrolnogPoligona = []
	
	for each in ulaz:
		each=each.rstrip()
		each=each.split()
		vrhovi = []
		for i in each:
			vrhovi.append(float(i))
		tockeKontrolnogPoligona.append(vrhovi)
	#print tockeKontrolnogPoligona
		
def smijestiTijeloURadniProstor():
	global vrhovi
	
	#dodijeli neku pocetnu vrijednost max i min
	xmax=vrhovi[0][0]
	xmin=vrhovi[0][0]
	
	ymax=vrhovi[0][1]
	ymin=vrhovi[0][1]
	
	zmax=vrhovi[0][2]
	zmin=vrhovi[0][2]
	
	for vrh in vrhovi:
		if vrh[0]>xmax:
			xmax=vrh[0]
		if vrh[0]<xmin:
			xmin=vrh[0]
		if vrh[1]>ymax:
			ymax=vrh[1]
		if vrh[1]<ymin:
			ymin=vrh[1]
		if vrh[2]>zmax:
			zmax=vrh[2]
		if vrh[2]<zmin:
			zmin=vrh[2]
			
	velicina_x = xmax - xmin
	velicina_y = ymax - ymin
	velicina_z = zmax - zmin
		
	srediste_x = (xmax + xmin)/2
	srediste_y = (ymax + ymin)/2
	srediste_z = (zmax + zmin)/2 
	
	
	#noviVrhovi=[]
	faktor = max(max(velicina_x,velicina_y),velicina_z)
	for vrh in vrhovi:
		
		#pomak za srediste
		vrh[0] = vrh[0] - srediste_x
		vrh[1] = vrh[1] - srediste_y
		vrh[2] = vrh[2] - srediste_z
	
	#print "nakon tranaslacije"
	#for i in vrhovi:
	#	print i
		
	for vrh in vrhovi:	
		#skaliranje:
		vrh[0]=vrh[0]*(2/faktor)
		vrh[1]=vrh[1]*(2/faktor)
		vrh[2]=vrh[2]*(2/faktor)
	#print "nakon sklairanja"
	
	#for i in vrhovi:
		#print i
		
def izracunajABCD():
	global ravnine
	global poligoni
	global vrhovi
	global normale
	global sredistaPoligona
	normale = []
	ravnine = []
	sredistaPoligona = []
	for every in poligoni:
		#napomena: u poligonima se vrhove krecu od 1, ne od 0!
		
		
		#print every, "izracinjaABCD:every poligon"
		V1=vrhovi[int(every[0])-1] #lista [1.0, 2.0, 3.0]
		V2=vrhovi[int(every[1])-1]
		V3=vrhovi[int(every[2])-1]
		
		#print V1, V2, V3 , "izracunaj abccf : v1, v2, v3!"
		#racunam sredisnju tocku poligona
		#to mi treba za racunanje vektora ocista i te tocke
		xmax = max(V1[0], max(V2[0], V3[0]))
		ymax = max(V1[1], max(V2[1], V3[1]))
		zmax = max(V1[2], max(V2[2], V3[2]))
		
		xmin = min(V1[0], min(V2[0], V3[0]))
		ymin = min(V1[1], min(V2[1], V3[1]))
		zmin = min(V1[2], min(V2[2], V3[2]))
		
		sredisnjaTocka = [(xmax+xmin)/2, (ymax+ymin)/2, (zmax+zmin)/2]
		
		#print sredisnjaTocka, "sredisnjatocka"
		sredistaPoligona.append(sredisnjaTocka)
		
		#0-xevi, 1-yoni, 2-zovi
		
		A = (float(V2[1])-float(V1[1]))*(float(V3[2])-float(V1[2]))-(float(V2[2])-float(V1[2]))*(float(V3[1])-float(V1[1]))
		B = -(float(V2[0])-float(V1[0]))*(float(V3[2])-float(V1[2]))+(float(V2[2])-float(V1[2]))*(float(V3[0])-float(V1[0]))
		C = (float(V2[0])-float(V1[0]))*(float(V3[1])-float(V1[1]))-(float(V2[1])-float(V1[1]))*(float(V3[0])-float(V1[0]))
		D = -A*float(V1[0])-B*float(V1[1])-C*float(V1[2])
		
		#print A, B, C, D, " --- A B C D"
		ravnine.append((A,B,C,D))

		norma = math.sqrt(A*A + B*B + C*C)
		normale.append((A/norma, B/norma, C/norma))



def odrediTocke(t,zastavica):
	n=len(tockeKontrolnogPoligona)-1
	tocka=0.0
	if zastavica=='x':
		for i in range(0,len(tockeKontrolnogPoligona)):
			tocka+=tockeKontrolnogPoligona[i][0]*baznaFunkcija(t,i)
	
	if zastavica=='y':
		for i in range(0, len(tockeKontrolnogPoligona)):
				tocka+=tockeKontrolnogPoligona[i][1]*baznaFunkcija(t,i)
	
	if zastavica=='z':
		for i in range(0, len(tockeKontrolnogPoligona)):
				tocka+=tockeKontrolnogPoligona[i][2]*baznaFunkcija(t,i)
	
	return tocka
		
		
def baznaFunkcija(t,i):
	
	
	#print math.factorial(0), "lA"
	n=len(tockeKontrolnogPoligona)-1
	
	#print 1.0*math.factorial(n)
	#print (math.factorial(i)*(n-i))
	
	b = 1.0*math.factorial(n)/(math.factorial(i)*math.factorial(n-i))
	b = b*math.pow(t,i)*math.pow((1-t),(n-i))
	
	return b
	
def odrediIntezitetePoligona():
	global inteziteti
	inteziteti=[]
	

	#Id=Iaka + Iika(LN)
	
	for i in range(0, len(poligoni)):
		
		L = [izvor[0]-sredistaPoligona[i][0], 
					izvor[1]-sredistaPoligona[i][1],
					izvor[2]-sredistaPoligona[i][2]]
		Lsqrt = math.sqrt(L[0]*L[0]+L[1]*L[1]+L[2]*L[2])
		Lnorm = [L[0]/Lsqrt, L[1]/Lsqrt, L[2]/Lsqrt]
		
		#print len(normale)
		##print len(poligoni)
		#print Lnorm, "lnrom"
		#print normale[i], "normale[i]"
		inteziteti.append(math.floor(Ia*ka+Ii*kd*(Lnorm[0]*normale[i][0]+Lnorm[1]*normale[i][1]+Lnorm[2]*normale[i][2])))
	#print inteziteti
		
def odrediNormaleVrhova():
	
	global normaleVrhova
	
	normaleVrhova=[]
	for i in range(1, len(vrhovi)+1):
		normV = [] #lista normala koji su povezane s vrhomm i
		for j in range(0, len(poligoni)):
			if str(i) in poligoni[j]:
				normV.append(normale[j])
		
		n_x=0
		n_y=0
		n_z=0
		for each in normV:
			n_x += each[0]
			n_y += each[1]
			n_z += each[2]
			
		n_x=n_x/len(normV)
		n_y=n_y/len(normV)
		n_z=n_z/len(normV)
		
		#normiranje
		nlen = math.sqrt(n_x*n_x+n_y*n_y+n_z*n_z)
		
		normaleVrhova.append((n_x/nlen,n_y/nlen,n_z/nlen))
	#print normaleVrhova


def odrediInteziteteVrhova():
	global intezitetiVrh
	intezitetiVrh=[]

	#Id=Iaka + Iika(LN)
	for i in range(0, len(vrhovi)):
		
		L = [izvor[0]-vrhovi[i][0], 
					izvor[1]-vrhovi[i][1],
					izvor[2]-vrhovi[i][2]]
		Lsqrt = math.sqrt(L[0]*L[0]+L[1]*L[1]+L[2]*L[2])
		Lnorm = [L[0]/Lsqrt, L[1]/Lsqrt, L[2]/Lsqrt]
		
		#print len(normaleVrhova), "normaleVrhova"
		#print len(poligoni)
		intezitetiVrh.append(int(Ia*ka+Ii*kd*(Lnorm[0]*normaleVrhova[i][0]+Lnorm[1]*normaleVrhova[i][1]+Lnorm[2]*normaleVrhova[i][2])))
	
	#print intezitetiVrh

def main():
	global window
	global width
	global height
	width = 600
	height = 600
	
	
	glutInit(sys.argv)

	#postavljanje dvostrukog spremnika za prikaz (zbog titranja)
	glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH)
	glutInitWindowSize (width, height)
	glutInitWindowPosition (100, 100)
	window = glutCreateWindow ("Tijelo")
	glEnable(GL_DEPTH_TEST)
	glDepthFunc(GL_LEQUAL)
	glutReshapeFunc(myReshape)
	glutDisplayFunc(myDisplay)
	glutMouseFunc(myMouse)
	glutKeyboardFunc(myKeyboard)
	print("Tipka: l - pomicanje ocista po x os +\n")
	print("Tipka: k - pomicanje ocista po x os -\n")
	print("Tipka: o - pomicanje ocista po y os +\n")
	print("Tipka: i - pomicanje ocista po y os -\n")
	print("Tipka: u - pomicanje ocista po krivulji +\n")
	print("Tipka: z - pomicanje ocista po krivulji -\n")
	print("Tipka: r - pocetno stanje\n")
	print("esc: izlaz iz programa\n")


	#ucitavanje objekta
	ucitajTijelo()
	#print "prije"
	#for i in vrhovi:
	#	print i
	smijestiTijeloURadniProstor()
	ucitajTockeKontrolnogPoligona()
	#print "posli"
	#for i in vrhovi:
	#	print i
	izracunajABCD()
	odrediIntezitetePoligona()
	odrediNormaleVrhova()
	odrediInteziteteVrhova()
	redisplay_all()
	glutMainLoop()
	return 0


def redisplay_all():
	glutSetWindow(window);
	myReshape (width, height);
	glutPostRedisplay();

if __name__ == '__main__':
	main()


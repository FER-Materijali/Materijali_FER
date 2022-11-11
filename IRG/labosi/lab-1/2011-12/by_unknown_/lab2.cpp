#ifdef _WIN32
#include <windows.h>             //bit ce ukljuceno ako se koriste windows
#endif

//  #include <GL/Gl.h>
//  #include <GL/Glu.h>    nije potrebno ako se koristi glut
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

GLdouble Lx[3], Ly[3];
GLint Ix;

//*********************************************************************************
//	Pokazivac na glavni prozor i pocetna velicina.
//*********************************************************************************

GLuint window; 
GLuint sub_width = 256, sub_height = 256;
GLboolean izvan = false;

//*********************************************************************************
//	Function Prototypes.
//*********************************************************************************

void myDisplay		();
void myReshape		(int width, int height);
void myMouse		(int button, int state, int x, int y);
void myKeyboard		(unsigned char theKey, int mouseX, int mouseY);
void colorPolygona	();
void colorPolygonb	();
void colorPolygonc	();

//Broj stranica mnogokuta
GLint brojStranica;

GLint xMin, xMax, yMin, yMax;

GLint *poljeX, *poljeY, *a, *b, *c;
GLint i, j;
GLboolean nacrtan = false;

//*********************************************************************************
//	Glavni program.
//*********************************************************************************

int main(int argc, char ** argv)
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(sub_width,sub_height);
	glutInitWindowPosition(100,100);
	glutInit(&argc, argv);

	window = glutCreateWindow("Glut OpenGL Linija");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(myDisplay);
	glutMouseFunc(myMouse);
	glutKeyboardFunc(myKeyboard);

	printf("Unesite broj stranica mnogokuta: ");
	scanf("%d", &brojStranica);
	printf("\n");
	printf("Oznacite u smjeru kazaljke vrhove poligon na ekranu\n", brojStranica);

	poljeX = new GLint[brojStranica];
	poljeY = new GLint[brojStranica];
	a = new GLint[brojStranica];
	b = new GLint[brojStranica];
	c = new GLint[brojStranica];

	glutMainLoop();
    	return 0;
}


//*********************************************************************************
//	Osvjezavanje prikaza. (nakon preklapanja prozora) 
//*********************************************************************************

void myDisplay()
{
 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glFlush();
}

//*********************************************************************************
//	Promjena velicine prozora.
//*********************************************************************************

void myReshape(int width, int height)
{
	sub_width = width;                      	//promjena sirine prozora
    	sub_height = height;				//promjena visine prozora

	Ix = 0;						//	indeks tocke 0-prva 1-druga tocka
    	glViewport(0, 0, sub_width, sub_height);	//  	otvor u prozoru
	glMatrixMode(GL_PROJECTION);			//	matrica projekcije
	glLoadIdentity();				//	jedinicna matrica
	gluOrtho2D(0, sub_width, 0, sub_height); 	//	okomita projekcija
	glClearColor( 1.0f, 1.0f, 1.0f, 0.0f );		//	boja pozadine
	glClear( GL_COLOR_BUFFER_BIT );			//	brisanje pozadine
	glPointSize(1.0);				//	postavi velicinu tocke
	glColor3f(0.0f, 0.0f, 0.0f);			//	postavi boju
}

//*********************************************************************************
//	Crtaj moju liniju.
//*********************************************************************************

void myLine(GLint xa, GLint ya, GLint xb, GLint yb)
{
	glBegin(GL_LINES);
	{
		glVertex2i(xa,ya);			//	crtanje gotove linije
		glVertex2i(xb,yb);				
	}
	glEnd();
	
	
}

//*********************************************************************************
//	Mis.
//*********************************************************************************

GLint predaniVrhovi = 1;
GLint temp;

void myMouse(int button, int state, int x, int y)
{
	y = sub_height - y;
	//	Lijeva tipka - crta pocetnu tocku ili liniju.
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)

	{
		if(predaniVrhovi <= brojStranica) {
			//	Pamti krajnju tocke linije.
			Lx[Ix] = x;							//	upisi tocku
			Ly[Ix] = y;
			Ix = Ix ^ 1;						//	flip - druga tocka
			
			poljeX[predaniVrhovi - 1] = x;
			poljeY[predaniVrhovi - 1] = y;

			if(predaniVrhovi==1) {
				Lx[2] = x;
				Ly[2] = y;
			}

			if(predaniVrhovi > 1) {
				
				if(x < xMin) xMin = x;
				if(x > xMax) xMax = x;
				if(y < yMin) yMin = y;
				if(y > yMax) yMax = y;

				if (predaniVrhovi < brojStranica)	myLine(Lx[0], Ly[0], Lx[1], Ly[1]);
				else {
					myLine(Lx[Ix^1], Ly[Ix^1], Lx[2], Ly[2]);
					myLine(Lx[0], Ly[0], Lx[1], Ly[1]);
				}
			}
			else {
				xMin = x; xMax = x; yMin = y; yMax = y;
			}

			printf("Koordinate tocke %d: %d %d \n", predaniVrhovi, x, y);
			predaniVrhovi++;

		}

		else {
			
			glPointSize(3.0);				//	postavi velicinu tocke
			glBegin(GL_POINTS);
			glVertex2i(x,y);
			glEnd();

			/*Ispitati odnos toèke V i poligona.
			Ako postoji barem jedan brid tako da vrijedi
			x1 a(i) + y1 b(i) + c(i) > 0, i = 0, n-1 -> toèka V je izvan poligona,
			inaèe, toèka V je unutar poligona.*/
			izvan = false;
			for (i = 0; i < brojStranica; i++) {
				temp = x*a[i] + y*b[i] + c[i];
				if (temp > 0) izvan = true;
			}
			if (izvan) printf("Koordinate tocke: %d %d -> Tocka je izvan poligona \n", x, y);
			else printf("Koordinate tocke: %d %d -> Tocka je unutar poligona \n", x, y);

		}

		if(predaniVrhovi == brojStranica + 1) {
			printf("Najmanji x je %d, najveci x je %d, najmanji y je %d, a najveci y je %d\n", xMin, xMax, yMin, yMax);
			nacrtan = true;
			for (i = 0; i < brojStranica; i++) {
				a[i] = poljeY[i] - (i == brojStranica-1 ? poljeY[0]:poljeY[i+1]);
				b[i] = -poljeX[i] + (i == brojStranica-1 ? poljeX[0]:poljeX[i+1]);
				c[i] = poljeX[i]*(i == brojStranica-1 ? poljeY[0]:poljeY[i+1]) 
					- poljeY[i]*(i == brojStranica-1 ? poljeX[0]:poljeX[i+1]);
				printf("Brid %d: %d, %d, %d\n", i, a[i], b[i], c[i]);
			}
			predaniVrhovi++;
		}

		glFlush();
	}

	//	Desna tipka - brise canvas. 
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//myReshape(sub_width, sub_height);
	}
}


//*********************************************************************************
//	Tastatura tipke - r, g, b, k - mijenjaju boju.
//*********************************************************************************

void myKeyboard(unsigned char theKey, int mouseX, int mouseY)
{
	switch (theKey)
	{
		case 'r':
			glColor3f(1,0,0);
			break;

		case 'g':
			glColor3f(0,1,0);
			break;

		case 'b':
			glColor3f(0,0,1);
			break;

		case 'k':
			glColor3f(0,0,0);
			break;

		case 'c':
			if (nacrtan) colorPolygon();
			break;

			
	}
	if(theKey != 'c') glRecti(sub_width-15, sub_height-15, sub_width, sub_height);
		// crta mali kvadrat u boji
	glFlush();
}

GLboolean obojan = false;
GLfloat L, D;
GLfloat sjeciste;
GLfloat l1, l2;

void colorPolygon() {
	if (!obojan) {
		obojan = true;

		for (i = yMin; i < yMax; i ++) { 

			L = xMin; D = xMax;

			for (j = 0; j < brojStranica; j++) {
				if(a[j] != 0) {
					sjeciste = (-b[j]*i - c[j])/(float)a[j]; //korak 12

					if (poljeY[j] < (j == brojStranica-1 ? poljeY[0]:poljeY[j+1])) {
						if (sjeciste > L) L = sjeciste; //korak 13
					}
					else if (sjeciste < D) {
						D = sjeciste; //korak 14
					}
				}
			}

			if (L < D) {
				glBegin(GL_LINES);
				glVertex2i(L, i);
				glVertex2i(D, i);
				glEnd();
			}
		}
	}
}

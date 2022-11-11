//*************************************************************************************************************
//	Crtanje tijela
//	Tijelo se crta u funkciji myObject
//	
//	Zadatak: Treba ucitati tijelo zapisano u *.obj, sjencati i ukloniti staznje poligone
//	S tastature l - pomicanje ocista po x osi +
//		k - pomicanje ocista po x osi +
//              r - pocetni polozaj
//              esc izlaz iz programa
//*************************************************************************************************************

#include <stdio.h>
#include <GL/glut.h>

//*********************************************************************************
//	Pokazivac na glavni prozor i pocetna velicina.
//*********************************************************************************

GLuint window; 
GLuint width = 300, height = 300;

typedef struct _Ociste {
	GLdouble	x;
	GLdouble	y;
	GLdouble	z;
} Ociste;


Ociste	ociste = {0, 0 ,5.0};

//*********************************************************************************
//	Function Prototypes.
//*********************************************************************************

void myDisplay		();
void myReshape		(int width, int height);
void myMouse		(int button, int state, int x, int y);
void myKeyboard		(unsigned char theKey, int mouseX, int mouseY);
void myObject		();
void redisplay_all	(void);

//*************************
//**************************

void redisplay_all(void)
{
    glutSetWindow(window);
    myReshape (width, height);
    glutPostRedisplay();
}

//*********************************************************************************
//	Glavni program.
//*********************************************************************************

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	// postavljanje dvostrukog spremnika za prikaz (zbog titranja)
	glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize (width, height); 
	glutInitWindowPosition (100, 100);
   
	window = glutCreateWindow ("Tijelo");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(myDisplay);
	glutMouseFunc(myMouse);
	glutKeyboardFunc(myKeyboard);
	printf("Tipka: l - pomicanje ocista po x os +\n");
	printf("Tipka: k - pomicanje ocista po x os -\n");
	printf("Tipka: r - pocetno stanje\n");
	printf("esc: izlaz iz programa\n");
	
	redisplay_all();
	glutMainLoop();
	return 0;
}

//*********************************************************************************
//	Osvjezavanje prikaza. 
//*********************************************************************************

void myDisplay(void)
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	myObject ();
	glutSwapBuffers();      // iscrtavanje iz dvostrukog spemnika (umjesto glFlush)
}

//*********************************************************************************
//	Promjena velicine prozora.
//	Funkcija gluPerspective i gluLookAt se obavlja 
//		transformacija pogleda i projekcija
//*********************************************************************************

void myReshape (int w, int h)
{
	width=w; height=h;
	glViewport (0, 0, width, height); 
	glMatrixMode (GL_PROJECTION);        // aktivirana matrica projekcije
	glLoadIdentity ();
	glClearColor( 1.0f, 1.0f, 1.0f, 1.0f);		         // boja pozadine - bijela
	glClear ( GL_COLOR_BUFFER_BIT );				     // brisanje zaslona
	gluPerspective(45.0, (float)width/height, 0.5, 8.0); // kut pogleda, x/y, prednja i straznja ravnina odsjecanja
	gluLookAt (ociste.x, ociste.y, ociste.z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);	// ociste x,y,z; glediste x,y,z; up vektor x,y,z
	glColor3ub (0, 0, 255);
	glMatrixMode (GL_MODELVIEW);         // aktivirana matrica modela
}

//*********************************************************************************
//	Crta moj objekt. Ovdje treba naciniti prikaz ucitanog objekta.
//*********************************************************************************

void myObject ()
{
//	glutWireCube (1.0);
//	glutSolidCube (1.0);
//	glutWireTeapot (1.0);
//	glutSolidTeapot (1.0);
	
	glBegin (GL_TRIANGLES); // ili glBegin (GL_LINE_LOOP); za zicnu formu
		glColor3ub(255, 0, 0);	glVertex3f(-1.0, 0.0, 0.0);
		glColor3ub(0, 0, 0);	glVertex3f(0.0, 1.0, 0.0);
		glColor3ub(100, 0, 0);	glVertex3f(0.0, 0.0, 1.0);
	glEnd();


}

//*********************************************************************************
//	Mis.
//*********************************************************************************

void myMouse(int button, int state, int x, int y)
{
	//	Desna tipka - brise canvas. 
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		ociste.x=0;
		redisplay_all();
	}
}

//*********************************************************************************
//	Tastatura tipke - esc - izlazi iz programa.
//*********************************************************************************

void myKeyboard(unsigned char theKey, int mouseX, int mouseY)
{
	switch (theKey) 
	{
		case 'l': ociste.x = ociste.x+0.1;
        break;

		case 'k': ociste.x =ociste.x-0.1;
        break;

		case 'r': ociste.x=0.0;
        break;

		case 27:  exit(0);
		break;
	}
    redisplay_all();
}


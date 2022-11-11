#ifdef _WIN32
#include <windows.h>             //bit ce ukljuceno ako se koriste windows
#endif

//  #include <GL/Gl.h>
//  #include <GL/Glu.h>    nije potrebno ako se koristi glut
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

//*********************************************************************************
//	Pokazivac na glavni prozor i pocetna velicina.
//*********************************************************************************

GLuint window; 
GLuint sub_width = 256, sub_height = 256;

//*********************************************************************************
//	Function Prototypes.
//*********************************************************************************

void myDisplay		();
void myReshape		(int width, int height);
void mandelbrontovSkup();
void julijinSkup();
GLuint eps, m;
GLdouble uMin, uMax, vMin, vMax;
GLint k;
GLdouble u0, v0;
GLdouble r;

typedef struct {
	double re;
	double im;
} complex;

complex c, z, z0;

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
	
	//printf("Unesite prag epsilon eps i maksimalan broj iteracija m:\n");
	//scanf("%d %d", &eps, &m);

	//printf("\nUnesite podrucje kompleksne ravnine koja se promatra (umin, umax), (vmin, vmax):\n");
	//scanf("%d %d %d %d", &uMin, &uMax, &vMin, &vMax);

	eps = 100; m = 16; uMin = -1; uMax = 1; vMin = -1.2; vMax = 1.2;

	glutMainLoop();
    	return 0;
}


//*********************************************************************************
//	Osvjezavanje prikaza. (nakon preklapanja prozora) 
//*********************************************************************************

void myDisplay()
{
 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//mandelbrontovSkup();
	julijinSkup();

	glFlush();
}

void mandelbrontovSkup() {
	
	glBegin(GL_POINTS);

	for(int i = 0; i < sub_height; i++) {		//sub_height
		for (int j = 0; j < sub_width; j++) {	//sub_width
			
			//odrediti u0, v0
			u0 = (uMax - uMin)*i/sub_height + uMin;
			v0 = (vMax - vMin)*j/sub_width + vMin;

			//Postaviti: k = -1, creal = u0, cimag = v0 , z0 = 0.
			k = -1; z0.re = 0; z0.im = 0; c.re = u0; c.im = v0;
			do {
				k++;
				z.re = pow(z0.re, 2) - pow(z0.im, 2) + c.re;
				z.im = 2 * z0.im * z0.re + c.im;
				z0.re = z.re; z0.im = z.im;
				r = sqrt(pow(z.re, 2) + pow(z.im, 2));
			} while (r < eps && k < m);
			if(r<eps) k = -1;
			//Na mjestu x0, y0 iscrtati slikovni element u boji k
			//printf("%d %d -> %d\n", i, j, k);
			if (k == -1) glColor3f(0.0, 0.0, 0.0);
			else glColor3f((double)k/m, 1.0-(double)k/m/2.0, 0.8-(double)k/m/3.0);
			glVertex2i(i, j);
		}
	}
	glEnd();
}

void julijinSkup() {
	
	//Ucitati c
	//scanf("%f %f", &c.re, &c.im);
	//c.re = −0.807984,c.im =−0.145732
	c.re = 0.32; c.im = 0.043;

	glBegin(GL_POINTS);

	for(int i = 0; i < sub_height; i++) {		//sub_height
		for (int j = 0; j < sub_width; j++) {	//sub_width
			
			//odrediti u0, v0
			u0 = (uMax - uMin)*i/sub_height + uMin;
			v0 = (vMax - vMin)*j/sub_width + vMin;

			//Postaviti: k = -1, creal = u0, cimag = v0 , z0 = 0.
			k = -1; z0.re = u0; z0.im = v0;
			do {
				k++;
				z.re = pow(z0.re, 2) - pow(z0.im, 2) + c.re;
				z.im = 2 * z0.im * z0.re + c.im;
				z0.re = z.re; z0.im = z.im;
				r = sqrt(pow(z.re, 2) + pow(z.im, 2));
			} while (r < eps && k < m);

			if(r<eps) k = -1;
			//Na mjestu x0, y0 iscrtati slikovni element u boji k
			//printf("%d %d -> %d\n", i, j, k);
			if (k == -1) glColor3f(0.0, 0.0, 0.0);
			else glColor3f((double)k/m, 1.0-(double)k/m/2.0, 0.8-(double)k/m/3.0);
			glVertex2i(i, j);
		}
	}
	glEnd();
}

//*********************************************************************************
//	Promjena velicine prozora.
//*********************************************************************************

void myReshape(int width, int height)
{
	sub_width = width;                      	//promjena sirine prozora
    sub_height = height;						//promjena visine prozora

    glViewport(0, 0, sub_width, sub_height);	//  otvor u prozoru
	glMatrixMode(GL_PROJECTION);				//	matrica projekcije
	glLoadIdentity();							//	jedinicna matrica
	gluOrtho2D(0, sub_width, 0, sub_height); 	//	okomita projekcija
	glClearColor( 1.0f, 1.0f, 1.0f, 0.0f );		//	boja pozadine
	glClear( GL_COLOR_BUFFER_BIT );				//	brisanje pozadine
	glPointSize(1.0);							//	postavi velicinu tocke
	//glColor3f(0.0f, 0.0f, 0.0f);				//	postavi boju
}

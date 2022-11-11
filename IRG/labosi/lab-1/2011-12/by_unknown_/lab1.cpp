//*********************************************************************************
//	Iscrtavanje linije 0-45, usporedba s glLine naredbom.
//	Pocetna i krajnja koordinata se zadaju lijevom tiplom misa, desnom se brise.
//	r,g, b, k s tastature mijenja boju.
//
//	Zadatak: Treba preraditi void myLine(GLint xa, GLint ya, GLint xb, GLint yb)
//	tako da radi ispravno za sve kutove
//
//*********************************************************************************

#ifdef _WIN32
#include <windows.h>             //bit ce ukljuceno ako se koriste windows
#endif

//  #include <GL/Gl.h>
//  #include <GL/Glu.h>    nije potrebno ako se koristi glut
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>


//*********************************************************************************
//	Pocetna tocka Lx[1], Ly[1] Krajnja tocke Lx[2], Ly[2] linije.
//	Ix - stanje (zadana 1 ili 2 tocka)
//*********************************************************************************

GLdouble Lx[2], Ly[2];
GLint Ix;

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
void myMouse		(int button, int state, int x, int y);
void myKeyboard		(unsigned char theKey, int mouseX, int mouseY);


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
	printf("Lijevom tipkom misa zadaj tocke - algoritam Bresenham-a\n");
	printf("Tipke r, g, b, k mijenjaju boju.\n");

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
    sub_height = height;						//promjena visine prozora

	Ix = 0;										//	indeks tocke 0-prva 1-druga tocka
    glViewport(0, 0, sub_width, sub_height);	//  otvor u prozoru
	glMatrixMode(GL_PROJECTION);				//	matrica projekcije
	glLoadIdentity();							//	jedinicna matrica
	gluOrtho2D(0, sub_width, 0, sub_height); 	//	okomita projekcija
	glClearColor( 1.0f, 1.0f, 1.0f, 0.0f );		//	boja pozadine
	glClear( GL_COLOR_BUFFER_BIT );				//	brisanje pozadine
	glPointSize(1.0);							//	postavi velicinu tocke
	glColor3f(0.0f, 0.0f, 0.0f);				//	postavi boju
}

//*********************************************************************************
//	Crtaj moju liniju.
//*********************************************************************************

//ispravljen primjer koji radi za sve kuteve
void myLine(GLint xa, GLint ya, GLint xb, GLint yb)
{
	GLuint tempX, tempY;

	if (xa > xb) 
	{
		//prva tocka je uvijek ona lijevo
		tempX = xa;
		tempY = ya;
		xa = xb;
		ya = yb;
		xb = tempX;
		yb = tempY;
	}

	glBegin(GL_LINES);
	{
		glVertex2i(xa,ya+5);					//	crtanje gotove linije
		glVertex2i(xb,yb+5);
	}
	glEnd();
	
	GLint	x = xa;                        		
	GLint	y = ya;
	
	GLint	dx = xb - xa;
	GLint	dy = yb - ya;

	GLboolean yRaste = true;

	if (dy < 0)
	{
		//gledamo da li pravac raste ili pada po y
		//ako pada, uzimamo apsolutnu vrijednost
		dy = abs(dy);
		yRaste = false;
	}

	GLfloat d;

	//gledamo da li je tan(kutRast) < 1
	if (dy/(double)dx < 1) d=abs(dy/(double)dx)-0.5;
	else d = abs(dx/(double)dy) - 0.5;

	printf ("dx = %d; dy = %d; d = %f\n", dx, dy, d);

	glBegin(GL_POINTS);
	if (dy/(double)dx < 1)
	{  
		for (int i = 0; i <= dx; i++)	     	
		{
			glVertex2i(x,y);
			//printf ("x = %d; y = %d; d = %f\n", x, y, d);
			if (d > 0)					
			{
				if (yRaste)y++;	
				else y--;
				d=d-1.0;				
			}
			x++;
			d+=dy/(double)dx;
		}
	}
	else
	{
		for (int i = 0; i <= dy; i++)	     	
		{
			glVertex2i(x,y);
			//printf ("x = %d; y = %d; d = %f\n", x, y, d);
			if (d > 0)					
			{
				x++;					
				d=d-1.0;				
			}
			if(yRaste)y++;
			else y--;
			d+=dx/(double)dy;
		}
	}
	glEnd();
}

//primjer sa stranica lab. vjezbi koji radi za do 45 stupnjeva
void myOriginalLine(GLint xa, GLint ya, GLint xb, GLint yb)
{
	glBegin(GL_LINES);
	{
		glVertex2i(xa,ya+5);			//	crtanje gotove linije
		glVertex2i(xb,yb+5);				
	}
	glEnd();
	
	GLint	x = xa;                        		//	Bresenhamov algoritam do 45  
	GLint	y = ya;
	
	GLint	dx = xb - xa;
	GLint	dy = yb - ya;

	GLfloat	d=dy/(double)dx-0.5;

	glBegin(GL_POINTS);
	  for (int i = 0; i <= dx; i++)	     	
		{
			glVertex2i(x,y);			
			if (d > 0)					
			{
				y++;					
				d=d-1.0;				
			}
			x++;
			d+=dy/(double)dx;
		}
	glEnd();
}

//*********************************************************************************
//	Mis.
//*********************************************************************************

void myMouse(int button, int state, int x, int y)
{
	//	Lijeva tipka - crta pocetnu tocku ili liniju.
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)

	{
		//	Pamti krajnju tocke linije.
		Lx[Ix] = x;							//	upisi tocku
		Ly[Ix] = sub_height - y;
		Ix = Ix ^ 1;						//	flip - druga tocka

		//	Crta prvu tocku ili liniju do druge tocke.
		if (Ix == 0)	myLine(Lx[0], Ly[0], Lx[1], Ly[1]);
		//if (Ix == 0)	myOriginalLine(Lx[0], Ly[0], Lx[1], Ly[1]);
		else			glVertex2i(x, sub_height-y);

		printf("Koordinate tocke %d: %d %d \n", Ix^1, x, y);

		glFlush();
	}

	//	Desna tipka - brise canvas. 
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		myReshape(sub_width, sub_height);
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
			
	}
	glRecti(sub_width-15, sub_height-15, sub_width, sub_height); // crta mali kvadrat u boji
	glFlush();
}


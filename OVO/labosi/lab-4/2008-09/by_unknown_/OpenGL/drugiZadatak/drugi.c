#include <math.h>
#include <GL\glut.h>

#define PI 3.14159

void init(void) 
{
	const GLfloat glfLightAmbient[4] = {0.1, 0.1, 0.1, 1.0};
	const GLfloat glfLightDiffuse[4] = {0.7, 0.7, 0.0, 1.0};
	const GLfloat glfLightSpecular[4] = {1.0, 1.0, 1.0, 1.0};

	glClearColor(0.0, 0.0, 0.0, 0.0);
	
	glLightfv(GL_LIGHT0, GL_AMBIENT,  glfLightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE,  glfLightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, glfLightSpecular);
	
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

/* ako se velicina prozora poveca po sirini povecaj projekcijski 
 * volumen za omjer sirina (prozora) / duzina (prozora) 
 */
	if ((GLsizei) w >= (GLsizei) h)
	{
		glOrtho(-5.5*(GLfloat) w /(GLfloat) h, 
				 5.5*(GLfloat) w /(GLfloat) h,
				-5.5, 5.5, -5.5, 5.5);
	}
/* ako se velicina prozora poveca po duzini povecaj projekcijski 
 * volumen za omjer duzina (prozora) / sirina (prozora) 
 */
	else
	{
		glOrtho(-5.5, 5.5,
				-5.5*(GLfloat) h /(GLfloat) w, 
				 5.5*(GLfloat) h /(GLfloat) w, 
				-5.5, 5.5);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void drawSphere(float R, float step)
{
	int i = 0;
	float theta, fi, 
		  koord1[3] = {0.0,0.0,0.0}, 
		  koord2[3] = {0.0,0.0,0.0}, 
		  koord3[3] = {0.0,0.0,0.0}, 
		  koord4[3] = {0.0,0.0,0.0};

	for(fi = 0; fi < PI; fi = fi + step)
	{
		for(theta = 0; theta <= 2*PI; theta = theta + 0.1, i = (i+1)%2)		
		{
			if(i == 0)
			{
			koord1[0] = R * cos(theta) * sin(fi);
			koord1[1] = R * sin(theta) * sin(fi);
			koord1[2] = R * cos(fi);
			
			koord2[0] = R * cos(theta) * sin(fi+step);
			koord2[1] = R * sin(theta) * sin(fi+step);
			koord2[2] = R * cos(fi+step);
			}
			
			else if(i == 1)
			{
			koord3[0] = R * cos(theta) * sin(fi);
			koord3[1] = R * sin(theta) * sin(fi);
			koord3[2] = R * cos(fi);
						            
			koord4[0] = R * cos(theta) * sin(fi+step);
			koord4[1] = R * sin(theta) * sin(fi+step);
			koord4[2] = R * cos(fi+step);
			}
						
			glBegin(GL_QUAD_STRIP);
				glVertex3fv(koord1);
				glNormal3fv(koord1);	
				
				glVertex3fv(koord2);
				glNormal3fv(koord2);	
				
				glVertex3fv(koord3);
				glNormal3fv(koord3);	
				
				glVertex3fv(koord4);
				glNormal3fv(koord4);	
			glEnd();
		}
	}
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	drawSphere(2.0, 0.01);
	
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
// koristenje z-spremnika
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (400, 400); 
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc(display); 
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}






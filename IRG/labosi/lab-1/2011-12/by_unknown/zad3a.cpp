/* treci zadatak - mandelbrotov fraktal

g++ zad3a.cpp -lglut -lGLU -o zad3a && ./zad3a

*/


#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void reshape(int width, int height);
void display();
void mouse(int button, int state, int x, int y);
void keyboard(unsigned char key, int x, int y);
void draw();

struct color {
	float r;
	float g;
	float b;
};


bool drugaTocka = false;
color curr = { 0.0f, 0.0f, 0.0f};

float umin, umax, vmin, vmax;
int maxit;
int eps;

GLuint width = 400;
GLuint height = 400;

int main(int argc, char *argv[]) {

	cout << "Unesite prag eps: ";
	cin >> eps;
	cout << "Unesite max broj iteracija: ";
	cin >> maxit;
	cout << "Unesite umin umax vmin i vmax: ";
	cin >> umin >> umax >> vmin >> vmax;
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(200,200);
	
	glutCreateWindow("Vjezba 3 - Mandelbrot");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutMainLoop();
}


void display() {
	cout << "display() called" << endl;
	
	glClearColor( 1.0f, 1.0f, 1.0f, 0.0f );
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
	glLoadIdentity();
	glPointSize(1.0);

	glBegin(GL_POINTS);
	float c_re, c_im, r, z_re, z_im, z_re2, z_im2;
	int k;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			c_re = (umax-umin)*x / (float) width + umin;
			c_im = (vmax-vmin)*y / (float) height + vmin;
			k = -1;
			z_re = 0;
			z_im = 0;
			do {
				k++;
				z_re2 = z_re * z_re - z_im*z_im + c_re;
				z_im2 = 2.0*z_re*z_im + c_im;
				z_re = z_re2;
				z_im = z_im2;
				r = sqrt(z_re*z_re + z_im*z_im);			
			} while  (r < eps && k < maxit);

			float t = k/(float)maxit;
			if (t < 0 || t > 1) t = 0.0;
			glColor3f(t,t,t);
			glVertex2i(x,height-y);
			
		}
	}
	glEnd();
	glutSwapBuffers();
}

void reshape(int w, int h) {
	cout << "reshape("<< width <<","<< height<<") called" << endl;
	width = w;
	height = h;

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width-1, 0, height);
	glMatrixMode(GL_MODELVIEW);

}

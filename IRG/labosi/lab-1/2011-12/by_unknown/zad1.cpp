/* prvi zadatak - bresenhamov postupak

g++ zad1.cpp -lglut -lGLU -o zad1 && ./zad1

*/


#include <GL/glut.h>
#include <iostream>
#include <vector>

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

struct line {
	int x0;
	int y0;
	int x1;
	int y1;
	color c;	
};

bool drugaTocka = false;
color curr = { 0.0f, 0.0f, 0.0f};

vector<line> lines;
line tmpline;

GLuint width = 400;
GLuint height = 400;

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(200,200);
	
	glutCreateWindow("Vjezba 1 - linije");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);

	glutMainLoop();
}


void drawLineGL(line l) {
	glColor3f(l.c.r, l.c.g, l.c.b);
	glBegin(GL_LINES);
		glVertex2i(l.x0,l.y0+20);
		glVertex2i(l.x1,l.y1+20);
	glEnd();
}

void bresenham1(int xs, int ys, int xe, int ye) {
	int x, yc, korr;
	int a, yf;
	
	if (ye - ys <= xe - xs) {
		a = 2*(ye - ys);
		yc = ys; yf = -(xe - xs); korr = - 2*(xe-xs);
		glBegin(GL_POINTS);
		for (x = xs; x <= xe; x++) {
			glVertex2i(x,yc);
			yf = yf + a;
			if (yf > 0) {
				yf = yf + korr;
				yc = yc + 1;
			}
		}
		glEnd();
	} else {
		x = xe; xe = ye; ye = x;
		x = xs; xs = ys; ys = x;
		
		a = 2*(ye - ys);
		yc = ys; yf = - (xe - xs); korr = -2 *(xe - xs);
		glBegin(GL_POINTS);
		for (x = xs; x <= xe; x++) {
			glVertex2i(yc,x);
			yf = yf + a;
			if(yf > 0) {
				yf = yf + korr;
				yc = yc + 1;
			}
		}
		glEnd();
	}

}

void bresenham2(int xs, int ys, int xe, int ye) {
	int x, yc, korr;
	int a, yf;
	
	if ( -(ye-ys) <= (xe-xs)) {
		a = 2*(ye - ys);
		yc = ys; yf = (xe - xs); korr = 2*(xe - xs);
		glBegin(GL_POINTS);
		for(x = xs; x <= xe; x++) {
			glVertex2i(x,yc);
			yf = yf + a;
			if (yf <= 0) {
				yf = yf + korr;
				yc = yc - 1;
			}
		}
		glEnd();
	} else {
		x = xe; xe = ys; ys = x;
		x = xs; xs = ye; ye = x;
		yc = ys; yf=(xe - xs); korr = 2*(xe - xs);
		a = 2 * (ye - ys);
		glBegin(GL_POINTS);
		for (x = xs; x <= xe; x++) {
			glVertex2i(yc,x);
			yf = yf + a;
			if (yf <= 0) {
				yf = yf + korr;
				yc = yc - 1;
			}
		}
		glEnd();
	}

}

void drawLine(line l) {

	glColor3f(l.c.r, l.c.g, l.c.b);
	if (l.x0 <= l.x1) {
		if ( l.y0 <= l.y1) {
			bresenham1(l.x0, l.y0, l.x1, l.y1);
		} else {
			bresenham2(l.x0, l.y0, l.x1, l.y1);
		}
	} else {
		if (l.y0 >= l.y1) {
 			bresenham1(l.x1, l.y1, l.x0, l.y0);
		} else {
			bresenham2(l.x1, l.y1, l.x0, l.y0);
		}
	}
}

void display() {
	cout << "display() called" << endl;
	
	glClearColor( 1.0f, 1.0f, 1.0f, 0.0f );
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glPointSize(1.0);
			
	vector<line>::iterator ii;
	for (ii = lines.begin(); ii < lines.end(); ++ii) {
		drawLine(*ii);
		drawLineGL(*ii);
	}

	glColor3f(curr.r, curr.g, curr.b);	
	glRecti(width-15, height-15, width, height);	// crta kvadrat inicijalne boje
	
	glutSwapBuffers();
}

void reshape(int w, int h) {
	cout << "reshape("<< width <<","<< height<<") called" << endl;
	width = w;
	height = h;

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width-1, 0, height-1);
	glMatrixMode(GL_MODELVIEW);

}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
		case 'r' : curr.r = 1.0f; curr.g = 0.0f; curr.b = 0.0f; cout << "red"   << endl; break;
		case 'g' : curr.r = 0.0f; curr.g = 1.0f; curr.b = 0.0f; cout << "green" << endl; break;
		case 'b' : curr.r = 0.0f; curr.g = 0.0f; curr.b = 1.0f; cout << "blue"  << endl; break;
		case 'k' : curr.r = 0.0f; curr.g = 0.0f; curr.b = 0.0f; cout << "black" << endl; break;	
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		cout << "clicked at ("<< x << "," << y << ") - ";
		if (!drugaTocka) {
			cout << "prva tocka" << endl;
			drugaTocka = true;
			tmpline.x0 = x;
			tmpline.y0 = height - y;
		} else {
			cout << "druga tocka" << endl;
			drugaTocka = false;
			tmpline.x1 = x;
			tmpline.y1 = height - y;
			tmpline.c = curr;
			lines.push_back(tmpline);
			glutPostRedisplay();
		}
	} else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		lines.clear();
		glutPostRedisplay();
	}
}

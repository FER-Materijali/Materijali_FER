/* drugi zadatak - crtanje i popunjavanje konveksnog poligona

g++ zad2.cpp -lglut -lGLU -o zad2 && ./zad2

*/


#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <unistd.h>

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

struct vertex {
	int x;
	int y;
};

struct edge {
	int a;
	int b;
	int c;
	bool lijevi;
};

struct tip {
	bool konv; // konveksan
	bool cw;  // counter clockwise
};

bool drugaTocka = false;
color curr = { 0.0f, 0.0f, 0.0f};

vector<line> lines;
//line tmpline;

vector<vertex> v;
vector<edge> e;

vertex tocka = {-1, -1};

GLuint width = 400;
GLuint height = 400;

int main(int argc, char *argv[]) {
	cout << "Lijevim clickom crta se poligon. Desnim clickom se zadaje tocka ciji se polozaj provjerava u odnosu na poligon."<< endl;
	cout << "Tipkom c brise se zadnji vrh poligona, a tipkama r, g, b i k se biraju boje poligona." << endl << endl;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(200,200);
	
	glutCreateWindow("Vjezba 2 - poligoni");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);

	glutMainLoop();
}


void drawLineGL(line l) {
	glColor3f(l.c.r, l.c.g, l.c.b);
	glBegin(GL_LINES);
		glVertex2i(l.x0,l.y0);
		glVertex2i(l.x1,l.y1);
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

void crtajKonveksniPoligon(void) {
	int i, i0;
	i0 = v.size()-1;
	
//	cout << "ctam poligon" << endl;
	
	for (i = 0; i < v.size(); i++) {
		line tmp;
		tmp.x0 = v.at(i0).x;
		tmp.y0 = v.at(i0).y;
		tmp.x1 = v.at(i).x;
		tmp.y1 = v.at(i).y;
		tmp.c = curr;
		drawLine(tmp);
		i0 = i;
	}
}

void computePolyCoeff(void) {
	int i, i0;
	
	e.clear();
	
	i0 = v.size()-1;
	for ( i = 0; i < v.size(); i++) {
		edge tmp;
		tmp.a = v.at(i0).y - v.at(i).y;
		if (tmp.a == 0) 
			cout << "DEKLARIRAM u " << e.size() << " a = 0 za i0 = " << i0 << "i = "<< i << " "<< v.at(i0).y << " " << v.at(i).y << endl;
		tmp.b = -(v.at(i0).x - v.at(i).x);
		tmp.c = v.at(i0).x * v.at(i).y - v.at(i0).y * v.at(i).x;
		tmp.lijevi = (v.at(i0).y < v.at(i).y);
		e.push_back(tmp);
		i0 = i;
	}
}

void popuniKonvPol(bool cw) {
	int i, i0, y;
	int xmin, xmax, ymin, ymax;
	double L, D, x;
	
	xmin = xmax = v.at(0).x;
	ymin = ymax = v.at(0).y;
	
//	cout << "imam " << v.size() << endl;
	for(i = 1; i < v.size(); i++) {
		if ( xmin > v.at(i).x ) xmin = v.at(i).x;
		if ( xmax < v.at(i).x ) xmax = v.at(i).x;
		if ( ymin > v.at(i).y ) ymin = v.at(i).y;
		if ( ymax < v.at(i).y ) ymax = v.at(i).y;
	}

//	cout << "xmin "	<< xmin << "xmax " << xmax << "ymin " << ymin << "ymax" << ymax << endl;
	for (y = ymin; y <= ymax; y++) {
		L = xmin; D = xmax;
		i0 = v.size() -1;
		
		// i0 - pocetak brida, i - kraj brida
//		cout << "===========" << endl;
		for (i = 0; i < v.size(); i0 = i++) {
			//cout << "i0 = " << i0 << " i = " << i << endl;
			if (e.at(i).a == 0) {// brid vodoravan
				if(v.at(i).y == y) {
				//	cout << "** vodoravni su " << "i0 = " << i0 << "i = "<< i << " "<< v.at(i0).y << " " << v.at(i).y << endl;
				/*	cout << "----" << endl;
					for(int w = 0; w < e.size(); w++) {
						cout << "b("<< w << ")="<<e.at(w).a<< endl;;
					}
					cout << "----" << endl;
*/					if (v.at(i0).x >= v.at(i).x) {
						L = v.at(i0).x;
						D = v.at(i).x;
					} else {
						L = v.at(i).x;
						D = v.at(i0).x;
					}
					// ===============
				//	cout << "L = " << L << " D = " << D << " i0= " << i0 << " i = " << i << endl;
					break;
				}
			} else { // normalan brid
				x = (-e.at(i).b * y - e.at(i).c)/ (double) e.at(i).a;
				bool tmp = e.at(i).lijevi;
				if (!cw)
					tmp = !tmp;
				if ( tmp ) {
					if (L < x) L = x;
				} else {
					if (D > x) D = x;
				}
			}
		}
		line tmp;
		tmp.x0 = (int) (L+0.5);
		tmp.y0 = y;
		tmp.x1 = (int) (D+0.5);
		tmp.y1 = y;
		tmp.c = curr;
		drawLine(tmp);
//		glutSwapBuffers();
//		usleep(50*1000);
	}
}


tip odreditip(void) {
	int i, i0, r;
	int iznad, ispod, na;
	
	ispod = iznad = na = 0;
	i0 = v.size() - 1;
	for (i = 0; i < v.size(); i++, i0++) {
		if (i0 >= v.size()) i0 = 0; // MORA BITI -1!!!
		//cout << "i = " << i << "  i0 = " << i0 << endl;		
		r = e.at(i0).a * v.at(i).x + e.at(i0).b * v.at(i).y + e.at(i0).c;
		//cout << "r=" << r << " " << e.at(i0).a << " " << v.at(i).x << " " << e.at(i0).b  << " " << v.at(i).y << " " << e.at(i0).c << endl;
	//	cout << "size e = " << e.size() << " v = " << v.size() << endl;
		if (r == 0) na++;
		else if (r > 0) iznad++;
		else ispod++;
	}
	
	
//	cout << "ispod = " << ispod << " iznad = " << iznad << " na = " << na << endl;
	tip tmp;
	tmp.konv = false;
	tmp.cw = false;
	if (ispod == 0) {
		//cout << "konkavno1" << endl;
		tmp.konv = true;
	} else if (iznad == 0) {
		//cout << "konkavno2" << endl;
		tmp.konv = true;
		tmp.cw = true;
	}
	return tmp;
}

void display() {
	cout << "display() called" << endl;
	
	glClearColor( 1.0f, 1.0f, 1.0f, 0.0f );
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
			
	vector<vertex>::iterator ii;

	glColor3f(curr.r, curr.g, curr.b);

	// oznacavano tocke di je clicknuto
	glPointSize(4.0);	
	glBegin(GL_POINTS);
	for (ii = v.begin(); ii < v.end(); ii++) {
		glVertex2i((*ii).x, (*ii).y);
	}
	glEnd();
	
	
	// crtamo poligon
	bool konveksni = true;
	bool cw;
	glPointSize(1.0);
	if (v.size() > 2 ) {
		crtajKonveksniPoligon();
		computePolyCoeff();
		tip poly = odreditip();
		cw = poly.cw;
		if (poly.konv) {
			popuniKonvPol(poly.cw);
			if (poly.cw) {
				cout << "Crtano CW" << endl;
			} else {
				cout << "Crtano CCW" << endl;
			}
		} else {
			konveksni = false;
			cout << "** Nacrtan je konkavni poligon, ispravite brisanjem sa tipkom c." << endl;
		}
	}
	if (tocka.x >= 0 && tocka.y >= 0) {
		// cout << "cwtam tocku u " << tocka.x << " " << tocka.y << endl;
		glPointSize(4.0);
		glColor3f(0.0f, 0.0f, 0.0f);;
		glBegin(GL_POINTS);
			glVertex2i(tocka.x, tocka.y);
		glEnd();
		glPointSize(2.0);
		glColor3f(1.0f, 1.0f, 1.0f);;
		glBegin(GL_POINTS);
			glVertex2i(tocka.x, tocka.y);
		glEnd();
		
		if (v.size() > 2 && konveksni) { 
			bool unutra = true;
			for (int i = 0; i < e.size(); i++ ) {
				if ( (cw && tocka.x * e.at(i).a + tocka.y * e.at(i).b + e.at(i).c > 0) ||
				     (!cw && tocka.x * e.at(i).a + tocka.y * e.at(i).b + e.at(i).c < 0) ) {
					unutra = false;
					break;
				}
			}
			if (unutra) {
				cout << "Tocka je unutar poligona" << endl;
			} else {
				cout << "Tocka je izvan poligona" << endl;
			}
		}

	}
	
//	glRecti(width-15, height-15, width, height);
	
	glutSwapBuffers();
	cout << endl;
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
		case 'c' : if (v.size() > 0 ) {
					cout << "brisem zadnji vrh" << endl;
					v.pop_back();
				}
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		cout << "clicked at ("<< x << "," << height-y << ")" << endl;
		vertex tmp;
		tmp.x = x;
		tmp.y = height-y;
		v.push_back(tmp);
		glutPostRedisplay();		
	} else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)  {
		cout << "Tocka u ("<< x << "," << height-y << ")" << endl;
		tocka.x = x;
		tocka.y = height-y;
		glutPostRedisplay();		
	}
}

// g++ 002.cpp -lglut -lGLU -o 002 && ./002 frog.obj

#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <math.h>
#include <float.h>

using namespace std;

struct point {
	double x;
	double y;
	double z;
	double h;
};

struct poly {
	int p1, p2, p3;
	double A, B, C, D;
};

point O = {15.0, 15.0, 15.0, 1.0};
point G = {0.0, 0.0, 2.0, 1.0};

void reshape(int width, int height);
void display();
void draw();

GLuint width = 800;
GLuint height = 600;

double T1[4][4], T2[4][4], T3[4][4], T4[4][4], T5[4][4];
double T[4][4], P[4][4], Tmp[4][4], I[4][4];

vector<point> vrh;
vector<poly> poligoni;

vector<string> split(const string& s, const string& delim, const bool keep_empty = true) {
    vector<string> result;
    if (delim.empty()) {
        result.push_back(s);
        return result;
    }
    string::const_iterator substart = s.begin(), subend;
    while (true) {
        subend = search(substart, s.end(), delim.begin(), delim.end());
        string temp(substart, subend);
        if (keep_empty || !temp.empty()) {
            result.push_back(temp);
        }
        if (subend == s.end()) {
            break;
        }
        substart = subend + delim.size();
    }
    return result;
}

void mprint( double A[4][4]) {
	for (int j = 0; j <= 3; j++) {
		for (int i = 0; i <= 3; i++) {
			cout << A[j][i] << "\t ";
		}
		cout << endl;
	}
	cout << endl;
}

void mull(double A[4][4], double B[4][4], double C[4][4] ) {
	for (int j = 0; j <= 3; j++) {
		for (int i = 0; i <= 3; i++) {
			C[j][i] = 0;	
			for (int n = 0; n <= 3; n++) {
				C[j][i] += A[j][n] * B[n][i];
			}
		}
	}
}

void pprint(point T) {
	cout << "(" << T.x << ", " << T.y << ", " << T.z << ", " << T.h << ")" << endl;
}
point trans(point T, double M[4][4]) {
	point t2;
	t2.x = T.x * M[0][0] + T.y * M[1][0] + T.z * M[2][0] + T.h * M[3][0];
	t2.y = T.x * M[0][1] + T.y * M[1][1] + T.z * M[2][1] + T.h * M[3][1];
	t2.z = T.x * M[0][2] + T.y * M[1][2] + T.z * M[2][2] + T.h * M[3][2];
	t2.h = T.x * M[0][3] + T.y * M[1][3] + T.z * M[2][3] + T.h * M[3][3];

	if (t2.h != 1 && t2.h != 0) {
		t2.x = t2.x / t2.h;
		t2.y = t2.y / t2.h;
		t2.z = t2.z / t2.h;
		t2.h = 1;
	}
	return t2;
}

int main(int argc, char *argv[]) {
	
	
	// ========= ucitavanje datoteke =========
	string line;
	ifstream myfile (argv[1]);
	double xmin = DBL_MAX, xmax = -DBL_MAX, ymin = DBL_MAX, ymax = -DBL_MAX, zmin = DBL_MAX, zmax = -DBL_MAX;
  	if (myfile.is_open()) {
		while ( myfile.good()) {
			getline (myfile,line);
			vector<string> tmp;
			tmp = split(line, " ");
			if (tmp[0] == "#") {
					// cout << "komentar" << endl;
			} else if (tmp[0] == "g") {
					// cout << "ime " << tmp[1] << endl;
			} else if (tmp[0] == "v") {
					//cout << "vrhovi " << tmp[1] << " " << tmp[2] << " " << tmp[3] << endl;
					point v;
					v.x = strtod(tmp[1].c_str(), NULL);
					v.y = strtod(tmp[2].c_str(), NULL);	
					v.z = strtod(tmp[3].c_str(), NULL);
					v.h = 1.0;
					vrh.push_back(v);
					
					if (v.x < xmin) xmin = v.x;
					if (v.x > xmax) xmax = v.x;
					if (v.y < ymin) ymin = v.y;
					if (v.y > ymax) ymax = v.y;
					if (v.z < zmin) zmin = v.z;
					if (v.z > zmax) zmax = v.z;				
			} else if (tmp[0] == "f") {
					poly p;
					p.p1 = atoi(tmp[1].c_str());
					p.p2 = atoi(tmp[2].c_str());
					p.p3 = atoi(tmp[3].c_str());
					poligoni.push_back(p);
			} else {
					
			}
//			cout << line << endl;
		}
    	myfile.close();
    	cout << "Ucitano " << vrh.size() << " vrhova i " << poligoni.size() << " poligona"<< endl;
    	cout << "Tjelo se prostire: x = " << xmin << " do " << xmax << ", y = " << ymin << " do " << ymax << ", z = " << zmin << " do " << zmax << endl;
    	cout << "Unesite koordinate ocista: ";
    	cin >> O.x >> O.y >> O.z; O.h = 1;
    	cout << "Unesite koordinate gledista: ";
    	cin >> G.x >> G.y >> G.z; G.h = 1;
	 } else  {
	 	cout << "Unable to open file" << endl;
	 	return -1;
	 }

	// T1, pomak ishodista u O
	T1[0][0] = 1;    T1[0][1] = 0;    T1[0][2] = 0;    T1[0][3] = 0;
	T1[1][0] = 0;    T1[1][1] = 1;    T1[1][2] = 0;    T1[1][3] = 0;
	T1[2][0] = 0;    T1[2][1] = 0;    T1[2][2] = 1;    T1[2][3] = 0;
	T1[3][0] = -O.x; T1[3][1] = -O.y; T1[3][2] = -O.z; T1[3][3] = 1;
	
	point G1 = {G.x - O.x, G.y - O.y, G.z - O.z, 1.0};
		
	//T2, rotacija za kut alpha oko z osi
	point G2;
	if (G1.x != 0 || G1.y != 0) {
		double sina = G1.y / sqrt(pow(G1.x,2) + pow(G1.y,2));
		double cosa = G1.x / sqrt(pow(G1.x,2) + pow(G1.y,2));
		T2[0][0] = cosa; T2[0][1] = -sina; T2[0][2] = 0;    T2[0][3] = 0;
		T2[1][0] = sina; T2[1][1] = cosa;  T2[1][2] = 0;    T2[1][3] = 0;
		T2[2][0] = 0;    T2[2][1] = 0;     T2[2][2] = 1;    T2[2][3] = 0;
		T2[3][0] = 0;    T2[3][1] = 0;     T2[3][2] = 0;    T2[3][3] = 1;	
	
		G2.x = sqrt(pow(G1.x,2) + pow(G1.y,2)); G2.y =  0; G2.z =  G1.z; G2.h = 1.0;
	} else {
		T2[0][0] = 1;   T2[0][1] = 0;   T2[0][2] = 0;  T2[0][3] = 0;
		T2[1][0] = 0;   T2[1][1] = 1;   T2[1][2] = 0;  T2[1][3] = 0;
		T2[2][0] = 0;   T2[2][1] = 0;   T2[2][2] = 1;  T2[2][3] = 0;
		T2[3][0] = 0;   T2[3][1] = 0;   T2[3][2] = 0;  T2[3][3] = 1;			
		
		G2.x = G1.x;
		G2.y = G1.y;
		G2.z = G1.z;
		G2.h = G1.h;
	}
	
	// T3 rotacija za kut beta oko y osi
	point G3;
	if (G1.x != 0 || G1.z != 0) {	
		double sinb = G2.x / sqrt(pow(G2.x,2) + pow(G2.z,2));
		double cosb = G2.z / sqrt(pow(G2.x,2) + pow(G2.z,2));
		T3[0][0] = cosb;  T3[0][1] = 0;     T3[0][2] = sinb; T3[0][3] = 0;
		T3[1][0] = 0;     T3[1][1] = 1;     T3[1][2] = 0;    T3[1][3] = 0;
		T3[2][0] = -sinb; T3[2][1] = 0;     T3[2][2] = cosb; T3[2][3] = 0;
		T3[3][0] = 0;     T3[3][1] = 0;     T3[3][2] = 0;    T3[3][3] = 1;

		G3.x = 0; G3.y =  0; G3.z = sqrt(pow(G2.x,2) + pow(G2.z,2)); G3.h = 1.0;
		
	} else {
		T3[0][0] = 1;   T3[0][1] = 0;   T3[0][2] = 0;  T3[0][3] = 0;
		T3[1][0] = 0;   T3[1][1] = 1;   T3[1][2] = 0;  T3[1][3] = 0;
		T3[2][0] = 0;   T3[2][1] = 0;   T3[2][2] = 1;  T3[2][3] = 0;
		T3[3][0] = 0;   T3[3][1] = 0;   T3[3][2] = 0;  T3[3][3] = 1;			
		
		G3.x = G2.x;
		G3.y = G2.y;
		G3.z = G2.z;
		G3.h = G2.h;	
	}
	
	// T4 rotacija za kut 90° oko z osi
	T4[0][0] = 0;   T4[0][1] = -1;  T4[0][2] = 0;  T4[0][3] = 0;
	T4[1][0] = 1;   T4[1][1] = 0;   T4[1][2] = 0;  T4[1][3] = 0;
	T4[2][0] = 0;   T4[2][1] = 0;   T4[2][2] = 1;  T4[2][3] = 0;
	T4[3][0] = 0;   T4[3][1] = 0;   T4[3][2] = 0;  T4[3][3] = 1;
	
	// T5 promjena predznaka na x osi
	T5[0][0] = -1;  T5[0][1] = 0;   T5[0][2] = 0;  T5[0][3] = 0;
	T5[1][0] = 0;   T5[1][1] = 1;   T5[1][2] = 0;  T5[1][3] = 0;
	T5[2][0] = 0;   T5[2][1] = 0;   T5[2][2] = 1;  T5[2][3] = 0;
	T5[3][0] = 0;   T5[3][1] = 0;   T5[3][2] = 0;  T5[3][3] = 1;

	// jedinicna matrica
	I[0][0] = 1;   I[0][1] = 0;   I[0][2] = 0;  I[0][3] = 0;
	I[1][0] = 0;   I[1][1] = 1;   I[1][2] = 0;  I[1][3] = 0;
	I[2][0] = 0;   I[2][1] = 0;   I[2][2] = 1;  I[2][3] = 0;
	I[3][0] = 0;   I[3][1] = 0;   I[3][2] = 0;  I[3][3] = 1;	

	// Generiranje Matrice T
	mull(T1, T2, Tmp);
	mull(Tmp, T3, T);
	mull(T, T4, Tmp);
	mull(Tmp, T5, T);
	
	// matrica projekcije P
	P[0][0] = 1;   P[0][1] = 0;   P[0][2] = 0;  P[0][3] = 0;
	P[1][0] = 0;   P[1][1] = 1;   P[1][2] = 0;  P[1][3] = 0;
	P[2][0] = 0;   P[2][1] = 0;   P[2][2] = 0;  P[2][3] = 1/G3.z;
	P[3][0] = 0;   P[3][1] = 0;   P[3][2] = 0;  P[3][3] = 0;
	
//	cout << "H = " << G3.z << endl;

	
	// ========= transformacije vrhova =========
	vector<point>::iterator it;
	for(it = vrh.begin(); it < vrh.end(); it++) {
		(*it) = trans((*it), T);
		(*it) = trans((*it), P);
//		pprint(*it);
	}
	  	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(50,50);
	
	glutCreateWindow("Vjezba 5 - Trans. pogleda i Pers. Projekcija");

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

	glColor3f(0.0f, 0.0f, 0.0f);

	vector<poly>::iterator it;
	for(it = poligoni.begin(); it < poligoni.end(); it++) {
		glBegin(GL_LINE_LOOP);
		glVertex2f(vrh[(*it).p1-1].x, vrh[(*it).p1-1].y);
		glVertex2f(vrh[(*it).p2-1].x, vrh[(*it).p2-1].y);
		glVertex2f(vrh[(*it).p3-1].x, vrh[(*it).p3-1].y);
		glEnd();
	}
	
	//glutSwapBuffers();
	glFlush();
}

void reshape(int w, int h) {
	cout << "reshape("<< width <<","<< height<<") called" << endl;
	width = w;
	height = h;

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	gluOrtho2D(0, width-1, 0, height);
//	gluOrtho2D(0, width-1, height, 0);
	//gluOrtho2D(-1, 1, 1, -1);
	gluOrtho2D(-1, 1, 1, -1);
	glMatrixMode(GL_MODELVIEW);

}

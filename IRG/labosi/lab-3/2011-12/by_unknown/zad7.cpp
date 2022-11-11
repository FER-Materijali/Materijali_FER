// g++ zad7.cpp -lglut -lGLU -o zad7 && ./zad7 dragon.obj putanja.txt

#include <stdio.h>
#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <float.h>

using namespace std;

struct point {
	double x;
	double y;
	double z;
	double h;
	double sumx, sumy, sumz;
	double n;
	double Nx, Ny, Nz;
};

struct poly {
	int p1, p2, p3;
	double A, B, C, D;
	double cx, cy, cz; // koordinate centra (tezista)
};

vector<point> vrh;
vector<poly> poligoni;

vector<point> bezVrh;

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

int fact(int factorialParameter){ 
 int answer = 1, current = 1;  
  while (current <= factorialParameter) {
    answer *= current;
    current++;
  }
  return answer; 
}


// obavlja transformaciju T nad tockom M
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

void pprint(point T) {
	cout << "(" << T.x << ", " << T.y << ", " << T.z << ", " << T.h << ")" << endl;
}

void updatePerspective();


//*********************************************************************************
//	Pokazivac na glavni prozor i pocetna velicina.
//*********************************************************************************

GLuint window; 
GLuint width = 600, height = 600;

typedef struct _Ociste {
	GLdouble	x;
	GLdouble	y;
	GLdouble	z;
} Ociste;


Ociste	ociste = {0, 0 ,5.0};
Ociste  izvor =  {0, 0, 5.0};

bool animacija = false;
double T = 0;
double step = 0.01;
//*********************************************************************************
//	Function Prototypes.
//*********************************************************************************

void myDisplay		();
void myReshape		(int width, int height);
void myMouse		(int button, int state, int x, int y);
void myKeyboard		(unsigned char theKey, int mouseX, int mouseY);
void myObject		();
void redisplay_all	(void);


//*********************************************************************************
//	Glavni program.
//*********************************************************************************

int main(int argc, char** argv)
{

	// ========= ucitavanje datoteke =========
	string line;
	ifstream myfile (argv[1]);
	double xmin = DBL_MAX, xmax = -DBL_MAX, ymin = DBL_MAX, ymax = -DBL_MAX, zmin = DBL_MAX, zmax = -DBL_MAX;
	double velicina_x, velicina_y, velicina_z;
	double srediste_x, srediste_y, srediste_z;
	double velicina_max, scale;
	double T1[4][4], T2[4][4];
	
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
					v.sumx = v.sumy = v.sumz = v.n = 0;
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
    } else  {
		cout << "Unable to open file" << endl;
		return -1;
	}
    cout << "Ucitano " << vrh.size() << " vrhova i " << poligoni.size() << " poligona"<< endl;
    cout << "Tjelo se prostire: x = " << xmin << " do " << xmax << ", y = " << ymin << " do " << ymax << ", z = " << zmin << " do " << zmax << endl;
    
    velicina_x = xmax - xmin;
    velicina_y = ymax - ymin;
    velicina_z = zmax - zmin;
    
    velicina_max = velicina_x;
	if (velicina_y > velicina_max) velicina_max = velicina_y;
	if (velicina_z > velicina_max) velicina_max = velicina_z;
	
	scale = 2/velicina_max;
	cout << "scale = " << scale << endl;
	
    srediste_x = (xmax + xmin)/2;
    srediste_y = (ymax + ymin)/2;
    srediste_z = (zmax + zmin)/2;
    
	// T1 - pomak
	T1[0][0] = 1;           T1[0][1] = 0;           T1[0][2] = 0;           T1[0][3] = 0;
	T1[1][0] = 0;           T1[1][1] = 1;           T1[1][2] = 0;           T1[1][3] = 0;
	T1[2][0] = 0;           T1[2][1] = 0;           T1[2][2] = 1;           T1[2][3] = 0;
	T1[3][0] = -srediste_x; T1[3][1] = -srediste_y; T1[3][2] = -srediste_z; T1[3][3] = 1;
	
	// T2 - skaliranje za 2/max
	T2[0][0] = scale;       T2[0][1] = 0;           T2[0][2] = 0;           T2[0][3] = 0;
	T2[1][0] = 0;           T2[1][1] = scale;       T2[1][2] = 0;           T2[1][3] = 0;
	T2[2][0] = 0;           T2[2][1] = 0;           T2[2][2] = scale;       T2[2][3] = 0;
	T2[3][0] = 0;           T2[3][1] = 0;           T2[3][2] = 0;           T2[3][3] = 1;    	
    
    // ========= transformacije svih vrhova =========
	vector<point>::iterator itv;
	for(itv = vrh.begin(); itv < vrh.end(); itv++) {
		(*itv) = trans((*itv), T1);
		(*itv) = trans((*itv), T2);
		//pprint(*it);
	}
	
	// ========= racunanje koeficijanata bridova ======
	vector<poly>::iterator it;
	for(it = poligoni.begin(); it < poligoni.end(); it++) {

	 	(*it).A = (vrh[(*it).p2-1].y - vrh[(*it).p1-1].y) * 
	 	          (vrh[(*it).p3-1].z - vrh[(*it).p1-1].z) -
	 	          
	 	          (vrh[(*it).p2-1].z - vrh[(*it).p1-1].z) *
	 	          (vrh[(*it).p3-1].y - vrh[(*it).p1-1].y) ;

	 	(*it).B = (-1)*(vrh[(*it).p2-1].x - vrh[(*it).p1-1].x) * 
	 	               (vrh[(*it).p3-1].z - vrh[(*it).p1-1].z) +
	 	          
	 	               (vrh[(*it).p2-1].z - vrh[(*it).p1-1].z) *
	 	               (vrh[(*it).p3-1].x - vrh[(*it).p1-1].x) ;

	 	(*it).C = (vrh[(*it).p2-1].x - vrh[(*it).p1-1].x) * 
	 	          (vrh[(*it).p3-1].y - vrh[(*it).p1-1].y) -
	 	          
	 	          (vrh[(*it).p2-1].y - vrh[(*it).p1-1].y) *
	 	          (vrh[(*it).p3-1].x - vrh[(*it).p1-1].x) ;
	 	
	 	(*it).D = -vrh[(*it).p1-1].x * (*it).A
	 	          -vrh[(*it).p1-1].y * (*it).B
	 	          -vrh[(*it).p1-1].z * (*it).C;
		(*it).cx = (vrh[(*it).p1].x + vrh[(*it).p2].x + vrh[(*it).p3].x) / 3;
		(*it).cy = (vrh[(*it).p1].y + vrh[(*it).p2].y + vrh[(*it).p3].y) / 3;
		(*it).cz = (vrh[(*it).p1].z + vrh[(*it).p2].z + vrh[(*it).p3].z) / 3;
	}
	
	// ========= racunanje normala vrhova ======
	for(it = poligoni.begin(); it < poligoni.end(); it++) {
		vrh[(*it).p1-1].n++;
		vrh[(*it).p1-1].sumx += (*it).A;
		vrh[(*it).p1-1].sumy += (*it).B;
		vrh[(*it).p1-1].sumz += (*it).C;		

		vrh[(*it).p2-1].n++;
		vrh[(*it).p2-1].sumx += (*it).A;
		vrh[(*it).p2-1].sumy += (*it).B;
		vrh[(*it).p2-1].sumz += (*it).C;

		vrh[(*it).p3-1].n++;
		vrh[(*it).p3-1].sumx += (*it).A;
		vrh[(*it).p3-1].sumy += (*it).B;
		vrh[(*it).p3-1].sumz += (*it).C;
	}
	
// ======================= ucitavanje krivulje bezijera ====================
	ifstream myfile2 (argv[2]);
		
  	if (myfile2.is_open()) {
		while ( myfile2.good()) {
			getline (myfile2,line);
			//cout << "-" << line << "-" << endl;
			if (line != "") {
				vector<string> tmp = split(line, " ");
				point v;
				v.x = strtod(tmp[0].c_str(), NULL);
				v.y = strtod(tmp[1].c_str(), NULL);	
				v.z = strtod(tmp[2].c_str(), NULL);
				v.h = 1.0;
				v.sumx = v.sumy = v.sumz = v.n = 0;
				bezVrh.push_back(v);	
			}
		}
    	myfile2.close();
    } else  {
		cout << "Unable to open file (putanja)" << endl;
		return -1;
	}	
	
	// postavljanje dvostrukog spremnika za prikaz (zbog titranja)
	glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize (width, height); 
	glutInitWindowPosition (100, 100);
	glutInit(&argc, argv);
   
   	glEnable(GL_DEPTH_TEST);
   	
	window = glutCreateWindow ("Tijelo");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(myDisplay);
	glutMouseFunc(myMouse);
	glutKeyboardFunc(myKeyboard);
	printf("Tipka: l - pomicanje ocista po x os +\n");
	printf("Tipka: k - pomicanje ocista po x os -\n");
	printf("Tipka: r - pocetno stanje\n");
	printf("esc: izlaz iz programa\n");

	glutMainLoop();
	return 0;
}


void animate(int value) {
	if (animacija) {
		T += step;
		if (T >= 1) step = -0.01;
		if (T <= 0) step = 0.01;
		
		double x = 0, y = 0, z = 0;
		int n = bezVrh.size()-1;
		int i = 0;
		
		vector<point>::iterator kTocka;
		
		for(kTocka = bezVrh.begin(); kTocka < bezVrh.end(); kTocka++) {
			double b = (fact(n)/(fact(i)*fact(n-i))) * pow(T, i) * pow(1-T, n-i);
			x += (*kTocka).x * b;
			y += (*kTocka).y * b;
			z += (*kTocka).z * b;
			i++;
		}
		ociste.x = x;
		ociste.y = y;
		ociste.z = z;
		
		updatePerspective();
		glutPostRedisplay();
		glutTimerFunc(20, animate, 0);
	}
}

//*********************************************************************************
//	Osvjezavanje prikaza. 
//*********************************************************************************

void myDisplay(void)
{
	// printf("Pozvan myDisplay()\n");
	glClearColor( 1.0f, 1.0f, 1.0f, 1.0f);		         // boja pozadine - bijela
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
	// printf("MR: width=%d, height=%d\n",w,h);
	width=w; height=h;
	glViewport (0, 0, width, height);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode (GL_PROJECTION);        // aktivirana matrica projekcije
	glLoadIdentity ();
	gluPerspective(45.0, (float)width/height, 0.5, 8.0); // kut pogleda, x/y, prednja i straznja ravnina odsjecanja
	gluLookAt (ociste.x, ociste.y, ociste.z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);	// ociste x,y,z; glediste x,y,z; up vektor x,y,z
	glMatrixMode (GL_MODELVIEW);         // aktivirana matrica modela
}

void updatePerspective()
{
	glMatrixMode (GL_PROJECTION);        // aktivirana matrica projekcije
	glLoadIdentity ();
	gluPerspective(45.0, (float)width/height, 0.5, 8.0); // kut pogleda, x/y, prednja i straznja ravnina odsjecanja
	gluLookAt (ociste.x, ociste.y, ociste.z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);	// ociste x,y,z; glediste x,y,z; up vektor x,y,z
	glMatrixMode (GL_MODELVIEW);         // aktivirana matrica modela
}

//*********************************************************************************
//	Crta moj objekt. Ovdje treba naciniti prikaz ucitanog objekta.
//*********************************************************************************

void myObject ()
{
	// ambijentalna komponenta
	double Ia = 100;
	double ka = 0.5;
	
	// difuzna komponenta
	double Ii = 200;
	double kd = 0.8;
	
	double Nx, Ny, Nz, Nn;
	double Lx, Ly, Lz, Ln;
	
	vector<poly>::iterator it;
	for(it = poligoni.begin(); it < poligoni.end(); it++) {
		// kut izmedju ocista i normale
		double cos = (*it).A * ociste.x + (*it).B * ociste.y + (*it).C * ociste.z + (*it).D;
		
		if(cos > 0) {
/*
// -------- wireframe prikaz --------
                        glBegin(GL_LINE_LOOP);
                        glColor3ub(255, 0, 0);
                        glVertex3f(vrh[(*it).p1-1].x, vrh[(*it).p1-1].y, vrh[(*it).p1-1].z);
                        glVertex3f(vrh[(*it).p2-1].x, vrh[(*it).p2-1].y, vrh[(*it).p2-1].z);
                        glVertex3f(vrh[(*it).p3-1].x, vrh[(*it).p3-1].y, vrh[(*it).p3-1].z);
                        glEnd();
 */

/*
// ------- prikaz konstantnim sjencanjem
			// normalizacija normale na povrsinu
			Nn = sqrt(pow((*it).A,2) + pow((*it).B,2) + pow((*it).C,2));
			Nx = (*it).A / Nn;
			Ny = (*it).B / Nn;
			Nz = (*it).C / Nn;
		
			// odredjivanje normiranog vektora prema izvoru
			Lx = izvor.x - (*it).cx;
			Ly = izvor.y - (*it).cy;
			Lz = izvor.z - (*it).cz;
			Ln = sqrt(pow(Lx,2) + pow(Ly,2) + pow(Lz,2));
			Lx = Lx / Ln;
			Ly = Ly / Ln;
			Lz = Lz / Ln;
		
			double LN = Lx*Nx + Ly*Ny + Lz*Nz;

			double dif = Ii*kd*LN; // difuzna komponenta
			if (dif < 0) dif = 0;
			double I = Ia*ka + dif;

			glBegin (GL_TRIANGLES);
			glColor3ub(I, 0, 0); 
			glVertex3f(vrh[(*it).p1-1].x, vrh[(*it).p1-1].y, vrh[(*it).p1-1].z);
			glVertex3f(vrh[(*it).p2-1].x, vrh[(*it).p2-1].y, vrh[(*it).p2-1].z);
			glVertex3f(vrh[(*it).p3-1].x, vrh[(*it).p3-1].y, vrh[(*it).p3-1].z);
			glEnd();
*/
// -- prikaz gauraudovim sjencanjem
		glBegin (GL_TRIANGLES);
		// za 1. vrh
		
			// odredjivanje normale vrha
			vrh[(*it).p1-1].Nx = vrh[(*it).p1-1].sumx / vrh[(*it).p1-1].n;
			vrh[(*it).p1-1].Ny = vrh[(*it).p1-1].sumy / vrh[(*it).p1-1].n;
			vrh[(*it).p1-1].Nz = vrh[(*it).p1-1].sumz / vrh[(*it).p1-1].n;
			
			// normiranje normale
			double norma = sqrt(pow(vrh[(*it).p1-1].Nx,2) + pow(vrh[(*it).p1-1].Ny,2) + pow(vrh[(*it).p1-1].Nz,2));
			vrh[(*it).p1-1].Nx = vrh[(*it).p1-1].Nx / norma;
			vrh[(*it).p1-1].Ny = vrh[(*it).p1-1].Ny / norma;
			vrh[(*it).p1-1].Nz = vrh[(*it).p1-1].Nz / norma;

			// odredjivanje normiranog vektora prema izvoru
			Lx = izvor.x - vrh[(*it).p1-1].x;
			Ly = izvor.y - vrh[(*it).p1-1].y;
			Lz = izvor.z - vrh[(*it).p1-1].z;
			Ln = sqrt(pow(Lx,2) + pow(Ly,2) + pow(Lz,2));
			Lx = Lx / Ln;
			Ly = Ly / Ln;
			Lz = Lz / Ln;
			
			double LN = Lx*vrh[(*it).p1-1].Nx + Ly*vrh[(*it).p1-1].Ny + Lz*vrh[(*it).p1-1].Nz;

			double dif = Ii*kd*LN; // difuzna komponenta
			if (dif < 0) dif = 0;
			double I = Ia*ka + dif;			
			glColor3ub(I, 0, 0); 
			glVertex3f(vrh[(*it).p1-1].x, vrh[(*it).p1-1].y, vrh[(*it).p1-1].z);

		// za 2. vrh
		
			// odredjivanje normale vrha
			vrh[(*it).p2-1].Nx = vrh[(*it).p2-1].sumx / vrh[(*it).p2-1].n;
			vrh[(*it).p2-1].Ny = vrh[(*it).p2-1].sumy / vrh[(*it).p2-1].n;
			vrh[(*it).p2-1].Nz = vrh[(*it).p2-1].sumz / vrh[(*it).p2-1].n;
			
			// normiranje normale
			norma = sqrt(pow(vrh[(*it).p2-1].Nx,2) + pow(vrh[(*it).p2-1].Ny,2) + pow(vrh[(*it).p2-1].Nz,2));
			vrh[(*it).p2-1].Nx = vrh[(*it).p2-1].Nx / norma;
			vrh[(*it).p2-1].Ny = vrh[(*it).p2-1].Ny / norma;
			vrh[(*it).p2-1].Nz = vrh[(*it).p2-1].Nz / norma;

			// odredjivanje normiranog vektora prema izvoru
			Lx = izvor.x - vrh[(*it).p2-1].x;
			Ly = izvor.y - vrh[(*it).p2-1].y;
			Lz = izvor.z - vrh[(*it).p2-1].z;
			Ln = sqrt(pow(Lx,2) + pow(Ly,2) + pow(Lz,2));
			Lx = Lx / Ln;
			Ly = Ly / Ln;
			Lz = Lz / Ln;
			
			LN = Lx*vrh[(*it).p2-1].Nx + Ly*vrh[(*it).p2-1].Ny + Lz*vrh[(*it).p2-1].Nz;
			dif = Ii*kd*LN; // difuzna komponenta
			if (dif < 0) dif = 0;
			I = Ia*ka + dif;			
			glColor3ub(I, 0, 0); 
			glVertex3f(vrh[(*it).p2-1].x, vrh[(*it).p2-1].y, vrh[(*it).p2-1].z);			

		// za 3. vrh
		
			// odredjivanje normale vrha
			vrh[(*it).p3-1].Nx = vrh[(*it).p3-1].sumx / vrh[(*it).p3-1].n;
			vrh[(*it).p3-1].Ny = vrh[(*it).p3-1].sumy / vrh[(*it).p3-1].n;
			vrh[(*it).p3-1].Nz = vrh[(*it).p3-1].sumz / vrh[(*it).p3-1].n;
			
			// normiranje normale
			norma = sqrt(pow(vrh[(*it).p3-1].Nx,2) + pow(vrh[(*it).p3-1].Ny,2) + pow(vrh[(*it).p3-1].Nz,2));
			vrh[(*it).p3-1].Nx = vrh[(*it).p3-1].Nx / norma;
			vrh[(*it).p3-1].Ny = vrh[(*it).p3-1].Ny / norma;
			vrh[(*it).p3-1].Nz = vrh[(*it).p3-1].Nz / norma;

			// odredjivanje normiranog vektora prema izvoru
			Lx = izvor.x - vrh[(*it).p3-1].x;
			Ly = izvor.y - vrh[(*it).p3-1].y;
			Lz = izvor.z - vrh[(*it).p3-1].z;
			Ln = sqrt(pow(Lx,2) + pow(Ly,2) + pow(Lz,2));
			Lx = Lx / Ln;
			Ly = Ly / Ln;
			Lz = Lz / Ln;
			
			LN = Lx*vrh[(*it).p3-1].Nx + Ly*vrh[(*it).p3-1].Ny + Lz*vrh[(*it).p3-1].Nz;
			dif = Ii*kd*LN; // difuzna komponenta
			if (dif < 0) dif = 0;
			I = Ia*ka + dif;			
			glColor3ub(I, 0, 0); 
			glVertex3f(vrh[(*it).p3-1].x, vrh[(*it).p3-1].y, vrh[(*it).p3-1].z);
			
			glEnd();
		} // end if(cos)
		
	}
	
	// ====== bezierova krivulja
	if (!animacija)	 { // ako nema animacije, crtamo krivulju iz fiksnog ocista
		vector<point>::iterator kTocka;
		glPointSize(5.0);
		glBegin(GL_POINTS);
		for(kTocka = bezVrh.begin(); kTocka < bezVrh.end(); kTocka++) {
			glColor3ub(0, 0, 255); 
			glVertex3f((*kTocka).x, (*kTocka).y, (*kTocka).z);
		}
		glEnd();
	

		glPointSize(2.0);
		glBegin(GL_POINTS);
		for(double t = 0; t <= 1; t += 0.01) {
			double x = 0, y = 0, z = 0;
			int n = bezVrh.size()-1;
			int i = 0;
			for(kTocka = bezVrh.begin(); kTocka < bezVrh.end(); kTocka++) {
				double b = (fact(n)/(fact(i)*fact(n-i))) * pow(t, i) * pow(1-t, n-i);
				x += (*kTocka).x * b;
				y += (*kTocka).y * b;
				z += (*kTocka).z * b;
				i++;
			}
			glVertex3f(x, y, z);
		}
		glEnd();
	}

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
		updatePerspective();
		glutPostRedisplay();
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

		case 'k': ociste.x = ociste.x-0.1;
        break;

		case 'r': ociste.x=0.0; izvor.x = 0.0; izvor.y = 0.0;
        break;
        
        case 'a': izvor.x = izvor.x-0.1;
        break;

		case 'd': izvor.x = izvor.x+0.1;
        break;

        case 'w': izvor.y = izvor.y+0.1;
        break;

		case 's': izvor.y = izvor.y-0.1;
        break;

        case ' ': animacija = !animacija;
        		if (animacija) glutTimerFunc(20, animate, 0);
        		else {
        			ociste.x = 0;
        			ociste.y = 0;
        			ociste.z = 5;
        		}
        break;

		case 27:  exit(0);
		break;
	}
	updatePerspective();
	glutPostRedisplay();
}


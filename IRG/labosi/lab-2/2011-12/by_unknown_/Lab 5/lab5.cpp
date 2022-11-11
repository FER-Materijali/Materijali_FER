#ifdef _WIN32
#include <windows.h>             //bit ce ukljuceno ako se koriste windows
#endif

//  #include <GL/Gl.h>
//  #include <GL/Glu.h>    nije potrebno ako se koristi glut
#include <GL/glut.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

int brF = 0, brV = 0;

GLfloat xg, yg, zg;
GLfloat xg1, yg1, zg1;
GLfloat xg2, yg2, zg2;
GLfloat xg3, yg3, zg3;
GLfloat xo, yo, zo;

GLfloat xMin, xMax, yMin, yMax;

class Vrh {
public:
	float x, y, z, h;
	Vrh(float x1, float y1, float z1) {
		x = x1; y = y1; z = z1; h = 1.0;
	}
};
class Poligon {
public:
	Vrh * v1, * v2, * v3;
	Poligon (Vrh * vX, Vrh * vY, Vrh * vZ) {
		v1 = vX; v2 = vY; v3 = vZ;
	}
};

  Poligon * poligoni;
  Vrh * vrhovi;


//*********************************************************************************
//	Pokazivac na glavni prozor i pocetna velicina.
//*********************************************************************************

GLuint window; 
GLuint sub_width = 256, sub_height = 256;
GLfloat T[4][4] = {0.0};
GLfloat T1[4][4] = {0.0};
GLfloat T2[4][4] = {0.0};
GLfloat T3[4][4] = {0.0};
GLfloat T4[4][4] = {0.0};
GLfloat T5[4][4] = {0.0};
GLfloat rez[4][4] = {0.0};
GLfloat H;

//*********************************************************************************
//	Function Prototypes.
//*********************************************************************************

void myDisplay			();
void myReshape			(int width, int height);
void ucitajGlediste		();
void napraviMatrice		();
void pomnoziMatrice		(float m1[4][4], float m2[4][4]);
void stvoriMatricu		();
void kopiraj			();
void ispisiVrhove		();

//*********************************************************************************
//	Glavni program.
//*********************************************************************************

int main(int argc, char ** argv)
{

	vector<string> text_file;

  //ifstream ifs("tetrahedron.obj");
  ifstream ifs("kocka.obj");
  //ifstream ifs("teddy.obj");
  //ifstream ifs("teapot.obj");
  //ifstream ifs("bird.obj");
  //ifstream ifs("frog.obj");
  //ifstream ifs("bik.obj");
  string temp;

  while( getline( ifs, temp ) )
     text_file.push_back( temp );

  for (int i = 0; i < text_file.size(); i++) {
	  if (text_file.at(i).at(0) == 'f') brF++;
	  else if (text_file.at(i).at(0) == 'v') brV++;
  }
  cout<<"Broj vrhova: "<<brV<<"\n";
  cout<<"Broj poligona: "<<brF<<"\n";

  vrhovi = (Vrh *) malloc (brV * sizeof(Vrh));
  poligoni = (Poligon *) malloc (brF * sizeof(Poligon));


  int oVrhovi = 0, oPoligoni = 0;

  for (int i = 0; i < text_file.size(); i++) {
	  if (text_file.at(i).at(0) == 'v') {
		  float d1, d2, d3;
		  char * text = new char[text_file.at(i).size()+1];
		  std::copy(text_file.at(i).begin(), text_file.at(i).end(), text);
		  sscanf(text, "v %f %f %f", &d1, &d2, &d3);
		  Vrh v(d1, d2, d3);
		  vrhovi[oVrhovi] = v;
		  oVrhovi++;
	  }
  }
  //cout<<"Vrhovi: ";
  //for (int i = 0; i < brV; i++) {
	 // cout<<vrhovi[i].x<<" "<<vrhovi[i].y<<" "<<vrhovi[i].z<<"\n";
  //}

  for (int i = 0; i < text_file.size(); i++) {
	  if (text_file.at(i).at(0) == 'f') {
		  int d1, d2, d3;
		  char *text = new char[text_file.at(i).size()+1];
		  std::copy(text_file.at(i).begin(), text_file.at(i).end(), text);
		  sscanf(text, "f %d %d %d", &d1, &d2, &d3);
		  Poligon p(&vrhovi[d1-1], &vrhovi[d2-1], &vrhovi[d3-1]);
		  poligoni[oPoligoni] = p;
		  oPoligoni++;
		  //cout<<"Prvi vrh: "<<p.v1->x<<" "<<p.v1->y<<" "<<p.v1->z<<"\n";
		  //cout<<"Drugi vrh: "<<p.v2->x<<" "<<p.v2->y<<" "<<p.v2->z<<"\n";
		  //cout<<"Treci vrh: "<<p.v3->x<<" "<<p.v3->y<<" "<<p.v3->z<<"\n";
	  }
  }

  ucitajGlediste();
  napraviMatrice();
  stvoriMatricu();

  for (int i = 0; i < 4; i++) {
	  for (int j = 0; j < 4; j++) {
		  printf("%f\t", T[i][j]);
	  }
	  printf("\n");
  }
  printf("Matrica\n");
  for (int i = 0; i < 4; i++) {
	  for(int j = 0; j < 4; j++) {
		  printf("%f\t", T[i][j]);
	  }
	  printf("\n");
  }
  printf("------------------------------------\n");
  ispisiVrhove();
  printf("------------------------------------\n");

  for (int i = 0; i < brV; i++) {
	  GLfloat tempX, tempY, tempZ, temp4;
	  tempX = vrhovi[i].x * T[0][0] + vrhovi[i].y * T[1][0] + vrhovi[i].z * T[2][0] + T[3][0];
	  tempY = vrhovi[i].x * T[0][1] + vrhovi[i].y * T[1][1] + vrhovi[i].z * T[2][1] + T[3][1];
	  tempZ = vrhovi[i].x * T[0][2] + vrhovi[i].y * T[1][2] + vrhovi[i].z * T[2][2] + T[3][2];
	  temp4 = vrhovi[i].x * T[0][3] + vrhovi[i].y * T[1][3] + vrhovi[i].z * T[2][3] + T[3][3];
	  tempX = tempX/temp4; tempY = tempY/temp4; tempZ = tempZ/temp4;

	  printf("Vrh %d - %f %f %f\n", i, tempX, tempY, tempZ);

	  printf("%f\n", vrhovi[i].z);
	  if (tempZ != 0) {
		  vrhovi[i].x = tempX * H / tempZ;
		  vrhovi[i].y = tempY * H / tempZ;
	  }
	  else {
		  vrhovi[i].x = 0;
		  vrhovi[i].y = 0;
	  }
  }
  xMin = vrhovi[0].x; xMax = vrhovi[0].x; yMin = vrhovi[0].y; yMax = vrhovi[0].y;
  for (int i = 1; i < brV; i++) {
	  if (vrhovi[i].x > xMax) xMax = vrhovi[i].x;
	  if (vrhovi[i].x < xMin) xMin = vrhovi[i].x;
	  if (vrhovi[i].y > yMax) yMax = vrhovi[i].y;
	  if (vrhovi[i].y < yMin) yMin = vrhovi[i].y;

  }
  printf("Vrhovi %f %f %f %f\n", xMin, xMax, yMin, yMax);
  ispisiVrhove();

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(sub_width,sub_height);
	glutInitWindowPosition(100,100);
	glutInit(&argc, argv);

	window = glutCreateWindow("Glut OpenGL Linija");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(myDisplay);

	glutMainLoop();
    	return 0;
}


//*********************************************************************************
//	Osvjezavanje prikaza. (nakon preklapanja prozora) 
//*********************************************************************************

void myDisplay()
{
 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < brF; i++) {
		//printf("Iscrtavam poligon %d\n", i);
		printf("%f %f\n", poligoni[i].v1->x, poligoni[i].v1->y);
		glVertex2f(poligoni[i].v1->x, poligoni[i].v1->y);
		glVertex2f(poligoni[i].v2->x, poligoni[i].v2->y);
		glVertex2f(poligoni[i].v3->x, poligoni[i].v3->y);
		glVertex2f(poligoni[i].v1->x, poligoni[i].v1->y);
	}
	 printf("Vrhovi %f %f %f %f\n", xMin, xMax, yMin, yMax);
	glEnd();
	glFlush();
}

//*********************************************************************************
//	Promjena velicine prozora.
//*********************************************************************************

void myReshape(int width, int height)
{
	sub_width = width;                      	//promjena sirine prozora
    	sub_height = height;				//promjena visine prozora
		
	gluOrtho2D(xMin-(xMax-xMin)/2, xMax+(xMax-xMin)/2, yMin-(yMax-yMin)/2, yMax+(yMax-yMin)/2); 	//	okomita projekcija
    	glViewport(0, 0, sub_width, sub_height);	//  	otvor u prozoru
	glMatrixMode(GL_PROJECTION);			//	matrica projekcije
	glLoadIdentity();				//	jedinicna matrica
	glClearColor( 1.0f, 1.0f, 1.0f, 0.0f );		//	boja pozadine
	glClear( GL_COLOR_BUFFER_BIT );			//	brisanje pozadine
	glPointSize(1.0);				//	postavi velicinu tocke
	glColor3f(0.0f, 0.0f, 0.0f);			//	postavi boju
}

void ucitajGlediste() {
	FILE * f = fopen("glediste.txt", "r");
	fscanf(f, "G %f %f %f\n", &xg, &yg, &zg);
	fscanf(f, "O %f %f %f", &xo, &yo, &zo);
	H = sqrt(pow((float)xo-xg, 2) + pow((float)yo-yg, 2) + pow((float)zo-zg, 2));
	printf("H = %f\n", H);
	fclose(f);
}

void napraviMatrice() {
	// T1

	T1[0][0] = 1.0; T1[1][1] = 1.0; T1[2][2] = 1.0; T1[3][3] = 1.0;
	T1[3][0] = -xo; T1[3][1] = -yo; T1[3][2] = -zo;

	xg1 = xg - xo;
	yg1 = yg - yo;
	zg1 = zg - zo;

	// T2

	float sin = yg1 / sqrt(pow((float)xg1, 2) + pow ((float)yg1, 2));
	float cos = xg1 / sqrt(pow((float)xg1, 2) + pow ((float)yg1, 2));

	T2[2][2] = 1.0; T2[3][3] = 1.0;
	T2[0][0] = cos; T2[1][1] = cos;
	T2[0][1] = -sin; T2[1][0] = sin;

	xg2 = sqrt(pow((float)xg1,2) + pow((float)yg1,2));
	yg2 = 0.0;
	zg2 = zg1;

	// T3

	sin = xg2 / sqrt(pow((float)xg2, 2) + pow ((float)zg2, 2));
	cos = zg2 / sqrt(pow((float)xg2, 2) + pow ((float)zg2, 2));

	T3[1][1] = 1.0; T3[3][3] = 1.0;
	T3[0][0] = cos; T3[2][2] = cos;
	T3[0][2] = sin; T3[2][0] = -sin;

	xg3 = 0;
	yg3 = 0;
	zg3 = sqrt(pow((float)xg2,2) + pow((float)zg2,2));

	// T4

	T4[2][2] = 1.0; T4[3][3] = 1.0;
	T4[0][1] = -1.0; T4[1][0] = 1.0;

	// T5
	
	T5[2][2] = 1.0; T5[3][3] = 1.0;
	T5[0][0] = -1.0; T5[1][1] = 1.0;


}

void pomnoziMatrice (float m1[4][4], float m2[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			rez[i][j] = 0;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				rez[i][j] += m1[i][k]*m2[k][j];
			}
		}
	}
}

void stvoriMatricu() {

	pomnoziMatrice(T1, T2);
	kopiraj();
	
	pomnoziMatrice(T, T3);
	kopiraj();

	pomnoziMatrice(T, T4);
	kopiraj();
	
	pomnoziMatrice(T, T5);
	kopiraj();
	
	for(int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (T[i][j] == -0.0) T[i][j] = 0.0;
		}
	}
}

void kopiraj() {
	for(int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			T[i][j] = rez[i][j];
		}
	}
}

void ispisiVrhove(){
	for(int i = 0; i < brV; i++) {
		printf("Vrh %d - %f %f %f\n", i, vrhovi[i].x, vrhovi[i].y, vrhovi[i].z);
	}
}
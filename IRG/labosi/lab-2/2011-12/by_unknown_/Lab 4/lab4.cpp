#include <string>
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

int brF = 0, brV = 0;

class Vrh {
public:
	float x, y, z;
	Vrh(float x1, float y1, float z1) {
		x = x1; y = y1; z = z1;
	}
};
class Poligon {
public:
	Vrh * v1, * v2, * v3;
	Poligon (Vrh * vX, Vrh * vY, Vrh * vZ) {
		v1 = vX; v2 = vY; v3 = vZ;
	}
};

int main()
{
  vector<string> text_file;

  //ifstream ifs("tetrahedron.obj");
  ifstream ifs("kocka.obj");
  string temp;

  while( getline( ifs, temp ) )
     text_file.push_back( temp );

  for (int i = 0; i < text_file.size(); i++) {
	  if (text_file.at(i).at(0) == 'f') brF++;
	  else if (text_file.at(i).at(0) == 'v') brV++;
  }
  cout<<"Broj vrhova: "<<brV<<"\n";
  cout<<"Broj poligona: "<<brF<<"\n";

  Vrh * vrhovi;
  vrhovi = (Vrh *) malloc (brV * sizeof(Vrh));
  Poligon * poligoni;
  poligoni = (Poligon *) malloc (brF * sizeof(Poligon));
  float * a, * b, * c, * d;
  a = (float *) malloc (brF * sizeof (float));
  b = (float *) malloc (brF * sizeof (float));
  c = (float *) malloc (brF * sizeof (float));
  d = (float *) malloc (brF * sizeof (float));


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
		  a[oPoligoni] = (p.v2->y-p.v1->y)*(p.v3->z-p.v1->z) - (p.v2->z-p.v1->z)*(p.v3->y-p.v1->y);
		  b[oPoligoni] = - (p.v2->x-p.v1->x)*(p.v3->z-p.v1->z) + (p.v2->z-p.v1->z)*(p.v3->x-p.v1->x);
		  c[oPoligoni] = (p.v2->x-p.v1->x)*(p.v3->y-p.v1->y) - (p.v2->y-p.v1->y)*(p.v3->x-p.v1->x);
		  d[oPoligoni] = -a[oPoligoni]*p.v1->x - b[oPoligoni]*p.v1->y - c[oPoligoni]*p.v1->z;
		  oPoligoni++;
		  //cout<<"Prvi vrh: "<<p.v1->x<<" "<<p.v1->y<<" "<<p.v1->z<<"\n";
		  //cout<<"Drugi vrh: "<<p.v2->x<<" "<<p.v2->y<<" "<<p.v2->z<<"\n";
		  //cout<<"Treci vrh: "<<p.v3->x<<" "<<p.v3->y<<" "<<p.v3->z<<"\n";
	  }
  }
  while(1) {
	  printf ("Unesite koordinate tocke: ");
	  float x, y, z;
	  bool izvan= false;
	  scanf ("%f %f %f", &x, &y, &z); 

	  for (int i = 0; i < brF; i++) {
		  if ((a[i] * x + b[i] * y + c[i] * z + d[i]) > 0) {
			  izvan = true;
			  break;
		  }
	  }
	  if (izvan) printf("Tocka se nalazi izvan\n");
	  else printf("Tocka se nalazi unutra\n");
  }
  getchar();
}

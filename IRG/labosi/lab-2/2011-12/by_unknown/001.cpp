// g++ 001.cpp -o 001 && ./001 kocka.obj

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


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


struct point {
	double x;
	double y;
	double z;
};


struct poly {
	int p1, p2, p3;
	double A, B, C, D;
};

int main (int argc, char *argv[]) {
	
	vector<point> vrh;
	vector<poly> poligoni;

	// ========= ucitavanje datoteke =========
	string line;
	ifstream myfile (argv[1]);
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
					vrh.push_back(v);
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
	 
	 // ========= racunanje koeficijenata =========	 
	 vector<poly>::iterator it;
	 for(it = poligoni.begin(); it < poligoni.end(); it++) {
/*
	 	cout << "("<< vrh[(*it).p1-1].x << " " << vrh[(*it).p1-1].y << " " << vrh[(*it).p1-1].z << ") "
   	 	 	 << "("<< vrh[(*it).p2-1].x << " " << vrh[(*it).p2-1].y << " " << vrh[(*it).p2-1].z << ") "
   	 	 	 << "("<< vrh[(*it).p3-1].x << " " << vrh[(*it).p3-1].y << " " << vrh[(*it).p3-1].z << ") "
   	 	 	 << endl;
*/
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

/*	 	
	 	cout << "za vrhove: " << (*it).p1 -1 << " " << (*it).p2 -1 << " " << (*it).p3 -1 << " : ";
	 	cout << (*it).A << " " << (*it).B << " " << (*it).C  << " " << (*it).D << endl;
*/
	 }
	 
	 // ========= testiranje ispitne tocke =========
	 double x, y, z;
	 cout << "Unesite koordinate ispitne tocke: ";
	 cin >> x >> y >> z;
	 
	 bool sveManje = true;
	 for(it = poligoni.begin(); it < poligoni.end(); it++) {
/*
	 	cout << "Mnozim " << (*it).A << "*" << x
	 	<< " + " << (*it).B << "*" << y << " + "
	 	<< (*it).C << "*" << z << " + " << (*it).D << " = ";
*/	 	
	 	double VR = (*it).A * x + (*it).B * y  + (*it).C * z + (*it).D;
	 	if (VR > 0) {
	 		sveManje = false;
	 		break;
	 	}
	 }
	 
	 if (sveManje) {
	 	cout << "Tocka je unutar tijela" << endl;
	 } else {
	 	cout << "Tocka je izvan tijela" << endl;
	 }
	 return 0;
}

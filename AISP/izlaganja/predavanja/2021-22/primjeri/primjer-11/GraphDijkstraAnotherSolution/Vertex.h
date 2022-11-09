#ifndef VERTEX_H_
#define VERTEX_H_

//#include <string>
//#include <unordered_map>
//#include <utility> // std::pair
//#include <new>
//
#include "List.h"

using namespace std;

class Vertex {
 public:
   using dist_t = float;

   string name;
   bool visited;
   List<pair<Vertex*, dist_t>> neighbors;   
   
   Vertex(string name = "") : name(name), visited(false) { };
   Vertex(Vertex& v) : name(v.name), visited(v.visited) { 
	   for (auto i = v.neighbors.begin(); i != v.neighbors.end(); ) {
		   neighbors.append(*i);
	   }
   };
   
   friend ostream &operator<<(ostream &o, const Vertex& v) { o << v.name; }
   ~Vertex() {
	   cout << "~Vertex() " << name << endl;
	   for (auto i = neighbors.begin(); i != neighbors.end(); ) {
		  auto tmp = i++;
		  delete *tmp;
		  tmp = nullptr;
	   }
   }
};

#endif  // VERTEX_H_
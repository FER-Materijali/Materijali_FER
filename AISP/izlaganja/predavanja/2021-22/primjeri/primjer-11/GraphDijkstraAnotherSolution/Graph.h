#ifndef GRAPH_H_
#define GRAPH_H_

//#include <utility>
//#include <string>
//
//#include "List.h"
//#include "Vertex.h"

using namespace std;
using dist_t = typename Vertex::dist_t;

class Graph { 
 public:
   List<Vertex> vertices;
   void print();

   void Dijkstra(Vertex& start); // for each vertex returns the shortest path + total distance from the starting vertex

   ~Graph() { 
	   cout << "~Graph()" << endl;
	   for (auto i = vertices.begin(); i != vertices.end(); ) {
		   auto tmp = i++;
		   delete *tmp; // calls ~Vertex() 
		   tmp = nullptr;
	   }
   }
};

#endif // GRAPH_H_

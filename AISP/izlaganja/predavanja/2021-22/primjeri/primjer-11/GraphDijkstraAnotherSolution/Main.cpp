#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <new> // nothrow
#include <utility> // std::pair

#include "List.h"
#include "Vertex.h"
#include "Graph.h"

using namespace std;

int main(void) {
   string r, t;
   size_t start, pos;
   bool found;

   Graph g;
   List<Vertex>::iterator i;
   Vertex *v = nullptr, *v0 = nullptr;

   // stvaranje grafa
   ifstream f("DijkstraInput.txt");
   //ifstream f("DijkstraInput2.txt");
   while (getline(f, r)) {
      cout << "row: " << r << endl;
      start = 0;
      do {
         pos = r.find(' ', start);
         if (pos == string::npos)
            pos = r.length();
         t = r.substr(start, pos - start);
         // postoji li već takav vrh u grafu
         found = false;
         for (i = g.vertices.begin(); i != g.vertices.end(); i++) {
            if (i->name == t) {
               found = true;
               break;
            }
         }
         if (!found) {
            v = new Vertex(t);
            g.vertices.append(v);
         } else {
            v = *i;
         }
         if (start == 0) { // prvi vrh u retku
            v0 = v;
		 }
		 else {
			 // ako nije prvi vrh, onda pročitaj i udaljenost od v0 do v
			 start = pos + 1;
			 pos = r.find(' ', start);
			 if (pos == string::npos) {
				 pos = r.length();
			 }
			 dist_t dist = stof(r.substr(start, pos - start)); // string to float
			 // nužno je da je lista organizirana kao lista referenci
			 // jer se inače neće promijeniti podatak koji je već dodan u listu
			 pair<Vertex*, dist_t> *p = new(nothrow) pair<Vertex*, dist_t>(v, dist);
			 v0->neighbors.append(p); // paziti na delete!
         }
         start = pos + 1;
      } while (start < r.length());
   }
   g.print();
   g.Dijkstra(**g.vertices.begin());

   cin.get();
   return 0;
}

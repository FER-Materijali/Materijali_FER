#include "GraphDijkstra.h"
#include <iostream>
#include <math.h>
#include <queue>
#include <stack>

int main(void) {
   Graph<string> g;
   Vertex<string> *u, *v;
   Neighbor<string> *n;
   double newDistance;

   g.readFromFile("DijkstraInput.txt");
   g.printStructure();

   string source = "A";
   // initialize Q
   auto comparator = [](Vertex<string> *a, Vertex<string> *b) {
      return a->distanceFromSource > b->distanceFromSource;
   };
   // all template parameters must be types, so decltype returns the type of
   // comparator
   priority_queue<Vertex<string> *, vector<Vertex<string> *>,
                  decltype(comparator)>
       Q(comparator);

   for (auto &vi : g.vertices) {
      v = &(vi.second);
      if (v->item == source) {
         v->distanceFromSource = 0;
      } else {
         v->distanceFromSource = INFINITY;
      }
      v->previous = nullptr;
      v->visited = false;
      Q.push(v);
   }

   // iterate through Q
   while (!Q.empty()) {
      u = Q.top();
      // if only interested in distance to a destination
      // if (u->item == destination) break;
      u->visited = true;
      for (auto &n : u->neighbors) {
         if (!n.vertex->visited) {
            newDistance = u->distanceFromSource + n.distance;
            if (newDistance < n.vertex->distanceFromSource) {
               n.vertex->distanceFromSource = newDistance;
               n.vertex->previous = u;
            }
         }
      }
      Q.pop();
   }
   g.printDistances();

   // actual paths for all nodes
   stack<Vertex<string> *> s;
   Vertex<string> *p;

   for (auto &vi : g.vertices) {
      v = &(vi.second);
      s.push(v);
      for (p = v->previous; p != nullptr; p = p->previous) {
         s.push(p);
      }
      while (!s.empty()) {
         v = s.top();
         cout << v->item << " ";
         s.pop();
      }
      cout << v->distanceFromSource << endl;
   }
   return 0;
}
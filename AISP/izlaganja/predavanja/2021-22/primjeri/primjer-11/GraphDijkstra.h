#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <string>

using namespace std;
template <class T> class Vertex;

template <class T> struct Neighbor {
 public:
   Vertex<T> *vertex;
   double distance;
};

template <class T> class Vertex {
 public:
   T item;
   list<Neighbor<T>> neighbors;
   Vertex<T> *previous;
   bool visited;
   double distanceFromSource;
   Vertex() {}
   Vertex(T item) : item(item) {}
};

template <class T> class Graph {
 public:
   map<T, Vertex<T>> vertices;

   Vertex<T> *addIfNotExists(T item) {
      auto i = vertices.find(item);
      if (i != vertices.end())
         return &(i->second);
      return &(vertices[item] = Vertex<T>(item));
   }

   void readFromFile(string filename) {
      string v1, v2;
      double distance;
      Vertex<string> *u, *v;
      ifstream f(filename);
      while (f >> v1 >> v2 >> distance) {
         cout << v1 << " " << v2 << " " << distance << endl;
         u = addIfNotExists(v1);
         v = addIfNotExists(v2);
         u->neighbors.push_back({v, distance});
         v->neighbors.push_back({u, distance});
      }
   }

   void printStructure() {
      for (auto &vi : vertices) {
         Vertex<T> *v = &(vi.second);
         cout << v->item << " ->";
         for (auto j : v->neighbors) {
            cout << " " << j.vertex->item << " " << j.distance;
         }
         cout << endl;
      }
   }
   void printDistances() {
      for (auto vi : vertices) {
         Vertex<T> *v = &(vi.second);
         cout << "(" + v->item + " " + to_string(v->distanceFromSource) + " " +
                     (v->previous == nullptr ? "NONE" : v->previous->item)
              << +") ";
      }
      cout << endl;
   }
};

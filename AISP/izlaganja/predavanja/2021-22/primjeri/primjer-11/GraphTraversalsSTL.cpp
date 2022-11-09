#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
using namespace std;

template <class T> class Vertex {
 public:
   T item;
   list<Vertex<T> *> neighbors;
   bool visited = false;
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

   void unvisit() {
      for_each(vertices.begin(), vertices.end(),
               [](auto &p) { p.second.visited = false; });
   }

   void printStructure() {
      for (auto &vi : vertices) {
         Vertex<T> *v = &(vi.second);
         cout << v->item << " ->";
         for (auto j : v->neighbors) {
            cout << " " << j->item << " ";
         }
         cout << endl;
      }
   }

   void readFromFile(string filename) {
      ifstream f(filename);
      string line, token;
      Vertex<string> *u, *v;
      while (getline(f, line)) {
         istringstream s(line);
         s >> token;
         u = addIfNotExists(token);
         while (s >> token) {
            v = addIfNotExists(token);
            u->neighbors.push_back(v);
         }
      }
   }

   void DFSRInternal(Vertex<T> *i) {
      cout << i->item << " ";
      i->visited = true;
      for (auto v : i->neighbors) {
         if (!(v->visited)) {
            DFSRInternal(v);
         }
      }
   }

   void DFSR() {
      cout << "DFSR ";
      DFSRInternal(&((vertices.begin())->second));
      cout << endl;
   }

   void DFS() {
      cout << "DFS ";
      stack<Vertex<T> *> s;
      Vertex<T> *p;
      s.push(&((vertices.begin())->second));
      while (!s.empty()) {
         p = s.top();
         s.pop();
         if (!p->visited) {
            p->visited = true;
            cout << p->item << " ";
            for (auto &v : p->neighbors) {
               if (!(v->visited)) {
                  s.push(v);
               }
            }
         }
      }
      cout << endl;
   }

   void BFS() {
      cout << "BFS ";
      queue<Vertex<T> *> q;
      Vertex<T> *p;
      p = &((vertices.begin())->second);
      p->visited = true;
      cout << p->item << " ";
      q.push(p);
      while (!q.empty()) {
         p = q.front();
         q.pop();
         for (auto &v : p->neighbors) {
            if (!(v->visited)) {
               v->visited = true;
               cout << v->item << " ";
               q.push(v);
            }
         }
      }
      cout << endl;
   }
};

int main(void) {
   Graph<string> g;
   g.readFromFile("TraversalInput.txt");
   g.printStructure();
   g.DFSR();
   g.unvisit();
   g.DFS();
   g.unvisit();
   g.BFS();
   return 0;
}

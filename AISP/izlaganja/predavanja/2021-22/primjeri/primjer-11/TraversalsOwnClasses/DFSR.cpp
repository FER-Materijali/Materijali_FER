#include <fstream>
#include <iostream>
using namespace std;

template <class T> struct ListElement {
   T *data;
   ListElement<T> *next;
};

template <class T> class ListIterator {
 private:
   ListElement<T> *ptr = nullptr;

 public:
   ListIterator<T>() : ptr(nullptr) {}
   ListIterator<T>(ListElement<T> *ptr) : ptr(ptr) {}
   ListIterator<T> &operator++() { // prefix ++
      if (ptr)
         ptr = ptr->next;
      return *this;
   }
   ListIterator<T> operator++(int) { // postfix ++
      ListIterator<T> tmp = *this;
      ++(*this);
      return tmp;
   }
   bool operator!=(const ListIterator<T> &other) { return ptr != other.ptr; }
   T *operator*() { return ptr->data; }
   T *operator->() { return ptr->data; }
};

template <class T> class List {
   ListElement<T> *head = nullptr;

 public:
   bool insert(T *data) { // umetanje na početak liste
      ListElement<T> *newElement = new (nothrow) ListElement<T>;
      if (newElement == nullptr)
         return false;
      newElement->data = data;
      newElement->next = head;
      head = newElement;
      return true;
   }
   bool append(T *data) { // dodavanje na kraj liste
      ListElement<T> *newElement = new ListElement<T>;
      if (newElement == nullptr)
         return false;
      newElement->data = data;
      newElement->next = nullptr;
      ListElement<T> **p;
      for (p = &head; *p; p = &((*p)->next))
         ;
      *p = newElement;
      return true;
   }
   bool insertSorted(T *data) { // umetanje po sortiranom redoslijedu, T mora
                                // imati implementiran operator >
      ListElement<T> *newElement = new (nothrow) ListElement<T>;
      if (newElement == nullptr)
         return false;
      newElement->data = data;
      ListElement<T> **p;
      for (p = &head; *p && data > (*p)->data; p = &((*p)->next))
         ;
      newElement->next = *p;
      *p = newElement;
      return true;
   }
   bool remove(T *data) {
      ListElement<T> **p;
      for (p = &head; *p && *data != *((*p)->data); p = &((*p)->next))
         ;
      if (*p) {
         ListElement<T> *tmp;
         tmp = *p;
         *p = (*p)->next;
         delete tmp;
         return true;
      } else {
         return false;
      }
   }
   typedef ListIterator<T> iterator;
   iterator begin() { return iterator(head); }
   iterator end() { return iterator(); }
};

class Vertex {
 public:
   string name;
   bool visited;
   List<Vertex> neighbors;
   Vertex() : visited(false){};
   Vertex(string name) : name(name), visited(false){};
};

class Graph {
   void DFSR(List<Vertex>::iterator i) {
      List<Vertex>::iterator j;
      cout << i->name << " ";
      i->visited = true;
      for (j = i->neighbors.begin(); j != i->neighbors.end(); j++) {
         if (!(j->visited)) {
            DFSR(j);
         }
      }
   }

 public:
   List<Vertex> vertices;
   void print();
   void DFS() {
      cout << "DFS ";
      DFSR(vertices.begin());
      cout << endl;
   }
};

void Graph::print() {
   List<Vertex>::iterator i, j;
   cout << "graf: " << endl;
   for (i = vertices.begin(); i != vertices.end(); i++) {
      cout << i->name << " ";
      for (j = i->neighbors.begin(); j != i->neighbors.end(); j++) {
         cout << j->name << " ";
      }
      cout << endl;
   }
}

int main(void) {
   string r, t;
   size_t start, pos;
   bool found;

   Graph g;
   List<Vertex>::iterator i;
   Vertex *v, *v0;

   // stvaranje grafa
   ifstream f("DFSInput.txt");
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
         } else {
            v0->neighbors.append(v);
         }
         start = pos + 1;
      } while (start < r.length());
   }
   g.print();
   g.DFS();
   return 0;
}
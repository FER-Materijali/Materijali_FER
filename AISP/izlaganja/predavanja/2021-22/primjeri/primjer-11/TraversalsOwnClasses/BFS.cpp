#include <fstream>
#include <iostream>
using namespace std;

template <class T> class Queue { // red referenci
 private:
   template <class X> struct QueueElement {
      T *data;
      QueueElement<X> *next;
   };
   QueueElement<T> *read = nullptr;
   QueueElement<T> *write = nullptr;

 public:
   bool enqueue(T *data) {
      QueueElement<T> *newElement = new (nothrow) QueueElement<T>;
      if (newElement == nullptr)
         return false;
      newElement->next = nullptr;
      newElement->data = data;
      if (write == nullptr) {
         read = newElement;
      } else {
         write->next = newElement;
      }
      write = newElement;
      return true;
   }
   T *dequeue() {
      T *data;
      if (read == nullptr)
         return nullptr;
      data = read->data;
      QueueElement<T> *tmp = read;
      read = read->next;
      if (read == nullptr)
         write = nullptr;
      delete tmp;
      return data;
   }
   void print() {
      QueueElement<T> *p;
      cout << endl << "Queue ";
      for (p = read; p != nullptr; p = p->next) {
         cout << *(p->data) << " ";
      }
      cout << endl;
   }
};

template <class T> struct ListElement { // lista referenci!
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
   friend ostream &operator<<(ostream &o, const Vertex v) { o << v.name; }
};

class Graph {
 public:
   List<Vertex> vertices;
   void print();
   void BFS();
};

void Graph::BFS() {
   Queue<Vertex> Q;
   Vertex *p, *r;
   List<Vertex>::iterator j;
   p = *(vertices.begin());
   p->visited = true;
   cout << p->name << " ";
   Q.enqueue(p);
   // Q.print();
   while (p = Q.dequeue()) {
      // Q.print();
      for (j = p->neighbors.begin(); j != p->neighbors.end(); j++) {
         if (!(j->visited)) {
            j->visited = true;
            cout << j->name << " ";
            Q.enqueue(*j);
            // Q.print();
         }
      }
   }
}

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
            // nužno je da je lista organizirana kao lista referenci
            // jer se inače neće promijeniti podatak koji je već dodan u listu
            v0->neighbors.append(v);
         }
         start = pos + 1;
      } while (start < r.length());
   }
   g.print();
   g.BFS();
   return 0;
}
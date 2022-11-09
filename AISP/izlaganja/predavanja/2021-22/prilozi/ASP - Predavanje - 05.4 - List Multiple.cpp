#include <iostream>
#include <string>

using namespace std;

struct Person {
   int number;
   string name;
};

class ListPersonMultiple {
   struct ListElement {
      Person data;
      ListElement *numberNext;
      ListElement *nameNext;
   };

   ListElement *numberHead = nullptr;
   ListElement *nameHead = nullptr;

 public:
   bool insert(Person data) { // umetanje po sortiranom redoslijedu
      ListElement *newElement = new (nothrow) ListElement;
      if (newElement == nullptr)
         return false;
      newElement->data = data;
      ListElement **p;
      for (p = &numberHead; *p && data.number > (*p)->data.number;
           p = &((*p)->numberNext))
         ;
      newElement->numberNext = *p;
      *p = newElement;
      for (p = &nameHead; *p && data.name > (*p)->data.name;
           p = &((*p)->nameNext))
         ;
      newElement->nameNext = *p;
      *p = newElement;
      return true;
   }
   void printByNumber() {
      for (ListElement *p = numberHead; p; p = p->numberNext) {
         cout << p->data.number << "-" << p->data.name << " ";
      }
      cout << endl;
   }
   void printByName() {
      for (ListElement *p = nameHead; p; p = p->nameNext) {
         cout << p->data.number << "-" << p->data.name << " ";
      }
      cout << endl;
   }
   bool findByNumber(int number, Person &result) {
      for (ListElement *p = numberHead; p; p = p->numberNext) {
         if (p->data.number == number) {
            result = p->data;
            return true;
         }
      }
      return false;
   }
   bool findByName(string name, Person &result) {
      for (ListElement *p = nameHead; p; p = p->nameNext) {
         if (p->data.name == name) {
            result = p->data;
            return true;
         }
      }
      return false;
   }
};

int main(void) {
   ListPersonMultiple l;
   Person a = {10, "Pero"}, b = {20, "Ivo"}, c = {30, "Ante"}, r;
   l.insert(a);
   l.insert(b);
   l.insert(c);
   l.printByName();
   l.printByNumber();
   if (l.findByNumber(10, r))
      cout << r.number << "-" << r.name << " " << endl;
   if (l.findByName("Ivo", r))
      cout << r.number << "-" << r.name << " " << endl;
   return 0;
}
#include "Hash.h"
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

template <typename T, typename K> class HashChaining : public IHash<T, K> {
 private:
   HashElement<T, K> **hash;
   void Empty() {
      size_t i;
      for (i = 0; i < this->size; i++) {
         hash[i] = nullptr;
      }
   }
   int HashStringToInt(string stringArray, size_t hashSize) const {
      size_t ascii_value = 0;
      for (size_t i = 0; i < stringArray.size(); i++) {
         ascii_value += (int)stringArray[i];
      }
      return ascii_value % hashSize;
   }

 public:
   virtual void Add(IHashableValue<T, K> *element) const {
      int i = HashStringToInt(element->GetKey(), this->size);
      HashElement<T, K> *el = new HashElement<T, K>(element);
      el->next = hash[i];
      hash[i] = el;
   }
   virtual IHashableValue<T, K> *Get(K key) const {
      int i = HashStringToInt(key, this->size);
      HashElement<T, K> *head;
      for (head = hash[i]; head && (head->value->GetKey() != key);
           head = head->next)
         ;
      return head->value;
   }
   virtual void Print() const {
      size_t i;
      HashElement<T, K> *tmp;
      std::cout << "Ispis sadrzaja tablice:\n";
      for (i = 0; i < this->size; i++) {
         std::cout << i << " ";
         tmp = hash[i];
         while (tmp != nullptr) {
            std::cout << tmp->value->GetKey() << " ";
            tmp = tmp->next;
         }
         std::cout << "\n";
      }
   }
   HashChaining(size_t size) {
      this->size = size;
      this->hash = new HashElement<T, K> *[this->size];
      this->Empty();
   }
   ~HashChaining() {
      size_t i;
      HashElement<T, K> *tmp;
      for (i = 0; i < this->size; i++) {
         tmp = hash[i];
         while (tmp != nullptr) {
            HashElement<T, K> *innerTmp;
            innerTmp = tmp;
            tmp = tmp->next;
            // delete innerTmp->value;
            delete innerTmp;
         }
      }
      delete[] this->hash;
   }
};

#define M 7

class Person : public IHashableValue<Person, string> {
 public:
   string name;
   Person() {}
   Person(string name) { this->name = name; }
   virtual string GetKey() const { return name; }
};

#define MAXINPUTELEM 12
int main(void) {
   try {
      Person A[MAXINPUTELEM] = {{"Ivana"}, {"Tihana"}, {"Marija"}, {"Antun"},
                                {"Josip"}, {"Nives"},  {"Matija"}, {"Iva"},
                                {"Anita"}, {"Ivan"},   {"Luka"},   {"Mirela"}};
      HashChaining<Person, string> hash(M);
      for (size_t i = 0; i < MAXINPUTELEM; i++) {
         hash.Add(&A[i]);
      }
      hash.Print();
   } catch (std::exception &e) {
      std::cerr << e.what();
   }
   std::cin.get();
   return 0;
}

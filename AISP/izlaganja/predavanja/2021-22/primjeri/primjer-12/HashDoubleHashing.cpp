#include "Hash.h"
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

#define MAXINPUTELEM 6
#define M 7

template <typename T, typename K> class HashDoubleHashing : public IHash<T, K> {
 private:
   IHashableValue<T, K> **hash;
   void Empty() {
      size_t i;
      for (i = 0; i < this->size; i++) {
         hash[i] = nullptr;
      }
   }

   int HashDoubleHashing1(int key) const { return key % M; }

   int HashDoubleHashing2(int key) const { return 1 + key % (M - 1); }

 public:
   virtual void Add(IHashableValue<T, K> *element) const {
      int h1 = HashDoubleHashing1(element->GetKey());
      int h2 = HashDoubleHashing2(element->GetKey());
      int index;
      for (int i = 0; i < this->size; i++) {
         index = (h1 + i * h2) % this->size;
         if (hash[index] == nullptr) {
            hash[index] = element;
            break;
         }
      }
   }
   virtual IHashableValue<T, K> *Get(K key) const {
      int h1 = HashDoubleHashing1(key);
      int h2 = HashDoubleHashing2(key);
      int index;
      for (int i = 0; i < this->size; i++) {
         index = (h1 + i * h2) % this->size;
         if (hash[index] != nullptr && (*hash[index]).GetKey() == key) {
            return hash[index];
         }
      }
      return nullptr;
   }
   virtual void Print() const {
      size_t i;
      IHashableValue<T, K> *tmp;
      std::cout << "Hash table contents:\n";
      for (i = 0; i < this->size; i++) {
         std::cout << i << " ";
         tmp = hash[i];
         if (tmp != nullptr) {
            std::cout << tmp->GetKey() << " ";
         }
         std::cout << "\n";
      }
   }
   HashDoubleHashing(size_t size) {
      this->size = size;
      this->hash = new IHashableValue<T, K> *[this->size];
      this->Empty();
   }
   ~HashDoubleHashing() { delete[] this->hash; }
};

class Person : public IHashableValue<Person, int> {
 public:
   int id;
   string name;
   Person() {
      this->id = 0;
      this->name = nullptr;
   }
   Person(int id, string name) {
      this->id = id;
      this->name = name;
   }
   virtual int GetKey() const { return id; }
};

int main(void) {
   try {
      Person A[MAXINPUTELEM] = {
          {256374, "pivo-psenicno"}, {745623, "cips"},
          {843723, "spageti"},       {823754, "marmelada"},
          {923854, "sok-naranca"},   {128443, "keksi"}};
      HashDoubleHashing<Person, int> hash(M);
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

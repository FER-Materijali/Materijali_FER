#include "Hash.h"
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

template <typename T, typename K> class HashLinearProbing : public IHash<T, K> {
 private:
   IHashableValue<T, K> **hash;
   void Empty() {
      size_t i;
      for (i = 0; i < this->size; i++) {
         hash[i] = nullptr;
      }
   }

   int HashIntOverlap(int key)
       const { // Overlap method used, the central part remains non-inverted
      int sum = 0;
      char result[2] = {0};
      for (int i = 0; i < 3; i++) { // split 6-digit number into 3 parts
         if (i != 1) {
            result[0] = key % 10;
            key = key / 10;
            result[1] = key % 10;
            key = key / 10;
            sum += result[0] * 10 + result[1];
         } else {
            result[0] = key % 10;
            key = key / 10;
            result[1] = key % 10;
            key = key / 10;
            sum += result[1] * 10 + result[0];
         }
      }
      return sum;
   }

 public:
   virtual void Add(IHashableValue<T, K> *element) const {
      int address = HashIntOverlap(element->GetKey());
      int index;
      for (int i = 0; i < this->size; i++) {
         index = (address + i) % this->size;
         if (hash[index] == nullptr) {
            hash[index] = element;
            break;
         }
      }
   }
   virtual IHashableValue<T, K> *Get(K key) const {
      int address = HashIntOverlap(key);
      int index;
      for (int i = 0; i < this->size; i++) {
         index = (address + i) % this->size;
         if (hash[index] != nullptr && (*hash[index]).GetKey() == key) {
            return hash[index];
         }
      }
      return nullptr;
   }
   virtual void Print() const {
      size_t i;
      IHashableValue<T, K> *tmp;
      std::cout << "Ispis sadrzaja tablice:\n";
      for (i = 0; i < this->size; i++) {
         std::cout << i << " ";
         tmp = hash[i];
         if (tmp != nullptr) {
            std::cout << tmp->GetKey() << " ";
         }
         std::cout << "\n";
      }
   }
   HashLinearProbing(size_t size) {
      this->size = size;
      this->hash = new IHashableValue<T, K> *[this->size];
      this->Empty();
   }
   ~HashLinearProbing() { delete[] this->hash; }
};

#define M 7

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

#define MAXINPUTELEM 6
int main(void) {
   try {
      Person A[MAXINPUTELEM] = {
          {256374, "pivo-psenicno"}, {745623, "cips"},
          {843723, "spageti"},       {823754, "marmelada"},
          {923854, "sok-naranca"},   {128443, "keksi"}};
      HashLinearProbing<Person, int> hash(M);
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

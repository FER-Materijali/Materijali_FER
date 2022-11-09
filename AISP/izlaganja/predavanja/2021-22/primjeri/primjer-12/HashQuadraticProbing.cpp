#include "Hash.h"
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

#define MAXINPUTELEM 6
#define M 8
#define c1                                                                     \
   0.5 // constants to be used by the quadratic probing function, set to 0.5
       // guarantee diverse indices for tables which have size of 2^k
#define c2 0.5

template <typename T, typename K>
class HashQuadraticProbing : public IHash<T, K> {
 private:
   IHashableValue<T, K> **hash;
   void Empty() {
      size_t i;
      for (i = 0; i < this->size; i++) {
         hash[i] = nullptr;
      }
   }
   int HashMultiplicationMethod(int key) const {
      unsigned int A = 2654435769; // constant A is chosen according to the
                                   // recommended value for 32-bit words (Knuth)
      unsigned int shift = 29; // (word size) - k = 32 - 3 (32 is due to 32-bit
                               // words, 3 comes from the exponent - 2^3)
      return (A * key) >> shift;
   }

 public:
   virtual void Add(IHashableValue<T, K> *element) const {
      int address = HashMultiplicationMethod(element->GetKey());
      int index;
      for (int i = 0; i < this->size; i++) {
         index = (int)fmod((address + c1 * i + c2 * i * i), this->size);
         if (hash[index] == nullptr) {
            hash[index] = element;
            break;
         }
      }
   }
   virtual IHashableValue<T, K> *Get(K key) const {
      int address = HashMultiplicationMethod(key);
      int index;
      for (int i = 0; i < this->size; i++) {
         index = (int)fmod((address + c1 * i + c2 * i * i), this->size);
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
   HashQuadraticProbing(size_t size) {
      this->size = size;
      this->hash = new IHashableValue<T, K> *[this->size];
      this->Empty();
   }
   ~HashQuadraticProbing() { delete[] this->hash; }
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
      HashQuadraticProbing<Person, int> hash(M);
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

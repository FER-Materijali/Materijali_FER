#include <cstring>
#include <iostream>
#include <string>
using namespace std;

template <typename T, typename K> class IHashableValue {
 public:
   virtual K GetKey() const = 0;
};

template <typename T, typename K> class HashElement {
 public:
   IHashableValue<T, K> *value;
   HashElement *next;
   HashElement(IHashableValue<T, K> *value) { this->value = value; }
};

template <typename T, typename K> class IHash {
 protected:
   size_t size;

 public:
   virtual void Add(IHashableValue<T, K> *element) const = 0;
   virtual IHashableValue<T, K> *Get(K key) const = 0;
   virtual void Print() const = 0;
};

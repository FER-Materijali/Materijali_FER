#ifndef LIST_H_
#define LIST_H_

//https ://stackoverflow.com/questions/1724036/splitting-templated-c-classes-into-hpp-cpp-files-is-it-possible

using namespace std;

// ListElement
template <class T> struct ListElement { // list of references
   T *data;
   ListElement<T> *next;
};

// ListIterator
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

// List
template <class T> class List {
   ListElement<T> *head = nullptr;

 public:
   bool insert(T *data); // at the beginning of the list
   bool append(T *data); // at the end of the list
   bool insertSorted(T *data); // insertion - asc order; operator > should be implemented
   bool remove(T *data); // remove from the list

   typedef ListIterator<T> iterator;
   iterator begin() { return iterator(head); }
   iterator end() { return iterator(); }

   ~List() {
	   auto *p = head;
	   while (p) {
		   auto next = p->next;
		   delete p;		   
		   p = next;
	   }
	   head = nullptr;
   }
};


template <class T>
inline bool List<T>::insert(T *data) { // insert at the beginning of the list
	ListElement<T> *newElement = new (nothrow) ListElement<T>;
	if (newElement == nullptr)
		return false;
	newElement->data = data;
	newElement->next = head;
	head = newElement;
	return true;
}

template <class T>
inline bool List<T>::append(T *data) { // append at the end of the list
	ListElement<T> *newElement = new ListElement<T>;
	if (newElement == nullptr)
		return false;
	newElement->data = data;
	newElement->next = nullptr;
	
	ListElement<T> **p;
	for (p = &head; *p; p = &((*p)->next)) ;
	*p = newElement;
	return true;
}

template <class T>
inline bool List<T>::insertSorted(T *data) { // sorted insertion; operator > required
	ListElement<T> *newElement = new (nothrow) ListElement<T>;
	if (newElement == nullptr)
		return false;
	newElement->data = data;
	ListElement<T> **p;
	for (p = &head; *p && data > (*p)->data; p = &((*p)->next));
	newElement->next = *p;
	*p = newElement;
	return true;
}

template <class T>
inline bool List<T>::remove(T *data) {
	ListElement<T> **p;
	for (p = &head; *p && *data != *((*p)->data); p = &((*p)->next));
	if (*p) {
		ListElement<T> *tmp;
		tmp = *p;
		*p = (*p)->next;
		delete tmp;
		return true;
	}
	else {
		return false;
	}
}

#endif  // LIST_H_

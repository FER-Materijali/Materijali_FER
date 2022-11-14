#define NDEBUG
template <typename T>
struct Array {
       Array (int sz=0): size_(sz), data_(new T[sz]) {}
       ~Array()  { delete [] data_; }
       int size() const {return size_;  }
       const T& operator[](int i) const { return data_[check(i)]; }
             T& operator[](int i)       { return data_[check(i)]; }
       Array(const Array<T>&);
       Array<T>& operator= (const Array<T>&);
       private:
               int size_;
               T* data_;
               inline int check(int i) const {
                      assert (i>=0 && i<size_);
                      return i;
                      }
       };

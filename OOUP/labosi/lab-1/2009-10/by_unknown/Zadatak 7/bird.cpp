#include <iostream>
#include <string>
#include <assert.h>
#include <exception>
#include <stdexcept>

using std::runtime_error;



class cannotFlyException : public runtime_error {
      public:
             cannotFlyException::cannotFlyException(): 
             runtime_error( "This bird doesn't fly!" ) {}
};

class Bird {
      public:
             Bird() {}
             virtual ~Bird() {}
             int altitude() const {
                 return altitude_;
             }
             virtual void fly()=0;
             
      protected:
                int altitude_;
};

void client(Bird&b){
     try {
     b.fly();
     assert(b.altitude()>0);
     } catch (cannotFlyException& e) {
             std::cerr << "Caught an exception: " <<e.what()<<"\n";
             }
}
     
class Chicken : public Bird {
      public:
             void fly() { throw cannotFlyException(); }
};
     
     
int main(){
    Chicken c;
    client(c);
} 

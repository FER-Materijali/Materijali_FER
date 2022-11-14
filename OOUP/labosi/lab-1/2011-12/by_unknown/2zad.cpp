#include <iostream>

using namespace std;

class CoolClass{
  public:
    virtual void setx(int x){x_=x;};
    virtual int getx(){return x_;};
    //virtual void sety(int y){y_=y;};
    //virtual int gety(){return y_;};
  private:
    int x_;
    //int y_;
  };

class PlainOldClass{
  public:
    void setx(int x){x_=x;};
    int getx(){return x_;};
    //void sety(int y){y_=y;};
    //int gety(){return y_;};
  private:
    int x_;
    //int y_;
  };

int main(){
    cout << sizeof(CoolClass) << endl;
    cout << sizeof(PlainOldClass) << endl;
  }

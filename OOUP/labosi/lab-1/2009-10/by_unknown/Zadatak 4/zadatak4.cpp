#include <iostream>
#include <assert.h>

  struct Point{
    int x; int y;
  };
  struct Shape{
    enum EType {circle, square, rhomb};
    EType type_;
  };
  struct Circle{
     Shape::EType type_;
     double radius_;
     Point center_;
  };
  struct Square{
     Shape::EType type_;
     double radius_;
     Point center_;
  };
  struct Rhomb{
         Shape::EType type_;
         double radius;
         Point center_;
  };
  void drawSquare(struct Square*){
    std::cerr <<"in drawSquare\n";
  }
  void drawCircle(struct Circle*){
    std::cerr <<"in drawCircle\n";
  }
  void drawRhomb(struct Rhomb*) {
       std::cerr<<"in drawRhomb\n";
  }
  void moveRhomb(struct Rhomb*) {
       std::cout<<"moving Rhomb!!\n";
  }
  void moveSquare(struct Square*){
       std::cout<<"moving Square!!\n";
  }
  void moveCircle(struct Circle*){
       std::cout<<"moving Circle!!\n";
  }
  
  void moveShapes(Shape** list, int n) {
       for (int i=0; i<n; i++){
           struct Shape* s = list[i];
           switch (s->type_) {
                  case Shape::square:
                       moveSquare((struct Square*)s);
                       break;
                  case Shape::circle:
                       moveCircle((struct Circle*)s);
                       break;
                 /* case Shape::rhomb:
                       moveRhomb((struct Rhomb*)s);
                       break; */
                  default:
                          exit(0);
                  }
       }
  }
  void drawShapes(Shape** list, int n){
    for (int i=0; i<n; ++i){
      struct Shape* s = list[i];
      switch (s->type_){
      case Shape::square:
        drawSquare((struct Square*)s);
        break;
      case Shape::circle:
        drawCircle((struct Circle*)s);
        break;
      case Shape::rhomb:
           drawRhomb((struct Rhomb*)s);
           break;
      default:
        assert(0); 
        exit(0);
      }
    }
  }
  int main(){
    Shape* list[4];
    list[0]=(Shape*)new Circle;
    list[0]->type_=Shape::circle;
    list[1]=(Shape*)new Square;
    list[1]->type_=Shape::square;
    list[2]=(Shape*)new Square;
    list[2]->type_=Shape::square;
    list[3]=(Shape*)new Circle;
    list[3]->type_=Shape::circle;
    list[4]=(Shape*) new Rhomb;
    list[4]->type_=Shape::rhomb;
 
    drawShapes(list, 5);
    std::cout<<"\n";
    moveShapes(list, 5);
  }

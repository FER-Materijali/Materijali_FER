#include <iostream>
#include <vector>
#include <list>

class Point{
    public:
        int x;
        int y;
  };

class Shape{
    public:
        virtual void draw()=0;
};

class Circle: public Shape{
    double radius_;
    Point center_;
    public :
        virtual void draw(){
            std::cout<<"Drawing a circle...\n";
        };
};

class Polyline: public Shape{
    std::vector <Point> points_ ;
    public:
        virtual void draw (){
            std::cout<<"Drawing a polyline...\n";
        };
};

void drawShapes(const std::list<Shape*> &list){
    std::list<Shape*>::const_iterator it;
        for (it=list.begin(); it!=list.end(); ++it){
            (*it)->draw();
    }
}

int main(){
    std::list<Shape*> shapes;
    Shape* c=new Circle();
    shapes.push_back(c);
    Shape* p=new Polyline();
    shapes.push_back(p);
    drawShapes(shapes);
}

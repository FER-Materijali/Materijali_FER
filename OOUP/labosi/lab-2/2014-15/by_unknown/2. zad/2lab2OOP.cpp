#include <iostream>
#include <assert.h>
#include <list>

struct Point{
	int x; int y;
};
class Shape{
	public:
		virtual void draw()=0;
		virtual void translate(int,int)=0;
};
class Square :public Shape{
		double radius_;
		Point center_;
	public:
		virtual void draw(){
			std::cerr <<"in drawSquare\n";
		}
		virtual void translate(int x,int y){
			center_.x+=x;
			center_.y+=y;
		}
};
class Circle :public Shape{
		double radius_;
		Point center_;
	public:
		virtual void draw(){
			std::cerr <<"in drawCircle\n";
		}
		virtual void translate(int x,int y){
			center_.x+=x;
			center_.y+=y;
		}
};
class Rhomb :public Shape{
		double radius_;
		Point center_;
	public:
		virtual void draw(){
			std::cerr <<"in drawRhomb\n";
		}
		virtual void translate(int x,int y){
			center_.x+=x;
			center_.y+=y;
		}
};


void drawShapes(const std::list<Shape*>& fig){
	std::list<Shape*>::const_iterator it;
	for (it=fig.begin(); it!=fig.end(); ++it){
		(*it)->draw();
	}
}
  
void moveShapes(const std::list<Shape*>& fig, int x, int y){
	std::list<Shape*>::const_iterator it;
	for (it=fig.begin(); it!=fig.end(); ++it){
		(*it)->translate(x,y);
	}
}
  
int main(){
	std::list<Shape*> shapes;
	
	shapes.push_back(new Circle);
	shapes.push_back(new Square);
	shapes.push_back(new Square);
	shapes.push_back(new Rhomb);
	
	drawShapes(shapes);
	moveShapes(shapes,1,1);
}

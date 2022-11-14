#include <iostream>
#include <list>

struct Point
{
    int x; 
    int y;
};

class Shape
{
    public: 
	    virtual void draw() = 0;
	    virtual void move() = 0;
};

class Circle : public Shape
{
    private:
	    double radius_;
        Point center_;

    public:
	    virtual void draw()
        {
            std::cout << "in drawCircle\n";
        }

	    virtual void move()
        {
            std::cout << "in moveCircle\n";
        }
};

class Square : public Shape
{
    private:
	    double radius_;
        Point center_;

    public:
	    virtual void draw()
        {
            std::cout << "in drawSquare\n";
        }

	    virtual void move()
        {
            std::cout << "in moveSquare\n";
        }
};

class Rhomb : public Shape
{
    private:
	    double radius_;
        Point center_;

    public:
	    virtual void draw()
        {
            std::cout << "in drawRhomb\n";
        }

	    virtual void move()
        {
            std::cout << "in moveRhomb\n";
        }
};


void drawShapes(const std::list<Shape*>& list)
{
	std::list<Shape*>::const_iterator it;
	for (it = list.begin(); it != list.end(); ++it)
    {
		(*it)->draw();
    }
}

void moveShapes(const std::list<Shape*>& list)
{
	std::list<Shape*>::const_iterator it;
	for (it = list.begin(); it != list.end(); ++it)
    {
		(*it)->move();
    }
}

int main2v6()
{
	std::list<Shape*> shapes;

	Circle* c1 = new Circle;
	shapes.push_front(c1);

	Circle* c2 = new Circle;
	shapes.push_front(c2);

	Square* s1 = new Square;
	shapes.push_front(s1);

	Rhomb* r1 = new Rhomb;
	shapes.push_front(r1);

	drawShapes(shapes);
	moveShapes(shapes);
    getchar();

    return 0;
}
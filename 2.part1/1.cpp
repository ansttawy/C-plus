#include <iostream>
#include <cmath>
#include "point.hpp"
using std::cout, std::endl;

class Circle
{
private:
	Point center;
	float radius;

public:
    Circle(const Point& x, float y)
    {
        center = x;
        radius = y;
    }
    Circle()
    {
        center = {0,0};
        radius = 1;
    }
    Circle(const Circle& other)
    {
        center = other.center;
        radius = other.radius;
    }

    const Point& getCenter() const {return center;}
    void setCenter(const Point& valueC) {center = valueC;}
    float getRadius() const {return radius;}
    void setRadius(float valueR)
    {
        if ( valueR >= 0) 
        {
            radius = valueR;
        }
        else
        {
            radius = 0;
        }
    }
    float area() const
    {
        return (radius*radius)*M_PI;
    }
    float distance(const Point& p) const
    {
        return std::abs(center.distance(p) - radius);
    }
    bool isColliding(const Circle& c) const
    {
        return center.distance(c.center) <= (radius + c.radius);
    }
    void move(const Point& p)
    {
        center = center + p;
    }
};

int main()
{
	Point p = {7, -1};
	Point q = {-4, 2};
	cout << "p = " << p << endl;
	cout << "q = " << q << endl;
	cout << "p + q = " << p + q << endl;


	Circle a({4, 1}, 3);
	Circle b;

	cout << "Circle a: center: " << a.getCenter() << " radius: " << a.getRadius() << endl; 
	cout << "Circle b: center: " << b.getCenter() << " radius: " << b.getRadius() << endl;

	cout << "Area of a = " << a.area() << endl;
	cout << "Distance from point p to circle a = " << a.distance(p) << endl;


	cout << "Collisions:" << endl;
	if (a.isColliding(b))
		cout << "Yes, a is colliding b" << endl;
	else
		cout << "No, a isn't colliding b" << endl;


	cout << "Moving b by {1, 1}:" << endl;
	b.move({1, 1});
	if (a.isColliding(b))
		cout << "Yes, a is colliding b" << endl;
	else
		cout << "No, a isn't colliding b" << endl;

}
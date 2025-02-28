#include <iostream>
#include <cmath>
using std::cout, std::endl;

struct Vector2f
{
    float x, y;
};

Vector2f operator+(Vector2f left, Vector2f right)
{
    Vector2f result = {left.x + right.x, left.y + right.y};
    return result;
}

Vector2f operator*(Vector2f left, float right)
{
    Vector2f result = {left.x * right, left.y * right};
    return result;
}

Vector2f operator*(float left, Vector2f right)
{
    Vector2f result = {left * right.x, left * right.y};
    return result;
}

Vector2f& operator+=(Vector2f& left, Vector2f right)
{
    left.x += right.x;
    left.y += right.y;
    return left;
}

float getDistance(Vector2f a, Vector2f b)
{
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

std::ostream& operator<<(std::ostream& out, Vector2f right)
{
    out << "(" << right.x << ", " << right.y << ")";
    return out;
}




/*
    Классы Circle, Rectangle и Triangle, описывающие круг, прямоугольник и треугольник соответственно.
*/
class Shape
{
public:
    Vector2f mPosition;
public:
    Shape() : mPosition({0, 0})
    {        
    }

    Vector2f getPosition()
    {
        return mPosition;
    }

    void setPosition(Vector2f newPosition)
    {
        mPosition = newPosition;
    }

    void move(Vector2f change)
    {
        mPosition = mPosition + change;
    }
};

class Circle : public Shape
{
private:

    float mRadius;

public:

    Circle(float radius) : mRadius(radius)
    {
    }



    float calculatePerimeter()
    {
        return 2 * std::numbers::pi * mRadius;
    }
};



class Rectangle : public Shape
{
private:

    float mWidth;
    float mHeight;

public:

    Rectangle(float width, float height) : mWidth(width), mHeight(height)
    {
    }


    float calculatePerimeter()
    {
        return 2 * (mWidth + mHeight);
    }
};




class Triangle : public Shape
{
private:

    Vector2f mPointA;
    Vector2f mPointB;
    Vector2f mPointC;

public:

    Triangle(Vector2f pointA, Vector2f pointB, Vector2f pointC) : 
            mPointA(pointA), mPointB(pointB), mPointC(pointC)
    {
    }

    float calculatePerimeter()
    {
        return getDistance(mPointA, mPointB) + getDistance(mPointB, mPointC) + getDistance(mPointC, mPointA);
    }
};


int main()
{
    Circle a(10);
    cout << a.calculatePerimeter() << endl;
    cout << "(" << a.getPosition().x << ", " << a.getPosition().y << ")" << endl; /*начальное положение*/
    a.move({3, 3});
    cout << "(" << a.getPosition().x << ", " << a.getPosition().y << ")" << endl; /*новое положение*/

    Rectangle b(100, 200);
    cout << b.calculatePerimeter() << endl;
    cout << "(" << b.getPosition().x << ", " << b.getPosition().y << ")" << endl; /*начальное положение*/
    b.move({-12, 12});
    cout << "(" << b.getPosition().x << ", " << b.getPosition().y << ")" << endl; /*новое положение*/

    Triangle c({5, 2}, {-7, 5}, {4, 4});
    cout << c.calculatePerimeter() << endl;
}
  
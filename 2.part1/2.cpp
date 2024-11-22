#include <iostream>
#include "complex.hpp"

using std::cout, std::cin, std::endl;

class Vector2f
{
private:
	float x;
	float y;

public:
    Vector2f(float x, float y)
    {
        this->x =  x;
        this->y =  y;
    }
    Vector2f()
    {
        x = 0;
        y = 0;
    }
    Vector2f operator+(const Vector2f& second) const 
    {
        return Vector2f(x + second.x, y + second.y);
    }
    Vector2f operator-(const Vector2f& second) const 
    {
        return Vector2f(x - second.x, y - second.y);
    }
    Vector2f operator*(float scalar) const 
    {
        return Vector2f(x * scalar, y * scalar);
    }
    float operator*(const Vector2f& second) const 
    {
        return x * second.x + y * second.y;
    }
    Vector2f operator-() const 
    {
        return Vector2f(-x, -y);
    }
    Vector2f operator+() const 
    {
        return Vector2f(x, y);
    }
    bool operator==(const Vector2f& second) const 
    {
        return x == second.x && y == second.y;
    }
    bool operator!=(const Vector2f& second) const 
    {
        return x != second.x && y != second.y;
    }
    Vector2f& operator+=(const Vector2f& second) 
    {
        x = x + second.x;
        y = y + second.y;
        return *this;
    }
    Vector2f& operator-=(const Vector2f& second) 
    {
        x = x - second.x;
        y = y - second.y;
        return *this;
    }
    Vector2f& operator*=(float scalar) 
    {
        x = x * scalar;
        y = y * scalar;
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& out, const Vector2f& a)
    {
        out << "(" << a.x << ", " << a.y << ")";
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Vector2f& a) 
    {
        in >> a.x >> a.y;
        return in;
    }

};



int main() 
{
  Vector2f a = {1.0, 2.0};
  Vector2f b = {4.0, -1.0};
  cout << "a = " << a << endl << "b = " << b << endl;
  cout << "a + b = " << a + b << endl;
  cout << "-a = " << -a << endl;
  cout << "Scalar product of a and b = " << a * b << endl;
  a += b;
  cout << "a after a+= b;" << a << endl;
}
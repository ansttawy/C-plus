#include <iostream>

void swap(int&a, int&b)
{
    a = b;
    b = a;
}

int main()
{
	int a = 10;
	int b = 20;
	std::cout << a << " " << b << std::endl; 
	swap(a, b);
	std::cout << a << " " << b << std::endl;  
}

#include <iostream>
#include <string>
#include <vector>

int main() 
{
    int* pa = new int(123);
    std::cout << *pa << std::endl;
	delete pa;

	std::string* p = new std::string("Cats and Dogs");
    std::cout << *p << std::endl;
	delete p;

	int n = 5;
	int* pb = new int[5]{10, 20, 30, 40, 50};
	for (std::size_t i = 0; i < n; ++i)
        std::cout << pb[i] << " ";
    std::cout << std::endl;
	delete[] pb;

	std::vector<int>* pc = new std::vector<int>{10, 20, 30, 40, 50};
	for (std::size_t i = 0; i < (*pc).size(); ++i)
        std::cout << (*pc)[i] << " ";
    std::cout << std::endl;
	delete pc;

	int l = 3;
	std::string* pd = new std::string[3]{"Cat", "Dog", "Mouse"};
	for (std::size_t i = 0; i < l; ++i)
        std::cout << pd[i] << " ";
    std::cout << std::endl;
	delete pd;
}


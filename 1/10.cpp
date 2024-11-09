#include <iostream>
#include <string>

bool isDomainName(const std::string& str) {
    
    if (str.compare(0, 4, "www.") != 0) { 
        return false;
    }
    if (str.compare(str.size() - 4, 4, ".com") != 0) { 
        return false;
    }
    return true; 
}


int main()
{
	std::cout << isDomainName("www.google.com") << std::endl;         // Напечатает 1
	std::cout << isDomainName("abc") << std::endl;                    // Напечатает 0
	std::cout << isDomainName("hello.com") << std::endl;              // Напечатает 0
}
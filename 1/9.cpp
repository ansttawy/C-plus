#include <iostream>

std::string repeat(int n)
{
    if (n<= 0){
        return "";
    }
    std::string res = std::to_string(n);
    for (int i = 1; i < n; ++i)
    {
        res+= std::to_string(n);
    }
    return res;
}
int main()
{
	std::cout << repeat(5)  << std::endl;  
	std::cout << repeat(10) << std::endl;  
	std::cout << repeat(-1) << std::endl;  
}
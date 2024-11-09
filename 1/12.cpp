#include <iostream>
#include <string>
#include <vector>

std::string concatenate(const std::vector<std::string>& v)
{
    std::string res = "";
    int size = v.size();
    for (int i = 0; i < size; ++i) 
    {
        res += v[i]; 
    } 

    return res;
}

int main()
{
	std::vector<std::string> v {"Cat", "Dog", "Mouse", "Tiger", "Elk"};
	std::cout << concatenate(v) << std::endl;
}
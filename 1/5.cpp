#include <iostream>
#include <string>

struct Book
{
    std::string title;
    int pages;
    float price;
};

bool isExpensive(const Book& book)
{
    if (book.price < 1000) { 
        return false;
    }
    return true; 

}


int main()
{
    Book a = {"Mathematical analysis", 3000, 200.5};
    std::cout << isExpensive(a) << std::endl; 
}
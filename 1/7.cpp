#include <iostream>
#include <string>
#include <cctype>

int numLetters = 0;
int numDigits = 0;
void countLetters(const std::string& str, int& numLetters, int& numDigits)
{
    for(int i = 0; i < str.size(); ++i)
    {
        if (std::isalpha(str[i]))
            numLetters +=1;
        if (std::isdigit(str[i]))
            numDigits +=1;

    }
}

int main()
{
int a = 0;
int b = 0;
countLetters("AAAAA5555", a, b);
std::cout << a << " " << b << std::endl;
}

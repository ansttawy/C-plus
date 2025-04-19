#include <iostream>
#include <vector>
#include <memory>


class Individual
{
public:
    virtual void speak() const = 0;
    virtual ~Individual() = default;
};

class Alice : public Individual
{
public:
    void speak() const override
    {
        std::cout << "Hi, I am Alice" << std::endl;
    }

};

class Bob : public Individual
{
public:
    void speak() const override
    {
        std::cout << "Hi, I am Bob" << std::endl;
    }

};

class Casper : public Individual
{
public:
    void speak() const override
    {
        std::cout << "Hi, I am Casper" << std::endl;
    }
};

std::vector<std::unique_ptr<Individual>> createIndividuals()
{
    std::vector<std::unique_ptr<Individual>> ind;

    ind.push_back(std::make_unique<Alice>());
    ind.push_back(std::make_unique<Alice>());
    ind.push_back(std::make_unique<Alice>());
    ind.push_back(std::make_unique<Bob>());
    ind.push_back(std::make_unique<Bob>());
    ind.push_back(std::make_unique<Casper>());
    ind.push_back(std::make_unique<Casper>());
    ind.push_back(std::make_unique<Casper>());
    ind.push_back(std::make_unique<Casper>());

    return ind;
}

void letThemSpeak(std::vector<std::unique_ptr<Individual>>&  ind)
{
    for(auto& p : ind)
        p->speak();
}


int main()
{   
    std::vector<std::unique_ptr<Individual>> inds = createIndividuals();

    letThemSpeak(inds);

}
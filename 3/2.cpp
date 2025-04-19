#include <iostream>
#include <vector> 

class Individual
{
public:
    virtual void speak() const = 0;
    virtual ~Individual() = default;
    virtual int ident() const = 0;
};

class Alice : public Individual
{
public:
    void speak() const override
    {
        std::cout << "Hi, I am Alice" << std::endl;
    }
    int ident() const override{
        return 0;
    }
};

class Bob : public Individual
{
public:
    void speak() const override
    {
        std::cout << "Hi, I am Bob" << std::endl;
    }
    int ident() const override{
        return 1;
    }
};

class Casper : public Individual
{
public:
    void speak() const override
    {
        std::cout << "Hi, I am Casper" << std::endl;
    }
    int ident() const override{
        return 2;
    }
};

std::vector<Individual*> createIndividuals()
{
    std::vector<Individual*> ind;

    ind.push_back(new Alice());
    ind.push_back(new Alice());
    ind.push_back(new Alice());
    ind.push_back(new Bob());
    ind.push_back(new Bob());
    ind.push_back(new Casper());
    ind.push_back(new Casper());
    ind.push_back(new Casper());
    ind.push_back(new Casper());

    return ind;
}

void letThemSpeak(std::vector<Individual*>& ind)
{
    for(auto& p : ind)
        p->speak();
}

void deleteIndividuals(std::vector<Individual*>& ind)
{
    for (auto& p : ind) 
        delete p;
}

int identification_a(Individual* p) 
{
    return p->ident(); 
}

int identification_b(Individual* p) 
{
    if (dynamic_cast<Alice*>(p))
        return 0;
    if (dynamic_cast<Bob*>(p)) 
        return 1;
    if (dynamic_cast<Casper*>(p)) 
        return 2;
}

int identification_c(Individual* p) 
{
    if (typeid(*p)==typeid(Alice))
        return 0;
    if (typeid(*p)==typeid(Bob))
        return 1;
    if (typeid(*p)==typeid(Casper))
        return 2;
}

int main()
{   
    Alice a;
    a.speak();

    std::vector<Individual*> inds = createIndividuals();

    letThemSpeak(inds);

    for (auto& p : inds) 
        std::cout <<  identification_a(p) << std::endl;

    for (auto& p : inds) 
        std::cout <<  identification_b(p) << std::endl;

    for (auto& p : inds) 
        std::cout <<  identification_c(p) << std::endl;
    deleteIndividuals(inds);

}

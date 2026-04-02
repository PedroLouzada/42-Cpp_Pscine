#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
    type = "Dog";
    std::cout << "A Dog has been contructed!\n";
}

Dog::Dog(const Dog& other)
{
    type = other.type;
    std::cout << "A Dog has been Copy contructed!\n";
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
        type = other.type;

    std::cout << "A Dog has been assigned to another!\n";
    return (*this);
}

Dog::~Dog(void)
{
    std::cout << "A Dog has been destroyed!\n";
}

void Dog::makeSound(void)
{
    std::cout << "AuAuAuAuAuAuAu\n";
}
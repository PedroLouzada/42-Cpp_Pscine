#include "Animal.hpp"

Animal::Animal(void)
{
    type = "I'm not a defined Animal";
    std::cout << "Animal default constructor called\n";
}

Animal::Animal(const Animal& other)
{
    type = other.type;
    std::cout << "Animal copy constructor called\n";
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
        type = other.type;
        
    std::cout << "Animal assignment operator called\n";
    return (*this);
}

Animal::~Animal(void)
{
    std::cout << "Animal destructor called\n";
}

void Animal::makeSound(void)
{
    std::cout << "BraiiiiiiinnnzzzZ...\n";
}
#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
    type = "Cat";
    std::cout << "A Cat has just be constructed\n";
}

Cat::Cat(const Cat& other) : Animal()
{
    type = other.type;
    std::cout << "A Cat had be copyed into another!?\n";
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
        type = other.type;

    std::cout << "A Cat has just assigned into other\n";
    return (*this);
}

Cat::~Cat(void)
{
    std::cout << "A Cat has been exploded\n";
}

void Cat::makeSound(void)
{
    std::cout << "Miauuuuuuuuuuuuu\n";
}
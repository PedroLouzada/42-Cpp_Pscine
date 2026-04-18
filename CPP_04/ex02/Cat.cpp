/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 19:11:44 by pbongiov          #+#    #+#             */
/*   Updated: 2026/04/06 19:11:45 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
    std::cout << "A Cat has just be constructed\n";
    type = "Cat";
    _brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal()
{
    std::cout << "A Cat had be copyed into another!?\n";
    type = other.type;
    _brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        type = other.type;
        delete(_brain);
        _brain = new Brain(*other._brain);
    }

    std::cout << "A Cat has just assigned into other\n";
    return (*this);
}

Cat::~Cat(void)
{
    delete(_brain);
    std::cout << "A Cat has been exploded\n";
}

void Cat::makeSound(void) const
{
    std::cout << "Miauuuuuuuuuuuuu\n";
}
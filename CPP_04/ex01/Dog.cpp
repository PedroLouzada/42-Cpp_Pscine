/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 19:11:48 by pbongiov          #+#    #+#             */
/*   Updated: 2026/04/06 19:11:49 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
    std::cout << "A Dog has been contructed!\n";
    type = "Dog";
    _brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal()
{
    std::cout << "A Dog has been Copy contructed!\n";
    type = other.type;
    _brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        type = other.type;
        delete(_brain);
        _brain = new Brain(*other._brain);
    }
    std::cout << "A Dog has been assigned to another!\n";
    return (*this);
}

Dog::~Dog(void)
{
    delete(_brain);
    std::cout << "A Dog has been destroyed!\n";
}

void Dog::makeSound(void) const
{
    std::cout << "AuAuAuAuAuAuAu\n";
}

std::string& Dog::getIdea(const int index) const
{
    return (this->_brain->ideas[index]);
}
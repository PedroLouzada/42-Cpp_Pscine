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
    type = "Dog";
    std::cout << "A Dog has been contructed!\n";
}

Dog::Dog(const Dog& other) : Animal()
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

void Dog::makeSound(void) const
{
    std::cout << "AuAuAuAuAuAuAu\n";
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 19:11:41 by pbongiov          #+#    #+#             */
/*   Updated: 2026/04/06 19:11:43 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
    type = "Unknown";
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

void Animal::makeSound(void) const
{
    std::cout << "BraiiiiiiinnnzzzZ...\n";
}

const std::string Animal::getType(void) const
{
    return(type);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 19:12:04 by pbongiov          #+#    #+#             */
/*   Updated: 2026/04/06 19:14:11 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    type = "I'm a WrongAnimal";
    std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    type = other.type;
    std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
        type = other.type;
        
    std::cout << "WrongAnimal assignment operator called\n";
    return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructor called\n";
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "I don't make any sound, I'm a Wrong Animal...\n";
}

const std::string WrongAnimal::getType(void) const
{
    return(type);
}
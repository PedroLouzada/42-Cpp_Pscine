/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 19:12:09 by pbongiov          #+#    #+#             */
/*   Updated: 2026/04/06 19:17:42 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
    type = "WrongCat";
    std::cout << "A WrongCat has just be constructed\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal()
{
    type = other.type;
    std::cout << "A WrongCat had be copyed into another!?\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
        type = other.type;

    std::cout << "A WrongCat has just assigned into other\n";
    return (*this);
}

WrongCat::~WrongCat(void)
{
    std::cout << "A WrongCat has been exploded\n";
}

void WrongCat::makeSound(void) const
{
    std::cout << "I'm a WrongCat, i do not MiauMiau!\n";
}
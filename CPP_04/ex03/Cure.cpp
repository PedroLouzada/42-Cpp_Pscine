/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 00:32:14 by pbongiov          #+#    #+#             */
/*   Updated: 2026/04/18 00:42:45 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
    std::cout << "A Cure spell had been created!\n";
}

Cure::Cure(const Cure& other) : AMateria(other._type)
{
    std::cout << "A Cure spell has been copied!\n";
    *this = other;
}

Cure& Cure::operator=(const Cure& other)
{
    std::cout << "A Cure spell has been assigned to another!\n";
    if(this != &other)
    {
        delete(this);
        *this = other;
    }

    return (*this);
}

Cure::~Cure(void)
{
    std::cout << "A Cure spell has vanished...\n";
}

AMateria* Cure::clone(void) const
{
    std::cout << "A Cure spell has been cloned!\n";
    
    return (new Cure());
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
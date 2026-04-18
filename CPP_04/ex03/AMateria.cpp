/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 21:34:35 by pbongiov          #+#    #+#             */
/*   Updated: 2026/04/18 15:57:11 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const& type)
{
    if (type.compare("ice") && type.compare("cure"))
    {
        std::cout << "No Materia match the input\n";
        _type = "Unknown";
    }
    std::cout << "A AMateria is in the making!\n";
    _type = type;
}

AMateria::AMateria(const AMateria& other)
{
    std::cout << "A AMateria has been copied!\n";
    *this = other;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    std::cout << "A AMateria has been assigned to another!\n";
    if(this != &other)
    {
        delete(this);
        *this = other;
    }

    return (*this);
}

AMateria::~AMateria(void)
{
    std::cout << "A AMateria has been destroyed\n";
}

std::string const& AMateria::getType(void) const
{
    return (_type);
}

void AMateria::use(ICharacter& target){ (void)target; }
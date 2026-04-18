/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 00:35:49 by pbongiov          #+#    #+#             */
/*   Updated: 2026/04/18 00:41:19 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
    std::cout << "A cold wind comes with a Ice spell beeing formated...\n";
}

Ice::Ice(const Ice& other) : AMateria(other._type)
{
    std::cout << "A Ice spell has been copied!\n";
    *this = other;
}

Ice& Ice::operator=(const Ice& other)
{
    std::cout << "A Ice spell has been assigned to another!\n";
    if(this != &other)
    {
        delete(this);
        *this = other;
    }

    return (*this);
}

Ice::~Ice(void)
{
    std::cout << "A Ice ball is melting...\n";
}

AMateria* Ice::clone(void) const
{
    std::cout << "A Ice spell has been cloned!\n";
    
    return (new Ice());
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}


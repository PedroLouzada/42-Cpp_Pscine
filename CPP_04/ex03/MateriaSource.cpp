/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 00:01:09 by pbongiov          #+#    #+#             */
/*   Updated: 2026/04/18 16:03:51 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : IMateriaSource()
{
    std::cout << "Materia Source is beeing generated...\n";
    for(int i= 0; i < 4; i++)
        _slots[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) : IMateriaSource()
{
    std::cout << "Materia Source is beeing copied...\n";
    for(int i = 0; i < 4; i++)
        _slots[i] = other._slots[i]->clone();
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    std::cout << "Materia Source is beeing assigned...\n";
    if(this != &other)
    {
        for(int i = 0; i < 4; i++)
        {
            if (_slots[i] != NULL)
                delete(_slots[i]);
            _slots[i] = other._slots[i]->clone();
        }
    }

    return(*this);
}

MateriaSource::~MateriaSource(void)
{
    std::cout << "Materia Source beeing desintegrated...\n";
    for(int i = 0; i < 4; i++)
    {
        if (_slots[i] != NULL)
            delete(_slots[i]);
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    for(int i = 0; i < 4; i++)
    {
        if (_slots[i] == NULL)
        {
            _slots[i] = m->clone();
            return ;
        }
    }
    std::cout << "Materia Source cannot learn more spells!.\n";
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
    for(int i = 0; i < 4; i++)
    {
        if (type == _slots[i]->getType())
            return (_slots[i]->clone());
    }
    std::cout << "Materia Source don't know the input type\n";
    return (0);
}
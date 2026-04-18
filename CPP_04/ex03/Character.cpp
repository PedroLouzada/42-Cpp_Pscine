/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 20:30:13 by pbongiov          #+#    #+#             */
/*   Updated: 2026/04/18 01:52:30 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name) : ICharacter()
{
    std::cout << "A Character has been born!\n";
    _name = name;
    for (int i = 0; i < 4; i++)
        _slots[i] = NULL;
}

Character::Character(const Character& other) : ICharacter(other)
{
    std::cout << "A Character has been copied!\n";
    _name = other._name;
    for(int i = 0; i < 4; i++)
        _slots[i] = _slots[i]->clone();
}

Character& Character::operator=(const Character& other)
{
    std::cout << "A Character has been assigned to another!\n";
    if(this != &other)
    {
        _name = other._name;
        for(int i = 0; i < 4; i++)
        {
            if (_slots[i] != NULL)
                delete(_slots[i]);
            _slots[i] = other._slots[i]->clone();
        }
    }

    return (*this);
}

Character::~Character(void)
{
    std::cout << "A Character has been killed 😵\n";
}

std::string const& Character::getName() const
{
    return (_name);
}

void Character::equip(AMateria* m)
{
    for(int i = 0; i < 4; i++)
    {
        if (_slots[i] == NULL)
        {
            _slots[i] = m;
            break ;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
        return ;
    if (_slots[idx] != NULL)
        _slots[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    _slots[idx]->use(target);
}
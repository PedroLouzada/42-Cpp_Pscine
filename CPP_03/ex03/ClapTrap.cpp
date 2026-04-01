/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 19:43:51 by pbongiov          #+#    #+#             */
/*   Updated: 2026/03/31 22:48:07 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
    std::cout << "ClapTrap deafult constructor called\n";
    _name = "";
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
}

ClapTrap::ClapTrap(const std::string& name)
{
    std::cout << "ClapTrap parameter constructor called\n";
     _name = name;
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
}

ClapTrap::ClapTrap(const std::string& name, const int hit, const int energy, const int attack)
{
    std::cout << "ClapTrap parameter constructor called\n";
     _name = name;
    _hitPoints = hit;
    _energyPoints = energy;
    _attackDamage = attack;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "ClapTrap copy constructor called\n";
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "ClapTrap assignement operator called\n";
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return (*this);
}

ClapTrap::~ClapTrap(void) { std::cout << "ClapTrap destructor called\n"; }

void ClapTrap::attack(const std::string& target)
{
    if (!_hitPoints)
    {
        std::cout << "ClapTrap " << _name << " has no Hit Points left!" << std::endl;
        return ;
    }
    if (!_energyPoints)
    {
        std::cout << "ClapTrap " << _name << " has no Energy Points left!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target 
    << " , causing " << _attackDamage <<" points of damage!" << std::endl;
    if (_energyPoints > 0)
        _energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    _hitPoints -= amount;
    if (_hitPoints < 0)
        _hitPoints = 0;
    std::cout << "ClapTrap " << _name << " has taken " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "ClapTrap " << _name << " it's repairing itself." << std::endl;
    _hitPoints += amount;
}
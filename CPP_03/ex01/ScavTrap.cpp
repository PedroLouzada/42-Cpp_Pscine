/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 21:25:10 by pbongiov          #+#    #+#             */
/*   Updated: 2026/03/31 23:22:45 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("", 100, 50, 20)
{
    std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name, 100, 50, 20)
{
    std::cout << "ScavTrap parameter constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other._name, other._hitPoints, other._energyPoints, other._attackDamage)
{
    std::cout << "ScavTrap copy constructor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "ScavTrap assignement operator called\n";
    return (*this);
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap destructor called\n";
}

void ScavTrap::attack(const std::string& target)
{
    if (!_hitPoints)
    {
        std::cout << "ScavTrap " << _name << " has no Hit Points left!" << std::endl;
        return ;
    }
    if (!_energyPoints)
    {
        std::cout << "ScavTrap " << _name << " has no Energy Points left!" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << _name << " attacks " << target << " with a bazooka , causing "
    << _attackDamage <<" points of damage!" << std::endl;
    if (_energyPoints > 0)
        _energyPoints--;
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode!" << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 17:58:02 by pbongiov          #+#    #+#             */
/*   Updated: 2026/04/15 13:58:46 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
    _name = name;
    _hitPoints = FragTrap::defaltHitPoints;
    _energyPoints = ScavTrap::defaultenergyPoints;
    _attackDamage = FragTrap::defaultAttackDamage;
    std::cout << "DiamondTrap default constructor called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other._name + "_clap_name"), ScavTrap(other._name + "_clap_name"), FragTrap(other._name + "_clap_name")
{
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    std::cout << "DiamondTrap copy constructor called\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "DiamondTrap assignement operator called\n";
    return (*this);
}

DiamondTrap::~DiamondTrap(void) { std::cout << "DiamondTrap destructor called\n"; }

void DiamondTrap::WhoAmI(void)
{
    std::cout << "I am " << _name << " and I inherid from " << ClapTrap::_name << std::endl;
}
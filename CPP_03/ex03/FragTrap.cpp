#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name, 100, 100, 30)
{
    std::cout << "FragTrap has been contructed by a default constructor.\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other._name, other._hitPoints, other._energyPoints, other._attackDamage)
{
    std::cout << "FragTrap has been contructed by a copy constructor.\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "FragTrap used a assignment operator.\n";
    return (*this);
}

FragTrap::~FragTrap(void) { std::cout << "FragTrap has been destructed by a default destructor\n"; }

void FragTrap::highFivesGuys(void)
{
    std::cout << "Let's High Five Guys! ✋\n";
}
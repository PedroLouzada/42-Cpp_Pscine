#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("")
{
    std::cout << "Deafult Constructor Called\n";
    _hitPoints = 0;
    _energyPoints = 0;
    _attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
    std::cout << "Parameter Constructor Called\n";
    _hitPoints = 0;
    _energyPoints = 0;
    _attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "Copy Constructor Called\n";
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "Assignement Operator Called\n";
    if (this != &other)
    {
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
}

ClapTrap::~ClapTrap(void) { std::cout << "Destructor Called\n"; }

void ClapTrap::attack(const std::string& target)
{
    if (!_hitPoints)
    {
        std::cout << "ClapTrap " << _name << "has no Hit Points left!" << std::endl;
        return ;
    }
    if (!_energyPoints)
    {
        std::cout << "ClapTrap " << _name << "has no Energy Points left!" << std::endl;
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
    
}
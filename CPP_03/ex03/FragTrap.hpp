#ifndef FRAGTRAP_H
# define SCRAVTRAP_H

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    protected:
        static const int defaltHitPoints = 100;
        static const int defaultAttackDamage = 30;

    public:
        FragTrap(void);
        FragTrap(const std::string& name);
        FragTrap(const FragTrap& other);
        FragTrap& operator=(const FragTrap& other);
        ~FragTrap(void);

        void highFivesGuys(void);
};

#endif
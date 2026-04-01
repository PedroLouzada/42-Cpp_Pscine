#ifndef FRAGTRAP_H
# define SCRAVTRAP_H

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap(void);
        FragTrap(const std::string& name);
        FragTrap(const FragTrap& other);
        FragTrap& operator=(const FragTrap& other);
        ~FragTrap(void);

        void highFivesGuys(void);
};

#endif
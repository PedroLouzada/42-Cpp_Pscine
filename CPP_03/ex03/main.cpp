/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 21:09:34 by pbongiov          #+#    #+#             */
/*   Updated: 2026/04/13 18:01:55 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
    std::cout << "---------------------------- Constructor Tests -------------------------------------\n";

    ClapTrap* a = new DiamondTrap("Object A");
    std::cout << std::endl;
    DiamondTrap b("Object B");
    std::cout << std::endl;
    DiamondTrap c(b);
    std::cout << std::endl;
    c = b;
    
    std::cout << "\n\n---------------------------------- Function Tests ---------------------------------------\n";

    a->attack("Object A");

    a->beRepaired(10);
    
    c.takeDamage(1000);

    c.attack("Object A");
    
    b.highFivesGuys();

    b.guardGate();

    b.WhoAmI();
    std::cout << "\n\n---------------------------------- Destructor Tests ---------------------------------------\n";

    delete(a);
}
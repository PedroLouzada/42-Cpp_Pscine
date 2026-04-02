/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 21:09:34 by pbongiov          #+#    #+#             */
/*   Updated: 2026/03/31 23:42:51 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
    std::cout << "---------------------------- Constructor Tests -------------------------------------\n";

    DiamondTrap a("Object B");
    std::cout << std::endl;
    DiamondTrap c(a);
    std::cout << std::endl;
    a = c;
    
    std::cout << "\n\n---------------------------------- Function Tests ---------------------------------------\n";

    a.attack("Object A");

    a.beRepaired(10);
    
    c.takeDamage(1000);

    c.attack("Object A");
    
    a.highFivesGuys();

    a.guardGate();

    a.WhoAmI();
    std::cout << "\n\n---------------------------------- Destructor Tests ---------------------------------------\n";

}
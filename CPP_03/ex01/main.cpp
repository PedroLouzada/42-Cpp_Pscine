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

#include "ScavTrap.hpp"

int main(void)
{
    std::cout << "---------------------------- Constructor Tests -------------------------------------\n";

    ScavTrap a;
    ScavTrap b("Object B");
    ScavTrap c(b);
    a = c;
    
    std::cout << "\n\n---------------------------------- Function Tests ---------------------------------------\n";

    a.attack("Object A");

    b.beRepaired(10);
    
    c.takeDamage(1000);

    c.attack("Object A");
    
    a.guardGate();

    std::cout << "\n\n---------------------------------- Destructor Tests ---------------------------------------\n";

}
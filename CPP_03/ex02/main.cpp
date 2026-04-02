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

#include "FragTrap.hpp"

int main(void)
{
    std::cout << "---------------------------- Constructor Tests -------------------------------------\n";

    FragTrap a("Object B");
    FragTrap c(a);
    a = c;
    
    std::cout << "\n\n---------------------------------- Function Tests ---------------------------------------\n";

    a.attack("Object A");

    a.beRepaired(10);
    
    c.takeDamage(1000);

    c.attack("Object A");
    
    a.highFivesGuys();

    std::cout << "\n\n---------------------------------- Destructor Tests ---------------------------------------\n";

}
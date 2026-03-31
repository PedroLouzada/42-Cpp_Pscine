/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 19:43:45 by pbongiov          #+#    #+#             */
/*   Updated: 2026/03/31 23:41:20 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    std::cout << "---------------------------- Constructor Tests -------------------------------------\n";

    ClapTrap a;
    ClapTrap b("Object B");
    ClapTrap c(b);
    a = c;
    
    std::cout << "\n\n---------------------------------- Function Tests ---------------------------------------\n";

    a.attack("Object A");

    b.beRepaired(10);
    
    c.takeDamage(1000);

    c.attack("Object A");

    std::cout << "\n\n---------------------------------- Destructor Tests ---------------------------------------\n";
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 11:46:11 by pbongiov          #+#    #+#             */
/*   Updated: 2026/03/23 12:15:09 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie *z1 = newZombie("Lisboa");
    Zombie *z2 = newZombie("Berlim");
    Zombie *z3 = newZombie("Moscow");
    Zombie *z4 = newZombie("Bruxelas");
    Zombie *z5 = newZombie("Praga");

    if (!z1 || !z2 || !z3 || !z4 || !z5)
        return (std::cout << "Allocation Error" << std::endl, 1);

    z1->announce();
    z2->announce();
    z3->announce();
    z4->announce();
    z5->announce();

    randomChump("Rio");
    randomChump("Sao Paulo");
    randomChump("Buenos Aires");
    randomChump("Santiago");
    randomChump("Monte Videl");

    delete(z1);
    delete(z2);
    delete(z3);
    delete(z4);
    delete(z5);

    return (0);
}
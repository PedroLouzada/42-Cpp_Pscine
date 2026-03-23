/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 13:01:44 by pbongiov          #+#    #+#             */
/*   Updated: 2026/03/23 13:04:30 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    int n = 10;
    Zombie *z = zombieHorde(n, "Jason");

    for (int i = 0; i < n; i++)
        z[i].announce();
        
    delete[](z);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 19:36:39 by pbongiov          #+#    #+#             */
/*   Updated: 2026/10/01 19:36:40 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Cannot sort less then two numbers" << std::endl;
        return 1;
    }

    PmergeMe obj;

    for (int i = 1; i < ac; ++i)
    {
        if (obj.parse(av[i]))
            return 1;
    }
}
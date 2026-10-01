/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 19:36:22 by pbongiov          #+#    #+#             */
/*   Updated: 2026/09/28 20:17:14 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2 || std::string(av[1]).empty())
    {
        std::cerr << "Program requires 2 arguments" << std::endl;
        return 1;
    }

    Rpn rpn;

    if (rpn.resolve(av[1]))
        return 1;
}
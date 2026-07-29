/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 13:34:14 by pbongiov          #+#    #+#             */
/*   Updated: 2026/07/29 15:49:45 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool parse(const std::string& arg)
{
    if (arg.empty())
    {
        std::cerr << "Argument cannot be empty!" << std::endl;
        return false;
    }

    return true;
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage ./convert <argument>" << std::endl;
        return 1;
    }
    if (!parse(std::string(av[1])))
        return 1;
    
    ScalarConverter::convert(std::string(av[1]));
    return 0;
}
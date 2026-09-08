/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 11:01:43 by pbongiov          #+#    #+#             */
/*   Updated: 2026/09/07 12:47:05 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int errorMsg(const std::string& msg)
{
    std::cerr << "Error: " << msg << std::endl;
    return (1);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return errorMsg("could not open file.");
    
    BitcoinExchange obj;
    obj.parseFile(av[1]);
    
    std::multimap<std::string, std::string>::iterator it;
    for (it = obj.begin(); it != obj.end(); ++it)
        obj.convertCoin(it);
}
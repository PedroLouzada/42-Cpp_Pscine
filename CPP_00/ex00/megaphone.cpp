/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 16:46:18 by pbongiov          #+#    #+#             */
/*   Updated: 2026/03/24 16:29:11 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>
    
int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    int i = 0;
    std::string str;
    while (++i < ac)
    {
        str = av[i];
        for (size_t j = 0; j < str.size(); j++)
            str[j] = std::toupper(str[j]);
        std::cout << str;
    }
    std::cout << std::endl;
}
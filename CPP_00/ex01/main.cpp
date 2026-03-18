/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 19:11:17 by pbongiov          #+#    #+#             */
/*   Updated: 2026/03/18 19:51:00 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main(void)
{
    int i = 0;
    std::string input;
    PhoneBook phonebook;
    
    while (1)
    {
        std::cout << "Enter a Command:" << std::endl << "ADD | SEARCH | EXIT\n" << std::endl; 
        if (!std::getline(std::cin, input))
            break ;
        if (!input.compare("ADD"))
        {
            phonebook.newContact(i++);
            i = i % 8;
        }
        else if (!input.compare("SEARCH"))
            phonebook.searchContact();
        else if (!input.compare("EXIT"))
            break;
    }
}
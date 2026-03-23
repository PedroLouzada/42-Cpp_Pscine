/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 18:17:00 by pbongiov          #+#    #+#             */
/*   Updated: 2026/03/23 10:53:39 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <cstdlib>
#include "PhoneBook.hpp"

bool isAllEmpty(std::string str)
{
    int i = 0;

    while (str[i])
    {
        if (str[i++] != ' ')
            return (false);
    }
    return (true);
}

std::string getInfo(std::string arg)
{
    std::string input = "";
    
    while (1)
    {
        std::cout << arg << ": " << std::endl;
        if (!std::getline(std::cin, input))
            return ("");
        if (input.empty() || isAllEmpty(input))
        {
            std::cout << "Field must not be empty" << std::endl;
            continue ;
        }
        break ;
    }
    return (input);
}

std::string reduceStr(std::string str)
{
    if (str.size() > 9)
        return (str.substr(0, 9) + '.');

    return (str);
}

bool PhoneBook::_displayTable(void)
{
    std::string fname;
    std::string lname;
    std::string num;
    
    bool        value = false;
    
    for (int i = 0; i < 8; i++)
    {
        fname = reduceStr(this->_contact[i].Get_firstname());
        lname = reduceStr(this->_contact[i].Get_lastname());
        num = reduceStr(this->_contact[i].Get_number());
        
        if (!fname.empty() || !lname.empty() || !num.empty())
        {
            if (!i)
                std::cout << "|     Index|First Name| Last Name|    Number|" << std::endl;
                
            std::cout << "|" << std::setw(10) << std::right << i << "|"
                             << std::setw(10) << std::right << fname << "|"
                             << std::setw(10) << std::right << lname << "|"
                             << std::setw(10) << std::right << num << "|"
                             << std::endl; 
            value = true;  
        }
    }
    return (value);
}

bool isAllDigit(std::string str)
{
    int i = 0;
    
    while (str[i])
    {
        if (!std::isdigit(str[i++]))
            return (false);
    }
    return (true);
}

void PhoneBook::searchContact(void)
{
    std::string input;
    int index;
 
    bool search = this->_displayTable();
    
    if (search)
    {
        while (1)
        {
            input = getInfo("Index to Search");
            if (input.empty())
                return ;
            index = std::atoi(input.c_str());
            if (index < 0 || index > 7 || !isAllDigit(input))
            {
                std::cout << "Invalid Index" << std::endl;
                continue ;
            }
            break ;
        }
        if (this->_contact[index].Get_firstname().empty())
        {
            std::cout << "Index not filled yet" << std::endl;
            return ;
        }
        std::cout << std::endl << "Index         : " << index << std::endl;
        std::cout << "First Name    : " << this->_contact[index].Get_firstname() << std::endl;
        std::cout << "Last Name     : " << this->_contact[index].Get_lastname() << std::endl;
        std::cout << "Nickname      : " << this->_contact[index].Get_nickname() << std::endl;
        std::cout << "Number        : " << this->_contact[index].Get_number() << std::endl;
        std::cout << "Darkest Secret: " << this->_contact[index].GetSecret() << std::endl << std::endl;
    }
}

void PhoneBook::newContact(int i)
{
    Contact contact;
    
    std::string firstname = getInfo("First Name");
    std::string lastname = getInfo("Last Name");
    std::string nickname = getInfo("Nickname");

    contact.SetName(firstname, lastname, nickname);

    std::string number = getInfo("Number");

    contact.Set_number(number);

    std::string darkestSecret = getInfo("Darkest Secret");

    contact.SetSecret(darkestSecret);

    this->_contact[i] = contact;
}